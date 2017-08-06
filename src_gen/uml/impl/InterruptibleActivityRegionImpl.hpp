//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERRUPTIBLEACTIVITYREGIONINTERRUPTIBLEACTIVITYREGIONIMPL_HPP
#define UML_INTERRUPTIBLEACTIVITYREGIONINTERRUPTIBLEACTIVITYREGIONIMPL_HPP

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
#include "../InterruptibleActivityRegion.hpp"

#include "impl/ActivityGroupImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class InterruptibleActivityRegionImpl :virtual public ActivityGroupImpl, virtual public InterruptibleActivityRegion 
	{
		public: 
			InterruptibleActivityRegionImpl(const InterruptibleActivityRegionImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			InterruptibleActivityRegionImpl& operator=(InterruptibleActivityRegionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			InterruptibleActivityRegionImpl();

		public:
			//destructor
			virtual ~InterruptibleActivityRegionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The interruptingEdges of an InterruptibleActivityRegion must have their source in the region and their target outside the region, but within the same Activity containing the region.
			interruptingEdge->forAll(edge | 
			  node->includes(edge.source) and node->excludes(edge.target) and edge.target.containingActivity() = inActivity) */ 
			virtual bool
			 interrupting_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The ActivityEdges leaving the InterruptibleActivityRegion on which a traversing token will result in the termination of other tokens flowing in the InterruptibleActivityRegion.
			<p>From package UML::Activities.</p> */
			virtual 	std::shared_ptr< Bag<uml::ActivityEdge> >
			 getInterruptingEdge() const ;
			
			/*!
			 ActivityNodes immediately contained in the InterruptibleActivityRegion.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode > >
			 getNode() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityNodes immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Union<uml::ActivityNode> > getContainedNode() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
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
#endif /* end of include guard: UML_INTERRUPTIBLEACTIVITYREGIONINTERRUPTIBLEACTIVITYREGIONIMPL_HPP */

