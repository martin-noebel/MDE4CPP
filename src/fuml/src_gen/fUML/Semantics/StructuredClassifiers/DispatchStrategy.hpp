//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_DISPATCHSTRATEGY_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_DISPATCHSTRATEGY_HPP

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
namespace fUML::Semantics::CommonBehavior 
{
	class Execution;
}
namespace fUML::Semantics::StructuredClassifiers 
{
	class Object;
}
namespace uml 
{
	class Behavior;
	class Operation;
}

// base class includes
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"

// enum includes


//Includes from codegen annotation
#include "abstractDataTypes/Bag.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"

//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	
	class DispatchStrategy:virtual public fUML::Semantics::Loci::SemanticStrategy
	{
		public:
 			DispatchStrategy(const DispatchStrategy &) {}
			DispatchStrategy& operator=(DispatchStrategy const&) = delete;

		protected:
			DispatchStrategy(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~DispatchStrategy() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatch(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object,std::shared_ptr<org.eclipse.uml2.uml.Operation> operation) = 0;
			
			 
			virtual std::string getName() = 0;
			
			 
			virtual std::shared_ptr<org.eclipse.uml2.uml.Behavior> retrieveMethod(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object,std::shared_ptr<org.eclipse.uml2.uml.Operation> operation) = 0;
			
			
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
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_DISPATCHSTRATEGY_HPP */
