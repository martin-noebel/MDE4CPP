//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_MESSAGE_HPP
#define UML_MESSAGE_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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
	class Connector;
	class Dependency;
	class Interaction;
	class MessageEnd;
	class Namespace;
	class StringExpression;
	class ValueSpecification;
}

// base class includes
#include "uml/NamedElement.hpp"

// enum includes
#include "uml/MessageKind.hpp"

#include "uml/MessageSort.hpp"

#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Message defines a particular communication between Lifelines of an Interaction.
	<p>From package UML::Interactions.</p>
	*/
	
	class Message: virtual public NamedElement
	{
		public:
 			Message(const Message &) {}

		protected:
			Message(){}
			//Additional constructors for the containments back reference
			Message(std::weak_ptr<uml::Interaction> par_interaction);

			//Additional constructors for the containments back reference
			Message(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			Message(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Message() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Arguments of a Message must only be: i) attributes of the sending lifeline, ii) constants, iii) symbolic values (which are wildcard values representing any legal value), iv) explicit parameters of the enclosing Interaction, v) attributes of the class owning the Interaction.
			*/
			 
			virtual bool arguments(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			Messages cannot cross boundaries of CombinedFragments or their operands.  This is true if and only if both MessageEnds are enclosed within the same InteractionFragment (i.e., an InteractionOperand or an Interaction).
			sendEvent->notEmpty() and receiveEvent->notEmpty() implies
			let sendEnclosingFrag : Set(InteractionFragment) = 
			sendEvent->asOrderedSet()->first().enclosingFragment()
			in 
			let receiveEnclosingFrag : Set(InteractionFragment) = 
			receiveEvent->asOrderedSet()->first().enclosingFragment()
			in  sendEnclosingFrag = receiveEnclosingFrag
			*/
			 
			virtual bool cannot_cross_boundaries(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			This query returns the MessageKind value for this Message.
			result = (messageKind)
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual uml::MessageKind getMessageKind() = 0;/*!
			If the MessageEnds are both OccurrenceSpecifications, then the connector must go between the Parts represented by the Lifelines of the two MessageEnds.
			*/
			 
			virtual bool occurrence_specifications(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			If the sendEvent and the receiveEvent of the same Message are on the same Lifeline, the sendEvent must be ordered before the receiveEvent.
			receiveEvent.oclIsKindOf(MessageOccurrenceSpecification)
			implies
			let f :  Lifeline = sendEvent->select(oclIsKindOf(MessageOccurrenceSpecification)).oclAsType(MessageOccurrenceSpecification)->asOrderedSet()->first().covered in
			f = receiveEvent->select(oclIsKindOf(MessageOccurrenceSpecification)).oclAsType(MessageOccurrenceSpecification)->asOrderedSet()->first().covered  implies
			f.events->indexOf(sendEvent.oclAsType(MessageOccurrenceSpecification)->asOrderedSet()->first() ) < 
			f.events->indexOf(receiveEvent.oclAsType(MessageOccurrenceSpecification)->asOrderedSet()->first() )
			*/
			 
			virtual bool sending_receiving_message_event(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			In the case when a Message with messageSort reply has a non empty Operation signature, the arguments of the Message must correspond to the out, inout, and return parameters of the Operation. A Parameter corresponds to an Argument if the Argument is of the same Class or a specialization of that of the Parameter.
			(messageSort = MessageSort::reply) and signature.oclIsKindOf(Operation) implies 
			 let replyParms : OrderedSet(Parameter) = signature.oclAsType(Operation).ownedParameter->
			select(direction = ParameterDirectionKind::inout or direction = ParameterDirectionKind::out or direction = ParameterDirectionKind::return)
			in replyParms->size() = self.argument->size() and
			self.argument->forAll( o: ValueSpecification | o.oclIsKindOf(Expression) and let e : Expression = o.oclAsType(Expression) in
			e.operand->notEmpty()  implies 
			let p : Parameter = replyParms->at(self.argument->indexOf(o)) in
			e.operand->asSequence()->first().type.oclAsType(Classifier).conformsTo(p.type.oclAsType(Classifier))
			)
			*/
			 
			virtual bool signature_is_operation_reply(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			In the case when a Message with messageSort synchCall or asynchCall has a non empty Operation signature, the arguments of the Message must correspond to the in and inout parameters of the Operation. A Parameter corresponds to an Argument if the Argument is of the same Class or a specialization of that of the Parameter.
			(messageSort = MessageSort::asynchCall or messageSort = MessageSort::synchCall) and signature.oclIsKindOf(Operation)  implies 
			 let requestParms : OrderedSet(Parameter) = signature.oclAsType(Operation).ownedParameter->
			 select(direction = ParameterDirectionKind::inout or direction = ParameterDirectionKind::_'in'  )
			in requestParms->size() = self.argument->size() and
			self.argument->forAll( o: ValueSpecification | 
			not (o.oclIsKindOf(Expression) and o.oclAsType(Expression).symbol->size()=0 and o.oclAsType(Expression).operand->isEmpty() ) implies 
			let p : Parameter = requestParms->at(self.argument->indexOf(o)) in
			o.type.oclAsType(Classifier).conformsTo(p.type.oclAsType(Classifier))
			)
			*/
			 
			virtual bool signature_is_operation_request(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			In the case when the Message signature is a Signal, the arguments of the Message must correspond to the attributes of the Signal. A Message Argument corresponds to a Signal Attribute if the Argument is of the same Class or a specialization of that of the Attribute.
			(messageSort = MessageSort::asynchSignal ) and signature.oclIsKindOf(Signal) implies
			   let signalAttributes : OrderedSet(Property) = signature.oclAsType(Signal).inheritedMember()->
			             select(n:NamedElement | n.oclIsTypeOf(Property))->collect(oclAsType(Property))->asOrderedSet()
			   in signalAttributes->size() = self.argument->size()
			   and self.argument->forAll( o: ValueSpecification |
			          not (o.oclIsKindOf(Expression)
			          and o.oclAsType(Expression).symbol->size()=0
			          and o.oclAsType(Expression).operand->isEmpty() ) implies
			              let p : Property = signalAttributes->at(self.argument->indexOf(o))
			              in o.type.oclAsType(Classifier).conformsTo(p.type.oclAsType(Classifier)))
			*/
			 
			virtual bool signature_is_signal(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The signature must either refer an Operation (in which case messageSort is either synchCall or asynchCall or reply) or a Signal (in which case messageSort is asynchSignal). The name of the NamedElement referenced by signature must be the same as that of the Message.
			signature->notEmpty() implies 
			((signature.oclIsKindOf(Operation) and 
			(messageSort = MessageSort::asynchCall or messageSort = MessageSort::synchCall or messageSort = MessageSort::reply) 
			) or (signature.oclIsKindOf(Signal)  and messageSort = MessageSort::asynchSignal )
			 ) and name = signature.name
			*/
			 
			virtual bool signature_refer_to(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			The derived kind of the Message (complete, lost, found, or unknown).
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual uml::MessageKind getMessageKind() const = 0;
			
			/*!
			The sort of communication reflected by the Message.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual uml::MessageSort getMessageSort() const = 0;
			/*!
			The sort of communication reflected by the Message.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual void setMessageSort (uml::MessageSort _messageSort)= 0;
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The arguments of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> getArgument() const = 0;
			
			/*!
			The Connector on which this Message is sent.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::Connector> getConnector() const = 0;
			/*!
			The Connector on which this Message is sent.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setConnector(std::shared_ptr<uml::Connector>) = 0;
			/*!
			The enclosing Interaction owning the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::weak_ptr<uml::Interaction> getInteraction() const = 0;
			/*!
			The enclosing Interaction owning the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setInteraction(std::weak_ptr<uml::Interaction>) = 0;
			/*!
			References the Receiving of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::MessageEnd> getReceiveEvent() const = 0;
			/*!
			References the Receiving of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setReceiveEvent(std::shared_ptr<uml::MessageEnd>) = 0;
			/*!
			References the Sending of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::MessageEnd> getSendEvent() const = 0;
			/*!
			References the Sending of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setSendEvent(std::shared_ptr<uml::MessageEnd>) = 0;
			/*!
			The signature of the Message is the specification of its content. It refers either an Operation or a Signal.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::NamedElement> getSignature() const = 0;
			/*!
			The signature of the Message is the specification of its content. It refers either an Operation or a Signal.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setSignature(std::shared_ptr<uml::NamedElement>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			The derived kind of the Message (complete, lost, found, or unknown).
			<p>From package UML::Interactions.</p>
			*/
			 
			uml::MessageKind m_messageKind = MessageKind::UNKNOWN;
			/*!
			The sort of communication reflected by the Message.
			<p>From package UML::Interactions.</p>
			*/
			 
			uml::MessageSort m_messageSort = MessageSort::SYNCHCALL;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The arguments of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> m_argument;/*!
			The Connector on which this Message is sent.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::Connector> m_connector;/*!
			The enclosing Interaction owning the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			std::weak_ptr<uml::Interaction> m_interaction;/*!
			References the Receiving of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::MessageEnd> m_receiveEvent;/*!
			References the Sending of the Message.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::MessageEnd> m_sendEvent;/*!
			The signature of the Message is the specification of its content. It refers either an Operation or a Signal.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::NamedElement> m_signature;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_MESSAGE_HPP */
