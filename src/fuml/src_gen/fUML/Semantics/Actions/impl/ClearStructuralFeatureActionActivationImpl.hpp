//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_CLEARSTRUCTURALFEATUREACTIONACTIVATIONCLEARSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_CLEARSTRUCTURALFEATUREACTIONACTIVATIONCLEARSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fuml/fuml.hpp" 

// model includes
#include "../ClearStructuralFeatureActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/StructuralFeatureActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API ClearStructuralFeatureActionActivationImpl : virtual public StructuralFeatureActionActivationImpl, virtual public ClearStructuralFeatureActionActivation 
	{
		public: 
			ClearStructuralFeatureActionActivationImpl(const ClearStructuralFeatureActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ClearStructuralFeatureActionActivationImpl& operator=(ClearStructuralFeatureActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			ClearStructuralFeatureActionActivationImpl();
			virtual std::shared_ptr<ClearStructuralFeatureActionActivation> getThisClearStructuralFeatureActionActivationPtr() const;
			virtual void setThisClearStructuralFeatureActionActivationPtr(std::weak_ptr<ClearStructuralFeatureActionActivation> thisClearStructuralFeatureActionActivationPtr);

			//Additional constructors for the containments back reference
			ClearStructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~ClearStructuralFeatureActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void doAction() ;
			
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
			std::weak_ptr<ClearStructuralFeatureActionActivation> m_thisClearStructuralFeatureActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CLEARSTRUCTURALFEATUREACTIONACTIVATIONCLEARSTRUCTURALFEATUREACTIONACTIVATIONIMPL_HPP */
