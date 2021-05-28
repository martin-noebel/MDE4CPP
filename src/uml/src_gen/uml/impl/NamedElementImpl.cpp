#include "uml/impl/NamedElementImpl.hpp"

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
#include <algorithm>

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Usage.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
NamedElementImpl::NamedElementImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

NamedElementImpl::~NamedElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete NamedElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
NamedElementImpl::NamedElementImpl(std::weak_ptr<uml::Namespace> par_namespace)
:NamedElementImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
NamedElementImpl::NamedElementImpl(std::weak_ptr<uml::Element> par_owner)
:NamedElementImpl()
{
	m_owner = par_owner;
}

NamedElementImpl::NamedElementImpl(const NamedElementImpl & obj): NamedElementImpl()
{
	*this = obj;
}

NamedElementImpl& NamedElementImpl::operator=(const NamedElementImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	NamedElement::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy NamedElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));
	m_namespace  = obj.getNamespace();
	//Clone references with containment (deep copy)
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> NamedElementImpl::copy() const
{
	std::shared_ptr<NamedElementImpl> element(new NamedElementImpl());
	*element =(*this);
	element->setThisNamedElementPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> NamedElementImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getNamedElement_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute name
*/
std::string NamedElementImpl::getName() const 
{
	return m_name;
}
void NamedElementImpl::setName(std::string _name)
{
	m_name = _name;
} 


/*
Getter & Setter for attribute qualifiedName
*/




/*
Getter & Setter for attribute visibility
*/
uml::VisibilityKind NamedElementImpl::getVisibility() const 
{
	return m_visibility;
}
void NamedElementImpl::setVisibility(uml::VisibilityKind _visibility)
{
	m_visibility = _visibility;
} 


//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Namespace> > NamedElementImpl::allNamespaces() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Namespace> > allNS(new Bag<uml::Namespace>());
    if (getNamespace().lock() == nullptr)
    {
        return allNS;
    }
    else
    {
    	std::shared_ptr<Bag<uml::Namespace> > currentNSList = getNamespace().lock()->allNamespaces();
        allNS->insert(allNS->end(), currentNSList->begin(), currentNSList->end());
        currentNSList = nullptr;

        std::shared_ptr<uml::Namespace> currentNS = getNamespace().lock();
        if (currentNS != nullptr)
        {
            allNS->push_back(currentNS);
        }
        return allNS;
    }
	//end of body
}

std::shared_ptr<Bag<uml::Package> > NamedElementImpl::allOwningPackages()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Dependency> NamedElementImpl::createDependency(std::shared_ptr<uml::NamedElement> supplier)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Usage> NamedElementImpl::createUsage(std::shared_ptr<uml::NamedElement> supplier)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Dependency> > NamedElementImpl::getClientDependencies()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string NamedElementImpl::getLabel()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string NamedElementImpl::getLabel(bool localize)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



std::string NamedElementImpl::getQualifiedName() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr< Bag<uml::Namespace> >  allNS = allNamespaces();

    if(!this->getName().empty() && std::none_of(allNS->cbegin(), allNS->cend(), [](std::shared_ptr<uml::Namespace> ns){ return ns->getName().empty(); }))
    {
        std::string ret;
        for(std::shared_ptr<uml::Namespace> ns : *allNS )
        {
            ret += ns->getName() + separator();
        }
        ret += getName();
        return ret;
    }
    else
    {
        return std::string();
    }
	//end of body
}

