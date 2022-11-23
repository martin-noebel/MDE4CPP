#include "fUML/Semantics/Activities/impl/ActivitiesPackageImpl.hpp"

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
#include "uml/umlPackage.hpp"
//include subpackages 
 
using namespace fUML::Semantics::Activities;

void ActivitiesPackageImpl::createPackageContents(std::shared_ptr<ecore::EPackage> package)
{
	if (isCreated) 
	{
		return;
	}
	isCreated = true;

	std::shared_ptr<ecore::ecoreFactory> factory = ecore::ecoreFactory::eInstance();

	createActivityEdgeInstanceContent(package, factory);
	createActivityExecutionContent(package, factory);
	createActivityFinalNodeActivationContent(package, factory);
	createActivityNodeActivationContent(package, factory);
	createActivityNodeActivationGroupContent(package, factory);
	createActivityParameterNodeActivationContent(package, factory);
	createCentralBufferNodeActivationContent(package, factory);
	createControlNodeActivationContent(package, factory);
	createControlTokenContent(package, factory);
	createDataStoreNodeActivationContent(package, factory);
	createDecisionNodeActivationContent(package, factory);
	createFlowFinalNodeActivationContent(package, factory);
	createForkNodeActivationContent(package, factory);
	createForkedTokenContent(package, factory);
	createInitialNodeActivationContent(package, factory);
	createJoinNodeActivationContent(package, factory);
	createMergeNodeActivationContent(package, factory);
	createObjectNodeActivationContent(package, factory);
	createObjectTokenContent(package, factory);
	createOfferContent(package, factory);
	createTokenContent(package, factory);
	createTokenSetContent(package, factory);

	createPackageEDataTypes(package, factory);

}

void ActivitiesPackageImpl::createActivityEdgeInstanceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activityEdgeInstance_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITYEDGEINSTANCE_CLASS);
	
	m_activityEdgeInstance_Attribute_edge = factory->createEReference_as_eReferences_in_EClass(m_activityEdgeInstance_Class, ACTIVITYEDGEINSTANCE_ATTRIBUTE_EDGE);
	m_activityEdgeInstance_Attribute_group = factory->createEReference_as_eReferences_in_EClass(m_activityEdgeInstance_Class, ACTIVITYEDGEINSTANCE_ATTRIBUTE_GROUP);
	m_activityEdgeInstance_Attribute_offers = factory->createEReference_as_eReferences_in_EClass(m_activityEdgeInstance_Class, ACTIVITYEDGEINSTANCE_ATTRIBUTE_OFFERS);
	m_activityEdgeInstance_Attribute_source = factory->createEReference_as_eReferences_in_EClass(m_activityEdgeInstance_Class, ACTIVITYEDGEINSTANCE_ATTRIBUTE_SOURCE);
	m_activityEdgeInstance_Attribute_target = factory->createEReference_as_eReferences_in_EClass(m_activityEdgeInstance_Class, ACTIVITYEDGEINSTANCE_ATTRIBUTE_TARGET);
	
	m_activityEdgeInstance_Operation_countOfferedValue = factory->createEOperation_as_eOperations_in_EClass(m_activityEdgeInstance_Class, ACTIVITYEDGEINSTANCE_OPERATION_COUNTOFFEREDVALUE);
	m_activityEdgeInstance_Operation_getOfferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_activityEdgeInstance_Class, ACTIVITYEDGEINSTANCE_OPERATION_GETOFFEREDTOKENS);
	m_activityEdgeInstance_Operation_hasOffer = factory->createEOperation_as_eOperations_in_EClass(m_activityEdgeInstance_Class, ACTIVITYEDGEINSTANCE_OPERATION_HASOFFER);
	m_activityEdgeInstance_Operation_sendOffer_Token = factory->createEOperation_as_eOperations_in_EClass(m_activityEdgeInstance_Class, ACTIVITYEDGEINSTANCE_OPERATION_SENDOFFER_TOKEN);
	m_activityEdgeInstance_Operation_takeOfferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_activityEdgeInstance_Class, ACTIVITYEDGEINSTANCE_OPERATION_TAKEOFFEREDTOKENS);
	m_activityEdgeInstance_Operation_takeOfferedTokens_EInt = factory->createEOperation_as_eOperations_in_EClass(m_activityEdgeInstance_Class, ACTIVITYEDGEINSTANCE_OPERATION_TAKEOFFEREDTOKENS_EINT);
	
}

