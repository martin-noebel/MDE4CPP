//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXPANSIONREGIONEXPANSIONREGIONIMPL_HPP
#define UML_EXPANSIONREGIONEXPANSIONREGIONIMPL_HPP

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

//*********************************
// generated Includes

//Model includes
#include "../ExpansionRegion.hpp"

#include "impl/StructuredActivityNodeImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class ExpansionRegionImpl :virtual public StructuredActivityNodeImpl, virtual public ExpansionRegion 
	{
		public: 
			ExpansionRegionImpl(const ExpansionRegionImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ExpansionRegionImpl& operator=(ExpansionRegionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ExpansionRegionImpl();

		public:
			//destructor
			virtual ~ExpansionRegionImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 The mode in which the ExpansionRegion executes its contents. If parallel, executions are concurrent. If iterative, executions are sequential. If stream, a stream of values flows into a single execution.
			<p>From package UML::Actions.</p> */ 
			virtual ExpansionKind getMode() const ;
			
			/*!
			 The mode in which the ExpansionRegion executes its contents. If parallel, executions are concurrent. If iterative, executions are sequential. If stream, a stream of values flows into a single execution.
			<p>From package UML::Actions.</p> */ 
			virtual void setMode (ExpansionKind _mode); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The ExpansionNodes that form the output collections of the ExpansionRegion.
			<p>From package UML::Actions.</p> */
			virtual 	std::shared_ptr< Bag<uml::ExpansionNode> >
			 getOutputElement() const ;
			
			/*!
			 The ExpansionNodes that hold the input collections for the ExpansionRegion.
			<p>From package UML::Actions.</p> */
			virtual 	std::shared_ptr< Bag<uml::ExpansionNode> >
			 getInputElement() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityNodes immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Union<uml::ActivityNode> > getContainedNode() const ;/*!
			 The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
			 getInput() const ;/*!
			 A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::NamedElement> > getMember() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 ActivityEdges immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Union<uml::ActivityEdge> > getContainedEdge() const ;/*!
			 The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > >
			 getOutput() const ;/*!
			 A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > >
			 getOwnedMember() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Union<uml::RedefinableElement> > getRedefinedElement() const ;/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Union<uml::ActivityGroup> > getInGroup() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Element > getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: UML_EXPANSIONREGIONEXPANSIONREGIONIMPL_HPP */

