//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INFORMATIONFLOWINFORMATIONFLOWIMPL_HPP
#define UML_INFORMATIONFLOWINFORMATIONFLOWIMPL_HPP

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
#include "../InformationFlow.hpp"

#include "impl/DirectedRelationshipImpl.hpp"
#include "impl/PackageableElementImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class InformationFlowImpl :virtual public DirectedRelationshipImpl, virtual public PackageableElementImpl, virtual public InformationFlow 
	{
		public: 
			InformationFlowImpl(const InformationFlowImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			InformationFlowImpl& operator=(InformationFlowImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			InformationFlowImpl();

		public:
			//destructor
			virtual ~InformationFlowImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The sources and targets of the information flow must conform to the sources and targets or conversely the targets and sources of the realization relationships. */ 
			virtual bool
			 must_conform(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The sources and targets of the information flow can only be one of the following kind: Actor, Node, UseCase, Artifact, Class, Component, Port, Property, Interface, Package, ActivityNode, ActivityPartition,
			Behavior and InstanceSpecification except when its classifier is a relationship (i.e. it represents a link).
			(self.informationSource->forAll( sis |
			  oclIsKindOf(Actor) or oclIsKindOf(Node) or oclIsKindOf(UseCase) or oclIsKindOf(Artifact) or 
			  oclIsKindOf(Class) or oclIsKindOf(Component) or oclIsKindOf(Port) or oclIsKindOf(Property) or 
			  oclIsKindOf(Interface) or oclIsKindOf(Package) or oclIsKindOf(ActivityNode) or oclIsKindOf(ActivityPartition) or 
			  (oclIsKindOf(InstanceSpecification) and not sis.oclAsType(InstanceSpecification).classifier->exists(oclIsKindOf(Relationship))))) 
			
			and
			
			(self.informationTarget->forAll( sit | 
			  oclIsKindOf(Actor) or oclIsKindOf(Node) or oclIsKindOf(UseCase) or oclIsKindOf(Artifact) or 
			  oclIsKindOf(Class) or oclIsKindOf(Component) or oclIsKindOf(Port) or oclIsKindOf(Property) or 
			  oclIsKindOf(Interface) or oclIsKindOf(Package) or oclIsKindOf(ActivityNode) or oclIsKindOf(ActivityPartition) or 
			(oclIsKindOf(InstanceSpecification) and not sit.oclAsType(InstanceSpecification).classifier->exists(oclIsKindOf(Relationship))))) */ 
			virtual bool
			 sources_and_targets_kind(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 An information flow can only convey classifiers that are allowed to represent an information item.
			self.conveyed->forAll(oclIsKindOf(Class) or oclIsKindOf(Interface)
			  or oclIsKindOf(InformationItem) or oclIsKindOf(Signal) or oclIsKindOf(Component)) */ 
			virtual bool
			 convey_classifiers(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 Specifies the information items that may circulate on this information flow.
			<p>From package UML::InformationFlows.</p> */
			virtual 	std::shared_ptr< Bag<uml::Classifier> >
			 getConveyed() const ;
			
			/*!
			 Defines from which source the conveyed InformationItems are initiated.
			<p>From package UML::InformationFlows.</p> */
			virtual 		std::shared_ptr<Subset<uml::NamedElement, uml::Element > >
			 getInformationSource() const ;
			
			/*!
			 Defines to which target the conveyed InformationItems are directed.
			<p>From package UML::InformationFlows.</p> */
			virtual 		std::shared_ptr<Subset<uml::NamedElement, uml::Element > >
			 getInformationTarget() const ;
			
			/*!
			 Determines which Relationship will realize the specified flow.
			<p>From package UML::InformationFlows.</p> */
			virtual 	std::shared_ptr< Bag<uml::Relationship> >
			 getRealization() const ;
			
			/*!
			 Determines which ActivityEdges will realize the specified flow.
			<p>From package UML::InformationFlows.</p> */
			virtual 	std::shared_ptr< Bag<uml::ActivityEdge> >
			 getRealizingActivityEdge() const ;
			
			/*!
			 Determines which Connectors will realize the specified flow.
			<p>From package UML::InformationFlows.</p> */
			virtual 	std::shared_ptr< Bag<uml::Connector> >
			 getRealizingConnector() const ;
			
			/*!
			 Determines which Messages will realize the specified flow.
			<p>From package UML::InformationFlows.</p> */
			virtual 	std::shared_ptr< Bag<uml::Message> >
			 getRealizingMessage() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getRelatedElement() const ;/*!
			 Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
			 getTarget() const ;/*!
			 Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
			 getSource() const ;/*!
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
#endif /* end of include guard: UML_INFORMATIONFLOWINFORMATIONFLOWIMPL_HPP */

