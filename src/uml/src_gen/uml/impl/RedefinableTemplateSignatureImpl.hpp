//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REDEFINABLETEMPLATESIGNATUREREDEFINABLETEMPLATESIGNATUREIMPL_HPP
#define UML_REDEFINABLETEMPLATESIGNATUREREDEFINABLETEMPLATESIGNATUREIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../RedefinableTemplateSignature.hpp"

#include "uml/impl/RedefinableElementImpl.hpp"
#include "uml/impl/TemplateSignatureImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API RedefinableTemplateSignatureImpl : virtual public RedefinableElementImpl, virtual public TemplateSignatureImpl, virtual public RedefinableTemplateSignature 
	{
		public: 
			RedefinableTemplateSignatureImpl(const RedefinableTemplateSignatureImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			RedefinableTemplateSignatureImpl& operator=(RedefinableTemplateSignatureImpl const&); 

		protected:
			friend class umlFactoryImpl;
			RedefinableTemplateSignatureImpl();
			virtual std::shared_ptr<uml::RedefinableTemplateSignature> getThisRedefinableTemplateSignaturePtr() const;
			virtual void setThisRedefinableTemplateSignaturePtr(std::weak_ptr<uml::RedefinableTemplateSignature> thisRedefinableTemplateSignaturePtr);

			//Additional constructors for the containments back reference
			RedefinableTemplateSignatureImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			RedefinableTemplateSignatureImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			RedefinableTemplateSignatureImpl(std::weak_ptr<uml::TemplateableElement> par_template);

		public:
			//destructor
			virtual ~RedefinableTemplateSignatureImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Derivation for RedefinableTemplateSignature::/inheritedParameter
			result = (if extendedSignature->isEmpty() then Set{} else extendedSignature.parameter->asSet() endif)
			<p>From package UML::Classification.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::TemplateParameter> > getInheritedParameters() ;
			/*!
			If any of the parent Classifiers are a template, then the extendedSignature must include the signature of that Classifier.
			classifier.allParents()->forAll(c | c.ownedTemplateSignature->notEmpty() implies self->closure(extendedSignature)->includes(c.ownedTemplateSignature))
			*/
			 
			virtual bool redefines_parents(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Classifier that owns this RedefinableTemplateSignature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Classifier> getClassifier() const ;
			/*!
			The Classifier that owns this RedefinableTemplateSignature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setClassifier(std::weak_ptr<uml::Classifier>) ;
			/*Additional Setter for 'TemplateSignature::template' redefined by reference 'classifier'*/
			/*!
			The TemplateableElement that owns this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setTemplate(std::weak_ptr<uml::TemplateableElement>) ;
			/*!
			The signatures extended by this RedefinableTemplateSignature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::RedefinableTemplateSignature, uml::RedefinableElement>> getExtendedSignature() const ;
			/*!
			The formal template parameters of the extended signatures.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::TemplateParameter, uml::TemplateParameter>> getInheritedParameter() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			/*!
			The ordered set of all formal TemplateParameters for this TemplateSignature.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::TemplateParameter>> getParameter() const ;
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;
			/*!
			The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getRedefinitionContext() const ;
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<uml::RedefinableTemplateSignature> m_thisRedefinableTemplateSignaturePtr;
	};
}
#endif /* end of include guard: UML_REDEFINABLETEMPLATESIGNATUREREDEFINABLETEMPLATESIGNATUREIMPL_HPP */
