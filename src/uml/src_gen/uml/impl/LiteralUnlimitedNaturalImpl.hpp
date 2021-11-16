//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LITERALUNLIMITEDNATURALLITERALUNLIMITEDNATURALIMPL_HPP
#define UML_LITERALUNLIMITEDNATURALLITERALUNLIMITEDNATURALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../LiteralUnlimitedNatural.hpp"

#include "uml/impl/LiteralSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API LiteralUnlimitedNaturalImpl : virtual public LiteralSpecificationImpl, virtual public LiteralUnlimitedNatural 
	{
		public: 
			LiteralUnlimitedNaturalImpl(const LiteralUnlimitedNaturalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LiteralUnlimitedNaturalImpl& operator=(LiteralUnlimitedNaturalImpl const&); 

		protected:
			friend class umlFactoryImpl;
			LiteralUnlimitedNaturalImpl();
			virtual std::shared_ptr<uml::LiteralUnlimitedNatural> getThisLiteralUnlimitedNaturalPtr() const;
			virtual void setThisLiteralUnlimitedNaturalPtr(std::weak_ptr<uml::LiteralUnlimitedNatural> thisLiteralUnlimitedNaturalPtr);

			//Additional constructors for the containments back reference
			LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::Slot> par_owningSlot);
			//Additional constructors for the containments back reference
			LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference
			LiteralUnlimitedNaturalImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

		public:
			//destructor
			virtual ~LiteralUnlimitedNaturalImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The query isComputable() is redefined to be true.
			result = (true)
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isComputable() ;
			/*!
			The query unlimitedValue() gives the value.
			result = (value)
			<p>From package UML::Values.</p>
			*/
			 
			virtual int unlimitedValue() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			The specified UnlimitedNatural value.
			<p>From package UML::Values.</p>
			*/
			 
			virtual int getValue() const ;
			/*!
			The specified UnlimitedNatural value.
			<p>From package UML::Values.</p>
			*/
			 
			virtual void setValue (int _value);
			
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<uml::LiteralUnlimitedNatural> m_thisLiteralUnlimitedNaturalPtr;
	};
}
#endif /* end of include guard: UML_LITERALUNLIMITEDNATURALLITERALUNLIMITEDNATURALIMPL_HPP */
