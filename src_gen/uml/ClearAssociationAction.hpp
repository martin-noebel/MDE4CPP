//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CLEARASSOCIATIONACTION_HPP
#define UML_CLEARASSOCIATIONACTION_HPP

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
	class Action;
}

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
	class Association;
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
	class ExceptionHandler;
}

namespace uml 
{
	class InputPin;
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
	class OutputPin;
}

namespace uml 
{
	class RedefinableElement;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class StructuredActivityNode;
}

// base class includes
#include "Action.hpp"

// enum includes
#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A ClearAssociationAction is an Action that destroys all links of an Association in which a particular object participates.
	<p>From package UML::Actions.</p> */
	class ClearAssociationAction:virtual public Action	{
		public:
 			ClearAssociationAction(const ClearAssociationAction &) {}
			ClearAssociationAction& operator=(ClearAssociationAction const&) = delete;
	
		protected:
			ClearAssociationAction(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ClearAssociationAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 The multiplicity of the object InputPin is 1..1.
			object.is(1,1) */ 
			virtual bool
			 multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The type of the InputPin must conform to the type of at least one of the memberEnds of the association.
			association.memberEnd->exists(self.object.type.conformsTo(type)) */ 
			virtual bool
			 same_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The Association to be cleared.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::Association > getAssociation() const = 0;
			
			/*!
			 The Association to be cleared.
			<p>From package UML::Actions.</p> */
			virtual void setAssociation(std::shared_ptr<uml::Association> _association_association) = 0;
			/*!
			 The InputPin that gives the object whose participation in the Association is to be cleared.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::InputPin > getObject() const = 0;
			
			/*!
			 The InputPin that gives the object whose participation in the Association is to be cleared.
			<p>From package UML::Actions.</p> */
			virtual void setObject(std::shared_ptr<uml::InputPin> _object_object) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 The Association to be cleared.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<uml::Association > m_association;
			/*!
			 The InputPin that gives the object whose participation in the Association is to be cleared.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<uml::InputPin > m_object;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
			 getInput() const = 0;/*!
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
#endif /* end of include guard: UML_CLEARASSOCIATIONACTION_HPP */

