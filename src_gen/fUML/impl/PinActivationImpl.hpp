//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_PINACTIVATIONPINACTIVATIONIMPL_HPP
#define FUML_PINACTIVATIONPINACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../PinActivation.hpp"

#include "fUML/impl/ObjectNodeActivationImpl.hpp"

//*********************************
namespace fUML 
{
	class PinActivationImpl :virtual public ObjectNodeActivationImpl, virtual public PinActivation 
	{
		public: 
			PinActivationImpl(const PinActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			PinActivationImpl& operator=(PinActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			PinActivationImpl();
			virtual std::shared_ptr<PinActivation> getThisPinActivationPtr();
			virtual void setThisPinActivationPtr(std::weak_ptr<PinActivation> thisPinActivationPtr);

			//Additional constructors for the containments back reference
			PinActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~PinActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens)  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > takeOfferedTokens()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::weak_ptr<fUML::ActionActivation > getActionActivation() const ;
			
			/*!
			 */
			virtual void setActionActivation(std::shared_ptr<fUML::ActionActivation> _actionActivation_actionActivation) ;
							
			
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
			std::weak_ptr<PinActivation> m_thisPinActivationPtr;
	};
}
#endif /* end of include guard: FUML_PINACTIVATIONPINACTIVATIONIMPL_HPP */
