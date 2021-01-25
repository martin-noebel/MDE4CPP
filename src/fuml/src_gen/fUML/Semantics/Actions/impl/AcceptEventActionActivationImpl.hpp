//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_ACCEPTEVENTACTIONACTIVATIONACCEPTEVENTACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_ACCEPTEVENTACTIONACTIVATIONACCEPTEVENTACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../AcceptEventActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class AcceptEventActionActivationImpl : virtual public ActionActivationImpl, virtual public AcceptEventActionActivation 
	{
		public: 
			AcceptEventActionActivationImpl(const AcceptEventActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			AcceptEventActionActivationImpl& operator=(AcceptEventActionActivationImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			AcceptEventActionActivationImpl();
			virtual std::shared_ptr<AcceptEventActionActivation> getThisAcceptEventActionActivationPtr() const;
			virtual void setThisAcceptEventActionActivationPtr(std::weak_ptr<AcceptEventActionActivation> thisAcceptEventActionActivationPtr);

			//Additional constructors for the containments back reference
			AcceptEventActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~AcceptEventActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void accept(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence) ;
			
			 
			virtual void doAction() ;
			
			 
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > incomingTokens) ;
			
			 
			virtual void initialize(std::shared_ptr<org.eclipse.uml2.uml.ActivityNode> node,std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> group) ;
			
			 
			virtual bool isReady() ;
			
			 
			virtual bool match(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence) ;
			
			 
			virtual void run() ;
			
			 
			virtual void terminate() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual bool  isWaiting() const ;
			
			 
			virtual void setWaiting (bool  _waiting); 
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter > getEventAccepter() const ;
			
			
			virtual void setEventAccepter(std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> _eventAccepter) ;
			
							
			
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
			std::weak_ptr<AcceptEventActionActivation> m_thisAcceptEventActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_ACCEPTEVENTACTIONACTIVATIONACCEPTEVENTACTIONACTIVATIONIMPL_HPP */
