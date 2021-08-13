#include "uml/impl/StateImpl.hpp"

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

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectionPointReference.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Pseudostate.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/Region.hpp"
#include "uml/State.hpp"
#include "uml/StateMachine.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Transition.hpp"
#include "uml/Trigger.hpp"
#include "uml/Vertex.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StateImpl::StateImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StateImpl::~StateImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete State "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StateImpl::StateImpl(std::weak_ptr<uml::Region> par_container)
:StateImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}

//Additional constructor for the containments back reference
StateImpl::StateImpl(std::weak_ptr<uml::Namespace> par_namespace)
:StateImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StateImpl::StateImpl(std::weak_ptr<uml::Element> par_owner)
:StateImpl()
{
	m_owner = par_owner;
}

StateImpl::StateImpl(const StateImpl & obj): StateImpl()
{
	*this = obj;
}

StateImpl& StateImpl::operator=(const StateImpl & obj)
{
	//call overloaded =Operator for each base class
	NamespaceImpl::operator=(obj);
	RedefinableElementImpl::operator=(obj);
	VertexImpl::operator=(obj);
	State::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy State "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isComposite = obj.getIsComposite();
	m_isOrthogonal = obj.getIsOrthogonal();
	m_isSimple = obj.getIsSimple();
	m_isSubmachineState = obj.getIsSubmachineState();

	//copy references with no containment (soft copy)
	m_submachine  = obj.getSubmachine();
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::ConnectionPointReference, uml::NamedElement>> connectionContainer = getConnection();
	if(nullptr != connectionContainer )
	{
		int size = connectionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _connection=(*connectionContainer)[i];
			if(nullptr != _connection)
			{
				connectionContainer->push_back(std::dynamic_pointer_cast<uml::ConnectionPointReference>(_connection->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container connection."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr connection."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>> connectionPointContainer = getConnectionPoint();
	if(nullptr != connectionPointContainer )
	{
		int size = connectionPointContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _connectionPoint=(*connectionPointContainer)[i];
			if(nullptr != _connectionPoint)
			{
				connectionPointContainer->push_back(std::dynamic_pointer_cast<uml::Pseudostate>(_connectionPoint->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container connectionPoint."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr connectionPoint."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Trigger, uml::Element>> deferrableTriggerContainer = getDeferrableTrigger();
	if(nullptr != deferrableTriggerContainer )
	{
		int size = deferrableTriggerContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _deferrableTrigger=(*deferrableTriggerContainer)[i];
			if(nullptr != _deferrableTrigger)
			{
				deferrableTriggerContainer->push_back(std::dynamic_pointer_cast<uml::Trigger>(_deferrableTrigger->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container deferrableTrigger."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr deferrableTrigger."<< std::endl;)
	}
	if(obj.getDoActivity()!=nullptr)
	{
		m_doActivity = std::dynamic_pointer_cast<uml::Behavior>(obj.getDoActivity()->copy());
	}
	if(obj.getEntry()!=nullptr)
	{
		m_entry = std::dynamic_pointer_cast<uml::Behavior>(obj.getEntry()->copy());
	}
	if(obj.getExit()!=nullptr)
	{
		m_exit = std::dynamic_pointer_cast<uml::Behavior>(obj.getExit()->copy());
	}
	if(obj.getRedefinedState()!=nullptr)
	{
		m_redefinedState = std::dynamic_pointer_cast<uml::State>(obj.getRedefinedState()->copy());
	}
	std::shared_ptr<Subset<uml::Region, uml::NamedElement>> regionContainer = getRegion();
	if(nullptr != regionContainer )
	{
		int size = regionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _region=(*regionContainer)[i];
			if(nullptr != _region)
			{
				regionContainer->push_back(std::dynamic_pointer_cast<uml::Region>(_region->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container region."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr region."<< std::endl;)
	}
	if(obj.getStateInvariant()!=nullptr)
	{
		m_stateInvariant = std::dynamic_pointer_cast<uml::Constraint>(obj.getStateInvariant()->copy());
	}
	/*Subset*/
	m_connection->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_connection - Subset<uml::ConnectionPointReference, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_connectionPoint->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_deferrableTrigger->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_deferrableTrigger - Subset<uml::Trigger, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	
	
	
	/*Subset*/
	m_region->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> StateImpl::copy() const
{
	std::shared_ptr<StateImpl> element(new StateImpl());
	*element =(*this);
	element->setThisStatePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StateImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getState_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isComposite
*/
bool StateImpl::getIsComposite() const 
{
	return m_isComposite;
}



/*
Getter & Setter for attribute isOrthogonal
*/
bool StateImpl::getIsOrthogonal() const 
{
	return m_isOrthogonal;
}



/*
Getter & Setter for attribute isSimple
*/
bool StateImpl::getIsSimple() const 
{
	return m_isSimple;
}



/*
Getter & Setter for attribute isSubmachineState
*/
bool StateImpl::getIsSubmachineState() const 
{
	return m_isSubmachineState;
}



//*********************************
// Operations
//*********************************
bool StateImpl::composite_states(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::destinations_or_sources_of_transitions(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::entry_or_exit(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::isComposite()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::isOrthogonal()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::isSimple()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::isSubmachineState()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Classifier> StateImpl::redefinitionContext()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::submachine_or_regions(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StateImpl::submachine_states(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference connection
*/
std::shared_ptr<Subset<uml::ConnectionPointReference, uml::NamedElement>> StateImpl::getConnection() const
{
	if(m_connection == nullptr)
	{
		/*Subset*/
		m_connection.reset(new Subset<uml::ConnectionPointReference, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_connection - Subset<uml::ConnectionPointReference, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_connection->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_connection - Subset<uml::ConnectionPointReference, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_connection;
}



/*
Getter & Setter for reference connectionPoint
*/
std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>> StateImpl::getConnectionPoint() const
{
	if(m_connectionPoint == nullptr)
	{
		/*Subset*/
		m_connectionPoint.reset(new Subset<uml::Pseudostate, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_connectionPoint->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_connectionPoint - Subset<uml::Pseudostate, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_connectionPoint;
}



/*
Getter & Setter for reference deferrableTrigger
*/
std::shared_ptr<Subset<uml::Trigger, uml::Element>> StateImpl::getDeferrableTrigger() const
{
	if(m_deferrableTrigger == nullptr)
	{
		/*Subset*/
		m_deferrableTrigger.reset(new Subset<uml::Trigger, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_deferrableTrigger - Subset<uml::Trigger, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_deferrableTrigger->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_deferrableTrigger - Subset<uml::Trigger, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_deferrableTrigger;
}



/*
Getter & Setter for reference doActivity
*/
std::shared_ptr<uml::Behavior> StateImpl::getDoActivity() const
{

    return m_doActivity;
}
void StateImpl::setDoActivity(std::shared_ptr<uml::Behavior> _doActivity)
{
    m_doActivity = _doActivity;
	
	
}


/*
Getter & Setter for reference entry
*/
std::shared_ptr<uml::Behavior> StateImpl::getEntry() const
{

    return m_entry;
}
void StateImpl::setEntry(std::shared_ptr<uml::Behavior> _entry)
{
    m_entry = _entry;
	
	
}


/*
Getter & Setter for reference exit
*/
std::shared_ptr<uml::Behavior> StateImpl::getExit() const
{

    return m_exit;
}
void StateImpl::setExit(std::shared_ptr<uml::Behavior> _exit)
{
    m_exit = _exit;
	
	
}


/*
Getter & Setter for reference redefinedState
*/
std::shared_ptr<uml::State> StateImpl::getRedefinedState() const
{

    return m_redefinedState;
}
void StateImpl::setRedefinedState(std::shared_ptr<uml::State> _redefinedState)
{
    m_redefinedState = _redefinedState;
	
	
}


/*
Getter & Setter for reference region
*/
std::shared_ptr<Subset<uml::Region, uml::NamedElement>> StateImpl::getRegion() const
{
	if(m_region == nullptr)
	{
		/*Subset*/
		m_region.reset(new Subset<uml::Region, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_region->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_region - Subset<uml::Region, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_region;
}



/*
Getter & Setter for reference stateInvariant
*/
std::shared_ptr<uml::Constraint> StateImpl::getStateInvariant() const
{

    return m_stateInvariant;
}
void StateImpl::setStateInvariant(std::shared_ptr<uml::Constraint> _stateInvariant)
{
    m_stateInvariant = _stateInvariant;
	
	
	
	
	
}


/*
Getter & Setter for reference submachine
*/
std::shared_ptr<uml::StateMachine> StateImpl::getSubmachine() const
{

    return m_submachine;
}
void StateImpl::setSubmachine(std::shared_ptr<uml::StateMachine> _submachine)
{
    m_submachine = _submachine;
	
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> StateImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> StateImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> StateImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> StateImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> StateImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> StateImpl::getRedefinedElement() const
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




std::shared_ptr<State> StateImpl::getThisStatePtr() const
{
	return m_thisStatePtr.lock();
}
void StateImpl::setThisStatePtr(std::weak_ptr<State> thisStatePtr)
{
	m_thisStatePtr = thisStatePtr;
	setThisNamespacePtr(thisStatePtr);
	setThisRedefinableElementPtr(thisStatePtr);
	setThisVertexPtr(thisStatePtr);
}
std::shared_ptr<ecore::EObject> StateImpl::eContainer() const
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any StateImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STATE_ATTRIBUTE_CONNECTION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ConnectionPointReference>::iterator iter = getConnection()->begin();
			Bag<uml::ConnectionPointReference>::iterator end = getConnection()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22021			
		}
		case uml::umlPackage::STATE_ATTRIBUTE_CONNECTIONPOINT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Pseudostate>::iterator iter = getConnectionPoint()->begin();
			Bag<uml::Pseudostate>::iterator end = getConnectionPoint()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22022			
		}
		case uml::umlPackage::STATE_ATTRIBUTE_DEFERRABLETRIGGER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Trigger>::iterator iter = getDeferrableTrigger()->begin();
			Bag<uml::Trigger>::iterator end = getDeferrableTrigger()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22023			
		}
		case uml::umlPackage::STATE_ATTRIBUTE_DOACTIVITY:
			{
				std::shared_ptr<ecore::EObject> returnValue=getDoActivity();
				return eAny(returnValue); //22024
			}
		case uml::umlPackage::STATE_ATTRIBUTE_ENTRY:
			{
				std::shared_ptr<ecore::EObject> returnValue=getEntry();
				return eAny(returnValue); //22025
			}
		case uml::umlPackage::STATE_ATTRIBUTE_EXIT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getExit();
				return eAny(returnValue); //22026
			}
		case uml::umlPackage::STATE_ATTRIBUTE_ISCOMPOSITE:
			return eAny(getIsComposite()); //22027
		case uml::umlPackage::STATE_ATTRIBUTE_ISORTHOGONAL:
			return eAny(getIsOrthogonal()); //22028
		case uml::umlPackage::STATE_ATTRIBUTE_ISSIMPLE:
			return eAny(getIsSimple()); //22029
		case uml::umlPackage::STATE_ATTRIBUTE_ISSUBMACHINESTATE:
			return eAny(getIsSubmachineState()); //22030
		case uml::umlPackage::STATE_ATTRIBUTE_REDEFINEDSTATE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getRedefinedState();
				return eAny(returnValue); //22031
			}
		case uml::umlPackage::STATE_ATTRIBUTE_REGION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Region>::iterator iter = getRegion()->begin();
			Bag<uml::Region>::iterator end = getRegion()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22034			
		}
		case uml::umlPackage::STATE_ATTRIBUTE_STATEINVARIANT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getStateInvariant();
				return eAny(returnValue); //22032
			}
		case uml::umlPackage::STATE_ATTRIBUTE_SUBMACHINE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getSubmachine();
				return eAny(returnValue); //22033
			}
	}
	Any result;
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = RedefinableElementImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = VertexImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool StateImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STATE_ATTRIBUTE_CONNECTION:
			return getConnection() != nullptr; //22021
		case uml::umlPackage::STATE_ATTRIBUTE_CONNECTIONPOINT:
			return getConnectionPoint() != nullptr; //22022
		case uml::umlPackage::STATE_ATTRIBUTE_DEFERRABLETRIGGER:
			return getDeferrableTrigger() != nullptr; //22023
		case uml::umlPackage::STATE_ATTRIBUTE_DOACTIVITY:
			return getDoActivity() != nullptr; //22024
		case uml::umlPackage::STATE_ATTRIBUTE_ENTRY:
			return getEntry() != nullptr; //22025
		case uml::umlPackage::STATE_ATTRIBUTE_EXIT:
			return getExit() != nullptr; //22026
		case uml::umlPackage::STATE_ATTRIBUTE_ISCOMPOSITE:
			return getIsComposite() != false; //22027
		case uml::umlPackage::STATE_ATTRIBUTE_ISORTHOGONAL:
			return getIsOrthogonal() != false; //22028
		case uml::umlPackage::STATE_ATTRIBUTE_ISSIMPLE:
			return getIsSimple() != true; //22029
		case uml::umlPackage::STATE_ATTRIBUTE_ISSUBMACHINESTATE:
			return getIsSubmachineState() != false; //22030
		case uml::umlPackage::STATE_ATTRIBUTE_REDEFINEDSTATE:
			return getRedefinedState() != nullptr; //22031
		case uml::umlPackage::STATE_ATTRIBUTE_REGION:
			return getRegion() != nullptr; //22034
		case uml::umlPackage::STATE_ATTRIBUTE_STATEINVARIANT:
			return getStateInvariant() != nullptr; //22032
		case uml::umlPackage::STATE_ATTRIBUTE_SUBMACHINE:
			return getSubmachine() != nullptr; //22033
	}
	bool result = false;
	result = NamespaceImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = VertexImpl::internalEIsSet(featureID);
	return result;
}
bool StateImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STATE_ATTRIBUTE_CONNECTION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ConnectionPointReference>> connectionList(new Bag<uml::ConnectionPointReference>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				connectionList->add(std::dynamic_pointer_cast<uml::ConnectionPointReference>(*iter));
				iter++;
			}
			
			Bag<uml::ConnectionPointReference>::iterator iterConnection = getConnection()->begin();
			Bag<uml::ConnectionPointReference>::iterator endConnection = getConnection()->end();
			while (iterConnection != endConnection)
			{
				if (connectionList->find(*iterConnection) == -1)
				{
					getConnection()->erase(*iterConnection);
				}
				iterConnection++;
			}
 
			iterConnection = connectionList->begin();
			endConnection = connectionList->end();
			while (iterConnection != endConnection)
			{
				if (getConnection()->find(*iterConnection) == -1)
				{
					getConnection()->add(*iterConnection);
				}
				iterConnection++;			
			}
			return true;
		}
		case uml::umlPackage::STATE_ATTRIBUTE_CONNECTIONPOINT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Pseudostate>> connectionPointList(new Bag<uml::Pseudostate>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				connectionPointList->add(std::dynamic_pointer_cast<uml::Pseudostate>(*iter));
				iter++;
			}
			
			Bag<uml::Pseudostate>::iterator iterConnectionPoint = getConnectionPoint()->begin();
			Bag<uml::Pseudostate>::iterator endConnectionPoint = getConnectionPoint()->end();
			while (iterConnectionPoint != endConnectionPoint)
			{
				if (connectionPointList->find(*iterConnectionPoint) == -1)
				{
					getConnectionPoint()->erase(*iterConnectionPoint);
				}
				iterConnectionPoint++;
			}
 
			iterConnectionPoint = connectionPointList->begin();
			endConnectionPoint = connectionPointList->end();
			while (iterConnectionPoint != endConnectionPoint)
			{
				if (getConnectionPoint()->find(*iterConnectionPoint) == -1)
				{
					getConnectionPoint()->add(*iterConnectionPoint);
				}
				iterConnectionPoint++;			
			}
			return true;
		}
		case uml::umlPackage::STATE_ATTRIBUTE_DEFERRABLETRIGGER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Trigger>> deferrableTriggerList(new Bag<uml::Trigger>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				deferrableTriggerList->add(std::dynamic_pointer_cast<uml::Trigger>(*iter));
				iter++;
			}
			
			Bag<uml::Trigger>::iterator iterDeferrableTrigger = getDeferrableTrigger()->begin();
			Bag<uml::Trigger>::iterator endDeferrableTrigger = getDeferrableTrigger()->end();
			while (iterDeferrableTrigger != endDeferrableTrigger)
			{
				if (deferrableTriggerList->find(*iterDeferrableTrigger) == -1)
				{
					getDeferrableTrigger()->erase(*iterDeferrableTrigger);
				}
				iterDeferrableTrigger++;
			}
 
			iterDeferrableTrigger = deferrableTriggerList->begin();
			endDeferrableTrigger = deferrableTriggerList->end();
			while (iterDeferrableTrigger != endDeferrableTrigger)
			{
				if (getDeferrableTrigger()->find(*iterDeferrableTrigger) == -1)
				{
					getDeferrableTrigger()->add(*iterDeferrableTrigger);
				}
				iterDeferrableTrigger++;			
			}
			return true;
		}
		case uml::umlPackage::STATE_ATTRIBUTE_DOACTIVITY:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _doActivity = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setDoActivity(_doActivity); //22024
			return true;
		}
		case uml::umlPackage::STATE_ATTRIBUTE_ENTRY:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _entry = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setEntry(_entry); //22025
			return true;
		}
		case uml::umlPackage::STATE_ATTRIBUTE_EXIT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _exit = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setExit(_exit); //22026
			return true;
		}
		case uml::umlPackage::STATE_ATTRIBUTE_REDEFINEDSTATE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::State> _redefinedState = std::dynamic_pointer_cast<uml::State>(_temp);
			setRedefinedState(_redefinedState); //22031
			return true;
		}
		case uml::umlPackage::STATE_ATTRIBUTE_REGION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Region>> regionList(new Bag<uml::Region>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				regionList->add(std::dynamic_pointer_cast<uml::Region>(*iter));
				iter++;
			}
			
			Bag<uml::Region>::iterator iterRegion = getRegion()->begin();
			Bag<uml::Region>::iterator endRegion = getRegion()->end();
			while (iterRegion != endRegion)
			{
				if (regionList->find(*iterRegion) == -1)
				{
					getRegion()->erase(*iterRegion);
				}
				iterRegion++;
			}
 
			iterRegion = regionList->begin();
			endRegion = regionList->end();
			while (iterRegion != endRegion)
			{
				if (getRegion()->find(*iterRegion) == -1)
				{
					getRegion()->add(*iterRegion);
				}
				iterRegion++;			
			}
			return true;
		}
		case uml::umlPackage::STATE_ATTRIBUTE_STATEINVARIANT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Constraint> _stateInvariant = std::dynamic_pointer_cast<uml::Constraint>(_temp);
			setStateInvariant(_stateInvariant); //22032
			return true;
		}
		case uml::umlPackage::STATE_ATTRIBUTE_SUBMACHINE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StateMachine> _submachine = std::dynamic_pointer_cast<uml::StateMachine>(_temp);
			setSubmachine(_submachine); //22033
			return true;
		}
	}

	bool result = false;
	result = NamespaceImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = VertexImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any StateImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 22116
		case umlPackage::STATE_OPERATION_COMPOSITE_STATES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->composite_states(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 22117
		case umlPackage::STATE_OPERATION_DESTINATIONS_OR_SOURCES_OF_TRANSITIONS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->destinations_or_sources_of_transitions(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 22114
		case umlPackage::STATE_OPERATION_ENTRY_OR_EXIT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->entry_or_exit(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 22119
		case umlPackage::STATE_OPERATION_ISCOMPOSITE:
		{
			result = eAny(this->isComposite());
			break;
		}
		
		// 22120
		case umlPackage::STATE_OPERATION_ISORTHOGONAL:
		{
			result = eAny(this->isOrthogonal());
			break;
		}
		
		// 22121
		case umlPackage::STATE_OPERATION_ISSIMPLE:
		{
			result = eAny(this->isSimple());
			break;
		}
		
		// 22122
		case umlPackage::STATE_OPERATION_ISSUBMACHINESTATE:
		{
			result = eAny(this->isSubmachineState());
			break;
		}
		
		// 22123
		case umlPackage::STATE_OPERATION_REDEFINITIONCONTEXT:
		{
			result = eAny(this->redefinitionContext());
			break;
		}
		
		// 22118
		case umlPackage::STATE_OPERATION_SUBMACHINE_OR_REGIONS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->submachine_or_regions(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 22115
		case umlPackage::STATE_OPERATION_SUBMACHINE_STATES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->submachine_states(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = VertexImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = RedefinableElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = NamespaceImpl::eInvoke(operationID, arguments);
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
void StateImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StateImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("redefinedState");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedState")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("stateInvariant");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("stateInvariant")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("submachine");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("submachine")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamespaceImpl::loadAttributes(loadHandler, attr_list);
	RedefinableElementImpl::loadAttributes(loadHandler, attr_list);
	VertexImpl::loadAttributes(loadHandler, attr_list);
}

void StateImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("connection") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ConnectionPointReference";
			}
			loadHandler->handleChildContainer<uml::ConnectionPointReference>(this->getConnection());  

			return; 
		}

		if ( nodeName.compare("connectionPoint") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Pseudostate";
			}
			loadHandler->handleChildContainer<uml::Pseudostate>(this->getConnectionPoint());  

			return; 
		}

		if ( nodeName.compare("deferrableTrigger") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Trigger";
			}
			loadHandler->handleChildContainer<uml::Trigger>(this->getDeferrableTrigger());  

			return; 
		}

		if ( nodeName.compare("doActivity") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getDoActivity()); 

			return; 
		}

		if ( nodeName.compare("entry") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getEntry()); 

			return; 
		}

		if ( nodeName.compare("exit") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getExit()); 

			return; 
		}

		if ( nodeName.compare("region") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Region";
			}
			loadHandler->handleChildContainer<uml::Region>(this->getRegion());  

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
	NamespaceImpl::loadNode(nodeName, loadHandler);
	RedefinableElementImpl::loadNode(nodeName, loadHandler);
	VertexImpl::loadNode(nodeName, loadHandler);
}

void StateImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::STATE_ATTRIBUTE_REDEFINEDSTATE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::State> _redefinedState = std::dynamic_pointer_cast<uml::State>( references.front() );
				setRedefinedState(_redefinedState);
			}
			
			return;
		}

		case uml::umlPackage::STATE_ATTRIBUTE_STATEINVARIANT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Constraint> _stateInvariant = std::dynamic_pointer_cast<uml::Constraint>( references.front() );
				setStateInvariant(_stateInvariant);
			}
			
			return;
		}

		case uml::umlPackage::STATE_ATTRIBUTE_SUBMACHINE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StateMachine> _submachine = std::dynamic_pointer_cast<uml::StateMachine>( references.front() );
				setSubmachine(_submachine);
			}
			
			return;
		}
	}
	NamespaceImpl::resolveReferences(featureID, references);
	RedefinableElementImpl::resolveReferences(featureID, references);
	VertexImpl::resolveReferences(featureID, references);
}

void StateImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	VertexImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void StateImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'connection'
		for (std::shared_ptr<uml::ConnectionPointReference> connection : *this->getConnection()) 
		{
			saveHandler->addReference(connection, "connection", connection->eClass() != package->getConnectionPointReference_Class());
		}

		// Save 'connectionPoint'
		for (std::shared_ptr<uml::Pseudostate> connectionPoint : *this->getConnectionPoint()) 
		{
			saveHandler->addReference(connectionPoint, "connectionPoint", connectionPoint->eClass() != package->getPseudostate_Class());
		}

		// Save 'deferrableTrigger'
		for (std::shared_ptr<uml::Trigger> deferrableTrigger : *this->getDeferrableTrigger()) 
		{
			saveHandler->addReference(deferrableTrigger, "deferrableTrigger", deferrableTrigger->eClass() != package->getTrigger_Class());
		}

		// Save 'doActivity'
		std::shared_ptr<uml::Behavior> doActivity = this->getDoActivity();
		if (doActivity != nullptr)
		{
			saveHandler->addReference(doActivity, "doActivity", doActivity->eClass() != package->getBehavior_Class());
		}

		// Save 'entry'
		std::shared_ptr<uml::Behavior> entry = this->getEntry();
		if (entry != nullptr)
		{
			saveHandler->addReference(entry, "entry", entry->eClass() != package->getBehavior_Class());
		}

		// Save 'exit'
		std::shared_ptr<uml::Behavior> exit = this->getExit();
		if (exit != nullptr)
		{
			saveHandler->addReference(exit, "exit", exit->eClass() != package->getBehavior_Class());
		}

		// Save 'region'
		for (std::shared_ptr<uml::Region> region : *this->getRegion()) 
		{
			saveHandler->addReference(region, "region", region->eClass() != package->getRegion_Class());
		}
	// Add references
		saveHandler->addReference(this->getRedefinedState(), "redefinedState", getRedefinedState()->eClass() != uml::umlPackage::eInstance()->getState_Class()); 
		saveHandler->addReference(this->getStateInvariant(), "stateInvariant", getStateInvariant()->eClass() != uml::umlPackage::eInstance()->getConstraint_Class()); 
		saveHandler->addReference(this->getSubmachine(), "submachine", getSubmachine()->eClass() != uml::umlPackage::eInstance()->getStateMachine_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

