//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PACKAGE_HPP
#define UML_PACKAGE_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T, class ... U> class Subset;
template<class T, class ... U> class SubsetUnion;


namespace boost
{
	class any;
}

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
	class UmlFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class Class;
}

namespace uml 
{
	class Comment;
}

namespace uml 
{
	class Constraint;
}

namespace uml 
{
	class Dependency;
}

namespace ecore 
{
	class EAnnotation;
}

namespace ecore 
{
	class EObject;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class ElementImport;
}

namespace uml 
{
	class Enumeration;
}

namespace uml 
{
	class Interface;
}

namespace uml 
{
	class NamedElement;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class Package;
}

namespace uml 
{
	class PackageImport;
}

namespace uml 
{
	class PackageMerge;
}

namespace uml 
{
	class PackageableElement;
}

namespace uml 
{
	class PrimitiveType;
}

namespace uml 
{
	class Profile;
}

namespace uml 
{
	class ProfileApplication;
}

namespace uml 
{
	class Stereotype;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class TemplateBinding;
}

namespace uml 
{
	class TemplateParameter;
}

namespace uml 
{
	class TemplateSignature;
}

namespace uml 
{
	class TemplateableElement;
}

namespace uml 
{
	class Type;
}

// base class includes
#include "uml/Namespace.hpp"

#include "uml/PackageableElement.hpp"

