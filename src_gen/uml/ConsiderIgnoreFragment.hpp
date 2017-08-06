//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONSIDERIGNOREFRAGMENT_HPP
#define UML_CONSIDERIGNOREFRAGMENT_HPP

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
	class CombinedFragment;
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
	class Gate;
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
	class NamedElement;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class StringExpression;
}

// base class includes
#include "CombinedFragment.hpp"

// enum includes
#include "InteractionOperatorKind.hpp"

#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A ConsiderIgnoreFragment is a kind of CombinedFragment that is used for the consider and ignore cases, which require lists of pertinent Messages to be specified.
	<p>From package UML::Interactions.</p> */
	class ConsiderIgnoreFragment:virtual public CombinedFragment	{
		public:
 			ConsiderIgnoreFragment(const ConsiderIgnoreFragment &) {}
			ConsiderIgnoreFragment& operator=(ConsiderIgnoreFragment const&) = delete;
	
		protected:
			ConsiderIgnoreFragment(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ConsiderIgnoreFragment() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 The interaction operator of a ConsiderIgnoreFragment must be either 'consider' or 'ignore'.
			(interactionOperator =  InteractionOperatorKind::consider) or (interactionOperator =  InteractionOperatorKind::ignore) */ 
			virtual bool
			 consider_or_ignore(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The NamedElements must be of a type of element that can be a signature for a message (i.e.., an Operation, or a Signal).
			message->forAll(m | m.oclIsKindOf(Operation) or m.oclIsKindOf(Signal)) */ 
			virtual bool
			 type(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The set of messages that apply to this fragment.
			<p>From package UML::Interactions.</p> */
			virtual 	std::shared_ptr< Bag<uml::NamedElement> >
			 getMessage() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 The set of messages that apply to this fragment.
			<p>From package UML::Interactions.</p> */
				std::shared_ptr< Bag<uml::NamedElement> >
			 m_message;
			

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
#endif /* end of include guard: UML_CONSIDERIGNOREFRAGMENT_HPP */

