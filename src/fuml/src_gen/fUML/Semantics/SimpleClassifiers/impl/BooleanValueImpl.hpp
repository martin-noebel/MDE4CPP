//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERS_BOOLEANVALUEBOOLEANVALUEIMPL_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERS_BOOLEANVALUEBOOLEANVALUEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../BooleanValue.hpp"

#include "fUML/Semantics/SimpleClassifiers/impl/SimpleClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/SimpleClassifiers/impl/PrimitiveValueImpl.hpp"

//*********************************
namespace fUML::Semantics::SimpleClassifiers 
{
	class FUML_API BooleanValueImpl : virtual public PrimitiveValueImpl, virtual public BooleanValue 
	{
		public: 
			BooleanValueImpl(const BooleanValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			BooleanValueImpl& operator=(BooleanValueImpl const&); 

		protected:
			friend class fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactoryImpl;
			BooleanValueImpl();
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> getThisBooleanValuePtr() const;
			virtual void setThisBooleanValuePtr(std::weak_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> thisBooleanValuePtr);


		public:
			//destructor
			virtual ~BooleanValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() ;
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue) ;
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() ;
			virtual std::shared_ptr<uml::ValueSpecification> specify() ;
			virtual std::string toString() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isValue() const ;
			virtual void setValue (bool _value);
			
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
			std::weak_ptr<fUML::Semantics::SimpleClassifiers::BooleanValue> m_thisBooleanValuePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERS_BOOLEANVALUEBOOLEANVALUEIMPL_HPP */
