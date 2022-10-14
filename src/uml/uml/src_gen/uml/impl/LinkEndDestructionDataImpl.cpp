
#include "uml/impl/LinkEndDestructionDataImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/InputPin.hpp"
#include "uml/LinkEndData.hpp"
#include "uml/Property.hpp"
#include "uml/QualifierValue.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LinkEndDestructionDataImpl::LinkEndDestructionDataImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LinkEndDestructionDataImpl::~LinkEndDestructionDataImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkEndDestructionData "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LinkEndDestructionDataImpl::LinkEndDestructionDataImpl(std::weak_ptr<uml::Element> par_owner)
:LinkEndDestructionDataImpl()
{
	m_owner = par_owner;
}

LinkEndDestructionDataImpl::LinkEndDestructionDataImpl(const LinkEndDestructionDataImpl & obj): LinkEndDestructionDataImpl()
{
	*this = obj;
}

LinkEndDestructionDataImpl& LinkEndDestructionDataImpl::operator=(const LinkEndDestructionDataImpl & obj)
{
	//call overloaded =Operator for each base class
	LinkEndDataImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LinkEndDestructionData 
	 * which is generated by the compiler (as LinkEndDestructionData is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LinkEndDestructionData::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkEndDestructionData "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isDestroyDuplicates = obj.getIsDestroyDuplicates();

	//copy references with no containment (soft copy)
	m_destroyAt  = obj.getDestroyAt();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> LinkEndDestructionDataImpl::copy() const
{
	std::shared_ptr<LinkEndDestructionDataImpl> element(new LinkEndDestructionDataImpl());
	*element =(*this);
	element->setThisLinkEndDestructionDataPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isDestroyDuplicates */
bool LinkEndDestructionDataImpl::getIsDestroyDuplicates() const 
{
	return m_isDestroyDuplicates;
}
void LinkEndDestructionDataImpl::setIsDestroyDuplicates(bool _isDestroyDuplicates)
{
	m_isDestroyDuplicates = _isDestroyDuplicates;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference destroyAt */
std::shared_ptr<uml::InputPin> LinkEndDestructionDataImpl::getDestroyAt() const
{
    return m_destroyAt;
}
void LinkEndDestructionDataImpl::setDestroyAt(std::shared_ptr<uml::InputPin> _destroyAt)
{
    m_destroyAt = _destroyAt;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LinkEndDestructionDataImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

std::shared_ptr<ecore::EClass> LinkEndDestructionDataImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLinkEndDestructionData_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> LinkEndDestructionDataImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_DESTROYAT:
			return eAny(getDestroyAt(),uml::umlPackage::INPUTPIN_CLASS,false); //1366
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_ISDESTROYDUPLICATES:
			return eAny(getIsDestroyDuplicates(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //1367
	}
	return LinkEndDataImpl::eGet(featureID, resolve, coreType);
}

bool LinkEndDestructionDataImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_DESTROYAT:
			return getDestroyAt() != nullptr; //1366
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_ISDESTROYDUPLICATES:
			return getIsDestroyDuplicates() != false; //1367
	}
	return LinkEndDataImpl::internalEIsSet(featureID);
}

bool LinkEndDestructionDataImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_DESTROYAT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::InputPin> _destroyAt = std::dynamic_pointer_cast<uml::InputPin>(eObject);
					if(_destroyAt)
					{
						setDestroyAt(_destroyAt); //1366
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'destroyAt'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'destroyAt'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LINKENDDESTRUCTIONDATA_ATTRIBUTE_ISDESTROYDUPLICATES:
		{
			try
			{
				bool _isDestroyDuplicates = newValue->get<bool>();
				setIsDestroyDuplicates(_isDestroyDuplicates); //1367
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isDestroyDuplicates'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return LinkEndDataImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> LinkEndDestructionDataImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = LinkEndDataImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::LinkEndDestructionData> LinkEndDestructionDataImpl::getThisLinkEndDestructionDataPtr() const
{
	return m_thisLinkEndDestructionDataPtr.lock();
}
void LinkEndDestructionDataImpl::setThisLinkEndDestructionDataPtr(std::weak_ptr<uml::LinkEndDestructionData> thisLinkEndDestructionDataPtr)
{
	m_thisLinkEndDestructionDataPtr = thisLinkEndDestructionDataPtr;
	setThisLinkEndDataPtr(thisLinkEndDestructionDataPtr);
}


