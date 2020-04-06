//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGEIMPL_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGEIMPL_HPP

#include "ecore/EcorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp" 


namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_DefaultRequestPropagationStrategy;
	class CS_DispatchOperationOfInterfaceStrategy;
	class CS_InteractionPoint;
	class CS_Link;
	class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy;
	class CS_Object;
	class CS_Reference;
	class CS_RequestPropagationStrategy;
	class CS_StructuralFeatureOfInterfaceAccessStrategy;}

namespace ecore
{
	class EcoreFactory;
}

namespace PSCS::Semantics::StructuredClassifiers
{
	class StructuredClassifiersPackageImpl : public ecore::EPackageImpl ,virtual public StructuredClassifiersPackage
	{
		private:    
			StructuredClassifiersPackageImpl(StructuredClassifiersPackageImpl const&) = delete;
			StructuredClassifiersPackageImpl& operator=(StructuredClassifiersPackageImpl const&) = delete;

		protected:
			StructuredClassifiersPackageImpl();

		public:
			virtual ~StructuredClassifiersPackageImpl();

			// Begin Class CS_DefaultRequestPropagationStrategy
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_DefaultRequestPropagationStrategy_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor() const ;
			
			// End Class CS_DefaultRequestPropagationStrategy

			// Begin Class CS_DispatchOperationOfInterfaceStrategy
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_DispatchOperationOfInterfaceStrategy_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation() const ;
			
			// End Class CS_DispatchOperationOfInterfaceStrategy

			// Begin Class CS_InteractionPoint
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_InteractionPoint_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCS_InteractionPoint_Attribute_definingPort() const ;
			virtual std::shared_ptr<ecore::EReference> getCS_InteractionPoint_Attribute_owner() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getCS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_InteractionPoint_Operation_dispatch_Operation() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_InteractionPoint_Operation_send_EventOccurrence() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_InteractionPoint_Operation_startBehavior_Class_ParameterValue() const ;
			
			// End Class CS_InteractionPoint

			// Begin Class CS_Link
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_Link_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_Link_Operation_getFeature_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Link_Operation_hasValueForAFeature_Value() const ;
			
			// End Class CS_Link

			// Begin Class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt() const ;
			
			// End Class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy

			// Begin Class CS_Object
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_Object_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_checkAllParents_Classifier_Classifier() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_contains_Object() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_directlyContains_Object() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_dispatchIn_Operation_Port() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_dispatchOut_Operation_Port() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_getDirectContainers() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_getFeatureValue_StructuralFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_getLinks_CS_InteractionPoint() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_hasValueForAFeature_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_isDescendant_Interface_Interface() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_isOperationProvided_Reference_Operation() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_isOperationRequired_Reference_Operation() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_realizesInterface_Class_Interface() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_sendIn_EventOccurrence_Port() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_sendOut_EventOccurrence_Port() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Object_Operation_setFeatureValue_StructuralFeature_EInt() const ;
			
			// End Class CS_Object

			// Begin Class CS_Reference
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_Reference_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCS_Reference_Attribute_compositeReferent() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_copy() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_dispatchIn_Operation_Port() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_dispatchOut_Operation_Port() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_sendIn_EventOccurrence_Port() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_sendOut_EventOccurrence_Port() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint() const ;
			
			// End Class CS_Reference

			// Begin Class CS_RequestPropagationStrategy
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_RequestPropagationStrategy_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_RequestPropagationStrategy_Operation_getName() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor() const ;
			
			// End Class CS_RequestPropagationStrategy

			// Begin Class CS_StructuralFeatureOfInterfaceAccessStrategy
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_StructuralFeatureOfInterfaceAccessStrategy_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer() const ;
			
			// End Class CS_StructuralFeatureOfInterfaceAccessStrategy

			virtual std::shared_ptr<ecore::EEnum> getCS_LinkKind_Class() const ;
			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_cS_DefaultRequestPropagationStrategy_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_DispatchOperationOfInterfaceStrategy_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_InteractionPoint_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_Link_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_Object_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_Reference_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_RequestPropagationStrategy_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_StructuralFeatureOfInterfaceAccessStrategy_Class = nullptr;
			std::shared_ptr<ecore::EEnum> m_cS_LinkKind_Class = nullptr;
			
