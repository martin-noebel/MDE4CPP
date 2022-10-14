//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_READLINKOBJECTENDACTION_HPP
#define UML_READLINKOBJECTENDACTION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace uml 
{
	class Activity;
	class ActivityEdge;
	class ActivityGroup;
	class ActivityPartition;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ExceptionHandler;
	class InputPin;
	class InterruptibleActivityRegion;
	class Namespace;
	class OutputPin;
	class Property;
	class StringExpression;
	class StructuredActivityNode;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Action.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A ReadLinkObjectEndAction is an Action that retrieves an end object from a link object.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ReadLinkObjectEndAction : virtual public Action
	{
		public:
 			ReadLinkObjectEndAction(const ReadLinkObjectEndAction &) {}

		protected:
			ReadLinkObjectEndAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ReadLinkObjectEndAction() {}

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
			The Association end to be read.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Property> getEnd() const = 0;
			/*!
			The Association end to be read.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setEnd(std::shared_ptr<uml::Property>) = 0;
			/*!
			The input pin from which the link object is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getObject() const = 0;
			/*!
			The input pin from which the link object is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(std::shared_ptr<uml::InputPin>) = 0;
			/*!
			The OutputPin where the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getResult() const = 0;
			/*!
			The OutputPin where the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(std::shared_ptr<uml::OutputPin>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The Association end to be read.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::Property> m_end;
			/*!
			The input pin from which the link object is obtained.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_object;
			/*!
			The OutputPin where the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::OutputPin> m_result;
	};
}
#endif /* end of include guard: UML_READLINKOBJECTENDACTION_HPP */
