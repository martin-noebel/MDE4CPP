
#include "ocl/Values/impl/OclVoidValueImpl.hpp"

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

//Includes from codegen annotation
#include "fUML/fUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Values/Value.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Values/ValuesPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"

using namespace ocl::Values;

//*********************************
// Constructor / Destructor
//*********************************
OclVoidValueImpl::OclVoidValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OclVoidValueImpl::~OclVoidValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OclVoidValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


OclVoidValueImpl::OclVoidValueImpl(const OclVoidValueImpl & obj): OclVoidValueImpl()
{
	*this = obj;
}

OclVoidValueImpl& OclVoidValueImpl::operator=(const OclVoidValueImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::ValueImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of OclVoidValue 
	 * which is generated by the compiler (as OclVoidValue is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//OclVoidValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OclVoidValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OclVoidValueImpl::copy() const
{
	std::shared_ptr<OclVoidValueImpl> element(new OclVoidValueImpl());
	*element =(*this);
	element->setThisOclVoidValuePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool OclVoidValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return otherValue != nullptr && otherValue->eClass()->getClassifierID() == this->eClass()->getClassifierID();
   
	//end of body
}

std::string OclVoidValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "";
	//end of body
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
std::shared_ptr<ecore::EObject> OclVoidValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void OclVoidValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OclVoidValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Values::ValueImpl::loadAttributes(loadHandler, attr_list);
}

void OclVoidValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::ValueImpl::loadNode(nodeName, loadHandler);
}

void OclVoidValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Values::ValueImpl::resolveReferences(featureID, references);
}

void OclVoidValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void OclVoidValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Values::ValuesPackage> package = ocl::Values::ValuesPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> OclVoidValueImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getOclVoidValue_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any OclVoidValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::ValueImpl::eGet(featureID, resolve, coreType);
}

bool OclVoidValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::ValueImpl::internalEIsSet(featureID);
}

bool OclVoidValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Values::ValueImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any OclVoidValueImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// ocl::Values::OclVoidValue::equals(fUML::Semantics::Values::Value) : bool: 613975732
		case ValuesPackage::OCLVOIDVALUE_OPERATION_EQUALS_VALUE:
		{
			//Retrieve input parameter 'otherValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_otherValue;
			std::list<Any>::const_iterator incoming_param_otherValue_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_otherValue = (*incoming_param_otherValue_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->equals(incoming_param_otherValue),0,false);
			break;
		}
		// ocl::Values::OclVoidValue::toString() : std::string: 1594356317
		case ValuesPackage::OCLVOIDVALUE_OPERATION_TOSTRING:
		{
			result = eAny(this->toString(),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::ValueImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Values::OclVoidValue> OclVoidValueImpl::getThisOclVoidValuePtr() const
{
	return m_thisOclVoidValuePtr.lock();
}
void OclVoidValueImpl::setThisOclVoidValuePtr(std::weak_ptr<ocl::Values::OclVoidValue> thisOclVoidValuePtr)
{
	m_thisOclVoidValuePtr = thisOclVoidValuePtr;
	setThisValuePtr(thisOclVoidValuePtr);
}


