
#include "uml/impl/InstanceSpecificationImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"

#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/DeployedArtifact.hpp"
#include "uml/Deployment.hpp"
#include "uml/DeploymentTarget.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Slot.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InstanceSpecificationImpl::InstanceSpecificationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InstanceSpecificationImpl::~InstanceSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InstanceSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InstanceSpecificationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::Element> par_owner)
:InstanceSpecificationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::Package> par_owningPackage)
:InstanceSpecificationImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
InstanceSpecificationImpl::InstanceSpecificationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:InstanceSpecificationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

InstanceSpecificationImpl::InstanceSpecificationImpl(const InstanceSpecificationImpl & obj): InstanceSpecificationImpl()
{
	*this = obj;
}

InstanceSpecificationImpl& InstanceSpecificationImpl::operator=(const InstanceSpecificationImpl & obj)
{
	//call overloaded =Operator for each base class
	DeploymentTargetImpl::operator=(obj);
	PackageableElementImpl::operator=(obj);
	DeployedArtifactImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InstanceSpecification 
	 * which is generated by the compiler (as InstanceSpecification is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InstanceSpecification::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InstanceSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_classifier  = obj.getClassifier();
	//Clone references with containment (deep copy)
	//clone reference 'slot'
	std::shared_ptr<Subset<uml::Slot, uml::Element>> slotList = obj.getSlot();
	if(slotList)
	{
		/*Subset*/
		m_slot.reset(new Subset<uml::Slot, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_slot - Subset<uml::Slot, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getSlot()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_slot - Subset<uml::Slot, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Slot> slotindexElem: *slotList) 
		{
			std::shared_ptr<uml::Slot> temp = std::dynamic_pointer_cast<uml::Slot>((slotindexElem)->copy());
			m_slot->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr slot."<< std::endl;)
	}

	//clone reference 'specification'
	if(obj.getSpecification()!=nullptr)
	{
		m_specification = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getSpecification()->copy());
	}
	/*Subset*/
	getSlot()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_slot - Subset<uml::Slot, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> InstanceSpecificationImpl::copy() const
{
	std::shared_ptr<InstanceSpecificationImpl> element(new InstanceSpecificationImpl());
	*element =(*this);
	element->setThisInstanceSpecificationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool InstanceSpecificationImpl::defining_feature(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InstanceSpecificationImpl::deployment_artifact(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InstanceSpecificationImpl::deployment_target(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InstanceSpecificationImpl::structural_feature(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference classifier */
std::shared_ptr<Bag<uml::Classifier>> InstanceSpecificationImpl::getClassifier() const
{
	if(m_classifier == nullptr)
	{
		m_classifier.reset(new Bag<uml::Classifier>());
		
		
	}
    return m_classifier;
}

/* Getter & Setter for reference slot */
std::shared_ptr<Subset<uml::Slot, uml::Element>> InstanceSpecificationImpl::getSlot() const
{
	if(m_slot == nullptr)
	{
		/*Subset*/
		m_slot.reset(new Subset<uml::Slot, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_slot - Subset<uml::Slot, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getSlot()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_slot - Subset<uml::Slot, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_slot;
}

/* Getter & Setter for reference specification */
std::shared_ptr<uml::ValueSpecification> InstanceSpecificationImpl::getSpecification() const
{
    return m_specification;
}
void InstanceSpecificationImpl::setSpecification(std::shared_ptr<uml::ValueSpecification> _specification)
{
    m_specification = _specification;
	
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> InstanceSpecificationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> InstanceSpecificationImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> InstanceSpecificationImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InstanceSpecificationImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void InstanceSpecificationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InstanceSpecificationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("classifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("classifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DeployedArtifactImpl::loadAttributes(loadHandler, attr_list);
	DeploymentTargetImpl::loadAttributes(loadHandler, attr_list);
	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
}

void InstanceSpecificationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("slot") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Slot";
			}
			loadHandler->handleChildContainer<uml::Slot>(this->getSlot());  

			return; 
		}

		if ( nodeName.compare("specification") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getSpecification()); 

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
	DeployedArtifactImpl::loadNode(nodeName, loadHandler);
	DeploymentTargetImpl::loadNode(nodeName, loadHandler);
	PackageableElementImpl::loadNode(nodeName, loadHandler);
}

void InstanceSpecificationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::INSTANCESPECIFICATION_ATTRIBUTE_CLASSIFIER:
		{
			std::shared_ptr<Bag<uml::Classifier>> _classifier = getClassifier();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_classifier->push_back(_r);
				}
			}
			return;
		}
	}
	DeployedArtifactImpl::resolveReferences(featureID, references);
	DeploymentTargetImpl::resolveReferences(featureID, references);
	PackageableElementImpl::resolveReferences(featureID, references);
}

void InstanceSpecificationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DeployedArtifactImpl::saveContent(saveHandler);
	DeploymentTargetImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void InstanceSpecificationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'slot'
		for (std::shared_ptr<uml::Slot> slot : *this->getSlot()) 
		{
			saveHandler->addReference(slot, "slot", slot->eClass() != package->getSlot_Class());
		}

		// Save 'specification'
		std::shared_ptr<uml::ValueSpecification> specification = this->getSpecification();
		if (specification != nullptr)
		{
			saveHandler->addReference(specification, "specification", specification->eClass() != package->getValueSpecification_Class());
		}
	// Add references
		saveHandler->addReferences<uml::Classifier>("classifier", this->getClassifier());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> InstanceSpecificationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInstanceSpecification_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any InstanceSpecificationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INSTANCESPECIFICATION_ATTRIBUTE_CLASSIFIER:
		{
			return eAnyBag(getClassifier(),845259359); //11714
		}
		case uml::umlPackage::INSTANCESPECIFICATION_ATTRIBUTE_SLOT:
		{
			return eAnyBag(getSlot(),1292161953); //11715
		}
		case uml::umlPackage::INSTANCESPECIFICATION_ATTRIBUTE_SPECIFICATION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getSpecification();
			return eAny(returnValue,returnValue->getMetaElementID(),false); //11716
		}
	}
	Any result;
	result = DeployedArtifactImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = DeploymentTargetImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = PackageableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool InstanceSpecificationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INSTANCESPECIFICATION_ATTRIBUTE_CLASSIFIER:
			return getClassifier() != nullptr; //11714
		case uml::umlPackage::INSTANCESPECIFICATION_ATTRIBUTE_SLOT:
			return getSlot() != nullptr; //11715
		case uml::umlPackage::INSTANCESPECIFICATION_ATTRIBUTE_SPECIFICATION:
			return getSpecification() != nullptr; //11716
	}
	bool result = false;
	result = DeployedArtifactImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = DeploymentTargetImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = PackageableElementImpl::internalEIsSet(featureID);
	return result;
}

