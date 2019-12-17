//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUMLFACTORYIMPL_HPP
#define FUMLFACTORYIMPL_HPP

#include "ecore/impl/EFactoryImpl.hpp"

#include "fUML/FUMLFactory.hpp"

namespace fUML 
{
}

namespace fUML 
{
	class FUMLFactoryImpl : virtual public ecore::EFactoryImpl , virtual public FUMLFactory 
	{
		private:    
			FUMLFactoryImpl(FUMLFactoryImpl const&) = delete;
			FUMLFactoryImpl& operator=(FUMLFactoryImpl const&) = delete;

		protected:
			friend class FUMLFactory;
			// Constructor
			FUMLFactoryImpl();

		public:
			virtual ~FUMLFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> createAcceptCallActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> createAcceptCallActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivations> createAcceptCallActionActivations(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> createAcceptEventActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> createAcceptEventActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> createAcceptEventActionEventAccepter(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> createActivityEdgeInstance(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> createActivityEdgeInstance_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> createActivityExecution(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> createActivityFinalNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> createActivityFinalNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> createActivityNodeActivationGroup(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> createActivityNodeActivationGroup_in_ActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution > par_activityExecution, const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> createActivityNodeActivationGroup_in_ContainingNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation > par_containingNodeActivation, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> createActivityParameterNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> createActivityParameterNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> createAddStructuralFeatureValueActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> createAddStructuralFeatureValueActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> createBooleanValue(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> createCallBehaviorActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> createCallBehaviorActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventBehavior> createCallEventBehavior(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> createCallEventExecution(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> createCallEventOccurrence(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> createCallOperationActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> createCallOperationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> createCentralBufferNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> createCentralBufferNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> createClassifierBehaviorExecution(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity> createClassifierBehaviorExecutionActivity(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorInvocationEventAccepter> createClassifierBehaviorInvocationEventAccepter(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> createClauseActivation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> createClearAssociationActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> createClearAssociationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> createClearStructuralFeatureActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> createClearStructuralFeatureActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> createConditionalNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> createConditionalNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ControlToken> createControlToken(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> createCreateLinkActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> createCreateLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> createCreateObjectActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> createCreateObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> createDataStoreNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> createDataStoreNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::DataValue> createDataValue(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> createDecisionNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> createDecisionNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> createDestroyLinkActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> createDestroyLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> createDestroyObjectActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> createDestroyObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategy> createDispatchStrategy(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::EnumerationValue> createEnumerationValue(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventDispatchLoop> createEventDispatchLoop(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> createEventOccurrence(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> createExecutionFactory(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> createExecutionFactory_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL1> createExecutionFactoryL1(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL1> createExecutionFactoryL1_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL2> createExecutionFactoryL2(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL2> createExecutionFactoryL2_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL3> createExecutionFactoryL3(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactoryL3> createExecutionFactoryL3_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Loci::Executor> createExecutor(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Loci::Executor> createExecutor_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> createExpansionActivationGroup(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> createExpansionActivationGroup_in_ActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution > par_activityExecution, const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> createExpansionActivationGroup_in_ContainingNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation > par_containingNodeActivation, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> createExpansionNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> createExpansionNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> createExpansionRegionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> createExpansionRegionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueList> createExtensionalValueList(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategy> createFIFOGetNextEventStrategy(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> createFeatureValue(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Loci::FirstChoiceStrategy> createFirstChoiceStrategy(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation> createFlowFinalNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation> createFlowFinalNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation> createForkNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation> createForkNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ForkedToken> createForkedToken(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation> createInitialNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation> createInitialNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Classification::InstanceValueEvaluation> createInstanceValueEvaluation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> createIntegerValue(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::InvocationEventOccurrence> createInvocationEventOccurrence(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> createJoinNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> createJoinNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> createLink(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Values::LiteralBooleanEvaluation> createLiteralBooleanEvaluation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Values::LiteralIntegerEvaluation> createLiteralIntegerEvaluation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Values::LiteralNullEvaluation> createLiteralNullEvaluation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Values::LiteralRealEvaluation> createLiteralRealEvaluation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Values::LiteralStringEvaluation> createLiteralStringEvaluation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluation> createLiteralUnlimitedNaturalEvaluation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Loci::Locus> createLocus(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> createLoopNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> createLoopNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation> createMergeNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation> createMergeNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> createObject(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> createObjectActivation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ObjectToken> createObjectToken(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::Offer> createOffer(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> createParameterValue(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> createReadExtentActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> createReadExtentActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> createReadIsClassifiedObjectActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> createReadIsClassifiedObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> createReadLinkActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> createReadLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> createReadSelfActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> createReadSelfActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> createReadStructuralFeatureActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> createReadStructuralFeatureActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::RealValue> createRealValue(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> createReclassifyObjectActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> createReclassifyObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategy> createRedefinitionBasedDispatchStrategy(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> createReduceActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> createReduceActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> createReference(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> createRemoveStructuralFeatureValueActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> createRemoveStructuralFeatureValueActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> createReplyActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> createReplyActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> createReturnInformation(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> createSendSignalActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> createSendSignalActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> createSignalEventOccurrence(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> createSignalInstance(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> createStartClassifierBehaviorActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> createStartClassifierBehaviorActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> createStartObjectBehaviorActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> createStartObjectBehaviorActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> createStringValue(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> createStructuredActivityNodeActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> createStructuredActivityNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> createTestIdentityActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> createTestIdentityActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::TokenSet> createTokenSet(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::UnlimitedNaturalValue> createUnlimitedNaturalValue(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> createValueSpecificationActionActivation(const int metaElementID=-1) const ;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> createValueSpecificationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group, const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::Values> createValues(const int metaElementID=-1) const ;
			
			

			//Package
			virtual std::shared_ptr<FUMLPackage> getFUMLPackage() const;

		private:
			static FUMLFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: FUMLFACTORYIMPL_HPP */
