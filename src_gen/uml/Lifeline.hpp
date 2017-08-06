//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LIFELINE_HPP
#define UML_LIFELINE_HPP

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
	class ConnectableElement;
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
	class Interaction;
}

namespace uml 
{
	class InteractionFragment;
}

namespace uml 
{
	class NamedElement;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class PartDecomposition;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class ValueSpecification;
}

// base class includes
#include "NamedElement.hpp"

// enum includes
#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A Lifeline represents an individual participant in the Interaction. While parts and structural features may have multiplicity greater than 1, Lifelines represent only one interacting entity.
	<p>From package UML::Interactions.</p> */
	class Lifeline:virtual public NamedElement	{
		public:
 			Lifeline(const Lifeline &) {}
			Lifeline& operator=(Lifeline const&) = delete;
	
		protected:
			Lifeline(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~Lifeline() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 The selector for a Lifeline must only be specified if the referenced Part is multivalued.
			 self.selector->notEmpty() = (self.represents.oclIsKindOf(MultiplicityElement) and self.represents.oclAsType(MultiplicityElement).isMultivalued()) */ 
			virtual bool
			 selector_specified(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 If a lifeline is in an Interaction referred to by an InteractionUse in an enclosing Interaction,  and that lifeline is common with another lifeline in an Interaction referred to by another InteractonUse within that same enclosing Interaction, it must be common to a lifeline within that enclosing Interaction. By common Lifelines we mean Lifelines with the same selector and represents associations.
			let intUses : Set(InteractionUse) = interaction.interactionUse  in 
			intUses->forAll
			( iuse : InteractionUse | 
			let usingInteraction : Set(Interaction)  = iuse.enclosingInteraction->asSet()
			->union(
			iuse.enclosingOperand.combinedFragment->asSet()->closure(enclosingOperand.combinedFragment).enclosingInteraction->asSet()
			               ) 
			in
			let peerUses : Set(InteractionUse) = usingInteraction.fragment->select(oclIsKindOf(InteractionUse)).oclAsType(InteractionUse)->asSet()
			->union(
			usingInteraction.fragment->select(oclIsKindOf(CombinedFragment)).oclAsType(CombinedFragment)->asSet()
			->closure(operand.fragment->select(oclIsKindOf(CombinedFragment)).oclAsType(CombinedFragment)).operand.fragment->
			select(oclIsKindOf(InteractionUse)).oclAsType(InteractionUse)->asSet()
			               )->excluding(iuse)
			 in
			peerUses->forAll( peerUse : InteractionUse |
			 peerUse.refersTo.lifeline->forAll( l : Lifeline | (l.represents = self.represents and 
			 ( self.selector.oclIsKindOf(LiteralString) implies
			  l.selector.oclIsKindOf(LiteralString) and 
			  self.selector.oclAsType(LiteralString).value = l.selector.oclAsType(LiteralString).value )
			  and 
			( self.selector.oclIsKindOf(LiteralInteger) implies
			  l.selector.oclIsKindOf(LiteralInteger) and 
			  self.selector.oclAsType(LiteralInteger).value = l.selector.oclAsType(LiteralInteger).value )
			)  
			implies
			 usingInteraction.lifeline->exists(represents = self.represents and
			 ( self.selector.oclIsKindOf(LiteralString) implies
			  l.selector.oclIsKindOf(LiteralString) and 
			  self.selector.oclAsType(LiteralString).value = l.selector.oclAsType(LiteralString).value )
			and 
			( self.selector.oclIsKindOf(LiteralInteger) implies
			  l.selector.oclIsKindOf(LiteralInteger) and 
			  self.selector.oclAsType(LiteralInteger).value = l.selector.oclAsType(LiteralInteger).value )
			)
			                                                )
			                    )
			) */ 
			virtual bool
			 interaction_uses_share_lifeline(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The classifier containing the referenced ConnectableElement must be the same classifier, or an ancestor, of the classifier that contains the interaction enclosing this lifeline.
			represents.namespace->closure(namespace)->includes(interaction._'context') */ 
			virtual bool
			 same_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The selector value, if present, must be a LiteralString or a LiteralInteger
			self.selector->notEmpty() implies 
			self.selector.oclIsKindOf(LiteralInteger) or 
			self.selector.oclIsKindOf(LiteralString) */ 
			virtual bool
			 selector_int_or_string(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 References the Interaction that represents the decomposition.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<uml::PartDecomposition > getDecomposedAs() const = 0;
			
			/*!
			 References the Interaction that represents the decomposition.
			<p>From package UML::Interactions.</p> */
			virtual void setDecomposedAs(std::shared_ptr<uml::PartDecomposition> _decomposedAs_decomposedAs) = 0;
			/*!
			 References the Interaction enclosing this Lifeline.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<uml::Interaction > getInteraction() const = 0;
			
			/*!
			 References the Interaction enclosing this Lifeline.
			<p>From package UML::Interactions.</p> */
			virtual void setInteraction(std::shared_ptr<uml::Interaction> _interaction_interaction) = 0;
			/*!
			 References the ConnectableElement within the classifier that contains the enclosing interaction.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<uml::ConnectableElement > getRepresents() const = 0;
			
			/*!
			 References the ConnectableElement within the classifier that contains the enclosing interaction.
			<p>From package UML::Interactions.</p> */
			virtual void setRepresents(std::shared_ptr<uml::ConnectableElement> _represents_represents) = 0;
			/*!
			 If the referenced ConnectableElement is multivalued, then this specifies the specific individual part within that set.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<uml::ValueSpecification > getSelector() const = 0;
			
			/*!
			 If the referenced ConnectableElement is multivalued, then this specifies the specific individual part within that set.
			<p>From package UML::Interactions.</p> */
			virtual void setSelector(std::shared_ptr<uml::ValueSpecification> _selector_selector) = 0;
			/*!
			 References the InteractionFragments in which this Lifeline takes part.
			<p>From package UML::Interactions.</p> */
			virtual 	std::shared_ptr< Bag<uml::InteractionFragment> >
			 getCoveredBy() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 References the Interaction that represents the decomposition.
			<p>From package UML::Interactions.</p> */
			std::shared_ptr<uml::PartDecomposition > m_decomposedAs;
			/*!
			 References the Interaction enclosing this Lifeline.
			<p>From package UML::Interactions.</p> */
			std::shared_ptr<uml::Interaction > m_interaction;
			/*!
			 References the ConnectableElement within the classifier that contains the enclosing interaction.
			<p>From package UML::Interactions.</p> */
			std::shared_ptr<uml::ConnectableElement > m_represents;
			/*!
			 If the referenced ConnectableElement is multivalued, then this specifies the specific individual part within that set.
			<p>From package UML::Interactions.</p> */
			std::shared_ptr<uml::ValueSpecification > m_selector;
			/*!
			 References the InteractionFragments in which this Lifeline takes part.
			<p>From package UML::Interactions.</p> */
				std::shared_ptr< Bag<uml::InteractionFragment> >
			 m_coveredBy;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Element > getOwner() const = 0;/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Namespace > getNamespace() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const = 0; 
	};

}
#endif /* end of include guard: UML_LIFELINE_HPP */

