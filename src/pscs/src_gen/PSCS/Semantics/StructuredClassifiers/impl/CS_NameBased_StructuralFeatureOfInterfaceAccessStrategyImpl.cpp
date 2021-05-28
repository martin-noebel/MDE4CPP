#include "PSCS/Semantics/StructuredClassifiers/impl/CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence


#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_StructuralFeatureOfInterfaceAccessStrategy.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "uml/StructuralFeature.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::~CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl(const CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl & obj): CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl()
{
	*this = obj;
}

CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl& CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::operator=(const CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	CS_StructuralFeatureOfInterfaceAccessStrategyImpl::operator=(obj);
	CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::copy() const
{
	std::shared_ptr<CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl> element(new CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl());
	*element =(*this);
	element->setThisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::eStaticClass() const
{
	return PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_NameBased_StructuralFeatureOfInterfaceAccessStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::read(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> cs_Object,std::shared_ptr<uml::StructuralFeature> feature)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			// returns a copy of the first feature value of cs_Object where the name
	// of the corresponding feature matches the name of the feature given as a parameter
	// Otherwise, returns an empty feature value
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues = cs_Object->getFeatureValues();
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> matchingFeatureValue = nullptr;
	for(unsigned int i = 0; (i < featureValues->size()) && (matchingFeatureValue == nullptr); i++) {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = featureValues->at(i);
		if(featureValue->getFeature()->getName() == feature->getName()) {
			matchingFeatureValue = featureValue;
		}
	}
	if(matchingFeatureValue != nullptr) {
		matchingFeatureValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::FeatureValue>(matchingFeatureValue->copy());
		matchingFeatureValue->setFeature(feature);
	}
	else {
		matchingFeatureValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createFeatureValue();
		matchingFeatureValue->setFeature(feature);
		matchingFeatureValue->setPosition(0);
	}
	return matchingFeatureValue;
	//end of body
}

void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::write(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> cs_Object,std::shared_ptr<uml::StructuralFeature> feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> values,int position)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			// returns a copy of the first feature value of cs_Object where the name
	// of the corresponding feature matches the name of the feature given as a parameter
	// Otherwise, returns an empty feature value
	std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues = cs_Object->getFeatureValues();
	std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> matchingFeatureValue = nullptr;
	for(unsigned int i = 0; (i < featureValues->size()) && (matchingFeatureValue == nullptr); i++) {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> featureValue = featureValues->at(i);
		if(featureValue->getFeature()->getName() == feature->getName()) {
			matchingFeatureValue = featureValue;
		}
	}
	if(matchingFeatureValue != nullptr) {
		cs_Object->assignFeatureValue(matchingFeatureValue->getFeature(), values, position);
	}
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy> CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::getThisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr() const
{
	return m_thisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr.lock();
}
void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::setThisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr(std::weak_ptr<CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy> thisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr)
{
	m_thisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr = thisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr;
	setThisCS_StructuralFeatureOfInterfaceAccessStrategyPtr(thisCS_NameBased_StructuralFeatureOfInterfaceAccessStrategyPtr);
}
std::shared_ptr<ecore::EObject> CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return CS_StructuralFeatureOfInterfaceAccessStrategyImpl::eGet(featureID, resolve, coreType);
}
bool CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return CS_StructuralFeatureOfInterfaceAccessStrategyImpl::internalEIsSet(featureID);
}
bool CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return CS_StructuralFeatureOfInterfaceAccessStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 2104
		case StructuredClassifiersPackage::CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_READ_CS_OBJECT_STRUCTURALFEATURE:
		{
			//Retrieve input parameter 'cs_Object'
			//parameter 0
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> incoming_param_cs_Object;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_cs_Object_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_cs_Object = (*incoming_param_cs_Object_arguments_citer)->get()->get<std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> >();
			//Retrieve input parameter 'feature'
			//parameter 1
			std::shared_ptr<uml::StructuralFeature> incoming_param_feature;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_feature = (*incoming_param_feature_arguments_citer)->get()->get<std::shared_ptr<uml::StructuralFeature> >();
			result = eAny(this->read(incoming_param_cs_Object,incoming_param_feature));
			break;
		}
		
		// 2105
		case StructuredClassifiersPackage::CS_NAMEBASED_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_OPERATION_WRITE_CS_OBJECT_EINT:
		{
			//Retrieve input parameter 'cs_Object'
			//parameter 0
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> incoming_param_cs_Object;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_cs_Object_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_cs_Object = (*incoming_param_cs_Object_arguments_citer)->get()->get<std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> >();
			//Retrieve input parameter 'feature'
			//parameter 1
			std::shared_ptr<uml::StructuralFeature> incoming_param_feature;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_feature = (*incoming_param_feature_arguments_citer)->get()->get<std::shared_ptr<uml::StructuralFeature> >();
			//Retrieve input parameter 'values'
			//parameter 2
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> incoming_param_values;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_values_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_values = (*incoming_param_values_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::Values::Value>> >();
			//Retrieve input parameter 'position'
			//parameter 3
			int incoming_param_position;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_position_arguments_citer = std::next(arguments->begin(), 3);
			incoming_param_position = (*incoming_param_position_arguments_citer)->get()->get<int >();
			this->write(incoming_param_cs_Object,incoming_param_feature,incoming_param_values,incoming_param_position);
			break;
		}

		default:
		{
			// call superTypes
			result = CS_StructuralFeatureOfInterfaceAccessStrategyImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CS_StructuralFeatureOfInterfaceAccessStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CS_StructuralFeatureOfInterfaceAccessStrategyImpl::loadNode(nodeName, loadHandler);
}

void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	CS_StructuralFeatureOfInterfaceAccessStrategyImpl::resolveReferences(featureID, references);
}

void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CS_StructuralFeatureOfInterfaceAccessStrategyImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void CS_NameBased_StructuralFeatureOfInterfaceAccessStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

