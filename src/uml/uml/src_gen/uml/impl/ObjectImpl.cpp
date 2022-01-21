
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
#include <stdexcept>


#include "abstractDataTypes/Bag.hpp"


#include "abstractDataTypes/Any.hpp"
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
#include "uml/Argument.hpp"
#include "uml/Object.hpp"
#include "uml/Operation.hpp"
#include "uml/Property.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

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
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Object 
	 * which is generated by the compiler (as Object is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Object::operator=(obj);

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

//*********************************
// Operations
//*********************************
Any ObjectImpl::get(std::shared_ptr<uml::Property> property) const
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Object> > ObjectImpl::invoke(std::shared_ptr<uml::Operation> op,std::shared_ptr<Bag<uml::Argument>> arguments)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

void ObjectImpl::set(std::shared_ptr<uml::Property> property,Any value)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

void ObjectImpl::unset(std::shared_ptr<uml::Property> property)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ObjectImpl::eContainer() const
{
	return nullptr;
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

std::shared_ptr<ecore::EClass> ObjectImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getObject_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
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
// EOperation Invoke
//*********************************
Any ObjectImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::Object::get(uml::Property) : Any {const}: 160022814
		case umlPackage::OBJECT_OPERATION_GET_PROPERTY:
		{
			//Retrieve input parameter 'property'
			//parameter 0
			std::shared_ptr<uml::Property> incoming_param_property;
			std::list<Any>::const_iterator incoming_param_property_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_property = (*incoming_param_property_arguments_citer)->get<std::shared_ptr<uml::Property> >();
			result = this->get(incoming_param_property);
			break;
		}
		// uml::Object::invoke(uml::Operation, uml::Argument[*]) : uml::Object[*]: 229017557
		case umlPackage::OBJECT_OPERATION_INVOKE_OPERATION_ARGUMENT:
		{
			//Retrieve input parameter 'op'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_op;
			std::list<Any>::const_iterator incoming_param_op_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_op = (*incoming_param_op_arguments_citer)->get<std::shared_ptr<uml::Operation> >();
			//Retrieve input parameter 'arguments'
			//parameter 1
			std::shared_ptr<Bag<uml::Argument>> incoming_param_arguments;
			std::list<Any>::const_iterator incoming_param_arguments_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_arguments = (*incoming_param_arguments_arguments_citer)->get<std::shared_ptr<Bag<uml::Argument>> >();
			std::shared_ptr<Bag<uml::Object> > resultList = this->invoke(incoming_param_op,incoming_param_arguments);
			return eAny(resultList,uml::umlPackage::OBJECT_CLASS,true);
			break;
		}
		// uml::Object::set(uml::Property, Any): 1266543324
		case umlPackage::OBJECT_OPERATION_SET_PROPERTY_EJAVAOBJECT:
		{
			//Retrieve input parameter 'property'
			//parameter 0
			std::shared_ptr<uml::Property> incoming_param_property;
			std::list<Any>::const_iterator incoming_param_property_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_property = (*incoming_param_property_arguments_citer)->get<std::shared_ptr<uml::Property> >();
			//Retrieve input parameter 'value'
			//parameter 1
			Any incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<Any >();
			this->set(incoming_param_property,incoming_param_value);
			break;
		}
		// uml::Object::unset(uml::Property): 1465531791
		case umlPackage::OBJECT_OPERATION_UNSET_PROPERTY:
		{
			//Retrieve input parameter 'property'
			//parameter 0
			std::shared_ptr<uml::Property> incoming_param_property;
			std::list<Any>::const_iterator incoming_param_property_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_property = (*incoming_param_property_arguments_citer)->get<std::shared_ptr<uml::Property> >();
			this->unset(incoming_param_property);
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Object> ObjectImpl::getThisObjectPtr() const
{
	return m_thisObjectPtr.lock();
}
void ObjectImpl::setThisObjectPtr(std::weak_ptr<uml::Object> thisObjectPtr)
{
	m_thisObjectPtr = thisObjectPtr;
}


