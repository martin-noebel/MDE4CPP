//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIORFACTORYIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIORFACTORYIMPL_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"

namespace CommonBehavior 
{	class EventDispatchLoop;
	class Execution;
	class ParameterValue;
}

namespace fUML::Semantics::CommonBehavior 
{
	class FUML_API CommonBehaviorFactoryImpl : virtual public ecore::EFactoryImpl , virtual public CommonBehaviorFactory 
	{
		private:    
			CommonBehaviorFactoryImpl(CommonBehaviorFactoryImpl const&) = delete;
			CommonBehaviorFactoryImpl& operator=(CommonBehaviorFactoryImpl const&) = delete;

		protected:
			friend class CommonBehaviorFactory;
			// Constructor
			CommonBehaviorFactoryImpl();

		public:
			virtual ~CommonBehaviorFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventDispatchLoop> createEventDispatchLoop(const int metaElementID = CommonBehaviorPackage::EVENTDISPATCHLOOP_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> createParameterValue(const int metaElementID = CommonBehaviorPackage::PARAMETERVALUE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> createParameterValue_as_parameterValues_in_Execution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> par_Execution, const int metaElementID = CommonBehaviorPackage::PARAMETERVALUE_CLASS) const ;
			 

		private:
			static CommonBehaviorFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIORFACTORYIMPL_HPP */
