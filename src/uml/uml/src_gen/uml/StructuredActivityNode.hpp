//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STRUCTUREDACTIVITYNODE_HPP
#define UML_STRUCTUREDACTIVITYNODE_HPP


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
	class ActivityPartition;
	class Classifier;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class ExceptionHandler;
	class InputPin;
	class InterruptibleActivityRegion;
	class OutputPin;
	class PackageImport;
	class PackageableElement;
	class StringExpression;
	class Variable;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Action.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/Namespace.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A StructuredActivityNode is an Action that is also an ActivityGroup and whose behavior is specified by the ActivityNodes and ActivityEdges it so contains. Unlike other kinds of ActivityGroup, a StructuredActivityNode owns the ActivityNodes and ActivityEdges it contains, and so a node or edge can only be directly contained in one StructuredActivityNode, though StructuredActivityNodes may be nested.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API StructuredActivityNode : virtual public Action, virtual public ActivityGroup, virtual public Namespace
	{
		public:
 			StructuredActivityNode(const StructuredActivityNode &) {}

		protected:
			StructuredActivityNode(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StructuredActivityNode() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Return those ActivityNodes contained immediately within the StructuredActivityNode that may act as sources of edges owned by the StructuredActivityNode.
			result = (node->union(input.oclAsType(ActivityNode)->asSet())->
			  union(node->select(oclIsKindOf(Action)).oclAsType(Action).output)->asSet())
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::ActivityNode>> sourceNodes() = 0;
			/*!
			Return those ActivityNodes contained immediately within the StructuredActivityNode that may act as targets of edges owned by the StructuredActivityNode.
			result = (node->union(output.oclAsType(ActivityNode)->asSet())->
			  union(node->select(oclIsKindOf(Action)).oclAsType(Action).input)->asSet())
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::ActivityNode>> targetNodes() = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			If true, then any object used by an Action within the StructuredActivityNode cannot be accessed by any Action outside the node until the StructuredActivityNode as a whole completes. Any concurrent Actions that would result in accessing such objects are required to have their execution deferred until the completion of the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getMustIsolate() const = 0;
			/*!
			If true, then any object used by an Action within the StructuredActivityNode cannot be accessed by any Action outside the node until the StructuredActivityNode as a whole completes. Any concurrent Actions that would result in accessing such objects are required to have their execution deferred until the completion of the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setMustIsolate (bool _mustIsolate)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The ActivityEdges immediately contained in the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge, uml::Element>> getEdge() const = 0;
			/*!
			The ActivityNodes immediately contained in the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode, uml::Element>> getNode() const = 0;
			/*!
			The InputPins owned by the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> getStructuredNodeInput() const = 0;
			/*!
			The OutputPins owned by the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> getStructuredNodeOutput() const = 0;
			/*!
			The Variables defined in the scope of the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> getVariable() const = 0;

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
			If true, then any object used by an Action within the StructuredActivityNode cannot be accessed by any Action outside the node until the StructuredActivityNode as a whole completes. Any concurrent Actions that would result in accessing such objects are required to have their execution deferred until the completion of the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			bool m_mustIsolate= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The ActivityEdges immediately contained in the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge, uml::Element>> m_edge;
			/*!
			The ActivityNodes immediately contained in the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode, uml::Element>> m_node;
			/*!
			The InputPins owned by the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> m_structuredNodeInput;
			/*!
			The OutputPins owned by the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> m_structuredNodeOutput;
			/*!
			The Variables defined in the scope of the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> m_variable;
	};
}
#endif /* end of include guard: UML_STRUCTUREDACTIVITYNODE_HPP */
