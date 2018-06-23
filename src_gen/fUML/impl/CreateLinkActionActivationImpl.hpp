//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_CREATELINKACTIONACTIVATIONCREATELINKACTIONACTIVATIONIMPL_HPP
#define FUML_CREATELINKACTIONACTIVATIONCREATELINKACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CreateLinkActionActivation.hpp"

#include "fUML/impl/WriteLinkActionActivationImpl.hpp"

//*********************************
namespace fUML 
{
	class CreateLinkActionActivationImpl :virtual public WriteLinkActionActivationImpl, virtual public CreateLinkActionActivation 
	{
		public: 
			CreateLinkActionActivationImpl(const CreateLinkActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CreateLinkActionActivationImpl& operator=(CreateLinkActionActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			CreateLinkActionActivationImpl();
			virtual std::shared_ptr<CreateLinkActionActivation> getThisCreateLinkActionActivationPtr();
			virtual void setThisCreateLinkActionActivationPtr(std::weak_ptr<CreateLinkActionActivation> thisCreateLinkActionActivationPtr);

			//Additional constructors for the containments back reference
			CreateLinkActionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~CreateLinkActionActivationImpl();
			
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
			std::weak_ptr<CreateLinkActionActivation> m_thisCreateLinkActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_CREATELINKACTIONACTIVATIONCREATELINKACTIONACTIVATIONIMPL_HPP */
