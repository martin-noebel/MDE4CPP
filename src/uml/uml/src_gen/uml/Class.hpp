//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CLASS_HPP
#define UML_CLASS_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace uml 
{
	class Behavior;
	class CollaborationUse;
	class Comment;
	class ConnectableElement;
	class Connector;
	class Constraint;
	class Dependency;
	class ElementImport;
	class Extension;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class InterfaceRealization;
	class Operation;
	class Package;
	class PackageImport;
	class Port;
	class Property;
	class Reception;
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
#include "uml/BehavioredClassifier.hpp"
#include "uml/EncapsulatedClassifier.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Class classifies a set of objects and specifies the features that characterize the structure and behavior of those objects.  A Class may have an internal structure and Ports.
	<p>From package UML::StructuredClassifiers.</p>
	*/
	
	class UML_API Class : virtual public BehavioredClassifier, virtual public EncapsulatedClassifier
	{
		public:
 			Class(const Class &) {}

		protected:
			Class(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Class() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Bag<uml::Operation>> getAllOperations() = 0;
			/*!
			Derivation for Class::/extension : Extension
			result = (Extension.allInstances()->select(ext | 
			  let endTypes : Sequence(Classifier) = ext.memberEnd->collect(type.oclAsType(Classifier)) in
			  endTypes->includes(self) or endTypes.allParents()->includes(self) ))
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Extension>> getExtensions() = 0;
			/*!
			Derivation for Class::/superClass : Class
			result = (self.general()->select(oclIsKindOf(Class))->collect(oclAsType(Class))->asSet())
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Class>> getSuperClasses() = 0;
			/*!
			Determines whether this class is a metaclass.
			*/
			 
			virtual bool isMetaclass() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Determines whether an object specified by this Class is active or not. If true, then the owning Class is referred to as an active Class. If false, then such a Class is referred to as a passive Class.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual bool getIsActive() const = 0;
			/*!
			Determines whether an object specified by this Class is active or not. If true, then the owning Class is referred to as an active Class. If false, then such a Class is referred to as a passive Class.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual void setIsActive (bool _isActive)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			This property is used when the Class is acting as a metaclass. It references the Extensions that specify additional properties of the metaclass. The property is derived from the Extensions whose memberEnds are typed by the Class.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Extension>> getExtension() const = 0;
			/*!
			The Classifiers owned by the Class that are not ownedBehaviors.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Classifier, uml::NamedElement>> getNestedClassifier() const = 0;
			virtual std::shared_ptr<Subset<uml::Property, uml::ConnectableElement, uml::NamedElement, uml::Property>> getClass_OwnedAttribute() const = 0;
			/*!
			The Operations owned by the Class.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Operation, uml::Feature, uml::NamedElement>> getOwnedOperation() const = 0;
			/*!
			The Receptions owned by the Class.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Reception, uml::Feature, uml::NamedElement>> getOwnedReception() const = 0;
			/*!
			The superclasses of a Class, derived from its Generalizations.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Class>> getSuperClass() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			Determines whether an object specified by this Class is active or not. If true, then the owning Class is referred to as an active Class. If false, then such a Class is referred to as a passive Class.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			bool m_isActive= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			This property is used when the Class is acting as a metaclass. It references the Extensions that specify additional properties of the metaclass. The property is derived from the Extensions whose memberEnds are typed by the Class.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Extension>> m_extension;
			/*!
			The Classifiers owned by the Class that are not ownedBehaviors.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Classifier, uml::NamedElement>> m_nestedClassifier;
			/*!
			The Operations owned by the Class.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Operation, uml::Feature, uml::NamedElement>> m_ownedOperation;
			/*!
			The Receptions owned by the Class.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Reception, uml::Feature, uml::NamedElement>> m_ownedReception;
	};
}
#endif /* end of include guard: UML_CLASS_HPP */
