#include "uml/impl/ObjectImpl.hpp"

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

#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Argument.hpp"
#include "uml/Object.hpp"
#include "uml/Operation.hpp"
#include "uml/Property.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ObjectImpl::ObjectImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ObjectImpl::~ObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Object "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ObjectImpl::ObjectImpl(const ObjectImpl & obj): ObjectImpl()
{
	*this = obj;
}

ObjectImpl& ObjectImpl::operator=(const ObjectImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	Object::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Object "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ObjectImpl::copy() const
{
	std::shared_ptr<ObjectImpl> element(new ObjectImpl());
	*element =(*this);
	element->setThisObjectPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ObjectImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getObject_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
Any ObjectImpl::get(std::shared_ptr<uml::Property> property) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Object> > ObjectImpl::invoke(std::shared_ptr<uml::Operation> op,std::shared_ptr<Bag<uml::Argument>> arguments)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ObjectImpl::set(std::shared_ptr<uml::Property> property,Any value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ObjectImpl::unset(std::shared_ptr<uml::Property> property)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<Object> ObjectImpl::getThisObjectPtr() const
{
	return m_thisObjectPtr.lock();
}
void ObjectImpl::setThisObjectPtr(std::weak_ptr<Object> thisObjectPtr)
{
	m_thisObjectPtr = thisObjectPtr;
}
std::shared_ptr<ecore::EObject> ObjectImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}
bool ObjectImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}
bool ObjectImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ObjectImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 15800
		case umlPackage::OBJECT_OPERATION_GET_PROPERTY:
		{
			//Retrieve input parameter 'property'
			//parameter 0
			std::shared_ptr<uml::Property> incoming_param_property;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_property_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_property = (*incoming_param_property_arguments_citer)->get()->get<std::shared_ptr<uml::Property> >();
			result = eAny(this->get(incoming_param_property));
			break;
		}
		
		// 15803
		case umlPackage::OBJECT_OPERATION_INVOKE_OPERATION_ARGUMENT:
		{
			//Retrieve input parameter 'op'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_op;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_op_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_op = (*incoming_param_op_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			//Retrieve input parameter 'arguments'
			//parameter 1
			std::shared_ptr<Bag<uml::Argument>> incoming_param_arguments;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_arguments_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_arguments = (*incoming_param_arguments_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::Argument>> >();
			result = eAny(this->invoke(incoming_param_op,incoming_param_arguments));
			break;
		}
		
		// 15801
		case umlPackage::OBJECT_OPERATION_SET_PROPERTY_EJAVAOBJECT:
		{
			//Retrieve input parameter 'property'
			//parameter 0
			std::shared_ptr<uml::Property> incoming_param_property;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_property_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_property = (*incoming_param_property_arguments_citer)->get()->get<std::shared_ptr<uml::Property> >();
			//Retrieve input parameter 'value'
			//parameter 1
			Any incoming_param_value;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get()->get<Any >();
			this->set(incoming_param_property,incoming_param_value);
			break;
		}
		
		// 15802
		case umlPackage::OBJECT_OPERATION_UNSET_PROPERTY:
		{
			//Retrieve input parameter 'property'
			//parameter 0
			std::shared_ptr<uml::Property> incoming_param_property;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_property_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_property = (*incoming_param_property_arguments_citer)->get()->get<std::shared_ptr<uml::Property> >();
			this->unset(incoming_param_property);
			break;
		}

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

//*********************************
// Persistence Functions
//*********************************
void ObjectImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
}

void ObjectImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void ObjectImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void ObjectImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

