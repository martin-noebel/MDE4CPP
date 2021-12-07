//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_LINKACTIONACTIVATIONLINKACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_LINKACTIONACTIVATIONLINKACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../LinkActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API LinkActionActivationImpl : virtual public ActionActivationImpl, virtual public LinkActionActivation 
	{
		public: 
			LinkActionActivationImpl(const LinkActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;
			LinkActionActivationImpl& operator=(LinkActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			LinkActionActivationImpl();
			virtual std::shared_ptr<fUML::Semantics::Actions::LinkActionActivation> getThisLinkActionActivationPtr() const;
			virtual void setThisLinkActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::LinkActionActivation> thisLinkActionActivationPtr);

			//Additional constructors for the containments back reference
			LinkActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~LinkActionActivationImpl() = 0;
			
			//*********************************
			// Operations
			//*********************************
			virtual bool endMatchesEndData(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link,std::shared_ptr<uml::LinkEndData> endData) ;
			virtual std::shared_ptr<uml::Association> getAssociation() ;
			virtual bool linkMatchesEndData(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Link> link,std::shared_ptr<Bag<uml::LinkEndData>> endDataList) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ;
			
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Actions::LinkActionActivation> m_thisLinkActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_LINKACTIONACTIVATIONLINKACTIONACTIVATIONIMPL_HPP */
