//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_CONSTRUCTSTRATEGY_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_CONSTRUCTSTRATEGY_HPP

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

namespace PSCS
{
	class PSCSFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::StructuredClassifiers 
{
	class Object;
}
namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_Object;
}
namespace uml 
{
	class Operation;
}

// base class includes
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"

// enum includes


//Includes from codegen annotation
#include "fUML/FUMLFactory.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	
	class CS_ConstructStrategy:virtual public fUML::Semantics::Loci::SemanticStrategy
	{
		public:
 			CS_ConstructStrategy(const CS_ConstructStrategy &) {}
			CS_ConstructStrategy& operator=(CS_ConstructStrategy const&) = delete;

		protected:
			CS_ConstructStrategy(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_ConstructStrategy() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> construct(std::shared_ptr<org.eclipse.uml2.uml.Operation> constructor,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> context) = 0;
			
			 
			virtual std::string getName() = 0;
			
			
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
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_CONSTRUCTSTRATEGY_HPP */
