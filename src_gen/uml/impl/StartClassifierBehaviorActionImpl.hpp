//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STARTCLASSIFIERBEHAVIORACTIONSTARTCLASSIFIERBEHAVIORACTIONIMPL_HPP
#define UML_STARTCLASSIFIERBEHAVIORACTIONSTARTCLASSIFIERBEHAVIORACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../StartClassifierBehaviorAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class StartClassifierBehaviorActionImpl :virtual public ActionImpl, virtual public StartClassifierBehaviorAction 
	{
		public: 
			StartClassifierBehaviorActionImpl(const StartClassifierBehaviorActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			StartClassifierBehaviorActionImpl& operator=(StartClassifierBehaviorActionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			StartClassifierBehaviorActionImpl();
			virtual std::shared_ptr<StartClassifierBehaviorAction> getThisStartClassifierBehaviorActionPtr();
			virtual void setThisStartClassifierBehaviorActionPtr(std::weak_ptr<StartClassifierBehaviorAction> thisStartClassifierBehaviorActionPtr);

			//Additional constructors for the containments back reference
			StartClassifierBehaviorActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			StartClassifierBehaviorActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			StartClassifierBehaviorActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			StartClassifierBehaviorActionImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~StartClassifierBehaviorActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The multiplicity of the object InputPin is 1..1
			object.is(1,1) */ 
			virtual bool multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 If the InputPin has a type, then the type or one of its ancestors must have a classifierBehavior.
			object.type->notEmpty() implies 
			   (object.type.oclIsKindOf(BehavioredClassifier) and object.type.oclAsType(BehavioredClassifier).classifierBehavior<>null) */ 
			virtual bool type_has_classifier(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The InputPin that holds the object whose classifierBehavior is to be started.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::InputPin > getObject() const ;
			
			/*!
			 The InputPin that holds the object whose classifierBehavior is to be started.
			<p>From package UML::Actions.</p> */
			virtual void setObject(std::shared_ptr<uml::InputPin> _object_object) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			 The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<StartClassifierBehaviorAction> m_thisStartClassifierBehaviorActionPtr;
	};
}
#endif /* end of include guard: UML_STARTCLASSIFIERBEHAVIORACTIONSTARTCLASSIFIERBEHAVIORACTIONIMPL_HPP */
