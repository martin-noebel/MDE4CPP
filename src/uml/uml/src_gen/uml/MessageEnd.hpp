//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_MESSAGEEND_HPP
#define UML_MESSAGEEND_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Comment;
	class Dependency;
	class InteractionFragment;
	class Message;
	class Namespace;
	class StringExpression;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/NamedElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	MessageEnd is an abstract specialization of NamedElement that represents what can occur at the end of a Message.
	<p>From package UML::Interactions.</p>
	*/
	
	class UML_API MessageEnd: virtual public NamedElement
	{
		public:
 			MessageEnd(const MessageEnd &) {}

		protected:
			MessageEnd(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~MessageEnd() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			This query returns a set including the enclosing InteractionFragment this MessageEnd is enclosed within.
			result = (if self->select(oclIsKindOf(Gate))->notEmpty() 
			then -- it is a Gate
			let endGate : Gate = 
			  self->select(oclIsKindOf(Gate)).oclAsType(Gate)->asOrderedSet()->first()
			  in
			  if endGate.isOutsideCF() 
			  then endGate.combinedFragment.enclosingInteraction.oclAsType(InteractionFragment)->asSet()->
			     union(endGate.combinedFragment.enclosingOperand.oclAsType(InteractionFragment)->asSet())
			  else if endGate.isInsideCF() 
			    then endGate.combinedFragment.oclAsType(InteractionFragment)->asSet()
			    else if endGate.isFormal() 
			      then endGate.interaction.oclAsType(InteractionFragment)->asSet()
			      else if endGate.isActual() 
			        then endGate.interactionUse.enclosingInteraction.oclAsType(InteractionFragment)->asSet()->
			     union(endGate.interactionUse.enclosingOperand.oclAsType(InteractionFragment)->asSet())
			        else null
			        endif
			      endif
			    endif
			  endif
			else -- it is a MessageOccurrenceSpecification
			let endMOS : MessageOccurrenceSpecification  = 
			  self->select(oclIsKindOf(MessageOccurrenceSpecification)).oclAsType(MessageOccurrenceSpecification)->asOrderedSet()->first() 
			  in
			  if endMOS.enclosingInteraction->notEmpty() 
			  then endMOS.enclosingInteraction.oclAsType(InteractionFragment)->asSet()
			  else endMOS.enclosingOperand.oclAsType(InteractionFragment)->asSet()
			  endif
			endif)
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::InteractionFragment> > enclosingFragment() = 0;
			/*!
			This query returns value true if this MessageEnd is a receiveEvent.
			message->notEmpty()
			result = (message.receiveEvent->asSet()->includes(self))
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual bool isReceive() = 0;
			/*!
			This query returns value true if this MessageEnd is a sendEvent.
			message->notEmpty()
			result = (message.sendEvent->asSet()->includes(self))
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual bool isSend() = 0;
			/*!
			This query returns a set including the MessageEnd (if exists) at the opposite end of the Message for this MessageEnd.
			result = (message->asSet().messageEnd->asSet()->excluding(self))
			message->notEmpty()
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::MessageEnd> > oppositeEnd() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			References a Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::Message> getMessage() const = 0;
			/*!
			References a Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setMessage(std::shared_ptr<uml::Message>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			References a Message.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::Message> m_message;
	};
}
#endif /* end of include guard: UML_MESSAGEEND_HPP */