			std::shared_ptr<ecore::EReference> m_cS_Reference_Attribute_compositeReferent = nullptr;std::shared_ptr<ecore::EReference> m_cS_InteractionPoint_Attribute_definingPort = nullptr;std::shared_ptr<ecore::EReference> m_cS_InteractionPoint_Attribute_owner = nullptr;
			std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_checkAllParents_Classifier_Classifier = nullptr;std::shared_ptr<ecore::EOperation> m_cS_InteractionPoint_Operation_checkAllParents_Classifier_Classifier = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_contains_Object = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Reference_Operation_copy = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_directlyContains_Object = nullptr;std::shared_ptr<ecore::EOperation> m_cS_InteractionPoint_Operation_dispatch_Operation = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_dispatchIn_Operation_CS_InteractionPoint = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_dispatchIn_Operation_Port = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Reference_Operation_dispatchIn_Operation_CS_InteractionPoint = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Reference_Operation_dispatchIn_Operation_Port = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_dispatchOut_Operation_CS_InteractionPoint = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_dispatchOut_Operation_Port = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Reference_Operation_dispatchOut_Operation_Port = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Reference_Operation_dispatchOut_Operation_CS_InteractionPoint = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_getDirectContainers = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Link_Operation_getFeature_Value = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_getFeatureValue_StructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_getLinkKind_CS_Link_CS_InteractionPoint = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_getLinks_CS_InteractionPoint = nullptr;std::shared_ptr<ecore::EOperation> m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_getName = nullptr;std::shared_ptr<ecore::EOperation> m_cS_RequestPropagationStrategy_Operation_getName = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_hasValueForAFeature_Value = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Link_Operation_hasValueForAFeature_Value = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_isDescendant_Interface_Interface = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_isOperationProvided_Reference_Operation = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_isOperationRequired_Reference_Operation = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DispatchOperationOfInterfaceStrategy_Operation_operationsMatch_Operation_Operation = nullptr;std::shared_ptr<ecore::EOperation> m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_read_CS_Object_StructuralFeature = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_realizesInterface_Class_Interface = nullptr;std::shared_ptr<ecore::EOperation> m_cS_RequestPropagationStrategy_Operation_select_Reference_SemanticVisitor = nullptr;std::shared_ptr<ecore::EOperation> m_cS_DefaultRequestPropagationStrategy_Operation_select_Reference_SemanticVisitor = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_selectTargetsForDispatching_CS_Link_EBoolean = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_selectTargetsForSending_CS_Link_EBoolean = nullptr;std::shared_ptr<ecore::EOperation> m_cS_InteractionPoint_Operation_send_EventOccurrence = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_sendIn_EventOccurrence_CS_InteractionPoint = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_sendIn_EventOccurrence_Port = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Reference_Operation_sendIn_EventOccurrence_CS_InteractionPoint = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Reference_Operation_sendIn_EventOccurrence_Port = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_sendOut_EventOccurrence_CS_InteractionPoint = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_sendOut_EventOccurrence_Port = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Reference_Operation_sendOut_EventOccurrence_Port = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Reference_Operation_sendOut_EventOccurrence_CS_InteractionPoint = nullptr;std::shared_ptr<ecore::EOperation> m_cS_Object_Operation_setFeatureValue_StructuralFeature_EInt = nullptr;std::shared_ptr<ecore::EOperation> m_cS_InteractionPoint_Operation_startBehavior_Class_ParameterValue = nullptr;std::shared_ptr<ecore::EOperation> m_cS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_EInt = nullptr;std::shared_ptr<ecore::EOperation> m_cS_StructuralFeatureOfInterfaceAccessStrategy_Operation_write_CS_Object_Integer = nullptr;

			friend class StructuredClassifiersPackage;

			static bool isInited;
			static StructuredClassifiersPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createCS_DefaultRequestPropagationStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createCS_DispatchOperationOfInterfaceStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createCS_InteractionPointContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createCS_LinkContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createCS_ObjectContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createCS_ReferenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createCS_RequestPropagationStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createCS_StructuralFeatureOfInterfaceAccessStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);

			void initializeCS_DefaultRequestPropagationStrategyContent();
			void initializeCS_DispatchOperationOfInterfaceStrategyContent();
			void initializeCS_InteractionPointContent();
			void initializeCS_LinkContent();
			void initializeCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyContent();
			void initializeCS_ObjectContent();
			void initializeCS_ReferenceContent();
			void initializeCS_RequestPropagationStrategyContent();
			void initializeCS_StructuralFeatureOfInterfaceAccessStrategyContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSPACKAGEIMPL_HPP */