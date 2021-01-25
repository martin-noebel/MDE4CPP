//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_OBJECT_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_OBJECT_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 



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
namespace fUML::Semantics::CommonBehavior 
{
	class EventOccurrence;
	class Execution;
	class ObjectActivation;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers 
{
	class FeatureValue;
}
namespace fUML::Semantics::StructuredClassifiers 
{
	class Reference;
}
namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_InteractionPoint;
	class CS_Link;
	class CS_Object;
}
namespace uml 
{
	class Class;
	class Classifier;
	class Interface;
	class Operation;
	class Port;
	class StructuralFeature;
}

// base class includes
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"

// enum includes
#include "PSCS/Semantics/StructuredClassifiers/CS_LinkKind.hpp"

#include "uml/ConnectorKind.hpp"


//Includes from codegen annotation
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_RequestPropagationStrategy.hpp"
#include "PSCS/Semantics/CommonBehavior/CS_CallEventExecution.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_StructuralFeatureOfInterfaceAccessStrategy.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_DispatchOperationOfInterfaceStrategy.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_LinkKind.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "uml/ConnectorKind.hpp"
#include "uml/InterfaceRealization.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Actions/CallOperationActionActivation.hpp"
#include "fUML/Semantics/Actions/SendSignalActionActivation.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Loci/ChoiceStrategy.hpp"

//*********************************
namespace PSCS::Semantics::StructuredClassifiers 
{
	
	class CS_Object:virtual public fUML::Semantics::StructuredClassifiers::Object
	{
		public:
 			CS_Object(const CS_Object &) {}
			CS_Object& operator=(CS_Object const&) = delete;

		protected:
			CS_Object(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_Object() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual bool checkAllParents(std::shared_ptr<org.eclipse.uml2.uml.Classifier> type,std::shared_ptr<org.eclipse.uml2.uml.Classifier> classifier) = 0;
			
			 
			virtual bool contains(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object) = 0;
			
			 
			virtual bool directlyContains(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object) = 0;
			
			 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchIn(std::shared_ptr<org.eclipse.uml2.uml.Operation> operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) = 0;
			
			 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchIn(std::shared_ptr<org.eclipse.uml2.uml.Operation> operation,std::shared_ptr<org.eclipse.uml2.uml.Port> onPort) = 0;
			
			 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchOut(std::shared_ptr<org.eclipse.uml2.uml.Operation> operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) = 0;
			
			 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchOut(std::shared_ptr<org.eclipse.uml2.uml.Operation> operation,std::shared_ptr<org.eclipse.uml2.uml.Port> onPort) = 0;
			
			 
			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object> > getDirectContainers() = 0;
			
			 
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> getFeatureValue(std::shared_ptr<org.eclipse.uml2.uml.StructuralFeature> feature) = 0;
			
			 
			virtual PSCS::Semantics::StructuredClassifiers::CS_LinkKind getLinkKind(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) = 0;
			
			 
			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link> > getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) = 0;
			
			 
			virtual bool hasValueForAFeature(std::shared_ptr<fUML::Semantics::Values::Value> value) = 0;
			
			 
			virtual bool isDescendant(std::shared_ptr<org.eclipse.uml2.uml.Interface> contract,std::shared_ptr<org.eclipse.uml2.uml.Interface> interface_) = 0;
			
			 
			virtual bool isOperationProvided(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference,std::shared_ptr<org.eclipse.uml2.uml.Operation> operation) = 0;
			
			 
			virtual bool isOperationRequired(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference,std::shared_ptr<org.eclipse.uml2.uml.Operation> operation) = 0;
			
			 
			virtual bool realizesInterface(std::shared_ptr<org.eclipse.uml2.uml.Class> type,std::shared_ptr<org.eclipse.uml2.uml.Interface> interface_) = 0;
			
			 
			virtual std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference> > selectTargetsForDispatching(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint,uml::ConnectorKind connectorKind,std::shared_ptr<org.eclipse.uml2.uml.Operation> operation,bool toInternal) = 0;
			
			 
			virtual std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference> > selectTargetsForSending(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> link,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint,uml::ConnectorKind connectorKind,bool toInternal) = 0;
			
			 
			virtual void sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) = 0;
			
			 
			virtual void sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<org.eclipse.uml2.uml.Port> onPort) = 0;
			
			 
			virtual void sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint) = 0;
			
			 
			virtual void sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence,std::shared_ptr<org.eclipse.uml2.uml.Port> onPort) = 0;
			
			 
			virtual void setFeatureValue(std::shared_ptr<org.eclipse.uml2.uml.StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value> > values,int position) = 0;
			
			
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
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_OBJECT_HPP */
