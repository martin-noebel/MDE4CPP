//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_NUMERICLITERALEXPNUMERICLITERALEXPIMPL_HPP
#define OCL_EXPRESSIONS_NUMERICLITERALEXPNUMERICLITERALEXPIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../NumericLiteralExp.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ocl/Expressions/impl/PrimitiveLiteralExpImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class NumericLiteralExpImpl : virtual public PrimitiveLiteralExpImpl, virtual public NumericLiteralExp 
	{
		public: 
			NumericLiteralExpImpl(const NumericLiteralExpImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			NumericLiteralExpImpl& operator=(NumericLiteralExpImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			NumericLiteralExpImpl();
			virtual std::shared_ptr<NumericLiteralExp> getThisNumericLiteralExpPtr() const;
			virtual void setThisNumericLiteralExpPtr(std::weak_ptr<NumericLiteralExp> thisNumericLiteralExpPtr);

			//Additional constructors for the containments back reference
			NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement);
			//Additional constructors for the containments back reference
			NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id);
			//Additional constructors for the containments back reference
			NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner);
			//Additional constructors for the containments back reference
			NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall);
			//Additional constructors for the containments back reference
			NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			NumericLiteralExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression);

		public:
			//destructor
			virtual ~NumericLiteralExpImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
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
			std::weak_ptr<NumericLiteralExp> m_thisNumericLiteralExpPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_NUMERICLITERALEXPNUMERICLITERALEXPIMPL_HPP */
