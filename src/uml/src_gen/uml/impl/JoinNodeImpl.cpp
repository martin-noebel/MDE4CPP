#include "uml/impl/JoinNodeImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"


#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/ControlNode.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
JoinNodeImpl::JoinNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

JoinNodeImpl::~JoinNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete JoinNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
JoinNodeImpl::JoinNodeImpl(std::weak_ptr<uml::Activity> par_activity)
:JoinNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
JoinNodeImpl::JoinNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:JoinNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
JoinNodeImpl::JoinNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:JoinNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
JoinNodeImpl::JoinNodeImpl(std::weak_ptr<uml::Element> par_owner)
:JoinNodeImpl()
{
	m_owner = par_owner;
}

JoinNodeImpl::JoinNodeImpl(const JoinNodeImpl & obj): JoinNodeImpl()
{
	*this = obj;
}

JoinNodeImpl& JoinNodeImpl::operator=(const JoinNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	ControlNodeImpl::operator=(obj);
	JoinNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy JoinNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isCombineDuplicate = obj.getIsCombineDuplicate();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	if(obj.getJoinSpec()!=nullptr)
	{
		m_joinSpec = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getJoinSpec()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> JoinNodeImpl::copy() const
{
	std::shared_ptr<JoinNodeImpl> element(new JoinNodeImpl());
	*element =(*this);
	element->setThisJoinNodePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> JoinNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getJoinNode_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isCombineDuplicate
*/
bool JoinNodeImpl::getIsCombineDuplicate() const 
{
	return m_isCombineDuplicate;
}
void JoinNodeImpl::setIsCombineDuplicate(bool _isCombineDuplicate)
{
	m_isCombineDuplicate = _isCombineDuplicate;
} 


//*********************************
// Operations
//*********************************
bool JoinNodeImpl::incoming_object_flow(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool JoinNodeImpl::one_outgoing_edge(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference joinSpec
*/
std::shared_ptr<uml::ValueSpecification> JoinNodeImpl::getJoinSpec() const
{

    return m_joinSpec;
}
void JoinNodeImpl::setJoinSpec(std::shared_ptr<uml::ValueSpecification> _joinSpec)
{
    m_joinSpec = _joinSpec;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> JoinNodeImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<Union<uml::Element>> JoinNodeImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> JoinNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> JoinNodeImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<JoinNode> JoinNodeImpl::getThisJoinNodePtr() const
{
	return m_thisJoinNodePtr.lock();
}
void JoinNodeImpl::setThisJoinNodePtr(std::weak_ptr<JoinNode> thisJoinNodePtr)
{
	m_thisJoinNodePtr = thisJoinNodePtr;
	setThisControlNodePtr(thisJoinNodePtr);
}
std::shared_ptr<ecore::EObject> JoinNodeImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any JoinNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::JOINNODE_ATTRIBUTE_ISCOMBINEDUPLICATE:
			return eAny(getIsCombineDuplicate()); //13120
		case uml::umlPackage::JOINNODE_ATTRIBUTE_JOINSPEC:
			return eAny(getJoinSpec()); //13121
	}
	return ControlNodeImpl::eGet(featureID, resolve, coreType);
}
bool JoinNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::JOINNODE_ATTRIBUTE_ISCOMBINEDUPLICATE:
			return getIsCombineDuplicate() != true; //13120
		case uml::umlPackage::JOINNODE_ATTRIBUTE_JOINSPEC:
			return getJoinSpec() != nullptr; //13121
	}
	return ControlNodeImpl::internalEIsSet(featureID);
}
bool JoinNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::JOINNODE_ATTRIBUTE_ISCOMBINEDUPLICATE:
		{
			// BOOST CAST
			bool _isCombineDuplicate = newValue->get<bool>();
			setIsCombineDuplicate(_isCombineDuplicate); //13120
			return true;
		}
		case uml::umlPackage::JOINNODE_ATTRIBUTE_JOINSPEC:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _joinSpec = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setJoinSpec(_joinSpec); //13121
			return true;
		}
	}

	return ControlNodeImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any JoinNodeImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 13185
		case umlPackage::JOINNODE_OPERATION_INCOMING_OBJECT_FLOW_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->incoming_object_flow(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 13184
		case umlPackage::JOINNODE_OPERATION_ONE_OUTGOING_EDGE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->one_outgoing_edge(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = ControlNodeImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void JoinNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void JoinNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isCombineDuplicate");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsCombineDuplicate(value);
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

	ControlNodeImpl::loadAttributes(loadHandler, attr_list);
}

void JoinNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("joinSpec") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getJoinSpec()); 

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
	ControlNodeImpl::loadNode(nodeName, loadHandler);
}

void JoinNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ControlNodeImpl::resolveReferences(featureID, references);
}

void JoinNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ControlNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void JoinNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'joinSpec'
		std::shared_ptr<uml::ValueSpecification> joinSpec = this->getJoinSpec();
		if (joinSpec != nullptr)
		{
			saveHandler->addReference(joinSpec, "joinSpec", joinSpec->eClass() != package->getValueSpecification_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getJoinNode_Attribute_isCombineDuplicate()) )
		{
			saveHandler->addAttribute("isCombineDuplicate", this->getIsCombineDuplicate());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