void ActivitiesPackageImpl::createActivityExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activityExecution_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITYEXECUTION_CLASS);
	
	m_activityExecution_Attribute_activationGroup = factory->createEReference_as_eReferences_in_EClass(m_activityExecution_Class, ACTIVITYEXECUTION_ATTRIBUTE_ACTIVATIONGROUP);
	m_activityExecution_Attribute_activity = factory->createEReference_as_eReferences_in_EClass(m_activityExecution_Class, ACTIVITYEXECUTION_ATTRIBUTE_ACTIVITY);
	
	m_activityExecution_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_activityExecution_Class, ACTIVITYEXECUTION_OPERATION__COPY);
	m_activityExecution_Operation_execute = factory->createEOperation_as_eOperations_in_EClass(m_activityExecution_Class, ACTIVITYEXECUTION_OPERATION_EXECUTE);
	m_activityExecution_Operation_execute_new = factory->createEOperation_as_eOperations_in_EClass(m_activityExecution_Class, ACTIVITYEXECUTION_OPERATION_EXECUTE_NEW);
	m_activityExecution_Operation_new_ = factory->createEOperation_as_eOperations_in_EClass(m_activityExecution_Class, ACTIVITYEXECUTION_OPERATION_NEW_);
	m_activityExecution_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_activityExecution_Class, ACTIVITYEXECUTION_OPERATION_TERMINATE);
	
}

void ActivitiesPackageImpl::createActivityFinalNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activityFinalNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITYFINALNODEACTIVATION_CLASS);
	
	
	m_activityFinalNodeActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_activityFinalNodeActivation_Class, ACTIVITYFINALNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
}

void ActivitiesPackageImpl::createActivityNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activityNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITYNODEACTIVATION_CLASS);
	m_activityNodeActivation_Attribute_running = factory->createEAttribute_as_eAttributes_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_ATTRIBUTE_RUNNING);
	
	m_activityNodeActivation_Attribute_group = factory->createEReference_as_eReferences_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_ATTRIBUTE_GROUP);
	m_activityNodeActivation_Attribute_heldTokens = factory->createEReference_as_eReferences_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_ATTRIBUTE_HELDTOKENS);
	m_activityNodeActivation_Attribute_incomingEdges = factory->createEReference_as_eReferences_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_ATTRIBUTE_INCOMINGEDGES);
	m_activityNodeActivation_Attribute_node = factory->createEReference_as_eReferences_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_ATTRIBUTE_NODE);
	m_activityNodeActivation_Attribute_outgoingEdges = factory->createEReference_as_eReferences_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_ATTRIBUTE_OUTGOINGEDGES);
	
	m_activityNodeActivation_Operation_addIncomingEdge_ActivityEdgeInstance = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_ADDINCOMINGEDGE_ACTIVITYEDGEINSTANCE);
	m_activityNodeActivation_Operation_addOutgoingEdge_ActivityEdgeInstance = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_ADDOUTGOINGEDGE_ACTIVITYEDGEINSTANCE);
	m_activityNodeActivation_Operation_addToken_Token = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_ADDTOKEN_TOKEN);
	m_activityNodeActivation_Operation_addTokens_Token = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_ADDTOKENS_TOKEN);
	m_activityNodeActivation_Operation_clearTokens = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_CLEARTOKENS);
	m_activityNodeActivation_Operation_createEdgeInstances = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_CREATEEDGEINSTANCES);
	m_activityNodeActivation_Operation_createNodeActivations = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_CREATENODEACTIVATIONS);
	m_activityNodeActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_FIRE_TOKEN);
	m_activityNodeActivation_Operation_getActivityExecution = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_GETACTIVITYEXECUTION);
	m_activityNodeActivation_Operation_getExecutionContext = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_GETEXECUTIONCONTEXT);
	m_activityNodeActivation_Operation_getExecutionLocus = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_GETEXECUTIONLOCUS);
	m_activityNodeActivation_Operation_getNodeActivation_ActivityNode = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	m_activityNodeActivation_Operation_getRunning = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_GETRUNNING);
	m_activityNodeActivation_Operation_getTokens = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_GETTOKENS);
	m_activityNodeActivation_Operation_isReady = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_ISREADY);
	m_activityNodeActivation_Operation_isSourceFor_ActivityEdgeInstance = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_ISSOURCEFOR_ACTIVITYEDGEINSTANCE);
	m_activityNodeActivation_Operation_receiveOffer = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_RECEIVEOFFER);
	m_activityNodeActivation_Operation_removeToken_Token = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_REMOVETOKEN_TOKEN);
	m_activityNodeActivation_Operation_resume = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_RESUME);
	m_activityNodeActivation_Operation_run = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_RUN);
	m_activityNodeActivation_Operation_sendOffers_Token = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_SENDOFFERS_TOKEN);
	m_activityNodeActivation_Operation_suspend = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_SUSPEND);
	m_activityNodeActivation_Operation_takeOfferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	m_activityNodeActivation_Operation_takeTokens = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_TAKETOKENS);
	m_activityNodeActivation_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivation_Class, ACTIVITYNODEACTIVATION_OPERATION_TERMINATE);
	
}

