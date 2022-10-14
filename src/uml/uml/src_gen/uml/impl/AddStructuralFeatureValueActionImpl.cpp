
#include "uml/impl/AddStructuralFeatureValueActionImpl.hpp"
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
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuralFeature.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/WriteStructuralFeatureAction.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AddStructuralFeatureValueActionImpl::~AddStructuralFeatureValueActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AddStructuralFeatureValueAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::Activity> par_activity)
:AddStructuralFeatureValueActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:AddStructuralFeatureValueActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:AddStructuralFeatureValueActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::Element> par_owner)
:AddStructuralFeatureValueActionImpl()
{
	m_owner = par_owner;
}

AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl(const AddStructuralFeatureValueActionImpl & obj): AddStructuralFeatureValueActionImpl()
{
	*this = obj;
}

AddStructuralFeatureValueActionImpl& AddStructuralFeatureValueActionImpl::operator=(const AddStructuralFeatureValueActionImpl & obj)
{
	//call overloaded =Operator for each base class
	WriteStructuralFeatureActionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of AddStructuralFeatureValueAction 
	 * which is generated by the compiler (as AddStructuralFeatureValueAction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//AddStructuralFeatureValueAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AddStructuralFeatureValueAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isReplaceAll = obj.getIsReplaceAll();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'insertAt'
	if(obj.getInsertAt()!=nullptr)
	{
		m_insertAt = std::dynamic_pointer_cast<uml::InputPin>(obj.getInsertAt()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> AddStructuralFeatureValueActionImpl::copy() const
{
	std::shared_ptr<AddStructuralFeatureValueActionImpl> element(new AddStructuralFeatureValueActionImpl());
	*element =(*this);
	element->setThisAddStructuralFeatureValueActionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isReplaceAll */
bool AddStructuralFeatureValueActionImpl::getIsReplaceAll() const 
{
	return m_isReplaceAll;
}
void AddStructuralFeatureValueActionImpl::setIsReplaceAll(bool _isReplaceAll)
{
	m_isReplaceAll = _isReplaceAll;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference insertAt */
std::shared_ptr<uml::InputPin> AddStructuralFeatureValueActionImpl::getInsertAt() const
{
    return m_insertAt;
}
void AddStructuralFeatureValueActionImpl::setInsertAt(std::shared_ptr<uml::InputPin> _insertAt)
{
    m_insertAt = _insertAt;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> AddStructuralFeatureValueActionImpl::eContainer() const
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

std::shared_ptr<ecore::EClass> AddStructuralFeatureValueActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getAddStructuralFeatureValueAction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> AddStructuralFeatureValueActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_INSERTAT:
			return eAny(getInsertAt(),uml::umlPackage::INPUTPIN_CLASS,false); //1531
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREPLACEALL:
			return eAny(getIsReplaceAll(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //1532
	}
	return WriteStructuralFeatureActionImpl::eGet(featureID, resolve, coreType);
}

bool AddStructuralFeatureValueActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_INSERTAT:
			return getInsertAt() != nullptr; //1531
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREPLACEALL:
			return getIsReplaceAll() != false; //1532
	}
	return WriteStructuralFeatureActionImpl::internalEIsSet(featureID);
}

bool AddStructuralFeatureValueActionImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_INSERTAT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::InputPin> _insertAt = std::dynamic_pointer_cast<uml::InputPin>(eObject);
					if(_insertAt)
					{
						setInsertAt(_insertAt); //1531
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'insertAt'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'insertAt'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREPLACEALL:
		{
			try
			{
				bool _isReplaceAll = newValue->get<bool>();
				setIsReplaceAll(_isReplaceAll); //1532
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isReplaceAll'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return WriteStructuralFeatureActionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> AddStructuralFeatureValueActionImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = WriteStructuralFeatureActionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::AddStructuralFeatureValueAction> AddStructuralFeatureValueActionImpl::getThisAddStructuralFeatureValueActionPtr() const
{
	return m_thisAddStructuralFeatureValueActionPtr.lock();
}
void AddStructuralFeatureValueActionImpl::setThisAddStructuralFeatureValueActionPtr(std::weak_ptr<uml::AddStructuralFeatureValueAction> thisAddStructuralFeatureValueActionPtr)
{
	m_thisAddStructuralFeatureValueActionPtr = thisAddStructuralFeatureValueActionPtr;
	setThisWriteStructuralFeatureActionPtr(thisAddStructuralFeatureValueActionPtr);
}


