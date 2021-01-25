//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_STRUCTURALFEATUREACTIONACTIVATIONSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_STRUCTURALFEATUREACTIONACTIVATIONSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../StructuralFeatureActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class StructuralFeatureActionActivationImpl : virtual public ActionActivationImpl, virtual public StructuralFeatureActionActivation 
	{
		public: 
			StructuralFeatureActionActivationImpl(const StructuralFeatureActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			StructuralFeatureActionActivationImpl& operator=(StructuralFeatureActionActivationImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			StructuralFeatureActionActivationImpl();
			virtual std::shared_ptr<StructuralFeatureActionActivation> getThisStructuralFeatureActionActivationPtr() const;
			virtual void setThisStructuralFeatureActionActivationPtr(std::weak_ptr<StructuralFeatureActionActivation> thisStructuralFeatureActionActivationPtr);

			//Additional constructors for the containments back reference
			StructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~StructuralFeatureActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<org.eclipse.uml2.uml.Association> getAssociation(std::shared_ptr<org.eclipse.uml2.uml.StructuralFeature> feature) ;
			
			 
			virtual std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link> > getMatchingLinks(std::shared_ptr<org.eclipse.uml2.uml.Association> association,std::shared_ptr<org.eclipse.uml2.uml.StructuralFeature> end,std::shared_ptr<fUML::Semantics::Values::Value> oppositeValue) ;
			
			 
			virtual std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link> > getMatchingLinksForEndValue(std::shared_ptr<org.eclipse.uml2.uml.Association> association,std::shared_ptr<org.eclipse.uml2.uml.StructuralFeature> end,std::shared_ptr<fUML::Semantics::Values::Value> oppositeValue,std::shared_ptr<fUML::Semantics::Values::Value> endValue) ;
			
			 
			virtual std::shared_ptr<org.eclipse.uml2.uml.Property> getOppositeEnd(std::shared_ptr<org.eclipse.uml2.uml.Association> association,std::shared_ptr<org.eclipse.uml2.uml.StructuralFeature> end) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ; 
			 
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
			std::weak_ptr<StructuralFeatureActionActivation> m_thisStructuralFeatureActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_STRUCTURALFEATUREACTIONACTIVATIONSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP */
