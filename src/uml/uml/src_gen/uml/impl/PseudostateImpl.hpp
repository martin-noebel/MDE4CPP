//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PSEUDOSTATEPSEUDOSTATEIMPL_HPP
#define UML_PSEUDOSTATEPSEUDOSTATEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Pseudostate.hpp"

#include "uml/impl/VertexImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API PseudostateImpl : virtual public VertexImpl, virtual public Pseudostate 
	{
		public: 
			PseudostateImpl(const PseudostateImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			PseudostateImpl& operator=(PseudostateImpl const&); 

		protected:
			friend class umlFactoryImpl;
			PseudostateImpl();
			virtual std::shared_ptr<uml::Pseudostate> getThisPseudostatePtr() const;
			virtual void setThisPseudostatePtr(std::weak_ptr<uml::Pseudostate> thisPseudostatePtr);

			//Additional constructors for the containments back reference
			PseudostateImpl(std::weak_ptr<uml::Region> par_container);
			//Additional constructors for the containments back reference
			PseudostateImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			PseudostateImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			PseudostateImpl(std::weak_ptr<uml::State> par_state);
			//Additional constructors for the containments back reference
			PseudostateImpl(std::weak_ptr<uml::StateMachine> par_stateMachine);

		public:
			//destructor
			virtual ~PseudostateImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Determines the precise type of the Pseudostate and can be one of: entryPoint, exitPoint, initial, deepHistory, shallowHistory, join, fork, junction, terminate or choice.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual uml::PseudostateKind getKind() const ;
			/*!
			Determines the precise type of the Pseudostate and can be one of: entryPoint, exitPoint, initial, deepHistory, shallowHistory, join, fork, junction, terminate or choice.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual void setKind (uml::PseudostateKind _kind);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The State that owns this Pseudostate and in which it appears.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::State> getState() const ;
			/*!
			The State that owns this Pseudostate and in which it appears.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setState(std::weak_ptr<uml::State>) ;
			/*!
			The StateMachine in which this Pseudostate is defined. This only applies to Pseudostates of the kind entryPoint or exitPoint.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::StateMachine> getStateMachine() const ;
			/*!
			The StateMachine in which this Pseudostate is defined. This only applies to Pseudostates of the kind entryPoint or exitPoint.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setStateMachine(std::weak_ptr<uml::StateMachine>) ;
			
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
			std::weak_ptr<uml::Pseudostate> m_thisPseudostatePtr;
	};
}
#endif /* end of include guard: UML_PSEUDOSTATEPSEUDOSTATEIMPL_HPP */
