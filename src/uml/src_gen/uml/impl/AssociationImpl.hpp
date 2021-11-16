//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ASSOCIATIONASSOCIATIONIMPL_HPP
#define UML_ASSOCIATIONASSOCIATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Association.hpp"

#include "uml/impl/ClassifierImpl.hpp"
#include "uml/impl/RelationshipImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API AssociationImpl : virtual public ClassifierImpl, virtual public RelationshipImpl, virtual public Association 
	{
		public: 
			AssociationImpl(const AssociationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			AssociationImpl& operator=(AssociationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			AssociationImpl();
			virtual std::shared_ptr<uml::Association> getThisAssociationPtr() const;
			virtual void setThisAssociationPtr(std::weak_ptr<uml::Association> thisAssociationPtr);

			//Additional constructors for the containments back reference
			AssociationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			AssociationImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			AssociationImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			AssociationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~AssociationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Ends of Associations with more than two ends must be owned by the Association itself.
			memberEnd->size() > 2 implies ownedEnd->includesAll(memberEnd)
			*/
			 
			virtual bool association_ends(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			Only binary Associations can be aggregations.
			memberEnd->exists(aggregation <> AggregationKind::none) implies (memberEnd->size() = 2 and memberEnd->exists(aggregation = AggregationKind::none))
			*/
			 
			virtual bool binary_associations(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			memberEnd->forAll(type->notEmpty())
			*/
			 
			virtual bool ends_must_be_typed(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			endType is derived from the types of the member ends.
			result = (memberEnd->collect(type)->asSet())
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Type> > getEndTypes() ;
			/*!
			Determines whether this association is a binary association, i.e. whether it has exactly two member ends.
			*/
			 
			virtual bool isBinary() ;
			/*!
			An Association specializing another Association has the same number of ends as the other Association.
			parents()->select(oclIsKindOf(Association)).oclAsType(Association)->forAll(p | p.memberEnd->size() = self.memberEnd->size())
			*/
			 
			virtual bool specialized_end_number(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			When an Association specializes another Association, every end of the specific Association corresponds to an end of the general Association, and the specific end reaches the same type or a subtype of the corresponding general end.
			Sequence{1..memberEnd->size()}->
				forAll(i | general->select(oclIsKindOf(Association)).oclAsType(Association)->
					forAll(ga | self.memberEnd->at(i).type.conformsTo(ga.memberEnd->at(i).type)))
			*/
			 
			virtual bool specialized_end_types(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies whether the Association is derived from other model elements such as other Associations.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual bool getIsDerived() const ;
			/*!
			Specifies whether the Association is derived from other model elements such as other Associations.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			 
			virtual void setIsDerived (bool _isDerived);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Classifiers that are used as types of the ends of the Association.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Type, uml::Element>> getEndType() const ;
			/*!
			Each end represents participation of instances of the Classifier connected to the end in links of the Association.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::NamedElement>> getMemberEnd() const ;
			/*!
			The navigable ends that are owned by the Association itself.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Property, uml::Property /*Subset does not reference a union*/>> getNavigableOwnedEnd() const ;
			/*!
			The ends that are owned by the Association itself.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::Feature, uml::NamedElement, uml::Property /*Subset does not reference a union*/>> getOwnedEnd() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const ;
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;
			
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;
			/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const ;
			
			
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
			std::weak_ptr<uml::Association> m_thisAssociationPtr;
	};
}
#endif /* end of include guard: UML_ASSOCIATIONASSOCIATIONIMPL_HPP */
