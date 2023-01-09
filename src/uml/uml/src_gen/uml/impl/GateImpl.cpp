
#include "uml/impl/GateImpl.hpp"
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
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Gate.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Message.hpp"
#include "uml/MessageEnd.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
GateImpl::GateImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

GateImpl::~GateImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Gate "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
GateImpl::GateImpl(std::weak_ptr<uml::Namespace> par_namespace)
:GateImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
GateImpl::GateImpl(std::weak_ptr<uml::Element> par_owner)
:GateImpl()
{
	m_owner = par_owner;
}

GateImpl::GateImpl(const GateImpl & obj): GateImpl()
{
	*this = obj;
}

GateImpl& GateImpl::operator=(const GateImpl & obj)
{
	//call overloaded =Operator for each base class
	MessageEndImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Gate 
	 * which is generated by the compiler (as Gate is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Gate::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Gate "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> GateImpl::copy() const
{
	std::shared_ptr<GateImpl> element(new GateImpl());
	*element =(*this);
	element->setThisGatePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::string GateImpl::getName() const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::InteractionOperand> GateImpl::getOperand()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool GateImpl::isActual()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool GateImpl::isFormal()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool GateImpl::isInsideCF()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool GateImpl::isOutsideCF()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool GateImpl::matches(std::shared_ptr<uml::Gate> gateToMatch)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> GateImpl::eContainer() const
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
// Persistence Functions
//*********************************
void GateImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void GateImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	MessageEndImpl::loadAttributes(loadHandler, attr_list);
}

void GateImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	MessageEndImpl::loadNode(nodeName, loadHandler);
}

void GateImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	MessageEndImpl::resolveReferences(featureID, references);
}

void GateImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	MessageEndImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void GateImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> GateImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getGate_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> GateImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return MessageEndImpl::eGet(featureID, resolve, coreType);
}

bool GateImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return MessageEndImpl::internalEIsSet(featureID);
}

bool GateImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
	}

	return MessageEndImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> GateImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Gate::getName() : std::string {const}: 2596943572
		case umlPackage::GATE_OPERATION_GETNAME:
		{
			result = eAny(this->getName(), 0, false);
			break;
		}
		// uml::Gate::getOperand() : uml::InteractionOperand: 1268229058
		case umlPackage::GATE_OPERATION_GETOPERAND:
		{
			result = eEcoreAny(this->getOperand(), uml::umlPackage::INTERACTIONOPERAND_CLASS);
			break;
		}
		// uml::Gate::isActual() : bool: 3905407116
		case umlPackage::GATE_OPERATION_ISACTUAL:
		{
			result = eAny(this->isActual(), 0, false);
			break;
		}
		// uml::Gate::isFormal() : bool: 1119363663
		case umlPackage::GATE_OPERATION_ISFORMAL:
		{
			result = eAny(this->isFormal(), 0, false);
			break;
		}
		// uml::Gate::isInsideCF() : bool: 1549572147
		case umlPackage::GATE_OPERATION_ISINSIDECF:
		{
			result = eAny(this->isInsideCF(), 0, false);
			break;
		}
		// uml::Gate::isOutsideCF() : bool: 2940571944
		case umlPackage::GATE_OPERATION_ISOUTSIDECF:
		{
			result = eAny(this->isOutsideCF(), 0, false);
			break;
		}
		// uml::Gate::matches(uml::Gate) : bool: 2884710854
		case umlPackage::GATE_OPERATION_MATCHES_GATE:
		{
			//Retrieve input parameter 'gateToMatch'
			//parameter 0
			std::shared_ptr<uml::Gate> incoming_param_gateToMatch;
			Bag<Any>::const_iterator incoming_param_gateToMatch_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>((*incoming_param_gateToMatch_arguments_citer));
				if(ecoreAny)
				{
					try
					{
						std::shared_ptr<ecore::EObject> _temp = ecoreAny->getAsEObject();
						incoming_param_gateToMatch = std::dynamic_pointer_cast<uml::Gate>(_temp);
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreAny' for parameter 'gateToMatch'. Failed to invoke operation 'matches'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreAny' for parameter 'gateToMatch'. Failed to invoke operation 'matches'!")
					return nullptr;
				}
			}
		
			result = eAny(this->matches(incoming_param_gateToMatch), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = MessageEndImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Gate> GateImpl::getThisGatePtr() const
{
	return m_thisGatePtr.lock();
}
void GateImpl::setThisGatePtr(std::weak_ptr<uml::Gate> thisGatePtr)
{
	m_thisGatePtr = thisGatePtr;
	setThisMessageEndPtr(thisGatePtr);
}


