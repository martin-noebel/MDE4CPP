//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_IFEXPEVALIFEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_IFEXPEVALIFEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../IfExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ocl/Evaluations/impl/OclExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API IfExpEvalImpl : virtual public OclExpEvalImpl, virtual public IfExpEval 
	{
		public: 
			IfExpEvalImpl(const IfExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			IfExpEvalImpl& operator=(IfExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			IfExpEvalImpl();
			virtual std::shared_ptr<ocl::Evaluations::IfExpEval> getThisIfExpEvalPtr() const;
			virtual void setThisIfExpEvalPtr(std::weak_ptr<ocl::Evaluations::IfExpEval> thisIfExpEvalPtr);


		public:
			//destructor
			virtual ~IfExpEvalImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ocl::Evaluations::OclExpEval> getCondition() const ;
			virtual void setCondition(std::shared_ptr<ocl::Evaluations::OclExpEval>) ;
			virtual std::shared_ptr<ocl::Evaluations::OclExpEval> getElseExpression() const ;
			virtual void setElseExpression(std::shared_ptr<ocl::Evaluations::OclExpEval>) ;
			virtual std::shared_ptr<ocl::Evaluations::OclExpEval> getThenExpression() const ;
			virtual void setThenExpression(std::shared_ptr<ocl::Evaluations::OclExpEval>) ;
			
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
			std::weak_ptr<ocl::Evaluations::IfExpEval> m_thisIfExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_IFEXPEVALIFEXPEVALIMPL_HPP */
