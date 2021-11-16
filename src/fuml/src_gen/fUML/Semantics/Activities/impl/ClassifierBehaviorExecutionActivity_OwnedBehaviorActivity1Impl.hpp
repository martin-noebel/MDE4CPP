//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1IMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1IMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl : virtual public ecore::EModelElementImpl,
virtual public ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1 
	{
		public: 
			ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl(const ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl& operator=(ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl();
			virtual std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> getThisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr() const;
			virtual void setThisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr(std::weak_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> thisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr);


		public:
			//destructor
			virtual ~ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Impl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> m_thisClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1Ptr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1IMPL_HPP */
