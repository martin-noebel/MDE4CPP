#include "PSCS/Semantics/StructuredClassifiers/impl/CS_RequestPropagationStrategyImpl.hpp"

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


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence


#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"

//Factories an Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
CS_RequestPropagationStrategyImpl::CS_RequestPropagationStrategyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_RequestPropagationStrategyImpl::~CS_RequestPropagationStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_RequestPropagationStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CS_RequestPropagationStrategyImpl::CS_RequestPropagationStrategyImpl(const CS_RequestPropagationStrategyImpl & obj): CS_RequestPropagationStrategyImpl()
{
	*this = obj;
}

CS_RequestPropagationStrategyImpl& CS_RequestPropagationStrategyImpl::operator=(const CS_RequestPropagationStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Loci::SemanticStrategyImpl::operator=(obj);
	CS_RequestPropagationStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_RequestPropagationStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_RequestPropagationStrategyImpl::copy() const
{
	std::shared_ptr<CS_RequestPropagationStrategyImpl> element(new CS_RequestPropagationStrategyImpl());
	*element =(*this);
	element->setThisCS_RequestPropagationStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_RequestPropagationStrategyImpl::eStaticClass() const
{
	return PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_RequestPropagationStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::string CS_RequestPropagationStrategyImpl::getName()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// a CS_RequestPropagationStrategy are always named "requestPropagation"
	return "requestPropagation";
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference> > CS_RequestPropagationStrategyImpl::select(std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> potentialTargets,std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<CS_RequestPropagationStrategy> CS_RequestPropagationStrategyImpl::getThisCS_RequestPropagationStrategyPtr() const
{
	return m_thisCS_RequestPropagationStrategyPtr.lock();
}
void CS_RequestPropagationStrategyImpl::setThisCS_RequestPropagationStrategyPtr(std::weak_ptr<CS_RequestPropagationStrategy> thisCS_RequestPropagationStrategyPtr)
{
	m_thisCS_RequestPropagationStrategyPtr = thisCS_RequestPropagationStrategyPtr;
	setThisSemanticStrategyPtr(thisCS_RequestPropagationStrategyPtr);
}
std::shared_ptr<ecore::EObject> CS_RequestPropagationStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_RequestPropagationStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticStrategyImpl::eGet(featureID, resolve, coreType);
}
bool CS_RequestPropagationStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticStrategyImpl::internalEIsSet(featureID);
}
bool CS_RequestPropagationStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Loci::SemanticStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CS_RequestPropagationStrategyImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 2801
		case StructuredClassifiersPackage::CS_REQUESTPROPAGATIONSTRATEGY_OPERATION_GETNAME:
		{
			result = eAny(this->getName());
			break;
		}
		
		// 2802
		case StructuredClassifiersPackage::CS_REQUESTPROPAGATIONSTRATEGY_OPERATION_SELECT_REFERENCE_SEMANTICVISITOR:
		{
			//Retrieve input parameter 'potentialTargets'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> incoming_param_potentialTargets;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_potentialTargets_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_potentialTargets = (*incoming_param_potentialTargets_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> >();
			result = eAny(this->select(incoming_param_potentialTargets,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Loci::SemanticStrategyImpl::eInvoke(operationID, arguments);
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
void CS_RequestPropagationStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_RequestPropagationStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Loci::SemanticStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void CS_RequestPropagationStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Loci::SemanticStrategyImpl::loadNode(nodeName, loadHandler);
}

void CS_RequestPropagationStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Loci::SemanticStrategyImpl::resolveReferences(featureID, references);
}

void CS_RequestPropagationStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void CS_RequestPropagationStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

