//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIORPACKAGEIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIORPACKAGEIMPL_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp" 


namespace fUML::Semantics::CommonBehavior 
{
	class EventDispatchLoop;
	class Execution;
	class ParameterValue;}

namespace ecore
{
	class ecoreFactory;
}

namespace fUML::Semantics::CommonBehavior
{
	class FUML_API CommonBehaviorPackageImpl : public ecore::EPackageImpl ,virtual public CommonBehaviorPackage
	{
		private:    
			CommonBehaviorPackageImpl(CommonBehaviorPackageImpl const&) = delete;
			CommonBehaviorPackageImpl& operator=(CommonBehaviorPackageImpl const&) = delete;

		protected:
			CommonBehaviorPackageImpl();

		public:
			virtual ~CommonBehaviorPackageImpl();

			// Begin Class EventDispatchLoop
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEventDispatchLoop_Class() const ;
			
			
			
			
			// End Class EventDispatchLoop

			// Begin Class Execution
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExecution_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_behavior() const ;
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_context() const ;
			virtual std::shared_ptr<ecore::EReference> getExecution_Attribute_parameterValues() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation__copy() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_execute() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_getOutputParameterValues() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_getParameterValue_Parameter() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_new_() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_setParameterValue_ParameterValue() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecution_Operation_terminate() const ;
			
			// End Class Execution

			// Begin Class ParameterValue
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getParameterValue_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getParameterValue_Attribute_values() const ;
			
			virtual std::shared_ptr<ecore::EReference> getParameterValue_Attribute_parameter() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getParameterValue_Operation__copy() const ;
			
			// End Class ParameterValue

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_eventDispatchLoop_Class = nullptr;std::shared_ptr<ecore::EClass> m_execution_Class = nullptr;std::shared_ptr<ecore::EClass> m_parameterValue_Class = nullptr;
			
			std::shared_ptr<ecore::EAttribute> m_parameterValue_Attribute_values = nullptr;
			std::shared_ptr<ecore::EReference> m_execution_Attribute_behavior = nullptr;std::shared_ptr<ecore::EReference> m_execution_Attribute_context = nullptr;std::shared_ptr<ecore::EReference> m_parameterValue_Attribute_parameter = nullptr;std::shared_ptr<ecore::EReference> m_execution_Attribute_parameterValues = nullptr;
			std::shared_ptr<ecore::EOperation> m_execution_Operation__copy = nullptr;std::shared_ptr<ecore::EOperation> m_parameterValue_Operation__copy = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_execute = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_getOutputParameterValues = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_getParameterValue_Parameter = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_new_ = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_setParameterValue_ParameterValue = nullptr;std::shared_ptr<ecore::EOperation> m_execution_Operation_terminate = nullptr;

			friend class CommonBehaviorPackage;

			static bool isInited;
			static CommonBehaviorPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createEventDispatchLoopContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createParameterValueContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializeEventDispatchLoopContent();
			void initializeExecutionContent();
			void initializeParameterValueContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIORPACKAGEIMPL_HPP */
