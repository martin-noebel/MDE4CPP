//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_WRITELINKACTIONWRITELINKACTIONIMPL_HPP
#define UML_WRITELINKACTIONWRITELINKACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../WriteLinkAction.hpp"

#include "uml/impl/LinkActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API WriteLinkActionImpl : virtual public LinkActionImpl, virtual public WriteLinkAction 
	{
		public: 
			WriteLinkActionImpl(const WriteLinkActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			WriteLinkActionImpl& operator=(WriteLinkActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			WriteLinkActionImpl();
			virtual std::shared_ptr<uml::WriteLinkAction> getThisWriteLinkActionPtr() const;
			virtual void setThisWriteLinkActionPtr(std::weak_ptr<uml::WriteLinkAction> thisWriteLinkActionPtr);

			//Additional constructors for the containments back reference
			WriteLinkActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			WriteLinkActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			WriteLinkActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			WriteLinkActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~WriteLinkActionImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
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
			std::weak_ptr<uml::WriteLinkAction> m_thisWriteLinkActionPtr;
	};
}
#endif /* end of include guard: UML_WRITELINKACTIONWRITELINKACTIONIMPL_HPP */
