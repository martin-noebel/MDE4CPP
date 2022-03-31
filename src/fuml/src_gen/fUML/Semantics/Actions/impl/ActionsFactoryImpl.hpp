//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONSFACTORYIMPL_HPP
#define FUML_SEMANTICS_ACTIONSFACTORYIMPL_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "fUML/Semantics/Actions/ActionsFactory.hpp"

namespace Actions 
{	class ActionActivation;
	class AddStructuralFeatureValueActionActivation;
	class ClearStructuralFeatureActionActivation;
	class CreateObjectActionActivation;
	class InputPinActivation;
	class OutputPinActivation;
	class PinActivation;
	class ReadSelfActionActivation;
	class StructuralFeatureActionActivation;
	class ValueSpecificationActionActivation;
	class Values;
	class WriteStructuralFeatureActionActivation;
}

namespace fUML::Semantics::Actions 
{
	class FUML_API ActionsFactoryImpl : virtual public ecore::EFactoryImpl , virtual public ActionsFactory 
	{
		private:    
			ActionsFactoryImpl(ActionsFactoryImpl const&) = delete;
			ActionsFactoryImpl& operator=(ActionsFactoryImpl const&) = delete;

		protected:
			friend class ActionsFactory;
			// Constructor
			ActionsFactoryImpl();

		public:
			virtual ~ActionsFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> createAddStructuralFeatureValueActionActivation(const int metaElementID = ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> createAddStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> createClearStructuralFeatureActionActivation(const int metaElementID = ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> createClearStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> createCreateObjectActionActivation(const int metaElementID = ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> createCreateObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation(const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation_as_inputPinActivation_in_ActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> par_ActionActivation, const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation(const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation_as_outputPinActivation_in_ActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> par_ActionActivation, const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> createReadSelfActionActivation(const int metaElementID = ActionsPackage::READSELFACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> createReadSelfActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READSELFACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> createValueSpecificationActionActivation(const int metaElementID = ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> createValueSpecificationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS) const ;
			 virtual std::shared_ptr<fUML::Semantics::Actions::Values> createValues(const int metaElementID = ActionsPackage::VALUES_CLASS) const ;
			 

		private:
			static ActionsFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONSFACTORYIMPL_HPP */
