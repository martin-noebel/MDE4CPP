//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_READLINKACTIONACTIVATIONREADLINKACTIONACTIVATIONIMPL_HPP
#define FUML_READLINKACTIONACTIVATIONREADLINKACTIONACTIVATIONIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../ReadLinkActionActivation.hpp"

#include "impl/LinkActionActivationImpl.hpp"



//*********************************
namespace fUML 
{
	class ReadLinkActionActivationImpl :virtual public LinkActionActivationImpl, virtual public ReadLinkActionActivation 
	{
		public: 
			ReadLinkActionActivationImpl(const ReadLinkActionActivationImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			ReadLinkActionActivationImpl& operator=(ReadLinkActionActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ReadLinkActionActivationImpl();

		public:
			//destructor
			virtual ~ReadLinkActionActivationImpl();
			
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
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_READLINKACTIONACTIVATIONREADLINKACTIONACTIVATIONIMPL_HPP */
