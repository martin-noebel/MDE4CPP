//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONNECTIONPOINTREFERENCE_HPP
#define UML_CONNECTIONPOINTREFERENCE_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
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
	class Pseudostate;
	class Region;
	class State;
	class StringExpression;
	class Transition;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Vertex.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A ConnectionPointReference represents a usage (as part of a submachine State) of an entry/exit point Pseudostate defined in the StateMachine referenced by the submachine State.
	<p>From package UML::StateMachines.</p>
	*/
	
	class UML_API ConnectionPointReference : virtual public Vertex
	{
		public:
 			ConnectionPointReference(const ConnectionPointReference &) {}

		protected:
			ConnectionPointReference(){}
			//Additional constructors for the containments back reference
			ConnectionPointReference(std::weak_ptr<uml::Region> par_container);

			//Additional constructors for the containments back reference
			ConnectionPointReference(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			ConnectionPointReference(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			ConnectionPointReference(std::weak_ptr<uml::State> par_state);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ConnectionPointReference() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The entryPoint Pseudostates corresponding to this connection point.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Pseudostate>> getEntry() const = 0;
			/*!
			The exitPoints kind Pseudostates corresponding to this connection point.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Pseudostate>> getExit() const = 0;
			/*!
			The State in which the ConnectionPointReference is defined.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::State> getState() const = 0;
			/*!
			The State in which the ConnectionPointReference is defined.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setState(std::weak_ptr<uml::State>) = 0;

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
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The entryPoint Pseudostates corresponding to this connection point.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Pseudostate>> m_entry;
			/*!
			The exitPoints kind Pseudostates corresponding to this connection point.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Pseudostate>> m_exit;
			/*!
			The State in which the ConnectionPointReference is defined.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::weak_ptr<uml::State> m_state;
	};
}
#endif /* end of include guard: UML_CONNECTIONPOINTREFERENCE_HPP */
