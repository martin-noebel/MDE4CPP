
#include "uml/impl/NamespaceImpl.hpp"
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
#include <stdexcept>
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
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
NamespaceImpl::NamespaceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

NamespaceImpl::~NamespaceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Namespace "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
NamespaceImpl::NamespaceImpl(std::weak_ptr<uml::Namespace> par_namespace)
:NamespaceImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
NamespaceImpl::NamespaceImpl(std::weak_ptr<uml::Element> par_owner)
:NamespaceImpl()
{
	m_owner = par_owner;
}

NamespaceImpl::NamespaceImpl(const NamespaceImpl & obj): NamespaceImpl()
{
	*this = obj;
}

NamespaceImpl& NamespaceImpl::operator=(const NamespaceImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Namespace 
	 * which is generated by the compiler (as Namespace is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Namespace::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Namespace "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_member  = obj.getMember();
	//Clone references with containment (deep copy)
	//clone reference 'elementImport'
	std::shared_ptr<SubsetUnion<uml::ElementImport, uml::Element>> elementImportList = obj.getElementImport();
	if(elementImportList)
	{
		/*SubsetUnion*/
		m_elementImport.reset(new SubsetUnion<uml::ElementImport, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getElementImport()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ElementImport> elementImportindexElem: *elementImportList) 
		{
			std::shared_ptr<uml::ElementImport> temp = std::dynamic_pointer_cast<uml::ElementImport>((elementImportindexElem)->copy());
			m_elementImport->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for elementImport.")
	}

	//clone reference 'importedMember'
	std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>> importedMemberList = obj.getImportedMember();
	if(importedMemberList)
	{
		/*Subset*/
		m_importedMember.reset(new Subset<uml::PackageableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_importedMember - Subset<uml::PackageableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getImportedMember()->initSubset(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_importedMember - Subset<uml::PackageableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::PackageableElement> importedMemberindexElem: *importedMemberList) 
		{
			std::shared_ptr<uml::PackageableElement> temp = std::dynamic_pointer_cast<uml::PackageableElement>((importedMemberindexElem)->copy());
			m_importedMember->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for importedMember.")
	}

	//clone reference 'ownedRule'
	std::shared_ptr<SubsetUnion<uml::Constraint, uml::NamedElement>> ownedRuleList = obj.getOwnedRule();
	if(ownedRuleList)
	{
		/*SubsetUnion*/
		m_ownedRule.reset(new SubsetUnion<uml::Constraint, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedRule()->initSubsetUnion(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Constraint> ownedRuleindexElem: *ownedRuleList) 
		{
			std::shared_ptr<uml::Constraint> temp = std::dynamic_pointer_cast<uml::Constraint>((ownedRuleindexElem)->copy());
			m_ownedRule->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for ownedRule.")
	}

	//clone reference 'packageImport'
	std::shared_ptr<SubsetUnion<uml::PackageImport, uml::Element>> packageImportList = obj.getPackageImport();
	if(packageImportList)
	{
		/*SubsetUnion*/
		m_packageImport.reset(new SubsetUnion<uml::PackageImport, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getPackageImport()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::PackageImport> packageImportindexElem: *packageImportList) 
		{
			std::shared_ptr<uml::PackageImport> temp = std::dynamic_pointer_cast<uml::PackageImport>((packageImportindexElem)->copy());
			m_packageImport->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for packageImport.")
	}
	/*SubsetUnion*/
	getElementImport()->initSubsetUnion(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*SubsetUnion*/
	getOwnedRule()->initSubsetUnion(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*SubsetUnion*/
	getPackageImport()->initSubsetUnion(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::ElementImport> NamespaceImpl::createElementImport(std::shared_ptr<uml::PackageableElement> element, uml::VisibilityKind visibility)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::PackageImport> NamespaceImpl::createPackageImport(std::shared_ptr<uml::Package> package_, uml::VisibilityKind visibility)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::PackageableElement>> NamespaceImpl::excludeCollisions(std::shared_ptr<Bag<uml::PackageableElement>> imps)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::PackageableElement>> NamespaceImpl::getImportedElements()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::PackageableElement>> NamespaceImpl::getImportedMembers()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Package>> NamespaceImpl::getImportedPackages()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<std::string>> NamespaceImpl::getNamesOfMember(std::shared_ptr<uml::NamedElement> element)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::NamedElement>> NamespaceImpl::getOwnedMembers()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::PackageableElement>> NamespaceImpl::importMembers(std::shared_ptr<Bag<uml::PackageableElement>> imps)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool NamespaceImpl::membersAreDistinguishable()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference elementImport */
std::shared_ptr<SubsetUnion<uml::ElementImport, uml::Element>> NamespaceImpl::getElementImport() const
{
	if(m_elementImport == nullptr)
	{
		/*SubsetUnion*/
		m_elementImport.reset(new SubsetUnion<uml::ElementImport, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getElementImport()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_elementImport;
}

/* Getter & Setter for reference importedMember */
std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>> NamespaceImpl::getImportedMember() const
{
	if(m_importedMember == nullptr)
	{
		/*Subset*/
		m_importedMember.reset(new Subset<uml::PackageableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_importedMember - Subset<uml::PackageableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getImportedMember()->initSubset(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_importedMember - Subset<uml::PackageableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
    return m_importedMember;
}

/* Getter & Setter for reference member */

/* Getter & Setter for reference ownedMember */

/* Getter & Setter for reference ownedRule */
std::shared_ptr<SubsetUnion<uml::Constraint, uml::NamedElement>> NamespaceImpl::getOwnedRule() const
{
	if(m_ownedRule == nullptr)
	{
		/*SubsetUnion*/
		m_ownedRule.reset(new SubsetUnion<uml::Constraint, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedRule()->initSubsetUnion(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_ownedRule;
}

/* Getter & Setter for reference packageImport */
std::shared_ptr<SubsetUnion<uml::PackageImport, uml::Element>> NamespaceImpl::getPackageImport() const
{
	if(m_packageImport == nullptr)
	{
		/*SubsetUnion*/
		m_packageImport.reset(new SubsetUnion<uml::PackageImport, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getPackageImport()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_packageImport;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> NamespaceImpl::getMember() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> NamespaceImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedMember()->initSubsetUnion(getOwnedElement(), getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >(getOwnedElement(), getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> NamespaceImpl::eContainer() const
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

std::shared_ptr<ecore::EClass> NamespaceImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getNamespace_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> NamespaceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_ELEMENTIMPORT:
			return eEcoreContainerAny(getElementImport(),uml::umlPackage::ELEMENTIMPORT_CLASS); //15610
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_IMPORTEDMEMBER:
			return eEcoreContainerAny(getImportedMember(),uml::umlPackage::PACKAGEABLEELEMENT_CLASS); //15613
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_MEMBER:
			return eEcoreContainerAny(getMember(),uml::umlPackage::NAMEDELEMENT_CLASS); //15614
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDMEMBER:
			return eEcoreContainerAny(getOwnedMember(),uml::umlPackage::NAMEDELEMENT_CLASS); //15612
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDRULE:
			return eEcoreContainerAny(getOwnedRule(),uml::umlPackage::CONSTRAINT_CLASS); //1569
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_PACKAGEIMPORT:
			return eEcoreContainerAny(getPackageImport(),uml::umlPackage::PACKAGEIMPORT_CLASS); //15611
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}

bool NamespaceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_ELEMENTIMPORT:
			return getElementImport() != nullptr; //15610
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_IMPORTEDMEMBER:
			return getImportedMember() != nullptr; //15613
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_MEMBER:
			return getMember() != nullptr; //15614
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDMEMBER:
			return getOwnedMember() != nullptr; //15612
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDRULE:
			return getOwnedRule() != nullptr; //1569
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_PACKAGEIMPORT:
			return getPackageImport() != nullptr; //15611
	}
	return NamedElementImpl::internalEIsSet(featureID);
}

bool NamespaceImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_ELEMENTIMPORT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::ElementImport>> _elementImport = getElementImport();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ElementImport> valueToAdd = std::dynamic_pointer_cast<uml::ElementImport>(anEObject);
	
							if (valueToAdd)
							{
								if(_elementImport->find(valueToAdd) == -1)
								{
									_elementImport->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'elementImport'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'elementImport'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDRULE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Constraint>> _ownedRule = getOwnedRule();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Constraint> valueToAdd = std::dynamic_pointer_cast<uml::Constraint>(anEObject);
	
							if (valueToAdd)
							{
								if(_ownedRule->find(valueToAdd) == -1)
								{
									_ownedRule->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'ownedRule'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'ownedRule'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_PACKAGEIMPORT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::PackageImport>> _packageImport = getPackageImport();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::PackageImport> valueToAdd = std::dynamic_pointer_cast<uml::PackageImport>(anEObject);
	
							if (valueToAdd)
							{
								if(_packageImport->find(valueToAdd) == -1)
								{
									_packageImport->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'packageImport'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'packageImport'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> NamespaceImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Namespace::createElementImport(uml::PackageableElement, uml::VisibilityKind) : uml::ElementImport: 3041688654
		case umlPackage::NAMESPACE_OPERATION_CREATEELEMENTIMPORT_PACKAGEABLEELEMENT_VISIBILITYKIND:
		{
			//Retrieve input parameter 'element'
			//parameter 0
			std::shared_ptr<uml::PackageableElement> incoming_param_element;
			Bag<Any>::const_iterator incoming_param_element_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_element_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_element = std::dynamic_pointer_cast<uml::PackageableElement>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'element'. Failed to invoke operation 'createElementImport'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'element'. Failed to invoke operation 'createElementImport'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'visibility'
			//parameter 1
			uml::VisibilityKind incoming_param_visibility;
			Bag<Any>::const_iterator incoming_param_visibility_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_visibility = (*incoming_param_visibility_arguments_citer)->get<uml::VisibilityKind>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'visibility'. Failed to invoke operation 'createElementImport'!")
				return nullptr;
			}
		
			result = eEcoreAny(this->createElementImport(incoming_param_element,incoming_param_visibility), uml::umlPackage::ELEMENTIMPORT_CLASS);
			break;
		}
		// uml::Namespace::createPackageImport(uml::Package, uml::VisibilityKind) : uml::PackageImport: 3501829020
		case umlPackage::NAMESPACE_OPERATION_CREATEPACKAGEIMPORT_PACKAGE_VISIBILITYKIND:
		{
			//Retrieve input parameter 'package_'
			//parameter 0
			std::shared_ptr<uml::Package> incoming_param_package_;
			Bag<Any>::const_iterator incoming_param_package__arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_package__arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_package_ = std::dynamic_pointer_cast<uml::Package>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'package_'. Failed to invoke operation 'createPackageImport'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'package_'. Failed to invoke operation 'createPackageImport'!")
					return nullptr;
				}
			}
		
			//Retrieve input parameter 'visibility'
			//parameter 1
			uml::VisibilityKind incoming_param_visibility;
			Bag<Any>::const_iterator incoming_param_visibility_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_visibility = (*incoming_param_visibility_arguments_citer)->get<uml::VisibilityKind>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'visibility'. Failed to invoke operation 'createPackageImport'!")
				return nullptr;
			}
		
			result = eEcoreAny(this->createPackageImport(incoming_param_package_,incoming_param_visibility), uml::umlPackage::PACKAGEIMPORT_CLASS);
			break;
		}
		// uml::Namespace::excludeCollisions(uml::PackageableElement[*]) : uml::PackageableElement[*]: 2855843539
		case umlPackage::NAMESPACE_OPERATION_EXCLUDECOLLISIONS_PACKAGEABLEELEMENT:
		{
			//Retrieve input parameter 'imps'
			//parameter 0
			std::shared_ptr<Bag<uml::PackageableElement>> incoming_param_imps;
			Bag<Any>::const_iterator incoming_param_imps_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_imps_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_imps.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<uml::PackageableElement> _temp = std::dynamic_pointer_cast<uml::PackageableElement>(anEObject);
								incoming_param_imps->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'imps'. Failed to invoke operation 'excludeCollisions'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'imps'. Failed to invoke operation 'excludeCollisions'!")
					return nullptr;
				}
			}
		
			std::shared_ptr<Bag<uml::PackageableElement>> resultList = this->excludeCollisions(incoming_param_imps);
			return eEcoreContainerAny(resultList,uml::umlPackage::PACKAGEABLEELEMENT_CLASS);
			break;
		}
		// uml::Namespace::getImportedElements() : uml::PackageableElement[*]: 2588792065
		case umlPackage::NAMESPACE_OPERATION_GETIMPORTEDELEMENTS:
		{
			std::shared_ptr<Bag<uml::PackageableElement>> resultList = this->getImportedElements();
			return eEcoreContainerAny(resultList,uml::umlPackage::PACKAGEABLEELEMENT_CLASS);
			break;
		}
		// uml::Namespace::getImportedMembers() : uml::PackageableElement[*]: 2627629447
		case umlPackage::NAMESPACE_OPERATION_GETIMPORTEDMEMBERS:
		{
			std::shared_ptr<Bag<uml::PackageableElement>> resultList = this->getImportedMembers();
			return eEcoreContainerAny(resultList,uml::umlPackage::PACKAGEABLEELEMENT_CLASS);
			break;
		}
		// uml::Namespace::getImportedPackages() : uml::Package[*]: 1496815389
		case umlPackage::NAMESPACE_OPERATION_GETIMPORTEDPACKAGES:
		{
			std::shared_ptr<Bag<uml::Package>> resultList = this->getImportedPackages();
			return eEcoreContainerAny(resultList,uml::umlPackage::PACKAGE_CLASS);
			break;
		}
		// uml::Namespace::getNamesOfMember(uml::NamedElement) : std::string[*]: 3293858424
		case umlPackage::NAMESPACE_OPERATION_GETNAMESOFMEMBER_NAMEDELEMENT:
		{
			//Retrieve input parameter 'element'
			//parameter 0
			std::shared_ptr<uml::NamedElement> incoming_param_element;
			Bag<Any>::const_iterator incoming_param_element_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_element_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_element = std::dynamic_pointer_cast<uml::NamedElement>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'element'. Failed to invoke operation 'getNamesOfMember'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'element'. Failed to invoke operation 'getNamesOfMember'!")
					return nullptr;
				}
			}
		
			result = eAny(this->getNamesOfMember(incoming_param_element), 0, true);
			break;
		}
		// uml::Namespace::getOwnedMembers() : uml::NamedElement[*]: 353105181
		case umlPackage::NAMESPACE_OPERATION_GETOWNEDMEMBERS:
		{
			std::shared_ptr<Bag<uml::NamedElement>> resultList = this->getOwnedMembers();
			return eEcoreContainerAny(resultList,uml::umlPackage::NAMEDELEMENT_CLASS);
			break;
		}
		// uml::Namespace::importMembers(uml::PackageableElement[*]) : uml::PackageableElement[*]: 2696590848
		case umlPackage::NAMESPACE_OPERATION_IMPORTMEMBERS_PACKAGEABLEELEMENT:
		{
			//Retrieve input parameter 'imps'
			//parameter 0
			std::shared_ptr<Bag<uml::PackageableElement>> incoming_param_imps;
			Bag<Any>::const_iterator incoming_param_imps_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_imps_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_imps.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<uml::PackageableElement> _temp = std::dynamic_pointer_cast<uml::PackageableElement>(anEObject);
								incoming_param_imps->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'imps'. Failed to invoke operation 'importMembers'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'imps'. Failed to invoke operation 'importMembers'!")
					return nullptr;
				}
			}
		
			std::shared_ptr<Bag<uml::PackageableElement>> resultList = this->importMembers(incoming_param_imps);
			return eEcoreContainerAny(resultList,uml::umlPackage::PACKAGEABLEELEMENT_CLASS);
			break;
		}
		// uml::Namespace::membersAreDistinguishable() : bool: 1431982872
		case umlPackage::NAMESPACE_OPERATION_MEMBERSAREDISTINGUISHABLE:
		{
			result = eAny(this->membersAreDistinguishable(), 0, false);
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

std::shared_ptr<uml::Namespace> NamespaceImpl::getThisNamespacePtr() const
{
	return m_thisNamespacePtr.lock();
}
void NamespaceImpl::setThisNamespacePtr(std::weak_ptr<uml::Namespace> thisNamespacePtr)
{
	m_thisNamespacePtr = thisNamespacePtr;
	setThisNamedElementPtr(thisNamespacePtr);
}


