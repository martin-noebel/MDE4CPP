//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_VALUES_LITERALEVALUATION_HPP
#define FUML_SEMANTICS_VALUES_LITERALEVALUATION_HPP

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
namespace uml 
{
	class PrimitiveType;
	class ValueSpecification;
}

// base class includes
#include "fUML/Semantics/Values/Evaluation.hpp"

// enum includes


//Includes from codegen annotation
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "uml/ValueSpecification.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Type.hpp"

//*********************************
namespace fUML::Semantics::Values 
{
	
	class LiteralEvaluation:virtual public Evaluation
	{
		public:
 			LiteralEvaluation(const LiteralEvaluation &) {}
			LiteralEvaluation& operator=(LiteralEvaluation const&) = delete;

		protected:
			LiteralEvaluation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~LiteralEvaluation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<org.eclipse.uml2.uml.PrimitiveType> getType(std::string builtInTypeName) = 0;
			
			
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
#endif /* end of include guard: FUML_SEMANTICS_VALUES_LITERALEVALUATION_HPP */
