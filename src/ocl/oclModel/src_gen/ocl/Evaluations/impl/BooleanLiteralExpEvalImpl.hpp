//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_BOOLEANLITERALEXPEVALBOOLEANLITERALEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_BOOLEANLITERALEXPEVALBOOLEANLITERALEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../BooleanLiteralExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralBooleanEvaluationImpl.hpp"
#include "ocl/Evaluations/impl/PrimitiveLiteralExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API BooleanLiteralExpEvalImpl : virtual public fUML::Semantics::Values::LiteralBooleanEvaluationImpl, virtual public PrimitiveLiteralExpEvalImpl, virtual public BooleanLiteralExpEval 
	{
		public: 
			BooleanLiteralExpEvalImpl(const BooleanLiteralExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			BooleanLiteralExpEvalImpl& operator=(BooleanLiteralExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			BooleanLiteralExpEvalImpl();
			virtual std::shared_ptr<ocl::Evaluations::BooleanLiteralExpEval> getThisBooleanLiteralExpEvalPtr() const;
			virtual void setThisBooleanLiteralExpEvalPtr(std::weak_ptr<ocl::Evaluations::BooleanLiteralExpEval> thisBooleanLiteralExpEvalPtr);


		public:
			//destructor
			virtual ~BooleanLiteralExpEvalImpl();
			
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<ocl::Evaluations::BooleanLiteralExpEval> m_thisBooleanLiteralExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_BOOLEANLITERALEXPEVALBOOLEANLITERALEXPEVALIMPL_HPP */
