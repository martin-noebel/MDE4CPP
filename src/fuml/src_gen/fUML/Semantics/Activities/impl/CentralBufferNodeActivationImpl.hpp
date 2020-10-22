//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_CENTRALBUFFERNODEACTIVATIONCENTRALBUFFERNODEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_CENTRALBUFFERNODEACTIVATIONCENTRALBUFFERNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CentralBufferNodeActivation.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ObjectNodeActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class CentralBufferNodeActivationImpl : virtual public ObjectNodeActivationImpl, virtual public CentralBufferNodeActivation 
	{
		public: 
			CentralBufferNodeActivationImpl(const CentralBufferNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CentralBufferNodeActivationImpl& operator=(CentralBufferNodeActivationImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			CentralBufferNodeActivationImpl();
			virtual std::shared_ptr<CentralBufferNodeActivation> getThisCentralBufferNodeActivationPtr() const;
			virtual void setThisCentralBufferNodeActivationPtr(std::weak_ptr<CentralBufferNodeActivation> thisCentralBufferNodeActivationPtr);

			//Additional constructors for the containments back reference
			CentralBufferNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~CentralBufferNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token> >  incomingTokens) ;
			
			
			
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
			std::weak_ptr<CentralBufferNodeActivation> m_thisCentralBufferNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_CENTRALBUFFERNODEACTIVATIONCENTRALBUFFERNODEACTIVATIONIMPL_HPP */
