//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ELEMENTELEMENTIMPL_HPP
#define UML_ELEMENTELEMENTIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Element.hpp"

#include "uml/impl/ObjectImpl.hpp"

//*********************************
namespace uml 
{
	class ElementImpl : virtual public ObjectImpl, virtual public Element 
	{
		public: 
			ElementImpl(const ElementImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ElementImpl& operator=(ElementImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ElementImpl();
			virtual std::shared_ptr<Element> getThisElementPtr() const;
			virtual void setThisElementPtr(std::weak_ptr<Element> thisElementPtr);

			//Additional constructors for the containments back reference
			ElementImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ElementImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Adds the specified keyword to this element.
			*/
			 
			virtual bool addKeyword(std::string keyword) ;/*!
			The query allOwnedElements() gives all of the direct and indirect ownedElements of an Element.
			result = (ownedElement->union(ownedElement->collect(e | e.allOwnedElements()))->asSet())
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Element> > allOwnedElements() ;/*!
			Applies the specified stereotype to this element.
			*/
			 
			virtual std::shared_ptr<ecore::EObject> applyStereotype(std::shared_ptr<uml::Stereotype> stereotype) ;/*!
			Returns the parent container of this element if any. Return Null if there is no containing element.
			
			<span style="background-color:#FF8000">This Element was merged from mof::Reflection package.</span>
			*/
			 
			virtual std::shared_ptr<uml::Element> container() ;/*!
			Creates an annotation with the specified source and this element as its model element.
			*/
			 
			virtual std::shared_ptr<ecore::EAnnotation> createEAnnotation(std::string source) ;/*!
			Destroys this element by removing all cross references to/from it and removing it from its containing resource or object.
			*/
			 
			virtual void destroy() ;/*!
			Retrieves the stereotype with the specified qualified name that is applicable to this element, or null if no such stereotype is applicable.
			*/
			 
			virtual std::shared_ptr<uml::Stereotype> getApplicableStereotype(std::string qualifiedName) ;/*!
			Retrieves the stereotypes that are applicable to this element, including those that are required and/or may already be applied.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Stereotype> > getApplicableStereotypes() ;/*!
			Retrieves the stereotype with the specified qualified name that is applied to this element, or null if no such stereotype is  applied.
			*/
			 
			virtual std::shared_ptr<uml::Stereotype> getAppliedStereotype(std::string qualifiedName) const ;/*!
			Retrieves the stereotypes that are applied to this element.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Stereotype> > getAppliedStereotypes() const ;/*!
			Retrieves the substereotype of the specified stereotype with the specified qualified name that is applied to this element, or null if no such stereotype is applied.
			*/
			 
			virtual std::shared_ptr<uml::Stereotype> getAppliedSubstereotype(std::shared_ptr<uml::Stereotype> stereotype,std::string qualifiedName) ;/*!
			Retrieves the substereotypes of the specified stereotype that are applied to this element.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Stereotype> > getAppliedSubstereotypes(std::shared_ptr<uml::Stereotype> stereotype) ;/*!
			Retrieves the keywords for this element.
			*/
			 
			virtual std::shared_ptr<Bag<std::string> > getKeywords() ;/*!
			Returns the Class that describes this element.
			
			<span style="background-color:#FF8000">This Element was merged from mof::Reflection package.</span>
			*/
			 
			virtual std::shared_ptr<uml::Class> getMetaClass() ;/*!
			Retrieves the model that owns (either directly or indirectly) this element.
			*/
			 
			virtual std::shared_ptr<uml::Model> getModel() ;/*!
			Retrieves the nearest package that owns (either directly or indirectly) this element, or the element itself (if it is a package).
			*/
			 
			virtual std::shared_ptr<uml::Package> getNearestPackage() ;/*!
			Retrieves the relationships in which this element is involved.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Relationship> > getRelationships() ;/*!
			Retrieves the relationships of the specified type in which this element is involved.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Relationship> > getRelationships(std::shared_ptr<ecore::EClass> eClass) ;/*!
			Retrieves the stereotype with the specified qualified name that is required for this element, or null if no such stereotype is required.
			*/
			 
			virtual std::shared_ptr<uml::Stereotype> getRequiredStereotype(std::string qualifiedName) ;/*!
			Retrieves the stereotypes that are required for this element.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Stereotype> > getRequiredStereotypes() ;/*!
			Retrieves the directed relationships for which this element is a source.
			*/
			 
			virtual std::shared_ptr<Bag<uml::DirectedRelationship> > getSourceDirectedRelationships() ;/*!
			Retrieves the directed relationships of the specified type for which this element is a source.
			*/
			 
			virtual std::shared_ptr<Bag<uml::DirectedRelationship> > getSourceDirectedRelationships(std::shared_ptr<ecore::EClass> eClass) ;/*!
			Retrieves the application of the specified stereotype for this element, or null if no such stereotype application exists.
			*/
			 
			virtual std::shared_ptr<ecore::EObject> getStereotypeApplication(std::shared_ptr<uml::Stereotype> stereotype) ;/*!
			Retrieves the stereotype applications for this element.
			*/
			 
			virtual std::shared_ptr<Bag<ecore::EObject> > getStereotypeApplications() ;/*!
			Retrieves the directed relationships for which this element is a target.
			*/
			 
			virtual std::shared_ptr<Bag<uml::DirectedRelationship> > getTargetDirectedRelationships() ;/*!
			Retrieves the directed relationships of the specified type for which this element is a target.
			*/
			 
			virtual std::shared_ptr<Bag<uml::DirectedRelationship> > getTargetDirectedRelationships(std::shared_ptr<ecore::EClass> eClass) ;/*!
			Retrieves the value of the property with the specified name in the specified stereotype for this element.
			*/
			 
			virtual Any getValue(std::shared_ptr<uml::Stereotype> stereotype,std::string propertyName) ;/*!
			Determines whether this element has the specified keyword.
			*/
			 
			virtual bool hasKeyword(std::string keyword) ;/*!
			Determines whether this element has a (non-default) value for the property with the specified name in the specified stereotype.
			*/
			 
			virtual bool hasValue(std::shared_ptr<uml::Stereotype> stereotype,std::string propertyName) ;/*!
			Elements that must be owned must have an owner.
			mustBeOwned() implies owner->notEmpty()
			*/
			 
			virtual bool has_owner(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			Determines whether the specified stereotype is applicable to this element.
			*/
			 
			virtual bool isStereotypeApplicable(std::shared_ptr<uml::Stereotype> stereotype) ;/*!
			Determines whether the specified stereotype is applied to this element.
			*/
			 
			virtual bool isStereotypeApplied(std::shared_ptr<uml::Stereotype> stereotype) ;/*!
			Determines whether the specified stereotype is required for this element.
			*/
			 
			virtual bool isStereotypeRequired(std::shared_ptr<uml::Stereotype> stereotype) ;/*!
			The query mustBeOwned() indicates whether Elements of this type must have an owner. Subclasses of Element that do not require an owner must override this operation.
			result = (true)
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual bool mustBeOwned() ;/*!
			An element may not directly or indirectly own itself.
			not allOwnedElements()->includes(self)
			*/
			 
			virtual bool not_own_self(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			Removes the specified keyword from this element.
			*/
			 
			virtual bool removeKeyword(std::string keyword) ;/*!
			Sets the value of the property with the specified name in the specified stereotype for this element.
			*/
			 
			virtual void setValue(std::shared_ptr<uml::Stereotype> stereotype,std::string propertyName,Any newValue) ;/*!
			Unapplies the specified stereotype from this element.
			*/
			 
			virtual std::shared_ptr<ecore::EObject> unapplyStereotype(std::shared_ptr<uml::Stereotype> stereotype) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The Comments owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Comment, uml::Element>> getOwnedComment() const ;
			
			
			
			
			
			
			
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
			
			virtual std::weak_ptr<uml::Element> getOwner() const ; 
			 
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

		private:
			std::weak_ptr<Element> m_thisElementPtr;
	};
}
#endif /* end of include guard: UML_ELEMENTELEMENTIMPL_HPP */
