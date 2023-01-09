//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DATATYPEDATATYPEIMPL_HPP
#define UML_DATATYPEDATATYPEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../DataType.hpp"

#include "uml/impl/ClassifierImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API DataTypeImpl : virtual public ClassifierImpl, virtual public DataType 
	{
		public: 
			DataTypeImpl(const DataTypeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DataTypeImpl& operator=(DataTypeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			DataTypeImpl();
			virtual std::shared_ptr<uml::DataType> getThisDataTypePtr() const;
			virtual void setThisDataTypePtr(std::weak_ptr<uml::DataType> thisDataTypePtr);

			//Additional constructors for the containments back reference
			DataTypeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			DataTypeImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			DataTypeImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			DataTypeImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~DataTypeImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Creates a property with the specified name, type, lower bound, and upper bound as an owned attribute of this data type.
			*/
			 
			virtual std::shared_ptr<uml::Property> createOwnedAttribute(std::string name, std::shared_ptr<uml::Type> type, int lower, int upper) ;
			/*!
			Creates an operation with the specified name, parameter names, parameter types, and return type (or null) as an owned operation of this data type.
			*/
			 
			virtual std::shared_ptr<uml::Operation> createOwnedOperation(std::string name, std::shared_ptr<Bag<std::string>> parameterNames, std::shared_ptr<Bag<uml::Type>> parameterTypes, std::shared_ptr<uml::Type> returnType) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The attributes owned by the DataType.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Property, uml::NamedElement, uml::Property>> getOwnedAttribute() const ;
			/*!
			The Operations owned by the DataType.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Operation, uml::Feature, uml::NamedElement>> getOwnedOperation() const ;
			
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
			std::weak_ptr<uml::DataType> m_thisDataTypePtr;
	};
}
#endif /* end of include guard: UML_DATATYPEDATATYPEIMPL_HPP */
