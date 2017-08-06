//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CLASSCLASSIMPL_HPP
#define UML_CLASSCLASSIMPL_HPP

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
#include "../Class.hpp"

#include "impl/BehavioredClassifierImpl.hpp"
#include "impl/EncapsulatedClassifierImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class ClassImpl :virtual public BehavioredClassifierImpl, virtual public EncapsulatedClassifierImpl, virtual public Class 
	{
		public: 
			ClassImpl(const ClassImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ClassImpl& operator=(ClassImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ClassImpl();

		public:
			//destructor
			virtual ~ClassImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 Only an active Class may own Receptions and have a classifierBehavior.
			not isActive implies (ownedReception->isEmpty() and classifierBehavior = null) */ 
			virtual bool
			 passive_class(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 Creates an operation with the specified name, parameter names, parameter types, and return type (or null) as an owned operation of this class. */ 
			virtual std::shared_ptr<uml::Operation> 
			 createOwnedOperation(std::string name,std::shared_ptr<Bag<std::string> >  parameterNames,std::shared_ptr<Bag<uml::Type> >  parameterTypes,std::shared_ptr<uml::Type>  returnType)  ;
			
			/*!
			 Determines whether this class is a metaclass. */ 
			virtual bool
			 isMetaclass()  ;
			
			/*!
			 Derivation for Class::/extension : Extension
			result = (Extension.allInstances()->select(ext | 
			  let endTypes : Sequence(Classifier) = ext.memberEnd->collect(type.oclAsType(Classifier)) in
			  endTypes->includes(self) or endTypes.allParents()->includes(self) ))
			<p>From package UML::StructuredClassifiers.</p> */ 
			virtual std::shared_ptr<Bag<uml::Extension> >
			 getExtensions()  ;
			
			/*!
			 Derivation for Class::/superClass : Class
			result = (self.general()->select(oclIsKindOf(Class))->collect(oclAsType(Class))->asSet())
			<p>From package UML::StructuredClassifiers.</p> */ 
			virtual std::shared_ptr<Bag<uml::Class> >
			 getSuperClasses()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Determines whether an object specified by this Class is active or not. If true, then the owning Class is referred to as an active Class. If false, then such a Class is referred to as a passive Class.
			<p>From package UML::StructuredClassifiers.</p> */ 
			virtual bool getIsActive() const ;
			
			/*!
			 Determines whether an object specified by this Class is active or not. If true, then the owning Class is referred to as an active Class. If false, then such a Class is referred to as a passive Class.
			<p>From package UML::StructuredClassifiers.</p> */ 
			virtual void setIsActive (bool _isActive); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The Operations owned by the Class.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual 		std::shared_ptr<Subset<uml::Operation, uml::Feature,uml::NamedElement > >
			 getOwnedOperation() const ;
			
			/*!
			 This property is used when the Class is acting as a metaclass. It references the Extensions that specify additional properties of the metaclass. The property is derived from the Extensions whose memberEnds are typed by the Class.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual 	std::shared_ptr< Bag<uml::Extension> >
			 getExtension() const ;
			
			/*!
			 The Classifiers owned by the Class that are not ownedBehaviors.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual 		std::shared_ptr<Subset<uml::Classifier, uml::NamedElement > >
			 getNestedClassifier() const ;
			
			/*!
			 The Receptions owned by the Class.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual 		std::shared_ptr<Subset<uml::Reception, uml::Feature,uml::NamedElement > >
			 getOwnedReception() const ;
			
			/*!
			 The superclasses of a Class, derived from its Generalizations.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual 	std::shared_ptr< Bag<uml::Class> >
			 getSuperClass() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > >
			 getAttribute() const ;/*!
			 A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::NamedElement> > getMember() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > >
			 getFeature() const ;/*!
			 A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > >
			 getOwnedMember() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Union<uml::RedefinableElement> > getRedefinedElement() const ;/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Namespace > getNamespace() const ;/*!
			 The roles that instances may play in this StructuredClassifier.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement > >
			 getRole() const ;/*!
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
#endif /* end of include guard: UML_CLASSCLASSIMPL_HPP */

