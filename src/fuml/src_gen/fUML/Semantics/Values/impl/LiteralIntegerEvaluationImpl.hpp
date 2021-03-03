//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_VALUES_LITERALINTEGEREVALUATIONLITERALINTEGEREVALUATIONIMPL_HPP
#define FUML_SEMANTICS_VALUES_LITERALINTEGEREVALUATIONLITERALINTEGEREVALUATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../LiteralIntegerEvaluation.hpp"

#include "fUML/Semantics/Values/impl/ValuesFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralEvaluationImpl.hpp"

//*********************************
namespace fUML::Semantics::Values 
{
	class LiteralIntegerEvaluationImpl : virtual public LiteralEvaluationImpl, virtual public LiteralIntegerEvaluation 
	{
		public: 
			LiteralIntegerEvaluationImpl(const LiteralIntegerEvaluationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LiteralIntegerEvaluationImpl& operator=(LiteralIntegerEvaluationImpl const&); 

		protected:
			friend class fUML::Semantics::Values::ValuesFactoryImpl;
			LiteralIntegerEvaluationImpl();
			virtual std::shared_ptr<LiteralIntegerEvaluation> getThisLiteralIntegerEvaluationPtr() const;
			virtual void setThisLiteralIntegerEvaluationPtr(std::weak_ptr<LiteralIntegerEvaluation> thisLiteralIntegerEvaluationPtr);


		public:
			//destructor
			virtual ~LiteralIntegerEvaluationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> evaluate() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<LiteralIntegerEvaluation> m_thisLiteralIntegerEvaluationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_VALUES_LITERALINTEGEREVALUATIONLITERALINTEGEREVALUATIONIMPL_HPP */
