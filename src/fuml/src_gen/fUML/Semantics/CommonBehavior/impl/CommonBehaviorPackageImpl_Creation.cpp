#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorPackageImpl.hpp"

// metametamodel factory
#include "ecore/ecoreFactory.hpp"

#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
//metametamodel classes
#include "ecore/EStringToStringMapEntry.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EReference.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EOperation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/EDataType.hpp"

//depending model packages
#include "ecore/ecorePackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "types/typesPackage.hpp"
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::CommonBehavior;

void CommonBehaviorPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createCallEventBehaviorContent(package, factory);
	createCallEventExecutionContent(package, factory);
	createCallEventOccurrenceContent(package, factory);
	createClassifierBehaviorExecutionContent(package, factory);
	createClassifierBehaviorInvocationEventAccepterContent(package, factory);
	createEventAccepterContent(package, factory);
	createEventDispatchLoopContent(package, factory);
	createEventOccurrenceContent(package, factory);
	createExecutionContent(package, factory);
	createFIFOGetNextEventStrategyContent(package, factory);
	createGetNextEventStrategyContent(package, factory);
	createInvocationEventOccurrenceContent(package, factory);
	createObjectActivationContent(package, factory);
	createOpaqueBehaviorExecutionContent(package, factory);
	createParameterValueContent(package, factory);
	createSignalEventOccurrenceContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void CommonBehaviorPackageImpl::createCallEventBehaviorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callEventBehavior_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLEVENTBEHAVIOR_CLASS);
	
	m_callEventBehavior_Attribute_operation = factory->createEReference_as_eStructuralFeatures_in_EClass(m_callEventBehavior_Class, CALLEVENTBEHAVIOR_ATTRIBUTE_OPERATION);
	
	
}

void CommonBehaviorPackageImpl::createCallEventExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callEventExecution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLEVENTEXECUTION_CLASS);
	m_callEventExecution_Attribute_callerSuspended = factory->createEAttribute_as_eStructuralFeatures_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_ATTRIBUTE_CALLERSUSPENDED);
	
	
	m_callEventExecution_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION__COPY);
	m_callEventExecution_Operation_createEventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_CREATEEVENTOCCURRENCE);
	m_callEventExecution_Operation_execute = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_EXECUTE);
	m_callEventExecution_Operation_getInputParameterValues = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_GETINPUTPARAMETERVALUES);
	m_callEventExecution_Operation_getOperation = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_GETOPERATION);
	m_callEventExecution_Operation_isCallerSuspended = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_ISCALLERSUSPENDED);
	m_callEventExecution_Operation_makeCall = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_MAKECALL);
	m_callEventExecution_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_NEW_);
	m_callEventExecution_Operation_releaseCaller = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_RELEASECALLER);
	m_callEventExecution_Operation_setOutputParameterValues_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_SETOUTPUTPARAMETERVALUES_PARAMETERVALUE);
	m_callEventExecution_Operation_suspendCaller = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_SUSPENDCALLER);
	m_callEventExecution_Operation_wait_ = factory->createEOperation_as_eOperations_in_EClass(m_callEventExecution_Class, CALLEVENTEXECUTION_OPERATION_WAIT_);
	
}

void CommonBehaviorPackageImpl::createCallEventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_callEventOccurrence_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CALLEVENTOCCURRENCE_CLASS);
	
	m_callEventOccurrence_Attribute_execution = factory->createEReference_as_eStructuralFeatures_in_EClass(m_callEventOccurrence_Class, CALLEVENTOCCURRENCE_ATTRIBUTE_EXECUTION);
	
	m_callEventOccurrence_Operation_getOperation = factory->createEOperation_as_eOperations_in_EClass(m_callEventOccurrence_Class, CALLEVENTOCCURRENCE_OPERATION_GETOPERATION);
	m_callEventOccurrence_Operation_getParameterValues = factory->createEOperation_as_eOperations_in_EClass(m_callEventOccurrence_Class, CALLEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES);
	m_callEventOccurrence_Operation_match_Trigger = factory->createEOperation_as_eOperations_in_EClass(m_callEventOccurrence_Class, CALLEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	m_callEventOccurrence_Operation_releaseCaller = factory->createEOperation_as_eOperations_in_EClass(m_callEventOccurrence_Class, CALLEVENTOCCURRENCE_OPERATION_RELEASECALLER);
	m_callEventOccurrence_Operation_setOutputParameterValues_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_callEventOccurrence_Class, CALLEVENTOCCURRENCE_OPERATION_SETOUTPUTPARAMETERVALUES_PARAMETERVALUE);
	
}

