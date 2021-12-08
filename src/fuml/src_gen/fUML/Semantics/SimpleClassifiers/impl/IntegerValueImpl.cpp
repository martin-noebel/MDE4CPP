
#include "fUML/Semantics/SimpleClassifiers/impl/IntegerValueImpl.hpp"

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

//Includes from codegen annotation
#include <cstdio>
#include "fUML/fUMLFactory.hpp"
#include "uml/Class.hpp"
#include "uml/LiteralInteger.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Type.hpp"
#include "uml/umlFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"

#include "uml/PrimitiveType.hpp"
#include "fUML/Semantics/SimpleClassifiers/PrimitiveValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
IntegerValueImpl::IntegerValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

IntegerValueImpl::~IntegerValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete IntegerValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


IntegerValueImpl::IntegerValueImpl(const IntegerValueImpl & obj): IntegerValueImpl()
{
	*this = obj;
}

IntegerValueImpl& IntegerValueImpl::operator=(const IntegerValueImpl & obj)
{
	//call overloaded =Operator for each base class
	PrimitiveValueImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of IntegerValue 
	 * which is generated by the compiler (as IntegerValue is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//IntegerValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy IntegerValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_value = obj.getValue();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> IntegerValueImpl::copy() const
{
	std::shared_ptr<IntegerValueImpl> element(new IntegerValueImpl());
	*element =(*this);
	element->setThisIntegerValuePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> IntegerValueImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new integer value with the same value as this integer value.

std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> newValue = fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
newValue->setType(this->getType()); //Duplicated from _copy()-method of super class in order to avoid having to call _copy()-method of super class and having to cast afterwards
newValue->setValue(this->getValue());
return newValue;
	//end of body
}

bool IntegerValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool isEqual = false;


    if(otherValue != nullptr && otherValue->eClass()->getClassifierID() == fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::INTEGERVALUE_CLASS)
    {
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> otherIntegerValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::IntegerValue>(otherValue);
        isEqual = (otherIntegerValue->getValue() == this->getValue());
    }

    return isEqual;
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> IntegerValueImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return a new integer value with no value.
return fUML::Semantics::SimpleClassifiers::SimpleClassifiersFactory::eInstance()->createIntegerValue();
	//end of body
}

std::shared_ptr<uml::ValueSpecification> IntegerValueImpl::specify()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<uml::LiteralInteger> literal = uml::umlFactory::eInstance()->createLiteralInteger_as_ownedMember_in_Namespace(std::shared_ptr<uml::Classifier>());

    literal->setType(this->getType());
    literal->setValue(this->getValue());

    return literal;
	//end of body
}

std::string IntegerValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    char buf [11];
    std::sprintf(buf, "%d", this->getValue());
    return std::string(buf);
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute value */
int IntegerValueImpl::getValue() const 
{
	return m_value;
}
void IntegerValueImpl::setValue(int _value)
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
std::shared_ptr<ecore::EObject> IntegerValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void IntegerValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void IntegerValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("value");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream(iter->second) >> value;
			this->setValue(value);
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

	PrimitiveValueImpl::loadAttributes(loadHandler, attr_list);
}

void IntegerValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PrimitiveValueImpl::loadNode(nodeName, loadHandler);
}

void IntegerValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	PrimitiveValueImpl::resolveReferences(featureID, references);
}

void IntegerValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PrimitiveValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void IntegerValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage> package = fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getIntegerValue_Attribute_value()) )
		{
			saveHandler->addAttribute("value", this->getValue());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> IntegerValueImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getIntegerValue_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any IntegerValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::INTEGERVALUE_ATTRIBUTE_VALUE:
			return eAny(getValue(),0,true); //641
	}
	return PrimitiveValueImpl::eGet(featureID, resolve, coreType);
}

bool IntegerValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::INTEGERVALUE_ATTRIBUTE_VALUE:
			return getValue() != 0; //641
	}
	return PrimitiveValueImpl::internalEIsSet(featureID);
}

bool IntegerValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::INTEGERVALUE_ATTRIBUTE_VALUE:
		{
			// CAST Any to int
			int _value = newValue->get<int>();
			setValue(_value); //641
			return true;
		}
	}

	return PrimitiveValueImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any IntegerValueImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// fUML::Semantics::SimpleClassifiers::IntegerValue::_copy() : fUML::Semantics::Values::Value: 409567895
		case SimpleClassifiersPackage::INTEGERVALUE_OPERATION__COPY:
		{
			result = eAny(this->_copy(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS,false);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::IntegerValue::equals(fUML::Semantics::Values::Value) : bool: 1332371302
		case SimpleClassifiersPackage::INTEGERVALUE_OPERATION_EQUALS_VALUE:
		{
			//Retrieve input parameter 'otherValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_otherValue;
			std::list<Any>::const_iterator incoming_param_otherValue_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_otherValue = (*incoming_param_otherValue_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->equals(incoming_param_otherValue),0,false);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::IntegerValue::new_() : fUML::Semantics::Values::Value: 1044297728
		case SimpleClassifiersPackage::INTEGERVALUE_OPERATION_NEW_:
		{
			result = eAny(this->new_(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS,false);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::IntegerValue::specify() : uml::ValueSpecification: 1191658488
		case SimpleClassifiersPackage::INTEGERVALUE_OPERATION_SPECIFY:
		{
			result = eAny(this->specify(), uml::umlPackage::VALUESPECIFICATION_CLASS,false);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::IntegerValue::toString() : std::string: 1852462258
		case SimpleClassifiersPackage::INTEGERVALUE_OPERATION_TOSTRING:
		{
			result = eAny(this->toString(),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = PrimitiveValueImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> IntegerValueImpl::getThisIntegerValuePtr() const
{
	return m_thisIntegerValuePtr.lock();
}
void IntegerValueImpl::setThisIntegerValuePtr(std::weak_ptr<fUML::Semantics::SimpleClassifiers::IntegerValue> thisIntegerValuePtr)
{
	m_thisIntegerValuePtr = thisIntegerValuePtr;
	setThisPrimitiveValuePtr(thisIntegerValuePtr);
}