void ActivitiesPackageImpl::createActivityNodeActivationGroupContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activityNodeActivationGroup_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITYNODEACTIVATIONGROUP_CLASS);
	
	m_activityNodeActivationGroup_Attribute_activityExecution = factory->createEReference_as_eReferences_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_ACTIVITYEXECUTION);
	m_activityNodeActivationGroup_Attribute_containingNodeActivation = factory->createEReference_as_eReferences_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_CONTAININGNODEACTIVATION);
	m_activityNodeActivationGroup_Attribute_edgeInstances = factory->createEReference_as_eReferences_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_EDGEINSTANCES);
	m_activityNodeActivationGroup_Attribute_nodeActivations = factory->createEReference_as_eReferences_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_NODEACTIVATIONS);
	m_activityNodeActivationGroup_Attribute_suspendedActivations = factory->createEReference_as_eReferences_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_ATTRIBUTE_SUSPENDEDACTIVATIONS);
	
	m_activityNodeActivationGroup_Operation_activate_ActivityNode_ActivityEdge = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_ACTIVATE_ACTIVITYNODE_ACTIVITYEDGE);
	m_activityNodeActivationGroup_Operation_addEdgeInstance_ActivityEdgeInstance = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_ADDEDGEINSTANCE_ACTIVITYEDGEINSTANCE);
	m_activityNodeActivationGroup_Operation_addNodeActivation_ActivityNodeActivation = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_ADDNODEACTIVATION_ACTIVITYNODEACTIVATION);
	m_activityNodeActivationGroup_Operation_checkIncomingEdges_ActivityEdgeInstance_ActivityNodeActivation = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_CHECKINCOMINGEDGES_ACTIVITYEDGEINSTANCE_ACTIVITYNODEACTIVATION);
	m_activityNodeActivationGroup_Operation_createEdgeInstance_ActivityEdge = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_CREATEEDGEINSTANCE_ACTIVITYEDGE);
	m_activityNodeActivationGroup_Operation_createNodeActivation_ActivityNode = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_CREATENODEACTIVATION_ACTIVITYNODE);
	m_activityNodeActivationGroup_Operation_createNodeActivations_ActivityNode = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_CREATENODEACTIVATIONS_ACTIVITYNODE);
	m_activityNodeActivationGroup_Operation_getNodeActivation_ActivityNode = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_GETNODEACTIVATION_ACTIVITYNODE);
	m_activityNodeActivationGroup_Operation_getOutputParameterNodeActivations = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_GETOUTPUTPARAMETERNODEACTIVATIONS);
	m_activityNodeActivationGroup_Operation_hasSourceFor_ActivityEdgeInstance = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_HASSOURCEFOR_ACTIVITYEDGEINSTANCE);
	m_activityNodeActivationGroup_Operation_isSuspended = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_ISSUSPENDED);
	m_activityNodeActivationGroup_Operation_resume_ActivityNodeActivation = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_RESUME_ACTIVITYNODEACTIVATION);
	m_activityNodeActivationGroup_Operation_retrieveActivityExecution = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_RETRIEVEACTIVITYEXECUTION);
	m_activityNodeActivationGroup_Operation_run_ActivityNodeActivation = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_RUN_ACTIVITYNODEACTIVATION);
	m_activityNodeActivationGroup_Operation_runNodes_ActivityNode = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_RUNNODES_ACTIVITYNODE);
	m_activityNodeActivationGroup_Operation_suspend_ActivityNodeActivation = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_SUSPEND_ACTIVITYNODEACTIVATION);
	m_activityNodeActivationGroup_Operation_terminateAll = factory->createEOperation_as_eOperations_in_EClass(m_activityNodeActivationGroup_Class, ACTIVITYNODEACTIVATIONGROUP_OPERATION_TERMINATEALL);
	
}