void CommonBehaviorPackageImpl::createClassifierBehaviorExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_classifierBehaviorExecution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLASSIFIERBEHAVIOREXECUTION_CLASS);
	
	m_classifierBehaviorExecution_Attribute_classifier = factory->createEReference_as_eStructuralFeatures_in_EClass(m_classifierBehaviorExecution_Class, CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_CLASSIFIER);
	m_classifierBehaviorExecution_Attribute_execution = factory->createEReference_as_eStructuralFeatures_in_EClass(m_classifierBehaviorExecution_Class, CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_EXECUTION);
	m_classifierBehaviorExecution_Attribute_objectActivation = factory->createEReference_as_eStructuralFeatures_in_EClass(m_classifierBehaviorExecution_Class, CLASSIFIERBEHAVIOREXECUTION_ATTRIBUTE_OBJECTACTIVATION);
	
	m_classifierBehaviorExecution_Operation__startObjectBehavior = factory->createEOperation_as_eOperations_in_EClass(m_classifierBehaviorExecution_Class, CLASSIFIERBEHAVIOREXECUTION_OPERATION__STARTOBJECTBEHAVIOR);
	m_classifierBehaviorExecution_Operation_execute_Class_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_classifierBehaviorExecution_Class, CLASSIFIERBEHAVIOREXECUTION_OPERATION_EXECUTE_CLASS_PARAMETERVALUE);
	m_classifierBehaviorExecution_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_classifierBehaviorExecution_Class, CLASSIFIERBEHAVIOREXECUTION_OPERATION_TERMINATE);
	
}

void CommonBehaviorPackageImpl::createClassifierBehaviorInvocationEventAccepterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_classifierBehaviorInvocationEventAccepter_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS);
	
	m_classifierBehaviorInvocationEventAccepter_Attribute_classifier = factory->createEReference_as_eStructuralFeatures_in_EClass(m_classifierBehaviorInvocationEventAccepter_Class, CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_CLASSIFIER);
	m_classifierBehaviorInvocationEventAccepter_Attribute_execution = factory->createEReference_as_eStructuralFeatures_in_EClass(m_classifierBehaviorInvocationEventAccepter_Class, CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_EXECUTION);
	m_classifierBehaviorInvocationEventAccepter_Attribute_objectActivation = factory->createEReference_as_eStructuralFeatures_in_EClass(m_classifierBehaviorInvocationEventAccepter_Class, CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_ATTRIBUTE_OBJECTACTIVATION);
	
	m_classifierBehaviorInvocationEventAccepter_Operation_accept_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_classifierBehaviorInvocationEventAccepter_Class, CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_OPERATION_ACCEPT_EVENTOCCURRENCE);
	m_classifierBehaviorInvocationEventAccepter_Operation_match_EventOccurrence = factory->createEOperation_as_eOperations_in_EClass(m_classifierBehaviorInvocationEventAccepter_Class, CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_OPERATION_MATCH_EVENTOCCURRENCE);
	m_classifierBehaviorInvocationEventAccepter_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_classifierBehaviorInvocationEventAccepter_Class, CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_OPERATION_TERMINATE);
	
}

void CommonBehaviorPackageImpl::createEventAccepterContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eventAccepter_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EVENTACCEPTER_CLASS);
	
	
	m_eventAccepter_Operation_accept_SignalInstance = factory->createEOperation_as_eOperations_in_EClass(m_eventAccepter_Class, EVENTACCEPTER_OPERATION_ACCEPT_SIGNALINSTANCE);
	m_eventAccepter_Operation_match_SignalInstance = factory->createEOperation_as_eOperations_in_EClass(m_eventAccepter_Class, EVENTACCEPTER_OPERATION_MATCH_SIGNALINSTANCE);
	
}

