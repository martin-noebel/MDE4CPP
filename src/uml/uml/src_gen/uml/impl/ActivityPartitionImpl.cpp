
#include "uml/impl/ActivityPartitionImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>


#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityPartitionImpl::ActivityPartitionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActivityPartitionImpl::~ActivityPartitionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityPartition "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActivityPartitionImpl::ActivityPartitionImpl(std::weak_ptr<uml::Activity> par_inActivity)
:ActivityPartitionImpl()
{
	m_inActivity = par_inActivity;
	m_owner = par_inActivity;
}

//Additional constructor for the containments back reference
ActivityPartitionImpl::ActivityPartitionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ActivityPartitionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ActivityPartitionImpl::ActivityPartitionImpl(std::weak_ptr<uml::Element> par_owner)
:ActivityPartitionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ActivityPartitionImpl::ActivityPartitionImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup)
:ActivityPartitionImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}

//Additional constructor for the containments back reference
ActivityPartitionImpl::ActivityPartitionImpl(std::weak_ptr<uml::ActivityPartition> par_superPartition)
:ActivityPartitionImpl()
{
	m_superPartition = par_superPartition;
	m_superGroup = par_superPartition;
}

ActivityPartitionImpl::ActivityPartitionImpl(const ActivityPartitionImpl & obj): ActivityPartitionImpl()
{
	*this = obj;
}

