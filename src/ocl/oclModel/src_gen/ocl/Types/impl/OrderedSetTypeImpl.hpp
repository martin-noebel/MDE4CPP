//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_TYPES_ORDEREDSETTYPEORDEREDSETTYPEIMPL_HPP
#define OCL_TYPES_ORDEREDSETTYPEORDEREDSETTYPEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../OrderedSetType.hpp"

#include "ocl/Types/impl/TypesFactoryImpl.hpp"
#include "ocl/Types/impl/CollectionTypeImpl.hpp"

//*********************************
namespace ocl::Types 
{
	class OCL_API OrderedSetTypeImpl : virtual public CollectionTypeImpl, virtual public OrderedSetType 
	{
		public: 
			OrderedSetTypeImpl(const OrderedSetTypeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OrderedSetTypeImpl& operator=(OrderedSetTypeImpl const&); 

		protected:
			friend class ocl::Types::TypesFactoryImpl;
			OrderedSetTypeImpl();
			virtual std::shared_ptr<ocl::Types::OrderedSetType> getThisOrderedSetTypePtr() const;
			virtual void setThisOrderedSetTypePtr(std::weak_ptr<ocl::Types::OrderedSetType> thisOrderedSetTypePtr);

			//Additional constructors for the containments back reference
			OrderedSetTypeImpl(std::weak_ptr<ecore::EPackage> par_ePackage);

		public:
			//destructor
			virtual ~OrderedSetTypeImpl();
			
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
			std::weak_ptr<ocl::Types::OrderedSetType> m_thisOrderedSetTypePtr;
	};
}
#endif /* end of include guard: OCL_TYPES_ORDEREDSETTYPEORDEREDSETTYPEIMPL_HPP */
