//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REGION_HPP
#define UML_REGION_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) /**/
#else
    #define ACT_DEBUG(a) a
#endif

#include <string>
#include <map>
#include <vector>
#include "SubsetUnion.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace uml 
{
	class Classifier;
}

namespace uml 
{
	class Comment;
}

namespace uml 
{
	class Constraint;
}

namespace uml 
{
	class Dependency;
}

namespace ecore 
{
	class EAnnotation;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class ElementImport;
}

namespace uml 
{
	class NamedElement;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class PackageImport;
}

namespace uml 
{
	class PackageableElement;
}

namespace uml 
{
	class RedefinableElement;
}

namespace uml 
{
	class Region;
}

namespace uml 
{
	class State;
}

namespace uml 
{
	class StateMachine;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class Transition;
}

namespace uml 
{
	class Vertex;
}

// base class includes
#include "Namespace.hpp"

#include "RedefinableElement.hpp"

// enum includes
#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A Region is a top-level part of a StateMachine or a composite State, that serves as a container for the Vertices and Transitions of the StateMachine. A StateMachine or composite State may contain multiple Regions representing behaviors that may occur in parallel.
	<p>From package UML::StateMachines.</p> */
	class Region:virtual public Namespace,virtual public RedefinableElement	{
		public:
 			Region(const Region &) {}
			Region& operator=(Region const&) = delete;
	
		protected:
			Region(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~Region() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 A Region can have at most one deep history Vertex.
			self.subvertex->select (oclIsKindOf(Pseudostate))->collect(oclAsType(Pseudostate))->
			   select(kind = PseudostateKind::deepHistory)->size() <= 1 */ 
			virtual bool
			 deep_history_vertex(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 A Region can have at most one shallow history Vertex.
			subvertex->select(oclIsKindOf(Pseudostate))->collect(oclAsType(Pseudostate))->
			  select(kind = PseudostateKind::shallowHistory)->size() <= 1 */ 
			virtual bool
			 shallow_history_vertex(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 If a Region is owned by a StateMachine, then it cannot also be owned by a State and vice versa.
			(stateMachine <> null implies state = null) and (state <> null implies stateMachine = null) */ 
			virtual bool
			 owned(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 A Region can have at most one initial Vertex.
			self.subvertex->select (oclIsKindOf(Pseudostate))->collect(oclAsType(Pseudostate))->
			  select(kind = PseudostateKind::initial)->size() <= 1 */ 
			virtual bool
			 initial_vertex(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The operation belongsToPSM () checks if the Region belongs to a ProtocolStateMachine.
			result = (if  stateMachine <> null 
			then
			  stateMachine.oclIsKindOf(ProtocolStateMachine)
			else 
			  state <> null  implies  state.container.belongsToPSM()
			endif )
			<p>From package UML::StateMachines.</p> */ 
			virtual bool
			 belongsToPSM()  = 0;
			
			/*!
			 The operation containingStateMachine() returns the StateMachine in which this Region is defined.
			result = (if stateMachine = null 
			then
			  state.containingStateMachine()
			else
			  stateMachine
			endif)
			<p>From package UML::StateMachines.</p> */ 
			virtual std::shared_ptr<uml::StateMachine> 
			 containingStateMachine()  = 0;
			
			/*!
			 The redefinition context of a Region is the nearest containing StateMachine.
			result = (let sm : StateMachine = containingStateMachine() in
			if sm._'context' = null or sm.general->notEmpty() then
			  sm
			else
			  sm._'context'
			endif)
			<p>From package UML::StateMachines.</p> */ 
			virtual std::shared_ptr<uml::Classifier> 
			 redefinitionContext()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The region of which this region is an extension.
			<p>From package UML::StateMachines.</p> */
			virtual std::shared_ptr<uml::Region > getExtendedRegion() const = 0;
			
			/*!
			 The region of which this region is an extension.
			<p>From package UML::StateMachines.</p> */
			virtual void setExtendedRegion(std::shared_ptr<uml::Region> _extendedRegion_extendedRegion) = 0;
			/*!
			 The State that owns the Region. If a Region is owned by a State, then it cannot also be owned by a StateMachine.
			<p>From package UML::StateMachines.</p> */
			virtual std::shared_ptr<uml::State > getState() const = 0;
			
			/*!
			 The State that owns the Region. If a Region is owned by a State, then it cannot also be owned by a StateMachine.
			<p>From package UML::StateMachines.</p> */
			virtual void setState(std::shared_ptr<uml::State> _state_state) = 0;
			/*!
			 The StateMachine that owns the Region. If a Region is owned by a StateMachine, then it cannot also be owned by a State.
			<p>From package UML::StateMachines.</p> */
			virtual std::shared_ptr<uml::StateMachine > getStateMachine() const = 0;
			
			/*!
			 The StateMachine that owns the Region. If a Region is owned by a StateMachine, then it cannot also be owned by a State.
			<p>From package UML::StateMachines.</p> */
			virtual void setStateMachine(std::shared_ptr<uml::StateMachine> _stateMachine_stateMachine) = 0;
			/*!
			 The set of Transitions owned by the Region.
			<p>From package UML::StateMachines.</p> */
			virtual 		std::shared_ptr<Subset<uml::Transition, uml::NamedElement > >
			 getTransition() const = 0;
			
			/*!
			 The set of Vertices that are owned by this Region.
			<p>From package UML::StateMachines.</p> */
			virtual 		std::shared_ptr<Subset<uml::Vertex, uml::NamedElement > >
			 getSubvertex() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 The region of which this region is an extension.
			<p>From package UML::StateMachines.</p> */
			std::shared_ptr<uml::Region > m_extendedRegion;
			/*!
			 The State that owns the Region. If a Region is owned by a State, then it cannot also be owned by a StateMachine.
			<p>From package UML::StateMachines.</p> */
			std::shared_ptr<uml::State > m_state;
			/*!
			 The StateMachine that owns the Region. If a Region is owned by a StateMachine, then it cannot also be owned by a State.
			<p>From package UML::StateMachines.</p> */
			std::shared_ptr<uml::StateMachine > m_stateMachine;
			/*!
			 The set of Transitions owned by the Region.
			<p>From package UML::StateMachines.</p> */
					std::shared_ptr<Subset<uml::Transition, uml::NamedElement > >
			 m_transition;
			/*!
			 The set of Vertices that are owned by this Region.
			<p>From package UML::StateMachines.</p> */
					std::shared_ptr<Subset<uml::Vertex, uml::NamedElement > >
			 m_subvertex;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Element > getOwner() const = 0;/*!
			 A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::NamedElement> > getMember() const = 0;/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Namespace > getNamespace() const = 0;/*!
			 A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > >
			 getOwnedMember() const = 0;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Union<uml::RedefinableElement> > getRedefinedElement() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const = 0; 
	};

}
#endif /* end of include guard: UML_REGION_HPP */

