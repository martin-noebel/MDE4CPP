//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PARTDECOMPOSITIONPARTDECOMPOSITIONIMPL_HPP
#define UML_PARTDECOMPOSITIONPARTDECOMPOSITIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../PartDecomposition.hpp"

#include "uml/impl/InteractionUseImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API PartDecompositionImpl : virtual public InteractionUseImpl, virtual public PartDecomposition 
	{
		public: 
			PartDecompositionImpl(const PartDecompositionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			PartDecompositionImpl& operator=(PartDecompositionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			PartDecompositionImpl();
			virtual std::shared_ptr<uml::PartDecomposition> getThisPartDecompositionPtr() const;
			virtual void setThisPartDecompositionPtr(std::weak_ptr<uml::PartDecomposition> thisPartDecompositionPtr);

			//Additional constructors for the containments back reference
			PartDecompositionImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			PartDecompositionImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			PartDecompositionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			PartDecompositionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~PartDecompositionImpl();
			
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
			std::weak_ptr<uml::PartDecomposition> m_thisPartDecompositionPtr;
	};
}
#endif /* end of include guard: UML_PARTDECOMPOSITIONPARTDECOMPOSITIONIMPL_HPP */