void ActivitiesPackageImpl::createActivityParameterNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_activityParameterNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, ACTIVITYPARAMETERNODEACTIVATION_CLASS);
	
	
	m_activityParameterNodeActivation_Operation_clearTokens = factory->createEOperation_as_eOperations_in_EClass(m_activityParameterNodeActivation_Class, ACTIVITYPARAMETERNODEACTIVATION_OPERATION_CLEARTOKENS);
	m_activityParameterNodeActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_activityParameterNodeActivation_Class, ACTIVITYPARAMETERNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
}

void ActivitiesPackageImpl::createCentralBufferNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_centralBufferNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CENTRALBUFFERNODEACTIVATION_CLASS);
	
	
	m_centralBufferNodeActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_centralBufferNodeActivation_Class, CENTRALBUFFERNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
}

void ActivitiesPackageImpl::createControlNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_controlNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONTROLNODEACTIVATION_CLASS);
	
	
	m_controlNodeActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_controlNodeActivation_Class, CONTROLNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
}

void ActivitiesPackageImpl::createControlTokenContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_controlToken_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, CONTROLTOKEN_CLASS);
	
	
	m_controlToken_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_controlToken_Class, CONTROLTOKEN_OPERATION__COPY);
	m_controlToken_Operation_equals_Token = factory->createEOperation_as_eOperations_in_EClass(m_controlToken_Class, CONTROLTOKEN_OPERATION_EQUALS_TOKEN);
	m_controlToken_Operation_isControl = factory->createEOperation_as_eOperations_in_EClass(m_controlToken_Class, CONTROLTOKEN_OPERATION_ISCONTROL);
	
}

void ActivitiesPackageImpl::createDataStoreNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_dataStoreNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DATASTORENODEACTIVATION_CLASS);
	
	
	m_dataStoreNodeActivation_Operation_addToken_Token = factory->createEOperation_as_eOperations_in_EClass(m_dataStoreNodeActivation_Class, DATASTORENODEACTIVATION_OPERATION_ADDTOKEN_TOKEN);
	m_dataStoreNodeActivation_Operation_removeToken_Token = factory->createEOperation_as_eOperations_in_EClass(m_dataStoreNodeActivation_Class, DATASTORENODEACTIVATION_OPERATION_REMOVETOKEN_TOKEN);
	
}

