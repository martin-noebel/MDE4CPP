
#include "fUML/Semantics/Actions/impl/CallBehaviorActionActivationImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/Semantics/Loci/Executor.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "uml/Behavior.hpp"
#include "uml/CallBehaviorAction.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterDirectionKind.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/Behavior.hpp"
#include "uml/CallAction.hpp"
#include "fUML/Semantics/Actions/CallActionActivation.hpp"
#include "uml/CallBehaviorAction.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CallBehaviorActionActivationImpl::CallBehaviorActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CallBehaviorActionActivationImpl::~CallBehaviorActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallBehaviorActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CallBehaviorActionActivationImpl::CallBehaviorActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CallBehaviorActionActivationImpl()
{
	m_group = par_group;
}

CallBehaviorActionActivationImpl::CallBehaviorActionActivationImpl(const CallBehaviorActionActivationImpl & obj): CallBehaviorActionActivationImpl()
{
	*this = obj;
}

CallBehaviorActionActivationImpl& CallBehaviorActionActivationImpl::operator=(const CallBehaviorActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	CallActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CallBehaviorActionActivation 
	 * which is generated by the compiler (as CallBehaviorActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CallBehaviorActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallBehaviorActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_callBehaviorAction  = obj.getCallBehaviorAction();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CallBehaviorActionActivationImpl::copy() const
{
	std::shared_ptr<CallBehaviorActionActivationImpl> element(new CallBehaviorActionActivationImpl());
	*element =(*this);
	element->setThisCallBehaviorActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> CallBehaviorActionActivationImpl::doCall(std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputParameterValues)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::Behavior> behavior = this->retrieveBehavior();

	if(behavior != nullptr)
	{
		std::shared_ptr<uml::Element> context = nullptr;
		if(behavior->getContext() != nullptr)
		{
			DEBUG_INFO("Behavior context is '" << behavior->getContext()->getName() << "'.")
			context = this->getExecutionContext();
		}
		
		return this->getExecutionLocus()->getExecutor()->execute(behavior, context, inputParameterValues);
	}
	return nullptr;

	//end of body
}



std::shared_ptr<uml::Behavior> CallBehaviorActionActivationImpl::retrieveBehavior() const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->getCallBehaviorAction()->getBehavior();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference callBehaviorAction */
std::shared_ptr<uml::CallBehaviorAction> CallBehaviorActionActivationImpl::getCallBehaviorAction() const
{
    return m_callBehaviorAction;
}
void CallBehaviorActionActivationImpl::setCallBehaviorAction(std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction)
{
    m_callBehaviorAction = _callBehaviorAction;
	//additional setter call for redefined reference CallActionActivation::callAction
	fUML::Semantics::Actions::CallActionActivationImpl::setCallAction(_callBehaviorAction);
}
/*Additional Setter for redefined reference 'CallActionActivation::callAction'*/
void CallBehaviorActionActivationImpl::setCallAction(std::shared_ptr<uml::CallAction> _callAction)
{
	std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>(_callAction);
	if(_callBehaviorAction)
	{
		m_callBehaviorAction = _callBehaviorAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setCallAction(_callBehaviorAction);
	}
	else
	{
		std::cerr<<"[CallBehaviorActionActivation::setCallAction] : Could not set callAction because provided callAction was not of type 'std::shared_ptr<uml::CallBehaviorAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActionActivation::action'*/
void CallBehaviorActionActivationImpl::setAction(std::shared_ptr<uml::Action> _action)
{
	std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>(_action);
	if(_callBehaviorAction)
	{
		m_callBehaviorAction = _callBehaviorAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setAction(_action);
	}
	else
	{
		std::cerr<<"[CallBehaviorActionActivation::setAction] : Could not set action because provided action was not of type 'std::shared_ptr<uml::CallBehaviorAction>'"<<std::endl;
	}
}
/*Additional Setter for redefined reference 'ActivityNodeActivation::node'*/
void CallBehaviorActionActivationImpl::setNode(std::shared_ptr<uml::ActivityNode> _node)
{
	std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>(_node);
	if(_callBehaviorAction)
	{
		m_callBehaviorAction = _callBehaviorAction;

		//additional setter call for redefined reference CallActionActivation::callAction
		fUML::Semantics::Actions::CallActionActivationImpl::setNode(_node);
	}
	else
	{
		std::cerr<<"[CallBehaviorActionActivation::setNode] : Could not set node because provided node was not of type 'std::shared_ptr<uml::CallBehaviorAction>'"<<std::endl;
	}
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CallBehaviorActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CallBehaviorActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CallBehaviorActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("callBehaviorAction");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("callBehaviorAction")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	CallActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CallBehaviorActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CallActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CallBehaviorActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLBEHAVIORACTIONACTIVATION_ATTRIBUTE_CALLBEHAVIORACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>( references.front() );
				setCallBehaviorAction(_callBehaviorAction);
			}
			
			return;
		}
	}
	CallActionActivationImpl::resolveReferences(featureID, references);
}

void CallBehaviorActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CallActionActivationImpl::saveContent(saveHandler);
	
	InvocationActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CallBehaviorActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getCallBehaviorAction(), "callBehaviorAction", getCallBehaviorAction()->eClass() != uml::umlPackage::eInstance()->getCallBehaviorAction_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CallBehaviorActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getCallBehaviorActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> CallBehaviorActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLBEHAVIORACTIONACTIVATION_ATTRIBUTE_CALLBEHAVIORACTION:
			return eAny(getCallBehaviorAction(),uml::umlPackage::CALLBEHAVIORACTION_CLASS,false); //1513
	}
	return CallActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool CallBehaviorActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLBEHAVIORACTIONACTIVATION_ATTRIBUTE_CALLBEHAVIORACTION:
			return getCallBehaviorAction() != nullptr; //1513
	}
	return CallActionActivationImpl::internalEIsSet(featureID);
}

bool CallBehaviorActionActivationImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::CALLBEHAVIORACTIONACTIVATION_ATTRIBUTE_CALLBEHAVIORACTION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::CallBehaviorAction> _callBehaviorAction = std::dynamic_pointer_cast<uml::CallBehaviorAction>(eObject);
					if(_callBehaviorAction)
					{
						setCallBehaviorAction(_callBehaviorAction); //1513
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'callBehaviorAction'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'callBehaviorAction'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return CallActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> CallBehaviorActionActivationImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::CallBehaviorActionActivation::doCall(fUML::Semantics::CommonBehavior::ParameterValue[*]) : fUML::Semantics::CommonBehavior::ParameterValue[*]: 2530900674
		case ActionsPackage::CALLBEHAVIORACTIONACTIVATION_OPERATION_DOCALL_PARAMETERVALUE:
		{
			//Retrieve input parameter 'inputParameterValues'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> incoming_param_inputParameterValues;
			Bag<Any>::const_iterator incoming_param_inputParameterValues_arguments_citer = std::next(arguments->begin(), 0);
			{
				std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>((*incoming_param_inputParameterValues_arguments_citer));
				if(ecoreContainerAny)
				{
					try
					{
						std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
				
						if(eObjectList)
						{
							incoming_param_inputParameterValues.reset();
							for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
							{
								std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> _temp = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ParameterValue>(anEObject);
								incoming_param_inputParameterValues->add(_temp);
							}
						}
					}
					catch(...)
					{
						DEBUG_ERROR("Invalid type stored in 'ecore::EcoreContainerAny' for parameter 'inputParameterValues'. Failed to invoke operation 'doCall'!")
						return nullptr;
					}
				}
				else
				{
					DEBUG_ERROR("Invalid instance of 'ecore::EcoreContainerAny' for parameter 'inputParameterValues'. Failed to invoke operation 'doCall'!")
					return nullptr;
				}
			}
		
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> resultList = this->doCall(incoming_param_inputParameterValues);
			return eEcoreContainerAny(resultList,fUML::Semantics::CommonBehavior::CommonBehaviorPackage::PARAMETERVALUE_CLASS);
			break;
		}
		// fUML::Semantics::Actions::CallBehaviorActionActivation::retrieveBehavior() : uml::Behavior {const}: 2035427474
		case ActionsPackage::CALLBEHAVIORACTIONACTIVATION_OPERATION_RETRIEVEBEHAVIOR:
		{
			result = eEcoreAny(this->retrieveBehavior(), uml::umlPackage::BEHAVIOR_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = CallActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> CallBehaviorActionActivationImpl::getThisCallBehaviorActionActivationPtr() const
{
	return m_thisCallBehaviorActionActivationPtr.lock();
}
void CallBehaviorActionActivationImpl::setThisCallBehaviorActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> thisCallBehaviorActionActivationPtr)
{
	m_thisCallBehaviorActionActivationPtr = thisCallBehaviorActionActivationPtr;
	setThisCallActionActivationPtr(thisCallBehaviorActionActivationPtr);
}