bool InstanceSpecificationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INSTANCESPECIFICATION_ATTRIBUTE_CLASSIFIER:
		{
			// BOOST CAST
			if((newValue->isContainer()) && (uml::umlPackage::CLASSIFIER_CLASS ==newValue->getTypeId()))
			{
				try
				{
					std::shared_ptr<Bag<uml::Classifier>> classifierList= newValue->get<std::shared_ptr<Bag<uml::Classifier>>>();
					std::shared_ptr<Bag<uml::Classifier>> _classifier=getClassifier();
					for(const std::shared_ptr<uml::Classifier> indexClassifier: *_classifier)
					{
						if (classifierList->find(indexClassifier) == -1)
						{
							_classifier->erase(indexClassifier);
						}
					}

					for(const std::shared_ptr<uml::Classifier> indexClassifier: *classifierList)
					{
						if (_classifier->find(indexClassifier) == -1)
						{
							_classifier->add(indexClassifier);
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
		case uml::umlPackage::INSTANCESPECIFICATION_ATTRIBUTE_SLOT:
		{
			// BOOST CAST
			if((newValue->isContainer()) && (uml::umlPackage::SLOT_CLASS ==newValue->getTypeId()))
			{
				try
				{
					std::shared_ptr<Bag<uml::Slot>> slotList= newValue->get<std::shared_ptr<Bag<uml::Slot>>>();
					std::shared_ptr<Bag<uml::Slot>> _slot=getSlot();
					for(const std::shared_ptr<uml::Slot> indexSlot: *_slot)
					{
						if (slotList->find(indexSlot) == -1)
						{
							_slot->erase(indexSlot);
						}
					}

					for(const std::shared_ptr<uml::Slot> indexSlot: *slotList)
					{
						if (_slot->find(indexSlot) == -1)
						{
							_slot->add(indexSlot);
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
		case uml::umlPackage::INSTANCESPECIFICATION_ATTRIBUTE_SPECIFICATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _specification = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setSpecification(_specification); //11716
			return true;
		}
	}

	bool result = false;
	result = DeployedArtifactImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = DeploymentTargetImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = PackageableElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
Any InstanceSpecificationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::InstanceSpecification::defining_feature(Any, std::map) : bool: 305091535
		case umlPackage::INSTANCESPECIFICATION_OPERATION_DEFINING_FEATURE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->defining_feature(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::InstanceSpecification::deployment_artifact(Any, std::map) : bool: 2089426612
		case umlPackage::INSTANCESPECIFICATION_OPERATION_DEPLOYMENT_ARTIFACT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->deployment_artifact(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::InstanceSpecification::deployment_target(Any, std::map) : bool: 1332220925
		case umlPackage::INSTANCESPECIFICATION_OPERATION_DEPLOYMENT_TARGET_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->deployment_target(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::InstanceSpecification::structural_feature(Any, std::map) : bool: 1699332849
		case umlPackage::INSTANCESPECIFICATION_OPERATION_STRUCTURAL_FEATURE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->structural_feature(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = DeployedArtifactImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = PackageableElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = DeploymentTargetImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::InstanceSpecification> InstanceSpecificationImpl::getThisInstanceSpecificationPtr() const
{
	return m_thisInstanceSpecificationPtr.lock();
}
void InstanceSpecificationImpl::setThisInstanceSpecificationPtr(std::weak_ptr<uml::InstanceSpecification> thisInstanceSpecificationPtr)
{
	m_thisInstanceSpecificationPtr = thisInstanceSpecificationPtr;
	setThisDeployedArtifactPtr(thisInstanceSpecificationPtr);
	setThisDeploymentTargetPtr(thisInstanceSpecificationPtr);
	setThisPackageableElementPtr(thisInstanceSpecificationPtr);
}


