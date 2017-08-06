//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIVITYGROUPACTIVITYGROUPIMPL_HPP
#define UML_ACTIVITYGROUPACTIVITYGROUPIMPL_HPP

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
#include "../ActivityGroup.hpp"

#include "impl/ActivityContentImpl.hpp"
#include "impl/NamedElementImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class ActivityGroupImpl :virtual public ActivityContentImpl, virtual public NamedElementImpl, virtual public ActivityGroup 
	{
		public: 
			ActivityGroupImpl(const ActivityGroupImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ActivityGroupImpl& operator=(ActivityGroupImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ActivityGroupImpl();

		public:
			//destructor
			virtual ~ActivityGroupImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 All containedNodes and containeEdges of an ActivityGroup must be in the same Activity as the group.
			containedNode->forAll(activity = self.containingActivity()) and 
			containedEdge->forAll(activity = self.containingActivity()) */ 
			virtual bool
			 nodes_and_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 No containedNode or containedEdge of an ActivityGroup may be contained by its subgroups or its superGroups, transitively.
			subgroup->closure(subgroup).containedNode->excludesAll(containedNode) and
			superGroup->closure(superGroup).containedNode->excludesAll(containedNode) and 
			subgroup->closure(subgroup).containedEdge->excludesAll(containedEdge) and 
			superGroup->closure(superGroup).containedEdge->excludesAll(containedEdge) */ 
			virtual bool
			 not_contained(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			/*!
			 The Activity containing the ActivityGroup, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<uml::Activity > getInActivity() const ;
			
			/*!
			 The Activity containing the ActivityGroup, if it is directly owned by an Activity.
			<p>From package UML::Activities.</p> */
			virtual void setInActivity(std::shared_ptr<uml::Activity> _inActivity_inActivity) ;
			
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityNodes immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Union<uml::ActivityNode> > getContainedNode() const ;/*!
			 The ActivityGroup immediately containing this ActivityGroup, if it is directly owned by another ActivityGroup.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<uml::ActivityGroup > getSuperGroup() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 ActivityEdges immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Union<uml::ActivityEdge> > getContainedEdge() const ;/*!
			 Other ActivityGroups immediately contained in this ActivityGroup.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element > >
			 getSubgroup() const ;/*!
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
#endif /* end of include guard: UML_ACTIVITYGROUPACTIVITYGROUPIMPL_HPP */

