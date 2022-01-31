
#include "uml/impl/CollaborationUseImpl.hpp"

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
#include "uml/Collaboration.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
CollaborationUseImpl::CollaborationUseImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollaborationUseImpl::~CollaborationUseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollaborationUse "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CollaborationUseImpl::CollaborationUseImpl(std::weak_ptr<uml::Namespace> par_namespace)
:CollaborationUseImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
CollaborationUseImpl::CollaborationUseImpl(std::weak_ptr<uml::Element> par_owner)
:CollaborationUseImpl()
{
	m_owner = par_owner;
}

CollaborationUseImpl::CollaborationUseImpl(const CollaborationUseImpl & obj): CollaborationUseImpl()
{
	*this = obj;
}

CollaborationUseImpl& CollaborationUseImpl::operator=(const CollaborationUseImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CollaborationUse 
	 * which is generated by the compiler (as CollaborationUse is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CollaborationUse::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollaborationUse "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_type  = obj.getType();
	//Clone references with containment (deep copy)
	//clone reference 'roleBinding'
	std::shared_ptr<Subset<uml::Dependency, uml::Element>> roleBindingList = obj.getRoleBinding();
	if(roleBindingList)
	{
		/*Subset*/
		m_roleBinding.reset(new Subset<uml::Dependency, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_roleBinding - Subset<uml::Dependency, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getRoleBinding()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_roleBinding - Subset<uml::Dependency, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Dependency> roleBindingindexElem: *roleBindingList) 
		{
			std::shared_ptr<uml::Dependency> temp = std::dynamic_pointer_cast<uml::Dependency>((roleBindingindexElem)->copy());
			m_roleBinding->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr roleBinding."<< std::endl;)
	}
	/*Subset*/
	getRoleBinding()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_roleBinding - Subset<uml::Dependency, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> CollaborationUseImpl::copy() const
{
	std::shared_ptr<CollaborationUseImpl> element(new CollaborationUseImpl());
	*element =(*this);
	element->setThisCollaborationUsePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool CollaborationUseImpl::client_elements(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool CollaborationUseImpl::connectors(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool CollaborationUseImpl::every_role(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference roleBinding */
std::shared_ptr<Subset<uml::Dependency, uml::Element>> CollaborationUseImpl::getRoleBinding() const
{
	if(m_roleBinding == nullptr)
	{
		/*Subset*/
		m_roleBinding.reset(new Subset<uml::Dependency, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_roleBinding - Subset<uml::Dependency, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getRoleBinding()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_roleBinding - Subset<uml::Dependency, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_roleBinding;
}

/* Getter & Setter for reference type */
std::shared_ptr<uml::Collaboration> CollaborationUseImpl::getType() const
{
    return m_type;
}
void CollaborationUseImpl::setType(std::shared_ptr<uml::Collaboration> _type)
{
    m_type = _type;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> CollaborationUseImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> CollaborationUseImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CollaborationUseImpl::eContainer() const
{
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
// Persistence Functions
//*********************************
void CollaborationUseImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollaborationUseImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("type");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("type")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void CollaborationUseImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("roleBinding") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Dependency";
			}
			loadHandler->handleChildContainer<uml::Dependency>(this->getRoleBinding());  

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
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void CollaborationUseImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::COLLABORATIONUSE_ATTRIBUTE_TYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Collaboration> _type = std::dynamic_pointer_cast<uml::Collaboration>( references.front() );
				setType(_type);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void CollaborationUseImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CollaborationUseImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'roleBinding'
		for (std::shared_ptr<uml::Dependency> roleBinding : *this->getRoleBinding()) 
		{
			saveHandler->addReference(roleBinding, "roleBinding", roleBinding->eClass() != package->getDependency_Class());
		}
	// Add references
		saveHandler->addReference(this->getType(), "type", getType()->eClass() != uml::umlPackage::eInstance()->getCollaboration_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CollaborationUseImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getCollaborationUse_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CollaborationUseImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::COLLABORATIONUSE_ATTRIBUTE_ROLEBINDING:
			return eAnyBag(getRoleBinding(),uml::umlPackage::DEPENDENCY_CLASS); //439
		case uml::umlPackage::COLLABORATIONUSE_ATTRIBUTE_TYPE:
			return eAny(getType(),uml::umlPackage::COLLABORATION_CLASS,false); //4310
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}

bool CollaborationUseImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::COLLABORATIONUSE_ATTRIBUTE_ROLEBINDING:
			return getRoleBinding() != nullptr; //439
		case uml::umlPackage::COLLABORATIONUSE_ATTRIBUTE_TYPE:
			return getType() != nullptr; //4310
	}
	return NamedElementImpl::internalEIsSet(featureID);
}

bool CollaborationUseImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::COLLABORATIONUSE_ATTRIBUTE_ROLEBINDING:
		{
			// CAST Any to Bag<uml::Dependency>
			if((newValue->isContainer()) && (uml::umlPackage::DEPENDENCY_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Dependency>> roleBindingList= newValue->get<std::shared_ptr<Bag<uml::Dependency>>>();
					std::shared_ptr<Bag<uml::Dependency>> _roleBinding=getRoleBinding();
					for(const std::shared_ptr<uml::Dependency> indexRoleBinding: *_roleBinding)
					{
						if (roleBindingList->find(indexRoleBinding) == -1)
						{
							_roleBinding->erase(indexRoleBinding);
						}
					}

					for(const std::shared_ptr<uml::Dependency> indexRoleBinding: *roleBindingList)
					{
						if (_roleBinding->find(indexRoleBinding) == -1)
						{
							_roleBinding->add(indexRoleBinding);
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
		case uml::umlPackage::COLLABORATIONUSE_ATTRIBUTE_TYPE:
		{
			// CAST Any to uml::Collaboration
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Collaboration> _type = std::dynamic_pointer_cast<uml::Collaboration>(_temp);
			setType(_type); //4310
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CollaborationUseImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::CollaborationUse::client_elements(Any, std::map) : bool: 123075857
		case umlPackage::COLLABORATIONUSE_OPERATION_CLIENT_ELEMENTS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->client_elements(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::CollaborationUse::connectors(Any, std::map) : bool: 851332840
		case umlPackage::COLLABORATIONUSE_OPERATION_CONNECTORS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->connectors(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::CollaborationUse::every_role(Any, std::map) : bool: 1617953717
		case umlPackage::COLLABORATIONUSE_OPERATION_EVERY_ROLE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->every_role(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::CollaborationUse> CollaborationUseImpl::getThisCollaborationUsePtr() const
{
	return m_thisCollaborationUsePtr.lock();
}
void CollaborationUseImpl::setThisCollaborationUsePtr(std::weak_ptr<uml::CollaborationUse> thisCollaborationUsePtr)
{
	m_thisCollaborationUsePtr = thisCollaborationUsePtr;
	setThisNamedElementPtr(thisCollaborationUsePtr);
}


