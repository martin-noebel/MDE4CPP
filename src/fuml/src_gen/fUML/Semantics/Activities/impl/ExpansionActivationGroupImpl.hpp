//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_EXPANSIONACTIVATIONGROUPEXPANSIONACTIVATIONGROUPIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_EXPANSIONACTIVATIONGROUPEXPANSIONACTIVATIONGROUPIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fuml/fuml.hpp" 

// model includes
#include "../ExpansionActivationGroup.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityNodeActivationGroupImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API ExpansionActivationGroupImpl : virtual public ActivityNodeActivationGroupImpl, virtual public ExpansionActivationGroup 
	{
		public: 
			ExpansionActivationGroupImpl(const ExpansionActivationGroupImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExpansionActivationGroupImpl& operator=(ExpansionActivationGroupImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ExpansionActivationGroupImpl();
			virtual std::shared_ptr<ExpansionActivationGroup> getThisExpansionActivationGroupPtr() const;
			virtual void setThisExpansionActivationGroupPtr(std::weak_ptr<ExpansionActivationGroup> thisExpansionActivationGroupPtr);

			//Additional constructors for the containments back reference
			ExpansionActivationGroupImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> par_activityExecution);
			//Additional constructors for the containments back reference
			ExpansionActivationGroupImpl(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> par_containingNodeActivation);

		public:
			//destructor
			virtual ~ExpansionActivationGroupImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> getActivityExecution() const ; 
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> getNodeActivation(std::shared_ptr<uml::ActivityNode> node) ; 
			virtual void resume(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation) ; 
			virtual void suspend(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual int getIndex() const ;
			 
			virtual void setIndex (int _index);
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> getGroupInputs() const ;
			
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::ExpansionNodeActivation>> getGroupOutputs() const ;
			
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> getRegionActivation() const ;
			
			virtual void setRegionActivation(std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation>) ;
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Actions::OutputPinActivation>> getRegionInputs() const ;
			
			
			
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<ExpansionActivationGroup> m_thisExpansionActivationGroupPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_EXPANSIONACTIVATIONGROUPEXPANSIONACTIVATIONGROUPIMPL_HPP */
