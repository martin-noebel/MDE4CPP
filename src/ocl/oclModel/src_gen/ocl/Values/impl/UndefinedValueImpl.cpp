#include "ocl/Values/impl/UndefinedValueImpl.hpp"

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
#include "fUML/FUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence


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
UndefinedValueImpl::UndefinedValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

UndefinedValueImpl::~UndefinedValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete UndefinedValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


UndefinedValueImpl::UndefinedValueImpl(const UndefinedValueImpl & obj): UndefinedValueImpl()
{
	*this = obj;
}

UndefinedValueImpl& UndefinedValueImpl::operator=(const UndefinedValueImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::ValueImpl::operator=(obj);
	UndefinedValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy UndefinedValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> UndefinedValueImpl::copy() const
{
	std::shared_ptr<UndefinedValueImpl> element(new UndefinedValueImpl());
	*element =(*this);
	element->setThisUndefinedValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> UndefinedValueImpl::eStaticClass() const
{
	return ocl::Values::ValuesPackage::eInstance()->getUndefinedValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool UndefinedValueImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return otherValue != nullptr && otherValue->eClass()->getClassifierID() == this->eClass()->getClassifierID();
   
	//end of body
}

std::string UndefinedValueImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "Undefined";
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<UndefinedValue> UndefinedValueImpl::getThisUndefinedValuePtr() const
{
	return m_thisUndefinedValuePtr.lock();
}
void UndefinedValueImpl::setThisUndefinedValuePtr(std::weak_ptr<UndefinedValue> thisUndefinedValuePtr)
{
	m_thisUndefinedValuePtr = thisUndefinedValuePtr;
	setThisValuePtr(thisUndefinedValuePtr);
}
std::shared_ptr<ecore::EObject> UndefinedValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any UndefinedValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::ValueImpl::eGet(featureID, resolve, coreType);
}
bool UndefinedValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Values::ValueImpl::internalEIsSet(featureID);
}
bool UndefinedValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Values::ValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void UndefinedValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void UndefinedValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Values::ValueImpl::loadAttributes(loadHandler, attr_list);
}

void UndefinedValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::ValueImpl::loadNode(nodeName, loadHandler);
}

void UndefinedValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Values::ValueImpl::resolveReferences(featureID, references);
}

void UndefinedValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void UndefinedValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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
