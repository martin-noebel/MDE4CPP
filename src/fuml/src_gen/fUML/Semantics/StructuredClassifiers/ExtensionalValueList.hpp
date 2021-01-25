//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_EXTENSIONALVALUELIST_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_EXTENSIONALVALUELIST_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations



//*********************************
// generated Includes

#include <map>

namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers 
{
	class FeatureValue;
}

// base class includes
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"

// enum includes


//Includes from codegen annotation

//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	
	class ExtensionalValueList:virtual public ExtensionalValue
	{
		public:
 			ExtensionalValueList(const ExtensionalValueList &) {}
			ExtensionalValueList& operator=(ExtensionalValueList const&) = delete;

		protected:
			ExtensionalValueList(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExtensionalValueList() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual bool addValue(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value) = 0;
			
			 
			virtual void addValue(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value,int i) = 0;
			
			 
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> getValue() = 0;
			
			 
			virtual std::string removeValue(int i) = 0;
			
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> setValue(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value,int i) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_EXTENSIONALVALUELIST_HPP */
