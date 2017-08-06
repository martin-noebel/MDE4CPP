//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INCLUDEINCLUDEIMPL_HPP
#define UML_INCLUDEINCLUDEIMPL_HPP

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
#include "../Include.hpp"

#include "impl/DirectedRelationshipImpl.hpp"
#include "impl/NamedElementImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class IncludeImpl :virtual public DirectedRelationshipImpl, virtual public NamedElementImpl, virtual public Include 
	{
		public: 
			IncludeImpl(const IncludeImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			IncludeImpl& operator=(IncludeImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			IncludeImpl();

		public:
			//destructor
			virtual ~IncludeImpl();
			
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
			 The UseCase that is to be included.
			<p>From package UML::UseCases.</p> */
			virtual std::shared_ptr<uml::UseCase > getAddition() const ;
			
			/*!
			 The UseCase that is to be included.
			<p>From package UML::UseCases.</p> */
			virtual void setAddition(std::shared_ptr<uml::UseCase> _addition_addition) ;
			/*!
			 The UseCase which includes the addition and owns the Include relationship.
			<p>From package UML::UseCases.</p> */
			virtual std::shared_ptr<uml::UseCase > getIncludingCase() const ;
			
			/*!
			 The UseCase which includes the addition and owns the Include relationship.
			<p>From package UML::UseCases.</p> */
			virtual void setIncludingCase(std::shared_ptr<uml::UseCase> _includingCase_includingCase) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getRelatedElement() const ;/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Namespace > getNamespace() const ;/*!
			 Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
			 getTarget() const ;/*!
			 Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::Element, uml::Element > >
			 getSource() const ;/*!
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
#endif /* end of include guard: UML_INCLUDEINCLUDEIMPL_HPP */

