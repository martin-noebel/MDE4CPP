//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CLEARASSOCIATIONACTIONCLEARASSOCIATIONACTIONIMPL_HPP
#define UML_CLEARASSOCIATIONACTIONCLEARASSOCIATIONACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ClearAssociationAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ClearAssociationActionImpl : virtual public ActionImpl, virtual public ClearAssociationAction 
	{
		public: 
			ClearAssociationActionImpl(const ClearAssociationActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ClearAssociationActionImpl& operator=(ClearAssociationActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ClearAssociationActionImpl();
			virtual std::shared_ptr<uml::ClearAssociationAction> getThisClearAssociationActionPtr() const;
			virtual void setThisClearAssociationActionPtr(std::weak_ptr<uml::ClearAssociationAction> thisClearAssociationActionPtr);

			//Additional constructors for the containments back reference
			ClearAssociationActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ClearAssociationActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ClearAssociationActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ClearAssociationActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ClearAssociationActionImpl();
			
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
			The Association to be cleared.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Association> getAssociation() const ;
			/*!
			The Association to be cleared.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setAssociation(std::shared_ptr<uml::Association>) ;
			/*!
			The InputPin that gives the object whose participation in the Association is to be cleared.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getObject() const ;
			/*!
			The InputPin that gives the object whose participation in the Association is to be cleared.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(std::shared_ptr<uml::InputPin>) ;
			
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
			std::weak_ptr<uml::ClearAssociationAction> m_thisClearAssociationActionPtr;
	};
}
#endif /* end of include guard: UML_CLEARASSOCIATIONACTIONCLEARASSOCIATIONACTIONIMPL_HPP */
