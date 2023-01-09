//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXECUTIONSPECIFICATION_HPP
#define UML_EXECUTIONSPECIFICATION_HPP


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
	class GeneralOrdering;
	class Interaction;
	class InteractionOperand;
	class Lifeline;
	class Namespace;
	class OccurrenceSpecification;
	class StringExpression;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/InteractionFragment.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An ExecutionSpecification is a specification of the execution of a unit of Behavior or Action within the Lifeline. The duration of an ExecutionSpecification is represented by two OccurrenceSpecifications, the start OccurrenceSpecification and the finish OccurrenceSpecification.
	<p>From package UML::Interactions.</p>
	*/
	
	class UML_API ExecutionSpecification : virtual public InteractionFragment
	{
		public:
 			ExecutionSpecification(const ExecutionSpecification &) {}

		protected:
			ExecutionSpecification(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExecutionSpecification() {}

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
			References the OccurrenceSpecification that designates the finish of the Action or Behavior.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::OccurrenceSpecification> getFinish() const = 0;
			/*!
			References the OccurrenceSpecification that designates the finish of the Action or Behavior.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setFinish(std::shared_ptr<uml::OccurrenceSpecification>) = 0;
			/*!
			References the OccurrenceSpecification that designates the start of the Action or Behavior.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::OccurrenceSpecification> getStart() const = 0;
			/*!
			References the OccurrenceSpecification that designates the start of the Action or Behavior.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setStart(std::shared_ptr<uml::OccurrenceSpecification>) = 0;

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
			References the OccurrenceSpecification that designates the finish of the Action or Behavior.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::OccurrenceSpecification> m_finish;
			/*!
			References the OccurrenceSpecification that designates the start of the Action or Behavior.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::OccurrenceSpecification> m_start;
	};
}
#endif /* end of include guard: UML_EXECUTIONSPECIFICATION_HPP */
