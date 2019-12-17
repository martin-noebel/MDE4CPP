//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCI_EXECUTIONFACTORYL3_HPP
#define FUML_SEMANTICS_LOCI_EXECUTIONFACTORYL3_HPP

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
	class FUMLFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class Element;
}

namespace fUML::Semantics::Loci 
{
	class ExecutionFactoryL2;
}

namespace fUML::Semantics::Loci 
{
	class Locus;
}

namespace fUML::Semantics::CommonBehavior 
{
	class OpaqueBehaviorExecution;
}

namespace uml 
{
	class PrimitiveType;
}

namespace fUML::Semantics::Loci 
{
	class SemanticStrategy;
}

namespace fUML::Semantics::Loci 
{
	class SemanticVisitor;
}

// base class includes
#include "fUML/Semantics/Loci/ExecutionFactoryL2.hpp"

// enum includes


//*********************************
namespace fUML::Semantics::Loci 
{
	/*!
	 */
	class ExecutionFactoryL3:virtual public ExecutionFactoryL2
	{
		public:
 			ExecutionFactoryL3(const ExecutionFactoryL3 &) {}
			ExecutionFactoryL3& operator=(ExecutionFactoryL3 const&) = delete;

		protected:
			ExecutionFactoryL3(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExecutionFactoryL3() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> instantiateVisitor(std::shared_ptr<uml::Element>  element) = 0;
			
			
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
#endif /* end of include guard: FUML_SEMANTICS_LOCI_EXECUTIONFACTORYL3_HPP */
