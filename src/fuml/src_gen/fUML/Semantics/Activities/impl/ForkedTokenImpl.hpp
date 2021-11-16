//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_FORKEDTOKENFORKEDTOKENIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_FORKEDTOKENFORKEDTOKENIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ForkedToken.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/TokenImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API ForkedTokenImpl : virtual public TokenImpl, virtual public ForkedToken 
	{
		public: 
			ForkedTokenImpl(const ForkedTokenImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ForkedTokenImpl& operator=(ForkedTokenImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ForkedTokenImpl();
			virtual std::shared_ptr<fUML::Semantics::Activities::ForkedToken> getThisForkedTokenPtr() const;
			virtual void setThisForkedTokenPtr(std::weak_ptr<fUML::Semantics::Activities::ForkedToken> thisForkedTokenPtr);

			//Additional constructors for the containments back reference
			ForkedTokenImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_holder);

		public:
			//destructor
			virtual ~ForkedTokenImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Activities::Token> _copy() ;
			virtual bool equals(std::shared_ptr<fUML::Semantics::Activities::Token> otherToken) ;
			virtual std::shared_ptr<fUML::Semantics::Values::Value> getValue() const ;
			virtual bool isControl() ;
			virtual void withdraw() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isBaseTokenIsWithdrawn() const ;
			virtual void setBaseTokenIsWithdrawn (bool _baseTokenIsWithdrawn);
			virtual int getRemainingOffersCount() const ;
			virtual void setRemainingOffersCount (int _remainingOffersCount);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Activities::Token> getBaseToken() const ;
			virtual void setBaseToken(std::shared_ptr<fUML::Semantics::Activities::Token>) ;
			
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
			std::weak_ptr<fUML::Semantics::Activities::ForkedToken> m_thisForkedTokenPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_FORKEDTOKENFORKEDTOKENIMPL_HPP */
