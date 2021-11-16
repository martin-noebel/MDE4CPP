//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERS_PRIMITIVEVALUEPRIMITIVEVALUEIMPL_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERS_PRIMITIVEVALUEPRIMITIVEVALUEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../PrimitiveValue.hpp"

#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/ValueImpl.hpp"

//*********************************
namespace fUML::Semantics::SimpleClassifiers 
{
	class FUML_API PrimitiveValueImpl : virtual public fUML::Semantics::Values::ValueImpl, virtual public PrimitiveValue 
	{
		public: 
			PrimitiveValueImpl(const PrimitiveValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			PrimitiveValueImpl& operator=(PrimitiveValueImpl const&); 

		protected:
			friend class fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactoryImpl;
			PrimitiveValueImpl();
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::PrimitiveValue> getThisPrimitiveValuePtr() const;
			virtual void setThisPrimitiveValuePtr(std::weak_ptr<fUML::Semantics::SimpleClassifiers::PrimitiveValue> thisPrimitiveValuePtr);


		public:
			//destructor
			virtual ~PrimitiveValueImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() ;
			virtual std::shared_ptr<Bag<uml::Classifier> > getTypes() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<uml::PrimitiveType> getType() const ;
			virtual void setType(std::shared_ptr<uml::PrimitiveType>) ;
			
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
			std::weak_ptr<fUML::Semantics::SimpleClassifiers::PrimitiveValue> m_thisPrimitiveValuePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERS_PRIMITIVEVALUEPRIMITIVEVALUEIMPL_HPP */
