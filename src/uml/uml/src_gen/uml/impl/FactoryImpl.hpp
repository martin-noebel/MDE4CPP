//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_FACTORYFACTORYIMPL_HPP
#define UML_FACTORYFACTORYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Factory.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API FactoryImpl : virtual public ElementImpl, virtual public Factory 
	{
		public: 
			FactoryImpl(const FactoryImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			FactoryImpl& operator=(FactoryImpl const&); 

		protected:
			friend class umlFactoryImpl;
			FactoryImpl();
			virtual std::shared_ptr<uml::Factory> getThisFactoryPtr() const;
			virtual void setThisFactoryPtr(std::weak_ptr<uml::Factory> thisFactoryPtr);

			//Additional constructors for the containments back reference
			FactoryImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~FactoryImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Creates an element that is an instance of the metaClass. Object::metaClass == metaClass and metaClass.isInstance(object)
			== true.
			All properties of the element are considered unset. The values are the same as if object.unset(property) was invoked for
			every property.
			*/
			 
			virtual std::shared_ptr<uml::Element> create(std::shared_ptr<uml::Class> metaClass) ;
			
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::Factory> m_thisFactoryPtr;
	};
}
#endif /* end of include guard: UML_FACTORYFACTORYIMPL_HPP */
