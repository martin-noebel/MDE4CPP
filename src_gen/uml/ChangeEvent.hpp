//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CHANGEEVENT_HPP
#define UML_CHANGEEVENT_HPP

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
	class Event;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class TemplateParameter;
}

namespace uml 
{
	class ValueSpecification;
}

// base class includes
#include "Event.hpp"

// enum includes
#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A ChangeEvent models a change in the system configuration that makes a condition true.
	<p>From package UML::CommonBehavior.</p> */
	class ChangeEvent:virtual public Event	{
		public:
 			ChangeEvent(const ChangeEvent &) {}
			ChangeEvent& operator=(ChangeEvent const&) = delete;
	
		protected:
			ChangeEvent(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ChangeEvent() {}

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
			 A Boolean-valued ValueSpecification that will result in a ChangeEvent whenever its value changes from false to true.
			<p>From package UML::CommonBehavior.</p> */
			virtual std::shared_ptr<uml::ValueSpecification > getChangeExpression() const = 0;
			
			/*!
			 A Boolean-valued ValueSpecification that will result in a ChangeEvent whenever its value changes from false to true.
			<p>From package UML::CommonBehavior.</p> */
			virtual void setChangeExpression(std::shared_ptr<uml::ValueSpecification> _changeExpression_changeExpression) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 A Boolean-valued ValueSpecification that will result in a ChangeEvent whenever its value changes from false to true.
			<p>From package UML::CommonBehavior.</p> */
			std::shared_ptr<uml::ValueSpecification > m_changeExpression;
			

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
#endif /* end of include guard: UML_CHANGEEVENT_HPP */

