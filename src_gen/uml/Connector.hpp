//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONNECTOR_HPP
#define UML_CONNECTOR_HPP

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
	class Association;
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
	class Connector;
}

namespace uml 
{
	class ConnectorEnd;
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
	class Feature;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class RedefinableElement;
}

namespace uml 
{
	class StringExpression;
}

// base class includes
#include "Feature.hpp"

// enum includes
#include "ConnectorKind.hpp"

#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A Connector specifies links that enables communication between two or more instances. In contrast to Associations, which specify links between any instance of the associated Classifiers, Connectors specify links between instances playing the connected parts only.
	<p>From package UML::StructuredClassifiers.</p> */
	class Connector:virtual public Feature	{
		public:
 			Connector(const Connector &) {}
			Connector& operator=(Connector const&) = delete;
	
		protected:
			Connector(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~Connector() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 The types of the ConnectableElements that the ends of a Connector are attached to must conform to the types of the ends of the Association that types the Connector, if any.
			type<>null implies 
			  let noOfEnds : Integer = end->size() in 
			  (type.memberEnd->size() = noOfEnds) and Sequence{1..noOfEnds}->forAll(i | end->at(i).role.type.conformsTo(type.memberEnd->at(i).type)) */ 
			virtual bool
			 types(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The ConnectableElements attached as roles to each ConnectorEnd owned by a Connector must be owned or inherited roles of the Classifier that owned the Connector, or they must be Ports of such roles.
			structuredClassifier <> null
			and
			  end->forAll( e | structuredClassifier.allRoles()->includes(e.role)
			or
			  e.role.oclIsKindOf(Port) and structuredClassifier.allRoles()->includes(e.partWithPort)) */ 
			virtual bool
			 roles(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 Derivation for Connector::/kind : ConnectorKind
			result = (if end->exists(
					role.oclIsKindOf(Port) 
					and partWithPort->isEmpty()
					and not role.oclAsType(Port).isBehavior)
			then ConnectorKind::delegation 
			else ConnectorKind::assembly 
			endif)
			<p>From package UML::StructuredClassifiers.</p> */ 
			virtual ConnectorKind
			 getKind()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Indicates the kind of Connector. This is derived: a Connector with one or more ends connected to a Port which is not on a Part and which is not a behavior port is a delegation; otherwise it is an assembly.
			<p>From package UML::StructuredClassifiers.</p> */ 
			virtual ConnectorKind getKind() const = 0;
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The set of Behaviors that specify the valid interaction patterns across the Connector.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual 	std::shared_ptr< Bag<uml::Behavior> >
			 getContract() const = 0;
			
			/*!
			 A Connector has at least two ConnectorEnds, each representing the participation of instances of the Classifiers typing the ConnectableElements attached to the end. The set of ConnectorEnds is ordered.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual 		std::shared_ptr<Subset<uml::ConnectorEnd, uml::Element > >
			 getEnd() const = 0;
			
			/*!
			 A Connector may be redefined when its containing Classifier is specialized. The redefining Connector may have a type that specializes the type of the redefined Connector. The types of the ConnectorEnds of the redefining Connector may specialize the types of the ConnectorEnds of the redefined Connector. The properties of the ConnectorEnds of the redefining Connector may be replaced.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual 		std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement > >
			 getRedefinedConnector() const = 0;
			
			/*!
			 An optional Association that classifies links corresponding to this Connector.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual std::shared_ptr<uml::Association > getType() const = 0;
			
			/*!
			 An optional Association that classifies links corresponding to this Connector.
			<p>From package UML::StructuredClassifiers.</p> */
			virtual void setType(std::shared_ptr<uml::Association> _type_type) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 Indicates the kind of Connector. This is derived: a Connector with one or more ends connected to a Port which is not on a Part and which is not a behavior port is a delegation; otherwise it is an assembly.
			<p>From package UML::StructuredClassifiers.</p> */ 
			ConnectorKind m_kind ;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 The set of Behaviors that specify the valid interaction patterns across the Connector.
			<p>From package UML::StructuredClassifiers.</p> */
				std::shared_ptr< Bag<uml::Behavior> >
			 m_contract;
			/*!
			 A Connector has at least two ConnectorEnds, each representing the participation of instances of the Classifiers typing the ConnectableElements attached to the end. The set of ConnectorEnds is ordered.
			<p>From package UML::StructuredClassifiers.</p> */
					std::shared_ptr<Subset<uml::ConnectorEnd, uml::Element > >
			 m_end;
			/*!
			 A Connector may be redefined when its containing Classifier is specialized. The redefining Connector may have a type that specializes the type of the redefined Connector. The types of the ConnectorEnds of the redefining Connector may specialize the types of the ConnectorEnds of the redefined Connector. The properties of the ConnectorEnds of the redefining Connector may be replaced.
			<p>From package UML::StructuredClassifiers.</p> */
					std::shared_ptr<Subset<uml::Connector, uml::RedefinableElement > >
			 m_redefinedConnector;
			/*!
			 An optional Association that classifies links corresponding to this Connector.
			<p>From package UML::StructuredClassifiers.</p> */
			std::shared_ptr<uml::Association > m_type;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Element > getOwner() const = 0;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Union<uml::RedefinableElement> > getRedefinedElement() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const = 0; 
	};

}
#endif /* end of include guard: UML_CONNECTOR_HPP */

