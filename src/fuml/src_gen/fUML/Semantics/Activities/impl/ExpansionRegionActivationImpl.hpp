//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_EXPANSIONREGIONACTIVATIONEXPANSIONREGIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_EXPANSIONREGIONACTIVATIONEXPANSIONREGIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ExpansionRegionActivation.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class ExpansionRegionActivationImpl : virtual public fUML::Semantics::Actions::ActionActivationImpl, virtual public ExpansionRegionActivation 
	{
		public: 
			ExpansionRegionActivationImpl(const ExpansionRegionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ExpansionRegionActivationImpl& operator=(ExpansionRegionActivationImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ExpansionRegionActivationImpl();
			virtual std::shared_ptr<ExpansionRegionActivation> getThisExpansionRegionActivationPtr() const;
			virtual void setThisExpansionRegionActivationPtr(std::weak_ptr<ExpansionRegionActivation> thisExpansionRegionActivationPtr);

			//Additional constructors for the containments back reference
			ExpansionRegionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~ExpansionRegionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void doAction() ;
			
			 
			virtual void doOutput() ;
			
			 
			virtual void doStructuredActivity() ;
			
			 
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> getExpansionNodeActivation(std::shared_ptr<uml::ExpansionNode>  node) ;
			
			 
			virtual bool isSuspended() ;
			
			 
			virtual int numberOfValues() ;
			
			 
			virtual void resume(std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup>  activationGroup) ;
			
			 
			virtual void runGroup(std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup>  activationGroup) ;
			
			 
			virtual void runIterative() ;
			
			 
			virtual void runParallel() ;
			
			 
			virtual void sendOffers() ;
			
			 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > takeOfferedTokens() ;
			
			 
			virtual void terminate() ;
			
			 
			virtual void terminateGroup(std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup>  activationGroup) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual int getNext() const ;
			
			 
			virtual void setNext (int _next); 
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionActivationGroup>> getActivationGroups() const ;
			
			
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> getInputExpansionTokens() const ;
			
			
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::TokenSet>> getInputTokens() const ;
			
			
							
			
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
			std::weak_ptr<ExpansionRegionActivation> m_thisExpansionRegionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_EXPANSIONREGIONACTIVATIONEXPANSIONREGIONACTIVATIONIMPL_HPP */
