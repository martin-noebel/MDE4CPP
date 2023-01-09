//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_STRUCTUREDACTIVITYNODEACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_STRUCTUREDACTIVITYNODEACTIVATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 

class Any;

//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
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
	class ExecutableNode;
	class OutputPin;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/Actions/ActionActivation.hpp"




//*********************************
namespace fUML::Semantics::Actions 
{
	
	class FUML_API StructuredActivityNodeActivation : virtual public ActionActivation
	{
		public:
 			StructuredActivityNodeActivation(const StructuredActivityNodeActivation &) {}

		protected:
			StructuredActivityNodeActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StructuredActivityNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> completeAction() = 0;
			virtual void createEdgeInstances() = 0;
			virtual void createNodeActivations() = 0;
			virtual void doAction() = 0;
			virtual void doStructuredActivity() = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> getNodeActivation(std::shared_ptr<uml::ActivityNode> node) = 0;
			virtual std::shared_ptr<Bag<Any>> getPinValues(std::shared_ptr<uml::OutputPin> pin) = 0;
			virtual bool isSourceFor(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance) = 0;
			virtual bool isSuspended() = 0;
			virtual std::shared_ptr<Bag<uml::ActivityNode>> makeActivityNodeList(std::shared_ptr<Bag<uml::ExecutableNode>> nodes) = 0;
			virtual void putPinValues(std::shared_ptr<uml::OutputPin> pin, std::shared_ptr<Bag<Any>> values) = 0;
			virtual void resume() = 0;
			virtual void terminate() = 0;
			virtual void terminateAll() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> getActivationGroup() const = 0;
			virtual void setActivationGroup(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> m_activationGroup;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_STRUCTUREDACTIVITYNODEACTIVATION_HPP */
