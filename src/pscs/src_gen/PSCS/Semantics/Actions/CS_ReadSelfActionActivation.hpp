//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_READSELFACTIONACTIVATION_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_READSELFACTIONACTIVATION_HPP

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
namespace fUML::Semantics::Actions 
{
	class InputPinActivation;
	class OutputPinActivation;
	class PinActivation;
}
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityNodeActivationGroup;
	class Token;
}
namespace uml 
{
	class Action;
	class ActivityNode;
	class ReadSelfAction;
}

// base class includes
#include "fUML/Semantics/Actions/ReadSelfActionActivation.hpp"

// enum includes


//Includes from codegen annotation
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "uml/OutputPin.hpp"
#include "uml/ReadSelfAction.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	
	class CS_ReadSelfActionActivation:virtual public fUML::Semantics::Actions::ReadSelfActionActivation
	{
		public:
 			CS_ReadSelfActionActivation(const CS_ReadSelfActionActivation &) {}
			CS_ReadSelfActionActivation& operator=(CS_ReadSelfActionActivation const&) = delete;

		protected:
			CS_ReadSelfActionActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_ReadSelfActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual void doAction() = 0;
			
			
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
			
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_READSELFACTIONACTIVATION_HPP */
