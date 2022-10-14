
#include "uml/impl/BroadcastSignalActionImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/InvocationAction.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/Port.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/Signal.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
BroadcastSignalActionImpl::BroadcastSignalActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

BroadcastSignalActionImpl::~BroadcastSignalActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete BroadcastSignalAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
BroadcastSignalActionImpl::BroadcastSignalActionImpl(std::weak_ptr<uml::Activity> par_activity)
:BroadcastSignalActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
BroadcastSignalActionImpl::BroadcastSignalActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:BroadcastSignalActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
BroadcastSignalActionImpl::BroadcastSignalActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:BroadcastSignalActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
BroadcastSignalActionImpl::BroadcastSignalActionImpl(std::weak_ptr<uml::Element> par_owner)
:BroadcastSignalActionImpl()
{
	m_owner = par_owner;
}

BroadcastSignalActionImpl::BroadcastSignalActionImpl(const BroadcastSignalActionImpl & obj): BroadcastSignalActionImpl()
{
	*this = obj;
}

BroadcastSignalActionImpl& BroadcastSignalActionImpl::operator=(const BroadcastSignalActionImpl & obj)
{
	//call overloaded =Operator for each base class
	InvocationActionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of BroadcastSignalAction 
	 * which is generated by the compiler (as BroadcastSignalAction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//BroadcastSignalAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy BroadcastSignalAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_signal  = obj.getSignal();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> BroadcastSignalActionImpl::copy() const
{
	std::shared_ptr<BroadcastSignalActionImpl> element(new BroadcastSignalActionImpl());
	*element =(*this);
	element->setThisBroadcastSignalActionPtr(element);
	return element;
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
/* Getter & Setter for reference signal */
std::shared_ptr<uml::Signal> BroadcastSignalActionImpl::getSignal() const
{
    return m_signal;
}
void BroadcastSignalActionImpl::setSignal(std::shared_ptr<uml::Signal> _signal)
{
    m_signal = _signal;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> BroadcastSignalActionImpl::eContainer() const
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

std::shared_ptr<ecore::EClass> BroadcastSignalActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getBroadcastSignalAction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> BroadcastSignalActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::BROADCASTSIGNALACTION_ATTRIBUTE_SIGNAL:
			return eAny(getSignal(),uml::umlPackage::SIGNAL_CLASS,false); //2729
	}
	return InvocationActionImpl::eGet(featureID, resolve, coreType);
}

bool BroadcastSignalActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::BROADCASTSIGNALACTION_ATTRIBUTE_SIGNAL:
			return getSignal() != nullptr; //2729
	}
	return InvocationActionImpl::internalEIsSet(featureID);
}

bool BroadcastSignalActionImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::BROADCASTSIGNALACTION_ATTRIBUTE_SIGNAL:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Signal> _signal = std::dynamic_pointer_cast<uml::Signal>(eObject);
					if(_signal)
					{
						setSignal(_signal); //2729
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'signal'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'signal'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return InvocationActionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> BroadcastSignalActionImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = InvocationActionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::BroadcastSignalAction> BroadcastSignalActionImpl::getThisBroadcastSignalActionPtr() const
{
	return m_thisBroadcastSignalActionPtr.lock();
}
void BroadcastSignalActionImpl::setThisBroadcastSignalActionPtr(std::weak_ptr<uml::BroadcastSignalAction> thisBroadcastSignalActionPtr)
{
	m_thisBroadcastSignalActionPtr = thisBroadcastSignalActionPtr;
	setThisInvocationActionPtr(thisBroadcastSignalActionPtr);
}


