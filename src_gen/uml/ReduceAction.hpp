//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REDUCEACTION_HPP
#define UML_REDUCEACTION_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) /**/
#else
    #define ACT_DEBUG(a) a
#endif

#include <string>
#include <map>
#include <vector>
#include "SubsetUnion.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace uml 
{
	class Action;
}

namespace uml 
{
	class Activity;
}

namespace uml 
{
	class ActivityEdge;
}

namespace uml 
{
	class ActivityGroup;
}

namespace uml 
{
	class ActivityNode;
}

namespace uml 
{
	class ActivityPartition;
}

namespace uml 
{
	class Behavior;
}

namespace uml 
{
	class Classifier;
}

namespace uml 
{
	class Comment;
}

namespace uml 
{
	class Constraint;
}

namespace uml 
{
	class Dependency;
}

namespace ecore 
{
	class EAnnotation;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class ExceptionHandler;
}

namespace uml 
{
	class InputPin;
}

namespace uml 
{
	class InterruptibleActivityRegion;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class OutputPin;
}

namespace uml 
{
	class RedefinableElement;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class StructuredActivityNode;
}

// base class includes
#include "Action.hpp"

// enum includes
#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A ReduceAction is an Action that reduces a collection to a single value by repeatedly combining the elements of the collection using a reducer Behavior.
	<p>From package UML::Actions.</p> */
	class ReduceAction:virtual public Action	{
		public:
 			ReduceAction(const ReduceAction &) {}
			ReduceAction& operator=(ReduceAction const&) = delete;
	
		protected:
			ReduceAction(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~ReduceAction() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 The reducer Behavior must have two input ownedParameters and one output ownedParameter, where the type of the output Parameter and the type of elements of the input collection conform to the types of the input Parameters.
			let inputs: OrderedSet(Parameter) = reducer.inputParameters() in
			let outputs: OrderedSet(Parameter) = reducer.outputParameters() in
			inputs->size()=2 and outputs->size()=1 and
			inputs.type->forAll(t | 
				outputs.type->forAll(conformsTo(t)) and 
				-- Note that the following only checks the case when the collection is via multiple tokens.
				collection.upperBound()>1 implies collection.type.conformsTo(t)) */ 
			virtual bool
			 reducer_inputs_output(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The type of the collection InputPin must be a collection. */ 
			virtual bool
			 input_type_is_collection(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The type of the output of the reducer Behavior must conform to the type of the result OutputPin.
			reducer.outputParameters().type->forAll(conformsTo(result.type)) */ 
			virtual bool
			 output_types_are_compatible(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Indicates whether the order of the input collection should determine the order in which the reducer Behavior is applied to its elements.
			<p>From package UML::Actions.</p> */ 
			virtual bool getIsOrdered() const = 0;
			
			/*!
			 Indicates whether the order of the input collection should determine the order in which the reducer Behavior is applied to its elements.
			<p>From package UML::Actions.</p> */ 
			virtual void setIsOrdered (bool _isOrdered)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The InputPin that provides the collection to be reduced.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::InputPin > getCollection() const = 0;
			
			/*!
			 The InputPin that provides the collection to be reduced.
			<p>From package UML::Actions.</p> */
			virtual void setCollection(std::shared_ptr<uml::InputPin> _collection_collection) = 0;
			/*!
			 A Behavior that is repreatedly applied to two elements of the input collection to produce a value that is of the same type as elements of the collection.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::Behavior > getReducer() const = 0;
			
			/*!
			 A Behavior that is repreatedly applied to two elements of the input collection to produce a value that is of the same type as elements of the collection.
			<p>From package UML::Actions.</p> */
			virtual void setReducer(std::shared_ptr<uml::Behavior> _reducer_reducer) = 0;
			/*!
			 The output pin on which the result value is placed.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::OutputPin > getResult() const = 0;
			
			/*!
			 The output pin on which the result value is placed.
			<p>From package UML::Actions.</p> */
			virtual void setResult(std::shared_ptr<uml::OutputPin> _result_result) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 Indicates whether the order of the input collection should determine the order in which the reducer Behavior is applied to its elements.
			<p>From package UML::Actions.</p> */ 
			bool m_isOrdered =  false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 The InputPin that provides the collection to be reduced.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<uml::InputPin > m_collection;
			/*!
			 A Behavior that is repreatedly applied to two elements of the input collection to produce a value that is of the same type as elements of the collection.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<uml::Behavior > m_reducer;
			/*!
			 The output pin on which the result value is placed.
			<p>From package UML::Actions.</p> */
			std::shared_ptr<uml::OutputPin > m_result;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
			 getInput() const = 0;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Element > getOwner() const = 0;/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Union<uml::ActivityGroup> > getInGroup() const = 0;/*!
			 The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > >
			 getOutput() const = 0;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Union<uml::RedefinableElement> > getRedefinedElement() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const = 0; 
	};

}
#endif /* end of include guard: UML_REDUCEACTION_HPP */

