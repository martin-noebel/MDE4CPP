//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_RECLASSIFYOBJECTACTION_HPP
#define UML_RECLASSIFYOBJECTACTION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
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
	A ReclassifyObjectAction is an Action that changes the Classifiers that classify an object.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API ReclassifyObjectAction : virtual public Action
	{
		public:
 			ReclassifyObjectAction(const ReclassifyObjectAction &) {}

		protected:
			ReclassifyObjectAction(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ReclassifyObjectAction() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether existing Classifiers should be removed before adding the new Classifiers.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getIsReplaceAll() const = 0;
			/*!
			Specifies whether existing Classifiers should be removed before adding the new Classifiers.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setIsReplaceAll (bool _isReplaceAll)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A set of Classifiers to be added to the Classifiers of the given object.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getNewClassifier() const = 0;
			/*!
			The InputPin that holds the object to be reclassified.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getObject() const = 0;
			/*!
			The InputPin that holds the object to be reclassified.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setObject(std::shared_ptr<uml::InputPin>) = 0;
			/*!
			A set of Classifiers to be removed from the Classifiers of the given object.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getOldClassifier() const = 0;

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
			Specifies whether existing Classifiers should be removed before adding the new Classifiers.
			<p>From package UML::Actions.</p>
			*/
			
			bool m_isReplaceAll= false;
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			A set of Classifiers to be added to the Classifiers of the given object.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Classifier>> m_newClassifier;
			/*!
			The InputPin that holds the object to be reclassified.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_object;
			/*!
			A set of Classifiers to be removed from the Classifiers of the given object.
			<p>From package UML::Actions.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Classifier>> m_oldClassifier;
	};
}
#endif /* end of include guard: UML_RECLASSIFYOBJECTACTION_HPP */
