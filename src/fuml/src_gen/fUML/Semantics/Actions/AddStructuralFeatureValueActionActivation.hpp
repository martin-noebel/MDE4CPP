//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_HPP

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
	class AddStructuralFeatureValueAction;
}

// base class includes
#include "fUML/Semantics/Actions/WriteStructuralFeatureActionActivation.hpp"

// enum includes


//Includes from codegen annotation
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/StructuredValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/UnlimitedNaturalValue.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "uml/AddStructuralFeatureValueAction.hpp"
#include "uml/Property.hpp"
#include "uml/InputPin.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	
	class AddStructuralFeatureValueActionActivation:virtual public WriteStructuralFeatureActionActivation
	{
		public:
 			AddStructuralFeatureValueActionActivation(const AddStructuralFeatureValueActionActivation &) {}
			AddStructuralFeatureValueActionActivation& operator=(AddStructuralFeatureValueActionActivation const&) = delete;

		protected:
			AddStructuralFeatureValueActionActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~AddStructuralFeatureValueActionActivation() {}

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
			
			virtual std::shared_ptr<org.eclipse.uml2.uml.AddStructuralFeatureValueAction > getAddStructuralFeatureValueAction() const = 0;
			
			
			virtual void setAddStructuralFeatureValueAction(std::shared_ptr<org.eclipse.uml2.uml.AddStructuralFeatureValueAction> _addStructuralFeatureValueAction) = 0;
			
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'addStructuralFeatureValueAction'*/
			
			virtual void setAction(std::shared_ptr<org.eclipse.uml2.uml.Action> _action) = 0;
			
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'addStructuralFeatureValueAction'*/
			
			virtual void setNode(std::shared_ptr<org.eclipse.uml2.uml.ActivityNode> _node) = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<org.eclipse.uml2.uml.AddStructuralFeatureValueAction > m_addStructuralFeatureValueAction;

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
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_HPP */
