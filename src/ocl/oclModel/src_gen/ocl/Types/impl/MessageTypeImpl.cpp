#include "ocl/Types/impl/MessageTypeImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlFactory.hpp"


#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/ETypeParameter.hpp"
#include "uml/Signal.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Types/TypesPackage.hpp"
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Types;

//*********************************
// Constructor / Destructor
//*********************************
MessageTypeImpl::MessageTypeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

MessageTypeImpl::~MessageTypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete MessageType "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
MessageTypeImpl::MessageTypeImpl(std::weak_ptr<ecore::EPackage> par_ePackage)
:MessageTypeImpl()
{
	m_ePackage = par_ePackage;
}

MessageTypeImpl::MessageTypeImpl(const MessageTypeImpl & obj): MessageTypeImpl()
{
	*this = obj;
}

MessageTypeImpl& MessageTypeImpl::operator=(const MessageTypeImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EClassifierImpl::operator=(obj);
	MessageType::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy MessageType "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_referredOperation  = obj.getReferredOperation();
	m_referredSignal  = obj.getReferredSignal();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> MessageTypeImpl::copy() const
{
	std::shared_ptr<MessageTypeImpl> element(new MessageTypeImpl());
	*element =(*this);
	element->setThisMessageTypePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> MessageTypeImpl::eStaticClass() const
{
	return ocl::Types::TypesPackage::eInstance()->getMessageType_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference referredOperation
*/
std::shared_ptr<ecore::EOperation> MessageTypeImpl::getReferredOperation() const
{

    return m_referredOperation;
}
void MessageTypeImpl::setReferredOperation(std::shared_ptr<ecore::EOperation> _referredOperation)
{
    m_referredOperation = _referredOperation;
}


/*
Getter & Setter for reference referredSignal
*/
std::shared_ptr<uml::Signal> MessageTypeImpl::getReferredSignal() const
{

    return m_referredSignal;
}
void MessageTypeImpl::setReferredSignal(std::shared_ptr<uml::Signal> _referredSignal)
{
    m_referredSignal = _referredSignal;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<MessageType> MessageTypeImpl::getThisMessageTypePtr() const
{
	return m_thisMessageTypePtr.lock();
}
void MessageTypeImpl::setThisMessageTypePtr(std::weak_ptr<MessageType> thisMessageTypePtr)
{
	m_thisMessageTypePtr = thisMessageTypePtr;
	setThisEClassifierPtr(thisMessageTypePtr);
}
std::shared_ptr<ecore::EObject> MessageTypeImpl::eContainer() const
{
	if(auto wp = m_ePackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any MessageTypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Types::TypesPackage::MESSAGETYPE_ATTRIBUTE_REFERREDOPERATION:
			return eAny(getReferredOperation()); //498
		case ocl::Types::TypesPackage::MESSAGETYPE_ATTRIBUTE_REFERREDSIGNAL:
			return eAny(getReferredSignal()); //499
	}
	return ecore::EClassifierImpl::eGet(featureID, resolve, coreType);
}
bool MessageTypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Types::TypesPackage::MESSAGETYPE_ATTRIBUTE_REFERREDOPERATION:
			return getReferredOperation() != nullptr; //498
		case ocl::Types::TypesPackage::MESSAGETYPE_ATTRIBUTE_REFERREDSIGNAL:
			return getReferredSignal() != nullptr; //499
	}
	return ecore::EClassifierImpl::internalEIsSet(featureID);
}
bool MessageTypeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Types::TypesPackage::MESSAGETYPE_ATTRIBUTE_REFERREDOPERATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EOperation> _referredOperation = std::dynamic_pointer_cast<ecore::EOperation>(_temp);
			setReferredOperation(_referredOperation); //498
			return true;
		}
		case ocl::Types::TypesPackage::MESSAGETYPE_ATTRIBUTE_REFERREDSIGNAL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Signal> _referredSignal = std::dynamic_pointer_cast<uml::Signal>(_temp);
			setReferredSignal(_referredSignal); //499
			return true;
		}
	}

	return ecore::EClassifierImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void MessageTypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get oclFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void MessageTypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("referredOperation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("referredOperation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("referredSignal");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("referredSignal")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EClassifierImpl::loadAttributes(loadHandler, attr_list);
}

void MessageTypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ecore::EClassifierImpl::loadNode(nodeName, loadHandler);
}

void MessageTypeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Types::TypesPackage::MESSAGETYPE_ATTRIBUTE_REFERREDOPERATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EOperation> _referredOperation = std::dynamic_pointer_cast<ecore::EOperation>( references.front() );
				setReferredOperation(_referredOperation);
			}
			
			return;
		}

		case ocl::Types::TypesPackage::MESSAGETYPE_ATTRIBUTE_REFERREDSIGNAL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Signal> _referredSignal = std::dynamic_pointer_cast<uml::Signal>( references.front() );
				setReferredSignal(_referredSignal);
			}
			
			return;
		}
	}
	ecore::EClassifierImpl::resolveReferences(featureID, references);
}

void MessageTypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EClassifierImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void MessageTypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Types::TypesPackage> package = ocl::Types::TypesPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getReferredOperation(),"referredOperation", getReferredOperation()->eClass() != ecore::ecorePackage::eInstance()->getEOperation_Class());
		saveHandler->addReference(this->getReferredSignal(), "referredSignal", getReferredSignal()->eClass() != uml::umlPackage::eInstance()->getSignal_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

