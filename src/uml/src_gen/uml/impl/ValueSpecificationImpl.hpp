//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_VALUESPECIFICATIONVALUESPECIFICATIONIMPL_HPP
#define UML_VALUESPECIFICATIONVALUESPECIFICATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ValueSpecification.hpp"

#include "uml/impl/PackageableElementImpl.hpp"
#include "uml/impl/TypedElementImpl.hpp"

//*********************************
namespace uml 
{
	class ValueSpecificationImpl : virtual public PackageableElementImpl, virtual public TypedElementImpl, virtual public ValueSpecification 
	{
		public: 
			ValueSpecificationImpl(const ValueSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ValueSpecificationImpl& operator=(ValueSpecificationImpl const&) = delete;

		protected:
			friend class umlFactoryImpl;
			ValueSpecificationImpl();
			virtual std::shared_ptr<ValueSpecification> getThisValueSpecificationPtr() const;
			virtual void setThisValueSpecificationPtr(std::weak_ptr<ValueSpecification> thisValueSpecificationPtr);

			//Additional constructors for the containments back reference
			ValueSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			ValueSpecificationImpl(std::weak_ptr<uml::Element > par_owner);


			//Additional constructors for the containments back reference
			ValueSpecificationImpl(std::weak_ptr<uml::Package > par_owningPackage);


			//Additional constructors for the containments back reference
			ValueSpecificationImpl(std::weak_ptr<uml::Slot > par_owningSlot);


			//Additional constructors for the containments back reference
			ValueSpecificationImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);


			//Additional constructors for the containments back reference
			ValueSpecificationImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction);




		public:
			//destructor
			virtual ~ValueSpecificationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The query booleanValue() gives a single Boolean value when one can be computed.
			result = (null)
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool booleanValue() ;
			
			/*!
			The query integerValue() gives a single Integer value when one can be computed.
			result = (null)
			<p>From package UML::Values.</p>
			*/
			 
			virtual int integerValue() ;
			
			/*!
			The query isComputable() determines whether a value specification can be computed in a model. This operation cannot be fully defined in OCL. A conforming implementation is expected to deliver true for this operation for all ValueSpecifications that it can compute, and to compute all of those for which the operation is true. A conforming implementation is expected to be able to compute at least the value of all LiteralSpecifications.
			result = (false)
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isComputable() ;
			
			/*!
			The query isNull() returns true when it can be computed that the value is null.
			result = (false)
			<p>From package UML::Values.</p>
			*/
			 
			virtual bool isNull() ;
			
			/*!
			The query realValue() gives a single Real value when one can be computed.
			result = (null)
			<p>From package UML::Values.</p>
			*/
			 
			virtual double realValue() ;
			
			/*!
			The query stringValue() gives a single String value when one can be computed.
			result = (null)
			<p>From package UML::Values.</p>
			*/
			 
			virtual std::string stringValue() ;
			
			/*!
			The query unlimitedValue() gives a single UnlimitedNatural value when one can be computed.
			result = (null)
			<p>From package UML::Values.</p>
			*/
			 
			virtual int unlimitedValue() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::weak_ptr<uml::Slot > getOwningSlot() const ;
			
			
			virtual void setOwningSlot(std::shared_ptr<uml::Slot> _owningSlot) ;
			
			
			virtual std::weak_ptr<uml::ValueSpecificationAction > getValueSpecificationAction() const ;
			
			
			virtual void setValueSpecificationAction(std::shared_ptr<uml::ValueSpecificationAction> _valueSpecificationAction) ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ValueSpecification> m_thisValueSpecificationPtr;
	};
}
#endif /* end of include guard: UML_VALUESPECIFICATIONVALUESPECIFICATIONIMPL_HPP */
