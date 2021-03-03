//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERFACE_HPP
#define UML_INTERFACE_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
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
	class CollaborationUse;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class Operation;
	class Package;
	class PackageImport;
	class Property;
	class ProtocolStateMachine;
	class Reception;
	class StringExpression;
	class Substitution;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class UseCase;
}

// base class includes
#include "uml/Classifier.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	Interfaces declare coherent services that are implemented by BehavioredClassifiers that implement the Interfaces via InterfaceRealizations.
	<p>From package UML::SimpleClassifiers.</p>
	*/
	
	class Interface: virtual public Classifier
	{
		public:
 			Interface(const Interface &) {}

		protected:
			Interface(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Interface() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Creates a property with the specified name, type, lower bound, and upper bound as an owned attribute of this interface.
			*/
			 
			virtual std::shared_ptr<uml::Property> createOwnedAttribute(std::string name,std::shared_ptr<uml::Type> type,int lower,int upper) = 0;/*!
			Creates an operation with the specified name, parameter names, parameter types, and return type (or null) as an owned operation of this interface.
			*/
			 
			virtual std::shared_ptr<uml::Operation> createOwnedOperation(std::string name,std::shared_ptr<Bag<std::string>> parameterNames,std::shared_ptr<Bag<uml::Type>> parameterTypes,std::shared_ptr<uml::Type> returnType) = 0;/*!
			The visibility of all Features owned by an Interface must be public.
			feature->forAll(visibility = VisibilityKind::public)
			*/
			 
			virtual bool visibility(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			References all the Classifiers that are defined (nested) within the Interface.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Classifier, uml::NamedElement>> getNestedClassifier() const = 0;
			
			/*!
			The attributes (i.e., the Properties) owned by the Interface.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Property, uml::Property,uml::NamedElement>> getOwnedAttribute() const = 0;
			
			/*!
			The Operations owned by the Interface.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Operation, uml::Feature,uml::NamedElement>> getOwnedOperation() const = 0;
			
			/*!
			Receptions that objects providing this Interface are willing to accept.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Reception, uml::Feature,uml::NamedElement>> getOwnedReception() const = 0;
			
			/*!
			References a ProtocolStateMachine specifying the legal sequences of the invocation of the BehavioralFeatures described in the Interface.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<uml::ProtocolStateMachine> getProtocol() const = 0;
			/*!
			References a ProtocolStateMachine specifying the legal sequences of the invocation of the BehavioralFeatures described in the Interface.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual void setProtocol(std::shared_ptr<uml::ProtocolStateMachine>) = 0;
			/*!
			References all the Interfaces redefined by this Interface.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/>> getRedefinedInterface() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			References all the Classifiers that are defined (nested) within the Interface.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Classifier, uml::NamedElement>> m_nestedClassifier;/*!
			The attributes (i.e., the Properties) owned by the Interface.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Property, uml::Property,uml::NamedElement>> m_ownedAttribute;/*!
			The Operations owned by the Interface.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Operation, uml::Feature,uml::NamedElement>> m_ownedOperation;/*!
			Receptions that objects providing this Interface are willing to accept.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Reception, uml::Feature,uml::NamedElement>> m_ownedReception;/*!
			References a ProtocolStateMachine specifying the legal sequences of the invocation of the BehavioralFeatures described in the Interface.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			std::shared_ptr<uml::ProtocolStateMachine> m_protocol;/*!
			References all the Interfaces redefined by this Interface.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/>> m_redefinedInterface;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> getAttribute() const = 0;/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const = 0;/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_INTERFACE_HPP */
