//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIVITYACTIVITYIMPL_HPP
#define UML_ACTIVITYACTIVITYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Activity.hpp"

#include "uml/impl/BehaviorImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ActivityImpl : virtual public BehaviorImpl, virtual public Activity 
	{
		public: 
			ActivityImpl(const ActivityImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ActivityImpl& operator=(ActivityImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ActivityImpl();
			virtual std::shared_ptr<uml::Activity> getThisActivityPtr() const;
			virtual void setThisActivityPtr(std::weak_ptr<uml::Activity> thisActivityPtr);

			//Additional constructors for the containments back reference
			ActivityImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier);
			//Additional constructors for the containments back reference
			ActivityImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ActivityImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ActivityImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			ActivityImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~ActivityImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			If true, this Activity must not make any changes to objects. The default is false (an Activity may make nonlocal changes). (This is an assertion, not an executable property. It may be used by an execution engine to optimize model execution. If the assertion is violated by the Activity, then the model is ill-formed.)
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool getIsReadOnly() const ;
			/*!
			If true, this Activity must not make any changes to objects. The default is false (an Activity may make nonlocal changes). (This is an assertion, not an executable property. It may be used by an execution engine to optimize model execution. If the assertion is violated by the Activity, then the model is ill-formed.)
			<p>From package UML::Activities.</p>
			*/
			 
			virtual void setIsReadOnly (bool _isReadOnly);
			/*!
			If true, all invocations of the Activity are handled by the same execution.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool getIsSingleExecution() const ;
			/*!
			If true, all invocations of the Activity are handled by the same execution.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual void setIsSingleExecution (bool _isSingleExecution);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			ActivityEdges expressing flow between the nodes of the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityEdge, uml::Element>> getEdge() const ;
			
			/*!
			ActivityNodes coordinated by the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ActivityNode, uml::Element>> getNode() const ;
			virtual std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::ActivityGroup>> getOwnedGroup() const ;
			virtual std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode /*Subset does not reference a union*/>> getOwnedNode() const ;
			/*!
			Top-level ActivityPartitions in the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup /*Subset does not reference a union*/, uml::ActivityGroup>> getPartition() const ;
			/*!
			Top-level StructuredActivityNodes in the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::StructuredActivityNode, uml::ActivityGroup, uml::ActivityNode /*Subset does not reference a union*/>> getStructuredNode() const ;
			/*!
			Top-level Variables defined by the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> getVariable() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Top-level ActivityGroups in the Activity.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ActivityGroup, uml::Element>> getGroup() const ;
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::Activity> m_thisActivityPtr;
	};
}
#endif /* end of include guard: UML_ACTIVITYACTIVITYIMPL_HPP */
