//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_ACTIVITYPARAMETERNODEACTIVATIONACTIVITYPARAMETERNODEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_ACTIVITYPARAMETERNODEACTIVATIONACTIVITYPARAMETERNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ActivityParameterNodeActivation.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ObjectNodeActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class ActivityParameterNodeActivationImpl : virtual public ObjectNodeActivationImpl, virtual public ActivityParameterNodeActivation 
	{
		public: 
			ActivityParameterNodeActivationImpl(const ActivityParameterNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ActivityParameterNodeActivationImpl& operator=(ActivityParameterNodeActivationImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ActivityParameterNodeActivationImpl();
			virtual std::shared_ptr<ActivityParameterNodeActivation> getThisActivityParameterNodeActivationPtr() const;
			virtual void setThisActivityParameterNodeActivationPtr(std::weak_ptr<ActivityParameterNodeActivation> thisActivityParameterNodeActivationPtr);

			//Additional constructors for the containments back reference
			ActivityParameterNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~ActivityParameterNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void clearTokens() ;
			
			 
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > incomingTokens) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
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
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ActivityParameterNodeActivation> m_thisActivityParameterNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_ACTIVITYPARAMETERNODEACTIVATIONACTIVITYPARAMETERNODEACTIVATIONIMPL_HPP */
