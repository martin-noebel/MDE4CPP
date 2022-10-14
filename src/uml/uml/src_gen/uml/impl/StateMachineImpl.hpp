//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STATEMACHINESTATEMACHINEIMPL_HPP
#define UML_STATEMACHINESTATEMACHINEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../StateMachine.hpp"

#include "uml/impl/BehaviorImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API StateMachineImpl : virtual public BehaviorImpl, virtual public StateMachine 
	{
		public: 
			StateMachineImpl(const StateMachineImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			StateMachineImpl& operator=(StateMachineImpl const&); 

		protected:
			friend class umlFactoryImpl;
			StateMachineImpl();
			virtual std::shared_ptr<uml::StateMachine> getThisStateMachinePtr() const;
			virtual void setThisStateMachinePtr(std::weak_ptr<uml::StateMachine> thisStateMachinePtr);

			//Additional constructors for the containments back reference
			StateMachineImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier);
			//Additional constructors for the containments back reference
			StateMachineImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			StateMachineImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			StateMachineImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			StateMachineImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~StateMachineImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The operation LCA(s1,s2) returns the Region that is the least common ancestor of Vertices s1 and s2, based on the StateMachine containment hierarchy.
			result = (if ancestor(s1, s2) then 
			    s2.container
			else
				if ancestor(s2, s1) then
				    s1.container 
				else 
				    LCA(s1.container.state, s2.container.state)
				endif
			endif)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::Region> LCA(std::shared_ptr<uml::Vertex> s1, std::shared_ptr<uml::Vertex> s2) ;
			/*!
			This utility funciton is like the LCA, except that it returns the nearest composite State that contains both input Vertices.
			result = (if v2.oclIsTypeOf(State) and ancestor(v1, v2) then
				v2.oclAsType(State)
			else if v1.oclIsTypeOf(State) and ancestor(v2, v1) then
				v1.oclAsType(State)
			else if (v1.container.state->isEmpty() or v2.container.state->isEmpty()) then 
				null.oclAsType(State)
			else LCAState(v1.container.state, v2.container.state)
			endif endif endif)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::State> LCAState(std::shared_ptr<uml::Vertex> v1, std::shared_ptr<uml::Vertex> v2) ;
			/*!
			The query ancestor(s1, s2) checks whether Vertex s2 is an ancestor of Vertex s1.
			result = (if (s2 = s1) then 
				true 
			else 
				if s1.container.stateMachine->notEmpty() then 
				    true
				else 
				    if s2.container.stateMachine->notEmpty() then 
				        false
				    else
				        ancestor(s1, s2.container.state)
				     endif
				 endif
			endif  )
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool ancestor(std::shared_ptr<uml::Vertex> s1, std::shared_ptr<uml::Vertex> s2) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The connection points defined for this StateMachine. They represent the interface of the StateMachine when used as part of submachine State
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>> getConnectionPoint() const ;
			/*!
			The StateMachines of which this is an extension.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::StateMachine>> getExtendedStateMachine() const ;
			/*!
			The Regions owned directly by the StateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Region, uml::NamedElement>> getRegion() const ;
			/*!
			References the submachine(s) in case of a submachine State. Multiple machines are referenced in case of a concurrent State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::State>> getSubmachineState() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::StateMachine> m_thisStateMachinePtr;
	};
}
#endif /* end of include guard: UML_STATEMACHINESTATEMACHINEIMPL_HPP */
