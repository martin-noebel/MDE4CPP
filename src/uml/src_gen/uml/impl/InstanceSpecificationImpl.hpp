//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INSTANCESPECIFICATIONINSTANCESPECIFICATIONIMPL_HPP
#define UML_INSTANCESPECIFICATIONINSTANCESPECIFICATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../InstanceSpecification.hpp"

#include "uml/impl/DeployedArtifactImpl.hpp"
#include "uml/impl/DeploymentTargetImpl.hpp"
#include "uml/impl/PackageableElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API InstanceSpecificationImpl : virtual public DeployedArtifactImpl, virtual public DeploymentTargetImpl, virtual public PackageableElementImpl, virtual public InstanceSpecification 
	{
		public: 
			InstanceSpecificationImpl(const InstanceSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			InstanceSpecificationImpl& operator=(InstanceSpecificationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			InstanceSpecificationImpl();
			virtual std::shared_ptr<InstanceSpecification> getThisInstanceSpecificationPtr() const;
			virtual void setThisInstanceSpecificationPtr(std::weak_ptr<InstanceSpecification> thisInstanceSpecificationPtr);

			//Additional constructors for the containments back reference
			InstanceSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			InstanceSpecificationImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			InstanceSpecificationImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			InstanceSpecificationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~InstanceSpecificationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The definingFeature of each slot is a StructuralFeature related to a classifier of the InstanceSpecification, including direct attributes, inherited attributes, private attributes in generalizations, and memberEnds of Associations, but excluding redefined StructuralFeatures.
			slot->forAll(s | classifier->exists (c | c.allSlottableFeatures()->includes (s.definingFeature)))
			*/
			 
			virtual bool defining_feature(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			An InstanceSpecification can act as a DeployedArtifact if it represents an instance of an Artifact.
			deploymentForArtifact->notEmpty() implies classifier->exists(oclIsKindOf(Artifact))
			*/
			 
			virtual bool deployment_artifact(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			An InstanceSpecification can act as a DeploymentTarget if it represents an instance of a Node and functions as a part in the internal structure of an encompassing Node.
			deployment->notEmpty() implies classifier->exists(node | node.oclIsKindOf(Node) and Node.allInstances()->exists(n | n.part->exists(p | p.type = node)))
			*/
			 
			virtual bool deployment_target(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			No more than one slot in an InstanceSpecification may have the same definingFeature.
			classifier->forAll(c | (c.allSlottableFeatures()->forAll(f | slot->select(s | s.definingFeature = f)->size() <= 1)))
			*/
			 
			virtual bool structural_feature(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The Classifier or Classifiers of the represented instance. If multiple Classifiers are specified, the instance is classified by all of them.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getClassifier() const ;
			
			/*!
			A Slot giving the value or values of a StructuralFeature of the instance. An InstanceSpecification can have one Slot per StructuralFeature of its Classifiers, including inherited features. It is not necessary to model a Slot for every StructuralFeature, in which case the InstanceSpecification is a partial description.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Slot, uml::Element>> getSlot() const ;
			
			/*!
			A specification of how to compute, derive, or construct the instance.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getSpecification() const ;
			/*!
			A specification of how to compute, derive, or construct the instance.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setSpecification(std::shared_ptr<uml::ValueSpecification>) ;
			
			
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
			std::weak_ptr<InstanceSpecification> m_thisInstanceSpecificationPtr;
	};
}
#endif /* end of include guard: UML_INSTANCESPECIFICATIONINSTANCESPECIFICATIONIMPL_HPP */
