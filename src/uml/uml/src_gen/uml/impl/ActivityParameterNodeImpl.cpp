
#include "uml/impl/ActivityParameterNodeImpl.hpp"
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
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/ObjectNode.hpp"
#include "uml/Parameter.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/State.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ActivityParameterNodeImpl::ActivityParameterNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ActivityParameterNodeImpl::~ActivityParameterNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ActivityParameterNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ActivityParameterNodeImpl::ActivityParameterNodeImpl(std::weak_ptr<uml::Activity> par_activity)
:ActivityParameterNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ActivityParameterNodeImpl::ActivityParameterNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ActivityParameterNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ActivityParameterNodeImpl::ActivityParameterNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ActivityParameterNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ActivityParameterNodeImpl::ActivityParameterNodeImpl(std::weak_ptr<uml::Element> par_owner)
:ActivityParameterNodeImpl()
{
	m_owner = par_owner;
}

ActivityParameterNodeImpl::ActivityParameterNodeImpl(const ActivityParameterNodeImpl & obj): ActivityParameterNodeImpl()
{
	*this = obj;
}

ActivityParameterNodeImpl& ActivityParameterNodeImpl::operator=(const ActivityParameterNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	ObjectNodeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ActivityParameterNode 
	 * which is generated by the compiler (as ActivityParameterNode is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ActivityParameterNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ActivityParameterNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_parameter  = obj.getParameter();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ActivityParameterNodeImpl::copy() const
{
	std::shared_ptr<ActivityParameterNodeImpl> element(new ActivityParameterNodeImpl());
	*element =(*this);
	element->setThisActivityParameterNodePtr(element);
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
/* Getter & Setter for reference parameter */
std::shared_ptr<uml::Parameter> ActivityParameterNodeImpl::getParameter() const
{
    return m_parameter;
}
void ActivityParameterNodeImpl::setParameter(std::shared_ptr<uml::Parameter> _parameter)
{
    m_parameter = _parameter;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ActivityParameterNodeImpl::eContainer() const
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

std::shared_ptr<ecore::EClass> ActivityParameterNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getActivityParameterNode_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ActivityParameterNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYPARAMETERNODE_ATTRIBUTE_PARAMETER:
			return eAny(getParameter(),uml::umlPackage::PARAMETER_CLASS,false); //1226
	}
	return ObjectNodeImpl::eGet(featureID, resolve, coreType);
}

bool ActivityParameterNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYPARAMETERNODE_ATTRIBUTE_PARAMETER:
			return getParameter() != nullptr; //1226
	}
	return ObjectNodeImpl::internalEIsSet(featureID);
}

bool ActivityParameterNodeImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ACTIVITYPARAMETERNODE_ATTRIBUTE_PARAMETER:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Parameter> _parameter = std::dynamic_pointer_cast<uml::Parameter>(eObject);
					if(_parameter)
					{
						setParameter(_parameter); //1226
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'parameter'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'parameter'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ObjectNodeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ActivityParameterNodeImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ObjectNodeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ActivityParameterNode> ActivityParameterNodeImpl::getThisActivityParameterNodePtr() const
{
	return m_thisActivityParameterNodePtr.lock();
}
void ActivityParameterNodeImpl::setThisActivityParameterNodePtr(std::weak_ptr<uml::ActivityParameterNode> thisActivityParameterNodePtr)
{
	m_thisActivityParameterNodePtr = thisActivityParameterNodePtr;
	setThisObjectNodePtr(thisActivityParameterNodePtr);
}