void ActivitiesPackageImpl::createDecisionNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_decisionNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, DECISIONNODEACTIVATION_CLASS);
	
	m_decisionNodeActivation_Attribute_decisionNode = factory->createEReference_as_eReferences_in_EClass(m_decisionNodeActivation_Class, DECISIONNODEACTIVATION_ATTRIBUTE_DECISIONNODE);
	
	m_decisionNodeActivation_Operation_executeDecisionInputBehavior_EJavaObject_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_decisionNodeActivation_Class, DECISIONNODEACTIVATION_OPERATION_EXECUTEDECISIONINPUTBEHAVIOR_EJAVAOBJECT_EJAVAOBJECT);
	m_decisionNodeActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_decisionNodeActivation_Class, DECISIONNODEACTIVATION_OPERATION_FIRE_TOKEN);
	m_decisionNodeActivation_Operation_getDecisionInputFlowInstance = factory->createEOperation_as_eOperations_in_EClass(m_decisionNodeActivation_Class, DECISIONNODEACTIVATION_OPERATION_GETDECISIONINPUTFLOWINSTANCE);
	m_decisionNodeActivation_Operation_getDecisionInputFlowValue = factory->createEOperation_as_eOperations_in_EClass(m_decisionNodeActivation_Class, DECISIONNODEACTIVATION_OPERATION_GETDECISIONINPUTFLOWVALUE);
	m_decisionNodeActivation_Operation_getDecisionValues_Token = factory->createEOperation_as_eOperations_in_EClass(m_decisionNodeActivation_Class, DECISIONNODEACTIVATION_OPERATION_GETDECISIONVALUES_TOKEN);
	m_decisionNodeActivation_Operation_hasObjectFlowInput = factory->createEOperation_as_eOperations_in_EClass(m_decisionNodeActivation_Class, DECISIONNODEACTIVATION_OPERATION_HASOBJECTFLOWINPUT);
	m_decisionNodeActivation_Operation_isReady = factory->createEOperation_as_eOperations_in_EClass(m_decisionNodeActivation_Class, DECISIONNODEACTIVATION_OPERATION_ISREADY);
	m_decisionNodeActivation_Operation_removeJoinedControlTokens_Token = factory->createEOperation_as_eOperations_in_EClass(m_decisionNodeActivation_Class, DECISIONNODEACTIVATION_OPERATION_REMOVEJOINEDCONTROLTOKENS_TOKEN);
	m_decisionNodeActivation_Operation_takeOfferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_decisionNodeActivation_Class, DECISIONNODEACTIVATION_OPERATION_TAKEOFFEREDTOKENS);
	m_decisionNodeActivation_Operation_test_ValueSpecification_EJavaObject = factory->createEOperation_as_eOperations_in_EClass(m_decisionNodeActivation_Class, DECISIONNODEACTIVATION_OPERATION_TEST_VALUESPECIFICATION_EJAVAOBJECT);
	
}

void ActivitiesPackageImpl::createFlowFinalNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_flowFinalNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FLOWFINALNODEACTIVATION_CLASS);
	
	
	
}

void ActivitiesPackageImpl::createForkNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_forkNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FORKNODEACTIVATION_CLASS);
	
	
	m_forkNodeActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_forkNodeActivation_Class, FORKNODEACTIVATION_OPERATION_FIRE_TOKEN);
	m_forkNodeActivation_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_forkNodeActivation_Class, FORKNODEACTIVATION_OPERATION_TERMINATE);
	
}

