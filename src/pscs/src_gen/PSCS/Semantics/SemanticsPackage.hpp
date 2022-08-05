//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICSPACKAGE_HPP
#define PSCS_SEMANTICSPACKAGE_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EAnnotation;
	class EEnumLiteral;
	class EOperation;
	class EPackage;
	class EAttribute;
	class EDataType;
	class EStringToStringMapEntry;
	class EReference;
	class EEnum;
	class EParameter;
	class EGenericType;
	class EClass;
}

namespace PSCS::Semantics 
{
	namespace Actions 
	{
		class ActionsPackage;
	}

	namespace Classification 
	{
		class ClassificationPackage;
	}

	namespace CommonBehavior 
	{
		class CommonBehaviorPackage;
	}

	namespace Loci 
	{
		class LociPackage;
	}

	namespace StructuredClassifiers 
	{
		class StructuredClassifiersPackage;
	}

	namespace Values 
	{
		class ValuesPackage;
	}
}
 
namespace PSCS::Semantics 
{
	/*!
	The Metamodel Package for the Semantics metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSCS_API SemanticsPackage : virtual public ecore::EPackage 
	{
		private:    
			SemanticsPackage(SemanticsPackage const&) = delete;
			SemanticsPackage& operator=(SemanticsPackage const&) = delete;

		protected:
			SemanticsPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			
			
			virtual std::shared_ptr<PSCS::Semantics::Actions::ActionsPackage> getActions_Package() const = 0;
			virtual std::shared_ptr<PSCS::Semantics::Classification::ClassificationPackage> getClassification_Package() const = 0;
			virtual std::shared_ptr<PSCS::Semantics::CommonBehavior::CommonBehaviorPackage> getCommonBehavior_Package() const = 0;
			virtual std::shared_ptr<PSCS::Semantics::Loci::LociPackage> getLoci_Package() const = 0;
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage> getStructuredClassifiers_Package() const = 0;
			virtual std::shared_ptr<PSCS::Semantics::Values::ValuesPackage> getValues_Package() const = 0;
			
		private:
			friend class SemanticsPluginImpl;
			// Header only sinleton like implemenation for SemanticsPackage eInstance()
			private: 
				static std::shared_ptr<SemanticsPackage>* getSemanticsPackageStaticPtr()
				{
					static std::shared_ptr<SemanticsPackage> local_instance; 
					return &(local_instance);
				}
			    static void seteInstance(std::shared_ptr<SemanticsPackage> _instance) {*(getSemanticsPackageStaticPtr())=_instance;}; 
			public:
				static std::shared_ptr<SemanticsPackage> eInstance(){return *(getSemanticsPackageStaticPtr());}
			
	};
}
#endif /* end of include guard: PSCS_SEMANTICSPACKAGE_HPP */
