//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONTINUATIONCONTINUATIONIMPL_HPP
#define UML_CONTINUATIONCONTINUATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Continuation.hpp"

#include "uml/impl/InteractionFragmentImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ContinuationImpl : virtual public InteractionFragmentImpl, virtual public Continuation 
	{
		public: 
			ContinuationImpl(const ContinuationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ContinuationImpl& operator=(ContinuationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ContinuationImpl();
			virtual std::shared_ptr<Continuation> getThisContinuationPtr() const;
			virtual void setThisContinuationPtr(std::weak_ptr<Continuation> thisContinuationPtr);

			//Additional constructors for the containments back reference
			ContinuationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			ContinuationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			ContinuationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ContinuationImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ContinuationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Continuations always occur as the very first InteractionFragment or the very last InteractionFragment of the enclosing InteractionOperand.
			 enclosingOperand->notEmpty() and 
			 let peerFragments : OrderedSet(InteractionFragment) =  enclosingOperand.fragment in 
			   ( peerFragments->notEmpty() and 
			   ((peerFragments->first() = self) or  (peerFragments->last() = self)))
			*/
			 
			virtual bool first_or_last_interaction_fragment(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			Continuations are always global in the enclosing InteractionFragment e.g., it always covers all Lifelines covered by the enclosing InteractionOperator.
			enclosingOperand->notEmpty() and
			  let operandLifelines : Set(Lifeline) =  enclosingOperand.covered in 
			    (operandLifelines->notEmpty() and 
			    operandLifelines->forAll(ol :Lifeline |self.covered->includes(ol)))
			*/
			 
			virtual bool global(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			Across all Interaction instances having the same context value, every Lifeline instance covered by a Continuation (self) must be common with one covered Lifeline instance of all other Continuation instances with the same name as self, and every Lifeline instance covered by a Continuation instance with the same name as self must be common with one covered Lifeline instance of self. Lifeline instances are common if they have the same selector and represents associationEnd values.
			enclosingOperand.combinedFragment->notEmpty() and
			let parentInteraction : Set(Interaction) = 
			enclosingOperand.combinedFragment->closure(enclosingOperand.combinedFragment)->
			collect(enclosingInteraction).oclAsType(Interaction)->asSet()
			in 
			(parentInteraction->size() = 1) 
			and let peerInteractions : Set(Interaction) =
			 (parentInteraction->union(parentInteraction->collect(_'context')->collect(behavior)->
			 select(oclIsKindOf(Interaction)).oclAsType(Interaction)->asSet())->asSet()) in
			 (peerInteractions->notEmpty()) and 
			  let combinedFragments1 : Set(CombinedFragment) = peerInteractions.fragment->
			 select(oclIsKindOf(CombinedFragment)).oclAsType(CombinedFragment)->asSet() in
			   combinedFragments1->notEmpty() and  combinedFragments1->closure(operand.fragment->
			   select(oclIsKindOf(CombinedFragment)).oclAsType(CombinedFragment))->asSet().operand.fragment->
			   select(oclIsKindOf(Continuation)).oclAsType(Continuation)->asSet()->
			   forAll(c : Continuation |  (c.name = self.name) implies 
			  (c.covered->asSet()->forAll(cl : Lifeline | --  cl must be common to one lifeline covered by self
			  self.covered->asSet()->
			  select(represents = cl.represents and selector = cl.selector)->asSet()->size()=1))
			   and
			 (self.covered->asSet()->forAll(cl : Lifeline | --  cl must be common to one lifeline covered by c
			 c.covered->asSet()->
			  select(represents = cl.represents and selector = cl.selector)->asSet()->size()=1))
			  )
			*/
			 
			virtual bool same_name(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			True: when the Continuation is at the end of the enclosing InteractionFragment and False when it is in the beginning.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual bool getSetting() const ;
			/*!
			True: when the Continuation is at the end of the enclosing InteractionFragment and False when it is in the beginning.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual void setSetting (bool _setting);
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ; 
			 
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<Continuation> m_thisContinuationPtr;
	};
}
#endif /* end of include guard: UML_CONTINUATIONCONTINUATIONIMPL_HPP */
