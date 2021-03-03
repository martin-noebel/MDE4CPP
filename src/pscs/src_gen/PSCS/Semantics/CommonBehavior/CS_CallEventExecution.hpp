//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_COMMONBEHAVIOR_CS_CALLEVENTEXECUTION_HPP
#define PSCS_SEMANTICS_COMMONBEHAVIOR_CS_CALLEVENTEXECUTION_HPP


#include <memory>
#include <string>
// forward declarations


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

namespace PSCS
{
	class PSCSFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::CommonBehavior 
{
	class EventOccurrence;
	class ObjectActivation;
	class ParameterValue;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers 
{
	class FeatureValue;
}
namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_InteractionPoint;
}
namespace uml 
{
	class Behavior;
	class Classifier;
}

// base class includes
#include "fUML/Semantics/CommonBehavior/CallEventExecution.hpp"

// enum includes



//*********************************
namespace PSCS::Semantics::CommonBehavior 
{
	
	class CS_CallEventExecution: virtual public fUML::Semantics::CommonBehavior::CallEventExecution
	{
		public:
 			CS_CallEventExecution(const CS_CallEventExecution &) {}

		protected:
			CS_CallEventExecution(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_CallEventExecution() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() = 0; 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> createEventOccurrence() = 0; 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> getInteractionPoint() const = 0;
			
			virtual void setInteractionPoint(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> m_interactionPoint;

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: PSCS_SEMANTICS_COMMONBEHAVIOR_CS_CALLEVENTEXECUTION_HPP */