void ActivitiesPackageImpl::createForkedTokenContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_forkedToken_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, FORKEDTOKEN_CLASS);
	m_forkedToken_Attribute_baseTokenIsWithdrawn = factory->createEAttribute_as_eAttributes_in_EClass(m_forkedToken_Class, FORKEDTOKEN_ATTRIBUTE_BASETOKENISWITHDRAWN);
	m_forkedToken_Attribute_remainingOffersCount = factory->createEAttribute_as_eAttributes_in_EClass(m_forkedToken_Class, FORKEDTOKEN_ATTRIBUTE_REMAININGOFFERSCOUNT);
	
	m_forkedToken_Attribute_baseToken = factory->createEReference_as_eReferences_in_EClass(m_forkedToken_Class, FORKEDTOKEN_ATTRIBUTE_BASETOKEN);
	
	m_forkedToken_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_forkedToken_Class, FORKEDTOKEN_OPERATION__COPY);
	m_forkedToken_Operation_equals_Token = factory->createEOperation_as_eOperations_in_EClass(m_forkedToken_Class, FORKEDTOKEN_OPERATION_EQUALS_TOKEN);
	m_forkedToken_Operation_getValue = factory->createEOperation_as_eOperations_in_EClass(m_forkedToken_Class, FORKEDTOKEN_OPERATION_GETVALUE);
	m_forkedToken_Operation_isControl = factory->createEOperation_as_eOperations_in_EClass(m_forkedToken_Class, FORKEDTOKEN_OPERATION_ISCONTROL);
	m_forkedToken_Operation_withdraw = factory->createEOperation_as_eOperations_in_EClass(m_forkedToken_Class, FORKEDTOKEN_OPERATION_WITHDRAW);
	
}

void ActivitiesPackageImpl::createInitialNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_initialNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, INITIALNODEACTIVATION_CLASS);
	
	
	m_initialNodeActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_initialNodeActivation_Class, INITIALNODEACTIVATION_OPERATION_FIRE_TOKEN);
	
}

void ActivitiesPackageImpl::createJoinNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_joinNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, JOINNODEACTIVATION_CLASS);
	
	
	m_joinNodeActivation_Operation_fire_Token = factory->createEOperation_as_eOperations_in_EClass(m_joinNodeActivation_Class, JOINNODEACTIVATION_OPERATION_FIRE_TOKEN);
	m_joinNodeActivation_Operation_isReady = factory->createEOperation_as_eOperations_in_EClass(m_joinNodeActivation_Class, JOINNODEACTIVATION_OPERATION_ISREADY);
	
}

void ActivitiesPackageImpl::createMergeNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_mergeNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, MERGENODEACTIVATION_CLASS);
	
	
	
}

void ActivitiesPackageImpl::createObjectNodeActivationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_objectNodeActivation_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OBJECTNODEACTIVATION_CLASS);
	m_objectNodeActivation_Attribute_offeredTokenCount = factory->createEAttribute_as_eAttributes_in_EClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_ATTRIBUTE_OFFEREDTOKENCOUNT);
	
	
	m_objectNodeActivation_Operation_addToken_Token = factory->createEOperation_as_eOperations_in_EClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_ADDTOKEN_TOKEN);
	m_objectNodeActivation_Operation_clearTokens = factory->createEOperation_as_eOperations_in_EClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_CLEARTOKENS);
	m_objectNodeActivation_Operation_countOfferedValues = factory->createEOperation_as_eOperations_in_EClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_COUNTOFFEREDVALUES);
	m_objectNodeActivation_Operation_countUnofferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_COUNTUNOFFEREDTOKENS);
	m_objectNodeActivation_Operation_getUnofferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_GETUNOFFEREDTOKENS);
	m_objectNodeActivation_Operation_removeToken_Token = factory->createEOperation_as_eOperations_in_EClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_REMOVETOKEN_TOKEN);
	m_objectNodeActivation_Operation_run = factory->createEOperation_as_eOperations_in_EClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_RUN);
	m_objectNodeActivation_Operation_sendOffers_Token = factory->createEOperation_as_eOperations_in_EClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_SENDOFFERS_TOKEN);
	m_objectNodeActivation_Operation_sendUnofferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_SENDUNOFFEREDTOKENS);
	m_objectNodeActivation_Operation_takeUnofferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_TAKEUNOFFEREDTOKENS);
	m_objectNodeActivation_Operation_terminate = factory->createEOperation_as_eOperations_in_EClass(m_objectNodeActivation_Class, OBJECTNODEACTIVATION_OPERATION_TERMINATE);
	
}

