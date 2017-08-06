//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIVITYEDGEACTIVITYEDGEIMPL_HPP
#define UML_ACTIVITYEDGEACTIVITYEDGEIMPL_HPP

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
#include "../ActivityEdge.hpp"

#include "impl/RedefinableElementImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class ActivityEdgeImpl :virtual public RedefinableElementImpl, virtual public ActivityEdge 
	{
		public: 
			ActivityEdgeImpl(const ActivityEdgeImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ActivityEdgeImpl& operator=(ActivityEdgeImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ActivityEdgeImpl();

		public:
			//destructor
			virtual ~ActivityEdgeImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 If an ActivityEdge is directly owned by an Activity, then its source and target must be directly or indirectly contained in the same Activity.
			activity<>null implies source.containingActivity() = activity and target.containingActivity() = activity */ 
			virtual bool
			 source_and_target(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The Activity containing the ActivityEdge, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<uml::Activity > getActivity() const ;
			
			/*!
			 The Activity containing the ActivityEdge, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p> */
			virtual void setActivity(std::shared_ptr<uml::Activity> _activity_activity) ;
			/*!
			 A ValueSpecification that is evaluated to determine if a token can traverse the ActivityEdge. If an ActivityEdge has no guard, then there is no restriction on tokens traversing the edge.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<uml::ValueSpecification > getGuard() const ;
			
			/*!
			 A ValueSpecification that is evaluated to determine if a token can traverse the ActivityEdge. If an ActivityEdge has no guard, then there is no restriction on tokens traversing the edge.
			<p>From package UML::Activities.</p> */
			virtual void setGuard(std::shared_ptr<uml::ValueSpecification> _guard_guard) ;
			/*!
			 ActivityPartitions containing the ActivityEdge.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup > >
			 getInPartition() const ;
			
			/*!
			 The InterruptibleActivityRegion for which this ActivityEdge is an interruptingEdge.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<uml::InterruptibleActivityRegion > getInterrupts() const ;
			
			/*!
			 The InterruptibleActivityRegion for which this ActivityEdge is an interruptingEdge.
			<p>From package UML::Activities.</p> */
			virtual void setInterrupts(std::shared_ptr<uml::InterruptibleActivityRegion> _interrupts_interrupts) ;
			/*!
			 The StructuredActivityNode containing the ActivityEdge, if it is owned by a StructuredActivityNode.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<uml::StructuredActivityNode > getInStructuredNode() const ;
			
			/*!
			 The StructuredActivityNode containing the ActivityEdge, if it is owned by a StructuredActivityNode.
			<p>From package UML::Activities.</p> */
			virtual void setInStructuredNode(std::shared_ptr<uml::StructuredActivityNode> _inStructuredNode_inStructuredNode) ;
			/*!
			 The ActivityNode to which tokens are put when they traverse the ActivityEdge.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<uml::ActivityNode > getTarget() const ;
			
			/*!
			 The ActivityNode to which tokens are put when they traverse the ActivityEdge.
			<p>From package UML::Activities.</p> */
			virtual void setTarget(std::shared_ptr<uml::ActivityNode> _target_target) ;
			/*!
			 The ActivityNode from which tokens are taken when they traverse the ActivityEdge.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<uml::ActivityNode > getSource() const ;
			
			/*!
			 The ActivityNode from which tokens are taken when they traverse the ActivityEdge.
			<p>From package UML::Activities.</p> */
			virtual void setSource(std::shared_ptr<uml::ActivityNode> _source_source) ;
			/*!
			 ActivityEdges from a generalization of the Activity containing this ActivityEdge that are redefined by this ActivityEdge.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Subset<uml::ActivityEdge, uml::RedefinableElement > >
			 getRedefinedEdge() const ;
			
			/*!
			 The minimum number of tokens that must traverse the ActivityEdge at the same time. If no weight is specified, this is equivalent to specifying a constant value of 1.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<uml::ValueSpecification > getWeight() const ;
			
			/*!
			 The minimum number of tokens that must traverse the ActivityEdge at the same time. If no weight is specified, this is equivalent to specifying a constant value of 1.
			<p>From package UML::Activities.</p> */
			virtual void setWeight(std::shared_ptr<uml::ValueSpecification> _weight_weight) ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 ActivityGroups containing the ActivityEdge.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Union<uml::ActivityGroup> > getInGroup() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Union<uml::RedefinableElement> > getRedefinedElement() const ;/*!
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
#endif /* end of include guard: UML_ACTIVITYEDGEACTIVITYEDGEIMPL_HPP */

