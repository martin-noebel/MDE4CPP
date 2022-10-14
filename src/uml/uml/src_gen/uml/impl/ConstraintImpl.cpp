
#include "uml/impl/ConstraintImpl.hpp"
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
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConstraintImpl::ConstraintImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ConstraintImpl::~ConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Constraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::Namespace> par_Namespace, const int reference_id)
:ConstraintImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
		m_context = par_Namespace;
		m_namespace = par_Namespace;
		 return;
	case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
		m_namespace = par_Namespace;
		m_owner = par_Namespace;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::Element> par_owner)
:ConstraintImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::Package> par_owningPackage)
:ConstraintImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
ConstraintImpl::ConstraintImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ConstraintImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

ConstraintImpl::ConstraintImpl(const ConstraintImpl & obj): ConstraintImpl()
{
	*this = obj;
}

ConstraintImpl& ConstraintImpl::operator=(const ConstraintImpl & obj)
{
	//call overloaded =Operator for each base class
	PackageableElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Constraint 
	 * which is generated by the compiler (as Constraint is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Constraint::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Constraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_constrainedElement  = obj.getConstrainedElement();
	m_context  = obj.getContext();
	//Clone references with containment (deep copy)
	//clone reference 'specification'
	if(obj.getSpecification()!=nullptr)
	{
		m_specification = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getSpecification()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ConstraintImpl::copy() const
{
	std::shared_ptr<ConstraintImpl> element(new ConstraintImpl());
	*element =(*this);
	element->setThisConstraintPtr(element);
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
/* Getter & Setter for reference constrainedElement */
std::shared_ptr<Bag<uml::Element>> ConstraintImpl::getConstrainedElement() const
{
	if(m_constrainedElement == nullptr)
	{
		m_constrainedElement.reset(new Bag<uml::Element>());
		
		
	}
    return m_constrainedElement;
}

/* Getter & Setter for reference context */
std::weak_ptr<uml::Namespace> ConstraintImpl::getContext() const
{
    return m_context;
}
void ConstraintImpl::setContext(std::weak_ptr<uml::Namespace> _context)
{
    m_context = _context;
	
}

/* Getter & Setter for reference specification */
std::shared_ptr<uml::ValueSpecification> ConstraintImpl::getSpecification() const
{
    return m_specification;
}
void ConstraintImpl::setSpecification(std::shared_ptr<uml::ValueSpecification> _specification)
{
    m_specification = _specification;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ConstraintImpl::eContainer() const
{
	if(auto wp = m_context.lock())
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

std::shared_ptr<ecore::EClass> ConstraintImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getConstraint_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ConstraintImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONSTRAINEDELEMENT:
			return eEcoreContainerAny(getConstrainedElement(),uml::umlPackage::ELEMENT_CLASS); //5712
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
		{
			std::shared_ptr<ecore::EObject> returnValue=getContext().lock();
			return eEcoreAny(returnValue,uml::umlPackage::NAMESPACE_CLASS); //5713
		}
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_SPECIFICATION:
			return eAny(getSpecification(),uml::umlPackage::VALUESPECIFICATION_CLASS,false); //5714
	}
	return PackageableElementImpl::eGet(featureID, resolve, coreType);
}

bool ConstraintImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONSTRAINEDELEMENT:
			return getConstrainedElement() != nullptr; //5712
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
			return getContext().lock() != nullptr; //5713
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_SPECIFICATION:
			return getSpecification() != nullptr; //5714
	}
	return PackageableElementImpl::internalEIsSet(featureID);
}

bool ConstraintImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONSTRAINEDELEMENT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Element>> _constrainedElement = getConstrainedElement();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Element> valueToAdd = std::dynamic_pointer_cast<uml::Element>(anEObject);
	
							if (valueToAdd)
							{
								if(_constrainedElement->find(valueToAdd) == -1)
								{
									_constrainedElement->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'constrainedElement'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'constrainedElement'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Namespace> _context = std::dynamic_pointer_cast<uml::Namespace>(eObject);
					if(_context)
					{
						setContext(_context); //5713
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'context'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'context'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CONSTRAINT_ATTRIBUTE_SPECIFICATION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::ValueSpecification> _specification = std::dynamic_pointer_cast<uml::ValueSpecification>(eObject);
					if(_specification)
					{
						setSpecification(_specification); //5714
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'specification'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'specification'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return PackageableElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ConstraintImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = PackageableElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Constraint> ConstraintImpl::getThisConstraintPtr() const
{
	return m_thisConstraintPtr.lock();
}
void ConstraintImpl::setThisConstraintPtr(std::weak_ptr<uml::Constraint> thisConstraintPtr)
{
	m_thisConstraintPtr = thisConstraintPtr;
	setThisPackageableElementPtr(thisConstraintPtr);
}


