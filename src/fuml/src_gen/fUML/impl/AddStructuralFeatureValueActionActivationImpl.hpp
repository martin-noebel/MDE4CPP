//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATIONADDSTRUCTURALFEATUREVALUEACTIONACTIVATIONIMPL_HPP
#define FUML_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATIONADDSTRUCTURALFEATUREVALUEACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../AddStructuralFeatureValueActionActivation.hpp"

#include "fUML/impl/WriteStructuralFeatureActionActivationImpl.hpp"

//*********************************
namespace fUML 
{
	class AddStructuralFeatureValueActionActivationImpl :virtual public WriteStructuralFeatureActionActivationImpl, virtual public AddStructuralFeatureValueActionActivation 
	{
		public: 
			AddStructuralFeatureValueActionActivationImpl(const AddStructuralFeatureValueActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			AddStructuralFeatureValueActionActivationImpl& operator=(AddStructuralFeatureValueActionActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			AddStructuralFeatureValueActionActivationImpl();
			virtual std::shared_ptr<AddStructuralFeatureValueActionActivation> getThisAddStructuralFeatureValueActionActivationPtr() const;
			virtual void setThisAddStructuralFeatureValueActionActivationPtr(std::weak_ptr<AddStructuralFeatureValueActionActivation> thisAddStructuralFeatureValueActionActivationPtr);

			//Additional constructors for the containments back reference
			AddStructuralFeatureValueActionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~AddStructuralFeatureValueActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
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
			/*!
			 */
			virtual std::shared_ptr<Union<fUML::PinActivation>> getPinActivation() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<AddStructuralFeatureValueActionActivation> m_thisAddStructuralFeatureValueActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATIONADDSTRUCTURALFEATUREVALUEACTIONACTIVATIONIMPL_HPP */
