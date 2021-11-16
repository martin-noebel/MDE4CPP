//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PACKAGEIMPORT_HPP
#define UML_PACKAGEIMPORT_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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
	class Comment;
	class Namespace;
	class Package;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/DirectedRelationship.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A PackageImport is a Relationship that imports all the non-private members of a Package into the Namespace owning the PackageImport, so that those Elements may be referred to by their unqualified names in the importingNamespace.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class UML_API PackageImport: virtual public DirectedRelationship
	{
		public:
 			PackageImport(const PackageImport &) {}

		protected:
			PackageImport(){}
			//Additional constructors for the containments back reference
			PackageImport(std::weak_ptr<uml::Namespace> par_importingNamespace);

			//Additional constructors for the containments back reference
			PackageImport(std::weak_ptr<uml::Element> par_owner);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~PackageImport() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The visibility of a PackageImport is either public or private.
			visibility = VisibilityKind::public or visibility = VisibilityKind::private
			*/
			 
			virtual bool public_or_private(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies the visibility of the imported PackageableElements within the importingNamespace, i.e., whether imported Elements will in turn be visible to other Namespaces. If the PackageImport is public, the imported Elements will be visible outside the importingNamespace, while, if the PackageImport is private, they will not.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual uml::VisibilityKind getVisibility() const = 0;
			/*!
			Specifies the visibility of the imported PackageableElements within the importingNamespace, i.e., whether imported Elements will in turn be visible to other Namespaces. If the PackageImport is public, the imported Elements will be visible outside the importingNamespace, while, if the PackageImport is private, they will not.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setVisibility (uml::VisibilityKind _visibility)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Specifies the Package whose members are imported into a Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::Package> getImportedPackage() const = 0;
			/*!
			Specifies the Package whose members are imported into a Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setImportedPackage(std::shared_ptr<uml::Package>) = 0;
			/*!
			Specifies the Namespace that imports the members from a Package.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getImportingNamespace() const = 0;
			/*!
			Specifies the Namespace that imports the members from a Package.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setImportingNamespace(std::weak_ptr<uml::Namespace>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;
			/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const = 0;
			/*!
			Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const = 0;
			/*!
			Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const = 0;

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
			Specifies the visibility of the imported PackageableElements within the importingNamespace, i.e., whether imported Elements will in turn be visible to other Namespaces. If the PackageImport is public, the imported Elements will be visible outside the importingNamespace, while, if the PackageImport is private, they will not.
			<p>From package UML::CommonStructure.</p>
			*/
			
			uml::VisibilityKind m_visibility= uml::VisibilityKind::PUBLIC;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			Specifies the Package whose members are imported into a Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::Package> m_importedPackage;
			/*!
			Specifies the Namespace that imports the members from a Package.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::weak_ptr<uml::Namespace> m_importingNamespace;
	};
}
#endif /* end of include guard: UML_PACKAGEIMPORT_HPP */
