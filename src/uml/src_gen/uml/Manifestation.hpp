//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_MANIFESTATION_HPP
#define UML_MANIFESTATION_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T, class ... U> class Subset;



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
	class Comment;
	class Namespace;
	class OpaqueExpression;
	class Package;
	class StringExpression;
	class TemplateParameter;
}

// base class includes
#include "uml/Abstraction.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//Includes from codegen annotation

//*********************************
namespace uml 
{
	/*!
	A manifestation is the concrete physical rendering of one or more model elements by an artifact.
	<p>From package UML::Deployments.</p>
	*/
	
	class Manifestation:virtual public Abstraction
	{
		public:
 			Manifestation(const Manifestation &) {}
			Manifestation& operator=(Manifestation const&) = delete;

		protected:
			Manifestation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Manifestation() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The model element that is utilized in the manifestation in an Artifact.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::shared_ptr<uml::PackageableElement > getUtilizedElement() const = 0;
			
			/*!
			The model element that is utilized in the manifestation in an Artifact.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual void setUtilizedElement(std::shared_ptr<uml::PackageableElement> _utilizedElement) = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The model element that is utilized in the manifestation in an Artifact.
			<p>From package UML::Deployments.</p>
			*/
			
			std::shared_ptr<uml::PackageableElement > m_utilizedElement;

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
			
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const = 0;/*!
			Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const = 0;/*!
			Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_MANIFESTATION_HPP */
