
#include "fUML/Semantics/Actions/impl/AcceptEventActionEventAccepterImpl.hpp"

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
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Actions/AcceptEventActionActivation.hpp"
#include "fUML/Semantics/CommonBehavior/EventAccepter.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
AcceptEventActionEventAccepterImpl::AcceptEventActionEventAccepterImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AcceptEventActionEventAccepterImpl::~AcceptEventActionEventAccepterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AcceptEventActionEventAccepter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


AcceptEventActionEventAccepterImpl::AcceptEventActionEventAccepterImpl(const AcceptEventActionEventAccepterImpl & obj): AcceptEventActionEventAccepterImpl()
{
	*this = obj;
}

AcceptEventActionEventAccepterImpl& AcceptEventActionEventAccepterImpl::operator=(const AcceptEventActionEventAccepterImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::CommonBehavior::EventAccepterImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of AcceptEventActionEventAccepter 
	 * which is generated by the compiler (as AcceptEventActionEventAccepter is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//AcceptEventActionEventAccepter::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AcceptEventActionEventAccepter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_actionActivation  = obj.getActionActivation();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> AcceptEventActionEventAccepterImpl::copy() const
{
	std::shared_ptr<AcceptEventActionEventAccepterImpl> element(new AcceptEventActionEventAccepterImpl());
	*element =(*this);
	element->setThisAcceptEventActionEventAccepterPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference actionActivation */
std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> AcceptEventActionEventAccepterImpl::getActionActivation() const
{
    return m_actionActivation;
}
void AcceptEventActionEventAccepterImpl::setActionActivation(std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> _actionActivation)
{
    m_actionActivation = _actionActivation;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> AcceptEventActionEventAccepterImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void AcceptEventActionEventAccepterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AcceptEventActionEventAccepterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("actionActivation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("actionActivation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::CommonBehavior::EventAccepterImpl::loadAttributes(loadHandler, attr_list);
}

void AcceptEventActionEventAccepterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::CommonBehavior::EventAccepterImpl::loadNode(nodeName, loadHandler);
}

void AcceptEventActionEventAccepterImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ATTRIBUTE_ACTIONACTIVATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> _actionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::AcceptEventActionActivation>( references.front() );
				setActionActivation(_actionActivation);
			}
			
			return;
		}
	}
	fUML::Semantics::CommonBehavior::EventAccepterImpl::resolveReferences(featureID, references);
}

void AcceptEventActionEventAccepterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::EventAccepterImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void AcceptEventActionEventAccepterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getActionActivation(), "actionActivation", getActionActivation()->eClass() != fUML::Semantics::Actions::ActionsPackage::eInstance()->getAcceptEventActionActivation_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> AcceptEventActionEventAccepterImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getAcceptEventActionEventAccepter_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any AcceptEventActionEventAccepterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ATTRIBUTE_ACTIONACTIVATION:
			return eAny(getActionActivation(),fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_CLASS,false); //40
	}
	return fUML::Semantics::CommonBehavior::EventAccepterImpl::eGet(featureID, resolve, coreType);
}

bool AcceptEventActionEventAccepterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ATTRIBUTE_ACTIONACTIVATION:
			return getActionActivation() != nullptr; //40
	}
	return fUML::Semantics::CommonBehavior::EventAccepterImpl::internalEIsSet(featureID);
}

bool AcceptEventActionEventAccepterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_ATTRIBUTE_ACTIONACTIVATION:
		{
			// CAST Any to fUML::Semantics::Actions::AcceptEventActionActivation
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> _actionActivation = std::dynamic_pointer_cast<fUML::Semantics::Actions::AcceptEventActionActivation>(_temp);
			setActionActivation(_actionActivation); //40
			return true;
		}
	}

	return fUML::Semantics::CommonBehavior::EventAccepterImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any AcceptEventActionEventAccepterImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = fUML::Semantics::CommonBehavior::EventAccepterImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> AcceptEventActionEventAccepterImpl::getThisAcceptEventActionEventAccepterPtr() const
{
	return m_thisAcceptEventActionEventAccepterPtr.lock();
}
void AcceptEventActionEventAccepterImpl::setThisAcceptEventActionEventAccepterPtr(std::weak_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> thisAcceptEventActionEventAccepterPtr)
{
	m_thisAcceptEventActionEventAccepterPtr = thisAcceptEventActionEventAccepterPtr;
	setThisEventAccepterPtr(thisAcceptEventActionEventAccepterPtr);
}


