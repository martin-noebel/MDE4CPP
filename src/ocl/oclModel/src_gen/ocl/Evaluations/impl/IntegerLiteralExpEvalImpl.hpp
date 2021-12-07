//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_INTEGERLITERALEXPEVALINTEGERLITERALEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_INTEGERLITERALEXPEVALINTEGERLITERALEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../IntegerLiteralExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralIntegerEvaluationImpl.hpp"
#include "ocl/Evaluations/impl/NumericLiteralExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API IntegerLiteralExpEvalImpl : virtual public fUML::Semantics::Values::LiteralIntegerEvaluationImpl, virtual public NumericLiteralExpEvalImpl, virtual public IntegerLiteralExpEval 
	{
		public: 
			IntegerLiteralExpEvalImpl(const IntegerLiteralExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			IntegerLiteralExpEvalImpl& operator=(IntegerLiteralExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			IntegerLiteralExpEvalImpl();
			virtual std::shared_ptr<ocl::Evaluations::IntegerLiteralExpEval> getThisIntegerLiteralExpEvalPtr() const;
			virtual void setThisIntegerLiteralExpEvalPtr(std::weak_ptr<ocl::Evaluations::IntegerLiteralExpEval> thisIntegerLiteralExpEvalPtr);


		public:
			//destructor
			virtual ~IntegerLiteralExpEvalImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
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

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<ocl::Evaluations::IntegerLiteralExpEval> m_thisIntegerLiteralExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_INTEGERLITERALEXPEVALINTEGERLITERALEXPEVALIMPL_HPP */
