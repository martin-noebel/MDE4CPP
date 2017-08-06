//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SIGNALEVENT_HPP
#define UML_SIGNALEVENT_HPP

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
	class MessageEvent;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class Signal;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class TemplateParameter;
}

// base class includes
#include "MessageEvent.hpp"

// enum includes
#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A SignalEvent represents the receipt of an asynchronous Signal instance.
	<p>From package UML::CommonBehavior.</p> */
	class SignalEvent:virtual public MessageEvent	{
		public:
 			SignalEvent(const SignalEvent &) {}
			SignalEvent& operator=(SignalEvent const&) = delete;
	
		protected:
			SignalEvent(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~SignalEvent() {}

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
			 The specific Signal that is associated with this SignalEvent.
			<p>From package UML::CommonBehavior.</p> */
			virtual std::shared_ptr<uml::Signal > getSignal() const = 0;
			
			/*!
			 The specific Signal that is associated with this SignalEvent.
			<p>From package UML::CommonBehavior.</p> */
			virtual void setSignal(std::shared_ptr<uml::Signal> _signal_signal) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 The specific Signal that is associated with this SignalEvent.
			<p>From package UML::CommonBehavior.</p> */
			std::shared_ptr<uml::Signal > m_signal;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Element > getOwner() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const = 0; 
	};

}
#endif /* end of include guard: UML_SIGNALEVENT_HPP */

