//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_VALUESPACKAGE_HPP
#define PSCS_SEMANTICS_VALUESPACKAGE_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EAnnotation;
	class EOperation;
	class EStringToStringMapEntry;
	class EGenericType;
	class EClass;
}

namespace PSCS::Semantics::Values 
{
	class CS_OpaqueExpressionEvaluation;}
 
namespace PSCS::Semantics::Values 
{
	/*!
	The Metamodel Package for the Values metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSCS_API ValuesPackage : virtual public ecore::EPackage 
	{
		private:    
			ValuesPackage(ValuesPackage const&) = delete;
			ValuesPackage& operator=(ValuesPackage const&) = delete;

		protected:
			ValuesPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class CS_OpaqueExpressionEvaluation
			//Class and Feature IDs 
			static const unsigned long CS_OPAQUEEXPRESSIONEVALUATION_CLASS = 2119672650;
			static const unsigned int CS_OPAQUEEXPRESSIONEVALUATION_CLASS_FEATURE_COUNT = 2;
			static const unsigned int CS_OPAQUEEXPRESSIONEVALUATION_CLASS_OPERATION_COUNT = 5;
			
			
			static const unsigned int CS_OPAQUEEXPRESSIONEVALUATION_OPERATION_EVALUATE = 3286539554;
			static const unsigned int CS_OPAQUEEXPRESSIONEVALUATION_OPERATION_EXECUTEEXPRESSIONBEHAVIOR = 4286290164;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_OpaqueExpressionEvaluation_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_OpaqueExpressionEvaluation_Operation_evaluate() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_OpaqueExpressionEvaluation_Operation_executeExpressionBehavior() const = 0;
			
			// End Class CS_OpaqueExpressionEvaluation
			
			
			
		private:
			friend class ValuesPluginImpl;
			// Header only sinleton like implemenation for ValuesPackage eInstance()
			private: 
				static std::shared_ptr<ValuesPackage>* getValuesPackageStaticPtr()
				{
					static std::shared_ptr<ValuesPackage> local_instance; 
					return &(local_instance);
				}
			    static void seteInstance(std::shared_ptr<ValuesPackage> _instance) {*(getValuesPackageStaticPtr())=_instance;}; 
			public:
				static std::shared_ptr<ValuesPackage> eInstance(){return *(getValuesPackageStaticPtr());}
			
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_VALUESPACKAGE_HPP */
