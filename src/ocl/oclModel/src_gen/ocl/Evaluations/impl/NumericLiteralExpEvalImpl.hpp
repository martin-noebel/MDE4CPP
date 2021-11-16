//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EVALUATIONS_NUMERICLITERALEXPEVALNUMERICLITERALEXPEVALIMPL_HPP
#define OCL_EVALUATIONS_NUMERICLITERALEXPEVALNUMERICLITERALEXPEVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../NumericLiteralExpEval.hpp"

#include "ocl/Evaluations/impl/EvaluationsFactoryImpl.hpp"
#include "ocl/Evaluations/impl/PrimitiveLiteralExpEvalImpl.hpp"

//*********************************
namespace ocl::Evaluations 
{
	class OCL_API NumericLiteralExpEvalImpl : virtual public PrimitiveLiteralExpEvalImpl, virtual public NumericLiteralExpEval 
	{
		public: 
			NumericLiteralExpEvalImpl(const NumericLiteralExpEvalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			NumericLiteralExpEvalImpl& operator=(NumericLiteralExpEvalImpl const&); 

		protected:
			friend class ocl::Evaluations::EvaluationsFactoryImpl;
			NumericLiteralExpEvalImpl();
			virtual std::shared_ptr<ocl::Evaluations::NumericLiteralExpEval> getThisNumericLiteralExpEvalPtr() const;
			virtual void setThisNumericLiteralExpEvalPtr(std::weak_ptr<ocl::Evaluations::NumericLiteralExpEval> thisNumericLiteralExpEvalPtr);


		public:
			//destructor
			virtual ~NumericLiteralExpEvalImpl();
			
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
			std::weak_ptr<ocl::Evaluations::NumericLiteralExpEval> m_thisNumericLiteralExpEvalPtr;
	};
}
#endif /* end of include guard: OCL_EVALUATIONS_NUMERICLITERALEXPEVALNUMERICLITERALEXPEVALIMPL_HPP */