void CommonBehaviorPackageImpl::createEventDispatchLoopContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eventDispatchLoop_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EVENTDISPATCHLOOP_CLASS);
	
	
	
}

void CommonBehaviorPackageImpl::createEventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_eventOccurrence_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EVENTOCCURRENCE_CLASS);
	
	m_eventOccurrence_Attribute_target = factory->createEReference_as_eStructuralFeatures_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_ATTRIBUTE_TARGET);
	
	m_eventOccurrence_Operation_doSend = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_DOSEND);
	m_eventOccurrence_Operation_getParameterValues = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES);
	m_eventOccurrence_Operation_match_Trigger = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	m_eventOccurrence_Operation_matchAny_Trigger = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_MATCHANY_TRIGGER);
	m_eventOccurrence_Operation_sendTo_Reference = factory->createEOperation_as_eOperations_in_EClass(m_eventOccurrence_Class, EVENTOCCURRENCE_OPERATION_SENDTO_REFERENCE);
	
}

void CommonBehaviorPackageImpl::createExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_execution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, EXECUTION_CLASS);
	
	m_execution_Attribute_behavior = factory->createEReference_as_eStructuralFeatures_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_BEHAVIOR);
	m_execution_Attribute_context = factory->createEReference_as_eStructuralFeatures_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_CONTEXT);
	m_execution_Attribute_parameterValues = factory->createEReference_as_eStructuralFeatures_in_EClass(m_execution_Class, EXECUTION_ATTRIBUTE_PARAMETERVALUES);
	
	m_execution_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION__COPY);
	m_execution_Operation_execute = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_EXECUTE);
	m_execution_Operation_getOutputParameterValues = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_GETOUTPUTPARAMETERVALUES);
	m_execution_Operation_getParameterValue_Parameter = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_GETPARAMETERVALUE_PARAMETER);
	m_execution_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_NEW_);
	m_execution_Operation_setParameterValue_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_SETPARAMETERVALUE_PARAMETERVALUE);
	m_execution_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_execution_Class, EXECUTION_OPERATION_TERMINATE);
	
}

void CommonBehaviorPackageImpl::createFIFOGetNextEventStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_fIFOGetNextEventStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FIFOGETNEXTEVENTSTRATEGY_CLASS);
	
	
	
}

void CommonBehaviorPackageImpl::createGetNextEventStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_getNextEventStrategy_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, GETNEXTEVENTSTRATEGY_CLASS);
	
	
	m_getNextEventStrategy_Operation_getName = factory->createEOperation_as_eOperations_in_EClass(m_getNextEventStrategy_Class, GETNEXTEVENTSTRATEGY_OPERATION_GETNAME);
	m_getNextEventStrategy_Operation_retrieveNextEvent_ObjectActivation = factory->createEOperation_as_eOperations_in_EClass(m_getNextEventStrategy_Class, GETNEXTEVENTSTRATEGY_OPERATION_RETRIEVENEXTEVENT_OBJECTACTIVATION);
	
}

void CommonBehaviorPackageImpl::createInvocationEventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_invocationEventOccurrence_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INVOCATIONEVENTOCCURRENCE_CLASS);
	
	m_invocationEventOccurrence_Attribute_execution = factory->createEReference_as_eStructuralFeatures_in_EClass(m_invocationEventOccurrence_Class, INVOCATIONEVENTOCCURRENCE_ATTRIBUTE_EXECUTION);
	
	m_invocationEventOccurrence_Operation_getParameterValues = factory->createEOperation_as_eOperations_in_EClass(m_invocationEventOccurrence_Class, INVOCATIONEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES);
	m_invocationEventOccurrence_Operation_match_Trigger = factory->createEOperation_as_eOperations_in_EClass(m_invocationEventOccurrence_Class, INVOCATIONEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	
}

