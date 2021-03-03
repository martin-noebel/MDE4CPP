//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SLOT_HPP
#define UML_SLOT_HPP


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
	class Comment;
	class InstanceSpecification;
	class StructuralFeature;
	class ValueSpecification;
}

// base class includes
#include "uml/Element.hpp"

// enum includes



//*********************************
namespace uml 
{
	/*!
	A Slot designates that an entity modeled by an InstanceSpecification has a value or values for a specific StructuralFeature.
	<p>From package UML::Classification.</p>
	*/
	
	class Slot: virtual public Element
	{
		public:
 			Slot(const Slot &) {}

		protected:
			Slot(){}
			//Additional constructors for the containments back reference
			Slot(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			Slot(std::weak_ptr<uml::InstanceSpecification> par_owningInstance);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Slot() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The StructuralFeature that specifies the values that may be held by the Slot.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<uml::StructuralFeature> getDefiningFeature() const = 0;
			/*!
			The StructuralFeature that specifies the values that may be held by the Slot.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setDefiningFeature(std::shared_ptr<uml::StructuralFeature>) = 0;
			/*!
			The InstanceSpecification that owns this Slot.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::InstanceSpecification> getOwningInstance() const = 0;
			/*!
			The InstanceSpecification that owns this Slot.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setOwningInstance(std::weak_ptr<uml::InstanceSpecification>) = 0;
			/*!
			The value or values held by the Slot.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> getValue() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The StructuralFeature that specifies the values that may be held by the Slot.
			<p>From package UML::Classification.</p>
			*/
			
			std::shared_ptr<uml::StructuralFeature> m_definingFeature;/*!
			The InstanceSpecification that owns this Slot.
			<p>From package UML::Classification.</p>
			*/
			
			std::weak_ptr<uml::InstanceSpecification> m_owningInstance;/*!
			The value or values held by the Slot.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ValueSpecification, uml::Element>> m_value;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
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
#endif /* end of include guard: UML_SLOT_HPP */
