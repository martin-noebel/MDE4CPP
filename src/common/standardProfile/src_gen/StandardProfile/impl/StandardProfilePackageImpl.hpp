//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_METAMODELPACKAGEIMPL_HPP
#define STANDARDPROFILE_METAMODELPACKAGEIMPL_HPP

#include "StandardProfile/StandardProfilePackage.hpp"
#include "uml/impl/ProfileImpl.hpp"

namespace uml
{
	class LiteralInteger;
	class umlFactory;
}


namespace StandardProfile
{
	class StandardProfilePackageImpl : virtual public uml::ProfileImpl, virtual public StandardProfilePackage
	{
			friend class StandardProfilePackage;
			// Constructor
			StandardProfilePackageImpl();

		public:
			// destructor
			virtual ~StandardProfilePackageImpl();

			//getter for the ownedMember
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Auxiliary_StandardProfile_Auxiliary();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_BuildComponent_StandardProfile_BuildComponent();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Call_StandardProfile_Call();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Derive_StandardProfile_Derive();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Destroy_StandardProfile_Destroy();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Document_StandardProfile_Document();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Entity_StandardProfile_Entity();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Executable_StandardProfile_Executable();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_File_StandardProfile_File();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Focus_StandardProfile_Focus();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Framework_StandardProfile_Framework();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Implement_StandardProfile_Implement();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Instantiate_StandardProfile_Instantiate();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Library_StandardProfile_Library();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Metaclass_StandardProfile_Metaclass();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Metamodel_StandardProfile_Metamodel();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Process_StandardProfile_Process();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Realization_StandardProfile_Realization();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Refine_StandardProfile_Refine();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Responsibility_StandardProfile_Responsibility();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Script_StandardProfile_Script();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Send_StandardProfile_Send();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Service_StandardProfile_Service();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Source_StandardProfile_Source();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Specification_StandardProfile_Specification();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Subsystem_StandardProfile_Subsystem();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_SystemModel_StandardProfile_SystemModel();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Trace_StandardProfile_Trace();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Type_StandardProfile_Type();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Usage_Create_StandardProfile_Create();  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Utility_StandardProfile_Utility();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Abstraction_Derive();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Abstraction_Refine();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Abstraction_Trace();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Document();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Executable();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_File();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Library();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Script();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Artifact_Source();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Auxiliary();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Auxiliary_base_Class();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_BehavioralFeature_Create();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_BehavioralFeature_Destroy();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_BuildComponent();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_BuildComponent_base_Component();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Call();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Call_base_Usage();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Auxiliary();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Focus();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_ImplementationClass();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Metaclass();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Type();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Class_Utility();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Classifier_Realization();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Classifier_Specification();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_BuildComponent();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Entity();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Implement();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Process();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Service();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Component_Subsystem();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Create();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Create_base_BehavioralFeature();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Create_base_Usage();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Derive();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Derive_base_Abstraction();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Destroy();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Destroy_base_BehavioralFeature();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Document();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Document_base_Artifact();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Entity();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Entity_base_Component();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Executable();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Executable_base_Artifact();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_File();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_File_base_Artifact();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Focus();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Focus_base_Class();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Framework();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Framework_base_Package();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Implement();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Implement_base_Component();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_ImplementationClass();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_ImplementationClass_base_Class();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Instantiate();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Instantiate_base_Usage();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Library();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Library_base_Artifact();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Metaclass();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Metaclass_base_Class();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Metamodel();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Metamodel_base_Model();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_ModelLibrary();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_ModelLibrary_base_Package();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Model_Metamodel();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Model_SystemModel();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Package_Framework();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Package_ModelLibrary();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Process();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Process_base_Component();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Realization();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Realization_base_Classifier();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Refine();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Refine_base_Abstraction();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Responsibility();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Responsibility_base_Usage();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Script();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Script_base_Artifact();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Send();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Send_base_Usage();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Service();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Service_base_Component();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Source();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Source_base_Artifact();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Specification();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Specification_base_Classifier();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Subsystem();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Subsystem_base_Component();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_SystemModel();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_SystemModel_base_Model();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Trace();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Trace_base_Abstraction();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Type();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Type_base_Class();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Call();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Create();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Instantiate();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Responsibility();  
			virtual std::shared_ptr<uml::Extension> get_StandardProfile_Usage_Send();  
			virtual std::shared_ptr<uml::Stereotype> get_StandardProfile_Utility();  
			virtual std::shared_ptr<uml::Property> get_StandardProfile_Utility_base_Class();  
			
			

			//getter for subPackages

