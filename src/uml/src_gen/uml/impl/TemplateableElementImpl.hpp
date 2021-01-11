//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATEABLEELEMENTTEMPLATEABLEELEMENTIMPL_HPP
#define UML_TEMPLATEABLEELEMENTTEMPLATEABLEELEMENTIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../TemplateableElement.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class TemplateableElementImpl : virtual public ElementImpl, virtual public TemplateableElement 
	{
		public: 
			TemplateableElementImpl(const TemplateableElementImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			TemplateableElementImpl& operator=(TemplateableElementImpl const&) = delete;

		protected:
			friend class umlFactoryImpl;
			TemplateableElementImpl();
			virtual std::shared_ptr<TemplateableElement> getThisTemplateableElementPtr() const;
			virtual void setThisTemplateableElementPtr(std::weak_ptr<TemplateableElement> thisTemplateableElementPtr);

			//Additional constructors for the containments back reference
			TemplateableElementImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~TemplateableElementImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The query isTemplate() returns whether this TemplateableElement is actually a template.
			result = (ownedTemplateSignature <> null)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool isTemplate() ;
			
			/*!
			The query parameterableElements() returns the set of ParameterableElements that may be used as the parameteredElements for a TemplateParameter of this TemplateableElement. By default, this set includes all the ownedElements. Subclasses may override this operation if they choose to restrict the set of ParameterableElements.
			result = (self.allOwnedElements()->select(oclIsKindOf(ParameterableElement)).oclAsType(ParameterableElement)->asSet())
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::ParameterableElement> > parameterableElements() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The optional TemplateSignature specifying the formal TemplateParameters for this TemplateableElement. If a TemplateableElement has a TemplateSignature, then it is a template.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::TemplateSignature > getOwnedTemplateSignature() const ;
			
			/*!
			The optional TemplateSignature specifying the formal TemplateParameters for this TemplateableElement. If a TemplateableElement has a TemplateSignature, then it is a template.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setOwnedTemplateSignature(std::shared_ptr<uml::TemplateSignature> _ownedTemplateSignature) ;
			
			/*!
			The optional TemplateBindings from this TemplateableElement to one or more templates.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::TemplateBinding, uml::Element>> getTemplateBinding() const ;
			
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<TemplateableElement> m_thisTemplateableElementPtr;
	};
}
#endif /* end of include guard: UML_TEMPLATEABLEELEMENTTEMPLATEABLEELEMENTIMPL_HPP */
