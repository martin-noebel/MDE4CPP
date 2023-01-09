//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONNECTIONPOINTREFERENCECONNECTIONPOINTREFERENCEIMPL_HPP
#define UML_CONNECTIONPOINTREFERENCECONNECTIONPOINTREFERENCEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ConnectionPointReference.hpp"

#include "uml/impl/VertexImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ConnectionPointReferenceImpl : virtual public VertexImpl, virtual public ConnectionPointReference 
	{
		public: 
			ConnectionPointReferenceImpl(const ConnectionPointReferenceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ConnectionPointReferenceImpl& operator=(ConnectionPointReferenceImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ConnectionPointReferenceImpl();
			virtual std::shared_ptr<uml::ConnectionPointReference> getThisConnectionPointReferencePtr() const;
			virtual void setThisConnectionPointReferencePtr(std::weak_ptr<uml::ConnectionPointReference> thisConnectionPointReferencePtr);

			//Additional constructors for the containments back reference
			ConnectionPointReferenceImpl(std::weak_ptr<uml::Region> par_container);
			//Additional constructors for the containments back reference
			ConnectionPointReferenceImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ConnectionPointReferenceImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ConnectionPointReferenceImpl(std::weak_ptr<uml::State> par_state);

		public:
			//destructor
			virtual ~ConnectionPointReferenceImpl();
			
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
			The entryPoint Pseudostates corresponding to this connection point.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Pseudostate>> getEntry() const ;
			/*!
			The exitPoints kind Pseudostates corresponding to this connection point.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Pseudostate>> getExit() const ;
			/*!
			The State in which the ConnectionPointReference is defined.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::State> getState() const ;
			/*!
			The State in which the ConnectionPointReference is defined.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setState(std::weak_ptr<uml::State>) ;
			
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
			std::weak_ptr<uml::ConnectionPointReference> m_thisConnectionPointReferencePtr;
	};
}
#endif /* end of include guard: UML_CONNECTIONPOINTREFERENCECONNECTIONPOINTREFERENCEIMPL_HPP */
