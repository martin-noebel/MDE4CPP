//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ENAMEDELEMENTENAMEDELEMENTIMPL_HPP
#define ECORE_ENAMEDELEMENTENAMEDELEMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ecore/ecore.hpp" 

// model includes
#include "../ENamedElement.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace ecore 
{
	class ECORE_API ENamedElementImpl : virtual public EModelElementImpl, virtual public ENamedElement 
	{
		public: 
			ENamedElementImpl(const ENamedElementImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			ENamedElementImpl& operator=(ENamedElementImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			ENamedElementImpl();
			virtual std::shared_ptr<ecore::ENamedElement> getThisENamedElementPtr() const;
			virtual void setThisENamedElementPtr(std::weak_ptr<ecore::ENamedElement> thisENamedElementPtr);

			//Additional constructors for the containments back reference
			ENamedElementImpl(std::weak_ptr<ecore::EObject> par_eContainer);

		public:
			//destructor
			virtual ~ENamedElementImpl() = 0;
			
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
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<ecore::EObject>> getEContentUnion() const ;
			
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<ecore::ENamedElement> m_thisENamedElementPtr;
	};
}
#endif /* end of include guard: ECORE_ENAMEDELEMENTENAMEDELEMENTIMPL_HPP */
