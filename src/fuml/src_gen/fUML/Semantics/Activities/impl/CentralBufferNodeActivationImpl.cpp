#include "fUML/Semantics/Activities/impl/CentralBufferNodeActivationImpl.hpp"

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
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"


#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/ObjectNodeActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
CentralBufferNodeActivationImpl::CentralBufferNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CentralBufferNodeActivationImpl::~CentralBufferNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CentralBufferNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CentralBufferNodeActivationImpl::CentralBufferNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CentralBufferNodeActivationImpl()
{
	m_group = par_group;
}

CentralBufferNodeActivationImpl::CentralBufferNodeActivationImpl(const CentralBufferNodeActivationImpl & obj): CentralBufferNodeActivationImpl()
{
	*this = obj;
}

CentralBufferNodeActivationImpl& CentralBufferNodeActivationImpl::operator=(const CentralBufferNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ObjectNodeActivationImpl::operator=(obj);
	CentralBufferNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CentralBufferNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CentralBufferNodeActivationImpl::copy() const
{
	std::shared_ptr<CentralBufferNodeActivationImpl> element(new CentralBufferNodeActivationImpl());
	*element =(*this);
	element->setThisCentralBufferNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CentralBufferNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getCentralBufferNodeActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void CentralBufferNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			//DEBUG_MESSAGE(std::cout << "[fire] " << this->getNode()->getClass()->getName() << " " << this->getNode()->getName();)

		DEBUG_MESSAGE(std::cout << "Central Buffer Node Activation" << std::endl;)

		this->addTokens(incomingTokens);
		this->sendUnofferedTokens();
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<CentralBufferNodeActivation> CentralBufferNodeActivationImpl::getThisCentralBufferNodeActivationPtr() const
{
	return m_thisCentralBufferNodeActivationPtr.lock();
}
void CentralBufferNodeActivationImpl::setThisCentralBufferNodeActivationPtr(std::weak_ptr<CentralBufferNodeActivation> thisCentralBufferNodeActivationPtr)
{
	m_thisCentralBufferNodeActivationPtr = thisCentralBufferNodeActivationPtr;
	setThisObjectNodeActivationPtr(thisCentralBufferNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> CentralBufferNodeActivationImpl::eContainer() const
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
Any CentralBufferNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ObjectNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool CentralBufferNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ObjectNodeActivationImpl::internalEIsSet(featureID);
}
bool CentralBufferNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ObjectNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CentralBufferNodeActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 2045
		case ActivitiesPackage::CENTRALBUFFERNODEACTIVATION_OPERATION_FIRE_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_incomingTokens = (*incoming_param_incomingTokens_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> >();
			this->fire(incoming_param_incomingTokens);
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
void CentralBufferNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CentralBufferNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ObjectNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CentralBufferNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ObjectNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void CentralBufferNodeActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ObjectNodeActivationImpl::resolveReferences(featureID, references);
}

void CentralBufferNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ObjectNodeActivationImpl::saveContent(saveHandler);
	
	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void CentralBufferNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

