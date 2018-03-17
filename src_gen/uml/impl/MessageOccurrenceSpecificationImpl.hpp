//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_MESSAGEOCCURRENCESPECIFICATIONMESSAGEOCCURRENCESPECIFICATIONIMPL_HPP
#define UML_MESSAGEOCCURRENCESPECIFICATIONMESSAGEOCCURRENCESPECIFICATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../MessageOccurrenceSpecification.hpp"

#include "uml/impl/MessageEndImpl.hpp"
#include "uml/impl/OccurrenceSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class MessageOccurrenceSpecificationImpl :virtual public MessageEndImpl, virtual public OccurrenceSpecificationImpl, virtual public MessageOccurrenceSpecification 
	{
		public: 
			MessageOccurrenceSpecificationImpl(const MessageOccurrenceSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			MessageOccurrenceSpecificationImpl& operator=(MessageOccurrenceSpecificationImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			MessageOccurrenceSpecificationImpl();
			virtual std::shared_ptr<MessageOccurrenceSpecification> getThisMessageOccurrenceSpecificationPtr();
			virtual void setThisMessageOccurrenceSpecificationPtr(std::weak_ptr<MessageOccurrenceSpecification> thisMessageOccurrenceSpecificationPtr);

			//Additional constructors for the containments back reference
			MessageOccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction);


			//Additional constructors for the containments back reference
			MessageOccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand);


			//Additional constructors for the containments back reference
			MessageOccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			MessageOccurrenceSpecificationImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~MessageOccurrenceSpecificationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
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
			std::weak_ptr<MessageOccurrenceSpecification> m_thisMessageOccurrenceSpecificationPtr;
	};
}
#endif /* end of include guard: UML_MESSAGEOCCURRENCESPECIFICATIONMESSAGEOCCURRENCESPECIFICATIONIMPL_HPP */
