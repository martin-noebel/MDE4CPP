//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCIPACKAGE_HPP
#define FUML_SEMANTICS_LOCIPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EStringToStringMapEntry;
	class EAnnotation;
	class EReference;
	class EGenericType;
	class EOperation;
	class EClass;
	class EParameter;
	class EDataType;
}

namespace fUML::Semantics::Loci 
{
	class ChoiceStrategy;
	class ExecutionFactory;
	class Executor;
	class FirstChoiceStrategy;
	class Locus;
	class SemanticStrategy;
	class SemanticVisitor;
}
 
namespace fUML::Semantics::Loci 
{
	/*!
	The Metamodel Package for the Loci metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API LociPackage : virtual public ecore::EPackage 
	{
		private:    
			LociPackage(LociPackage const&) = delete;
			LociPackage& operator=(LociPackage const&) = delete;

		protected:
			LociPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class ChoiceStrategy
			//Class and Feature IDs 
			static const unsigned long CHOICESTRATEGY_CLASS = 645728985;
			static const unsigned int CHOICESTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CHOICESTRATEGY_CLASS_OPERATION_COUNT = 3;
			
			
			static const unsigned long CHOICESTRATEGY_OPERATION_CHOOSE_EINT = 3427851710;
			static const unsigned long CHOICESTRATEGY_OPERATION_GETNAME = 1209409598;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getChoiceStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getChoiceStrategy_Operation_choose_EInt() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getChoiceStrategy_Operation_getName() const = 0;
			
			// End Class ChoiceStrategy


			// Begin Class ExecutionFactory
			//Class and Feature IDs 
			static const unsigned long EXECUTIONFACTORY_CLASS = 102788675;
			static const unsigned int EXECUTIONFACTORY_CLASS_FEATURE_COUNT = 3;
			static const unsigned int EXECUTIONFACTORY_CLASS_OPERATION_COUNT = 7;
			
			static const unsigned long EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES = 1371486848;
			static const unsigned long EXECUTIONFACTORY_ATTRIBUTE_LOCUS = 648263615;
			static const unsigned long EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES = 1614243054;
			
			static const unsigned long EXECUTIONFACTORY_OPERATION_ADDBUILTINTYPE_PRIMITIVETYPE = 1000019030;
			static const unsigned long EXECUTIONFACTORY_OPERATION_ASSIGNSTRATEGY_SEMANTICSTRATEGY = 4022033692;
			static const unsigned long EXECUTIONFACTORY_OPERATION_CREATEEXECUTION_BEHAVIOR_ELEMENT = 2395760303;
			static const unsigned long EXECUTIONFACTORY_OPERATION_GETBUILTINTYPE_ESTRING = 3934172273;
			static const unsigned long EXECUTIONFACTORY_OPERATION_GETSTRATEGY_ESTRING = 4148006243;
			static const unsigned long EXECUTIONFACTORY_OPERATION_GETSTRATEGYINDEX_ESTRING = 353629829;
			static const unsigned long EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT = 442268567;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExecutionFactory_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getExecutionFactory_Attribute_builtInTypes() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecutionFactory_Attribute_locus() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecutionFactory_Attribute_strategies() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_addBuiltInType_PrimitiveType() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_assignStrategy_SemanticStrategy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_createExecution_Behavior_Element() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_getBuiltInType_EString() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_getStrategy_EString() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_getStrategyIndex_EString() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_instantiateVisitor_Element() const = 0;
			
			// End Class ExecutionFactory


			// Begin Class Executor
			//Class and Feature IDs 
			static const unsigned long EXECUTOR_CLASS = 1690815834;
			static const unsigned int EXECUTOR_CLASS_FEATURE_COUNT = 1;
			static const unsigned int EXECUTOR_CLASS_OPERATION_COUNT = 3;
			
			static const unsigned long EXECUTOR_ATTRIBUTE_LOCUS = 32912316;
			
			static const unsigned long EXECUTOR_OPERATION_EVALUATE_VALUESPECIFICATION = 321446891;
			static const unsigned long EXECUTOR_OPERATION_EXECUTE_BEHAVIOR_PARAMETERVALUE = 3205044137;
			static const unsigned long EXECUTOR_OPERATION_START_CLASS_PARAMETERVALUE = 2158458358;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExecutor_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getExecutor_Attribute_locus() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getExecutor_Operation_evaluate_ValueSpecification() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutor_Operation_execute_Behavior_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutor_Operation_start_Class_ParameterValue() const = 0;
			
			// End Class Executor


			// Begin Class FirstChoiceStrategy
			//Class and Feature IDs 
			static const unsigned long FIRSTCHOICESTRATEGY_CLASS = 1039516550;
			static const unsigned int FIRSTCHOICESTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int FIRSTCHOICESTRATEGY_CLASS_OPERATION_COUNT = 4;
			
			
			static const unsigned long FIRSTCHOICESTRATEGY_OPERATION_CHOOSE_EINT = 1235408894;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getFirstChoiceStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getFirstChoiceStrategy_Operation_choose_EInt() const = 0;
			
			// End Class FirstChoiceStrategy


			// Begin Class Locus
			//Class and Feature IDs 
			static const unsigned long LOCUS_CLASS = 274444621;
			static const unsigned int LOCUS_CLASS_FEATURE_COUNT = 3;
			static const unsigned int LOCUS_CLASS_OPERATION_COUNT = 7;
			
			static const unsigned long LOCUS_ATTRIBUTE_EXECUTOR = 1079111157;
			static const unsigned long LOCUS_ATTRIBUTE_EXTENSIONALVALUES = 1315349633;
			static const unsigned long LOCUS_ATTRIBUTE_FACTORY = 897667860;
			
			static const unsigned long LOCUS_OPERATION_ADD_ELEMENT = 2336178890;
			static const unsigned long LOCUS_OPERATION_ASSIGNEXECUTOR_EXECUTOR = 4071294562;
			static const unsigned long LOCUS_OPERATION_ASSIGNFACTORY_EXECUTIONFACTORY = 2681202388;
			static const unsigned long LOCUS_OPERATION_CONFORMS_CLASSIFIER_CLASSIFIER = 2253046160;
			static const unsigned long LOCUS_OPERATION_INSTANTIATE_CLASS = 928635219;
			static const unsigned long LOCUS_OPERATION_REMOVE_ELEMENT = 2186013543;
			static const unsigned long LOCUS_OPERATION_RETRIEVEEXTENT_CLASSIFIER = 844948954;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLocus_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getLocus_Attribute_executor() const = 0;
			virtual std::shared_ptr<ecore::EReference> getLocus_Attribute_extensionalValues() const = 0;
			virtual std::shared_ptr<ecore::EReference> getLocus_Attribute_factory() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_add_Element() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_assignExecutor_Executor() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_assignFactory_ExecutionFactory() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_conforms_Classifier_Classifier() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_instantiate_Class() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_remove_Element() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_retrieveExtent_Classifier() const = 0;
			
			// End Class Locus


			// Begin Class SemanticStrategy
			//Class and Feature IDs 
			static const unsigned long SEMANTICSTRATEGY_CLASS = 1874097743;
			static const unsigned int SEMANTICSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int SEMANTICSTRATEGY_CLASS_OPERATION_COUNT = 1;
			
			
			static const unsigned long SEMANTICSTRATEGY_OPERATION_GETNAME = 3310607623;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getSemanticStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getSemanticStrategy_Operation_getName() const = 0;
			
			// End Class SemanticStrategy


			// Begin Class SemanticVisitor
			//Class and Feature IDs 
			static const unsigned long SEMANTICVISITOR_CLASS = 768926104;
			static const unsigned int SEMANTICVISITOR_CLASS_FEATURE_COUNT = 0;
			static const unsigned int SEMANTICVISITOR_CLASS_OPERATION_COUNT = 2;
			
			
			static const unsigned long SEMANTICVISITOR_OPERATION__BEGINISOLATION = 1570555301;
			static const unsigned long SEMANTICVISITOR_OPERATION__ENDISOLATION = 3956519543;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getSemanticVisitor_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getSemanticVisitor_Operation__beginIsolation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getSemanticVisitor_Operation__endIsolation() const = 0;
			
			// End Class SemanticVisitor

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<LociPackage> instance;
			public:
				static std::shared_ptr<LociPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCIPACKAGE_HPP */
