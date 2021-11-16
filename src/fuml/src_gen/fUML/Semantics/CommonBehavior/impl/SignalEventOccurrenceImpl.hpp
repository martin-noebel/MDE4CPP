//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_SIGNALEVENTOCCURRENCESIGNALEVENTOCCURRENCEIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_SIGNALEVENTOCCURRENCESIGNALEVENTOCCURRENCEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../SignalEventOccurrence.hpp"

#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/EventOccurrenceImpl.hpp"

//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	class FUML_API SignalEventOccurrenceImpl : virtual public EventOccurrenceImpl, virtual public SignalEventOccurrence 
	{
		public: 
			SignalEventOccurrenceImpl(const SignalEventOccurrenceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			SignalEventOccurrenceImpl& operator=(SignalEventOccurrenceImpl const&); 

		protected:
			friend class fUML::Semantics::CommonBehavior::CommonBehaviorFactoryImpl;
			SignalEventOccurrenceImpl();
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> getThisSignalEventOccurrencePtr() const;
			virtual void setThisSignalEventOccurrencePtr(std::weak_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> thisSignalEventOccurrencePtr);


		public:
			//destructor
			virtual ~SignalEventOccurrenceImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > getParameterValues() ;
			virtual bool match(std::shared_ptr<uml::Trigger> trigger) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> getSignalInstance() const ;
			virtual void setSignalInstance(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance>) ;
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> m_thisSignalEventOccurrencePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_SIGNALEVENTOCCURRENCESIGNALEVENTOCCURRENCEIMPL_HPP */
