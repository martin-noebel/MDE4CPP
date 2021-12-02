
#include "ecore/impl/EObjectContainerImpl.hpp"

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

#include "abstractDataTypes/Union.hpp"


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"

#include "ecore/EObject.hpp"

//Factories an Package includes
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EObjectContainerImpl::EObjectContainerImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EObjectContainerImpl::~EObjectContainerImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EObjectContainer "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EObjectContainerImpl::EObjectContainerImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EObjectContainerImpl()
{
	m_eContainer = par_eContainer;
}

EObjectContainerImpl::EObjectContainerImpl(const EObjectContainerImpl & obj): EObjectContainerImpl()
{
	*this = obj;
}

EObjectContainerImpl& EObjectContainerImpl::operator=(const EObjectContainerImpl & obj)
{
	//call overloaded =Operator for each base class
	EObjectImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EObjectContainer 
	 * which is generated by the compiler (as EObjectContainer is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EObjectContainer::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EObjectContainer "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_container  = obj.getContainer();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EObjectContainerImpl::copy() const
{
	std::shared_ptr<EObjectContainerImpl> element(new EObjectContainerImpl());
	*element =(*this);
	element->setThisEObjectContainerPtr(element);
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
/* Getter & Setter for reference container */
std::shared_ptr<Bag<ecore::EObject>> EObjectContainerImpl::getContainer() const
{
	if(m_container == nullptr)
	{
		m_container.reset(new Bag<ecore::EObject>());
		
		
	}
    return m_container;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EObjectContainerImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EObjectContainerImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get ecoreFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EObjectContainerImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("container");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("container")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void EObjectContainerImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	EObjectImpl::loadNode(nodeName, loadHandler);
}

void EObjectContainerImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOBJECTCONTAINER_ATTRIBUTE_CONTAINER:
		{
			std::shared_ptr<Bag<ecore::EObject>> _container = getContainer();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ecore::EObject>  _r = std::dynamic_pointer_cast<ecore::EObject>(ref);
				if (_r != nullptr)
				{
					_container->push_back(_r);
				}
			}
			return;
		}
	}
	EObjectImpl::resolveReferences(featureID, references);
}

void EObjectContainerImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EObjectContainerImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
	// Add references
		saveHandler->addReferences<ecore::EObject>("container", this->getContainer());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<EClass> EObjectContainerImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEObjectContainer_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EObjectContainerImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOBJECTCONTAINER_ATTRIBUTE_CONTAINER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EObject>::iterator iter = getContainer()->begin();
			Bag<ecore::EObject>::iterator end = getContainer()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //403			
		}
	}
	return EObjectImpl::eGet(featureID, resolve, coreType);
}

bool EObjectContainerImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOBJECTCONTAINER_ATTRIBUTE_CONTAINER:
			return getContainer() != nullptr; //403
	}
	return EObjectImpl::internalEIsSet(featureID);
}

bool EObjectContainerImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOBJECTCONTAINER_ATTRIBUTE_CONTAINER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EObject>> containerList(new Bag<ecore::EObject>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				containerList->add(std::dynamic_pointer_cast<ecore::EObject>(*iter));
				iter++;
			}
			
			Bag<ecore::EObject>::iterator iterContainer = getContainer()->begin();
			Bag<ecore::EObject>::iterator endContainer = getContainer()->end();
			while (iterContainer != endContainer)
			{
				if (containerList->find(*iterContainer) == -1)
				{
					getContainer()->erase(*iterContainer);
				}
				iterContainer++;
			}
 
			iterContainer = containerList->begin();
			endContainer = containerList->end();
			while (iterContainer != endContainer)
			{
				if (getContainer()->find(*iterContainer) == -1)
				{
					getContainer()->add(*iterContainer);
				}
				iterContainer++;			
			}
			return true;
		}
	}

	return EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EObjectContainerImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = EObjectImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<ecore::EObjectContainer> EObjectContainerImpl::getThisEObjectContainerPtr() const
{
	return m_thisEObjectContainerPtr.lock();
}
void EObjectContainerImpl::setThisEObjectContainerPtr(std::weak_ptr<ecore::EObjectContainer> thisEObjectContainerPtr)
{
	m_thisEObjectContainerPtr = thisEObjectContainerPtr;
	setThisEObjectPtr(thisEObjectContainerPtr);
}
