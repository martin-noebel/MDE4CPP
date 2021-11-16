//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_COMBINEDFRAGMENT_HPP
#define UML_COMBINEDFRAGMENT_HPP

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
	class Dependency;
	class Gate;
	class GeneralOrdering;
	class Interaction;
	class InteractionOperand;
	class Lifeline;
	class Namespace;
	class StringExpression;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/InteractionFragment.hpp"

// enum includes
#include "uml/InteractionOperatorKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A CombinedFragment defines an expression of InteractionFragments. A CombinedFragment is defined by an interaction operator and corresponding InteractionOperands. Through the use of CombinedFragments the user will be able to describe a number of traces in a compact and concise manner.
	<p>From package UML::Interactions.</p>
	*/
	
	class UML_API CombinedFragment: virtual public InteractionFragment
	{
		public:
 			CombinedFragment(const CombinedFragment &) {}

		protected:
			CombinedFragment(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CombinedFragment() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			If the interactionOperator is break, the corresponding InteractionOperand must cover all Lifelines covered by the enclosing InteractionFragment.
			interactionOperator=InteractionOperatorKind::break  implies   
			enclosingInteraction.oclAsType(InteractionFragment)->asSet()->union(
			   enclosingOperand.oclAsType(InteractionFragment)->asSet()).covered->asSet() = self.covered->asSet()
			*/
			 
			virtual bool break_(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			The interaction operators 'consider' and 'ignore' can only be used for the ConsiderIgnoreFragment subtype of CombinedFragment
			((interactionOperator = InteractionOperatorKind::consider) or (interactionOperator =  InteractionOperatorKind::ignore)) implies oclIsKindOf(ConsiderIgnoreFragment)
			*/
			 
			virtual bool consider_and_ignore(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			/*!
			If the interactionOperator is opt, loop, break, assert or neg, there must be exactly one operand.
			(interactionOperator =  InteractionOperatorKind::opt or interactionOperator = InteractionOperatorKind::loop or
			interactionOperator = InteractionOperatorKind::break or interactionOperator = InteractionOperatorKind::assert or
			interactionOperator = InteractionOperatorKind::neg)
			implies operand->size()=1
			*/
			 
			virtual bool opt_loop_break_neg(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies the operation which defines the semantics of this combination of InteractionFragments.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual uml::InteractionOperatorKind getInteractionOperator() const = 0;
			/*!
			Specifies the operation which defines the semantics of this combination of InteractionFragments.
			<p>From package UML::Interactions.</p>
			*/
			 
			virtual void setInteractionOperator (uml::InteractionOperatorKind _interactionOperator)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Specifies the gates that form the interface between this CombinedFragment and its surroundings
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Gate, uml::Element>> getCfragmentGate() const = 0;
			/*!
			The set of operands of the combined fragment.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::InteractionOperand, uml::Element>> getOperand() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;
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
			/*!
			Specifies the operation which defines the semantics of this combination of InteractionFragments.
			<p>From package UML::Interactions.</p>
			*/
			
			uml::InteractionOperatorKind m_interactionOperator= uml::InteractionOperatorKind::SEQ;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			Specifies the gates that form the interface between this CombinedFragment and its surroundings
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Gate, uml::Element>> m_cfragmentGate;
			/*!
			The set of operands of the combined fragment.
			<p>From package UML::Interactions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::InteractionOperand, uml::Element>> m_operand;
	};
}
#endif /* end of include guard: UML_COMBINEDFRAGMENT_HPP */
