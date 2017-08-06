//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OPERATIONTEMPLATEPARAMETEROPERATIONTEMPLATEPARAMETERIMPL_HPP
#define UML_OPERATIONTEMPLATEPARAMETEROPERATIONTEMPLATEPARAMETERIMPL_HPP

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
#include "../OperationTemplateParameter.hpp"

#include "impl/TemplateParameterImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class OperationTemplateParameterImpl :virtual public TemplateParameterImpl, virtual public OperationTemplateParameter 
	{
		public: 
			OperationTemplateParameterImpl(const OperationTemplateParameterImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			OperationTemplateParameterImpl& operator=(OperationTemplateParameterImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			OperationTemplateParameterImpl();

		public:
			//destructor
			virtual ~OperationTemplateParameterImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 default->notEmpty() implies (default.oclIsKindOf(Operation) and (let defaultOp : Operation = default.oclAsType(Operation) in 
			    defaultOp.ownedParameter->size() = parameteredElement.ownedParameter->size() and
			    Sequence{1.. defaultOp.ownedParameter->size()}->forAll( ix | 
			        let p1: Parameter = defaultOp.ownedParameter->at(ix), p2 : Parameter = parameteredElement.ownedParameter->at(ix) in
			          p1.type = p2.type and p1.upper = p2.upper and p1.lower = p2.lower and p1.direction = p2.direction and p1.isOrdered = p2.isOrdered and p1.isUnique = p2.isUnique))) */ 
			virtual bool
			 match_default_signature(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
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
#endif /* end of include guard: UML_OPERATIONTEMPLATEPARAMETEROPERATIONTEMPLATEPARAMETERIMPL_HPP */

