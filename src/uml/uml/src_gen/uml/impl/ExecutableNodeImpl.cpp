
#include "uml/impl/ExecutableNodeImpl.hpp"

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
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExecutableNodeImpl::ExecutableNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExecutableNodeImpl::~ExecutableNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutableNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExecutableNodeImpl::ExecutableNodeImpl(std::weak_ptr<uml::Activity> par_activity)
:ExecutableNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ExecutableNodeImpl::ExecutableNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ExecutableNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ExecutableNodeImpl::ExecutableNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ExecutableNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExecutableNodeImpl::ExecutableNodeImpl(std::weak_ptr<uml::Element> par_owner)
:ExecutableNodeImpl()
{
	m_owner = par_owner;
}

ExecutableNodeImpl::ExecutableNodeImpl(const ExecutableNodeImpl & obj): ExecutableNodeImpl()
{
	*this = obj;
}

ExecutableNodeImpl& ExecutableNodeImpl::operator=(const ExecutableNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	ActivityNodeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ExecutableNode 
	 * which is generated by the compiler (as ExecutableNode is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ExecutableNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutableNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'handler'
	std::shared_ptr<Subset<uml::ExceptionHandler, uml::Element>> handlerList = obj.getHandler();
	if(handlerList)
	{
		/*Subset*/
		m_handler.reset(new Subset<uml::ExceptionHandler, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getHandler()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ExceptionHandler> handlerindexElem: *handlerList) 
		{
			std::shared_ptr<uml::ExceptionHandler> temp = std::dynamic_pointer_cast<uml::ExceptionHandler>((handlerindexElem)->copy());
			m_handler->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr handler."<< std::endl;)
	}
	/*Subset*/
	getHandler()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference handler */
std::shared_ptr<Subset<uml::ExceptionHandler, uml::Element>> ExecutableNodeImpl::getHandler() const
{
	if(m_handler == nullptr)
	{
		/*Subset*/
		m_handler.reset(new Subset<uml::ExceptionHandler, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getHandler()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_handler;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ExecutableNodeImpl::getInGroup() const
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

std::shared_ptr<Union<uml::Element>> ExecutableNodeImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ExecutableNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ExecutableNodeImpl::getRedefinedElement() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExecutableNodeImpl::eContainer() const
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
// Persistence Functions
//*********************************
void ExecutableNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExecutableNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActivityNodeImpl::loadAttributes(loadHandler, attr_list);
}

void ExecutableNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("handler") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ExceptionHandler";
			}
			loadHandler->handleChildContainer<uml::ExceptionHandler>(this->getHandler());  

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
	ActivityNodeImpl::loadNode(nodeName, loadHandler);
}

void ExecutableNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ActivityNodeImpl::resolveReferences(featureID, references);
}

void ExecutableNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExecutableNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'handler'
		for (std::shared_ptr<uml::ExceptionHandler> handler : *this->getHandler()) 
		{
			saveHandler->addReference(handler, "handler", handler->eClass() != package->getExceptionHandler_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ExecutableNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExecutableNode_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ExecutableNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXECUTABLENODE_ATTRIBUTE_HANDLER:
			return eAnyBag(getHandler(),uml::umlPackage::EXCEPTIONHANDLER_CLASS); //8820
	}
	return ActivityNodeImpl::eGet(featureID, resolve, coreType);
}

bool ExecutableNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXECUTABLENODE_ATTRIBUTE_HANDLER:
			return getHandler() != nullptr; //8820
	}
	return ActivityNodeImpl::internalEIsSet(featureID);
}

bool ExecutableNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::EXECUTABLENODE_ATTRIBUTE_HANDLER:
		{
			// CAST Any to Bag<uml::ExceptionHandler>
			if((newValue->isContainer()) && (uml::umlPackage::EXCEPTIONHANDLER_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ExceptionHandler>> handlerList= newValue->get<std::shared_ptr<Bag<uml::ExceptionHandler>>>();
					std::shared_ptr<Bag<uml::ExceptionHandler>> _handler=getHandler();
					for(const std::shared_ptr<uml::ExceptionHandler> indexHandler: *_handler)
					{
						if (handlerList->find(indexHandler) == -1)
						{
							_handler->erase(indexHandler);
						}
					}

					for(const std::shared_ptr<uml::ExceptionHandler> indexHandler: *handlerList)
					{
						if (_handler->find(indexHandler) == -1)
						{
							_handler->add(indexHandler);
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
	}

	return ActivityNodeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ExecutableNodeImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ActivityNodeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ExecutableNode> ExecutableNodeImpl::getThisExecutableNodePtr() const
{
	return m_thisExecutableNodePtr.lock();
}
void ExecutableNodeImpl::setThisExecutableNodePtr(std::weak_ptr<uml::ExecutableNode> thisExecutableNodePtr)
{
	m_thisExecutableNodePtr = thisExecutableNodePtr;
	setThisActivityNodePtr(thisExecutableNodePtr);
}