ActivityPartitionImpl& ActivityPartitionImpl::operator=(const ActivityPartitionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActivityGroupImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ActivityPartition 
	 * which is generated by the compiler (as ActivityPartition is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ActivityPartition::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityPartition "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isDimension = obj.getIsDimension();
	m_isExternal = obj.getIsExternal();

	//copy references with no containment (soft copy)
	m_represents  = obj.getRepresents();
	m_superPartition  = obj.getSuperPartition();
	//Clone references with containment (deep copy)
	//clone reference 'edge'
	std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge>> edgeList = obj.getEdge();
	if(edgeList)
	{
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::ActivityEdge >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge >()" << std::endl;
		#endif
		
		/*Subset*/
		getEdge()->initSubset(getContainedEdge());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge >(getContainedEdge())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityEdge> edgeindexElem: *edgeList) 
		{
			std::shared_ptr<uml::ActivityEdge> temp = std::dynamic_pointer_cast<uml::ActivityEdge>((edgeindexElem)->copy());
			m_edge->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr edge."<< std::endl;)
	}

	//clone reference 'node'
	std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> nodeList = obj.getNode();
	if(nodeList)
	{
		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >()" << std::endl;
		#endif
		
		/*Subset*/
		getNode()->initSubset(getContainedNode());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >(getContainedNode())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityNode> nodeindexElem: *nodeList) 
		{
			std::shared_ptr<uml::ActivityNode> temp = std::dynamic_pointer_cast<uml::ActivityNode>((nodeindexElem)->copy());
			m_node->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr node."<< std::endl;)
	}

	//clone reference 'subpartition'
	std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> subpartitionList = obj.getSubpartition();
	if(subpartitionList)
	{
		/*Subset*/
		m_subpartition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subpartition - Subset<uml::ActivityPartition, uml::ActivityGroup >()" << std::endl;
		#endif
		
		/*Subset*/
		getSubpartition()->initSubset(getSubgroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subpartition - Subset<uml::ActivityPartition, uml::ActivityGroup >(getSubgroup())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityPartition> subpartitionindexElem: *subpartitionList) 
		{
			std::shared_ptr<uml::ActivityPartition> temp = std::dynamic_pointer_cast<uml::ActivityPartition>((subpartitionindexElem)->copy());
			m_subpartition->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr subpartition."<< std::endl;)
	}
	/*Subset*/
	getSubpartition()->initSubset(getSubgroup());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_subpartition - Subset<uml::ActivityPartition, uml::ActivityGroup >(getSubgroup())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ActivityPartitionImpl::copy() const
{
	std::shared_ptr<ActivityPartitionImpl> element(new ActivityPartitionImpl());
	*element =(*this);
	element->setThisActivityPartitionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool ActivityPartitionImpl::dimension_not_contained(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ActivityPartitionImpl::represents_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ActivityPartitionImpl::represents_property(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ActivityPartitionImpl::represents_property_and_is_contained(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isDimension */
bool ActivityPartitionImpl::getIsDimension() const 
{
	return m_isDimension;
}
void ActivityPartitionImpl::setIsDimension(bool _isDimension)
{
	m_isDimension = _isDimension;
	
}

/* Getter & Setter for attribute isExternal */
bool ActivityPartitionImpl::getIsExternal() const 
{
	return m_isExternal;
}
void ActivityPartitionImpl::setIsExternal(bool _isExternal)
{
	m_isExternal = _isExternal;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference edge */
std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge>> ActivityPartitionImpl::getEdge() const
{
	if(m_edge == nullptr)
	{
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::ActivityEdge >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge >()" << std::endl;
		#endif
		
		/*Subset*/
		getEdge()->initSubset(getContainedEdge());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge >(getContainedEdge())" << std::endl;
		#endif
		
	}
    return m_edge;
}

/* Getter & Setter for reference node */
std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> ActivityPartitionImpl::getNode() const
{
	if(m_node == nullptr)
	{
		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >()" << std::endl;
		#endif
		
		/*Subset*/
		getNode()->initSubset(getContainedNode());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >(getContainedNode())" << std::endl;
		#endif
		
	}
    return m_node;
}

/* Getter & Setter for reference represents */
std::shared_ptr<uml::Element> ActivityPartitionImpl::getRepresents() const
{
    return m_represents;
}
void ActivityPartitionImpl::setRepresents(std::shared_ptr<uml::Element> _represents)
{
    m_represents = _represents;
	
}

/* Getter & Setter for reference subpartition */
std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> ActivityPartitionImpl::getSubpartition() const
{
	if(m_subpartition == nullptr)
	{
		/*Subset*/
		m_subpartition.reset(new Subset<uml::ActivityPartition, uml::ActivityGroup >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subpartition - Subset<uml::ActivityPartition, uml::ActivityGroup >()" << std::endl;
		#endif
		
		/*Subset*/
		getSubpartition()->initSubset(getSubgroup());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subpartition - Subset<uml::ActivityPartition, uml::ActivityGroup >(getSubgroup())" << std::endl;
		#endif
		
	}
    return m_subpartition;
}

/* Getter & Setter for reference superPartition */
std::weak_ptr<uml::ActivityPartition> ActivityPartitionImpl::getSuperPartition() const
{
    return m_superPartition;
}
void ActivityPartitionImpl::setSuperPartition(std::weak_ptr<uml::ActivityPartition> _superPartition)
{
    m_superPartition = _superPartition;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityEdge>> ActivityPartitionImpl::getContainedEdge() const
{
	if(m_containedEdge == nullptr)
	{
		/*Union*/
		m_containedEdge.reset(new Union<uml::ActivityEdge>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedEdge - Union<uml::ActivityEdge>()" << std::endl;
		#endif
		
		
	}
	return m_containedEdge;
}

std::shared_ptr<Union<uml::ActivityNode>> ActivityPartitionImpl::getContainedNode() const
{
	if(m_containedNode == nullptr)
	{
		/*Union*/
		m_containedNode.reset(new Union<uml::ActivityNode>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedNode - Union<uml::ActivityNode>()" << std::endl;
		#endif
		
		
	}
	return m_containedNode;
}

std::shared_ptr<Union<uml::Element>> ActivityPartitionImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> ActivityPartitionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> ActivityPartitionImpl::getSubgroup() const
{
	if(m_subgroup == nullptr)
	{
		/*SubsetUnion*/
		m_subgroup.reset(new SubsetUnion<uml::ActivityGroup, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_subgroup - SubsetUnion<uml::ActivityGroup, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getSubgroup()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_subgroup - SubsetUnion<uml::ActivityGroup, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_subgroup;
}

std::weak_ptr<uml::ActivityGroup> ActivityPartitionImpl::getSuperGroup() const
{
	return m_superGroup;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ActivityPartitionImpl::eContainer() const
{
	if(auto wp = m_inActivity.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_superGroup.lock())
	{
		return wp;
	}

	if(auto wp = m_superPartition.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ActivityPartitionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ActivityPartitionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isDimension");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsDimension(value);
		}

		iter = attr_list.find("isExternal");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsExternal(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("edge");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("edge")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("node");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("node")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("represents");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("represents")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ActivityGroupImpl::loadAttributes(loadHandler, attr_list);
}

void ActivityPartitionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("subpartition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ActivityPartition";
			}
			loadHandler->handleChildContainer<uml::ActivityPartition>(this->getSubpartition());  

			return; 
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}
	//load BasePackage Nodes
	ActivityGroupImpl::loadNode(nodeName, loadHandler);
}

void ActivityPartitionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_EDGE:
		{
			std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge>> _edge = getEdge();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityEdge>  _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_edge->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_NODE:
		{
			std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> _node = getNode();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityNode>  _r = std::dynamic_pointer_cast<uml::ActivityNode>(ref);
				if (_r != nullptr)
				{
					_node->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_REPRESENTS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Element> _represents = std::dynamic_pointer_cast<uml::Element>( references.front() );
				setRepresents(_represents);
			}
			
			return;
		}

		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ActivityPartition> _superPartition = std::dynamic_pointer_cast<uml::ActivityPartition>( references.front() );
				setSuperPartition(_superPartition);
			}
			
			return;
		}
	}
	ActivityGroupImpl::resolveReferences(featureID, references);
}

void ActivityPartitionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityGroupImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ActivityPartitionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'subpartition'
		for (std::shared_ptr<uml::ActivityPartition> subpartition : *this->getSubpartition()) 
		{
			saveHandler->addReference(subpartition, "subpartition", subpartition->eClass() != package->getActivityPartition_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getActivityPartition_Attribute_isDimension()) )
		{
			saveHandler->addAttribute("isDimension", this->getIsDimension());
		}

		if ( this->eIsSet(package->getActivityPartition_Attribute_isExternal()) )
		{
			saveHandler->addAttribute("isExternal", this->getIsExternal());
		}
	// Add references
		saveHandler->addReferences<uml::ActivityEdge>("edge", this->getEdge());
		saveHandler->addReferences<uml::ActivityNode>("node", this->getNode());
		saveHandler->addReference(this->getRepresents(), "represents", getRepresents()->eClass() != uml::umlPackage::eInstance()->getElement_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ActivityPartitionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getActivityPartition_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ActivityPartitionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_EDGE:
		{
			return eAnyBag(getEdge(),uml::umlPackage::ACTIVITYEDGE_CLASS); //1320
		}
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_ISDIMENSION:
			return eAny(getIsDimension(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //1314
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_ISEXTERNAL:
			return eAny(getIsExternal(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //1315
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_NODE:
		{
			return eAnyBag(getNode(),uml::umlPackage::ACTIVITYNODE_CLASS); //1316
		}
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_REPRESENTS:
		{
			std::shared_ptr<ecore::EObject> returnValue=getRepresents();
			return eAny(returnValue,uml::umlPackage::ELEMENT_CLASS,false); //1317
		}
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUBPARTITION:
		{
			return eAnyBag(getSubpartition(),uml::umlPackage::ACTIVITYPARTITION_CLASS); //1318
		}
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getSuperPartition().lock();
			return eAny(returnValue,uml::umlPackage::ACTIVITYPARTITION_CLASS,false); //1319
		}
	}
	return ActivityGroupImpl::eGet(featureID, resolve, coreType);
}

bool ActivityPartitionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_EDGE:
			return getEdge() != nullptr; //1320
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_ISDIMENSION:
			return getIsDimension() != false; //1314
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_ISEXTERNAL:
			return getIsExternal() != false; //1315
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_NODE:
			return getNode() != nullptr; //1316
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_REPRESENTS:
			return getRepresents() != nullptr; //1317
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUBPARTITION:
			return getSubpartition() != nullptr; //1318
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION:
			return getSuperPartition().lock() != nullptr; //1319
	}
	return ActivityGroupImpl::internalEIsSet(featureID);
}

bool ActivityPartitionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_EDGE:
		{
			// CAST Any to Bag<uml::ActivityEdge>
			if((newValue->isContainer()) && (uml::umlPackage::ACTIVITYEDGE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ActivityEdge>> edgeList= newValue->get<std::shared_ptr<Bag<uml::ActivityEdge>>>();
					std::shared_ptr<Bag<uml::ActivityEdge>> _edge=getEdge();
					for(const std::shared_ptr<uml::ActivityEdge> indexEdge: *_edge)
					{
						if (edgeList->find(indexEdge) == -1)
						{
							_edge->erase(indexEdge);
						}
					}

					for(const std::shared_ptr<uml::ActivityEdge> indexEdge: *edgeList)
					{
						if (_edge->find(indexEdge) == -1)
						{
							_edge->add(indexEdge);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_ISDIMENSION:
		{
			// CAST Any to bool
			bool _isDimension = newValue->get<bool>();
			setIsDimension(_isDimension); //1314
			return true;
		}
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_ISEXTERNAL:
		{
			// CAST Any to bool
			bool _isExternal = newValue->get<bool>();
			setIsExternal(_isExternal); //1315
			return true;
		}
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_NODE:
		{
			// CAST Any to Bag<uml::ActivityNode>
			if((newValue->isContainer()) && (uml::umlPackage::ACTIVITYNODE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ActivityNode>> nodeList= newValue->get<std::shared_ptr<Bag<uml::ActivityNode>>>();
					std::shared_ptr<Bag<uml::ActivityNode>> _node=getNode();
					for(const std::shared_ptr<uml::ActivityNode> indexNode: *_node)
					{
						if (nodeList->find(indexNode) == -1)
						{
							_node->erase(indexNode);
						}
					}

					for(const std::shared_ptr<uml::ActivityNode> indexNode: *nodeList)
					{
						if (_node->find(indexNode) == -1)
						{
							_node->add(indexNode);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_REPRESENTS:
		{
			// CAST Any to uml::Element
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Element> _represents = std::dynamic_pointer_cast<uml::Element>(_temp);
			setRepresents(_represents); //1317
			return true;
		}
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUBPARTITION:
		{
			// CAST Any to Bag<uml::ActivityPartition>
			if((newValue->isContainer()) && (uml::umlPackage::ACTIVITYPARTITION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ActivityPartition>> subpartitionList= newValue->get<std::shared_ptr<Bag<uml::ActivityPartition>>>();
					std::shared_ptr<Bag<uml::ActivityPartition>> _subpartition=getSubpartition();
					for(const std::shared_ptr<uml::ActivityPartition> indexSubpartition: *_subpartition)
					{
						if (subpartitionList->find(indexSubpartition) == -1)
						{
							_subpartition->erase(indexSubpartition);
						}
					}

					for(const std::shared_ptr<uml::ActivityPartition> indexSubpartition: *subpartitionList)
					{
						if (_subpartition->find(indexSubpartition) == -1)
						{
							_subpartition->add(indexSubpartition);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::ACTIVITYPARTITION_ATTRIBUTE_SUPERPARTITION:
		{
			// CAST Any to uml::ActivityPartition
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ActivityPartition> _superPartition = std::dynamic_pointer_cast<uml::ActivityPartition>(_temp);
			setSuperPartition(_superPartition); //1319
			return true;
		}
	}

	return ActivityGroupImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ActivityPartitionImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::ActivityPartition::dimension_not_contained(Any, std::map) : bool: 1076567983
		case umlPackage::ACTIVITYPARTITION_OPERATION_DIMENSION_NOT_CONTAINED_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->dimension_not_contained(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ActivityPartition::represents_classifier(Any, std::map) : bool: 639011092
		case umlPackage::ACTIVITYPARTITION_OPERATION_REPRESENTS_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->represents_classifier(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ActivityPartition::represents_property(Any, std::map) : bool: 511389922
		case umlPackage::ACTIVITYPARTITION_OPERATION_REPRESENTS_PROPERTY_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->represents_property(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ActivityPartition::represents_property_and_is_contained(Any, std::map) : bool: 1105654129
		case umlPackage::ACTIVITYPARTITION_OPERATION_REPRESENTS_PROPERTY_AND_IS_CONTAINED_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->represents_property_and_is_contained(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ActivityGroupImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ActivityPartition> ActivityPartitionImpl::getThisActivityPartitionPtr() const
{
	return m_thisActivityPartitionPtr.lock();
}
void ActivityPartitionImpl::setThisActivityPartitionPtr(std::weak_ptr<uml::ActivityPartition> thisActivityPartitionPtr)
{
	m_thisActivityPartitionPtr = thisActivityPartitionPtr;
	setThisActivityGroupPtr(thisActivityPartitionPtr);
}


