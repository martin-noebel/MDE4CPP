//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PSEUDOSTATE_HPP
#define UML_PSEUDOSTATE_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Comment;
	class Dependency;
	class Namespace;
	class Region;
	class State;
	class StateMachine;
	class StringExpression;
	class Transition;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Vertex.hpp"

// enum includes
#include "uml/PseudostateKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Pseudostate is an abstraction that encompasses different types of transient Vertices in the StateMachine graph. A StateMachine instance never comes to rest in a Pseudostate, instead, it will exit and enter the Pseudostate within a single run-to-completion step.
	<p>From package UML::StateMachines.</p>
	*/
	
	class UML_API Pseudostate : virtual public Vertex
	{
		public:
 			Pseudostate(const Pseudostate &) {}

		protected:
			Pseudostate(){}
			//Additional constructors for the containments back reference
			Pseudostate(std::weak_ptr<uml::Region> par_container);

			//Additional constructors for the containments back reference
			Pseudostate(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Pseudostate(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			Pseudostate(std::weak_ptr<uml::State> par_state);

			//Additional constructors for the containments back reference
			Pseudostate(std::weak_ptr<uml::StateMachine> par_stateMachine);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Pseudostate() {}

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
			 
			virtual uml::PseudostateKind getKind() const = 0;
			/*!
			Determines the precise type of the Pseudostate and can be one of: entryPoint, exitPoint, initial, deepHistory, shallowHistory, join, fork, junction, terminate or choice.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual void setKind (uml::PseudostateKind _kind)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The State that owns this Pseudostate and in which it appears.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::State> getState() const = 0;
			/*!
			The State that owns this Pseudostate and in which it appears.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setState(std::weak_ptr<uml::State>) = 0;
			/*!
			The StateMachine in which this Pseudostate is defined. This only applies to Pseudostates of the kind entryPoint or exitPoint.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::StateMachine> getStateMachine() const = 0;
			/*!
			The StateMachine in which this Pseudostate is defined. This only applies to Pseudostates of the kind entryPoint or exitPoint.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setStateMachine(std::weak_ptr<uml::StateMachine>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			Determines the precise type of the Pseudostate and can be one of: entryPoint, exitPoint, initial, deepHistory, shallowHistory, join, fork, junction, terminate or choice.
			<p>From package UML::StateMachines.</p>
			*/
			
			uml::PseudostateKind m_kind= uml::PseudostateKind::INITIAL;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The State that owns this Pseudostate and in which it appears.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::weak_ptr<uml::State> m_state;
			/*!
			The StateMachine in which this Pseudostate is defined. This only applies to Pseudostates of the kind entryPoint or exitPoint.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::weak_ptr<uml::StateMachine> m_stateMachine;
	};
}
#endif /* end of include guard: UML_PSEUDOSTATE_HPP */
