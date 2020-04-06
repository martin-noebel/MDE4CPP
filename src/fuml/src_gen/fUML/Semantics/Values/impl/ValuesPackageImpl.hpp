//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_VALUESPACKAGEIMPL_HPP
#define FUML_SEMANTICS_VALUESPACKAGEIMPL_HPP

#include "ecore/EcorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "fUML/Semantics/Values/ValuesPackage.hpp" 


namespace fUML::Semantics::Values 
{
	class Evaluation;
	class LiteralBooleanEvaluation;
	class LiteralEvaluation;
	class LiteralIntegerEvaluation;
	class LiteralNullEvaluation;
	class LiteralRealEvaluation;
	class LiteralStringEvaluation;
	class LiteralUnlimitedNaturalEvaluation;
	class Value;}

namespace ecore
{
	class EcoreFactory;
}

namespace fUML::Semantics::Values
{
	class ValuesPackageImpl : public ecore::EPackageImpl ,virtual public ValuesPackage
	{
		private:    
			ValuesPackageImpl(ValuesPackageImpl const&) = delete;
			ValuesPackageImpl& operator=(ValuesPackageImpl const&) = delete;

		protected:
			ValuesPackageImpl();

		public:
			virtual ~ValuesPackageImpl();

			// Begin Class Evaluation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEvaluation_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getEvaluation_Attribute_locus() const ;
			virtual std::shared_ptr<ecore::EReference> getEvaluation_Attribute_specification() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getEvaluation_Operation_evaluate() const ;
			
			// End Class Evaluation

			// Begin Class LiteralBooleanEvaluation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralBooleanEvaluation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralBooleanEvaluation_Operation_evaluate() const ;
			
			// End Class LiteralBooleanEvaluation

			// Begin Class LiteralEvaluation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralEvaluation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralEvaluation_Operation_getType_EString() const ;
			
			// End Class LiteralEvaluation

			// Begin Class LiteralIntegerEvaluation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralIntegerEvaluation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralIntegerEvaluation_Operation_evaluate() const ;
			
			// End Class LiteralIntegerEvaluation

			// Begin Class LiteralNullEvaluation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralNullEvaluation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralNullEvaluation_Operation_evaluate() const ;
			
			// End Class LiteralNullEvaluation

			// Begin Class LiteralRealEvaluation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralRealEvaluation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralRealEvaluation_Operation_evaluate() const ;
			
			// End Class LiteralRealEvaluation

			// Begin Class LiteralStringEvaluation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralStringEvaluation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralStringEvaluation_Operation_evaluate() const ;
			
			// End Class LiteralStringEvaluation

			// Begin Class LiteralUnlimitedNaturalEvaluation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLiteralUnlimitedNaturalEvaluation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getLiteralUnlimitedNaturalEvaluation_Operation_evaluate() const ;
			
			// End Class LiteralUnlimitedNaturalEvaluation

			// Begin Class Value
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getValue_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_checkAllParents_Classifier_Classifier() const ;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_equals_Value() const ;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_getTypes() const ;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_hasTypes_Classifier() const ;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_objectId() const ;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_specify() const ;
			virtual std::shared_ptr<ecore::EOperation> getValue_Operation_toString() const ;
			
			// End Class Value

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_evaluation_Class = nullptr;std::shared_ptr<ecore::EClass> m_literalBooleanEvaluation_Class = nullptr;std::shared_ptr<ecore::EClass> m_literalEvaluation_Class = nullptr;std::shared_ptr<ecore::EClass> m_literalIntegerEvaluation_Class = nullptr;std::shared_ptr<ecore::EClass> m_literalNullEvaluation_Class = nullptr;std::shared_ptr<ecore::EClass> m_literalRealEvaluation_Class = nullptr;std::shared_ptr<ecore::EClass> m_literalStringEvaluation_Class = nullptr;std::shared_ptr<ecore::EClass> m_literalUnlimitedNaturalEvaluation_Class = nullptr;std::shared_ptr<ecore::EClass> m_value_Class = nullptr;
			
			
			std::shared_ptr<ecore::EReference> m_evaluation_Attribute_locus = nullptr;std::shared_ptr<ecore::EReference> m_evaluation_Attribute_specification = nullptr;
			std::shared_ptr<ecore::EOperation> m_value_Operation_checkAllParents_Classifier_Classifier = nullptr;std::shared_ptr<ecore::EOperation> m_value_Operation_equals_Value = nullptr;std::shared_ptr<ecore::EOperation> m_evaluation_Operation_evaluate = nullptr;std::shared_ptr<ecore::EOperation> m_literalBooleanEvaluation_Operation_evaluate = nullptr;std::shared_ptr<ecore::EOperation> m_literalIntegerEvaluation_Operation_evaluate = nullptr;std::shared_ptr<ecore::EOperation> m_literalNullEvaluation_Operation_evaluate = nullptr;std::shared_ptr<ecore::EOperation> m_literalRealEvaluation_Operation_evaluate = nullptr;std::shared_ptr<ecore::EOperation> m_literalStringEvaluation_Operation_evaluate = nullptr;std::shared_ptr<ecore::EOperation> m_literalUnlimitedNaturalEvaluation_Operation_evaluate = nullptr;std::shared_ptr<ecore::EOperation> m_literalEvaluation_Operation_getType_EString = nullptr;std::shared_ptr<ecore::EOperation> m_value_Operation_getTypes = nullptr;std::shared_ptr<ecore::EOperation> m_value_Operation_hasTypes_Classifier = nullptr;std::shared_ptr<ecore::EOperation> m_value_Operation_objectId = nullptr;std::shared_ptr<ecore::EOperation> m_value_Operation_specify = nullptr;std::shared_ptr<ecore::EOperation> m_value_Operation_toString = nullptr;

			friend class ValuesPackage;

			static bool isInited;
			static ValuesPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createLiteralBooleanEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createLiteralEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createLiteralIntegerEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createLiteralNullEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createLiteralRealEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createLiteralStringEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createLiteralUnlimitedNaturalEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::EcoreFactory> factory);

			void initializeEvaluationContent();
			void initializeLiteralBooleanEvaluationContent();
			void initializeLiteralEvaluationContent();
			void initializeLiteralIntegerEvaluationContent();
			void initializeLiteralNullEvaluationContent();
			void initializeLiteralRealEvaluationContent();
			void initializeLiteralStringEvaluationContent();
			void initializeLiteralUnlimitedNaturalEvaluationContent();
			void initializeValueContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: FUML_SEMANTICS_VALUESPACKAGEIMPL_HPP */