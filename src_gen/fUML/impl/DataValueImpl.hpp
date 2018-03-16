//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_DATAVALUEDATAVALUEIMPL_HPP
#define FUML_DATAVALUEDATAVALUEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../DataValue.hpp"

#include "fUML/impl/CompoundValueImpl.hpp"

//*********************************
namespace fUML 
{
	class DataValueImpl :virtual public CompoundValueImpl, virtual public DataValue 
	{
		public: 
			DataValueImpl(const DataValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			DataValueImpl& operator=(DataValueImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			DataValueImpl();
			virtual std::shared_ptr<DataValue> getThisDataValuePtr();
			virtual void setThisDataValuePtr(std::weak_ptr<DataValue> thisDataValuePtr);



		public:
			//destructor
			virtual ~DataValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<Bag<uml::Classifier> > getTypes()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> new_()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<uml::DataType > getType() const ;
			
			/*!
			 */
			virtual void setType(std::shared_ptr<uml::DataType> _type_type) ;
							
			
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
			std::weak_ptr<DataValue> m_thisDataValuePtr;
	};
}
#endif /* end of include guard: FUML_DATAVALUEDATAVALUEIMPL_HPP */
