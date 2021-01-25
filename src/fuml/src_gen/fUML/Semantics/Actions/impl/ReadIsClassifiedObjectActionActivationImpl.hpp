//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_READISCLASSIFIEDOBJECTACTIONACTIVATIONREADISCLASSIFIEDOBJECTACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_READISCLASSIFIEDOBJECTACTIONACTIVATIONREADISCLASSIFIEDOBJECTACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ReadIsClassifiedObjectActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class ReadIsClassifiedObjectActionActivationImpl : virtual public ActionActivationImpl, virtual public ReadIsClassifiedObjectActionActivation 
	{
		public: 
			ReadIsClassifiedObjectActionActivationImpl(const ReadIsClassifiedObjectActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ReadIsClassifiedObjectActionActivationImpl& operator=(ReadIsClassifiedObjectActionActivationImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			ReadIsClassifiedObjectActionActivationImpl();
			virtual std::shared_ptr<ReadIsClassifiedObjectActionActivation> getThisReadIsClassifiedObjectActionActivationPtr() const;
			virtual void setThisReadIsClassifiedObjectActionActivationPtr(std::weak_ptr<ReadIsClassifiedObjectActionActivation> thisReadIsClassifiedObjectActionActivationPtr);

			//Additional constructors for the containments back reference
			ReadIsClassifiedObjectActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~ReadIsClassifiedObjectActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual bool checkAllParents(std::shared_ptr<org.eclipse.uml2.uml.Classifier> type,std::shared_ptr<org.eclipse.uml2.uml.Classifier> classifier) ;
			
			
			
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
			std::weak_ptr<ReadIsClassifiedObjectActionActivation> m_thisReadIsClassifiedObjectActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_READISCLASSIFIEDOBJECTACTIONACTIVATIONREADISCLASSIFIEDOBJECTACTIONACTIVATIONIMPL_HPP */
