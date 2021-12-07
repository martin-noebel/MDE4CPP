//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_TYPES_NAMETYPEBINDINGNAMETYPEBINDINGIMPL_HPP
#define OCL_TYPES_NAMETYPEBINDINGNAMETYPEBINDINGIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../NameTypeBinding.hpp"

#include "ocl/Types/impl/TypesFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace ocl::Types 
{
	class OCL_API NameTypeBindingImpl : virtual public ecore::EModelElementImpl,
virtual public NameTypeBinding 
	{
		public: 
			NameTypeBindingImpl(const NameTypeBindingImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			NameTypeBindingImpl& operator=(NameTypeBindingImpl const&); 

		protected:
			friend class ocl::Types::TypesFactoryImpl;
			NameTypeBindingImpl();
			virtual std::shared_ptr<ocl::Types::NameTypeBinding> getThisNameTypeBindingPtr() const;
			virtual void setThisNameTypeBindingPtr(std::weak_ptr<ocl::Types::NameTypeBinding> thisNameTypeBindingPtr);


		public:
			//destructor
			virtual ~NameTypeBindingImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual std::string getName() const ;
			virtual void setName (std::string _name);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ecore::EClassifier> getType() const ;
			virtual void setType(std::shared_ptr<ecore::EClassifier>) ;
			
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<ocl::Types::NameTypeBinding> m_thisNameTypeBindingPtr;
	};
}
#endif /* end of include guard: OCL_TYPES_NAMETYPEBINDINGNAMETYPEBINDINGIMPL_HPP */
