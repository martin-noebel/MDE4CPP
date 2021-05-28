#include "uml/impl/NamespaceImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"


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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	Namespace::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Namespace "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<SubsetUnion<uml::ElementImport, uml::Element>> elementImportContainer = getElementImport();
	if(nullptr != elementImportContainer )
	{
		int size = elementImportContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _elementImport=(*elementImportContainer)[i];
			if(nullptr != _elementImport)
			{
				elementImportContainer->push_back(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container elementImport."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr elementImport."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>> importedMemberContainer = getImportedMember();
	if(nullptr != importedMemberContainer )
	{
		int size = importedMemberContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _importedMember=(*importedMemberContainer)[i];
			if(nullptr != _importedMember)
			{
				importedMemberContainer->push_back(std::dynamic_pointer_cast<uml::PackageableElement>(_importedMember->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container importedMember."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr importedMember."<< std::endl;)
	}
	std::shared_ptr<SubsetUnion<uml::Constraint, uml::NamedElement>> ownedRuleContainer = getOwnedRule();
	if(nullptr != ownedRuleContainer )
	{
		int size = ownedRuleContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedRule=(*ownedRuleContainer)[i];
			if(nullptr != _ownedRule)
			{
				ownedRuleContainer->push_back(std::dynamic_pointer_cast<uml::Constraint>(_ownedRule->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedRule."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedRule."<< std::endl;)
	}
	std::shared_ptr<SubsetUnion<uml::PackageImport, uml::Element>> packageImportContainer = getPackageImport();
	if(nullptr != packageImportContainer )
	{
		int size = packageImportContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _packageImport=(*packageImportContainer)[i];
			if(nullptr != _packageImport)
			{
				packageImportContainer->push_back(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container packageImport."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr packageImport."<< std::endl;)
	}
	/*SubsetUnion*/
	m_elementImport->initSubsetUnion(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*SubsetUnion*/
	m_ownedRule->initSubsetUnion(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*SubsetUnion*/
	m_packageImport->initSubsetUnion(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> NamespaceImpl::copy() const
{
	std::shared_ptr<NamespaceImpl> element(new NamespaceImpl());
	*element =(*this);
	element->setThisNamespacePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> NamespaceImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getNamespace_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool NamespaceImpl::cannot_import_ownedMembers(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamespaceImpl::cannot_import_self(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::ElementImport> NamespaceImpl::createElementImport(std::shared_ptr<uml::PackageableElement> element,uml::VisibilityKind visibility)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::PackageImport> NamespaceImpl::createPackageImport(std::shared_ptr<uml::Package> package_,uml::VisibilityKind visibility)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::PackageableElement> > NamespaceImpl::excludeCollisions(std::shared_ptr<Bag<uml::PackageableElement>> imps)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::PackageableElement> > NamespaceImpl::getImportedElements()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::PackageableElement> > NamespaceImpl::getImportedMembers()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Package> > NamespaceImpl::getImportedPackages()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<std::string> > NamespaceImpl::getNamesOfMember(std::shared_ptr<uml::NamedElement> element)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::NamedElement> > NamespaceImpl::getOwnedMembers()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::PackageableElement> > NamespaceImpl::importMembers(std::shared_ptr<Bag<uml::PackageableElement>> imps)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamespaceImpl::membersAreDistinguishable()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamespaceImpl::members_distinguishable(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference elementImport
*/
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
		m_elementImport->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_elementImport;
}



/*
Getter & Setter for reference importedMember
*/
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
		m_importedMember->initSubset(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_importedMember - Subset<uml::PackageableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}

    return m_importedMember;
}



/*
Getter & Setter for reference member
*/




/*
Getter & Setter for reference ownedMember
*/




/*
Getter & Setter for reference ownedRule
*/
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
		m_ownedRule->initSubsetUnion(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedRule;
}



/*
Getter & Setter for reference packageImport
*/
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
		m_packageImport->initSubsetUnion(getOwnedElement());
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

std::shared_ptr<Union<uml::Element>> NamespaceImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> NamespaceImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> NamespaceImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Namespace> NamespaceImpl::getThisNamespacePtr() const
{
	return m_thisNamespacePtr.lock();
}
void NamespaceImpl::setThisNamespacePtr(std::weak_ptr<Namespace> thisNamespacePtr)
{
	m_thisNamespacePtr = thisNamespacePtr;
	setThisNamedElementPtr(thisNamespacePtr);
}
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

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any NamespaceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_ELEMENTIMPORT:
		{
			return eAny(getElementImport()); //15610			
		}
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_IMPORTEDMEMBER:
		{
			return eAny(getImportedMember()); //15613			
		}
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_MEMBER:
		{
			return eAny(getMember()); //15614			
		}
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDMEMBER:
		{
			return eAny(getOwnedMember()); //15612			
		}
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDRULE:
		{
			return eAny(getOwnedRule()); //1569			
		}
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_PACKAGEIMPORT:
		{
			return eAny(getPackageImport()); //15611			
		}
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
bool NamespaceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_ELEMENTIMPORT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ElementImport>> elementImportList(new Bag<uml::ElementImport>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				elementImportList->add(std::dynamic_pointer_cast<uml::ElementImport>(*iter));
				iter++;
			}
			
			Bag<uml::ElementImport>::iterator iterElementImport = m_elementImport->begin();
			Bag<uml::ElementImport>::iterator endElementImport = m_elementImport->end();
			while (iterElementImport != endElementImport)
			{
				if (elementImportList->find(*iterElementImport) == -1)
				{
					m_elementImport->erase(*iterElementImport);
				}
				iterElementImport++;
			}
 
			iterElementImport = elementImportList->begin();
			endElementImport = elementImportList->end();
			while (iterElementImport != endElementImport)
			{
				if (m_elementImport->find(*iterElementImport) == -1)
				{
					m_elementImport->add(*iterElementImport);
				}
				iterElementImport++;			
			}
			return true;
		}
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDRULE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Constraint>> ownedRuleList(new Bag<uml::Constraint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedRuleList->add(std::dynamic_pointer_cast<uml::Constraint>(*iter));
				iter++;
			}
			
			Bag<uml::Constraint>::iterator iterOwnedRule = m_ownedRule->begin();
			Bag<uml::Constraint>::iterator endOwnedRule = m_ownedRule->end();
			while (iterOwnedRule != endOwnedRule)
			{
				if (ownedRuleList->find(*iterOwnedRule) == -1)
				{
					m_ownedRule->erase(*iterOwnedRule);
				}
				iterOwnedRule++;
			}
 
			iterOwnedRule = ownedRuleList->begin();
			endOwnedRule = ownedRuleList->end();
			while (iterOwnedRule != endOwnedRule)
			{
				if (m_ownedRule->find(*iterOwnedRule) == -1)
				{
					m_ownedRule->add(*iterOwnedRule);
				}
				iterOwnedRule++;			
			}
			return true;
		}
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_PACKAGEIMPORT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::PackageImport>> packageImportList(new Bag<uml::PackageImport>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				packageImportList->add(std::dynamic_pointer_cast<uml::PackageImport>(*iter));
				iter++;
			}
			
			Bag<uml::PackageImport>::iterator iterPackageImport = m_packageImport->begin();
			Bag<uml::PackageImport>::iterator endPackageImport = m_packageImport->end();
			while (iterPackageImport != endPackageImport)
			{
				if (packageImportList->find(*iterPackageImport) == -1)
				{
					m_packageImport->erase(*iterPackageImport);
				}
				iterPackageImport++;
			}
 
			iterPackageImport = packageImportList->begin();
			endPackageImport = packageImportList->end();
			while (iterPackageImport != endPackageImport)
			{
				if (m_packageImport->find(*iterPackageImport) == -1)
				{
					m_packageImport->add(*iterPackageImport);
				}
				iterPackageImport++;			
			}
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any NamespaceImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 15673
		case umlPackage::NAMESPACE_OPERATION_CANNOT_IMPORT_OWNEDMEMBERS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->cannot_import_ownedMembers(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 15672
		case umlPackage::NAMESPACE_OPERATION_CANNOT_IMPORT_SELF_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->cannot_import_self(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 15674
		case umlPackage::NAMESPACE_OPERATION_CREATEELEMENTIMPORT_PACKAGEABLEELEMENT_VISIBILITYKIND:
		{
			//Retrieve input parameter 'element'
			//parameter 0
			std::shared_ptr<uml::PackageableElement> incoming_param_element;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_element_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_element = (*incoming_param_element_arguments_citer)->get()->get<std::shared_ptr<uml::PackageableElement> >();
			//Retrieve input parameter 'visibility'
			//parameter 1
			uml::VisibilityKind incoming_param_visibility;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_visibility_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_visibility = (*incoming_param_visibility_arguments_citer)->get()->get<uml::VisibilityKind >();
			result = eAny(this->createElementImport(incoming_param_element,incoming_param_visibility));
			break;
		}
		
		// 15675
		case umlPackage::NAMESPACE_OPERATION_CREATEPACKAGEIMPORT_PACKAGE_VISIBILITYKIND:
		{
			//Retrieve input parameter 'package_'
			//parameter 0
			std::shared_ptr<uml::Package> incoming_param_package_;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_package__arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_package_ = (*incoming_param_package__arguments_citer)->get()->get<std::shared_ptr<uml::Package> >();
			//Retrieve input parameter 'visibility'
			//parameter 1
			uml::VisibilityKind incoming_param_visibility;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_visibility_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_visibility = (*incoming_param_visibility_arguments_citer)->get()->get<uml::VisibilityKind >();
			result = eAny(this->createPackageImport(incoming_param_package_,incoming_param_visibility));
			break;
		}
		
		// 15679
		case umlPackage::NAMESPACE_OPERATION_EXCLUDECOLLISIONS_PACKAGEABLEELEMENT:
		{
			//Retrieve input parameter 'imps'
			//parameter 0
			std::shared_ptr<Bag<uml::PackageableElement>> incoming_param_imps;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_imps_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_imps = (*incoming_param_imps_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::PackageableElement>> >();
			result = eAny(this->excludeCollisions(incoming_param_imps));
			break;
		}
		
		// 15676
		case umlPackage::NAMESPACE_OPERATION_GETIMPORTEDELEMENTS:
		{
			result = eAny(this->getImportedElements());
			break;
		}
		
		// 15682
		case umlPackage::NAMESPACE_OPERATION_GETIMPORTEDMEMBERS:
		{
			result = eAny(this->getImportedMembers());
			break;
		}
		
		// 15677
		case umlPackage::NAMESPACE_OPERATION_GETIMPORTEDPACKAGES:
		{
			result = eAny(this->getImportedPackages());
			break;
		}
		
		// 15680
		case umlPackage::NAMESPACE_OPERATION_GETNAMESOFMEMBER_NAMEDELEMENT:
		{
			//Retrieve input parameter 'element'
			//parameter 0
			std::shared_ptr<uml::NamedElement> incoming_param_element;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_element_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_element = (*incoming_param_element_arguments_citer)->get()->get<std::shared_ptr<uml::NamedElement> >();
			result = eAny(this->getNamesOfMember(incoming_param_element));
			break;
		}
		
		// 15678
		case umlPackage::NAMESPACE_OPERATION_GETOWNEDMEMBERS:
		{
			result = eAny(this->getOwnedMembers());
			break;
		}
		
		// 15681
		case umlPackage::NAMESPACE_OPERATION_IMPORTMEMBERS_PACKAGEABLEELEMENT:
		{
			//Retrieve input parameter 'imps'
			//parameter 0
			std::shared_ptr<Bag<uml::PackageableElement>> incoming_param_imps;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_imps_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_imps = (*incoming_param_imps_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::PackageableElement>> >();
			result = eAny(this->importMembers(incoming_param_imps));
			break;
		}
		
		// 15683
		case umlPackage::NAMESPACE_OPERATION_MEMBERSAREDISTINGUISHABLE:
		{
			result = eAny(this->membersAreDistinguishable());
			break;
		}
		
		// 15671
		case umlPackage::NAMESPACE_OPERATION_MEMBERS_DISTINGUISHABLE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->members_distinguishable(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
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
void NamespaceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void NamespaceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void NamespaceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("elementImport") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ElementImport";
			}
			loadHandler->handleChildContainer<uml::ElementImport>(this->getElementImport());  

			return; 
		}

		if ( nodeName.compare("ownedMember") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::NamedElement>(this->getOwnedMember());  

			return; 
		}

		if ( nodeName.compare("ownedRule") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Constraint";
			}
			loadHandler->handleChildContainer<uml::Constraint>(this->getOwnedRule());  

			return; 
		}

		if ( nodeName.compare("packageImport") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "PackageImport";
			}
			loadHandler->handleChildContainer<uml::PackageImport>(this->getPackageImport());  

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

void NamespaceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	NamedElementImpl::resolveReferences(featureID, references);
}

void NamespaceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void NamespaceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'elementImport'

		saveHandler->addReferences<uml::ElementImport>("elementImport", this->getElementImport());

		// Save 'ownedMember'

		saveHandler->addReferences<uml::NamedElement>("ownedMember", this->getOwnedMember());

		// Save 'ownedRule'

		saveHandler->addReferences<uml::Constraint>("ownedRule", this->getOwnedRule());

		// Save 'packageImport'

		saveHandler->addReferences<uml::PackageImport>("packageImport", this->getPackageImport());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

