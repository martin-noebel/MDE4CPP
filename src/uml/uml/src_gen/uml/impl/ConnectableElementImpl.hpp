//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONNECTABLEELEMENTCONNECTABLEELEMENTIMPL_HPP
#define UML_CONNECTABLEELEMENTCONNECTABLEELEMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ConnectableElement.hpp"

#include "uml/impl/ParameterableElementImpl.hpp"
#include "uml/impl/TypedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ConnectableElementImpl : virtual public ParameterableElementImpl, virtual public TypedElementImpl, virtual public ConnectableElement 
	{
		public: 
			ConnectableElementImpl(const ConnectableElementImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			ConnectableElementImpl& operator=(ConnectableElementImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ConnectableElementImpl();
			virtual std::shared_ptr<uml::ConnectableElement> getThisConnectableElementPtr() const;
			virtual void setThisConnectableElementPtr(std::weak_ptr<uml::ConnectableElement> thisConnectableElementPtr);

			//Additional constructors for the containments back reference
			ConnectableElementImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ConnectableElementImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ConnectableElementImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~ConnectableElementImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Derivation for ConnectableElement::/end : ConnectorEnd
			result = (ConnectorEnd.allInstances()->select(role = self))
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::ConnectorEnd>> getEnds() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A set of ConnectorEnds that attach to this ConnectableElement.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ConnectorEnd>> getEnd() const ;
			
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
			std::weak_ptr<uml::ConnectableElement> m_thisConnectableElementPtr;
	};
}
#endif /* end of include guard: UML_CONNECTABLEELEMENTCONNECTABLEELEMENTIMPL_HPP */
