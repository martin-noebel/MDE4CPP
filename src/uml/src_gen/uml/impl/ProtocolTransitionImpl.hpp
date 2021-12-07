//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PROTOCOLTRANSITIONPROTOCOLTRANSITIONIMPL_HPP
#define UML_PROTOCOLTRANSITIONPROTOCOLTRANSITIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ProtocolTransition.hpp"

#include "uml/impl/TransitionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ProtocolTransitionImpl : virtual public TransitionImpl, virtual public ProtocolTransition 
	{
		public: 
			ProtocolTransitionImpl(const ProtocolTransitionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ProtocolTransitionImpl& operator=(ProtocolTransitionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ProtocolTransitionImpl();
			virtual std::shared_ptr<uml::ProtocolTransition> getThisProtocolTransitionPtr() const;
			virtual void setThisProtocolTransitionPtr(std::weak_ptr<uml::ProtocolTransition> thisProtocolTransitionPtr);

			//Additional constructors for the containments back reference
			ProtocolTransitionImpl(std::weak_ptr<uml::Region> par_container);
			//Additional constructors for the containments back reference
			ProtocolTransitionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ProtocolTransitionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ProtocolTransitionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			A ProtocolTransition never has associated Behaviors.
			effect = null
			*/
			 
			virtual bool associated_actions(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			A ProtocolTransition always belongs to a ProtocolStateMachine.
			container.belongsToPSM()
			*/
			 
			virtual bool belongs_to_psm(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			Derivation for ProtocolTransition::/referred
			result = (trigger->collect(event)->select(oclIsKindOf(CallEvent))->collect(oclAsType(CallEvent).operation)->asSet())
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Operation> > getReferreds() ;
			/*!
			If a ProtocolTransition refers to an Operation (i.e., has a CallEvent trigger corresponding to an Operation), then that Operation should apply to the context Classifier of the StateMachine of the ProtocolTransition.
			if (referred()->notEmpty() and containingStateMachine()._'context'->notEmpty()) then 
			    containingStateMachine()._'context'.oclAsType(BehavioredClassifier).allFeatures()->includesAll(referred())
			else true endif
			*/
			 
			virtual bool refers_to_operation(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Specifies the post condition of the Transition which is the Condition that should be obtained once the Transition is triggered. This post condition is part of the post condition of the Operation connected to the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Constraint> getPostCondition() const ;
			/*!
			Specifies the post condition of the Transition which is the Condition that should be obtained once the Transition is triggered. This post condition is part of the post condition of the Operation connected to the Transition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setPostCondition(std::shared_ptr<uml::Constraint>) ;
			/*!
			Specifies the precondition of the Transition. It specifies the Condition that should be verified before triggering the Transition. This guard condition added to the source State will be evaluated as part of the precondition of the Operation referred by the Transition if any.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Constraint> getPreCondition() const ;
			/*!
			Specifies the precondition of the Transition. It specifies the Condition that should be verified before triggering the Transition. This guard condition added to the source State will be evaluated as part of the precondition of the Operation referred by the Transition if any.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setPreCondition(std::shared_ptr<uml::Constraint>) ;
			/*!
			This association refers to the associated Operation. It is derived from the Operation of the CallEvent Trigger when applicable.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Operation>> getReferred() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;
			
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
			std::weak_ptr<uml::ProtocolTransition> m_thisProtocolTransitionPtr;
	};
}
#endif /* end of include guard: UML_PROTOCOLTRANSITIONPROTOCOLTRANSITIONIMPL_HPP */
