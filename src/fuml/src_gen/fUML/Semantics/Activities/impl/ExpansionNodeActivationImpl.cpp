#include "fUML/Semantics/Activities/impl/ExpansionNodeActivationImpl.hpp"

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
#include "uml/ExpansionNode.hpp"
#include "uml/ExpansionRegion.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ExpansionRegionActivation.hpp"
#include "fUML/Semantics/Activities/ObjectNodeActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionNodeActivationImpl::ExpansionNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExpansionNodeActivationImpl::~ExpansionNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExpansionNodeActivationImpl::ExpansionNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ExpansionNodeActivationImpl()
{
	m_group = par_group;
}

ExpansionNodeActivationImpl::ExpansionNodeActivationImpl(const ExpansionNodeActivationImpl & obj): ExpansionNodeActivationImpl()
{
	*this = obj;
}

ExpansionNodeActivationImpl& ExpansionNodeActivationImpl::operator=(const ExpansionNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ObjectNodeActivationImpl::operator=(obj);
	ExpansionNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExpansionNodeActivationImpl::copy() const
{
	std::shared_ptr<ExpansionNodeActivationImpl> element(new ExpansionNodeActivationImpl());
	*element =(*this);
	element->setThisExpansionNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExpansionNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getExpansionNodeActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ExpansionNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	addTokens(incomingTokens);
	//end of body
}

std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> ExpansionNodeActivationImpl::getExpansionRegionActivation()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::ExpansionNode> node = std::dynamic_pointer_cast<uml::ExpansionNode>(m_node);
	std::shared_ptr<uml::ExpansionRegion> region = node->getRegionAsInput();
	if (region == nullptr)
	{
		region = node->getRegionAsOutput();
	}

	auto group = m_group.lock();
	if (group == nullptr)
	{
        DEBUG_MESSAGE(std::cout << __PRETTY_FUNCTION__ << ": unknown group" << std::endl;)
		throw "unknown group";
	}

	return std::dynamic_pointer_cast<fUML::Semantics::Activities::ExpansionRegionActivation>(group->getNodeActivation(region));
	//end of body
}

bool ExpansionNodeActivationImpl::isReady()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return false;
	//end of body
}

void ExpansionNodeActivationImpl::receiveOffer()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	getExpansionRegionActivation()->receiveOffer();
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<ExpansionNodeActivation> ExpansionNodeActivationImpl::getThisExpansionNodeActivationPtr() const
{
	return m_thisExpansionNodeActivationPtr.lock();
}
void ExpansionNodeActivationImpl::setThisExpansionNodeActivationPtr(std::weak_ptr<ExpansionNodeActivation> thisExpansionNodeActivationPtr)
{
	m_thisExpansionNodeActivationPtr = thisExpansionNodeActivationPtr;
	setThisObjectNodeActivationPtr(thisExpansionNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> ExpansionNodeActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ExpansionNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ObjectNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool ExpansionNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ObjectNodeActivationImpl::internalEIsSet(featureID);
}
bool ExpansionNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ObjectNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ExpansionNodeActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 5046
		case ActivitiesPackage::EXPANSIONNODEACTIVATION_OPERATION_FIRE_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_incomingTokens = (*incoming_param_incomingTokens_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> >();
			this->fire(incoming_param_incomingTokens);
			break;
		}
		
		// 5045
		case ActivitiesPackage::EXPANSIONNODEACTIVATION_OPERATION_GETEXPANSIONREGIONACTIVATION:
		{
			result = eAny(this->getExpansionRegionActivation());
			break;
		}
		
		// 5048
		case ActivitiesPackage::EXPANSIONNODEACTIVATION_OPERATION_ISREADY:
		{
			result = eAny(this->isReady());
			break;
		}
		
		// 5047
		case ActivitiesPackage::EXPANSIONNODEACTIVATION_OPERATION_RECEIVEOFFER:
		{
			this->receiveOffer();
			break;
		}

		default:
		{
			// call superTypes
			result = ObjectNodeActivationImpl::eInvoke(operationID, arguments);
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
void ExpansionNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ExpansionNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ObjectNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ExpansionNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ObjectNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void ExpansionNodeActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ObjectNodeActivationImpl::resolveReferences(featureID, references);
}

void ExpansionNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ObjectNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ExpansionNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