#include "uml/TemplateableElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A package can have one or more profile applications to indicate which profiles have been applied. Because a profile is a package, it is possible to apply a profile not only to packages, but also to profiles.
	Package specializes TemplateableElement and PackageableElement specializes ParameterableElement to specify that a package can be used as a template and a PackageableElement as a template parameter.
	A package is used to group elements, and provides a namespace for the grouped elements.
	<p>From package UML::Packages.</p> */
	class Package:virtual public Namespace,virtual public PackageableElement,virtual public TemplateableElement
	{
		public:
 			Package(const Package &) {}
			Package& operator=(Package const&) = delete;

		protected:
			Package(){}


			//Additional constructors for the containments back reference

			Package(std::weak_ptr<uml::Namespace > par_namespace);

			//Additional constructors for the containments back reference

			Package(std::weak_ptr<uml::Package > par_Package, const int reference_id);

			//Additional constructors for the containments back reference

			Package(std::weak_ptr<uml::Element > par_owner);

			//Additional constructors for the containments back reference


			//Additional constructors for the containments back reference

			Package(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Package() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 The query allApplicableStereotypes() returns all the directly or indirectly owned stereotypes, including stereotypes contained in sub-profiles.
			result = (let ownedPackages : Bag(Package) = ownedMember->select(oclIsKindOf(Package))->collect(oclAsType(Package)) in
			 ownedStereotype->union(ownedPackages.allApplicableStereotypes())->flatten()->asSet()
			)
			<p>From package UML::Packages.</p> */ 
			virtual std::shared_ptr<Bag<uml::Stereotype> > allApplicableStereotypes()  = 0;
			
			/*!
			 Applies the current definition of the specified profile to this package and automatically applies required stereotypes in the profile to elements within this package's namespace hieararchy. If a different definition is already applied, automatically migrates any associated stereotype values on a "best effort" basis (matching classifiers and structural features by name). */ 
			virtual std::shared_ptr<Bag<ecore::EObject> > applyProfile(std::shared_ptr<uml::Profile>  profile)  = 0;
			
			/*!
			 The query containingProfile() returns the closest profile directly or indirectly containing this package (or this package itself, if it is a profile).
			result = (if self.oclIsKindOf(Profile) then 
				self.oclAsType(Profile)
			else
				self.namespace.oclAsType(Package).containingProfile()
			endif)
			<p>From package UML::Packages.</p> */ 
			virtual std::shared_ptr<uml::Profile> containingProfile()  = 0;
			
			/*!
			 Creates a(n) (abstract) class with the specified name as an owned type of this package. */ 
			virtual std::shared_ptr<uml::Class> createOwnedClass(std::string name,bool isAbstract)  = 0;
			
			/*!
			 Creates a enumeration with the specified name as an owned type of this package. */ 
			virtual std::shared_ptr<uml::Enumeration> createOwnedEnumeration(std::string name)  = 0;
			
			/*!
			 Creates an interface with the specified name as an owned type of this package. */ 
			virtual std::shared_ptr<uml::Interface> createOwnedInterface(std::string name)  = 0;
			
			/*!
			 Creates a primitive type with the specified name as an owned type of this package. */ 
			virtual std::shared_ptr<uml::PrimitiveType> createOwnedPrimitiveType(std::string name)  = 0;
			
			/*!
			 Creates a(n) (abstract) stereotype with the specified name as an owned stereotype of this profile. */ 
			virtual std::shared_ptr<uml::Stereotype> createOwnedStereotype(std::string name,bool isAbstract)  = 0;
			
			/*!
			 If an element that is owned by a package has visibility, it is public or private.
			packagedElement->forAll(e | e.visibility<> null implies e.visibility = VisibilityKind::public or e.visibility = VisibilityKind::private) */ 
			virtual bool elements_public_or_private(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 Retrieves all the profiles that are applied to this package, including profiles applied to its nesting package(s). */ 
			virtual std::shared_ptr<Bag<uml::Profile> > getAllAppliedProfiles()  = 0;
			
			/*!
			 Retrieves all the profile applications for this package, including profile applications for its nesting package(s). */ 
			virtual std::shared_ptr<Bag<uml::ProfileApplication> > getAllProfileApplications()  = 0;
			
			/*!
			 Retrieves the profile with the specified qualified name that is applied to this package, or null if no such profile is applied. */ 
			virtual std::shared_ptr<uml::Profile> getAppliedProfile(std::string qualifiedName)  = 0;
			
			/*!
			 Retrieves the profile with the specified qualified name that is applied to this package or any of its nesting packages (if indicated), or null if no such profile is applied. */ 
			virtual std::shared_ptr<uml::Profile> getAppliedProfile(std::string qualifiedName,bool recurse)  = 0;
			
			/*!
			 Retrieves the profiles that are applied to this package. */ 
			virtual std::shared_ptr<Bag<uml::Profile> > getAppliedProfiles()  = 0;
			
			/*!
			 Derivation for Package::/nestedPackage
			result = (packagedElement->select(oclIsKindOf(Package))->collect(oclAsType(Package))->asSet())
			<p>From package UML::Packages.</p> */ 
			virtual std::shared_ptr<Bag<uml::Package> > getNestedPackages()  = 0;
			
			/*!
			 Derivation for Package::/ownedStereotype
			result = (packagedElement->select(oclIsKindOf(Stereotype))->collect(oclAsType(Stereotype))->asSet())
			<p>From package UML::Packages.</p> */ 
			virtual std::shared_ptr<Bag<uml::Stereotype> > getOwnedStereotypes()  = 0;
			
			/*!
			 Derivation for Package::/ownedType
			result = (packagedElement->select(oclIsKindOf(Type))->collect(oclAsType(Type))->asSet())
			<p>From package UML::Packages.</p> */ 
			virtual std::shared_ptr<Bag<uml::Type> > getOwnedTypes()  = 0;
			
			/*!
			 Retrieves the application of the specified profile to this package, or null if no such profile is applied. */ 
			virtual std::shared_ptr<uml::ProfileApplication> getProfileApplication(std::shared_ptr<uml::Profile>  profile)  = 0;
			
			/*!
			 Retrieves the application of the specified profile to this package or any of its nesting packages (if indicated), or null if no such profile is applied. */ 
			virtual std::shared_ptr<uml::ProfileApplication> getProfileApplication(std::shared_ptr<uml::Profile>  profile,bool recurse)  = 0;
			
			/*!
			 Determines whether this package is a model library. */ 
			virtual bool isModelLibrary()  = 0;
			
			/*!
			 Determines whether the specified profile is applied to this package. */ 
			virtual bool isProfileApplied(std::shared_ptr<uml::Profile>  profile)  = 0;
			
			/*!
			 The query makesVisible() defines whether a Package makes an element visible outside itself. Elements with no visibility and elements with public visibility are made visible.
			member->includes(el)
			result = (ownedMember->includes(el) or
			(elementImport->select(ei|ei.importedElement = VisibilityKind::public)->collect(importedElement.oclAsType(NamedElement))->includes(el)) or
			(packageImport->select(visibility = VisibilityKind::public)->collect(importedPackage.member->includes(el))->notEmpty()))
			<p>From package UML::Packages.</p> */ 
			virtual bool makesVisible(std::shared_ptr<uml::NamedElement>  el)  = 0;
			
			/*!
			 Unapplies the specified profile from this package and automatically unapplies stereotypes in the profile from elements within this package's namespace hieararchy. */ 
			virtual std::shared_ptr<Bag<ecore::EObject> > unapplyProfile(std::shared_ptr<uml::Profile>  profile)  = 0;
			
			/*!
			 The query visibleMembers() defines which members of a Package can be accessed outside it.
			result = (member->select( m | m.oclIsKindOf(PackageableElement) and self.makesVisible(m))->collect(oclAsType(PackageableElement))->asSet())
			<p>From package UML::Packages.</p> */ 
			virtual std::shared_ptr<Bag<uml::PackageableElement> > visibleMembers()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Provides an identifier for the package that can be used for many purposes. A URI is the universally unique identification of the package following the IETF URI specification, RFC 2396 http://www.ietf.org/rfc/rfc2396.txt and it must comply with those syntax rules.
			<p>From package UML::Packages.</p> */ 
			virtual std::string getURI() const = 0;
			
			/*!
			 Provides an identifier for the package that can be used for many purposes. A URI is the universally unique identification of the package following the IETF URI specification, RFC 2396 http://www.ietf.org/rfc/rfc2396.txt and it must comply with those syntax rules.
			<p>From package UML::Packages.</p> */ 
			virtual void setURI (std::string _URI)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 References the packaged elements that are Packages.
			<p>From package UML::Packages.</p> */
			virtual std::shared_ptr<Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/>> getNestedPackage() const = 0;
			
			/*!
			 References the Package that owns this Package.
			<p>From package UML::Packages.</p> */
			virtual std::weak_ptr<uml::Package > getNestingPackage() const = 0;
			
			/*!
			 References the Package that owns this Package.
			<p>From package UML::Packages.</p> */
			virtual void setNestingPackage(std::shared_ptr<uml::Package> _nestingPackage_nestingPackage) = 0;
			/*!
			 References the Stereotypes that are owned by the Package.
			<p>From package UML::Packages.</p> */
			virtual std::shared_ptr<Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/>> getOwnedStereotype() const = 0;
			
			/*!
			 References the packaged elements that are Types.
			<p>From package UML::Packages.</p> */
			virtual std::shared_ptr<Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/>> getOwnedType() const = 0;
			
			/*!
			 References the PackageMerges that are owned by this Package.
			<p>From package UML::Packages.</p> */
			virtual std::shared_ptr<Subset<uml::PackageMerge, uml::Element>> getPackageMerge() const = 0;
			
			/*!
			 Specifies the packageable elements that are owned by this Package.
			<p>From package UML::Packages.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::PackageableElement, uml::NamedElement>> getPackagedElement() const = 0;
			
			/*!
			 References the ProfileApplications that indicate which profiles have been applied to the Package.
			<p>From package UML::Packages.</p> */
			virtual std::shared_ptr<Subset<uml::ProfileApplication, uml::Element>> getProfileApplication() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 Provides an identifier for the package that can be used for many purposes. A URI is the universally unique identification of the package following the IETF URI specification, RFC 2396 http://www.ietf.org/rfc/rfc2396.txt and it must comply with those syntax rules.
			<p>From package UML::Packages.</p> */ 
			std::string m_URI = "";
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 References the packaged elements that are Packages.
			<p>From package UML::Packages.</p> */
			std::shared_ptr<Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/>> m_nestedPackage;
			/*!
			 References the Package that owns this Package.
			<p>From package UML::Packages.</p> */
			std::weak_ptr<uml::Package > m_nestingPackage;
			/*!
			 References the Stereotypes that are owned by the Package.
			<p>From package UML::Packages.</p> */
			std::shared_ptr<Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/>> m_ownedStereotype;
			/*!
			 References the packaged elements that are Types.
			<p>From package UML::Packages.</p> */
			std::shared_ptr<Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/>> m_ownedType;
			/*!
			 References the PackageMerges that are owned by this Package.
			<p>From package UML::Packages.</p> */
			std::shared_ptr<Subset<uml::PackageMerge, uml::Element>> m_packageMerge;
			/*!
			 Specifies the packageable elements that are owned by this Package.
			<p>From package UML::Packages.</p> */
			std::shared_ptr<SubsetUnion<uml::PackageableElement, uml::NamedElement>> m_packagedElement;
			/*!
			 References the ProfileApplications that indicate which profiles have been applied to the Package.
			<p>From package UML::Packages.</p> */
			std::shared_ptr<Subset<uml::ProfileApplication, uml::Element>> m_profileApplication;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			 A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const = 0;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
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
#endif /* end of include guard: UML_PACKAGE_HPP */
