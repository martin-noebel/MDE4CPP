//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_OBJECTNODEACTIVATIONOBJECTNODEACTIVATIONIMPL_HPP
#define FUML_OBJECTNODEACTIVATIONOBJECTNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ObjectNodeActivation.hpp"

#include "fUML/impl/ActivityNodeActivationImpl.hpp"

//*********************************
namespace fUML 
{
	class ObjectNodeActivationImpl :virtual public ActivityNodeActivationImpl, virtual public ObjectNodeActivation 
	{
		public: 
			ObjectNodeActivationImpl(const ObjectNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ObjectNodeActivationImpl& operator=(ObjectNodeActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ObjectNodeActivationImpl();
			virtual std::shared_ptr<ObjectNodeActivation> getThisObjectNodeActivationPtr();
			virtual void setThisObjectNodeActivationPtr(std::weak_ptr<ObjectNodeActivation> thisObjectNodeActivationPtr);

			//Additional constructors for the containments back reference
			ObjectNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~ObjectNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void addToken(std::shared_ptr<fUML::Token>  token)  ;
			
			/*!
			 */ 
			virtual void clearTokens()  ;
			
			/*!
			 */ 
			virtual int countOfferedValues()  ;
			
			/*!
			 */ 
			virtual int countUnofferedTokens()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > getUnofferedTokens()  ;
			
			/*!
			 */ 
			virtual int removeToken(std::shared_ptr<fUML::Token>  token)  ;
			
			/*!
			 */ 
			virtual void run()  ;
			
			/*!
			 */ 
			virtual void sendOffers(std::shared_ptr<Bag<fUML::Token> >  tokens)  ;
			
			/*!
			 */ 
			virtual void sendUnofferedTokens()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > takeUnofferedTokens()  ;
			
			/*!
			 */ 
			virtual void terminate()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual int getOfferedTokenCount() const ;
			
			/*!
			 */ 
			virtual void setOfferedTokenCount (int _offeredTokenCount); 
			
			
			
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
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<ObjectNodeActivation> m_thisObjectNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_OBJECTNODEACTIVATIONOBJECTNODEACTIVATIONIMPL_HPP */
