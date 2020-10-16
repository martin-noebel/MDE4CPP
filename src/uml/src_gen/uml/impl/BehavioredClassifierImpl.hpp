//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_BEHAVIOREDCLASSIFIERBEHAVIOREDCLASSIFIERIMPL_HPP
#define UML_BEHAVIOREDCLASSIFIERBEHAVIOREDCLASSIFIERIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../BehavioredClassifier.hpp"

#include "uml/impl/ClassifierImpl.hpp"

//*********************************
namespace uml 
{
	class BehavioredClassifierImpl : virtual public ClassifierImpl, virtual public BehavioredClassifier 
	{
		public: 
			BehavioredClassifierImpl(const BehavioredClassifierImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			BehavioredClassifierImpl& operator=(BehavioredClassifierImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			BehavioredClassifierImpl();
			virtual std::shared_ptr<BehavioredClassifier> getThisBehavioredClassifierPtr() const;
			virtual void setThisBehavioredClassifierPtr(std::weak_ptr<BehavioredClassifier> thisBehavioredClassifierPtr);

			//Additional constructors for the containments back reference
			BehavioredClassifierImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			BehavioredClassifierImpl(std::weak_ptr<uml::Element > par_owner);


			//Additional constructors for the containments back reference
			BehavioredClassifierImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id);


			//Additional constructors for the containments back reference
			BehavioredClassifierImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);


			//Additional constructors for the containments back reference




		public:
			//destructor
			virtual ~BehavioredClassifierImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			If a behavior is classifier behavior, it does not have a specification.
			classifierBehavior->notEmpty() implies classifierBehavior.specification->isEmpty()
			*/
			 
			virtual bool class_behavior(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			Retrieves all the interfaces on which this behaviored classifier or any of its parents has an interface realization dependency.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Interface> > getAllImplementedInterfaces() ;
			
			/*!
			Retrieves the interfaces on which this behaviored classifier has an interface realization dependency.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Interface> > getImplementedInterfaces() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			A Behavior that specifies the behavior of the BehavioredClassifier itself.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior > getClassifierBehavior() const ;
			
			/*!
			A Behavior that specifies the behavior of the BehavioredClassifier itself.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual void setClassifierBehavior(std::shared_ptr<uml::Behavior> _classifierBehavior) ;
			
			/*!
			The set of InterfaceRealizations owned by the BehavioredClassifier. Interface realizations reference the Interfaces of which the BehavioredClassifier is an implementation.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::InterfaceRealization, uml::Element>> getInterfaceRealization() const ;
			
			
			/*!
			Behaviors owned by a BehavioredClassifier.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Behavior, uml::NamedElement>> getOwnedBehavior() const ;
			
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const ;/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ; 
			 
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
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<BehavioredClassifier> m_thisBehavioredClassifierPtr;
	};
}
#endif /* end of include guard: UML_BEHAVIOREDCLASSIFIERBEHAVIOREDCLASSIFIERIMPL_HPP */
