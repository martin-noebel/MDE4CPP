//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PIN_HPP
#define UML_PIN_HPP


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
	class Activity;
	class ActivityEdge;
	class ActivityGroup;
	class ActivityPartition;
	class Behavior;
	class Classifier;
	class Comment;
	class Dependency;
	class InterruptibleActivityRegion;
	class Namespace;
	class State;
	class StringExpression;
	class StructuredActivityNode;
	class Type;
	class ValueSpecification;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/MultiplicityElement.hpp"
#include "uml/ObjectNode.hpp"

// enum includes
#include "uml/ObjectNodeOrderingKind.hpp"
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A Pin is an ObjectNode and MultiplicityElement that provides input values to an Action or accepts output values from an Action.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API Pin : virtual public MultiplicityElement, virtual public ObjectNode
	{
		public:
 			Pin(const Pin &) {}

		protected:
			Pin(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Pin() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates whether the Pin provides data to the Action or just controls how the Action executes.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsControl() const = 0;
			/*!
			Indicates whether the Pin provides data to the Action or just controls how the Action executes.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsControl (bool _isControl)= 0;

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
			/*!
			Indicates whether the Pin provides data to the Action or just controls how the Action executes.
			<p>From package UML::Actions.</p>
			*/
			
			bool m_isControl= false;
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: UML_PIN_HPP */
