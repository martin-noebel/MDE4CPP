//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIVITYPARTITION_HPP
#define UML_ACTIVITYPARTITION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


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

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/ActivityGroup.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An ActivityPartition is a kind of ActivityGroup for identifying ActivityNodes that have some characteristic in common.
	<p>From package UML::Activities.</p>
	*/
	
	class UML_API ActivityPartition : virtual public ActivityGroup
	{
		public:
 			ActivityPartition(const ActivityPartition &) {}

		protected:
			ActivityPartition(){}
			//Additional constructors for the containments back reference
			ActivityPartition(std::weak_ptr<uml::Activity> par_inActivity);

			//Additional constructors for the containments back reference
			ActivityPartition(std::weak_ptr<uml::Namespace> par_namespace);

			//Additional constructors for the containments back reference
			ActivityPartition(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			ActivityPartition(std::weak_ptr<uml::ActivityGroup> par_superGroup);

			//Additional constructors for the containments back reference
			ActivityPartition(std::weak_ptr<uml::ActivityPartition> par_superPartition);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityPartition() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Indicates whether the ActivityPartition groups other ActivityPartitions along a dimension.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool getIsDimension() const = 0;
			/*!
			Indicates whether the ActivityPartition groups other ActivityPartitions along a dimension.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual void setIsDimension (bool _isDimension)= 0;
			/*!
			Indicates whether the ActivityPartition represents an entity to which the partitioning structure does not apply.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual bool getIsExternal() const = 0;
			/*!
			Indicates whether the ActivityPartition represents an entity to which the partitioning structure does not apply.
			<p>From package UML::Activities.</p>
			*/
			 
			virtual void setIsExternal (bool _isExternal)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			ActivityEdges immediately contained in the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge>> getEdge() const = 0;
			/*!
			ActivityNodes immediately contained in the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> getNode() const = 0;
			/*!
			An Element represented by the functionality modeled within the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::Element> getRepresents() const = 0;
			/*!
			An Element represented by the functionality modeled within the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setRepresents(std::shared_ptr<uml::Element>) = 0;
			/*!
			Other ActivityPartitions immediately contained in this ActivityPartition (as its subgroups).
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> getSubpartition() const = 0;
			/*!
			Other ActivityPartitions immediately containing this ActivityPartition (as its superGroups).
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::ActivityPartition> getSuperPartition() const = 0;
			/*!
			Other ActivityPartitions immediately containing this ActivityPartition (as its superGroups).
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setSuperPartition(std::weak_ptr<uml::ActivityPartition>) = 0;

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
			Indicates whether the ActivityPartition groups other ActivityPartitions along a dimension.
			<p>From package UML::Activities.</p>
			*/
			
			bool m_isDimension= false;
			/*!
			Indicates whether the ActivityPartition represents an entity to which the partitioning structure does not apply.
			<p>From package UML::Activities.</p>
			*/
			
			bool m_isExternal= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			ActivityEdges immediately contained in the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge>> m_edge;
			/*!
			ActivityNodes immediately contained in the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> m_node;
			/*!
			An Element represented by the functionality modeled within the ActivityPartition.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::Element> m_represents;
			/*!
			Other ActivityPartitions immediately contained in this ActivityPartition (as its subgroups).
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ActivityPartition, uml::ActivityGroup>> m_subpartition;
			/*!
			Other ActivityPartitions immediately containing this ActivityPartition (as its superGroups).
			<p>From package UML::Activities.</p>
			*/
			
			std::weak_ptr<uml::ActivityPartition> m_superPartition;
	};
}
#endif /* end of include guard: UML_ACTIVITYPARTITION_HPP */
