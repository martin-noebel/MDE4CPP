//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_FINALSTATEFINALSTATEIMPL_HPP
#define UML_FINALSTATEFINALSTATEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../FinalState.hpp"

#include "uml/impl/StateImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API FinalStateImpl : virtual public StateImpl, virtual public FinalState 
	{
		public: 
			FinalStateImpl(const FinalStateImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			FinalStateImpl& operator=(FinalStateImpl const&); 

		protected:
			friend class umlFactoryImpl;
			FinalStateImpl();
			virtual std::shared_ptr<uml::FinalState> getThisFinalStatePtr() const;
			virtual void setThisFinalStatePtr(std::weak_ptr<uml::FinalState> thisFinalStatePtr);

			//Additional constructors for the containments back reference
			FinalStateImpl(std::weak_ptr<uml::Region> par_container);
			//Additional constructors for the containments back reference
			FinalStateImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			FinalStateImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~FinalStateImpl();
			
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

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::FinalState> m_thisFinalStatePtr;
	};
}
#endif /* end of include guard: UML_FINALSTATEFINALSTATEIMPL_HPP */
