//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONNECTORCONNECTORIMPL_HPP
#define UML_CONNECTORCONNECTORIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Connector.hpp"

#include "uml/impl/FeatureImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ConnectorImpl : virtual public FeatureImpl, virtual public Connector 
	{
		public: 
			ConnectorImpl(const ConnectorImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ConnectorImpl& operator=(ConnectorImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ConnectorImpl();
			virtual std::shared_ptr<uml::Connector> getThisConnectorPtr() const;
			virtual void setThisConnectorPtr(std::weak_ptr<uml::Connector> thisConnectorPtr);

			//Additional constructors for the containments back reference
			ConnectorImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ConnectorImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ConnectorImpl(std::weak_ptr<uml::StructuredClassifier> par_structuredClassifier);

		public:
			//destructor
			virtual ~ConnectorImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Derivation for Connector::/kind : ConnectorKind
			result = (if end->exists(
					role.oclIsKindOf(Port) 
					and partWithPort->isEmpty()
					and not role.oclAsType(Port).isBehavior)
			then ConnectorKind::delegation 
			else ConnectorKind::assembly 
			endif)
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual uml::ConnectorKind getKind() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates the kind of Connector. This is derived: a Connector with one or more ends connected to a Port which is not on a Part and which is not a behavior port is a delegation; otherwise it is an assembly.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual uml::ConnectorKind getKind() const ;
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The set of Behaviors that specify the valid interaction patterns across the Connector.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Behavior>> getContract() const ;
			/*!
			A Connector has at least two ConnectorEnds, each representing the participation of instances of the Classifiers typing the ConnectableElements attached to the end. The set of ConnectorEnds is ordered.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ConnectorEnd, uml::Element>> getEnd() const ;
			/*!
			A Connector may be redefined when its containing Classifier is specialized. The redefining Connector may have a type that specializes the type of the redefined Connector. The types of the ConnectorEnds of the redefining Connector may specialize the types of the ConnectorEnds of the redefined Connector. The properties of the ConnectorEnds of the redefining Connector may be replaced.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement>> getRedefinedConnector() const ;
			virtual std::weak_ptr<uml::StructuredClassifier> getStructuredClassifier() const ;
			virtual void setStructuredClassifier(std::weak_ptr<uml::StructuredClassifier>) ;
			/*!
			An optional Association that classifies links corresponding to this Connector.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<uml::Association> getType() const ;
			/*!
			An optional Association that classifies links corresponding to this Connector.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual void setType(std::shared_ptr<uml::Association>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 

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
			std::weak_ptr<uml::Connector> m_thisConnectorPtr;
	};
}
#endif /* end of include guard: UML_CONNECTORCONNECTORIMPL_HPP */
