
#include "ocl/Values/impl/ElementImpl.hpp"

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


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Values/ValuesFactory.hpp"

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Values;

//*********************************
// Constructor / Destructor
//*********************************
ElementImpl::ElementImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ElementImpl::~ElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Element "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ElementImpl::ElementImpl(const ElementImpl & obj): ElementImpl()
{
	*this = obj;
}

ElementImpl& ElementImpl::operator=(const ElementImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Element 
	 * which is generated by the compiler (as Element is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Element::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Element "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_indexNr = obj.getIndexNr();

	//copy references with no containment (soft copy)
	m_value  = obj.getValue();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ElementImpl::copy() const
{
	std::shared_ptr<ElementImpl> element(new ElementImpl());
	*element =(*this);
	element->setThisElementPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute indexNr */
int ElementImpl::getIndexNr() const 
{
	return m_indexNr;
}
void ElementImpl::setIndexNr(int _indexNr)
{
	m_indexNr = _indexNr;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference value */
std::shared_ptr<fUML::Semantics::Values::Value> ElementImpl::getValue() const
{
    return m_value;
}
void ElementImpl::setValue(std::shared_ptr<fUML::Semantics::Values::Value> _value)
{
    m_value = _value;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ElementImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get oclFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("indexNr");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream(iter->second) >> value;
			this->setIndexNr(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("value")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void ElementImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::ELEMENT_ATTRIBUTE_VALUE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Values::Value> _value = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>( references.front() );
				setValue(_value);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void ElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Values::ValuesPackage> package = ocl::Values::ValuesPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getElement_Attribute_indexNr()) )
		{
			saveHandler->addAttribute("indexNr", this->getIndexNr());
		}
	// Add references
		saveHandler->addReference(this->getValue(), "value", getValue()->eClass() != fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ElementImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getElement_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::ELEMENT_ATTRIBUTE_INDEXNR:
			return eAny(getIndexNr(),0,true); //230
		case ocl::Values::ValuesPackage::ELEMENT_ATTRIBUTE_VALUE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getValue();
			return eAny(returnValue,returnValue->getMetaElementID(),false); //231
		}
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool ElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::ELEMENT_ATTRIBUTE_INDEXNR:
			return getIndexNr() != 0; //230
		case ocl::Values::ValuesPackage::ELEMENT_ATTRIBUTE_VALUE:
			return getValue() != nullptr; //231
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool ElementImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::ELEMENT_ATTRIBUTE_INDEXNR:
		{
			// CAST Any to int
			int _indexNr = newValue->get<int>();
			setIndexNr(_indexNr); //230
			return true;
		}
		case ocl::Values::ValuesPackage::ELEMENT_ATTRIBUTE_VALUE:
		{
			// CAST Any to fUML::Semantics::Values::Value
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Values::Value> _value = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(_temp);
			setValue(_value); //231
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ElementImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Values::Element> ElementImpl::getThisElementPtr() const
{
	return m_thisElementPtr.lock();
}
void ElementImpl::setThisElementPtr(std::weak_ptr<ocl::Values::Element> thisElementPtr)
{
	m_thisElementPtr = thisElementPtr;
}


