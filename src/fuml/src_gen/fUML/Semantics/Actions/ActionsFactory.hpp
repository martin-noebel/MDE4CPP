//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONSFACTORY_HPP
#define FUML_SEMANTICS_ACTIONSFACTORY_HPP
// namespace macro header include
#include "fUML/fUML.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"

namespace fUML::Semantics::Activities
{
	class ActivityNodeActivationGroup;
}



namespace fUML::Semantics::Actions 
{
	class FUML_API ActionsFactory : virtual public ecore::EFactory 
	{
		private:    
			ActionsFactory(ActionsFactory const&) = delete;
			ActionsFactory& operator=(ActionsFactory const&) = delete;
		protected:
			ActionsFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ActionsFactory> instance;
			public:
				static std::shared_ptr<ActionsFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> createAddStructuralFeatureValueActionActivation(const int metaElementID = ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> createAddStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> createCallBehaviorActionActivation(const int metaElementID = ActionsPackage::CALLBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> createCallBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CALLBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> createCallOperationActionActivation(const int metaElementID = ActionsPackage::CALLOPERATIONACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> createCallOperationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CALLOPERATIONACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> createClearStructuralFeatureActionActivation(const int metaElementID = ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> createClearStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> createCreateObjectActionActivation(const int metaElementID = ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> createCreateObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> createDestroyObjectActionActivation(const int metaElementID = ActionsPackage::DESTROYOBJECTACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> createDestroyObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::DESTROYOBJECTACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation(const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation_as_inputPinActivation_in_ActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> par_ActionActivation, const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation(const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation_as_outputPinActivation_in_ActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> par_ActionActivation, const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> createReadSelfActionActivation(const int metaElementID = ActionsPackage::READSELFACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> createReadSelfActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READSELFACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> createReadStructuralFeatureActionActivation(const int metaElementID = ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> createReadStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivation> createRemoveStructuralFeatureValueActionActivation(const int metaElementID = ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActionActivation> createRemoveStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> createStructuredActivityNodeActivation(const int metaElementID = ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> createStructuredActivityNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> createValueSpecificationActionActivation(const int metaElementID = ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> createValueSpecificationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::Values> createValues(const int metaElementID = ActionsPackage::VALUES_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONSFACTORY_HPP */
