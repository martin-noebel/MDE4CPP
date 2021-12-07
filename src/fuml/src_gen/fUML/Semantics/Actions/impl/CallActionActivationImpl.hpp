//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATIONCALLACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATIONCALLACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../CallActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/InvocationActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API CallActionActivationImpl : virtual public InvocationActionActivationImpl, virtual public CallActionActivation 
	{
		public: 
			CallActionActivationImpl(const CallActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			CallActionActivationImpl& operator=(CallActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			CallActionActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::CallActionActivation> getThisCallActionActivationPtr() const;
			virtual void setThisCallActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::CallActionActivation> thisCallActionActivationPtr);

			//Additional constructors for the containments back reference
			CallActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~CallActionActivationImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual void doAction() ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getCallExecution() ;
			virtual void removeCallExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> execution) ;
			virtual void terminate() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::CallAction> getCallAction() const ;
			virtual void setCallAction(std::shared_ptr<uml::CallAction>) ;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'callAction'*/
			virtual void setAction(std::shared_ptr<uml::Action>) ;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'callAction'*/
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::Execution>> getCallExecutions() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ;
			
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
			std::weak_ptr<fUML::Semantics::Actions::CallActionActivation> m_thisCallActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CALLACTIONACTIVATIONCALLACTIONACTIVATIONIMPL_HPP */
