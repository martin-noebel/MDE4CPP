//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CLAUSE_HPP
#define UML_CLAUSE_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 


class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Comment;
	class ExecutableNode;
	class OutputPin;
}

// base class includes
#include "uml/Element.hpp"

// enum includes


//Includes from codegen annotation

//*********************************
namespace uml 
{
	/*!
	A Clause is an Element that represents a single branch of a ConditionalNode, including a test and a body section. The body section is executed only if (but not necessarily if) the test section evaluates to true.
	<p>From package UML::Actions.</p>
	*/
	
	class Clause:virtual public Element
	{
		public:
 			Clause(const Clause &) {}
			Clause& operator=(Clause const&) = delete;

		protected:
			Clause(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Clause() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The bodyOutput Pins are OutputPins on Actions in the body of the Clause.
			_'body'.oclAsType(Action).allActions().output->includesAll(bodyOutput)
			*/
			 
			virtual bool body_output_pins(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			The decider Pin must be on an Action in the test section of the Clause and must be of type Boolean with multiplicity 1..1.
			test.oclAsType(Action).allActions().output->includes(decider) and
			decider.type = Boolean and
			decider.is(1,1)
			*/
			 
			virtual bool decider_output(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			The test and body parts of a ConditionalNode must be disjoint with each other.
			test->intersection(_'body')->isEmpty()
			*/
			 
			virtual bool test_and_body(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The set of ExecutableNodes that are executed if the test evaluates to true and the Clause is chosen over other Clauses within the ConditionalNode that also have tests that evaluate to true.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExecutableNode>> getBody() const = 0;
			
			
			/*!
			The OutputPins on Actions within the body section whose values are moved to the result OutputPins of the containing ConditionalNode after execution of the body.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::OutputPin>> getBodyOutput() const = 0;
			
			
			/*!
			An OutputPin on an Action in the test section whose Boolean value determines the result of the test.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin > getDecider() const = 0;
			
			/*!
			An OutputPin on an Action in the test section whose Boolean value determines the result of the test.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setDecider(std::shared_ptr<uml::OutputPin> _decider) = 0;
			
			/*!
			A set of Clauses whose tests must all evaluate to false before this Clause can evaluate its test.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Clause>> getPredecessorClause() const = 0;
			
			
			/*!
			A set of Clauses that may not evaluate their tests unless the test for this Clause evaluates to false.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Clause>> getSuccessorClause() const = 0;
			
			
			/*!
			The set of ExecutableNodes that are executed in order to provide a test result for the Clause.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExecutableNode>> getTest() const = 0;
			
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The set of ExecutableNodes that are executed if the test evaluates to true and the Clause is chosen over other Clauses within the ConditionalNode that also have tests that evaluate to true.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::ExecutableNode>> m_body;/*!
			The OutputPins on Actions within the body section whose values are moved to the result OutputPins of the containing ConditionalNode after execution of the body.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::OutputPin>> m_bodyOutput;/*!
			An OutputPin on an Action in the test section whose Boolean value determines the result of the test.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::OutputPin > m_decider;/*!
			A set of Clauses whose tests must all evaluate to false before this Clause can evaluate its test.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Clause>> m_predecessorClause;/*!
			A set of Clauses that may not evaluate their tests unless the test for this Clause evaluates to false.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Clause>> m_successorClause;/*!
			The set of ExecutableNodes that are executed in order to provide a test result for the Clause.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::ExecutableNode>> m_test;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_CLAUSE_HPP */
