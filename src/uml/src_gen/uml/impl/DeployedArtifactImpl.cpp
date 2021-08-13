#include "uml/impl/DeployedArtifactImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DeployedArtifactImpl::DeployedArtifactImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DeployedArtifactImpl::~DeployedArtifactImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DeployedArtifact "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DeployedArtifactImpl::DeployedArtifactImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DeployedArtifactImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DeployedArtifactImpl::DeployedArtifactImpl(std::weak_ptr<uml::Element> par_owner)
:DeployedArtifactImpl()
{
	m_owner = par_owner;
}

DeployedArtifactImpl::DeployedArtifactImpl(const DeployedArtifactImpl & obj): DeployedArtifactImpl()
{
	*this = obj;
}

DeployedArtifactImpl& DeployedArtifactImpl::operator=(const DeployedArtifactImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	DeployedArtifact::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DeployedArtifact "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DeployedArtifactImpl::copy() const
{
	std::shared_ptr<DeployedArtifactImpl> element(new DeployedArtifactImpl());
	*element =(*this);
	element->setThisDeployedArtifactPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DeployedArtifactImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDeployedArtifact_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> DeployedArtifactImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> DeployedArtifactImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<DeployedArtifact> DeployedArtifactImpl::getThisDeployedArtifactPtr() const
{
	return m_thisDeployedArtifactPtr.lock();
}
void DeployedArtifactImpl::setThisDeployedArtifactPtr(std::weak_ptr<DeployedArtifact> thisDeployedArtifactPtr)
{
	m_thisDeployedArtifactPtr = thisDeployedArtifactPtr;
	setThisNamedElementPtr(thisDeployedArtifactPtr);
}
std::shared_ptr<ecore::EObject> DeployedArtifactImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any DeployedArtifactImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool DeployedArtifactImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool DeployedArtifactImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any DeployedArtifactImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
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
void DeployedArtifactImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void DeployedArtifactImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void DeployedArtifactImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void DeployedArtifactImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	NamedElementImpl::resolveReferences(featureID, references);
}

void DeployedArtifactImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void DeployedArtifactImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

