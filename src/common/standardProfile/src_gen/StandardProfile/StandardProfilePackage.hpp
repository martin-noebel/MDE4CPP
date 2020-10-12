//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_METAMODELPACKAGE_HPP
#define STANDARDPROFILE_METAMODELPACKAGE_HPP
#include "uml/Profile.hpp"

namespace uml 
{
	class Extension;
	class ExtensionEnd;
	class Property;
	class Stereotype;
	class ConnectorEnd;
}

namespace StandardProfile 
{
	/*!
	The Metamodel Package for the StandardProfile metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	class StandardProfilePackage : virtual public uml::Profile
	{
		//protected default construcotr
		protected:
			StandardProfilePackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			//getter for the ownedMember
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Auxiliary_StandardProfile_Auxiliary() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_BuildComponent_StandardProfile_BuildComponent() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Call_StandardProfile_Call() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Derive_StandardProfile_Derive() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Destroy_StandardProfile_Destroy() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Document_StandardProfile_Document() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Entity_StandardProfile_Entity() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Executable_StandardProfile_Executable() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_File_StandardProfile_File() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Focus_StandardProfile_Focus() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Framework_StandardProfile_Framework() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Implement_StandardProfile_Implement() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Instantiate_StandardProfile_Instantiate() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Library_StandardProfile_Library() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Metaclass_StandardProfile_Metaclass() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Metamodel_StandardProfile_Metamodel() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Process_StandardProfile_Process() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Realization_StandardProfile_Realization() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Refine_StandardProfile_Refine() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Responsibility_StandardProfile_Responsibility() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Script_StandardProfile_Script() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Send_StandardProfile_Send() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Service_StandardProfile_Service() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Source_StandardProfile_Source() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Specification_StandardProfile_Specification() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Subsystem_StandardProfile_Subsystem() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_SystemModel_StandardProfile_SystemModel() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Trace_StandardProfile_Trace() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Type_StandardProfile_Type() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Usage_Create_StandardProfile_Create() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Utility_StandardProfile_Utility() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Abstraction_Derive() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Abstraction_Refine() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Abstraction_Trace() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Document() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Executable() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_File() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Library() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Script() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Source() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Auxiliary() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Auxiliary_base_Class() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_BehavioralFeature_Create() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_BehavioralFeature_Destroy() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_BuildComponent() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_BuildComponent_base_Component() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Call() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Call_base_Usage() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Auxiliary() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Focus() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_ImplementationClass() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Metaclass() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Type() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Utility() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Classifier_Realization() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Classifier_Specification() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_BuildComponent() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Entity() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Implement() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Process() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Service() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Subsystem() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Create() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Create_base_BehavioralFeature() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Create_base_Usage() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Derive() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Derive_base_Abstraction() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Destroy() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Destroy_base_BehavioralFeature() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Document() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Document_base_Artifact() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Entity() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Entity_base_Component() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Executable() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Executable_base_Artifact() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_File() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_File_base_Artifact() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Focus() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Focus_base_Class() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Framework() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Framework_base_Package() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Implement() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Implement_base_Component() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_ImplementationClass() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_ImplementationClass_base_Class() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Instantiate() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Instantiate_base_Usage() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Library() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Library_base_Artifact() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Metaclass() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Metaclass_base_Class() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Metamodel() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Metamodel_base_Model() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_ModelLibrary() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_ModelLibrary_base_Package() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Model_Metamodel() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Model_SystemModel() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Package_Framework() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Package_ModelLibrary() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Process() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Process_base_Component() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Realization() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Realization_base_Classifier() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Refine() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Refine_base_Abstraction() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Responsibility() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Responsibility_base_Usage() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Script() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Script_base_Artifact() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Send() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Send_base_Usage() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Service() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Service_base_Component() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Source() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Source_base_Artifact() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Specification() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Specification_base_Classifier() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Subsystem() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Subsystem_base_Component() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_SystemModel() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_SystemModel_base_Model() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Trace() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Trace_base_Abstraction() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Type() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Type_base_Class() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Call() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Create() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Instantiate() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Responsibility() = 0;  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Send() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Utility() = 0;  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Utility_base_Class() = 0;  
			
			

			//Singleton Instance and Getter
			
			private:
				static std::shared_ptr<StandardProfilePackage> instance;
			public:
				static std::shared_ptr<StandardProfilePackage> eInstance();

			//Class IDs
				static const unsigned long AUXILIARY_CLASS = 1466047990;
				static const unsigned int AUXILIARY_CLASS_FEATURE_COUNT = 1;
				static const unsigned int AUXILIARY_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long BUILDCOMPONENT_CLASS = 133779747;
				static const unsigned int BUILDCOMPONENT_CLASS_FEATURE_COUNT = 1;
				static const unsigned int BUILDCOMPONENT_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long CALL_CLASS = 495006810;
				static const unsigned int CALL_CLASS_FEATURE_COUNT = 1;
				static const unsigned int CALL_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long CREATE_CLASS = 841207773;
				static const unsigned int CREATE_CLASS_FEATURE_COUNT = 2;
				static const unsigned int CREATE_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long DERIVE_CLASS = 501351344;
				static const unsigned int DERIVE_CLASS_FEATURE_COUNT = 1;
				static const unsigned int DERIVE_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long DESTROY_CLASS = 308948604;
				static const unsigned int DESTROY_CLASS_FEATURE_COUNT = 1;
				static const unsigned int DESTROY_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long DOCUMENT_CLASS = 301496007;
				static const unsigned int DOCUMENT_CLASS_FEATURE_COUNT = 2;
				static const unsigned int DOCUMENT_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long ENTITY_CLASS = 2070209470;
				static const unsigned int ENTITY_CLASS_FEATURE_COUNT = 1;
				static const unsigned int ENTITY_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long EXECUTABLE_CLASS = 1083872305;
				static const unsigned int EXECUTABLE_CLASS_FEATURE_COUNT = 2;
				static const unsigned int EXECUTABLE_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long FILE_CLASS = 242613410;
				static const unsigned int FILE_CLASS_FEATURE_COUNT = 1;
				static const unsigned int FILE_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long FOCUS_CLASS = 2011110723;
				static const unsigned int FOCUS_CLASS_FEATURE_COUNT = 1;
				static const unsigned int FOCUS_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long FRAMEWORK_CLASS = 758834892;
				static const unsigned int FRAMEWORK_CLASS_FEATURE_COUNT = 1;
				static const unsigned int FRAMEWORK_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long IMPLEMENT_CLASS = 1810753173;
				static const unsigned int IMPLEMENT_CLASS_FEATURE_COUNT = 1;
				static const unsigned int IMPLEMENT_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long IMPLEMENTATIONCLASS_CLASS = 1555601512;
				static const unsigned int IMPLEMENTATIONCLASS_CLASS_FEATURE_COUNT = 1;
				static const unsigned int IMPLEMENTATIONCLASS_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long INSTANTIATE_CLASS = 1393463882;
				static const unsigned int INSTANTIATE_CLASS_FEATURE_COUNT = 1;
				static const unsigned int INSTANTIATE_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long LIBRARY_CLASS = 1931384455;
				static const unsigned int LIBRARY_CLASS_FEATURE_COUNT = 2;
				static const unsigned int LIBRARY_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long METACLASS_CLASS = 1110600536;
				static const unsigned int METACLASS_CLASS_FEATURE_COUNT = 1;
				static const unsigned int METACLASS_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long METAMODEL_CLASS = 269527075;
				static const unsigned int METAMODEL_CLASS_FEATURE_COUNT = 1;
				static const unsigned int METAMODEL_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long MODELLIBRARY_CLASS = 690477192;
				static const unsigned int MODELLIBRARY_CLASS_FEATURE_COUNT = 1;
				static const unsigned int MODELLIBRARY_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long PROCESS_CLASS = 985526206;
				static const unsigned int PROCESS_CLASS_FEATURE_COUNT = 1;
				static const unsigned int PROCESS_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long REALIZATION_CLASS = 1122657704;
				static const unsigned int REALIZATION_CLASS_FEATURE_COUNT = 1;
				static const unsigned int REALIZATION_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long REFINE_CLASS = 1523062016;
				static const unsigned int REFINE_CLASS_FEATURE_COUNT = 1;
				static const unsigned int REFINE_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long RESPONSIBILITY_CLASS = 737133505;
				static const unsigned int RESPONSIBILITY_CLASS_FEATURE_COUNT = 1;
				static const unsigned int RESPONSIBILITY_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long SCRIPT_CLASS = 364379155;
				static const unsigned int SCRIPT_CLASS_FEATURE_COUNT = 2;
				static const unsigned int SCRIPT_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long SEND_CLASS = 1722014911;
				static const unsigned int SEND_CLASS_FEATURE_COUNT = 1;
				static const unsigned int SEND_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long SERVICE_CLASS = 1531161909;
				static const unsigned int SERVICE_CLASS_FEATURE_COUNT = 1;
				static const unsigned int SERVICE_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long SOURCE_CLASS = 548518589;
				static const unsigned int SOURCE_CLASS_FEATURE_COUNT = 2;
				static const unsigned int SOURCE_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long SPECIFICATION_CLASS = 504804019;
				static const unsigned int SPECIFICATION_CLASS_FEATURE_COUNT = 1;
				static const unsigned int SPECIFICATION_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long SUBSYSTEM_CLASS = 1825466533;
				static const unsigned int SUBSYSTEM_CLASS_FEATURE_COUNT = 1;
				static const unsigned int SUBSYSTEM_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long SYSTEMMODEL_CLASS = 275535946;
				static const unsigned int SYSTEMMODEL_CLASS_FEATURE_COUNT = 1;
				static const unsigned int SYSTEMMODEL_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long TRACE_CLASS = 1903938062;
				static const unsigned int TRACE_CLASS_FEATURE_COUNT = 1;
				static const unsigned int TRACE_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long TYPE_CLASS = 66837757;
				static const unsigned int TYPE_CLASS_FEATURE_COUNT = 1;
				static const unsigned int TYPE_CLASS_OPERATION_COUNT = 0;
				
				static const unsigned long UTILITY_CLASS = 995008667;
				static const unsigned int UTILITY_CLASS_FEATURE_COUNT = 1;
				static const unsigned int UTILITY_CLASS_OPERATION_COUNT = 0;
				
			
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_METAMODELPACKAGE_HPP */
