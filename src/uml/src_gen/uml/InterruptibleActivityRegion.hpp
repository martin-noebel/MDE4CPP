//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERRUPTIBLEACTIVITYREGION_HPP
#define UML_INTERRUPTIBLEACTIVITYREGION_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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
	class ActivityNode;
	class Comment;
	class Dependency;
	class Namespace;
	class StringExpression;
}

// base class includes
#include "uml/ActivityGroup.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An InterruptibleActivityRegion is an ActivityGroup that supports the termination of tokens flowing in the portions of an activity within it.
	<p>From package UML::Activities.</p>
	*/
	
	class InterruptibleActivityRegion: virtual public ActivityGroup
	{
		public:
 			InterruptibleActivityRegion(const InterruptibleActivityRegion &) {}

		protected:
			InterruptibleActivityRegion(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~InterruptibleActivityRegion() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The interruptingEdges of an InterruptibleActivityRegion must have their source in the region and their target outside the region, but within the same Activity containing the region.
			interruptingEdge->forAll(edge | 
			  node->includes(edge.source) and node->excludes(edge.target) and edge.target.containingActivity() = inActivity)
			*/
			 
			virtual bool interrupting_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The ActivityEdges leaving the InterruptibleActivityRegion on which a traversing token will result in the termination of other tokens flowing in the InterruptibleActivityRegion.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ActivityEdge>> getInterruptingEdge() const = 0;
			
			/*!
			ActivityNodes immediately contained in the InterruptibleActivityRegion.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> getNode() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The ActivityEdges leaving the InterruptibleActivityRegion on which a traversing token will result in the termination of other tokens flowing in the InterruptibleActivityRegion.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::ActivityEdge>> m_interruptingEdge;/*!
			ActivityNodes immediately contained in the InterruptibleActivityRegion.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> m_node;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityNodes immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityNode>> getContainedNode() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_INTERRUPTIBLEACTIVITYREGION_HPP */
