//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_BEHAVIOREXECUTIONSPECIFICATIONBEHAVIOREXECUTIONSPECIFICATIONIMPL_HPP
#define UML_BEHAVIOREXECUTIONSPECIFICATIONBEHAVIOREXECUTIONSPECIFICATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../BehaviorExecutionSpecification.hpp"

#include "uml/impl/ExecutionSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API BehaviorExecutionSpecificationImpl : virtual public ExecutionSpecificationImpl, virtual public BehaviorExecutionSpecification 
	{
		public: 
			BehaviorExecutionSpecificationImpl(const BehaviorExecutionSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			BehaviorExecutionSpecificationImpl& operator=(BehaviorExecutionSpecificationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			BehaviorExecutionSpecificationImpl();
			virtual std::shared_ptr<uml::BehaviorExecutionSpecification> getThisBehaviorExecutionSpecificationPtr() const;
			virtual void setThisBehaviorExecutionSpecificationPtr(std::weak_ptr<uml::BehaviorExecutionSpecification> thisBehaviorExecutionSpecificationPtr);

			//Additional constructors for the containments back reference
			BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			BehaviorExecutionSpecificationImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~BehaviorExecutionSpecificationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Behavior whose execution is occurring.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getBehavior() const ;
			/*!
			Behavior whose execution is occurring.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setBehavior(std::shared_ptr<uml::Behavior>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<uml::BehaviorExecutionSpecification> m_thisBehaviorExecutionSpecificationPtr;
	};
}
#endif /* end of include guard: UML_BEHAVIOREXECUTIONSPECIFICATIONBEHAVIOREXECUTIONSPECIFICATIONIMPL_HPP */
