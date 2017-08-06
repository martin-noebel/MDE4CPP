//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATEPARAMETERTEMPLATEPARAMETERIMPL_HPP
#define UML_TEMPLATEPARAMETERTEMPLATEPARAMETERIMPL_HPP

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
#include "../TemplateParameter.hpp"

#include "impl/ElementImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class TemplateParameterImpl :virtual public ElementImpl, virtual public TemplateParameter 
	{
		public: 
			TemplateParameterImpl(const TemplateParameterImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			TemplateParameterImpl& operator=(TemplateParameterImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			TemplateParameterImpl();

		public:
			//destructor
			virtual ~TemplateParameterImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The default must be compatible with the formal TemplateParameter.
			default <> null implies default.isCompatibleWith(parameteredElement) */ 
			virtual bool
			 must_be_compatible(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The ParameterableElement that is the default for this formal TemplateParameter.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::ParameterableElement > getDefault() const ;
			
			/*!
			 The ParameterableElement that is the default for this formal TemplateParameter.
			<p>From package UML::CommonStructure.</p> */
			virtual void setDefault(std::shared_ptr<uml::ParameterableElement> _default_default) ;
			/*!
			 The ParameterableElement that is owned by this TemplateParameter for the purpose of providing a default.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::ParameterableElement > getOwnedDefault() const ;
			
			/*!
			 The ParameterableElement that is owned by this TemplateParameter for the purpose of providing a default.
			<p>From package UML::CommonStructure.</p> */
			virtual void setOwnedDefault(std::shared_ptr<uml::ParameterableElement> _ownedDefault_ownedDefault) ;
			/*!
			 The ParameterableElement exposed by this TemplateParameter.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::ParameterableElement > getParameteredElement() const ;
			
			/*!
			 The ParameterableElement exposed by this TemplateParameter.
			<p>From package UML::CommonStructure.</p> */
			virtual void setParameteredElement(std::shared_ptr<uml::ParameterableElement> _parameteredElement_parameteredElement) ;
			/*!
			 The TemplateSignature that owns this TemplateParameter.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::TemplateSignature > getSignature() const ;
			
			/*!
			 The TemplateSignature that owns this TemplateParameter.
			<p>From package UML::CommonStructure.</p> */
			virtual void setSignature(std::shared_ptr<uml::TemplateSignature> _signature_signature) ;
			/*!
			 The ParameterableElement that is owned by this TemplateParameter for the purpose of exposing it as the parameteredElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::ParameterableElement > getOwnedParameteredElement() const ;
			
			/*!
			 The ParameterableElement that is owned by this TemplateParameter for the purpose of exposing it as the parameteredElement.
			<p>From package UML::CommonStructure.</p> */
			virtual void setOwnedParameteredElement(std::shared_ptr<uml::ParameterableElement> _ownedParameteredElement_ownedParameteredElement) ;
							
			
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
#endif /* end of include guard: UML_TEMPLATEPARAMETERTEMPLATEPARAMETERIMPL_HPP */

