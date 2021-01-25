//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERS_PRIMITIVEVALUE_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERS_PRIMITIVEVALUE_HPP

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
namespace uml 
{
	class Classifier;
	class PrimitiveType;
}

// base class includes
#include "fUML/Semantics/Values/Value.hpp"

// enum includes


//Includes from codegen annotation
#include "fUML/FUMLFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Classifier.hpp"

//*********************************
namespace fUML::Semantics::SimpleClassifiers 
{
	
	class PrimitiveValue:virtual public fUML::Semantics::Values::Value
	{
		public:
 			PrimitiveValue(const PrimitiveValue &) {}
			PrimitiveValue& operator=(PrimitiveValue const&) = delete;

		protected:
			PrimitiveValue(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~PrimitiveValue() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() = 0;
			
			 
			virtual std::shared_ptr<Bag<org.eclipse.uml2.uml.Classifier> > getTypes() = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<org.eclipse.uml2.uml.PrimitiveType > getType() const = 0;
			
			
			virtual void setType(std::shared_ptr<org.eclipse.uml2.uml.PrimitiveType> _type) = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<org.eclipse.uml2.uml.PrimitiveType > m_type;

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
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERS_PRIMITIVEVALUE_HPP */
