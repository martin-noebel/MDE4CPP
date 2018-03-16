//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_EXECUTIONFACTORYL2_HPP
#define FUML_EXECUTIONFACTORYL2_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations



//*********************************
// generated Includes

#include <map>

namespace persistence
{
	namespace interface
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

namespace fUML 
{
	class ExecutionFactoryL1;
}

namespace fUML 
{
	class Locus;
}

namespace fUML 
{
	class OpaqueBehaviorExecution;
}

namespace uml 
{
	class PrimitiveType;
}

namespace fUML 
{
	class SemanticStrategy;
}

namespace fUML 
{
	class SemanticVisitor;
}

// base class includes
#include "fUML/ExecutionFactoryL1.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class ExecutionFactoryL2:virtual public ExecutionFactoryL1
	{
		public:
 			ExecutionFactoryL2(const ExecutionFactoryL2 &) {}
			ExecutionFactoryL2& operator=(ExecutionFactoryL2 const&) = delete;

		protected:
			ExecutionFactoryL2(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExecutionFactoryL2() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::SemanticVisitor> instantiateVisitor(std::shared_ptr<uml::Element>  element)  = 0;
			
			
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
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_EXECUTIONFACTORYL2_HPP */
