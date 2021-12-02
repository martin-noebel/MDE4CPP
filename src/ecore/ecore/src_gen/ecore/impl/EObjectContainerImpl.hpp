//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EOBJECTCONTAINEREOBJECTCONTAINERIMPL_HPP
#define ECORE_EOBJECTCONTAINEREOBJECTCONTAINERIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../EObjectContainer.hpp"

#include "ecore/impl/EObjectImpl.hpp"

//*********************************
namespace ecore 
{
	class ECORE_API EObjectContainerImpl : virtual public EObjectImpl, virtual public EObjectContainer 
	{
		public: 
			EObjectContainerImpl(const EObjectContainerImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EObjectContainerImpl& operator=(EObjectContainerImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EObjectContainerImpl();
			virtual std::shared_ptr<ecore::EObjectContainer> getThisEObjectContainerPtr() const;
			virtual void setThisEObjectContainerPtr(std::weak_ptr<ecore::EObjectContainer> thisEObjectContainerPtr);

			//Additional constructors for the containments back reference
			EObjectContainerImpl(std::weak_ptr<ecore::EObject> par_eContainer);

		public:
			//destructor
			virtual ~EObjectContainerImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<ecore::EObject>> getContainer() const ;
			
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
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<ecore::EObjectContainer> m_thisEObjectContainerPtr;
	};
}
#endif /* end of include guard: ECORE_EOBJECTCONTAINEREOBJECTCONTAINERIMPL_HPP */
