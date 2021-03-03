#include "fUML/Semantics/SimpleClassifiers/impl/SignalInstanceImpl.hpp"

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

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "fUML/Semantics/SimpleClassifiers/CompoundValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "uml/Signal.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
SignalInstanceImpl::SignalInstanceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SignalInstanceImpl::~SignalInstanceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SignalInstance "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


SignalInstanceImpl::SignalInstanceImpl(const SignalInstanceImpl & obj): SignalInstanceImpl()
{
	*this = obj;
}

SignalInstanceImpl& SignalInstanceImpl::operator=(const SignalInstanceImpl & obj)
{
	//call overloaded =Operator for each base class
	CompoundValueImpl::operator=(obj);
	SignalInstance::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SignalInstance "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_type  = obj.getType();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> SignalInstanceImpl::copy() const
{
	std::shared_ptr<SignalInstanceImpl> element(new SignalInstanceImpl());
	*element =(*this);
	element->setThisSignalInstancePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> SignalInstanceImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getSignalInstance_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> SignalInstanceImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new signal instance with the same type and feature values as this signal instance.

std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> newValue = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::SignalInstance>(fUML::Semantics::SimpleClassifiers::CompoundValueImpl::_copy());
newValue->setType(this->getType());
return newValue;
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference type
*/
std::shared_ptr<uml::Signal> SignalInstanceImpl::getType() const
{
//assert(m_type);
    return m_type;
}
void SignalInstanceImpl::setType(std::shared_ptr<uml::Signal> _type)
{
    m_type = _type;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<SignalInstance> SignalInstanceImpl::getThisSignalInstancePtr() const
{
	return m_thisSignalInstancePtr.lock();
}
void SignalInstanceImpl::setThisSignalInstancePtr(std::weak_ptr<SignalInstance> thisSignalInstancePtr)
{
	m_thisSignalInstancePtr = thisSignalInstancePtr;
	setThisCompoundValuePtr(thisSignalInstancePtr);
}
std::shared_ptr<ecore::EObject> SignalInstanceImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any SignalInstanceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::SIGNALINSTANCE_ATTRIBUTE_TYPE:
			return eAny(getType()); //1071
	}
	return CompoundValueImpl::eGet(featureID, resolve, coreType);
}
bool SignalInstanceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::SIGNALINSTANCE_ATTRIBUTE_TYPE:
			return getType() != nullptr; //1071
	}
	return CompoundValueImpl::internalEIsSet(featureID);
}
bool SignalInstanceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::SIGNALINSTANCE_ATTRIBUTE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Signal> _type = std::dynamic_pointer_cast<uml::Signal>(_temp);
			setType(_type); //1071
			return true;
		}
	}

	return CompoundValueImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void SignalInstanceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void SignalInstanceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("type");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("type")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	CompoundValueImpl::loadAttributes(loadHandler, attr_list);
}

void SignalInstanceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CompoundValueImpl::loadNode(nodeName, loadHandler);
}

void SignalInstanceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::SIGNALINSTANCE_ATTRIBUTE_TYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Signal> _type = std::dynamic_pointer_cast<uml::Signal>( references.front() );
				setType(_type);
			}
			
			return;
		}
	}
	CompoundValueImpl::resolveReferences(featureID, references);
}

void SignalInstanceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CompoundValueImpl::saveContent(saveHandler);
	
	StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void SignalInstanceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage> package = fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getType(), "type", getType()->eClass() != uml::umlPackage::eInstance()->getSignal_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

