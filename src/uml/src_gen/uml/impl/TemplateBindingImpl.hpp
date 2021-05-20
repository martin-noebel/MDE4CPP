//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATEBINDINGTEMPLATEBINDINGIMPL_HPP
#define UML_TEMPLATEBINDINGTEMPLATEBINDINGIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../TemplateBinding.hpp"

#include "uml/impl/DirectedRelationshipImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API TemplateBindingImpl : virtual public DirectedRelationshipImpl, virtual public TemplateBinding 
	{
		public: 
			TemplateBindingImpl(const TemplateBindingImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TemplateBindingImpl& operator=(TemplateBindingImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TemplateBindingImpl();
			virtual std::shared_ptr<TemplateBinding> getThisTemplateBindingPtr() const;
			virtual void setThisTemplateBindingPtr(std::weak_ptr<TemplateBinding> thisTemplateBindingPtr);

			//Additional constructors for the containments back reference
			TemplateBindingImpl(std::weak_ptr<uml::TemplateableElement> par_boundElement);
			//Additional constructors for the containments back reference
			TemplateBindingImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~TemplateBindingImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			A TemplateBiinding contains at most one TemplateParameterSubstitution for each formal TemplateParameter of the target TemplateSignature.
			signature.parameter->forAll(p | parameterSubstitution->select(b | b.formal = p)->size() <= 1)
			*/
			 
			virtual bool one_parameter_substitution(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			Each parameterSubstitution must refer to a formal TemplateParameter of the target TemplateSignature.
			parameterSubstitution->forAll(b | signature.parameter->includes(b.formal))
			*/
			 
			virtual bool parameter_substitution_formal(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The TemplateableElement that is bound by this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::TemplateableElement> getBoundElement() const ;
			/*!
			The TemplateableElement that is bound by this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setBoundElement(std::weak_ptr<uml::TemplateableElement>) ;
			/*!
			The TemplateParameterSubstitutions owned by this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::TemplateParameterSubstitution, uml::Element>> getParameterSubstitution() const ;
			
			/*!
			The TemplateSignature for the template that is the target of this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::TemplateSignature> getSignature() const ;
			/*!
			The TemplateSignature for the template that is the target of this TemplateBinding.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setSignature(std::shared_ptr<uml::TemplateSignature>) ;
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const ;/*!
			Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const ;/*!
			Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const ; 
			 
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
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<TemplateBinding> m_thisTemplateBindingPtr;
	};
}
#endif /* end of include guard: UML_TEMPLATEBINDINGTEMPLATEBINDINGIMPL_HPP */
