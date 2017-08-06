//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LITERALREALLITERALREALIMPL_HPP
#define UML_LITERALREALLITERALREALIMPL_HPP

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
#include "../LiteralReal.hpp"

#include "impl/LiteralSpecificationImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class LiteralRealImpl :virtual public LiteralSpecificationImpl, virtual public LiteralReal 
	{
		public: 
			LiteralRealImpl(const LiteralRealImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			LiteralRealImpl& operator=(LiteralRealImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			LiteralRealImpl();

		public:
			//destructor
			virtual ~LiteralRealImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 The specified Real value.
			<p>From package UML::Values.</p> */ 
			virtual double getValue() const ;
			
			/*!
			 The specified Real value.
			<p>From package UML::Values.</p> */ 
			virtual void setValue (double _value); 
			
			
			
			//*********************************
			// Reference
			//*********************************
							
			
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
#endif /* end of include guard: UML_LITERALREALLITERALREALIMPL_HPP */

