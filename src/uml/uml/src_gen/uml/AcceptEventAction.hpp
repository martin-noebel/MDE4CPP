//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACCEPTEVENTACTION_HPP
#define UML_ACCEPTEVENTACTION_HPP


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
	class StringExpression;
	class StructuredActivityNode;
	class Trigger;
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
	An AcceptEventAction is an Action that waits for the occurrence of one or more specific Events.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API AcceptEventAction : virtual public Action
	{
		public:
 			AcceptEventAction(const AcceptEventAction &) {}

		protected:
			AcceptEventAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~AcceptEventAction() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates whether there is a single OutputPin for a SignalEvent occurrence, or multiple OutputPins for attribute values of the instance of the Signal associated with a SignalEvent occurrence.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsUnmarshall() const = 0;
			/*!
			Indicates whether there is a single OutputPin for a SignalEvent occurrence, or multiple OutputPins for attribute values of the instance of the Signal associated with a SignalEvent occurrence.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsUnmarshall (bool _isUnmarshall)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			OutputPins holding the values received from an Event occurrence.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> getResult() const = 0;
			/*!
			The Triggers specifying the Events of which the AcceptEventAction waits for occurrences.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Trigger, uml::Element>> getTrigger() const = 0;

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
			/*!
			Indicates whether there is a single OutputPin for a SignalEvent occurrence, or multiple OutputPins for attribute values of the instance of the Signal associated with a SignalEvent occurrence.
			<p>From package UML::Actions.</p>
			*/
			
			bool m_isUnmarshall= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			OutputPins holding the values received from an Event occurrence.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> m_result;
			/*!
			The Triggers specifying the Events of which the AcceptEventAction waits for occurrences.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Trigger, uml::Element>> m_trigger;
	};
}
#endif /* end of include guard: UML_ACCEPTEVENTACTION_HPP */
