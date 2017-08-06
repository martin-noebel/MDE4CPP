//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXPANSIONNODE_HPP
#define UML_EXPANSIONNODE_HPP

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
	class ExpansionRegion;
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
	class ObjectNode;
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
#include "ObjectNode.hpp"

// enum includes
#include "ObjectNodeOrderingKind.hpp"

#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 An ExpansionNode is an ObjectNode used to indicate a collection input or output for an ExpansionRegion. A collection input of an ExpansionRegion contains a collection that is broken into its individual elements inside the region, whose content is executed once per element. A collection output of an ExpansionRegion combines individual elements produced by the execution of the region into a collection for use outside the region.
	<p>From package UML::Actions.</p> */
	class ExpansionNode:virtual public ObjectNode	{
		public:
 			ExpansionNode(const ExpansionNode &) {}
			ExpansionNode& operator=(ExpansionNode const&) = delete;
	
		protected:
			ExpansionNode(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ExpansionNode() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 One of regionAsInput or regionAsOutput must be non-empty, but not both.
			regionAsInput->notEmpty() xor regionAsOutput->notEmpty() */ 
			virtual bool
			 region_as_input_or_output(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The ExpansionRegion for which the ExpansionNode is an input.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::ExpansionRegion > getRegionAsInput() const = 0;
			
			/*!
			 The ExpansionRegion for which the ExpansionNode is an input.
			<p>From package UML::Actions.</p> */
			virtual void setRegionAsInput(std::shared_ptr<uml::ExpansionRegion> _regionAsInput_regionAsInput) = 0;
			/*!
			 The ExpansionRegion for which the ExpansionNode is an output.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::ExpansionRegion > getRegionAsOutput() const = 0;
			
			/*!
			 The ExpansionRegion for which the ExpansionNode is an output.
			<p>From package UML::Actions.</p> */
			virtual void setRegionAsOutput(std::shared_ptr<uml::ExpansionRegion> _regionAsOutput_regionAsOutput) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 The ExpansionRegion for which the ExpansionNode is an input.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<uml::ExpansionRegion > m_regionAsInput;
			/*!
			 The ExpansionRegion for which the ExpansionNode is an output.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<uml::ExpansionRegion > m_regionAsOutput;
			

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
#endif /* end of include guard: UML_EXPANSIONNODE_HPP */

