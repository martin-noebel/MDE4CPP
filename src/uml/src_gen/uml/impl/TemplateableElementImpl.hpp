//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATEABLEELEMENTTEMPLATEABLEELEMENTIMPL_HPP
#define UML_TEMPLATEABLEELEMENTTEMPLATEABLEELEMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../TemplateableElement.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API TemplateableElementImpl : virtual public ElementImpl, virtual public TemplateableElement 
	{
		public: 
			TemplateableElementImpl(const TemplateableElementImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			TemplateableElementImpl& operator=(TemplateableElementImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TemplateableElementImpl();
			virtual std::shared_ptr<uml::TemplateableElement> getThisTemplateableElementPtr() const;
			virtual void setThisTemplateableElementPtr(std::weak_ptr<uml::TemplateableElement> thisTemplateableElementPtr);

			//Additional constructors for the containments back reference
			TemplateableElementImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~TemplateableElementImpl() = 0;
			
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
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The optional TemplateSignature specifying the formal TemplateParameters for this TemplateableElement. If a TemplateableElement has a TemplateSignature, then it is a template.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::TemplateSignature> getOwnedTemplateSignature() const ;
			/*!
			The optional TemplateSignature specifying the formal TemplateParameters for this TemplateableElement. If a TemplateableElement has a TemplateSignature, then it is a template.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setOwnedTemplateSignature(std::shared_ptr<uml::TemplateSignature>) ;
			/*!
			The optional TemplateBindings from this TemplateableElement to one or more templates.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::TemplateBinding, uml::Element>> getTemplateBinding() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			
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
			std::weak_ptr<uml::TemplateableElement> m_thisTemplateableElementPtr;
	};
}
#endif /* end of include guard: UML_TEMPLATEABLEELEMENTTEMPLATEABLEELEMENTIMPL_HPP */