		private:
			//private variables for ownedMember of the metamodel package
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Auxiliary_StandardProfile_Auxiliary = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Auxiliary_StandardProfile_Auxiliary_lowerValue_LiteralInteger_ExtensionEnd_extension_Auxiliary_StandardProfile_Auxiliary = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create_lowerValue_LiteralInteger_ExtensionEnd_extension_BehavioralFeature_Create_StandardProfile_Create = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_BuildComponent_StandardProfile_BuildComponent = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_BuildComponent_StandardProfile_BuildComponent_lowerValue_LiteralInteger_ExtensionEnd_extension_BuildComponent_StandardProfile_BuildComponent = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Call_StandardProfile_Call = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Call_StandardProfile_Call_lowerValue_LiteralInteger_ExtensionEnd_extension_Call_StandardProfile_Call = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Derive_StandardProfile_Derive = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Derive_StandardProfile_Derive_lowerValue_LiteralInteger_ExtensionEnd_extension_Derive_StandardProfile_Derive = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Destroy_StandardProfile_Destroy = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Destroy_StandardProfile_Destroy_lowerValue_LiteralInteger_ExtensionEnd_extension_Destroy_StandardProfile_Destroy = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Document_StandardProfile_Document = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Document_StandardProfile_Document_lowerValue_LiteralInteger_ExtensionEnd_extension_Document_StandardProfile_Document = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Entity_StandardProfile_Entity = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Entity_StandardProfile_Entity_lowerValue_LiteralInteger_ExtensionEnd_extension_Entity_StandardProfile_Entity = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Executable_StandardProfile_Executable = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Executable_StandardProfile_Executable_lowerValue_LiteralInteger_ExtensionEnd_extension_Executable_StandardProfile_Executable = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_File_StandardProfile_File = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_File_StandardProfile_File_lowerValue_LiteralInteger_ExtensionEnd_extension_File_StandardProfile_File = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Focus_StandardProfile_Focus = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Focus_StandardProfile_Focus_lowerValue_LiteralInteger_ExtensionEnd_extension_Focus_StandardProfile_Focus = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Framework_StandardProfile_Framework = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Framework_StandardProfile_Framework_lowerValue_LiteralInteger_ExtensionEnd_extension_Framework_StandardProfile_Framework = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Implement_StandardProfile_Implement = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Implement_StandardProfile_Implement_lowerValue_LiteralInteger_ExtensionEnd_extension_Implement_StandardProfile_Implement = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass_lowerValue_LiteralInteger_ExtensionEnd_extension_ImplementationClass_StandardProfile_ImplementationClass = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Instantiate_StandardProfile_Instantiate = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Instantiate_StandardProfile_Instantiate_lowerValue_LiteralInteger_ExtensionEnd_extension_Instantiate_StandardProfile_Instantiate = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Library_StandardProfile_Library = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Library_StandardProfile_Library_lowerValue_LiteralInteger_ExtensionEnd_extension_Library_StandardProfile_Library = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Metaclass_StandardProfile_Metaclass = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Metaclass_StandardProfile_Metaclass_lowerValue_LiteralInteger_ExtensionEnd_extension_Metaclass_StandardProfile_Metaclass = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Metamodel_StandardProfile_Metamodel = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Metamodel_StandardProfile_Metamodel_lowerValue_LiteralInteger_ExtensionEnd_extension_Metamodel_StandardProfile_Metamodel = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary_lowerValue_LiteralInteger_ExtensionEnd_extension_ModelLibrary_StandardProfile_ModelLibrary = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Process_StandardProfile_Process = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Process_StandardProfile_Process_lowerValue_LiteralInteger_ExtensionEnd_extension_Process_StandardProfile_Process = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Realization_StandardProfile_Realization = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Realization_StandardProfile_Realization_lowerValue_LiteralInteger_ExtensionEnd_extension_Realization_StandardProfile_Realization = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Refine_StandardProfile_Refine = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Refine_StandardProfile_Refine_lowerValue_LiteralInteger_ExtensionEnd_extension_Refine_StandardProfile_Refine = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Responsibility_StandardProfile_Responsibility = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Responsibility_StandardProfile_Responsibility_lowerValue_LiteralInteger_ExtensionEnd_extension_Responsibility_StandardProfile_Responsibility = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Script_StandardProfile_Script = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Script_StandardProfile_Script_lowerValue_LiteralInteger_ExtensionEnd_extension_Script_StandardProfile_Script = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Send_StandardProfile_Send = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Send_StandardProfile_Send_lowerValue_LiteralInteger_ExtensionEnd_extension_Send_StandardProfile_Send = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Service_StandardProfile_Service = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Service_StandardProfile_Service_lowerValue_LiteralInteger_ExtensionEnd_extension_Service_StandardProfile_Service = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Source_StandardProfile_Source = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Source_StandardProfile_Source_lowerValue_LiteralInteger_ExtensionEnd_extension_Source_StandardProfile_Source = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Specification_StandardProfile_Specification = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Specification_StandardProfile_Specification_lowerValue_LiteralInteger_ExtensionEnd_extension_Specification_StandardProfile_Specification = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Subsystem_StandardProfile_Subsystem = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Subsystem_StandardProfile_Subsystem_lowerValue_LiteralInteger_ExtensionEnd_extension_Subsystem_StandardProfile_Subsystem = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_SystemModel_StandardProfile_SystemModel = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_SystemModel_StandardProfile_SystemModel_lowerValue_LiteralInteger_ExtensionEnd_extension_SystemModel_StandardProfile_SystemModel = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Trace_StandardProfile_Trace = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Trace_StandardProfile_Trace_lowerValue_LiteralInteger_ExtensionEnd_extension_Trace_StandardProfile_Trace = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Type_StandardProfile_Type = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Type_StandardProfile_Type_lowerValue_LiteralInteger_ExtensionEnd_extension_Type_StandardProfile_Type = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Usage_Create_StandardProfile_Create = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Usage_Create_StandardProfile_Create_lowerValue_LiteralInteger_ExtensionEnd_extension_Usage_Create_StandardProfile_Create = nullptr;
			std::shared_ptr<uml::ExtensionEnd> extensionEnd_extension_Utility_StandardProfile_Utility = nullptr;
			std::shared_ptr<uml::LiteralInteger> extensionEnd_extension_Utility_StandardProfile_Utility_lowerValue_LiteralInteger_ExtensionEnd_extension_Utility_StandardProfile_Utility = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Abstraction_Derive = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Abstraction_Refine = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Abstraction_Trace = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Artifact_Document = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Artifact_Executable = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Artifact_File = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Artifact_Library = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Artifact_Script = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Artifact_Source = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Auxiliary = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Auxiliary_base_Class = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_BehavioralFeature_Create = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_BehavioralFeature_Destroy = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_BuildComponent = nullptr;
			std::shared_ptr<uml::Property> standardProfile_BuildComponent_base_Component = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Call = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Call_base_Usage = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Class_Auxiliary = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Class_Focus = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Class_ImplementationClass = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Class_Metaclass = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Class_Type = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Class_Utility = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Classifier_Realization = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Classifier_Specification = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Component_BuildComponent = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Component_Entity = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Component_Implement = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Component_Process = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Component_Service = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Component_Subsystem = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Create = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Create_base_BehavioralFeature = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Create_base_Usage = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Derive = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Derive_base_Abstraction = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Destroy = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Destroy_base_BehavioralFeature = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Document = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Document_base_Artifact = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Entity = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Entity_base_Component = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Executable = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Executable_base_Artifact = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_File = nullptr;
			std::shared_ptr<uml::Property> standardProfile_File_base_Artifact = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Focus = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Focus_base_Class = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Framework = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Framework_base_Package = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Implement = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Implement_base_Component = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_ImplementationClass = nullptr;
			std::shared_ptr<uml::Property> standardProfile_ImplementationClass_base_Class = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Instantiate = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Instantiate_base_Usage = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Library = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Library_base_Artifact = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Metaclass = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Metaclass_base_Class = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Metamodel = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Metamodel_base_Model = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_ModelLibrary = nullptr;
			std::shared_ptr<uml::Property> standardProfile_ModelLibrary_base_Package = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Model_Metamodel = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Model_SystemModel = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Package_Framework = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Package_ModelLibrary = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Process = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Process_base_Component = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Realization = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Realization_base_Classifier = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Refine = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Refine_base_Abstraction = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Responsibility = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Responsibility_base_Usage = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Script = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Script_base_Artifact = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Send = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Send_base_Usage = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Service = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Service_base_Component = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Source = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Source_base_Artifact = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Specification = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Specification_base_Classifier = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Subsystem = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Subsystem_base_Component = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_SystemModel = nullptr;
			std::shared_ptr<uml::Property> standardProfile_SystemModel_base_Model = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Trace = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Trace_base_Abstraction = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Type = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Type_base_Class = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Usage_Call = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Usage_Create = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Usage_Instantiate = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Usage_Responsibility = nullptr;
			std::shared_ptr<uml::Extension> standardProfile_Usage_Send = nullptr;
			std::shared_ptr<uml::Stereotype> standardProfile_Utility = nullptr;
			std::shared_ptr<uml::Property> standardProfile_Utility_base_Class = nullptr;
			
			

