//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_VALUESPECIFICATIONACTION_HPP
#define UML_VALUESPECIFICATIONACTION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace uml 
{
	class Activity;
	class ActivityEdge;
	class ActivityGroup;
	class ActivityPartition;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ExceptionHandler;
	class InputPin;
	class InterruptibleActivityRegion;
	class Namespace;
	class OutputPin;
	class StringExpression;
	class StructuredActivityNode;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Action.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A ValueSpecificationAction is an Action that evaluates a ValueSpecification and provides a result.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ValueSpecificationAction : virtual public Action
	{
		public:
 			ValueSpecificationAction(const ValueSpecificationAction &) {}

		protected:
			ValueSpecificationAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ValueSpecificationAction() {}

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
			The OutputPin on which the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getResult() const = 0;
			/*!
			The OutputPin on which the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(std::shared_ptr<uml::OutputPin>) = 0;
			/*!
			The ValueSpecification to be evaluated.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification> getValue() const = 0;
			/*!
			The ValueSpecification to be evaluated.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setValue(std::shared_ptr<uml::ValueSpecification>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The OutputPin on which the result value is placed.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::OutputPin> m_result;
			/*!
			The ValueSpecification to be evaluated.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification> m_value;
	};
}
#endif /* end of include guard: UML_VALUESPECIFICATIONACTION_HPP */
