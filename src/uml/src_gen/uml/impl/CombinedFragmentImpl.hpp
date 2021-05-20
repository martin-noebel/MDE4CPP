//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_COMBINEDFRAGMENTCOMBINEDFRAGMENTIMPL_HPP
#define UML_COMBINEDFRAGMENTCOMBINEDFRAGMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../CombinedFragment.hpp"

#include "uml/impl/InteractionFragmentImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API CombinedFragmentImpl : virtual public InteractionFragmentImpl, virtual public CombinedFragment 
	{
		public: 
			CombinedFragmentImpl(const CombinedFragmentImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CombinedFragmentImpl& operator=(CombinedFragmentImpl const&); 

		protected:
			friend class umlFactoryImpl;
			CombinedFragmentImpl();
			virtual std::shared_ptr<CombinedFragment> getThisCombinedFragmentPtr() const;
			virtual void setThisCombinedFragmentPtr(std::weak_ptr<CombinedFragment> thisCombinedFragmentPtr);

			//Additional constructors for the containments back reference
			CombinedFragmentImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			CombinedFragmentImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			CombinedFragmentImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			CombinedFragmentImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~CombinedFragmentImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			If the interactionOperator is break, the corresponding InteractionOperand must cover all Lifelines covered by the enclosing InteractionFragment.
			interactionOperator=InteractionOperatorKind::break  implies   
			enclosingInteraction.oclAsType(InteractionFragment)->asSet()->union(
			   enclosingOperand.oclAsType(InteractionFragment)->asSet()).covered->asSet() = self.covered->asSet()
			*/
			 
			virtual bool break_(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			The interaction operators 'consider' and 'ignore' can only be used for the ConsiderIgnoreFragment subtype of CombinedFragment
			((interactionOperator = InteractionOperatorKind::consider) or (interactionOperator =  InteractionOperatorKind::ignore)) implies oclIsKindOf(ConsiderIgnoreFragment)
			*/
			 
			virtual bool consider_and_ignore(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			If the interactionOperator is opt, loop, break, assert or neg, there must be exactly one operand.
			(interactionOperator =  InteractionOperatorKind::opt or interactionOperator = InteractionOperatorKind::loop or
			interactionOperator = InteractionOperatorKind::break or interactionOperator = InteractionOperatorKind::assert or
			interactionOperator = InteractionOperatorKind::neg)
			implies operand->size()=1
			*/
			 
			virtual bool opt_loop_break_neg(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			Specifies the operation which defines the semantics of this combination of InteractionFragments.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual uml::InteractionOperatorKind getInteractionOperator() const ;
			/*!
			Specifies the operation which defines the semantics of this combination of InteractionFragments.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual void setInteractionOperator (uml::InteractionOperatorKind _interactionOperator);
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			Specifies the gates that form the interface between this CombinedFragment and its surroundings
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Gate, uml::Element>> getCfragmentGate() const ;
			
			/*!
			The set of operands of the combined fragment.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::InteractionOperand, uml::Element>> getOperand() const ;
			
			
			
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
			std::weak_ptr<CombinedFragment> m_thisCombinedFragmentPtr;
	};
}
#endif /* end of include guard: UML_COMBINEDFRAGMENTCOMBINEDFRAGMENTIMPL_HPP */
