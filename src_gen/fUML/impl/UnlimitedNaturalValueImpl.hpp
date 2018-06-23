//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_UNLIMITEDNATURALVALUEUNLIMITEDNATURALVALUEIMPL_HPP
#define FUML_UNLIMITEDNATURALVALUEUNLIMITEDNATURALVALUEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../UnlimitedNaturalValue.hpp"

#include "fUML/impl/PrimitiveValueImpl.hpp"

//*********************************
namespace fUML 
{
	class UnlimitedNaturalValueImpl :virtual public PrimitiveValueImpl, virtual public UnlimitedNaturalValue 
	{
		public: 
			UnlimitedNaturalValueImpl(const UnlimitedNaturalValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			UnlimitedNaturalValueImpl& operator=(UnlimitedNaturalValueImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			UnlimitedNaturalValueImpl();
			virtual std::shared_ptr<UnlimitedNaturalValue> getThisUnlimitedNaturalValuePtr();
			virtual void setThisUnlimitedNaturalValuePtr(std::weak_ptr<UnlimitedNaturalValue> thisUnlimitedNaturalValuePtr);



		public:
			//destructor
			virtual ~UnlimitedNaturalValueImpl();
			
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
			std::weak_ptr<UnlimitedNaturalValue> m_thisUnlimitedNaturalValuePtr;
	};
}
#endif /* end of include guard: FUML_UNLIMITEDNATURALVALUEUNLIMITEDNATURALVALUEIMPL_HPP */
