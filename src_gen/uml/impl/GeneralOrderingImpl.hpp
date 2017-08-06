//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_GENERALORDERINGGENERALORDERINGIMPL_HPP
#define UML_GENERALORDERINGGENERALORDERINGIMPL_HPP

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
#include "../GeneralOrdering.hpp"

#include "impl/NamedElementImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class GeneralOrderingImpl :virtual public NamedElementImpl, virtual public GeneralOrdering 
	{
		public: 
			GeneralOrderingImpl(const GeneralOrderingImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			GeneralOrderingImpl& operator=(GeneralOrderingImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			GeneralOrderingImpl();

		public:
			//destructor
			virtual ~GeneralOrderingImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 An occurrence specification must not be ordered relative to itself through a series of general orderings. (In other words, the transitive closure of the general orderings is irreflexive.)
			after->closure(toAfter.after)->excludes(before) */ 
			virtual bool
			 irreflexive_transitive_closure(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The OccurrenceSpecification referenced comes after the OccurrenceSpecification referenced by before.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<uml::OccurrenceSpecification > getAfter() const ;
			
			/*!
			 The OccurrenceSpecification referenced comes after the OccurrenceSpecification referenced by before.
			<p>From package UML::Interactions.</p> */
			virtual void setAfter(std::shared_ptr<uml::OccurrenceSpecification> _after_after) ;
			/*!
			 The OccurrenceSpecification referenced comes before the OccurrenceSpecification referenced by after.
			<p>From package UML::Interactions.</p> */
			virtual std::shared_ptr<uml::OccurrenceSpecification > getBefore() const ;
			
			/*!
			 The OccurrenceSpecification referenced comes before the OccurrenceSpecification referenced by after.
			<p>From package UML::Interactions.</p> */
			virtual void setBefore(std::shared_ptr<uml::OccurrenceSpecification> _before_before) ;
							
			
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
#endif /* end of include guard: UML_GENERALORDERINGGENERALORDERINGIMPL_HPP */

