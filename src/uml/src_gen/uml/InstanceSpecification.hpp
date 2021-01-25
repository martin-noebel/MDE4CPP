//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INSTANCESPECIFICATION_HPP
#define UML_INSTANCESPECIFICATION_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;


class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

//*********************************
// generated Includes

#include <map>

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
	class Classifier;
	class Comment;
	class Dependency;
	class Deployment;
	class Namespace;
	class Package;
	class Slot;
	class StringExpression;
	class TemplateParameter;
	class ValueSpecification;
}

// base class includes
#include "uml/DeployedArtifact.hpp"

#include "uml/DeploymentTarget.hpp"

#include "uml/PackageableElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//Includes from codegen annotation

//*********************************
namespace uml 
{
	/*!
	An InstanceSpecification is a model element that represents an instance in a modeled system. An InstanceSpecification can act as a DeploymentTarget in a Deployment relationship, in the case that it represents an instance of a Node. It can also act as a DeployedArtifact, if it represents an instance of an Artifact.
	<p>From package UML::Classification.</p>
	*/
	
	class InstanceSpecification:virtual public DeployedArtifact,virtual public DeploymentTarget,virtual public PackageableElement
	{
		public:
 			InstanceSpecification(const InstanceSpecification &) {}
			InstanceSpecification& operator=(InstanceSpecification const&) = delete;

		protected:
			InstanceSpecification(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~InstanceSpecification() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The definingFeature of each slot is a StructuralFeature related to a classifier of the InstanceSpecification, including direct attributes, inherited attributes, private attributes in generalizations, and memberEnds of Associations, but excluding redefined StructuralFeatures.
			slot->forAll(s | classifier->exists (c | c.allSlottableFeatures()->includes (s.definingFeature)))
			*/
			 
			virtual bool defining_feature(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			An InstanceSpecification can act as a DeployedArtifact if it represents an instance of an Artifact.
			deploymentForArtifact->notEmpty() implies classifier->exists(oclIsKindOf(Artifact))
			*/
			 
			virtual bool deployment_artifact(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			An InstanceSpecification can act as a DeploymentTarget if it represents an instance of a Node and functions as a part in the internal structure of an encompassing Node.
			deployment->notEmpty() implies classifier->exists(node | node.oclIsKindOf(Node) and Node.allInstances()->exists(n | n.part->exists(p | p.type = node)))
			*/
			 
			virtual bool deployment_target(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			No more than one slot in an InstanceSpecification may have the same definingFeature.
			classifier->forAll(c | (c.allSlottableFeatures()->forAll(f | slot->select(s | s.definingFeature = f)->size() <= 1)))
			*/
			 
			virtual bool structural_feature(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			
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
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getClassifier() const = 0;
			
			
			/*!
			A Slot giving the value or values of a StructuralFeature of the instance. An InstanceSpecification can have one Slot per StructuralFeature of its Classifiers, including inherited features. It is not necessary to model a Slot for every StructuralFeature, in which case the InstanceSpecification is a partial description.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Slot, uml::Element>> getSlot() const = 0;
			
			
			/*!
			A specification of how to compute, derive, or construct the instance.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification > getSpecification() const = 0;
			
			/*!
			A specification of how to compute, derive, or construct the instance.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setSpecification(std::shared_ptr<uml::ValueSpecification> _specification) = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The Classifier or Classifiers of the represented instance. If multiple Classifiers are specified, the instance is classified by all of them.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Classifier>> m_classifier;/*!
			A Slot giving the value or values of a StructuralFeature of the instance. An InstanceSpecification can have one Slot per StructuralFeature of its Classifiers, including inherited features. It is not necessary to model a Slot for every StructuralFeature, in which case the InstanceSpecification is a partial description.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Slot, uml::Element>> m_slot;/*!
			A specification of how to compute, derive, or construct the instance.
			<p>From package UML::Classification.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification > m_specification;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace > getNamespace() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_INSTANCESPECIFICATION_HPP */
