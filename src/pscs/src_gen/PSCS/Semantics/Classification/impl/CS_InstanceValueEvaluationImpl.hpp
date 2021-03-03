//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_CLASSIFICATION_CS_INSTANCEVALUEEVALUATIONCS_INSTANCEVALUEEVALUATIONIMPL_HPP
#define PSCS_SEMANTICS_CLASSIFICATION_CS_INSTANCEVALUEEVALUATIONCS_INSTANCEVALUEEVALUATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CS_InstanceValueEvaluation.hpp"

#include "PSCS/Semantics/Classification/impl/ClassificationFactoryImpl.hpp"
#include "fUML/Semantics/Classification/impl/InstanceValueEvaluationImpl.hpp"

//*********************************
namespace PSCS::Semantics::Classification 
{
	class CS_InstanceValueEvaluationImpl : virtual public fUML::Semantics::Classification::InstanceValueEvaluationImpl, virtual public CS_InstanceValueEvaluation 
	{
		public: 
			CS_InstanceValueEvaluationImpl(const CS_InstanceValueEvaluationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_InstanceValueEvaluationImpl& operator=(CS_InstanceValueEvaluationImpl const&); 

		protected:
			friend class PSCS::Semantics::Classification::ClassificationFactoryImpl;
			CS_InstanceValueEvaluationImpl();
			virtual std::shared_ptr<CS_InstanceValueEvaluation> getThisCS_InstanceValueEvaluationPtr() const;
			virtual void setThisCS_InstanceValueEvaluationPtr(std::weak_ptr<CS_InstanceValueEvaluation> thisCS_InstanceValueEvaluationPtr);


		public:
			//destructor
			virtual ~CS_InstanceValueEvaluationImpl();
			
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
			std::weak_ptr<CS_InstanceValueEvaluation> m_thisCS_InstanceValueEvaluationPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_CLASSIFICATION_CS_INSTANCEVALUEEVALUATIONCS_INSTANCEVALUEEVALUATIONIMPL_HPP */