bool NamedElementImpl::has_no_qualified_name(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamedElementImpl::has_qualified_name(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool NamedElementImpl::isDistinguishableFrom(std::shared_ptr<uml::NamedElement> n,std::shared_ptr<uml::Namespace> ns)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string NamedElementImpl::separator() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "::";
	//end of body
}

bool NamedElementImpl::visibility_needs_ownership(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference clientDependency
*/
std::shared_ptr<Bag<uml::Dependency>> NamedElementImpl::getClientDependency() const
{
	if(m_clientDependency == nullptr)
	{
		m_clientDependency.reset(new Bag<uml::Dependency>());
		
		
	}

    return m_clientDependency;
}



/*
Getter & Setter for reference nameExpression
*/
std::shared_ptr<uml::StringExpression> NamedElementImpl::getNameExpression() const
{

    return m_nameExpression;
}
void NamedElementImpl::setNameExpression(std::shared_ptr<uml::StringExpression> _nameExpression)
{
    m_nameExpression = _nameExpression;
}


/*
Getter & Setter for reference namespace
*/




//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> NamedElementImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> NamedElementImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> NamedElementImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<NamedElement> NamedElementImpl::getThisNamedElementPtr() const
{
	return m_thisNamedElementPtr.lock();
}
void NamedElementImpl::setThisNamedElementPtr(std::weak_ptr<NamedElement> thisNamedElementPtr)
{
	m_thisNamedElementPtr = thisNamedElementPtr;
	setThisElementPtr(thisNamedElementPtr);
}
std::shared_ptr<ecore::EObject> NamedElementImpl::eContainer() const
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
Any NamedElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_CLIENTDEPENDENCY:
		{
			return eAny(getClientDependency()); //1553			
		}
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAME:
			return eAny(getName()); //1554
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAMEEXPRESSION:
			return eAny(getNameExpression()); //1555
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
			return eAny(getNamespace().lock()); //1556
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_QUALIFIEDNAME:
			return eAny(getQualifiedName()); //1557
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_VISIBILITY:
			return eAny(getVisibility()); //1558
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool NamedElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_CLIENTDEPENDENCY:
			return getClientDependency() != nullptr; //1553
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAME:
			return getName() != ""; //1554
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAMEEXPRESSION:
			return getNameExpression() != nullptr; //1555
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
			return getNamespace().lock() != nullptr; //1556
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_QUALIFIEDNAME:
			return getQualifiedName() != ""; //1557
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_VISIBILITY:
			return m_visibility != VisibilityKind::PUBLIC;; //1558
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool NamedElementImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAME:
		{
			// BOOST CAST
			std::string _name = newValue->get<std::string>();
			setName(_name); //1554
			return true;
		}
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAMEEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StringExpression> _nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(_temp);
			setNameExpression(_nameExpression); //1555
			return true;
		}
		case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			uml::VisibilityKind _visibility = newValue->get<uml::VisibilityKind>();
			setVisibility(_visibility); //1558
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any NamedElementImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 15559
		case umlPackage::NAMEDELEMENT_OPERATION_ALLNAMESPACES:
		{
			result = eAny(this->allNamespaces());
			break;
		}
		
		// 15560
		case umlPackage::NAMEDELEMENT_OPERATION_ALLOWNINGPACKAGES:
		{
			result = eAny(this->allOwningPackages());
			break;
		}
		
		// 15554
		case umlPackage::NAMEDELEMENT_OPERATION_CREATEDEPENDENCY_NAMEDELEMENT:
		{
			//Retrieve input parameter 'supplier'
			//parameter 0
			std::shared_ptr<uml::NamedElement> incoming_param_supplier;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_supplier_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_supplier = (*incoming_param_supplier_arguments_citer)->get()->get<std::shared_ptr<uml::NamedElement> >();
			result = eAny(this->createDependency(incoming_param_supplier));
			break;
		}
		
		// 15555
		case umlPackage::NAMEDELEMENT_OPERATION_CREATEUSAGE_NAMEDELEMENT:
		{
			//Retrieve input parameter 'supplier'
			//parameter 0
			std::shared_ptr<uml::NamedElement> incoming_param_supplier;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_supplier_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_supplier = (*incoming_param_supplier_arguments_citer)->get()->get<std::shared_ptr<uml::NamedElement> >();
			result = eAny(this->createUsage(incoming_param_supplier));
			break;
		}
		
		// 15564
		case umlPackage::NAMEDELEMENT_OPERATION_GETCLIENTDEPENDENCIES:
		{
			result = eAny(this->getClientDependencies());
			break;
		}
		
		// 15556
		case umlPackage::NAMEDELEMENT_OPERATION_GETLABEL:
		{
			result = eAny(this->getLabel());
			break;
		}
		
		// 15557
		case umlPackage::NAMEDELEMENT_OPERATION_GETLABEL_BOOLEAN:
		{
			//Retrieve input parameter 'localize'
			//parameter 0
			bool incoming_param_localize;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_localize_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_localize = (*incoming_param_localize_arguments_citer)->get()->get<bool >();
			result = eAny(this->getLabel(incoming_param_localize));
			break;
		}
		
		// 15558
		case umlPackage::NAMEDELEMENT_OPERATION_GETNAMESPACE:
		{
			result = eAny(this->getNamespace());
			break;
		}
		
		// 15562
		case umlPackage::NAMEDELEMENT_OPERATION_GETQUALIFIEDNAME:
		{
			result = eAny(this->getQualifiedName());
			break;
		}
		
		// 15553
		case umlPackage::NAMEDELEMENT_OPERATION_HAS_NO_QUALIFIED_NAME_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->has_no_qualified_name(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 15552
		case umlPackage::NAMEDELEMENT_OPERATION_HAS_QUALIFIED_NAME_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->has_qualified_name(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 15561
		case umlPackage::NAMEDELEMENT_OPERATION_ISDISTINGUISHABLEFROM_NAMEDELEMENT_NAMESPACE:
		{
			//Retrieve input parameter 'n'
			//parameter 0
			std::shared_ptr<uml::NamedElement> incoming_param_n;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_n_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_n = (*incoming_param_n_arguments_citer)->get()->get<std::shared_ptr<uml::NamedElement> >();
			//Retrieve input parameter 'ns'
			//parameter 1
			std::shared_ptr<uml::Namespace> incoming_param_ns;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_ns_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_ns = (*incoming_param_ns_arguments_citer)->get()->get<std::shared_ptr<uml::Namespace> >();
			result = eAny(this->isDistinguishableFrom(incoming_param_n,incoming_param_ns));
			break;
		}
		
		// 15563
		case umlPackage::NAMEDELEMENT_OPERATION_SEPARATOR:
		{
			result = eAny(this->separator());
			break;
		}
		
		// 15551
		case umlPackage::NAMEDELEMENT_OPERATION_VISIBILITY_NEEDS_OWNERSHIP_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->visibility_needs_ownership(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = ElementImpl::eInvoke(operationID, arguments);
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
void NamedElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void NamedElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("name");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setName(value);
		}

		iter = attr_list.find("visibility");
		if ( iter != attr_list.end() )
		{
			uml::VisibilityKind value = VisibilityKind::PUBLIC;
			std::string literal = iter->second;
			if (literal == "public")
			{
				value = VisibilityKind::PUBLIC;
			}
			else if (literal == "private")
			{
				value = VisibilityKind::PRIVATE;
			}
			else if (literal == "protected")
			{
				value = VisibilityKind::PROTECTED;
			}
			else if (literal == "package")
			{
				value = VisibilityKind::PACKAGE;
			}
			this->setVisibility(value);
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

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void NamedElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("nameExpression") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "StringExpression";
			}
			loadHandler->handleChild(this->getNameExpression()); 

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
	ElementImpl::loadNode(nodeName, loadHandler);
}

void NamedElementImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ElementImpl::resolveReferences(featureID, references);
}

void NamedElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void NamedElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'nameExpression'
		std::shared_ptr<uml::StringExpression> nameExpression = this->getNameExpression();
		if (nameExpression != nullptr)
		{
			saveHandler->addReference(nameExpression, "nameExpression", nameExpression->eClass() != package->getStringExpression_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getNamedElement_Attribute_name()) )
		{
			saveHandler->addAttribute("name", this->getName());
		}

		if ( this->eIsSet(package->getNamedElement_Attribute_visibility()) )
		{
			uml::VisibilityKind value = this->getVisibility();
			std::string literal = "";
			if (value == VisibilityKind::PUBLIC)
			{
				literal = "public";
			}
			else if (value == VisibilityKind::PRIVATE)
			{
				literal = "private";
			}
			else if (value == VisibilityKind::PROTECTED)
			{
				literal = "protected";
			}
			else if (value == VisibilityKind::PACKAGE)
			{
				literal = "package";
			}
			saveHandler->addAttribute("visibility", literal);
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

