//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_LINKLINKIMPL_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_LINKLINKIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Link.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ExtensionalValueImpl.hpp"

//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	class LinkImpl : virtual public ExtensionalValueImpl, virtual public Link 
	{
		public: 
			LinkImpl(const LinkImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LinkImpl& operator=(LinkImpl const&); 

		protected:
			friend class fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			LinkImpl();
			virtual std::shared_ptr<Link> getThisLinkPtr() const;
			virtual void setThisLinkPtr(std::weak_ptr<Link> thisLinkPtr);


		public:
			//destructor
			virtual ~LinkImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() ; 
			virtual void addTo(std::shared_ptr<fUML::Semantics::Loci::Locus> locus) ; 
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> > getOtherFeatureValues(std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extent,std::shared_ptr<uml::Property> end) ; 
			virtual std::shared_ptr<Bag<uml::Classifier> > getTypes() const ; 
			virtual bool isMatchingLink(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> link,std::shared_ptr<uml::Property> end) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<uml::Association> getType() const ;
			
			virtual void setType(std::shared_ptr<uml::Association>) ;
			
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
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
			std::weak_ptr<Link> m_thisLinkPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_LINKLINKIMPL_HPP */
