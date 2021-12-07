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
			/*!
			Assume that within Interaction X, Lifeline L is of class C and decomposed to D. Within X there is a sequence of constructs along L (such constructs are CombinedFragments, InteractionUse and (plain) OccurrenceSpecifications). Then a corresponding sequence of constructs must appear within D, matched one-to-one in the same order. i) CombinedFragment covering L are matched with an extra-global CombinedFragment in D. ii) An InteractionUse covering L is matched with a global (i.e., covering all Lifelines) InteractionUse in D. iii) A plain OccurrenceSpecification on L is considered an actualGate that must be matched by a formalGate of D.
			*/
			 
			virtual bool assume(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			Assume that within Interaction X, Lifeline L is of class C and decomposed to D. Assume also that there is within X an InteractionUse (say) U that covers L. According to the constraint above U will have a counterpart CU within D. Within the Interaction referenced by U, L should also be decomposed, and the decomposition should reference CU. (This rule is called commutativity of decomposition.)
			*/
			 
			virtual bool commutativity_of_decomposition(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			PartDecompositions apply only to Parts that are Parts of Internal Structures not to Parts of Collaborations.
			*/
			 
			virtual bool parts_of_internal_structures(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::PartDecomposition> m_thisPartDecompositionPtr;
	};
}
#endif /* end of include guard: UML_PARTDECOMPOSITIONPARTDECOMPOSITIONIMPL_HPP */
