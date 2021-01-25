//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OCCURRENCESPECIFICATIONOCCURRENCESPECIFICATIONIMPL_HPP
#define UML_OCCURRENCESPECIFICATIONOCCURRENCESPECIFICATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../OccurrenceSpecification.hpp"

#include "uml/impl/InteractionFragmentImpl.hpp"

//*********************************
namespace uml 
{
	class OccurrenceSpecificationImpl : virtual public InteractionFragmentImpl, virtual public OccurrenceSpecification 
	{
		public: 
			OccurrenceSpecificationImpl(const OccurrenceSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			OccurrenceSpecificationImpl& operator=(OccurrenceSpecificationImpl const&) = delete;

		protected:
			friend class umlFactoryImpl;
			OccurrenceSpecificationImpl();
			virtual std::shared_ptr<OccurrenceSpecification> getThisOccurrenceSpecificationPtr() const;
			virtual void setThisOccurrenceSpecificationPtr(std::weak_ptr<OccurrenceSpecification> thisOccurrenceSpecificationPtr);

			//Additional constructors for the containments back reference
			OccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction);


			//Additional constructors for the containments back reference
			OccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand);


			//Additional constructors for the containments back reference
			OccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			OccurrenceSpecificationImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~OccurrenceSpecificationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			/*!
			Sets the Lifeline on which the OccurrenceSpecification appears.
			*/
			 
			virtual void setCovered(std::shared_ptr<uml::Lifeline> value) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			References the GeneralOrderings that specify EventOcurrences that must occur after this OccurrenceSpecification.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::GeneralOrdering>> getToAfter() const ;
			
			
			/*!
			References the GeneralOrderings that specify EventOcurrences that must occur before this OccurrenceSpecification.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::GeneralOrdering>> getToBefore() const ;
			
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const ; 
			 
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
			std::weak_ptr<OccurrenceSpecification> m_thisOccurrenceSpecificationPtr;
	};
}
#endif /* end of include guard: UML_OCCURRENCESPECIFICATIONOCCURRENCESPECIFICATIONIMPL_HPP */
