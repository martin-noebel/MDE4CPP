//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_CALLBEHAVIORACTIONACTIVATIONCALLBEHAVIORACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_CALLBEHAVIORACTIONACTIVATIONCALLBEHAVIORACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CallBehaviorActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/CallActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class CallBehaviorActionActivationImpl : virtual public CallActionActivationImpl, virtual public CallBehaviorActionActivation 
	{
		public: 
			CallBehaviorActionActivationImpl(const CallBehaviorActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CallBehaviorActionActivationImpl& operator=(CallBehaviorActionActivationImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			CallBehaviorActionActivationImpl();
			virtual std::shared_ptr<CallBehaviorActionActivation> getThisCallBehaviorActionActivationPtr() const;
			virtual void setThisCallBehaviorActionActivationPtr(std::weak_ptr<CallBehaviorActionActivation> thisCallBehaviorActionActivationPtr);

			//Additional constructors for the containments back reference
			CallBehaviorActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~CallBehaviorActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getCallExecution() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<org.eclipse.uml2.uml.CallBehaviorAction > getCallBehaviorAction() const ;
			
			
			virtual void setCallBehaviorAction(std::shared_ptr<org.eclipse.uml2.uml.CallBehaviorAction> _callBehaviorAction) ;
			
			/*Additional Setter for 'CallActionActivation::callAction' redefined by reference 'callBehaviorAction'*/
			
			virtual void setCallAction(std::shared_ptr<org.eclipse.uml2.uml.CallAction> _callAction) ;
			
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'callBehaviorAction'*/
			
			virtual void setAction(std::shared_ptr<org.eclipse.uml2.uml.Action> _action) ;
			
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'callBehaviorAction'*/
			
			virtual void setNode(std::shared_ptr<org.eclipse.uml2.uml.ActivityNode> _node) ;
			
							
			
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
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<CallBehaviorActionActivation> m_thisCallBehaviorActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CALLBEHAVIORACTIONACTIVATIONCALLBEHAVIORACTIONACTIVATIONIMPL_HPP */
