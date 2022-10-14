//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TIMECONSTRAINT_HPP
#define UML_TIMECONSTRAINT_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace uml 
{
	class Comment;
	class Dependency;
	class Namespace;
	class Package;
	class StringExpression;
	class TemplateParameter;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/IntervalConstraint.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A TimeConstraint is a Constraint that refers to a TimeInterval.
	<p>From package UML::Values.</p>
	*/
	
	class UML_API TimeConstraint : virtual public IntervalConstraint
	{
		public:
 			TimeConstraint(const TimeConstraint &) {}

		protected:
			TimeConstraint(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TimeConstraint() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The value of firstEvent is related to the constrainedElement. If firstEvent is true, then the corresponding observation event is the first time instant the execution enters the constrainedElement. If firstEvent is false, then the corresponding observation event is the last time instant the execution is within the constrainedElement.
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool getFirstEvent() const = 0;
			/*!
			The value of firstEvent is related to the constrainedElement. If firstEvent is true, then the corresponding observation event is the first time instant the execution enters the constrainedElement. If firstEvent is false, then the corresponding observation event is the last time instant the execution is within the constrainedElement.
			<p>From package UML::Values.</p>
			*/
			 
			virtual void setFirstEvent (bool _firstEvent)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************

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
			/*!
			The value of firstEvent is related to the constrainedElement. If firstEvent is true, then the corresponding observation event is the first time instant the execution enters the constrainedElement. If firstEvent is false, then the corresponding observation event is the last time instant the execution is within the constrainedElement.
			<p>From package UML::Values.</p>
			*/
			
			bool m_firstEvent= true;
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: UML_TIMECONSTRAINT_HPP */
