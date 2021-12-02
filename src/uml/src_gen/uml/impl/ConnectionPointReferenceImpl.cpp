
#include "uml/impl/ConnectionPointReferenceImpl.hpp"

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

#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Pseudostate.hpp"
#include "uml/Region.hpp"
#include "uml/State.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Transition.hpp"
#include "uml/Vertex.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ConnectionPointReferenceImpl::~ConnectionPointReferenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConnectionPointReference "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::Region> par_container)
:ConnectionPointReferenceImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}

//Additional constructor for the containments back reference
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ConnectionPointReferenceImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::Element> par_owner)
:ConnectionPointReferenceImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::State> par_state)
:ConnectionPointReferenceImpl()
{
	m_state = par_state;
	m_namespace = par_state;
}

ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(const ConnectionPointReferenceImpl & obj): ConnectionPointReferenceImpl()
{
	*this = obj;
}

ConnectionPointReferenceImpl& ConnectionPointReferenceImpl::operator=(const ConnectionPointReferenceImpl & obj)
{
	//call overloaded =Operator for each base class
	VertexImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ConnectionPointReference 
	 * which is generated by the compiler (as ConnectionPointReference is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ConnectionPointReference::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConnectionPointReference "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_entry  = obj.getEntry();
	m_exit  = obj.getExit();
	m_state  = obj.getState();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ConnectionPointReferenceImpl::copy() const
{
	std::shared_ptr<ConnectionPointReferenceImpl> element(new ConnectionPointReferenceImpl());
	*element =(*this);
	element->setThisConnectionPointReferencePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool ConnectionPointReferenceImpl::entry_pseudostates(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectionPointReferenceImpl::exit_pseudostates(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
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
/* Getter & Setter for reference entry */
std::shared_ptr<Bag<uml::Pseudostate>> ConnectionPointReferenceImpl::getEntry() const
{
	if(m_entry == nullptr)
	{
		m_entry.reset(new Bag<uml::Pseudostate>());
		
		
	}
    return m_entry;
}

/* Getter & Setter for reference exit */
std::shared_ptr<Bag<uml::Pseudostate>> ConnectionPointReferenceImpl::getExit() const
{
	if(m_exit == nullptr)
	{
		m_exit.reset(new Bag<uml::Pseudostate>());
		
		
	}
    return m_exit;
}

/* Getter & Setter for reference state */
std::weak_ptr<uml::State> ConnectionPointReferenceImpl::getState() const
{
    return m_state;
}
void ConnectionPointReferenceImpl::setState(std::weak_ptr<uml::State> _state)
{
    m_state = _state;
	
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> ConnectionPointReferenceImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ConnectionPointReferenceImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ConnectionPointReferenceImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ConnectionPointReferenceImpl::eContainer() const
{
	if(auto wp = m_container.lock())
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

	if(auto wp = m_state.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ConnectionPointReferenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ConnectionPointReferenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("entry");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("entry")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("exit");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("exit")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	VertexImpl::loadAttributes(loadHandler, attr_list);
}

void ConnectionPointReferenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	VertexImpl::loadNode(nodeName, loadHandler);
}

void ConnectionPointReferenceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY:
		{
			std::shared_ptr<Bag<uml::Pseudostate>> _entry = getEntry();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Pseudostate>  _r = std::dynamic_pointer_cast<uml::Pseudostate>(ref);
				if (_r != nullptr)
				{
					_entry->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT:
		{
			std::shared_ptr<Bag<uml::Pseudostate>> _exit = getExit();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Pseudostate>  _r = std::dynamic_pointer_cast<uml::Pseudostate>(ref);
				if (_r != nullptr)
				{
					_exit->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>( references.front() );
				setState(_state);
			}
			
			return;
		}
	}
	VertexImpl::resolveReferences(featureID, references);
}

void ConnectionPointReferenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	VertexImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ConnectionPointReferenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::Pseudostate>("entry", this->getEntry());
		saveHandler->addReferences<uml::Pseudostate>("exit", this->getExit());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> ConnectionPointReferenceImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getConnectionPointReference_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ConnectionPointReferenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Pseudostate>::iterator iter = getEntry()->begin();
			Bag<uml::Pseudostate>::iterator end = getEntry()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5212			
		}
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Pseudostate>::iterator iter = getExit()->begin();
			Bag<uml::Pseudostate>::iterator end = getExit()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5213			
		}
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getState().lock();
			return eAny(returnValue); //5214
		}
	}
	return VertexImpl::eGet(featureID, resolve, coreType);
}

bool ConnectionPointReferenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY:
			return getEntry() != nullptr; //5212
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT:
			return getExit() != nullptr; //5213
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
			return getState().lock() != nullptr; //5214
	}
	return VertexImpl::internalEIsSet(featureID);
}

bool ConnectionPointReferenceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Pseudostate>> entryList(new Bag<uml::Pseudostate>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				entryList->add(std::dynamic_pointer_cast<uml::Pseudostate>(*iter));
				iter++;
			}
			
			Bag<uml::Pseudostate>::iterator iterEntry = getEntry()->begin();
			Bag<uml::Pseudostate>::iterator endEntry = getEntry()->end();
			while (iterEntry != endEntry)
			{
				if (entryList->find(*iterEntry) == -1)
				{
					getEntry()->erase(*iterEntry);
				}
				iterEntry++;
			}
 
			iterEntry = entryList->begin();
			endEntry = entryList->end();
			while (iterEntry != endEntry)
			{
				if (getEntry()->find(*iterEntry) == -1)
				{
					getEntry()->add(*iterEntry);
				}
				iterEntry++;			
			}
			return true;
		}
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Pseudostate>> exitList(new Bag<uml::Pseudostate>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				exitList->add(std::dynamic_pointer_cast<uml::Pseudostate>(*iter));
				iter++;
			}
			
			Bag<uml::Pseudostate>::iterator iterExit = getExit()->begin();
			Bag<uml::Pseudostate>::iterator endExit = getExit()->end();
			while (iterExit != endExit)
			{
				if (exitList->find(*iterExit) == -1)
				{
					getExit()->erase(*iterExit);
				}
				iterExit++;
			}
 
			iterExit = exitList->begin();
			endExit = exitList->end();
			while (iterExit != endExit)
			{
				if (getExit()->find(*iterExit) == -1)
				{
					getExit()->add(*iterExit);
				}
				iterExit++;			
			}
			return true;
		}
		case uml::umlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>(_temp);
			setState(_state); //5214
			return true;
		}
	}

	return VertexImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ConnectionPointReferenceImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 1348223732
		case umlPackage::CONNECTIONPOINTREFERENCE_OPERATION_ENTRY_PSEUDOSTATES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->entry_pseudostates(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 1938887954
		case umlPackage::CONNECTIONPOINTREFERENCE_OPERATION_EXIT_PSEUDOSTATES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->exit_pseudostates(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = VertexImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<uml::ConnectionPointReference> ConnectionPointReferenceImpl::getThisConnectionPointReferencePtr() const
{
	return m_thisConnectionPointReferencePtr.lock();
}
void ConnectionPointReferenceImpl::setThisConnectionPointReferencePtr(std::weak_ptr<uml::ConnectionPointReference> thisConnectionPointReferencePtr)
{
	m_thisConnectionPointReferencePtr = thisConnectionPointReferencePtr;
	setThisVertexPtr(thisConnectionPointReferencePtr);
}
