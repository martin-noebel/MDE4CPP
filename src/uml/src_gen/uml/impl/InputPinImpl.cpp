#include "uml/impl/InputPinImpl.hpp"

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

#include "uml/Action.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/AddStructuralFeatureValueAction.hpp"
#include "uml/Behavior.hpp"
#include "uml/CallOperationAction.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/DestroyObjectAction.hpp"
#include "uml/Element.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/InvocationAction.hpp"
#include "uml/Namespace.hpp"
#include "uml/Pin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "uml/State.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuralFeatureAction.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/WriteStructuralFeatureAction.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InputPinImpl::InputPinImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InputPinImpl::~InputPinImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InputPin "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::Action> par_action)
:InputPinImpl()
{
	m_action = par_action;
	m_owner = par_action;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::Activity> par_activity)
:InputPinImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::AddStructuralFeatureValueAction> par_addStructuralFeatureValueAction)
:InputPinImpl()
{
	m_addStructuralFeatureValueAction = par_addStructuralFeatureValueAction;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::CallOperationAction> par_callOperationAction)
:InputPinImpl()
{
	m_callOperationAction = par_callOperationAction;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::DestroyObjectAction> par_destroyObjectAction)
:InputPinImpl()
{
	m_destroyObjectAction = par_destroyObjectAction;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:InputPinImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::InvocationAction> par_invocationAction)
:InputPinImpl()
{
	m_invocationAction = par_invocationAction;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InputPinImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::Element> par_owner)
:InputPinImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::RemoveStructuralFeatureValueAction> par_removeStructuralFeatureValueAction)
:InputPinImpl()
{
	m_removeStructuralFeatureValueAction = par_removeStructuralFeatureValueAction;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::StructuralFeatureAction> par_structuralFeatureAction)
:InputPinImpl()
{
	m_structuralFeatureAction = par_structuralFeatureAction;
}

//Additional constructor for the containments back reference
InputPinImpl::InputPinImpl(std::weak_ptr<uml::WriteStructuralFeatureAction> par_writeStructuralFeatureAction)
:InputPinImpl()
{
	m_writeStructuralFeatureAction = par_writeStructuralFeatureAction;
}

InputPinImpl::InputPinImpl(const InputPinImpl & obj): InputPinImpl()
{
	*this = obj;
}

