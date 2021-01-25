//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_HPP

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
namespace fUML::Semantics::SimpleClassifiers 
{
	class StructuredValue;
}
namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_Link;
	class CS_Reference;
}
namespace fUML::Semantics::Values 
{
	class Value;
}
namespace uml 
{
	class Action;
	class ActivityNode;
	class RemoveStructuralFeatureValueAction;
	class StructuralFeature;
}

// base class includes
#include "fUML/Semantics/Actions/RemoveStructuralFeatureValueActivation.hpp"

// enum includes


//Includes from codegen annotation
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

#include "uml/RemoveStructuralFeatureValueAction.hpp"
#include "uml/Association.hpp"
#include "uml/Port.hpp"
#include "fUML/Semantics/SimpleClassifiers/UnlimitedNaturalValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "fUML/Semantics/Activities/ActivityExecution.hpp"
#include "uml/InputPin.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	
	class CS_RemoveStructuralFeatureValueActionActivation:virtual public fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation
	{
		public:
 			CS_RemoveStructuralFeatureValueActionActivation(const CS_RemoveStructuralFeatureValueActionActivation &) {}
			CS_RemoveStructuralFeatureValueActionActivation& operator=(CS_RemoveStructuralFeatureValueActionActivation const&) = delete;

		protected:
			CS_RemoveStructuralFeatureValueActionActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_RemoveStructuralFeatureValueActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual void doAction() = 0;
			
			 
			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link> > getLinksToDestroy(std::shared_ptr<fUML::Semantics::SimpleClassifiers::StructuredValue> value,std::shared_ptr<org.eclipse.uml2.uml.StructuralFeature> feature,std::shared_ptr<fUML::Semantics::Values::Value> removedValue) = 0;
			
			 
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > getPotentialLinkEnds(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> context,std::shared_ptr<org.eclipse.uml2.uml.StructuralFeature> feature) = 0;
			
			
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
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_HPP */
