//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OPAQUEBEHAVIOROPAQUEBEHAVIORIMPL_HPP
#define UML_OPAQUEBEHAVIOROPAQUEBEHAVIORIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../OpaqueBehavior.hpp"

#include "uml/impl/BehaviorImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API OpaqueBehaviorImpl : virtual public BehaviorImpl, virtual public OpaqueBehavior 
	{
		public: 
			OpaqueBehaviorImpl(const OpaqueBehaviorImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OpaqueBehaviorImpl& operator=(OpaqueBehaviorImpl const&); 

		protected:
			friend class umlFactoryImpl;
			OpaqueBehaviorImpl();
			virtual std::shared_ptr<uml::OpaqueBehavior> getThisOpaqueBehaviorPtr() const;
			virtual void setThisOpaqueBehaviorPtr(std::weak_ptr<uml::OpaqueBehavior> thisOpaqueBehaviorPtr);

			//Additional constructors for the containments back reference
			OpaqueBehaviorImpl(std::weak_ptr<uml::BehavioredClassifier> par_behavioredClassifier);
			//Additional constructors for the containments back reference
			OpaqueBehaviorImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			OpaqueBehaviorImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			OpaqueBehaviorImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			OpaqueBehaviorImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~OpaqueBehaviorImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies the behavior in one or more languages.
			<p>From package UML::CommonBehavior.</p>
			*/
			 
			virtual std::shared_ptr<Bag<std::string>> getBody() const ;
			/*!
			Languages the body strings use in the same order as the body strings.
			<p>From package UML::CommonBehavior.</p>
			*/
			 
			virtual std::shared_ptr<Bag<std::string>> getLanguage() const ;
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
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
			std::weak_ptr<uml::OpaqueBehavior> m_thisOpaqueBehaviorPtr;
	};
}
#endif /* end of include guard: UML_OPAQUEBEHAVIOROPAQUEBEHAVIORIMPL_HPP */
