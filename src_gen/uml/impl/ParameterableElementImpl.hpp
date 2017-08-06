//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PARAMETERABLEELEMENTPARAMETERABLEELEMENTIMPL_HPP
#define UML_PARAMETERABLEELEMENTPARAMETERABLEELEMENTIMPL_HPP

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
#include "../ParameterableElement.hpp"

#include "impl/ElementImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class ParameterableElementImpl :virtual public ElementImpl, virtual public ParameterableElement 
	{
		public: 
			ParameterableElementImpl(const ParameterableElementImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ParameterableElementImpl& operator=(ParameterableElementImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ParameterableElementImpl();

		public:
			//destructor
			virtual ~ParameterableElementImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The query isCompatibleWith() determines if this ParameterableElement is compatible with the specified ParameterableElement. By default, this ParameterableElement is compatible with another ParameterableElement p if the kind of this ParameterableElement is the same as or a subtype of the kind of p. Subclasses of ParameterableElement should override this operation to specify different compatibility constraints.
			result = (self.oclIsKindOf(p.oclType()))
			<p>From package UML::CommonStructure.</p> */ 
			virtual bool
			 isCompatibleWith(std::shared_ptr<uml::ParameterableElement>  p)  ;
			
			/*!
			 The query isTemplateParameter() determines if this ParameterableElement is exposed as a formal TemplateParameter.
			result = (templateParameter->notEmpty())
			<p>From package UML::CommonStructure.</p> */ 
			virtual bool
			 isTemplateParameter()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The formal TemplateParameter that owns this ParameterableElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::TemplateParameter > getOwningTemplateParameter() const ;
			
			/*!
			 The formal TemplateParameter that owns this ParameterableElement.
			<p>From package UML::CommonStructure.</p> */
			virtual void setOwningTemplateParameter(std::shared_ptr<uml::TemplateParameter> _owningTemplateParameter_owningTemplateParameter) ;
			/*!
			 The TemplateParameter that exposes this ParameterableElement as a formal parameter.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::TemplateParameter > getTemplateParameter() const ;
			
			/*!
			 The TemplateParameter that exposes this ParameterableElement as a formal parameter.
			<p>From package UML::CommonStructure.</p> */
			virtual void setTemplateParameter(std::shared_ptr<uml::TemplateParameter> _templateParameter_templateParameter) ;
							
			
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
#endif /* end of include guard: UML_PARAMETERABLEELEMENTPARAMETERABLEELEMENTIMPL_HPP */

