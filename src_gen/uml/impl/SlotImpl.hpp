//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SLOTSLOTIMPL_HPP
#define UML_SLOTSLOTIMPL_HPP

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

//*********************************
// generated Includes

//Model includes
#include "../Slot.hpp"

#include "impl/ElementImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class SlotImpl :virtual public ElementImpl, virtual public Slot 
	{
		public: 
			SlotImpl(const SlotImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			SlotImpl& operator=(SlotImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			SlotImpl();

		public:
			//destructor
			virtual ~SlotImpl();
			
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
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<uml::StructuralFeature > getDefiningFeature() const ;
			
			/*!
			 The StructuralFeature that specifies the values that may be held by the Slot.
			<p>From package UML::Classification.</p> */
			virtual void setDefiningFeature(std::shared_ptr<uml::StructuralFeature> _definingFeature_definingFeature) ;
			/*!
			 The value or values held by the Slot.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Subset<uml::ValueSpecification, uml::Element > >
			 getValue() const ;
			
			/*!
			 The InstanceSpecification that owns this Slot.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<uml::InstanceSpecification > getOwningInstance() const ;
			
			/*!
			 The InstanceSpecification that owns this Slot.
			<p>From package UML::Classification.</p> */
			virtual void setOwningInstance(std::shared_ptr<uml::InstanceSpecification> _owningInstance_owningInstance) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Element > getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: UML_SLOTSLOTIMPL_HPP */

