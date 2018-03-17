//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INCLUDEINCLUDEIMPL_HPP
#define UML_INCLUDEINCLUDEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Include.hpp"

#include "uml/impl/DirectedRelationshipImpl.hpp"
#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class IncludeImpl :virtual public DirectedRelationshipImpl, virtual public NamedElementImpl, virtual public Include 
	{
		public: 
			IncludeImpl(const IncludeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			IncludeImpl& operator=(IncludeImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			IncludeImpl();
			virtual std::shared_ptr<Include> getThisIncludePtr();
			virtual void setThisIncludePtr(std::weak_ptr<Include> thisIncludePtr);

			//Additional constructors for the containments back reference
			IncludeImpl(std::weak_ptr<uml::UseCase > par_includingCase);


			//Additional constructors for the containments back reference
			IncludeImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			IncludeImpl(std::weak_ptr<uml::Element > par_owner);




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
			virtual std::weak_ptr<uml::UseCase > getIncludingCase() const ;
			
			/*!
			 The UseCase which includes the addition and owns the Include relationship.
			<p>From package UML::UseCases.</p> */
			virtual void setIncludingCase(std::shared_ptr<uml::UseCase> _includingCase_includingCase) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			 Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const ;/*!
			 Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const ;/*!
			 Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p> */
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<Include> m_thisIncludePtr;
	};
}
#endif /* end of include guard: UML_INCLUDEINCLUDEIMPL_HPP */
