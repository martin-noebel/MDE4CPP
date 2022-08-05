//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONSPACKAGE_HPP
#define PSCS_SEMANTICS_ACTIONSPACKAGE_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EAnnotation;
	class EOperation;
	class EDataType;
	class EStringToStringMapEntry;
	class EReference;
	class EParameter;
	class EGenericType;
	class EClass;
}

namespace PSCS::Semantics::Actions 
{
	class CS_AcceptCallActionActivation;
	class CS_AcceptEventActionActivation;
	class CS_AddStructuralFeatureValueActionActivation;
	class CS_CallOperationActionActivation;
	class CS_ClearStructuralFeatureActionActivation;
	class CS_ConstructStrategy;
	class CS_CreateLinkActionActivation;
	class CS_CreateObjectActionActivation;
	class CS_DefaultConstructStrategy;
	class CS_ReadExtentActionActivation;
	class CS_ReadSelfActionActivation;
	class CS_RemoveStructuralFeatureValueActionActivation;
	class CS_SendSignalActionActivation;}
 
namespace PSCS::Semantics::Actions 
{
	/*!
	The Metamodel Package for the Actions metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSCS_API ActionsPackage : virtual public ecore::EPackage 
	{
		private:    
			ActionsPackage(ActionsPackage const&) = delete;
			ActionsPackage& operator=(ActionsPackage const&) = delete;

		protected:
			ActionsPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class CS_AcceptCallActionActivation
			//Class and Feature IDs 
			static const unsigned long CS_ACCEPTCALLACTIONACTIVATION_CLASS = 465654510;
			static const unsigned int CS_ACCEPTCALLACTIONACTIVATION_CLASS_FEATURE_COUNT = 13;
			static const unsigned int CS_ACCEPTCALLACTIONACTIVATION_CLASS_OPERATION_COUNT = 57;
			
			
			static const unsigned int CS_ACCEPTCALLACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE = 2621330370;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_AcceptCallActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_AcceptCallActionActivation_Operation_accept_EventOccurrence() const = 0;
			
			// End Class CS_AcceptCallActionActivation

			// Begin Class CS_AcceptEventActionActivation
			//Class and Feature IDs 
			static const unsigned long CS_ACCEPTEVENTACTIONACTIVATION_CLASS = 967219298;
			static const unsigned int CS_ACCEPTEVENTACTIONACTIVATION_CLASS_FEATURE_COUNT = 13;
			static const unsigned int CS_ACCEPTEVENTACTIONACTIVATION_CLASS_OPERATION_COUNT = 56;
			
			
			static const unsigned int CS_ACCEPTEVENTACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE = 1744804804;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_AcceptEventActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_AcceptEventActionActivation_Operation_accept_EventOccurrence() const = 0;
			
			// End Class CS_AcceptEventActionActivation

			// Begin Class CS_AddStructuralFeatureValueActionActivation
			//Class and Feature IDs 
			static const unsigned long CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS = 666852493;
			static const unsigned int CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS_OPERATION_COUNT = 55;
			
			
			static const unsigned int CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION = 2459034463;
			static const unsigned int CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTIONDEFAULT = 572905456;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_AddStructuralFeatureValueActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_AddStructuralFeatureValueActionActivation_Operation_doAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault() const = 0;
			
			// End Class CS_AddStructuralFeatureValueActionActivation

			// Begin Class CS_CallOperationActionActivation
			//Class and Feature IDs 
			static const unsigned long CS_CALLOPERATIONACTIONACTIVATION_CLASS = 359462383;
			static const unsigned int CS_CALLOPERATIONACTIONACTIVATION_CLASS_FEATURE_COUNT = 14;
			static const unsigned int CS_CALLOPERATIONACTIONACTIVATION_CLASS_OPERATION_COUNT = 58;
			
			
			static const unsigned int CS_CALLOPERATIONACTIONACTIVATION_OPERATION__ISCREATE_OPERATION = 1345774800;
			static const unsigned int CS_CALLOPERATIONACTIONACTIVATION_OPERATION_DOACTION = 1729294133;
			static const unsigned int CS_CALLOPERATIONACTIONACTIVATION_OPERATION_GETCALLEXECUTION = 3811651158;
			static const unsigned int CS_CALLOPERATIONACTIONACTIVATION_OPERATION_ISCREATE_OPERATION = 2024874825;
			static const unsigned int CS_CALLOPERATIONACTIONACTIVATION_OPERATION_ISOPERATIONPROVIDED_PORT_OPERATION = 4192990466;
			static const unsigned int CS_CALLOPERATIONACTIONACTIVATION_OPERATION_ISOPERATIONREQUIRED_PORT_OPERATION = 2625896910;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_CallOperationActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_CallOperationActionActivation_Operation__isCreate_Operation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallOperationActionActivation_Operation_doAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallOperationActionActivation_Operation_getCallExecution() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallOperationActionActivation_Operation_isCreate_Operation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallOperationActionActivation_Operation_isOperationProvided_Port_Operation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallOperationActionActivation_Operation_isOperationRequired_Port_Operation() const = 0;
			
			// End Class CS_CallOperationActionActivation

			// Begin Class CS_ClearStructuralFeatureActionActivation
			//Class and Feature IDs 
			static const unsigned long CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS = 116608301;
			static const unsigned int CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS_OPERATION_COUNT = 55;
			
			
			static const unsigned int CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION = 1473569464;
			static const unsigned int CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETLINKSTODESTROY_STRUCTUREDVALUE_STRUCTURALFEATURE = 3586980415;
			static const unsigned int CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETPOTENTIALLINKENDS_CS_REFERENCE_STRUCTURALFEATURE = 4153851883;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ClearStructuralFeatureActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ClearStructuralFeatureActionActivation_Operation_doAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature() const = 0;
			
			// End Class CS_ClearStructuralFeatureActionActivation

			// Begin Class CS_ConstructStrategy
			//Class and Feature IDs 
			static const unsigned long CS_CONSTRUCTSTRATEGY_CLASS = 983698108;
			static const unsigned int CS_CONSTRUCTSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CS_CONSTRUCTSTRATEGY_CLASS_OPERATION_COUNT = 3;
			
			
			static const unsigned int CS_CONSTRUCTSTRATEGY_OPERATION_CONSTRUCT_OPERATION_CS_OBJECT = 1666096409;
			static const unsigned int CS_CONSTRUCTSTRATEGY_OPERATION_GETNAME = 753057332;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ConstructStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ConstructStrategy_Operation_construct_Operation_CS_Object() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_ConstructStrategy_Operation_getName() const = 0;
			
			// End Class CS_ConstructStrategy

			// Begin Class CS_CreateLinkActionActivation
			//Class and Feature IDs 
			static const unsigned long CS_CREATELINKACTIONACTIVATION_CLASS = 606847404;
			static const unsigned int CS_CREATELINKACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int CS_CREATELINKACTIONACTIVATION_CLASS_OPERATION_COUNT = 51;
			
			
			static const unsigned int CS_CREATELINKACTIONACTIVATION_OPERATION_DOACTION = 3584940798;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_CreateLinkActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_CreateLinkActionActivation_Operation_doAction() const = 0;
			
			// End Class CS_CreateLinkActionActivation

			// Begin Class CS_CreateObjectActionActivation
			//Class and Feature IDs 
			static const unsigned long CS_CREATEOBJECTACTIONACTIVATION_CLASS = 1438312354;
			static const unsigned int CS_CREATEOBJECTACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int CS_CREATEOBJECTACTIONACTIVATION_CLASS_OPERATION_COUNT = 49;
			
			
			static const unsigned int CS_CREATEOBJECTACTIONACTIVATION_OPERATION_DOACTION = 1795145183;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_CreateObjectActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_CreateObjectActionActivation_Operation_doAction() const = 0;
			
			// End Class CS_CreateObjectActionActivation

			// Begin Class CS_DefaultConstructStrategy
			//Class and Feature IDs 
			static const unsigned long CS_DEFAULTCONSTRUCTSTRATEGY_CLASS = 1444853409;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_CLASS_FEATURE_COUNT = 3;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_CLASS_OPERATION_COUNT = 17;
			
			static const unsigned long CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_DEFAULTASSOCIATION = 1521826585;
			static const unsigned long CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_GENERATEDREALIZINGCLASSES = 1929799087;
			static const unsigned long CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS = 783119218;
			
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_ADDSTRUCTURALFEATUREVALUE_CS_REFERENCE_VALUE = 948866639;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_CANINSTANTIATE_PROPERTY = 1675598055;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_CONSTRUCT_OPERATION_CS_OBJECT = 3447623878;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_CONSTRUCTOBJECT_CS_OBJECT_CLASS = 3370616454;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GENERATEARRAYPATTERN_CS_REFERENCE_CONNECTOR = 643894154;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GENERATEREALIZINGCLASS_INTERFACE_ESTRING = 3303361213;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GENERATESTARPATTERN_CS_REFERENCE_CONNECTOR = 3283301729;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GETCARDINALITY_CONNECTOREND = 929434209;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GETDEFAULTASSOCIATION = 3875607915;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GETREALIZINGCLASS_INTERFACE = 2418555460;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GETVALUESFROMCONNECTOREND_CS_REFERENCE_CONNECTOREND = 1303973719;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_INSTANTIATEINTERFACE_INTERFACE_LOCUS = 1953064269;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_ISARRAYPATTERN_CONNECTOR = 2364964836;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_ISSTARPATTERN_CONNECTOR = 1857762815;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_DefaultConstructStrategy_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCS_DefaultConstructStrategy_Attribute_defaultAssociation() const = 0;
			virtual std::shared_ptr<ecore::EReference> getCS_DefaultConstructStrategy_Attribute_generatedRealizingClasses() const = 0;
			virtual std::shared_ptr<ecore::EReference> getCS_DefaultConstructStrategy_Attribute_locus() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_addStructuralFeatureValue_CS_Reference_Value() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_canInstantiate_Property() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_construct_Operation_CS_Object() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_constructObject_CS_Object_Class() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_generateArrayPattern_CS_Reference_Connector() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_generateRealizingClass_Interface_EString() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_generateStarPattern_CS_Reference_Connector() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_getCardinality_ConnectorEnd() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_getDefaultAssociation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_getRealizingClass_Interface() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_getValuesFromConnectorEnd_CS_Reference_ConnectorEnd() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_instantiateInterface_Interface_Locus() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_isArrayPattern_Connector() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_DefaultConstructStrategy_Operation_isStarPattern_Connector() const = 0;
			
			// End Class CS_DefaultConstructStrategy

			// Begin Class CS_ReadExtentActionActivation
			//Class and Feature IDs 
			static const unsigned long CS_READEXTENTACTIONACTIVATION_CLASS = 1846972855;
			static const unsigned int CS_READEXTENTACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int CS_READEXTENTACTIONACTIVATION_CLASS_OPERATION_COUNT = 48;
			
			
			static const unsigned int CS_READEXTENTACTIONACTIVATION_OPERATION_DOACTION = 212290264;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ReadExtentActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ReadExtentActionActivation_Operation_doAction() const = 0;
			
			// End Class CS_ReadExtentActionActivation

			// Begin Class CS_ReadSelfActionActivation
			//Class and Feature IDs 
			static const unsigned long CS_READSELFACTIONACTIVATION_CLASS = 1154790487;
			static const unsigned int CS_READSELFACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int CS_READSELFACTIONACTIVATION_CLASS_OPERATION_COUNT = 49;
			
			
			static const unsigned int CS_READSELFACTIONACTIVATION_OPERATION_DOACTION = 1702243650;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ReadSelfActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ReadSelfActionActivation_Operation_doAction() const = 0;
			
			// End Class CS_ReadSelfActionActivation

			// Begin Class CS_RemoveStructuralFeatureValueActionActivation
			//Class and Feature IDs 
			static const unsigned long CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS = 1505686076;
			static const unsigned int CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS_OPERATION_COUNT = 56;
			
			
			static const unsigned int CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION = 1253243884;
			static const unsigned int CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_GETLINKSTODESTROY_STRUCTUREDVALUE_VALUE = 3094667083;
			static const unsigned int CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_GETPOTENTIALLINKENDS_CS_REFERENCE_STRUCTURALFEATURE = 1508622231;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_RemoveStructuralFeatureValueActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_RemoveStructuralFeatureValueActionActivation_Operation_doAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature() const = 0;
			
			// End Class CS_RemoveStructuralFeatureValueActionActivation

			// Begin Class CS_SendSignalActionActivation
			//Class and Feature IDs 
			static const unsigned long CS_SENDSIGNALACTIONACTIVATION_CLASS = 263661846;
			static const unsigned int CS_SENDSIGNALACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int CS_SENDSIGNALACTIONACTIVATION_CLASS_OPERATION_COUNT = 49;
			
			
			static const unsigned int CS_SENDSIGNALACTIONACTIVATION_OPERATION_DOACTION = 796983372;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_SendSignalActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_SendSignalActionActivation_Operation_doAction() const = 0;
			
			// End Class CS_SendSignalActionActivation
			
			
			
		private:
			friend class ActionsPluginImpl;
			// Header only sinleton like implemenation for ActionsPackage eInstance()
			private: 
				static std::shared_ptr<ActionsPackage>* getActionsPackageStaticPtr()
				{
					static std::shared_ptr<ActionsPackage> local_instance; 
					return &(local_instance);
				}
			    static void seteInstance(std::shared_ptr<ActionsPackage> _instance) {*(getActionsPackageStaticPtr())=_instance;}; 
			public:
				static std::shared_ptr<ActionsPackage> eInstance(){return *(getActionsPackageStaticPtr());}
			
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONSPACKAGE_HPP */
