//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_INTEGERVALUEINTEGERVALUEIMPL_HPP
#define FUML_INTEGERVALUEINTEGERVALUEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../IntegerValue.hpp"

#include "fUML/impl/PrimitiveValueImpl.hpp"

//*********************************
namespace fUML 
{
	class IntegerValueImpl :virtual public PrimitiveValueImpl, virtual public IntegerValue 
	{
		public: 
			IntegerValueImpl(const IntegerValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			IntegerValueImpl& operator=(IntegerValueImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			IntegerValueImpl();
			virtual std::shared_ptr<IntegerValue> getThisIntegerValuePtr();
			virtual void setThisIntegerValuePtr(std::weak_ptr<IntegerValue> thisIntegerValuePtr);



		public:
			//destructor
			virtual ~IntegerValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual bool equals(std::shared_ptr<fUML::Value>  otherValue)  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<uml::ValueSpecification> specify()  ;
			
			/*!
			 */ 
			virtual std::string toString()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual int getValue() const ;
			
			/*!
			 */ 
			virtual void setValue (int _value); 
			
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<IntegerValue> m_thisIntegerValuePtr;
	};
}
#endif /* end of include guard: FUML_INTEGERVALUEINTEGERVALUEIMPL_HPP */
