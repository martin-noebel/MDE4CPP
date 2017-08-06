//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_BEHAVIOREXECUTIONSPECIFICATION_HPP
#define UML_BEHAVIOREXECUTIONSPECIFICATION_HPP

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
	class Behavior;
}

namespace uml 
{
	class Comment;
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
	class ExecutionSpecification;
}

namespace uml 
{
	class GeneralOrdering;
}

namespace uml 
{
	class Interaction;
}

namespace uml 
{
	class InteractionOperand;
}

namespace uml 
{
	class Lifeline;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class OccurrenceSpecification;
}

namespace uml 
{
	class StringExpression;
}

// base class includes
#include "ExecutionSpecification.hpp"

// enum includes
#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A BehaviorExecutionSpecification is a kind of ExecutionSpecification representing the execution of a Behavior.
	<p>From package UML::Interactions.</p> */
	class BehaviorExecutionSpecification:virtual public ExecutionSpecification	{
		public:
 			BehaviorExecutionSpecification(const BehaviorExecutionSpecification &) {}
			BehaviorExecutionSpecification& operator=(BehaviorExecutionSpecification const&) = delete;
	
		protected:
			BehaviorExecutionSpecification(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~BehaviorExecutionSpecification() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 Behavior whose execution is occurring.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<uml::Behavior > getBehavior() const = 0;
			
			/*!
			 Behavior whose execution is occurring.
			<p>From package UML::Interactions.</p> */
			virtual void setBehavior(std::shared_ptr<uml::Behavior> _behavior_behavior) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 Behavior whose execution is occurring.
			<p>From package UML::Interactions.</p> */
			std::shared_ptr<uml::Behavior > m_behavior;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Element > getOwner() const = 0;/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Namespace > getNamespace() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const = 0; 
	};

}
#endif /* end of include guard: UML_BEHAVIOREXECUTIONSPECIFICATION_HPP */

