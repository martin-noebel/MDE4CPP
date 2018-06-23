//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_PRIMITIVEVALUEPRIMITIVEVALUEIMPL_HPP
#define FUML_PRIMITIVEVALUEPRIMITIVEVALUEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../PrimitiveValue.hpp"

#include "fUML/impl/ValueImpl.hpp"

//*********************************
namespace fUML 
{
	class PrimitiveValueImpl :virtual public ValueImpl, virtual public PrimitiveValue 
	{
		public: 
			PrimitiveValueImpl(const PrimitiveValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			PrimitiveValueImpl& operator=(PrimitiveValueImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			PrimitiveValueImpl();
			virtual std::shared_ptr<PrimitiveValue> getThisPrimitiveValuePtr();
			virtual void setThisPrimitiveValuePtr(std::weak_ptr<PrimitiveValue> thisPrimitiveValuePtr);



		public:
			//destructor
			virtual ~PrimitiveValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<Bag<uml::Classifier> > getTypes()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<uml::PrimitiveType > getType() const ;
			
			/*!
			 */
			virtual void setType(std::shared_ptr<uml::PrimitiveType> _type_type) ;
							
			
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
			std::weak_ptr<PrimitiveValue> m_thisPrimitiveValuePtr;
	};
}
#endif /* end of include guard: FUML_PRIMITIVEVALUEPRIMITIVEVALUEIMPL_HPP */
