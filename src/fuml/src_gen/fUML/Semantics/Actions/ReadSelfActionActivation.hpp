//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_READSELFACTIONACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_READSELFACTIONACTIVATION_HPP

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
#include "fUML/Semantics/Actions/ActionActivation.hpp"

// enum includes


//Includes from codegen annotation
#include "uml/ReadSelfAction.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	
	class ReadSelfActionActivation:virtual public ActionActivation
	{
		public:
 			ReadSelfActionActivation(const ReadSelfActionActivation &) {}
			ReadSelfActionActivation& operator=(ReadSelfActionActivation const&) = delete;

		protected:
			ReadSelfActionActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ReadSelfActionActivation() {}

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
			
			virtual std::shared_ptr<org.eclipse.uml2.uml.ReadSelfAction > getReadSelfAction() const = 0;
			
			
			virtual void setReadSelfAction(std::shared_ptr<org.eclipse.uml2.uml.ReadSelfAction> _readSelfAction) = 0;
			
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'readSelfAction'*/
			
			virtual void setAction(std::shared_ptr<org.eclipse.uml2.uml.Action> _action) = 0;
			
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'readSelfAction'*/
			
			virtual void setNode(std::shared_ptr<org.eclipse.uml2.uml.ActivityNode> _node) = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<org.eclipse.uml2.uml.ReadSelfAction > m_readSelfAction;

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
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_READSELFACTIONACTIVATION_HPP */
