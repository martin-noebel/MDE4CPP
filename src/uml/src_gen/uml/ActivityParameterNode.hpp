//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIVITYPARAMETERNODE_HPP
#define UML_ACTIVITYPARAMETERNODE_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations


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
	class Parameter;
	class State;
	class StringExpression;
	class StructuredActivityNode;
	class Type;
	class ValueSpecification;
}

// base class includes
#include "uml/ObjectNode.hpp"

// enum includes
#include "uml/ObjectNodeOrderingKind.hpp"

#include "uml/VisibilityKind.hpp"


//Includes from codegen annotation

//*********************************
namespace uml 
{
	/*!
	An ActivityParameterNode is an ObjectNode for accepting values from the input Parameters or providing values to the output Parameters of an Activity.
	<p>From package UML::Activities.</p>
	*/
	
	class ActivityParameterNode:virtual public ObjectNode
	{
		public:
 			ActivityParameterNode(const ActivityParameterNode &) {}
			ActivityParameterNode& operator=(ActivityParameterNode const&) = delete;

		protected:
			ActivityParameterNode(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityParameterNode() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The parameter of an ActivityParameterNode must be from the containing Activity.
			activity.ownedParameter->includes(parameter)
			*/
			 
			virtual bool has_parameters(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			An ActivityParameterNode may have all incoming ActivityEdges or all outgoing ActivityEdges, but it must not have both incoming and outgoing ActivityEdges.
			incoming->isEmpty() or outgoing->isEmpty()
			*/
			 
			virtual bool no_edges(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			An ActivityParameterNode with no incoming ActivityEdges and one or more outgoing ActivityEdges must have a parameter with direction in or inout.
			(outgoing->notEmpty() and incoming->isEmpty()) implies 
				(parameter.direction = ParameterDirectionKind::_'in' or 
				 parameter.direction = ParameterDirectionKind::inout)
			*/
			 
			virtual bool no_incoming_edges(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			An ActivityParameterNode with no outgoing ActivityEdges and one or more incoming ActivityEdges must have a parameter with direction out, inout, or return.
			(incoming->notEmpty() and outgoing->isEmpty()) implies 
				(parameter.direction = ParameterDirectionKind::out or 
				 parameter.direction = ParameterDirectionKind::inout or 
				 parameter.direction = ParameterDirectionKind::return)
			*/
			 
			virtual bool no_outgoing_edges(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			The type of an ActivityParameterNode is the same as the type of its parameter.
			type = parameter.type
			*/
			 
			virtual bool same_type(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The Parameter for which the ActivityParameterNode will be accepting or providing values.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::Parameter > getParameter() const = 0;
			
			/*!
			The Parameter for which the ActivityParameterNode will be accepting or providing values.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setParameter(std::shared_ptr<uml::Parameter> _parameter) = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The Parameter for which the ActivityParameterNode will be accepting or providing values.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::Parameter > m_parameter;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_ACTIVITYPARAMETERNODE_HPP */
