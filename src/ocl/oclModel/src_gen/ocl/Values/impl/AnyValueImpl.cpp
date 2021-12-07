
#include "ocl/Values/impl/AnyValueImpl.hpp"

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

#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Values;

//*********************************
// Constructor / Destructor
//*********************************
AnyValueImpl::AnyValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AnyValueImpl::~AnyValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AnyValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


AnyValueImpl::AnyValueImpl(const AnyValueImpl & obj): AnyValueImpl()
{
	*this = obj;
}

AnyValueImpl& AnyValueImpl::operator=(const AnyValueImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::ValueImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of AnyValue 
	 * which is generated by the compiler (as AnyValue is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//AnyValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AnyValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> AnyValueImpl::copy() const
{
	std::shared_ptr<AnyValueImpl> element(new AnyValueImpl());
	*element =(*this);
	element->setThisAnyValuePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::string AnyValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "AnyValues";
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute value */
Any AnyValueImpl::getValue() const 
{
	return m_value;
}
void AnyValueImpl::setValue(Any _value)
{
	m_value = _value;
	
}

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> AnyValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void AnyValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AnyValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// TODO this attribute has a non handle type
			std::cout << "| ERROR    | " << __PRETTY_FUNCTION__ << " handle type of 'value'" << " org.eclipse.emf.ecore.impl.EDataTypeImpl@3a2b2322 (name: EJavaObject) (instanceClassName: java.lang.Object) (serializable: true)" << std::endl; 
			Any value; 			this->setValue(value);
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

	fUML::Semantics::Values::ValueImpl::loadAttributes(loadHandler, attr_list);
}

void AnyValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::ValueImpl::loadNode(nodeName, loadHandler);
}

void AnyValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Values::ValueImpl::resolveReferences(featureID, references);
}

void AnyValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void AnyValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Values::ValuesPackage> package = ocl::Values::ValuesPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getAnyValue_Attribute_value()) )
		{
			//Cannot save attributes of type Any (EJavaObject)
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> AnyValueImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getAnyValue_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any AnyValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::ANYVALUE_ATTRIBUTE_VALUE:
				return eAny(getValue(),0,true); //20
	}
	return fUML::Semantics::Values::ValueImpl::eGet(featureID, resolve, coreType);
}

bool AnyValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::ANYVALUE_ATTRIBUTE_VALUE:
			return getValue() != nullptr; //20
	}
	return fUML::Semantics::Values::ValueImpl::internalEIsSet(featureID);
}

bool AnyValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Values::ValuesPackage::ANYVALUE_ATTRIBUTE_VALUE:
		{
			// BOOST CAST
			Any _value = newValue->get<Any>();
			setValue(_value); //20
			return true;
		}
	}

	return fUML::Semantics::Values::ValueImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any AnyValueImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 944564240
		case ValuesPackage::ANYVALUE_OPERATION_TOSTRING:
		{
					result = eAny(this->toString(),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::ValueImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Values::AnyValue> AnyValueImpl::getThisAnyValuePtr() const
{
	return m_thisAnyValuePtr.lock();
}
void AnyValueImpl::setThisAnyValuePtr(std::weak_ptr<ocl::Values::AnyValue> thisAnyValuePtr)
{
	m_thisAnyValuePtr = thisAnyValuePtr;
	setThisValuePtr(thisAnyValuePtr);
}


