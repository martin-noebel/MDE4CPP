//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_VALUEPINVALUEPINIMPL_HPP
#define UML_VALUEPINVALUEPINIMPL_HPP

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
#include "../ValuePin.hpp"

#include "impl/InputPinImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class ValuePinImpl :virtual public InputPinImpl, virtual public ValuePin 
	{
		public: 
			ValuePinImpl(const ValuePinImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ValuePinImpl& operator=(ValuePinImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ValuePinImpl();

		public:
			//destructor
			virtual ~ValuePinImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 A ValuePin may have no incoming ActivityEdges.
			incoming->isEmpty() */ 
			virtual bool
			 no_incoming_edges(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The type of the value ValueSpecification must conform to the type of the ValuePin.
			value.type.conformsTo(type) */ 
			virtual bool
			 compatible_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The ValueSpecification that is evaluated to obtain the value that the ValuePin will provide.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::ValueSpecification > getValue() const ;
			
			/*!
			 The ValueSpecification that is evaluated to obtain the value that the ValuePin will provide.
			<p>From package UML::Actions.</p> */
			virtual void setValue(std::shared_ptr<uml::ValueSpecification> _value_value) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Union<uml::RedefinableElement> > getRedefinedElement() const ;/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Union<uml::ActivityGroup> > getInGroup() const ;/*!
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
#endif /* end of include guard: UML_VALUEPINVALUEPINIMPL_HPP */

