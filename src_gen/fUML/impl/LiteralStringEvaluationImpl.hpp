//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_LITERALSTRINGEVALUATIONLITERALSTRINGEVALUATIONIMPL_HPP
#define FUML_LITERALSTRINGEVALUATIONLITERALSTRINGEVALUATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../LiteralStringEvaluation.hpp"

#include "fUML/impl/LiteralEvaluationImpl.hpp"

//*********************************
namespace fUML 
{
	class LiteralStringEvaluationImpl :virtual public LiteralEvaluationImpl, virtual public LiteralStringEvaluation 
	{
		public: 
			LiteralStringEvaluationImpl(const LiteralStringEvaluationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			LiteralStringEvaluationImpl& operator=(LiteralStringEvaluationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			LiteralStringEvaluationImpl();
			virtual std::shared_ptr<LiteralStringEvaluation> getThisLiteralStringEvaluationPtr();
			virtual void setThisLiteralStringEvaluationPtr(std::weak_ptr<LiteralStringEvaluation> thisLiteralStringEvaluationPtr);



		public:
			//destructor
			virtual ~LiteralStringEvaluationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> evaluate()  ;
			
			
			
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<LiteralStringEvaluation> m_thisLiteralStringEvaluationPtr;
	};
}
#endif /* end of include guard: FUML_LITERALSTRINGEVALUATIONLITERALSTRINGEVALUATIONIMPL_HPP */
