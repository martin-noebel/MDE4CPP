//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_GENERALIZATIONGENERALIZATIONIMPL_HPP
#define UML_GENERALIZATIONGENERALIZATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Generalization.hpp"

#include "uml/impl/DirectedRelationshipImpl.hpp"

//*********************************
namespace uml 
{
	class GeneralizationImpl : virtual public DirectedRelationshipImpl, virtual public Generalization 
	{
		public: 
			GeneralizationImpl(const GeneralizationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			GeneralizationImpl& operator=(GeneralizationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			GeneralizationImpl();
			virtual std::shared_ptr<Generalization> getThisGeneralizationPtr() const;
			virtual void setThisGeneralizationPtr(std::weak_ptr<Generalization> thisGeneralizationPtr);

			//Additional constructors for the containments back reference
			GeneralizationImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			GeneralizationImpl(std::weak_ptr<uml::Classifier> par_specific);

		public:
			//destructor
			virtual ~GeneralizationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			Indicates whether the specific Classifier can be used wherever the general Classifier can be used. If true, the execution traces of the specific Classifier shall be a superset of the execution traces of the general Classifier. If false, there is no such constraint on execution traces. If unset, the modeler has not stated whether there is such a constraint or not.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsSubstitutable() const ;
			/*!
			Indicates whether the specific Classifier can be used wherever the general Classifier can be used. If true, the execution traces of the specific Classifier shall be a superset of the execution traces of the general Classifier. If false, there is no such constraint on execution traces. If unset, the modeler has not stated whether there is such a constraint or not.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsSubstitutable (bool _isSubstitutable);
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The general classifier in the Generalization relationship.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<uml::Classifier> getGeneral() const ;
			/*!
			The general classifier in the Generalization relationship.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setGeneral(std::shared_ptr<uml::Classifier>) ;
			/*!
			Represents a set of instances of Generalization.  A Generalization may appear in many GeneralizationSets.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::GeneralizationSet>> getGeneralizationSet() const ;
			
			/*!
			The specializing Classifier in the Generalization relationship.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Classifier> getSpecific() const ;
			/*!
			The specializing Classifier in the Generalization relationship.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setSpecific(std::weak_ptr<uml::Classifier>) ;
			
			
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

		private:
			std::weak_ptr<Generalization> m_thisGeneralizationPtr;
	};
}
#endif /* end of include guard: UML_GENERALIZATIONGENERALIZATIONIMPL_HPP */
