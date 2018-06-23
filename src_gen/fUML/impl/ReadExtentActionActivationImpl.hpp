//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_READEXTENTACTIONACTIVATIONREADEXTENTACTIONACTIVATIONIMPL_HPP
#define FUML_READEXTENTACTIONACTIVATIONREADEXTENTACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ReadExtentActionActivation.hpp"

#include "fUML/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML 
{
	class ReadExtentActionActivationImpl :virtual public ActionActivationImpl, virtual public ReadExtentActionActivation 
	{
		public: 
			ReadExtentActionActivationImpl(const ReadExtentActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ReadExtentActionActivationImpl& operator=(ReadExtentActionActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ReadExtentActionActivationImpl();
			virtual std::shared_ptr<ReadExtentActionActivation> getThisReadExtentActionActivationPtr();
			virtual void setThisReadExtentActionActivationPtr(std::weak_ptr<ReadExtentActionActivation> thisReadExtentActionActivationPtr);

			//Additional constructors for the containments back reference
			ReadExtentActionActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~ReadExtentActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<Union<fUML::PinActivation>> getPinActivation() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ReadExtentActionActivation> m_thisReadExtentActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_READEXTENTACTIONACTIVATIONREADEXTENTACTIONACTIVATIONIMPL_HPP */
