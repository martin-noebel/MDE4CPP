//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSFACTORYIMPL_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSFACTORYIMPL_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"

namespace StructuredClassifiers 
{	class CS_DefaultRequestPropagationStrategy;
	class CS_DispatchOperationOfInterfaceStrategy;
	class CS_InteractionPoint;
	class CS_Link;
	class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy;
	class CS_Object;
	class CS_Reference;
	class CS_RequestPropagationStrategy;
	class CS_StructuralFeatureOfInterfaceAccessStrategy;
}

namespace PSCS::Semantics::StructuredClassifiers 
{
	class PSCS_API StructuredClassifiersFactoryImpl : virtual public ecore::EFactoryImpl , virtual public StructuredClassifiersFactory 
	{
		private:    
			StructuredClassifiersFactoryImpl(StructuredClassifiersFactoryImpl const&) = delete;
			StructuredClassifiersFactoryImpl& operator=(StructuredClassifiersFactoryImpl const&) = delete;

		protected:
			friend class StructuredClassifiersPluginImpl;  
			// Constructor
			StructuredClassifiersFactoryImpl();

		public:
			virtual ~StructuredClassifiersFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DefaultRequestPropagationStrategy> createCS_DefaultRequestPropagationStrategy(const int metaElementID = StructuredClassifiersPackage::CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_DispatchOperationOfInterfaceStrategy> createCS_DispatchOperationOfInterfaceStrategy(const int metaElementID = StructuredClassifiersPackage::CS_DISPATCHOPERATIONOFINTERFACESTRATEGY_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> createCS_InteractionPoint(const int metaElementID = StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> createCS_InteractionPoint_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> createCS_InteractionPoint_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> createCS_InteractionPoint_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> createCS_Link(const int metaElementID = StructuredClassifiersPackage::CS_LINK_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> createCS_Link_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID = StructuredClassifiersPackage::CS_LINK_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> createCS_Link_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = StructuredClassifiersPackage::CS_LINK_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> createCS_Link_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = StructuredClassifiersPackage::CS_LINK_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Link> createCS_Link_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = StructuredClassifiersPackage::CS_LINK_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy> createCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy(const int metaElementID = StructuredClassifiersPackage::CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> createCS_Object(const int metaElementID = StructuredClassifiersPackage::CS_OBJECT_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> createCS_Object_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID = StructuredClassifiersPackage::CS_OBJECT_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> createCS_Object_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = StructuredClassifiersPackage::CS_OBJECT_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> createCS_Object_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = StructuredClassifiersPackage::CS_OBJECT_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> createCS_Object_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = StructuredClassifiersPackage::CS_OBJECT_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> createCS_Reference(const int metaElementID = StructuredClassifiersPackage::CS_REFERENCE_CLASS) const ;
			 //Add as contained object
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> createCS_Reference_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = StructuredClassifiersPackage::CS_REFERENCE_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> createCS_Reference_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = StructuredClassifiersPackage::CS_REFERENCE_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> createCS_Reference_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = StructuredClassifiersPackage::CS_REFERENCE_CLASS) const ;
			 

		private:
			static StructuredClassifiersFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERSFACTORYIMPL_HPP */