void ActivitiesPackageImpl::createObjectTokenContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_objectToken_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OBJECTTOKEN_CLASS);
	m_objectToken_Attribute_value = factory->createEAttribute_as_eAttributes_in_EClass(m_objectToken_Class, OBJECTTOKEN_ATTRIBUTE_VALUE);
	
	
	m_objectToken_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_objectToken_Class, OBJECTTOKEN_OPERATION__COPY);
	m_objectToken_Operation_equals_Token = factory->createEOperation_as_eOperations_in_EClass(m_objectToken_Class, OBJECTTOKEN_OPERATION_EQUALS_TOKEN);
	m_objectToken_Operation_isControl = factory->createEOperation_as_eOperations_in_EClass(m_objectToken_Class, OBJECTTOKEN_OPERATION_ISCONTROL);
	
}

void ActivitiesPackageImpl::createOfferContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_offer_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, OFFER_CLASS);
	
	m_offer_Attribute_offeredTokens = factory->createEReference_as_eReferences_in_EClass(m_offer_Class, OFFER_ATTRIBUTE_OFFEREDTOKENS);
	
	m_offer_Operation_countOfferedVales = factory->createEOperation_as_eOperations_in_EClass(m_offer_Class, OFFER_OPERATION_COUNTOFFEREDVALES);
	m_offer_Operation_hasTokens = factory->createEOperation_as_eOperations_in_EClass(m_offer_Class, OFFER_OPERATION_HASTOKENS);
	m_offer_Operation_removeOfferedValues_EInt = factory->createEOperation_as_eOperations_in_EClass(m_offer_Class, OFFER_OPERATION_REMOVEOFFEREDVALUES_EINT);
	m_offer_Operation_removeWithdrawnTokens = factory->createEOperation_as_eOperations_in_EClass(m_offer_Class, OFFER_OPERATION_REMOVEWITHDRAWNTOKENS);
	m_offer_Operation_retrieveOfferedTokens = factory->createEOperation_as_eOperations_in_EClass(m_offer_Class, OFFER_OPERATION_RETRIEVEOFFEREDTOKENS);
	
}

void ActivitiesPackageImpl::createTokenContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_token_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TOKEN_CLASS);
	m_token_Attribute_withdrawn = factory->createEAttribute_as_eAttributes_in_EClass(m_token_Class, TOKEN_ATTRIBUTE_WITHDRAWN);
	
	m_token_Attribute_holder = factory->createEReference_as_eReferences_in_EClass(m_token_Class, TOKEN_ATTRIBUTE_HOLDER);
	
	m_token_Operation__copy = factory->createEOperation_as_eOperations_in_EClass(m_token_Class, TOKEN_OPERATION__COPY);
	m_token_Operation_equals_Token = factory->createEOperation_as_eOperations_in_EClass(m_token_Class, TOKEN_OPERATION_EQUALS_TOKEN);
	m_token_Operation_getValue = factory->createEOperation_as_eOperations_in_EClass(m_token_Class, TOKEN_OPERATION_GETVALUE);
	m_token_Operation_isControl = factory->createEOperation_as_eOperations_in_EClass(m_token_Class, TOKEN_OPERATION_ISCONTROL);
	m_token_Operation_transfer_ActivityNodeActivation = factory->createEOperation_as_eOperations_in_EClass(m_token_Class, TOKEN_OPERATION_TRANSFER_ACTIVITYNODEACTIVATION);
	m_token_Operation_withdraw = factory->createEOperation_as_eOperations_in_EClass(m_token_Class, TOKEN_OPERATION_WITHDRAW);
	
}

void ActivitiesPackageImpl::createTokenSetContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	m_tokenSet_Class = factory->createEClass_as_eClassifiers_in_EPackage(package, TOKENSET_CLASS);
	
	m_tokenSet_Attribute_tokens = factory->createEReference_as_eReferences_in_EClass(m_tokenSet_Class, TOKENSET_ATTRIBUTE_TOKENS);
	
	
}

void ActivitiesPackageImpl::createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory)
{
	
}