void CommonBehaviorPackageImpl::createObjectActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_objectActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OBJECTACTIVATION_CLASS);
	
	m_objectActivation_Attribute_classifierBehaviorExecutions = factory->createEReference_as_eStructuralFeatures_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_ATTRIBUTE_CLASSIFIERBEHAVIOREXECUTIONS);
	m_objectActivation_Attribute_eventPool = factory->createEReference_as_eStructuralFeatures_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_ATTRIBUTE_EVENTPOOL);
	m_objectActivation_Attribute_object = factory->createEReference_as_eStructuralFeatures_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_ATTRIBUTE_OBJECT);
	m_objectActivation_Attribute_waitingEventAccepters = factory->createEReference_as_eStructuralFeatures_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_ATTRIBUTE_WAITINGEVENTACCEPTERS);
	
	m_objectActivation_Operation__register_EventAccepter = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION__REGISTER_EVENTACCEPTER);
	m_objectActivation_Operation__send_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION__SEND_EJAVAOBJECT);
	m_objectActivation_Operation__startObjectBehavior = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION__STARTOBJECTBEHAVIOR);
	m_objectActivation_Operation_dispatchNextEvent = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_DISPATCHNEXTEVENT);
	m_objectActivation_Operation_retrieveNextEvent = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_RETRIEVENEXTEVENT);
	m_objectActivation_Operation_send_SignalInstance = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_SEND_SIGNALINSTANCE);
	m_objectActivation_Operation_startBehavior_Class_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE);
	m_objectActivation_Operation_stop = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_STOP);
	m_objectActivation_Operation_unregister_EventAccepter = factory->createEOperation_as_eOperations_in_EClass(m_objectActivation_Class, OBJECTACTIVATION_OPERATION_UNREGISTER_EVENTACCEPTER);
	
}

void CommonBehaviorPackageImpl::createOpaqueBehaviorExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_opaqueBehaviorExecution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OPAQUEBEHAVIOREXECUTION_CLASS);
	
	
	m_opaqueBehaviorExecution_Operation_doBody_ParameterValue_ParameterValue = factory->createEOperation_as_eOperations_in_EClass(m_opaqueBehaviorExecution_Class, OPAQUEBEHAVIOREXECUTION_OPERATION_DOBODY_PARAMETERVALUE_PARAMETERVALUE);
	m_opaqueBehaviorExecution_Operation_execute = factory->createEOperation_as_eOperations_in_EClass(m_opaqueBehaviorExecution_Class, OPAQUEBEHAVIOREXECUTION_OPERATION_EXECUTE);
	
}

void CommonBehaviorPackageImpl::createParameterValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_parameterValue_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, PARAMETERVALUE_CLASS);
	
	m_parameterValue_Attribute_parameter = factory->createEReference_as_eStructuralFeatures_in_EClass(m_parameterValue_Class, PARAMETERVALUE_ATTRIBUTE_PARAMETER);
	m_parameterValue_Attribute_values = factory->createEReference_as_eStructuralFeatures_in_EClass(m_parameterValue_Class, PARAMETERVALUE_ATTRIBUTE_VALUES);
	
	m_parameterValue_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_parameterValue_Class, PARAMETERVALUE_OPERATION__COPY);
	
}

void CommonBehaviorPackageImpl::createSignalEventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_signalEventOccurrence_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, SIGNALEVENTOCCURRENCE_CLASS);
	
	m_signalEventOccurrence_Attribute_signalInstance = factory->createEReference_as_eStructuralFeatures_in_EClass(m_signalEventOccurrence_Class, SIGNALEVENTOCCURRENCE_ATTRIBUTE_SIGNALINSTANCE);
	
	m_signalEventOccurrence_Operation_getParameterValues = factory->createEOperation_as_eOperations_in_EClass(m_signalEventOccurrence_Class, SIGNALEVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES);
	m_signalEventOccurrence_Operation_match_Trigger = factory->createEOperation_as_eOperations_in_EClass(m_signalEventOccurrence_Class, SIGNALEVENTOCCURRENCE_OPERATION_MATCH_TRIGGER);
	
}

void CommonBehaviorPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
