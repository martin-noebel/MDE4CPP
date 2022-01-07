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
	class EParameter;
	class EDataType;
	class EStringToStringMapEntry;
	class EGenericType;
	class EReference;
	class EOperation;
	class EAnnotation;
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
	class CS_SendSignalActionActivation;
}
 
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
			static const long long CS_ACCEPTCALLACTIONACTIVATION_CLASS = 465654510;
			static const unsigned int CS_ACCEPTCALLACTIONACTIVATION_CLASS_FEATURE_COUNT = 13;
			static const unsigned int CS_ACCEPTCALLACTIONACTIVATION_CLASS_OPERATION_COUNT = 57;
			
			
			static const int CS_ACCEPTCALLACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE = 2027172968;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_AcceptCallActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_AcceptCallActionActivation_Operation_accept_EventOccurrence() const = 0;
			
			// End Class CS_AcceptCallActionActivation


			// Begin Class CS_AcceptEventActionActivation
			//Class and Feature IDs 
			static const long long CS_ACCEPTEVENTACTIONACTIVATION_CLASS = 967219298;
			static const unsigned int CS_ACCEPTEVENTACTIONACTIVATION_CLASS_FEATURE_COUNT = 13;
			static const unsigned int CS_ACCEPTEVENTACTIONACTIVATION_CLASS_OPERATION_COUNT = 56;
			
			
			static const int CS_ACCEPTEVENTACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE = 2123318986;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_AcceptEventActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_AcceptEventActionActivation_Operation_accept_EventOccurrence() const = 0;
			
			// End Class CS_AcceptEventActionActivation


			// Begin Class CS_AddStructuralFeatureValueActionActivation
			//Class and Feature IDs 
			static const long long CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS = 666852493;
			static const unsigned int CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS_OPERATION_COUNT = 55;
			
			
			static const int CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION = 998058488;
			static const int CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTIONDEFAULT = 494359846;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_AddStructuralFeatureValueActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_AddStructuralFeatureValueActionActivation_Operation_doAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_AddStructuralFeatureValueActionActivation_Operation_doActionDefault() const = 0;
			
			// End Class CS_AddStructuralFeatureValueActionActivation


			// Begin Class CS_CallOperationActionActivation
			//Class and Feature IDs 
			static const long long CS_CALLOPERATIONACTIONACTIVATION_CLASS = 359462383;
			static const unsigned int CS_CALLOPERATIONACTIONACTIVATION_CLASS_FEATURE_COUNT = 14;
			static const unsigned int CS_CALLOPERATIONACTIONACTIVATION_CLASS_OPERATION_COUNT = 58;
			
			
			static const int CS_CALLOPERATIONACTIONACTIVATION_OPERATION__ISCREATE_OPERATION = 777835038;
			static const int CS_CALLOPERATIONACTIONACTIVATION_OPERATION_DOACTION = 161083929;
			static const int CS_CALLOPERATIONACTIONACTIVATION_OPERATION_GETCALLEXECUTION = 1367520836;
			static const int CS_CALLOPERATIONACTIONACTIVATION_OPERATION_ISCREATE_OPERATION = 1805833323;
			static const int CS_CALLOPERATIONACTIONACTIVATION_OPERATION_ISOPERATIONPROVIDED_PORT_OPERATION = 1814316481;
			static const int CS_CALLOPERATIONACTIONACTIVATION_OPERATION_ISOPERATIONREQUIRED_PORT_OPERATION = 1388387072;
			
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
			static const long long CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS = 116608301;
			static const unsigned int CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS_OPERATION_COUNT = 55;
			
			
			static const int CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_DOACTION = 425670922;
			static const int CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETLINKSTODESTROY_STRUCTUREDVALUE_STRUCTURALFEATURE = 1339765966;
			static const int CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETPOTENTIALLINKENDS_CS_REFERENCE_STRUCTURALFEATURE = 1423989550;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ClearStructuralFeatureActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ClearStructuralFeatureActionActivation_Operation_doAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_ClearStructuralFeatureActionActivation_Operation_getLinksToDestroy_StructuredValue_StructuralFeature() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_ClearStructuralFeatureActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature() const = 0;
			
			// End Class CS_ClearStructuralFeatureActionActivation


			// Begin Class CS_ConstructStrategy
			//Class and Feature IDs 
			static const long long CS_CONSTRUCTSTRATEGY_CLASS = 983698108;
			static const unsigned int CS_CONSTRUCTSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CS_CONSTRUCTSTRATEGY_CLASS_OPERATION_COUNT = 3;
			
			
			static const int CS_CONSTRUCTSTRATEGY_OPERATION_CONSTRUCT_OPERATION_CS_OBJECT = 597739318;
			static const int CS_CONSTRUCTSTRATEGY_OPERATION_GETNAME = 1128538055;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ConstructStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ConstructStrategy_Operation_construct_Operation_CS_Object() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_ConstructStrategy_Operation_getName() const = 0;
			
			// End Class CS_ConstructStrategy


			// Begin Class CS_CreateLinkActionActivation
			//Class and Feature IDs 
			static const long long CS_CREATELINKACTIONACTIVATION_CLASS = 606847404;
			static const unsigned int CS_CREATELINKACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int CS_CREATELINKACTIONACTIVATION_CLASS_OPERATION_COUNT = 51;
			
			
			static const int CS_CREATELINKACTIONACTIVATION_OPERATION_DOACTION = 1042294370;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_CreateLinkActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_CreateLinkActionActivation_Operation_doAction() const = 0;
			
			// End Class CS_CreateLinkActionActivation


			// Begin Class CS_CreateObjectActionActivation
			//Class and Feature IDs 
			static const long long CS_CREATEOBJECTACTIONACTIVATION_CLASS = 1438312354;
			static const unsigned int CS_CREATEOBJECTACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int CS_CREATEOBJECTACTIONACTIVATION_CLASS_OPERATION_COUNT = 49;
			
			
			static const int CS_CREATEOBJECTACTIONACTIVATION_OPERATION_DOACTION = 543161058;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_CreateObjectActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_CreateObjectActionActivation_Operation_doAction() const = 0;
			
			// End Class CS_CreateObjectActionActivation


			// Begin Class CS_DefaultConstructStrategy
			//Class and Feature IDs 
			static const long long CS_DEFAULTCONSTRUCTSTRATEGY_CLASS = 1444853409;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_CLASS_FEATURE_COUNT = 3;
			static const unsigned int CS_DEFAULTCONSTRUCTSTRATEGY_CLASS_OPERATION_COUNT = 17;
			
			static const long long CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_DEFAULTASSOCIATION = 1521826585;
			static const long long CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_GENERATEDREALIZINGCLASSES = 1929799087;
			static const long long CS_DEFAULTCONSTRUCTSTRATEGY_ATTRIBUTE_LOCUS = 783119218;
			
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_ADDSTRUCTURALFEATUREVALUE_CS_REFERENCE_VALUE = 1646320932;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_CANINSTANTIATE_PROPERTY = 144834873;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_CONSTRUCT_OPERATION_CS_OBJECT = 819868466;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_CONSTRUCTOBJECT_CS_OBJECT_CLASS = 517187992;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GENERATEARRAYPATTERN_CS_REFERENCE_CONNECTOR = 928453684;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GENERATEREALIZINGCLASS_INTERFACE_ESTRING = 567067280;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GENERATESTARPATTERN_CS_REFERENCE_CONNECTOR = 1413719551;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GETCARDINALITY_CONNECTOREND = 1031700126;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GETDEFAULTASSOCIATION = 1689856359;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GETREALIZINGCLASS_INTERFACE = 637221846;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_GETVALUESFROMCONNECTOREND_CS_REFERENCE_CONNECTOREND = 1894002496;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_INSTANTIATEINTERFACE_INTERFACE_LOCUS = 1839205058;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_ISARRAYPATTERN_CONNECTOR = 1940370942;
			static const int CS_DEFAULTCONSTRUCTSTRATEGY_OPERATION_ISSTARPATTERN_CONNECTOR = 1094385999;
			
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
			static const long long CS_READEXTENTACTIONACTIVATION_CLASS = 1846972855;
			static const unsigned int CS_READEXTENTACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int CS_READEXTENTACTIONACTIVATION_CLASS_OPERATION_COUNT = 48;
			
			
			static const int CS_READEXTENTACTIONACTIVATION_OPERATION_DOACTION = 134936174;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ReadExtentActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ReadExtentActionActivation_Operation_doAction() const = 0;
			
			// End Class CS_ReadExtentActionActivation


			// Begin Class CS_ReadSelfActionActivation
			//Class and Feature IDs 
			static const long long CS_READSELFACTIONACTIVATION_CLASS = 1154790487;
			static const unsigned int CS_READSELFACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int CS_READSELFACTIONACTIVATION_CLASS_OPERATION_COUNT = 49;
			
			
			static const int CS_READSELFACTIONACTIVATION_OPERATION_DOACTION = 1482151985;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_ReadSelfActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_ReadSelfActionActivation_Operation_doAction() const = 0;
			
			// End Class CS_ReadSelfActionActivation


			// Begin Class CS_RemoveStructuralFeatureValueActionActivation
			//Class and Feature IDs 
			static const long long CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS = 1505686076;
			static const unsigned int CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS_FEATURE_COUNT = 12;
			static const unsigned int CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS_OPERATION_COUNT = 56;
			
			
			static const int CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_DOACTION = 2088584924;
			static const int CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_GETLINKSTODESTROY_STRUCTUREDVALUE_VALUE = 1499748761;
			static const int CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_OPERATION_GETPOTENTIALLINKENDS_CS_REFERENCE_STRUCTURALFEATURE = 502293310;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_RemoveStructuralFeatureValueActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_RemoveStructuralFeatureValueActionActivation_Operation_doAction() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_RemoveStructuralFeatureValueActionActivation_Operation_getLinksToDestroy_StructuredValue_Value() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_RemoveStructuralFeatureValueActionActivation_Operation_getPotentialLinkEnds_CS_Reference_StructuralFeature() const = 0;
			
			// End Class CS_RemoveStructuralFeatureValueActionActivation


			// Begin Class CS_SendSignalActionActivation
			//Class and Feature IDs 
			static const long long CS_SENDSIGNALACTIONACTIVATION_CLASS = 263661846;
			static const unsigned int CS_SENDSIGNALACTIONACTIVATION_CLASS_FEATURE_COUNT = 11;
			static const unsigned int CS_SENDSIGNALACTIONACTIVATION_CLASS_OPERATION_COUNT = 49;
			
			
			static const int CS_SENDSIGNALACTIONACTIVATION_OPERATION_DOACTION = 699108812;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_SendSignalActionActivation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_SendSignalActionActivation_Operation_doAction() const = 0;
			
			// End Class CS_SendSignalActionActivation

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ActionsPackage> instance;
			public:
				static std::shared_ptr<ActionsPackage> eInstance();
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONSPACKAGE_HPP */
