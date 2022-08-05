
#include "PSCS/Semantics/Actions/impl/CS_ReadSelfActionActivationImpl.hpp"
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

#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Includes from codegen annotation
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Object.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_Reference.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "uml/OutputPin.hpp"
#include "uml/ReadSelfAction.hpp"
//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/ReadSelfAction.hpp"
#include "fUML/Semantics/Actions/ReadSelfActionActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_ReadSelfActionActivationImpl::CS_ReadSelfActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_ReadSelfActionActivationImpl::~CS_ReadSelfActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_ReadSelfActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CS_ReadSelfActionActivationImpl::CS_ReadSelfActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CS_ReadSelfActionActivationImpl()
{
	m_group = par_group;
}

CS_ReadSelfActionActivationImpl::CS_ReadSelfActionActivationImpl(const CS_ReadSelfActionActivationImpl & obj): CS_ReadSelfActionActivationImpl()
{
	*this = obj;
}

CS_ReadSelfActionActivationImpl& CS_ReadSelfActionActivationImpl::operator=(const CS_ReadSelfActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Actions::ReadSelfActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CS_ReadSelfActionActivation 
	 * which is generated by the compiler (as CS_ReadSelfActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CS_ReadSelfActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_ReadSelfActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_ReadSelfActionActivationImpl::copy() const
{
	std::shared_ptr<CS_ReadSelfActionActivationImpl> element(new CS_ReadSelfActionActivationImpl());
	*element =(*this);
	element->setThisCS_ReadSelfActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void CS_ReadSelfActionActivationImpl::doAction()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the context object of the activity execution containing this
	// action activation and place a reference to it on the result output
	// pin.
	// Extends fUML semantics in the sense that the reference placed on
	// the result pin is a CS_Reference, not a Reference

	//DEBUG_MESSAGE(std::cout << "[ReadSelfActionActivation] Start..." << std::endl;)
	
	std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Reference> context = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createCS_Reference();
	context->setReferent(this->getExecutionContext());
	if(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(context->getReferent()) != nullptr) {
		// i.e. alternatively, it can be an execution
		context->setCompositeReferent(std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_Object>(context->getReferent()));
	}
	
	//DEBUG_MESSAGE(std::cout << "[ReadSelfActionActivation] context object = " << context->getReferent()->toString() << std::endl;)
	
	std::shared_ptr<uml::OutputPin> resultPin = this->getReadSelfAction()->getResult();
	this->putToken(resultPin, context);
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CS_ReadSelfActionActivationImpl::getPinActivation() const
{
	if(m_pinActivation == nullptr)
	{
		/*Union*/
		m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::Semantics::Actions::PinActivation>()" << std::endl;
		#endif
		
		
	}
	return m_pinActivation;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CS_ReadSelfActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CS_ReadSelfActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_ReadSelfActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Actions::ReadSelfActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_ReadSelfActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Actions::ReadSelfActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CS_ReadSelfActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Actions::ReadSelfActionActivationImpl::resolveReferences(featureID, references);
}

void CS_ReadSelfActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Actions::ReadSelfActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CS_ReadSelfActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::Actions::ActionsPackage> package = PSCS::Semantics::Actions::ActionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CS_ReadSelfActionActivationImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_ReadSelfActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CS_ReadSelfActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::ReadSelfActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool CS_ReadSelfActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::ReadSelfActionActivationImpl::internalEIsSet(featureID);
}

bool CS_ReadSelfActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Actions::ReadSelfActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CS_ReadSelfActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// PSCS::Semantics::Actions::CS_ReadSelfActionActivation::doAction(): 1702243650
		case ActionsPackage::CS_READSELFACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Actions::ReadSelfActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivation> CS_ReadSelfActionActivationImpl::getThisCS_ReadSelfActionActivationPtr() const
{
	return m_thisCS_ReadSelfActionActivationPtr.lock();
}
void CS_ReadSelfActionActivationImpl::setThisCS_ReadSelfActionActivationPtr(std::weak_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivation> thisCS_ReadSelfActionActivationPtr)
{
	m_thisCS_ReadSelfActionActivationPtr = thisCS_ReadSelfActionActivationPtr;
	setThisReadSelfActionActivationPtr(thisCS_ReadSelfActionActivationPtr);
}


