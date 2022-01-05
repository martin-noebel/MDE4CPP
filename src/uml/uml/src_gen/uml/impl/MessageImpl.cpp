
#include "uml/impl/MessageImpl.hpp"

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
#include <stdexcept>


#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/Any.hpp"
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
#include "uml/Connector.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Interaction.hpp"
#include "uml/MessageEnd.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
MessageImpl::MessageImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

MessageImpl::~MessageImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Message "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
MessageImpl::MessageImpl(std::weak_ptr<uml::Interaction> par_interaction)
:MessageImpl()
{
	m_interaction = par_interaction;
	m_namespace = par_interaction;
}

//Additional constructor for the containments back reference
MessageImpl::MessageImpl(std::weak_ptr<uml::Namespace> par_namespace)
:MessageImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
MessageImpl::MessageImpl(std::weak_ptr<uml::Element> par_owner)
:MessageImpl()
{
	m_owner = par_owner;
}

MessageImpl::MessageImpl(const MessageImpl & obj): MessageImpl()
{
	*this = obj;
}

MessageImpl& MessageImpl::operator=(const MessageImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Message 
	 * which is generated by the compiler (as Message is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Message::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Message "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_messageKind = obj.getMessageKind();
	m_messageSort = obj.getMessageSort();

	//copy references with no containment (soft copy)
	m_connector  = obj.getConnector();
	m_interaction  = obj.getInteraction();
	m_receiveEvent  = obj.getReceiveEvent();
	m_sendEvent  = obj.getSendEvent();
	m_signature  = obj.getSignature();
	//Clone references with containment (deep copy)
	//clone reference 'argument'
	std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> argumentList = obj.getArgument();
	if(argumentList)
	{
		/*Subset*/
		m_argument.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getArgument()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ValueSpecification> argumentindexElem: *argumentList) 
		{
			std::shared_ptr<uml::ValueSpecification> temp = std::dynamic_pointer_cast<uml::ValueSpecification>((argumentindexElem)->copy());
			m_argument->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr argument."<< std::endl;)
	}
	/*Subset*/
	getArgument()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> MessageImpl::copy() const
{
	std::shared_ptr<MessageImpl> element(new MessageImpl());
	*element =(*this);
	element->setThisMessagePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool MessageImpl::arguments(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool MessageImpl::cannot_cross_boundaries(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

uml::MessageKind MessageImpl::getMessageKind()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool MessageImpl::occurrence_specifications(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool MessageImpl::sending_receiving_message_event(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool MessageImpl::signature_is_operation_reply(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool MessageImpl::signature_is_operation_request(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool MessageImpl::signature_is_signal(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool MessageImpl::signature_refer_to(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute messageKind */
uml::MessageKind MessageImpl::getMessageKind() const 
{
	return m_messageKind;
}

/* Getter & Setter for attribute messageSort */
uml::MessageSort MessageImpl::getMessageSort() const 
{
	return m_messageSort;
}
void MessageImpl::setMessageSort(uml::MessageSort _messageSort)
{
	m_messageSort = _messageSort;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference argument */
std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> MessageImpl::getArgument() const
{
	if(m_argument == nullptr)
	{
		/*Subset*/
		m_argument.reset(new Subset<uml::ValueSpecification, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getArgument()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_argument - Subset<uml::ValueSpecification, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_argument;
}

/* Getter & Setter for reference connector */
std::shared_ptr<uml::Connector> MessageImpl::getConnector() const
{
    return m_connector;
}
void MessageImpl::setConnector(std::shared_ptr<uml::Connector> _connector)
{
    m_connector = _connector;
	
}

/* Getter & Setter for reference interaction */
std::weak_ptr<uml::Interaction> MessageImpl::getInteraction() const
{
    return m_interaction;
}
void MessageImpl::setInteraction(std::weak_ptr<uml::Interaction> _interaction)
{
    m_interaction = _interaction;
	
}

/* Getter & Setter for reference receiveEvent */
std::shared_ptr<uml::MessageEnd> MessageImpl::getReceiveEvent() const
{
    return m_receiveEvent;
}
void MessageImpl::setReceiveEvent(std::shared_ptr<uml::MessageEnd> _receiveEvent)
{
    m_receiveEvent = _receiveEvent;
	
}

/* Getter & Setter for reference sendEvent */
std::shared_ptr<uml::MessageEnd> MessageImpl::getSendEvent() const
{
    return m_sendEvent;
}
void MessageImpl::setSendEvent(std::shared_ptr<uml::MessageEnd> _sendEvent)
{
    m_sendEvent = _sendEvent;
	
}

/* Getter & Setter for reference signature */
std::shared_ptr<uml::NamedElement> MessageImpl::getSignature() const
{
    return m_signature;
}
void MessageImpl::setSignature(std::shared_ptr<uml::NamedElement> _signature)
{
    m_signature = _signature;
	
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> MessageImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> MessageImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> MessageImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> MessageImpl::eContainer() const
{
	if(auto wp = m_interaction.lock())
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

//*********************************
// Persistence Functions
//*********************************
void MessageImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void MessageImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("messageSort");
		if ( iter != attr_list.end() )
		{
			uml::MessageSort value = uml::MessageSort::SYNCHCALL;
			std::string literal = iter->second;
						if (literal == "synchCall")
			{
				value = uml::MessageSort::SYNCHCALL;
			}
			else 			if (literal == "asynchCall")
			{
				value = uml::MessageSort::ASYNCHCALL;
			}
			else 			if (literal == "asynchSignal")
			{
				value = uml::MessageSort::ASYNCHSIGNAL;
			}
			else 			if (literal == "createMessage")
			{
				value = uml::MessageSort::CREATEMESSAGE;
			}
			else 			if (literal == "deleteMessage")
			{
				value = uml::MessageSort::DELETEMESSAGE;
			}
			else 			if (literal == "reply")
			{
				value = uml::MessageSort::REPLY;
			}
			this->setMessageSort(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("connector");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("connector")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("receiveEvent");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("receiveEvent")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("sendEvent");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("sendEvent")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("signature");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("signature")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void MessageImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("argument") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ValueSpecification>(this->getArgument());  

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

void MessageImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::MESSAGE_ATTRIBUTE_CONNECTOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Connector> _connector = std::dynamic_pointer_cast<uml::Connector>( references.front() );
				setConnector(_connector);
			}
			
			return;
		}

		case uml::umlPackage::MESSAGE_ATTRIBUTE_INTERACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interaction> _interaction = std::dynamic_pointer_cast<uml::Interaction>( references.front() );
				setInteraction(_interaction);
			}
			
			return;
		}

		case uml::umlPackage::MESSAGE_ATTRIBUTE_RECEIVEEVENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::MessageEnd> _receiveEvent = std::dynamic_pointer_cast<uml::MessageEnd>( references.front() );
				setReceiveEvent(_receiveEvent);
			}
			
			return;
		}

		case uml::umlPackage::MESSAGE_ATTRIBUTE_SENDEVENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::MessageEnd> _sendEvent = std::dynamic_pointer_cast<uml::MessageEnd>( references.front() );
				setSendEvent(_sendEvent);
			}
			
			return;
		}

		case uml::umlPackage::MESSAGE_ATTRIBUTE_SIGNATURE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::NamedElement> _signature = std::dynamic_pointer_cast<uml::NamedElement>( references.front() );
				setSignature(_signature);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void MessageImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void MessageImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'argument'
		for (std::shared_ptr<uml::ValueSpecification> argument : *this->getArgument()) 
		{
			saveHandler->addReference(argument, "argument", argument->eClass() != package->getValueSpecification_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getMessage_Attribute_messageSort()) )
		{
			uml::MessageSort value = this->getMessageSort();
			std::string literal = "";
			if (value == uml::MessageSort::SYNCHCALL)
			{
				literal = "synchCall";
			}
			else if (value == uml::MessageSort::ASYNCHCALL)
			{
				literal = "asynchCall";
			}
			else if (value == uml::MessageSort::ASYNCHSIGNAL)
			{
				literal = "asynchSignal";
			}
			else if (value == uml::MessageSort::CREATEMESSAGE)
			{
				literal = "createMessage";
			}
			else if (value == uml::MessageSort::DELETEMESSAGE)
			{
				literal = "deleteMessage";
			}
			else if (value == uml::MessageSort::REPLY)
			{
				literal = "reply";
			}
			saveHandler->addAttribute("messageSort", literal);
		}
	// Add references
		saveHandler->addReference(this->getConnector(), "connector", getConnector()->eClass() != uml::umlPackage::eInstance()->getConnector_Class()); 
		saveHandler->addReference(this->getReceiveEvent(), "receiveEvent", getReceiveEvent()->eClass() != uml::umlPackage::eInstance()->getMessageEnd_Class()); 
		saveHandler->addReference(this->getSendEvent(), "sendEvent", getSendEvent()->eClass() != uml::umlPackage::eInstance()->getMessageEnd_Class()); 
		saveHandler->addReference(this->getSignature(), "signature", getSignature()->eClass() != uml::umlPackage::eInstance()->getNamedElement_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> MessageImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getMessage_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any MessageImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::MESSAGE_ATTRIBUTE_ARGUMENT:
		{
			return eAnyBag(getArgument(),uml::umlPackage::VALUESPECIFICATION_CLASS); //1479
		}
		case uml::umlPackage::MESSAGE_ATTRIBUTE_CONNECTOR:
		{
			std::shared_ptr<ecore::EObject> returnValue=getConnector();
			return eAny(returnValue,uml::umlPackage::CONNECTOR_CLASS,false); //14710
		}
		case uml::umlPackage::MESSAGE_ATTRIBUTE_INTERACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getInteraction().lock();
			return eAny(returnValue,uml::umlPackage::INTERACTION_CLASS,false); //14711
		}
		case uml::umlPackage::MESSAGE_ATTRIBUTE_MESSAGEKIND:
			return eAny(getMessageKind(),uml::umlPackage::MESSAGEKIND_CLASS,false); //14712
		case uml::umlPackage::MESSAGE_ATTRIBUTE_MESSAGESORT:
			return eAny(getMessageSort(),uml::umlPackage::MESSAGESORT_CLASS,false); //14713
		case uml::umlPackage::MESSAGE_ATTRIBUTE_RECEIVEEVENT:
		{
			std::shared_ptr<ecore::EObject> returnValue=getReceiveEvent();
			return eAny(returnValue,uml::umlPackage::MESSAGEEND_CLASS,false); //14714
		}
		case uml::umlPackage::MESSAGE_ATTRIBUTE_SENDEVENT:
		{
			std::shared_ptr<ecore::EObject> returnValue=getSendEvent();
			return eAny(returnValue,uml::umlPackage::MESSAGEEND_CLASS,false); //14715
		}
		case uml::umlPackage::MESSAGE_ATTRIBUTE_SIGNATURE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getSignature();
			return eAny(returnValue,uml::umlPackage::NAMEDELEMENT_CLASS,false); //14716
		}
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}

bool MessageImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::MESSAGE_ATTRIBUTE_ARGUMENT:
			return getArgument() != nullptr; //1479
		case uml::umlPackage::MESSAGE_ATTRIBUTE_CONNECTOR:
			return getConnector() != nullptr; //14710
		case uml::umlPackage::MESSAGE_ATTRIBUTE_INTERACTION:
			return getInteraction().lock() != nullptr; //14711
		case uml::umlPackage::MESSAGE_ATTRIBUTE_MESSAGEKIND:
			return m_messageKind != uml::MessageKind::UNKNOWN;; //14712
		case uml::umlPackage::MESSAGE_ATTRIBUTE_MESSAGESORT:
			return m_messageSort != uml::MessageSort::SYNCHCALL;; //14713
		case uml::umlPackage::MESSAGE_ATTRIBUTE_RECEIVEEVENT:
			return getReceiveEvent() != nullptr; //14714
		case uml::umlPackage::MESSAGE_ATTRIBUTE_SENDEVENT:
			return getSendEvent() != nullptr; //14715
		case uml::umlPackage::MESSAGE_ATTRIBUTE_SIGNATURE:
			return getSignature() != nullptr; //14716
	}
	return NamedElementImpl::internalEIsSet(featureID);
}

bool MessageImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::MESSAGE_ATTRIBUTE_ARGUMENT:
		{
			// CAST Any to Bag<uml::ValueSpecification>
			if((newValue->isContainer()) && (uml::umlPackage::VALUESPECIFICATION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ValueSpecification>> argumentList= newValue->get<std::shared_ptr<Bag<uml::ValueSpecification>>>();
					std::shared_ptr<Bag<uml::ValueSpecification>> _argument=getArgument();
					for(const std::shared_ptr<uml::ValueSpecification> indexArgument: *_argument)
					{
						if (argumentList->find(indexArgument) == -1)
						{
							_argument->erase(indexArgument);
						}
					}

					for(const std::shared_ptr<uml::ValueSpecification> indexArgument: *argumentList)
					{
						if (_argument->find(indexArgument) == -1)
						{
							_argument->add(indexArgument);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::MESSAGE_ATTRIBUTE_CONNECTOR:
		{
			// CAST Any to uml::Connector
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Connector> _connector = std::dynamic_pointer_cast<uml::Connector>(_temp);
			setConnector(_connector); //14710
			return true;
		}
		case uml::umlPackage::MESSAGE_ATTRIBUTE_INTERACTION:
		{
			// CAST Any to uml::Interaction
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Interaction> _interaction = std::dynamic_pointer_cast<uml::Interaction>(_temp);
			setInteraction(_interaction); //14711
			return true;
		}
		case uml::umlPackage::MESSAGE_ATTRIBUTE_MESSAGESORT:
		{
			// CAST Any to uml::MessageSort
			uml::MessageSort _messageSort = newValue->get<uml::MessageSort>();
			setMessageSort(_messageSort); //14713
			return true;
		}
		case uml::umlPackage::MESSAGE_ATTRIBUTE_RECEIVEEVENT:
		{
			// CAST Any to uml::MessageEnd
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::MessageEnd> _receiveEvent = std::dynamic_pointer_cast<uml::MessageEnd>(_temp);
			setReceiveEvent(_receiveEvent); //14714
			return true;
		}
		case uml::umlPackage::MESSAGE_ATTRIBUTE_SENDEVENT:
		{
			// CAST Any to uml::MessageEnd
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::MessageEnd> _sendEvent = std::dynamic_pointer_cast<uml::MessageEnd>(_temp);
			setSendEvent(_sendEvent); //14715
			return true;
		}
		case uml::umlPackage::MESSAGE_ATTRIBUTE_SIGNATURE:
		{
			// CAST Any to uml::NamedElement
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::NamedElement> _signature = std::dynamic_pointer_cast<uml::NamedElement>(_temp);
			setSignature(_signature); //14716
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any MessageImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::Message::arguments(Any, std::map) : bool: 1899252778
		case umlPackage::MESSAGE_OPERATION_ARGUMENTS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->arguments(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Message::cannot_cross_boundaries(Any, std::map) : bool: 558087146
		case umlPackage::MESSAGE_OPERATION_CANNOT_CROSS_BOUNDARIES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->cannot_cross_boundaries(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Message::getMessageKind() : uml::MessageKind: 1841698888
		case umlPackage::MESSAGE_OPERATION_GETMESSAGEKIND:
		{
			result = eAny(this->getMessageKind(),0,false);
			break;
		}
		// uml::Message::occurrence_specifications(Any, std::map) : bool: 794631385
		case umlPackage::MESSAGE_OPERATION_OCCURRENCE_SPECIFICATIONS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->occurrence_specifications(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Message::sending_receiving_message_event(Any, std::map) : bool: 1304019371
		case umlPackage::MESSAGE_OPERATION_SENDING_RECEIVING_MESSAGE_EVENT_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->sending_receiving_message_event(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Message::signature_is_operation_reply(Any, std::map) : bool: 1755211186
		case umlPackage::MESSAGE_OPERATION_SIGNATURE_IS_OPERATION_REPLY_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->signature_is_operation_reply(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Message::signature_is_operation_request(Any, std::map) : bool: 555346418
		case umlPackage::MESSAGE_OPERATION_SIGNATURE_IS_OPERATION_REQUEST_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->signature_is_operation_request(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Message::signature_is_signal(Any, std::map) : bool: 295075675
		case umlPackage::MESSAGE_OPERATION_SIGNATURE_IS_SIGNAL_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->signature_is_signal(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Message::signature_refer_to(Any, std::map) : bool: 1691024653
		case umlPackage::MESSAGE_OPERATION_SIGNATURE_REFER_TO_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->signature_refer_to(incoming_param_diagnostics,incoming_param_context),0,false);
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

std::shared_ptr<uml::Message> MessageImpl::getThisMessagePtr() const
{
	return m_thisMessagePtr.lock();
}
void MessageImpl::setThisMessagePtr(std::weak_ptr<uml::Message> thisMessagePtr)
{
	m_thisMessagePtr = thisMessagePtr;
	setThisNamedElementPtr(thisMessagePtr);
}

