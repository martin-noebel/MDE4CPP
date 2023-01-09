//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DEPLOYMENTSPECIFICATION_HPP
#define UML_DEPLOYMENTSPECIFICATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


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
	class CollaborationUse;
	class Comment;
	class Constraint;
	class Dependency;
	class Deployment;
	class ElementImport;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class Manifestation;
	class Operation;
	class Package;
	class PackageImport;
	class Property;
	class StringExpression;
	class Substitution;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class UseCase;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Artifact.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A deployment specification specifies a set of properties that determine execution parameters of a component artifact that is deployed on a node. A deployment specification can be aimed at a specific type of container. An artifact that reifies or implements deployment specification properties is a deployment descriptor.
	<p>From package UML::Deployments.</p>
	*/
	
	class UML_API DeploymentSpecification : virtual public Artifact
	{
		public:
 			DeploymentSpecification(const DeploymentSpecification &) {}

		protected:
			DeploymentSpecification(){}
			//Additional constructors for the containments back reference
			DeploymentSpecification(std::weak_ptr<uml::Deployment> par_deployment);

			//Additional constructors for the containments back reference
			DeploymentSpecification(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			DeploymentSpecification(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			DeploymentSpecification(std::weak_ptr<uml::Package> par_Package, const int reference_id);

			//Additional constructors for the containments back reference
			DeploymentSpecification(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

			//Additional constructors for the containments back reference

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~DeploymentSpecification() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The location where an Artifact is deployed onto a Node. This is typically a 'directory' or 'memory address.'
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual std::string getDeploymentLocation() const = 0;
			/*!
			The location where an Artifact is deployed onto a Node. This is typically a 'directory' or 'memory address.'
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual void setDeploymentLocation (std::string _deploymentLocation)= 0;
			/*!
			The location where a component Artifact executes. This may be a local or remote location.
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual std::string getExecutionLocation() const = 0;
			/*!
			The location where a component Artifact executes. This may be a local or remote location.
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual void setExecutionLocation (std::string _executionLocation)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The deployment with which the DeploymentSpecification is associated.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::weak_ptr<uml::Deployment> getDeployment() const = 0;
			/*!
			The deployment with which the DeploymentSpecification is associated.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual void setDeployment(std::weak_ptr<uml::Deployment>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

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
			The location where an Artifact is deployed onto a Node. This is typically a 'directory' or 'memory address.'
			<p>From package UML::Deployments.</p>
			*/
			
			std::string m_deploymentLocation= "";
			/*!
			The location where a component Artifact executes. This may be a local or remote location.
			<p>From package UML::Deployments.</p>
			*/
			
			std::string m_executionLocation= "";
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The deployment with which the DeploymentSpecification is associated.
			<p>From package UML::Deployments.</p>
			*/
			
			std::weak_ptr<uml::Deployment> m_deployment;
	};
}
#endif /* end of include guard: UML_DEPLOYMENTSPECIFICATION_HPP */
