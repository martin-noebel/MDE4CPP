//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INPUTPIN_HPP
#define UML_INPUTPIN_HPP

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
	class Activity;
}

namespace uml 
{
	class ActivityEdge;
}

namespace uml 
{
	class ActivityGroup;
}

namespace uml 
{
	class ActivityNode;
}

namespace uml 
{
	class ActivityPartition;
}

namespace uml 
{
	class Behavior;
}

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
	class InterruptibleActivityRegion;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class Pin;
}

namespace uml 
{
	class RedefinableElement;
}

namespace uml 
{
	class State;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class StructuredActivityNode;
}

namespace uml 
{
	class Type;
}

namespace uml 
{
	class ValueSpecification;
}

// base class includes
#include "Pin.hpp"

// enum includes
#include "ObjectNodeOrderingKind.hpp"

#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 An InputPin is a Pin that holds input values to be consumed by an Action.
	<p>From package UML::Actions.</p> */
	class InputPin:virtual public Pin	{
		public:
 			InputPin(const InputPin &) {}
			InputPin& operator=(InputPin const&) = delete;
	
		protected:
			InputPin(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~InputPin() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 An InputPin may have outgoing ActivityEdges only when it is owned by a StructuredActivityNode, and these edges must target a node contained (directly or indirectly) in the owning StructuredActivityNode.
			outgoing->notEmpty() implies
				action<>null and
				action.oclIsKindOf(StructuredActivityNode) and
				action.oclAsType(StructuredActivityNode).allOwnedNodes()->includesAll(outgoing.target) */ 
			virtual bool
			 outgoing_edges_structured_only(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Element > getOwner() const = 0;/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Union<uml::ActivityGroup> > getInGroup() const = 0;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Union<uml::RedefinableElement> > getRedefinedElement() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const = 0; 
	};

}
#endif /* end of include guard: UML_INPUTPIN_HPP */

