//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERVALINTERVALIMPL_HPP
#define UML_INTERVALINTERVALIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Interval.hpp"

#include "uml/impl/ValueSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class IntervalImpl : virtual public ValueSpecificationImpl, virtual public Interval 
	{
		public: 
			IntervalImpl(const IntervalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			IntervalImpl& operator=(IntervalImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			IntervalImpl();
			virtual std::shared_ptr<Interval> getThisIntervalPtr() const;
			virtual void setThisIntervalPtr(std::weak_ptr<Interval> thisIntervalPtr);

			//Additional constructors for the containments back reference
			IntervalImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			IntervalImpl(std::weak_ptr<uml::Element > par_owner);


			//Additional constructors for the containments back reference
			IntervalImpl(std::weak_ptr<uml::Package > par_owningPackage);


			//Additional constructors for the containments back reference
			IntervalImpl(std::weak_ptr<uml::Slot > par_owningSlot);


			//Additional constructors for the containments back reference
			IntervalImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);


			//Additional constructors for the containments back reference
			IntervalImpl(std::weak_ptr<uml::ValueSpecificationAction > par_valueSpecificationAction);




		public:
			//destructor
			virtual ~IntervalImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			Refers to the ValueSpecification denoting the maximum value of the range.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification > getMax() const ;
			
			/*!
			Refers to the ValueSpecification denoting the maximum value of the range.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setMax(std::shared_ptr<uml::ValueSpecification> _max) ;
			
			/*!
			Refers to the ValueSpecification denoting the minimum value of the range.
			<p>From package UML::Values.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification > getMin() const ;
			
			/*!
			Refers to the ValueSpecification denoting the minimum value of the range.
			<p>From package UML::Values.</p>
			*/
			
			virtual void setMin(std::shared_ptr<uml::ValueSpecification> _min) ;
			
							
			
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
			std::weak_ptr<Interval> m_thisIntervalPtr;
	};
}
#endif /* end of include guard: UML_INTERVALINTERVALIMPL_HPP */
