
#include "fUML/Semantics/Actions/impl/LoopNodeActivationImpl.hpp"

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
#include <stdexcept>


#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Actions/StructuredActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Actions/Values.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
LoopNodeActivationImpl::LoopNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LoopNodeActivationImpl::~LoopNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LoopNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LoopNodeActivationImpl::LoopNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:LoopNodeActivationImpl()
{
	m_group = par_group;
}

LoopNodeActivationImpl::LoopNodeActivationImpl(const LoopNodeActivationImpl & obj): LoopNodeActivationImpl()
{
	*this = obj;
}

LoopNodeActivationImpl& LoopNodeActivationImpl::operator=(const LoopNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuredActivityNodeActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LoopNodeActivation 
	 * which is generated by the compiler (as LoopNodeActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LoopNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LoopNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'bodyOutputLists'
	std::shared_ptr<Bag<fUML::Semantics::Actions::Values>> bodyOutputListsList = obj.getBodyOutputLists();
	if(bodyOutputListsList)
	{
		m_bodyOutputLists.reset(new Bag<fUML::Semantics::Actions::Values>());
		
		
		for(const std::shared_ptr<fUML::Semantics::Actions::Values> bodyOutputListsindexElem: *bodyOutputListsList) 
		{
			std::shared_ptr<fUML::Semantics::Actions::Values> temp = std::dynamic_pointer_cast<fUML::Semantics::Actions::Values>((bodyOutputListsindexElem)->copy());
			m_bodyOutputLists->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr bodyOutputLists."<< std::endl;)
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> LoopNodeActivationImpl::copy() const
{
	std::shared_ptr<LoopNodeActivationImpl> element(new LoopNodeActivationImpl());
	*element =(*this);
	element->setThisLoopNodeActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::ActivityNode> LoopNodeActivationImpl::makeLoopVariableList()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

void LoopNodeActivationImpl::runBody()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

void LoopNodeActivationImpl::runLoopVariables()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool LoopNodeActivationImpl::runTest()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference bodyOutputLists */
std::shared_ptr<Bag<fUML::Semantics::Actions::Values>> LoopNodeActivationImpl::getBodyOutputLists() const
{
	if(m_bodyOutputLists == nullptr)
	{
		m_bodyOutputLists.reset(new Bag<fUML::Semantics::Actions::Values>());
		
		
	}
    return m_bodyOutputLists;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> LoopNodeActivationImpl::getPinActivation() const
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
std::shared_ptr<ecore::EObject> LoopNodeActivationImpl::eContainer() const
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
void LoopNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LoopNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	StructuredActivityNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void LoopNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("bodyOutputLists") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Values";
			}
			loadHandler->handleChildContainer<fUML::Semantics::Actions::Values>(this->getBodyOutputLists());  

			return; 
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}
	//load BasePackage Nodes
	StructuredActivityNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void LoopNodeActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	StructuredActivityNodeActivationImpl::resolveReferences(featureID, references);
}

void LoopNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuredActivityNodeActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void LoopNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'bodyOutputLists'

		saveHandler->addReferences<fUML::Semantics::Actions::Values>("bodyOutputLists", this->getBodyOutputLists());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> LoopNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getLoopNodeActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any LoopNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::LOOPNODEACTIVATION_ATTRIBUTE_BODYOUTPUTLISTS:
		{
			return eAnyBag(getBodyOutputLists(),fUML::Semantics::Actions::ActionsPackage::VALUES_CLASS); //7812
		}
	}
	return StructuredActivityNodeActivationImpl::eGet(featureID, resolve, coreType);
}

bool LoopNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::LOOPNODEACTIVATION_ATTRIBUTE_BODYOUTPUTLISTS:
			return getBodyOutputLists() != nullptr; //7812
	}
	return StructuredActivityNodeActivationImpl::internalEIsSet(featureID);
}

bool LoopNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::LOOPNODEACTIVATION_ATTRIBUTE_BODYOUTPUTLISTS:
		{
			// CAST Any to Bag<fUML::Semantics::Actions::Values>
			if((newValue->isContainer()) && (fUML::Semantics::Actions::ActionsPackage::VALUES_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<fUML::Semantics::Actions::Values>> bodyOutputListsList= newValue->get<std::shared_ptr<Bag<fUML::Semantics::Actions::Values>>>();
					std::shared_ptr<Bag<fUML::Semantics::Actions::Values>> _bodyOutputLists=getBodyOutputLists();
					for(const std::shared_ptr<fUML::Semantics::Actions::Values> indexBodyOutputLists: *_bodyOutputLists)
					{
						if (bodyOutputListsList->find(indexBodyOutputLists) == -1)
						{
							_bodyOutputLists->erase(indexBodyOutputLists);
						}
					}

					for(const std::shared_ptr<fUML::Semantics::Actions::Values> indexBodyOutputLists: *bodyOutputListsList)
					{
						if (_bodyOutputLists->find(indexBodyOutputLists) == -1)
						{
							_bodyOutputLists->add(indexBodyOutputLists);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
	}

	return StructuredActivityNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any LoopNodeActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// fUML::Semantics::Actions::LoopNodeActivation::makeLoopVariableList() : uml::ActivityNode: 1597416642
		case ActionsPackage::LOOPNODEACTIVATION_OPERATION_MAKELOOPVARIABLELIST:
		{
			result = eAny(this->makeLoopVariableList(), uml::umlPackage::ACTIVITYNODE_CLASS,false);
			break;
		}
		// fUML::Semantics::Actions::LoopNodeActivation::runBody(): 563107466
		case ActionsPackage::LOOPNODEACTIVATION_OPERATION_RUNBODY:
		{
			this->runBody();
		}
		// fUML::Semantics::Actions::LoopNodeActivation::runLoopVariables(): 1175069894
		case ActionsPackage::LOOPNODEACTIVATION_OPERATION_RUNLOOPVARIABLES:
		{
			this->runLoopVariables();
		}
		// fUML::Semantics::Actions::LoopNodeActivation::runTest() : bool: 1241885508
		case ActionsPackage::LOOPNODEACTIVATION_OPERATION_RUNTEST:
		{
			result = eAny(this->runTest(),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = StructuredActivityNodeActivationImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> LoopNodeActivationImpl::getThisLoopNodeActivationPtr() const
{
	return m_thisLoopNodeActivationPtr.lock();
}
void LoopNodeActivationImpl::setThisLoopNodeActivationPtr(std::weak_ptr<fUML::Semantics::Actions::LoopNodeActivation> thisLoopNodeActivationPtr)
{
	m_thisLoopNodeActivationPtr = thisLoopNodeActivationPtr;
	setThisStructuredActivityNodeActivationPtr(thisLoopNodeActivationPtr);
}


