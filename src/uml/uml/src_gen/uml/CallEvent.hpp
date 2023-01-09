//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CALLEVENT_HPP
#define UML_CALLEVENT_HPP


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

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Comment;
	class Dependency;
	class Namespace;
	class Operation;
	class Package;
	class StringExpression;
	class TemplateParameter;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/MessageEvent.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A CallEvent models the receipt by an object of a message invoking a call of an Operation.
	<p>From package UML::CommonBehavior.</p>
	*/
	
	class UML_API CallEvent : virtual public MessageEvent
	{
		public:
 			CallEvent(const CallEvent &) {}

		protected:
			CallEvent(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CallEvent() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			Designates the Operation whose invocation raised the CalEvent.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual std::shared_ptr<uml::Operation> getOperation() const = 0;
			/*!
			Designates the Operation whose invocation raised the CalEvent.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual void setOperation(std::shared_ptr<uml::Operation>) = 0;

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
			/*!
			Designates the Operation whose invocation raised the CalEvent.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			std::shared_ptr<uml::Operation> m_operation;
	};
}
#endif /* end of include guard: UML_CALLEVENT_HPP */
