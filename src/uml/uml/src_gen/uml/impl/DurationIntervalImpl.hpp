//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DURATIONINTERVALDURATIONINTERVALIMPL_HPP
#define UML_DURATIONINTERVALDURATIONINTERVALIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../DurationInterval.hpp"

#include "uml/impl/IntervalImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API DurationIntervalImpl : virtual public IntervalImpl, virtual public DurationInterval 
	{
		public: 
			DurationIntervalImpl(const DurationIntervalImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DurationIntervalImpl& operator=(DurationIntervalImpl const&); 

		protected:
			friend class umlFactoryImpl;
			DurationIntervalImpl();
			virtual std::shared_ptr<uml::DurationInterval> getThisDurationIntervalPtr() const;
			virtual void setThisDurationIntervalPtr(std::weak_ptr<uml::DurationInterval> thisDurationIntervalPtr);

			//Additional constructors for the containments back reference
			DurationIntervalImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			DurationIntervalImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			DurationIntervalImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			DurationIntervalImpl(std::weak_ptr<uml::Slot> par_owningSlot);
			//Additional constructors for the containments back reference
			DurationIntervalImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference
			DurationIntervalImpl(std::weak_ptr<uml::ValueSpecificationAction> par_valueSpecificationAction);

		public:
			//destructor
			virtual ~DurationIntervalImpl();
			
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
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::DurationInterval> m_thisDurationIntervalPtr;
	};
}
#endif /* end of include guard: UML_DURATIONINTERVALDURATIONINTERVALIMPL_HPP */
