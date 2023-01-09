//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INPUTPIN_HPP
#define UML_INPUTPIN_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;
template<class T, class ... U> class SubsetUnion;


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

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Action;
	class Activity;
	class ActivityEdge;
	class ActivityGroup;
	class ActivityPartition;
	class AddStructuralFeatureValueAction;
	class Behavior;
	class CallOperationAction;
	class Classifier;
	class Comment;
	class Dependency;
	class DestroyObjectAction;
	class InterruptibleActivityRegion;
	class InvocationAction;
	class Namespace;
	class RemoveStructuralFeatureValueAction;
	class State;
	class StringExpression;
	class StructuralFeatureAction;
	class StructuredActivityNode;
	class Type;
	class ValueSpecification;
	class WriteStructuralFeatureAction;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Pin.hpp"

// enum includes
#include "uml/ObjectNodeOrderingKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An InputPin is a Pin that holds input values to be consumed by an Action.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API InputPin : virtual public Pin
	{
		public:
 			InputPin(const InputPin &) {}

		protected:
			InputPin(){}
			//Additional constructors for the containments back reference
			InputPin(std::weak_ptr<uml::Action> par_action);

			//Additional constructors for the containments back reference
			InputPin(std::weak_ptr<uml::Activity> par_activity);

			//Additional constructors for the containments back reference
			InputPin(std::weak_ptr<uml::AddStructuralFeatureValueAction> par_addStructuralFeatureValueAction);

			//Additional constructors for the containments back reference
			InputPin(std::weak_ptr<uml::CallOperationAction> par_callOperationAction);

			//Additional constructors for the containments back reference
			InputPin(std::weak_ptr<uml::DestroyObjectAction> par_destroyObjectAction);

			//Additional constructors for the containments back reference
			InputPin(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);

			//Additional constructors for the containments back reference
			InputPin(std::weak_ptr<uml::InvocationAction> par_invocationAction);

			//Additional constructors for the containments back reference
			InputPin(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			InputPin(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			InputPin(std::weak_ptr<uml::RemoveStructuralFeatureValueAction> par_removeStructuralFeatureValueAction);

			//Additional constructors for the containments back reference
			InputPin(std::weak_ptr<uml::StructuralFeatureAction> par_structuralFeatureAction);

			//Additional constructors for the containments back reference
			InputPin(std::weak_ptr<uml::WriteStructuralFeatureAction> par_writeStructuralFeatureAction);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~InputPin() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<uml::Action> getAction() const = 0;
			virtual std::weak_ptr<uml::AddStructuralFeatureValueAction> getAddStructuralFeatureValueAction() const = 0;
			virtual void setAddStructuralFeatureValueAction(std::weak_ptr<uml::AddStructuralFeatureValueAction>) = 0;
			virtual std::weak_ptr<uml::CallOperationAction> getCallOperationAction() const = 0;
			virtual void setCallOperationAction(std::weak_ptr<uml::CallOperationAction>) = 0;
			virtual std::weak_ptr<uml::DestroyObjectAction> getDestroyObjectAction() const = 0;
			virtual void setDestroyObjectAction(std::weak_ptr<uml::DestroyObjectAction>) = 0;
			virtual std::weak_ptr<uml::InvocationAction> getInvocationAction() const = 0;
			virtual void setInvocationAction(std::weak_ptr<uml::InvocationAction>) = 0;
			virtual std::weak_ptr<uml::RemoveStructuralFeatureValueAction> getRemoveStructuralFeatureValueAction() const = 0;
			virtual void setRemoveStructuralFeatureValueAction(std::weak_ptr<uml::RemoveStructuralFeatureValueAction>) = 0;
			virtual std::weak_ptr<uml::StructuralFeatureAction> getStructuralFeatureAction() const = 0;
			virtual void setStructuralFeatureAction(std::weak_ptr<uml::StructuralFeatureAction>) = 0;
			virtual std::weak_ptr<uml::WriteStructuralFeatureAction> getWriteStructuralFeatureAction() const = 0;
			virtual void setWriteStructuralFeatureAction(std::weak_ptr<uml::WriteStructuralFeatureAction>) = 0;

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
			std::weak_ptr<uml::Action> m_action;
			std::weak_ptr<uml::AddStructuralFeatureValueAction> m_addStructuralFeatureValueAction;
			std::weak_ptr<uml::CallOperationAction> m_callOperationAction;
			std::weak_ptr<uml::DestroyObjectAction> m_destroyObjectAction;
			std::weak_ptr<uml::InvocationAction> m_invocationAction;
			std::weak_ptr<uml::RemoveStructuralFeatureValueAction> m_removeStructuralFeatureValueAction;
			std::weak_ptr<uml::StructuralFeatureAction> m_structuralFeatureAction;
			std::weak_ptr<uml::WriteStructuralFeatureAction> m_writeStructuralFeatureAction;
	};
}
#endif /* end of include guard: UML_INPUTPIN_HPP */
