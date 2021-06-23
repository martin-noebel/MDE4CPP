#include "fUML/Semantics/Actions/impl/InputPinActivationImpl.hpp"

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
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "uml/Pin.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/UmlFactory.hpp"


#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/Pin.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
InputPinActivationImpl::InputPinActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InputPinActivationImpl::~InputPinActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InputPinActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InputPinActivationImpl::InputPinActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:InputPinActivationImpl()
{
	m_group = par_group;
}

InputPinActivationImpl::InputPinActivationImpl(const InputPinActivationImpl & obj): InputPinActivationImpl()
{
	*this = obj;
}

InputPinActivationImpl& InputPinActivationImpl::operator=(const InputPinActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	PinActivationImpl::operator=(obj);
	InputPinActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InputPinActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> InputPinActivationImpl::copy() const
{
	std::shared_ptr<InputPinActivationImpl> element(new InputPinActivationImpl());
	*element =(*this);
	element->setThisInputPinActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InputPinActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getInputPinActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InputPinActivationImpl::isReady()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool ready = fUML::Semantics::Activities::ActivityNodeActivationImpl::isReady();
	if (getNode()->getName().find("self") == 0)
	{
		return true;
	}
	if (ready) 
	{
		int totalValueCount = this->countUnofferedTokens() + this->countOfferedValues();
		int minimum = getPin()->getLower();
		ready = (totalValueCount >= minimum);	
	}
	return ready;
	//end of body
}

void InputPinActivationImpl::receiveOffer()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	this->getActionActivation().lock()->receiveOffer();
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<InputPinActivation> InputPinActivationImpl::getThisInputPinActivationPtr() const
{
	return m_thisInputPinActivationPtr.lock();
}
void InputPinActivationImpl::setThisInputPinActivationPtr(std::weak_ptr<InputPinActivation> thisInputPinActivationPtr)
{
	m_thisInputPinActivationPtr = thisInputPinActivationPtr;
	setThisPinActivationPtr(thisInputPinActivationPtr);
}
std::shared_ptr<ecore::EObject> InputPinActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any InputPinActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return PinActivationImpl::eGet(featureID, resolve, coreType);
}
bool InputPinActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return PinActivationImpl::internalEIsSet(featureID);
}
bool InputPinActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return PinActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any InputPinActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 6250
		case ActionsPackage::INPUTPINACTIVATION_OPERATION_ISREADY:
		{
			result = eAny(this->isReady());
			break;
		}
		
		// 6249
		case ActionsPackage::INPUTPINACTIVATION_OPERATION_RECEIVEOFFER:
		{
			this->receiveOffer();
			break;
		}

		default:
		{
			// call superTypes
			result = PinActivationImpl::eInvoke(operationID, arguments);
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
void InputPinActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void InputPinActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PinActivationImpl::loadAttributes(loadHandler, attr_list);
}

void InputPinActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PinActivationImpl::loadNode(nodeName, loadHandler);
}

void InputPinActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	PinActivationImpl::resolveReferences(featureID, references);
}

void InputPinActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PinActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ObjectNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void InputPinActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

