//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_CONTROLTOKENCONTROLTOKENIMPL_HPP
#define FUML_CONTROLTOKENCONTROLTOKENIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ControlToken.hpp"

#include "fUML/impl/TokenImpl.hpp"

//*********************************
namespace fUML 
{
	class ControlTokenImpl :virtual public TokenImpl, virtual public ControlToken 
	{
		public: 
			ControlTokenImpl(const ControlTokenImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ControlTokenImpl& operator=(ControlTokenImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ControlTokenImpl();
			virtual std::shared_ptr<ControlToken> getThisControlTokenPtr();
			virtual void setThisControlTokenPtr(std::weak_ptr<ControlToken> thisControlTokenPtr);



		public:
			//destructor
			virtual ~ControlTokenImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual bool equals(std::shared_ptr<fUML::Token>  other)  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> getValue()  const  ;
			
			/*!
			 */ 
			virtual bool isControl()  ;
			
			
			
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
			std::weak_ptr<ControlToken> m_thisControlTokenPtr;
	};
}
#endif /* end of include guard: FUML_CONTROLTOKENCONTROLTOKENIMPL_HPP */
