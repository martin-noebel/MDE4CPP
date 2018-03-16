//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_BOOLEANVALUEBOOLEANVALUEIMPL_HPP
#define FUML_BOOLEANVALUEBOOLEANVALUEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../BooleanValue.hpp"

#include "fUML/impl/PrimitiveValueImpl.hpp"

//*********************************
namespace fUML 
{
	class BooleanValueImpl :virtual public PrimitiveValueImpl, virtual public BooleanValue 
	{
		public: 
			BooleanValueImpl(const BooleanValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			BooleanValueImpl& operator=(BooleanValueImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			BooleanValueImpl();
			virtual std::shared_ptr<BooleanValue> getThisBooleanValuePtr();
			virtual void setThisBooleanValuePtr(std::weak_ptr<BooleanValue> thisBooleanValuePtr);



		public:
			//destructor
			virtual ~BooleanValueImpl();
			
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
			virtual bool isValue() const ;
			
			/*!
			 */ 
			virtual void setValue (bool _value); 
			
			
			
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
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<BooleanValue> m_thisBooleanValuePtr;
	};
}
#endif /* end of include guard: FUML_BOOLEANVALUEBOOLEANVALUEIMPL_HPP */
