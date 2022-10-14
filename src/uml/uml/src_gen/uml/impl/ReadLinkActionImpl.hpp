//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_READLINKACTIONREADLINKACTIONIMPL_HPP
#define UML_READLINKACTIONREADLINKACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ReadLinkAction.hpp"

#include "uml/impl/LinkActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ReadLinkActionImpl : virtual public LinkActionImpl, virtual public ReadLinkAction 
	{
		public: 
			ReadLinkActionImpl(const ReadLinkActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReadLinkActionImpl& operator=(ReadLinkActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ReadLinkActionImpl();
			virtual std::shared_ptr<uml::ReadLinkAction> getThisReadLinkActionPtr() const;
			virtual void setThisReadLinkActionPtr(std::weak_ptr<uml::ReadLinkAction> thisReadLinkActionPtr);

			//Additional constructors for the containments back reference
			ReadLinkActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ReadLinkActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ReadLinkActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ReadLinkActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ReadLinkActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Returns the ends corresponding to endData with no value InputPin. (A well-formed ReadLinkAction is constrained to have only one of these.)
			result = (endData->select(value=null).end->asOrderedSet())
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Property>> openEnd() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The OutputPin on which the objects retrieved from the "open" end of those links whose values on other ends are given by the endData.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getResult() const ;
			/*!
			The OutputPin on which the objects retrieved from the "open" end of those links whose values on other ends are given by the endData.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(std::shared_ptr<uml::OutputPin>) ;
			
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
			std::weak_ptr<uml::ReadLinkAction> m_thisReadLinkActionPtr;
	};
}
#endif /* end of include guard: UML_READLINKACTIONREADLINKACTIONIMPL_HPP */
