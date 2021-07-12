//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_METAMODELPACKAGE_HPP
#define UML4CPPPROFILE_METAMODELPACKAGE_HPP
#include "uml/Profile.hpp"

namespace uml 
{
	class Extension;
	class ExtensionEnd;
	class Property;
	class Stereotype;
	class ConnectorEnd;
}


namespace UML4CPPProfile 
{
	/*!
	The Metamodel Package for the UML4CPPProfile metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	class UML4CPPProfilePackage : virtual public uml::Profile
	{
		//protected default construcotr
		protected:
			UML4CPPProfilePackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			//getter for the ownedMember
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_DoNotGenerate_UML4CPPProfile_DoNotGenerate() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_ExternalLibrary_UML4CPPProfile_ExternalLibrary() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_MainBehavior_UML4CPPProfile_MainBehavior() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_NonExecutable_UML4CPPProfile_NonExecutable() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_Singleton_UML4CPPProfile_Singleton() = 0;  
			virtual std::shared_ptr<uml::ExtensionEnd> get_ExtensionEnd_extension_UML4CPPPackage_UML4CPPProfile_UML4CPPPackage() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_Behavior_MainBehavior() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_Class_Singleton() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_DoNotGenerate() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_DoNotGenerate_base_Element() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_Element_DoNotGenerate() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_ExternalLibrary() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_ExternalLibrary_base_Package() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_ExternalLibrary_includePath() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_ExternalLibrary_libraryName() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_ExternalLibrary_libraryPath() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_MainBehavior() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_MainBehavior_base_Behavior() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_NamedElement_NonExecutable() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_NonExecutable() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_NonExecutable_base_NamedElement() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_Package_ExternalLibrary() = 0;  
			virtual std::shared_ptr<uml::Extension> get_UML4CPPProfile_Package_UML4CPPPackage() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_Singleton() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_Singleton_base_Class() = 0;  
			virtual std::shared_ptr<uml::Stereotype> get_UML4CPPProfile_UML4CPPPackage() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_UML4CPPPackage_base_Package() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_UML4CPPPackage_eclipseURI() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_UML4CPPPackage_ignoreNamespace() = 0;  
			virtual std::shared_ptr<uml::Property> get_UML4CPPProfile_UML4CPPPackage_packageOnly() = 0;  
			
			

			//getter for subPackages

			//Singleton Instance and Getter
			
			private:
				static std::shared_ptr<UML4CPPProfilePackage> instance;
			public:
				static std::shared_ptr<UML4CPPProfilePackage> eInstance();

			//Class IDs
				static const unsigned long DONOTGENERATE_CLASS = 173581214;
				static const unsigned int DONOTGENERATE_CLASS_FEATURE_COUNT = 1;
				static const unsigned int DONOTGENERATE_CLASS_OPERATION_COUNT = 0;
				static const unsigned long EXTERNALLIBRARY_CLASS = 744219230;
				static const unsigned int EXTERNALLIBRARY_CLASS_FEATURE_COUNT = 4;
				static const unsigned int EXTERNALLIBRARY_CLASS_OPERATION_COUNT = 0;
				static const unsigned long MAINBEHAVIOR_CLASS = 1527007467;
				static const unsigned int MAINBEHAVIOR_CLASS_FEATURE_COUNT = 1;
				static const unsigned int MAINBEHAVIOR_CLASS_OPERATION_COUNT = 0;
				static const unsigned long NONEXECUTABLE_CLASS = 1641344257;
				static const unsigned int NONEXECUTABLE_CLASS_FEATURE_COUNT = 1;
				static const unsigned int NONEXECUTABLE_CLASS_OPERATION_COUNT = 0;
				static const unsigned long SINGLETON_CLASS = 1215028894;
				static const unsigned int SINGLETON_CLASS_FEATURE_COUNT = 1;
				static const unsigned int SINGLETON_CLASS_OPERATION_COUNT = 0;
				static const unsigned long UML4CPPPACKAGE_CLASS = 1707580997;
				static const unsigned int UML4CPPPACKAGE_CLASS_FEATURE_COUNT = 4;
				static const unsigned int UML4CPPPACKAGE_CLASS_OPERATION_COUNT = 0;
			
			
	};
}
#endif /* end of include guard: UML4CPPPROFILE_METAMODELPACKAGE_HPP */