InputPinImpl& InputPinImpl::operator=(const InputPinImpl & obj)
{
	//call overloaded =Operator for each base class
	PinImpl::operator=(obj);
	InputPin::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InputPin "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_action  = obj.getAction();
	m_addStructuralFeatureValueAction  = obj.getAddStructuralFeatureValueAction();
	m_callOperationAction  = obj.getCallOperationAction();
	m_destroyObjectAction  = obj.getDestroyObjectAction();
	m_invocationAction  = obj.getInvocationAction();
	m_removeStructuralFeatureValueAction  = obj.getRemoveStructuralFeatureValueAction();
	m_structuralFeatureAction  = obj.getStructuralFeatureAction();
	m_writeStructuralFeatureAction  = obj.getWriteStructuralFeatureAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> InputPinImpl::copy() const
{
	std::shared_ptr<InputPinImpl> element(new InputPinImpl());
	*element =(*this);
	element->setThisInputPinPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InputPinImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInputPin_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InputPinImpl::outgoing_edges_structured_only(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference action
*/
std::weak_ptr<uml::Action> InputPinImpl::getAction() const
{

    return m_action;
}



/*
Getter & Setter for reference addStructuralFeatureValueAction
*/
std::weak_ptr<uml::AddStructuralFeatureValueAction> InputPinImpl::getAddStructuralFeatureValueAction() const
{

    return m_addStructuralFeatureValueAction;
}
void InputPinImpl::setAddStructuralFeatureValueAction(std::weak_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction)
{
    m_addStructuralFeatureValueAction = _addStructuralFeatureValueAction;
}


/*
Getter & Setter for reference callOperationAction
*/
std::weak_ptr<uml::CallOperationAction> InputPinImpl::getCallOperationAction() const
{

    return m_callOperationAction;
}
void InputPinImpl::setCallOperationAction(std::weak_ptr<uml::CallOperationAction> _callOperationAction)
{
    m_callOperationAction = _callOperationAction;
}


/*
Getter & Setter for reference destroyObjectAction
*/
std::weak_ptr<uml::DestroyObjectAction> InputPinImpl::getDestroyObjectAction() const
{

    return m_destroyObjectAction;
}
void InputPinImpl::setDestroyObjectAction(std::weak_ptr<uml::DestroyObjectAction> _destroyObjectAction)
{
    m_destroyObjectAction = _destroyObjectAction;
}


/*
Getter & Setter for reference invocationAction
*/
std::weak_ptr<uml::InvocationAction> InputPinImpl::getInvocationAction() const
{

    return m_invocationAction;
}
void InputPinImpl::setInvocationAction(std::weak_ptr<uml::InvocationAction> _invocationAction)
{
    m_invocationAction = _invocationAction;
}


/*
Getter & Setter for reference removeStructuralFeatureValueAction
*/
std::weak_ptr<uml::RemoveStructuralFeatureValueAction> InputPinImpl::getRemoveStructuralFeatureValueAction() const
{

    return m_removeStructuralFeatureValueAction;
}
void InputPinImpl::setRemoveStructuralFeatureValueAction(std::weak_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction)
{
    m_removeStructuralFeatureValueAction = _removeStructuralFeatureValueAction;
}


/*
Getter & Setter for reference structuralFeatureAction
*/
std::weak_ptr<uml::StructuralFeatureAction> InputPinImpl::getStructuralFeatureAction() const
{

    return m_structuralFeatureAction;
}
void InputPinImpl::setStructuralFeatureAction(std::weak_ptr<uml::StructuralFeatureAction> _structuralFeatureAction)
{
    m_structuralFeatureAction = _structuralFeatureAction;
}


/*
Getter & Setter for reference writeStructuralFeatureAction
*/
std::weak_ptr<uml::WriteStructuralFeatureAction> InputPinImpl::getWriteStructuralFeatureAction() const
{

    return m_writeStructuralFeatureAction;
}
void InputPinImpl::setWriteStructuralFeatureAction(std::weak_ptr<uml::WriteStructuralFeatureAction> _writeStructuralFeatureAction)
{
    m_writeStructuralFeatureAction = _writeStructuralFeatureAction;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> InputPinImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<Union<uml::Element>> InputPinImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> InputPinImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> InputPinImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<InputPin> InputPinImpl::getThisInputPinPtr() const
{
	return m_thisInputPinPtr.lock();
}
void InputPinImpl::setThisInputPinPtr(std::weak_ptr<InputPin> thisInputPinPtr)
{
	m_thisInputPinPtr = thisInputPinPtr;
	setThisPinPtr(thisInputPinPtr);
}
std::shared_ptr<ecore::EObject> InputPinImpl::eContainer() const
{
	if(auto wp = m_action.lock())
	{
		return wp;
	}

	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_addStructuralFeatureValueAction.lock())
	{
		return wp;
	}

	if(auto wp = m_callOperationAction.lock())
	{
		return wp;
	}

	if(auto wp = m_destroyObjectAction.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_invocationAction.lock())
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

	if(auto wp = m_removeStructuralFeatureValueAction.lock())
	{
		return wp;
	}

	if(auto wp = m_structuralFeatureAction.lock())
	{
		return wp;
	}

	if(auto wp = m_writeStructuralFeatureAction.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any InputPinImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_ACTION:
			return eAny(getAction().lock()); //11636
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
			return eAny(getAddStructuralFeatureValueAction().lock()); //11638
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION:
			return eAny(getCallOperationAction().lock()); //11634
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION:
			return eAny(getDestroyObjectAction().lock()); //11639
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_INVOCATIONACTION:
			return eAny(getInvocationAction().lock()); //11635
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
			return eAny(getRemoveStructuralFeatureValueAction().lock()); //11640
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION:
			return eAny(getStructuralFeatureAction().lock()); //11633
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
			return eAny(getWriteStructuralFeatureAction().lock()); //11637
	}
	return PinImpl::eGet(featureID, resolve, coreType);
}
bool InputPinImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_ACTION:
			return getAction().lock() != nullptr; //11636
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
			return getAddStructuralFeatureValueAction().lock() != nullptr; //11638
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION:
			return getCallOperationAction().lock() != nullptr; //11634
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION:
			return getDestroyObjectAction().lock() != nullptr; //11639
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_INVOCATIONACTION:
			return getInvocationAction().lock() != nullptr; //11635
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
			return getRemoveStructuralFeatureValueAction().lock() != nullptr; //11640
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION:
			return getStructuralFeatureAction().lock() != nullptr; //11633
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
			return getWriteStructuralFeatureAction().lock() != nullptr; //11637
	}
	return PinImpl::internalEIsSet(featureID);
}
bool InputPinImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>(_temp);
			setAddStructuralFeatureValueAction(_addStructuralFeatureValueAction); //11638
			return true;
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>(_temp);
			setCallOperationAction(_callOperationAction); //11634
			return true;
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction = std::dynamic_pointer_cast<uml::DestroyObjectAction>(_temp);
			setDestroyObjectAction(_destroyObjectAction); //11639
			return true;
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_INVOCATIONACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InvocationAction> _invocationAction = std::dynamic_pointer_cast<uml::InvocationAction>(_temp);
			setInvocationAction(_invocationAction); //11635
			return true;
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::RemoveStructuralFeatureValueAction>(_temp);
			setRemoveStructuralFeatureValueAction(_removeStructuralFeatureValueAction); //11640
			return true;
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StructuralFeatureAction> _structuralFeatureAction = std::dynamic_pointer_cast<uml::StructuralFeatureAction>(_temp);
			setStructuralFeatureAction(_structuralFeatureAction); //11633
			return true;
		}
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::WriteStructuralFeatureAction> _writeStructuralFeatureAction = std::dynamic_pointer_cast<uml::WriteStructuralFeatureAction>(_temp);
			setWriteStructuralFeatureAction(_writeStructuralFeatureAction); //11637
			return true;
		}
	}

	return PinImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void InputPinImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InputPinImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PinImpl::loadAttributes(loadHandler, attr_list);
}

void InputPinImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PinImpl::loadNode(nodeName, loadHandler);
}

void InputPinImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::INPUTPIN_ATTRIBUTE_ADDSTRUCTURALFEATUREVALUEACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::AddStructuralFeatureValueAction> _addStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::AddStructuralFeatureValueAction>( references.front() );
				setAddStructuralFeatureValueAction(_addStructuralFeatureValueAction);
			}
			
			return;
		}

		case uml::umlPackage::INPUTPIN_ATTRIBUTE_CALLOPERATIONACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CallOperationAction> _callOperationAction = std::dynamic_pointer_cast<uml::CallOperationAction>( references.front() );
				setCallOperationAction(_callOperationAction);
			}
			
			return;
		}

		case uml::umlPackage::INPUTPIN_ATTRIBUTE_DESTROYOBJECTACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DestroyObjectAction> _destroyObjectAction = std::dynamic_pointer_cast<uml::DestroyObjectAction>( references.front() );
				setDestroyObjectAction(_destroyObjectAction);
			}
			
			return;
		}

		case uml::umlPackage::INPUTPIN_ATTRIBUTE_INVOCATIONACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::InvocationAction> _invocationAction = std::dynamic_pointer_cast<uml::InvocationAction>( references.front() );
				setInvocationAction(_invocationAction);
			}
			
			return;
		}

		case uml::umlPackage::INPUTPIN_ATTRIBUTE_REMOVESTRUCTURALFEATUREVALUEACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::RemoveStructuralFeatureValueAction> _removeStructuralFeatureValueAction = std::dynamic_pointer_cast<uml::RemoveStructuralFeatureValueAction>( references.front() );
				setRemoveStructuralFeatureValueAction(_removeStructuralFeatureValueAction);
			}
			
			return;
		}

		case uml::umlPackage::INPUTPIN_ATTRIBUTE_STRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StructuralFeatureAction> _structuralFeatureAction = std::dynamic_pointer_cast<uml::StructuralFeatureAction>( references.front() );
				setStructuralFeatureAction(_structuralFeatureAction);
			}
			
			return;
		}

		case uml::umlPackage::INPUTPIN_ATTRIBUTE_WRITESTRUCTURALFEATUREACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::WriteStructuralFeatureAction> _writeStructuralFeatureAction = std::dynamic_pointer_cast<uml::WriteStructuralFeatureAction>( references.front() );
				setWriteStructuralFeatureAction(_writeStructuralFeatureAction);
			}
			
			return;
		}
	}
	PinImpl::resolveReferences(featureID, references);
}

void InputPinImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PinImpl::saveContent(saveHandler);
	
	MultiplicityElementImpl::saveContent(saveHandler);
	ObjectNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void InputPinImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

