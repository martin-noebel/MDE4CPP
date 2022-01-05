//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INFORMATIONFLOWINFORMATIONFLOWIMPL_HPP
#define UML_INFORMATIONFLOWINFORMATIONFLOWIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InformationFlow.hpp"

#include "uml/impl/DirectedRelationshipImpl.hpp"
#include "uml/impl/PackageableElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InformationFlowImpl : virtual public DirectedRelationshipImpl, virtual public PackageableElementImpl, virtual public InformationFlow 
	{
		public: 
			InformationFlowImpl(const InformationFlowImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InformationFlowImpl& operator=(InformationFlowImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InformationFlowImpl();
			virtual std::shared_ptr<uml::InformationFlow> getThisInformationFlowPtr() const;
			virtual void setThisInformationFlowPtr(std::weak_ptr<uml::InformationFlow> thisInformationFlowPtr);

			//Additional constructors for the containments back reference
			InformationFlowImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InformationFlowImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			InformationFlowImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			InformationFlowImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~InformationFlowImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			An information flow can only convey classifiers that are allowed to represent an information item.
			self.conveyed->forAll(oclIsKindOf(Class) or oclIsKindOf(Interface)
			  or oclIsKindOf(InformationItem) or oclIsKindOf(Signal) or oclIsKindOf(Component))
			*/
			 
			virtual bool convey_classifiers(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The sources and targets of the information flow must conform to the sources and targets or conversely the targets and sources of the realization relationships.
			*/
			 
			virtual bool must_conform(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
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
			(oclIsKindOf(InstanceSpecification) and not sit.oclAsType(InstanceSpecification).classifier->exists(oclIsKindOf(Relationship)))))
			*/
			 
			virtual bool sources_and_targets_kind(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Specifies the information items that may circulate on this information flow.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getConveyed() const ;
			/*!
			Defines from which source the conveyed InformationItems are initiated.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::NamedElement, uml::Element>> getInformationSource() const ;
			/*!
			Defines to which target the conveyed InformationItems are directed.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::NamedElement, uml::Element>> getInformationTarget() const ;
			/*!
			Determines which Relationship will realize the specified flow.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Relationship>> getRealization() const ;
			/*!
			Determines which ActivityEdges will realize the specified flow.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ActivityEdge>> getRealizingActivityEdge() const ;
			/*!
			Determines which Connectors will realize the specified flow.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Connector>> getRealizingConnector() const ;
			/*!
			Determines which Messages will realize the specified flow.
			<p>From package UML::InformationFlows.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Message>> getRealizingMessage() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const ;
			/*!
			Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const ;
			/*!
			Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const ;
			
			
			//*********************************
			// Container Getter
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

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::InformationFlow> m_thisInformationFlowPtr;
	};
}
#endif /* end of include guard: UML_INFORMATIONFLOWINFORMATIONFLOWIMPL_HPP */