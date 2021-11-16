//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_TYPES_VOIDTYPEVOIDTYPEIMPL_HPP
#define OCL_TYPES_VOIDTYPEVOIDTYPEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../VoidType.hpp"

#include "ocl/Types/impl/TypesFactoryImpl.hpp"
#include "ecore/impl/EClassifierImpl.hpp"

//*********************************
namespace ocl::Types 
{
	class OCL_API VoidTypeImpl : virtual public ecore::EClassifierImpl, virtual public VoidType 
	{
		public: 
			VoidTypeImpl(const VoidTypeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			VoidTypeImpl& operator=(VoidTypeImpl const&); 

		protected:
			friend class ocl::Types::TypesFactoryImpl;
			VoidTypeImpl();
			virtual std::shared_ptr<ocl::Types::VoidType> getThisVoidTypePtr() const;
			virtual void setThisVoidTypePtr(std::weak_ptr<ocl::Types::VoidType> thisVoidTypePtr);

			//Additional constructors for the containments back reference
			VoidTypeImpl(std::weak_ptr<ecore::EPackage> par_ePackage);

		public:
			//destructor
			virtual ~VoidTypeImpl();
			
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
			std::weak_ptr<ocl::Types::VoidType> m_thisVoidTypePtr;
	};
}
#endif /* end of include guard: OCL_TYPES_VOIDTYPEVOIDTYPEIMPL_HPP */
