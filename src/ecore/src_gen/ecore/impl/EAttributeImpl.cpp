
#include "ecore/impl/EAttributeImpl.hpp"

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
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EDataType.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EStructuralFeature.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EAttributeImpl::EAttributeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EAttributeImpl::~EAttributeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EAttribute "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EAttributeImpl::EAttributeImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EAttributeImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EAttributeImpl::EAttributeImpl(std::weak_ptr<ecore::EClass> par_eContainingClass)
:EAttributeImpl()
{
	m_eContainingClass = par_eContainingClass;
}

EAttributeImpl::EAttributeImpl(const EAttributeImpl & obj): EAttributeImpl()
{
	*this = obj;
}

EAttributeImpl& EAttributeImpl::operator=(const EAttributeImpl & obj)
{
	//call overloaded =Operator for each base class
	EStructuralFeatureImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EAttribute 
	 * which is generated by the compiler (as EAttribute is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EAttribute::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EAttribute "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_iD = obj.isID();

	//copy references with no containment (soft copy)
	m_eAttributeType  = obj.getEAttributeType();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> EAttributeImpl::copy() const
{
	std::shared_ptr<EAttributeImpl> element(new EAttributeImpl());
	*element =(*this);
	element->setThisEAttributePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute iD */
bool EAttributeImpl::isID() const 
{
	return m_iD;
}
void EAttributeImpl::setID(bool _iD)
{
	m_iD = _iD;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eAttributeType */
std::shared_ptr<ecore::EDataType> EAttributeImpl::getEAttributeType() const
{
    return m_eAttributeType;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EAttributeImpl::getEContentUnion() const
{
	if(m_eContentUnion == nullptr)
	{
		/*Union*/
		m_eContentUnion.reset(new Union<ecore::EObject>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_eContentUnion - Union<ecore::EObject>()" << std::endl;
		#endif
		
		
	}
	return m_eContentUnion;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EAttributeImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_eContainingClass.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EAttributeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EAttributeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("iD");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setID(value);
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

	EStructuralFeatureImpl::loadAttributes(loadHandler, attr_list);
}

void EAttributeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	EStructuralFeatureImpl::loadNode(nodeName, loadHandler);
}

void EAttributeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	EStructuralFeatureImpl::resolveReferences(featureID, references);
}

void EAttributeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EStructuralFeatureImpl::saveContent(saveHandler);
	
	ETypedElementImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EAttributeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getEAttribute_Attribute_iD()) )
		{
			saveHandler->addAttribute("iD", this->isID());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<EClass> EAttributeImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEAttribute_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EAttributeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EATTRIBUTE_ATTRIBUTE_EATTRIBUTETYPE:
			return eAny(getEAttributeType(),ecore::ecorePackage::EDATATYPE_CLASS,false); //323
		case ecore::ecorePackage::EATTRIBUTE_ATTRIBUTE_ID:
			return eAny(isID(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //322
	}
	return EStructuralFeatureImpl::eGet(featureID, resolve, coreType);
}

bool EAttributeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EATTRIBUTE_ATTRIBUTE_EATTRIBUTETYPE:
			return getEAttributeType() != nullptr; //323
		case ecore::ecorePackage::EATTRIBUTE_ATTRIBUTE_ID:
			return isID() != false; //322
	}
	return EStructuralFeatureImpl::internalEIsSet(featureID);
}

bool EAttributeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EATTRIBUTE_ATTRIBUTE_ID:
		{
			// CAST Any to bool
			bool _iD = newValue->get<bool>();
			setID(_iD); //322
			return true;
		}
	}

	return EStructuralFeatureImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EAttributeImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = EStructuralFeatureImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::EAttribute> EAttributeImpl::getThisEAttributePtr() const
{
	return m_thisEAttributePtr.lock();
}
void EAttributeImpl::setThisEAttributePtr(std::weak_ptr<ecore::EAttribute> thisEAttributePtr)
{
	m_thisEAttributePtr = thisEAttributePtr;
	setThisEStructuralFeaturePtr(thisEAttributePtr);
}


