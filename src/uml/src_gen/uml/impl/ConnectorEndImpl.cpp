
#include "uml/impl/ConnectorEndImpl.hpp"

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

#include "abstractDataTypes/Subset.hpp"


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
#include "uml/ConnectableElement.hpp"
#include "uml/Connector.hpp"
#include "uml/Element.hpp"
#include "uml/MultiplicityElement.hpp"
#include "uml/Property.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectorEndImpl::ConnectorEndImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ConnectorEndImpl::~ConnectorEndImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConnectorEnd "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConnectorEndImpl::ConnectorEndImpl(std::weak_ptr<uml::Connector> par_connector)
:ConnectorEndImpl()
{
	m_connector = par_connector;
}

//Additional constructor for the containments back reference
ConnectorEndImpl::ConnectorEndImpl(std::weak_ptr<uml::Element> par_owner)
:ConnectorEndImpl()
{
	m_owner = par_owner;
}

ConnectorEndImpl::ConnectorEndImpl(const ConnectorEndImpl & obj): ConnectorEndImpl()
{
	*this = obj;
}

ConnectorEndImpl& ConnectorEndImpl::operator=(const ConnectorEndImpl & obj)
{
	//call overloaded =Operator for each base class
	MultiplicityElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ConnectorEnd 
	 * which is generated by the compiler (as ConnectorEnd is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ConnectorEnd::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConnectorEnd "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_connector  = obj.getConnector();
	m_definingEnd  = obj.getDefiningEnd();
	m_partWithPort  = obj.getPartWithPort();
	m_role  = obj.getRole();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ConnectorEndImpl::copy() const
{
	std::shared_ptr<ConnectorEndImpl> element(new ConnectorEndImpl());
	*element =(*this);
	element->setThisConnectorEndPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************


bool ConnectorEndImpl::multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorEndImpl::part_with_port_empty(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorEndImpl::role_and_part_with_port(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectorEndImpl::self_part_with_port(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
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
/* Getter & Setter for reference connector */
std::weak_ptr<uml::Connector> ConnectorEndImpl::getConnector() const
{
    return m_connector;
}
void ConnectorEndImpl::setConnector(std::weak_ptr<uml::Connector> _connector)
{
    m_connector = _connector;
	
}

/* Getter & Setter for reference definingEnd */
std::shared_ptr<uml::Property> ConnectorEndImpl::getDefiningEnd() const
{
    return m_definingEnd;
}

/* Getter & Setter for reference partWithPort */
std::shared_ptr<uml::Property> ConnectorEndImpl::getPartWithPort() const
{
    return m_partWithPort;
}
void ConnectorEndImpl::setPartWithPort(std::shared_ptr<uml::Property> _partWithPort)
{
    m_partWithPort = _partWithPort;
	
}

/* Getter & Setter for reference role */
std::shared_ptr<uml::ConnectableElement> ConnectorEndImpl::getRole() const
{
    return m_role;
}
void ConnectorEndImpl::setRole(std::shared_ptr<uml::ConnectableElement> _role)
{
    m_role = _role;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ConnectorEndImpl::getOwnedElement() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ConnectorEndImpl::eContainer() const
{
	if(auto wp = m_connector.lock())
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
// Persistence Functions
//*********************************
void ConnectorEndImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ConnectorEndImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("partWithPort");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("partWithPort")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("role");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("role")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	MultiplicityElementImpl::loadAttributes(loadHandler, attr_list);
}

void ConnectorEndImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	MultiplicityElementImpl::loadNode(nodeName, loadHandler);
}

void ConnectorEndImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_CONNECTOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Connector> _connector = std::dynamic_pointer_cast<uml::Connector>( references.front() );
				setConnector(_connector);
			}
			
			return;
		}

		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_PARTWITHPORT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Property> _partWithPort = std::dynamic_pointer_cast<uml::Property>( references.front() );
				setPartWithPort(_partWithPort);
			}
			
			return;
		}

		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_ROLE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ConnectableElement> _role = std::dynamic_pointer_cast<uml::ConnectableElement>( references.front() );
				setRole(_role);
			}
			
			return;
		}
	}
	MultiplicityElementImpl::resolveReferences(featureID, references);
}

void ConnectorEndImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	MultiplicityElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ConnectorEndImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getPartWithPort(), "partWithPort", getPartWithPort()->eClass() != uml::umlPackage::eInstance()->getProperty_Class()); 
		saveHandler->addReference(this->getRole(), "role", getRole()->eClass() != uml::umlPackage::eInstance()->getConnectableElement_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> ConnectorEndImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getConnectorEnd_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ConnectorEndImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_CONNECTOR:
			{
				std::shared_ptr<ecore::EObject> returnValue=getConnector().lock();
				return eAny(returnValue); //5412
			}
		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_DEFININGEND:
			{
				std::shared_ptr<ecore::EObject> returnValue=getDefiningEnd();
				return eAny(returnValue); //549
			}
		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_PARTWITHPORT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getPartWithPort();
				return eAny(returnValue); //5410
			}
		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_ROLE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getRole();
				return eAny(returnValue); //5411
			}
	}
	return MultiplicityElementImpl::eGet(featureID, resolve, coreType);
}

bool ConnectorEndImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_CONNECTOR:
			return getConnector().lock() != nullptr; //5412
		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_DEFININGEND:
			return getDefiningEnd() != nullptr; //549
		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_PARTWITHPORT:
			return getPartWithPort() != nullptr; //5410
		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_ROLE:
			return getRole() != nullptr; //5411
	}
	return MultiplicityElementImpl::internalEIsSet(featureID);
}

bool ConnectorEndImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_CONNECTOR:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Connector> _connector = std::dynamic_pointer_cast<uml::Connector>(_temp);
			setConnector(_connector); //5412
			return true;
		}
		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_PARTWITHPORT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Property> _partWithPort = std::dynamic_pointer_cast<uml::Property>(_temp);
			setPartWithPort(_partWithPort); //5410
			return true;
		}
		case uml::umlPackage::CONNECTOREND_ATTRIBUTE_ROLE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ConnectableElement> _role = std::dynamic_pointer_cast<uml::ConnectableElement>(_temp);
			setRole(_role); //5411
			return true;
		}
	}

	return MultiplicityElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ConnectorEndImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 847443347
		case umlPackage::CONNECTOREND_OPERATION_GETDEFININGEND:
		{
			result = eAny(this->getDefiningEnd());
			break;
		}
		
		// 931479953
		case umlPackage::CONNECTOREND_OPERATION_MULTIPLICITY_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->multiplicity(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 1300949541
		case umlPackage::CONNECTOREND_OPERATION_PART_WITH_PORT_EMPTY_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->part_with_port_empty(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 1121458246
		case umlPackage::CONNECTOREND_OPERATION_ROLE_AND_PART_WITH_PORT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->role_and_part_with_port(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 1132520274
		case umlPackage::CONNECTOREND_OPERATION_SELF_PART_WITH_PORT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->self_part_with_port(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = MultiplicityElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<uml::ConnectorEnd> ConnectorEndImpl::getThisConnectorEndPtr() const
{
	return m_thisConnectorEndPtr.lock();
}
void ConnectorEndImpl::setThisConnectorEndPtr(std::weak_ptr<uml::ConnectorEnd> thisConnectorEndPtr)
{
	m_thisConnectorEndPtr = thisConnectorEndPtr;
	setThisMultiplicityElementPtr(thisConnectorEndPtr);
}