			static StandardProfilePackage* create();
			static bool isInited;
			bool isInitialized = false;
			bool isCreated = false;

			void initMetaModel();
			virtual void init(std::shared_ptr<uml::Package> package);

		public:
 			void initializePackageContents(std::shared_ptr<uml::Package> standardProfile);
			void createPackageContents(std::shared_ptr<uml::Package> standardProfile);

		private:
			void createPackageActivities(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory);
			void createPackageClasses(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory);
			void createPackageDataTypes(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory);
			void createPackageAssociations(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory);
			void createPackageDependencies(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory);
			void createPackageEnumerationLiterals(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory);
			void createPackageInstanceSpecifications(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory);
			void createPackageInterfaceRealizations(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory);
			void createPackageInterfaces(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory);
			void createPackagePrimitiveTypes(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory);
			void createPackageStereotypes(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory);
			void createPackageValueSpecifications(std::shared_ptr<uml::Package> standardProfile, std::shared_ptr<uml::umlFactory> factory);

			void initializePackageActivities();
			void initializePackageClasses();
			void initializePackageDataTypes();
			void initializePackageAssociations();
			void initializePackageDependencies();
			void initializePackageInstanceSpecifications();
			void initializePackageInterfaceRealizations();
			void initializePackageInterfaces();
			void initializePackageNestedPackages();
			void initializePackageStereotypes();
			void initializePackageValueSpecifications();
	};
}
#endif /* end of include guard: STANDARDPROFILE_METAMODELPACKAGEIMPL_HPP */
