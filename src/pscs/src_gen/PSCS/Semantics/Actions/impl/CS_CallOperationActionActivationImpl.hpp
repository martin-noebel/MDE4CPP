//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_CALLOPERATIONACTIONACTIVATIONCS_CALLOPERATIONACTIONACTIVATIONIMPL_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_CALLOPERATIONACTIONACTIVATIONCS_CALLOPERATIONACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "pscs/pscs.hpp" 

// model includes
#include "../CS_CallOperationActionActivation.hpp"

#include "PSCS/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallOperationActionActivationImpl.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	class PSCS_API CS_CallOperationActionActivationImpl : virtual public fUML::Semantics::Actions::CallOperationActionActivationImpl, virtual public CS_CallOperationActionActivation 
	{
		public: 
			CS_CallOperationActionActivationImpl(const CS_CallOperationActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_CallOperationActionActivationImpl& operator=(CS_CallOperationActionActivationImpl const&); 

		protected:
			friend class PSCS::Semantics::Actions::ActionsFactoryImpl;
			CS_CallOperationActionActivationImpl();
			virtual std::shared_ptr<CS_CallOperationActionActivation> getThisCS_CallOperationActionActivationPtr() const;
			virtual void setThisCS_CallOperationActionActivationPtr(std::weak_ptr<CS_CallOperationActionActivation> thisCS_CallOperationActionActivationPtr);

			//Additional constructors for the containments back reference
			CS_CallOperationActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~CS_CallOperationActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual bool _isCreate(std::shared_ptr<uml::Operation> operation) ; 
			virtual void doAction() ; 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getCallExecution() ; 
			virtual bool isCreate(std::shared_ptr<uml::Operation> operation) ; 
			virtual bool isOperationProvided(std::shared_ptr<uml::Port> port,std::shared_ptr<uml::Operation> operation) ; 
			virtual bool isOperationRequired(std::shared_ptr<uml::Port> port,std::shared_ptr<uml::Operation> operation) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ; 
			 
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<CS_CallOperationActionActivation> m_thisCS_CallOperationActionActivationPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_CALLOPERATIONACTIONACTIVATIONCS_CALLOPERATIONACTIONACTIVATIONIMPL_HPP */
