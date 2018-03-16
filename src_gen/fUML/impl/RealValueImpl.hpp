//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_REALVALUEREALVALUEIMPL_HPP
#define FUML_REALVALUEREALVALUEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../RealValue.hpp"

#include "fUML/impl/PrimitiveValueImpl.hpp"

//*********************************
namespace fUML 
{
	class RealValueImpl :virtual public PrimitiveValueImpl, virtual public RealValue 
	{
		public: 
			RealValueImpl(const RealValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			RealValueImpl& operator=(RealValueImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			RealValueImpl();
			virtual std::shared_ptr<RealValue> getThisRealValuePtr();
			virtual void setThisRealValuePtr(std::weak_ptr<RealValue> thisRealValuePtr);



		public:
			//destructor
			virtual ~RealValueImpl();
			
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
			virtual float getValue() const ;
			
			/*!
			 */ 
			virtual void setValue (float _value); 
			
			
			
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
			std::weak_ptr<RealValue> m_thisRealValuePtr;
	};
}
#endif /* end of include guard: FUML_REALVALUEREALVALUEIMPL_HPP */
