//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REPLYACTIONREPLYACTIONIMPL_HPP
#define UML_REPLYACTIONREPLYACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ReplyAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class ReplyActionImpl : virtual public ActionImpl, virtual public ReplyAction 
	{
		public: 
			ReplyActionImpl(const ReplyActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReplyActionImpl& operator=(ReplyActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ReplyActionImpl();
			virtual std::shared_ptr<ReplyAction> getThisReplyActionPtr() const;
			virtual void setThisReplyActionPtr(std::weak_ptr<ReplyAction> thisReplyActionPtr);

			//Additional constructors for the containments back reference
			ReplyActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ReplyActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ReplyActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ReplyActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ReplyActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The event of the replyToCall Trigger must be a CallEvent.
			replyToCall.event.oclIsKindOf(CallEvent)
			*/
			 
			virtual bool event_on_reply_to_call_trigger(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			The replyValue InputPins must match the output (return, out, and inout) parameters of the operation of the event of the replyToCall Trigger in number, type, ordering, and multiplicity.
			let parameter:OrderedSet(Parameter) = replyToCall.event.oclAsType(CallEvent).operation.outputParameters() in
			replyValue->size()=parameter->size() and
			Sequence{1..replyValue->size()}->forAll(i |
				replyValue->at(i).type.conformsTo(parameter->at(i).type) and
				replyValue->at(i).isOrdered=parameter->at(i).isOrdered and
				replyValue->at(i).compatibleWith(parameter->at(i)))
			*/
			 
			virtual bool pins_match_parameter(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The Trigger specifying the Operation whose call is being replied to.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Trigger> getReplyToCall() const ;
			/*!
			The Trigger specifying the Operation whose call is being replied to.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setReplyToCall(std::shared_ptr<uml::Trigger>) ;
			/*!
			A list of InputPins providing the values for the output (inout, out, and return) Parameters of the Operation. These values are returned to the caller.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> getReplyValue() const ;
			
			/*!
			An InputPin that holds the return information value produced by an earlier AcceptCallAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getReturnInformation() const ;
			/*!
			An InputPin that holds the return information value produced by an earlier AcceptCallAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setReturnInformation(std::shared_ptr<uml::InputPin>) ;
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ReplyAction> m_thisReplyActionPtr;
	};
}
#endif /* end of include guard: UML_REPLYACTIONREPLYACTIONIMPL_HPP */
