
#include "fUML/Semantics/StructuredClassifiers/impl/ExtensionalValueListImpl.hpp"

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


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"

#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
ExtensionalValueListImpl::ExtensionalValueListImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExtensionalValueListImpl::~ExtensionalValueListImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExtensionalValueList "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ExtensionalValueListImpl::ExtensionalValueListImpl(const ExtensionalValueListImpl & obj): ExtensionalValueListImpl()
{
	*this = obj;
}

ExtensionalValueListImpl& ExtensionalValueListImpl::operator=(const ExtensionalValueListImpl & obj)
{
	//call overloaded =Operator for each base class
	ExtensionalValueImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ExtensionalValueList 
	 * which is generated by the compiler (as ExtensionalValueList is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ExtensionalValueList::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExtensionalValueList "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExtensionalValueListImpl::copy() const
{
	std::shared_ptr<ExtensionalValueListImpl> element(new ExtensionalValueListImpl());
	*element =(*this);
	element->setThisExtensionalValueListPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool ExtensionalValueListImpl::addValue(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ExtensionalValueListImpl::addValue(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value,int i)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> ExtensionalValueListImpl::getValue()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string ExtensionalValueListImpl::removeValue(int i)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<fUML::Semantics::Values::Value> ExtensionalValueListImpl::setValue(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value,int i)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
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
std::shared_ptr<ecore::EObject> ExtensionalValueListImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ExtensionalValueListImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExtensionalValueListImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ExtensionalValueImpl::loadAttributes(loadHandler, attr_list);
}

void ExtensionalValueListImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ExtensionalValueImpl::loadNode(nodeName, loadHandler);
}

void ExtensionalValueListImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ExtensionalValueImpl::resolveReferences(featureID, references);
}

void ExtensionalValueListImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExtensionalValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExtensionalValueListImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> ExtensionalValueListImpl::eStaticClass() const
{
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getExtensionalValueList_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ExtensionalValueListImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ExtensionalValueImpl::eGet(featureID, resolve, coreType);
}

bool ExtensionalValueListImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ExtensionalValueImpl::internalEIsSet(featureID);
}

bool ExtensionalValueListImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ExtensionalValueImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ExtensionalValueListImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 935741283
		case StructuredClassifiersPackage::EXTENSIONALVALUELIST_OPERATION_ADDVALUE_EXTENSIONALVALUE:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> incoming_param_value;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> >();
			result = eAny(this->addValue(incoming_param_value));
			break;
		}
		
		// 160454059
		case StructuredClassifiersPackage::EXTENSIONALVALUELIST_OPERATION_ADDVALUE_EXTENSIONALVALUE_EINT:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> incoming_param_value;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> >();
			//Retrieve input parameter 'i'
			//parameter 1
			int incoming_param_i;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_i_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_i = (*incoming_param_i_arguments_citer)->get()->get<int >();
			this->addValue(incoming_param_value,incoming_param_i);
			break;
		}
		
		// 1588146499
		case StructuredClassifiersPackage::EXTENSIONALVALUELIST_OPERATION_GETVALUE:
		{
			result = eAny(this->getValue());
			break;
		}
		
		// 1425086792
		case StructuredClassifiersPackage::EXTENSIONALVALUELIST_OPERATION_REMOVEVALUE_EINT:
		{
			//Retrieve input parameter 'i'
			//parameter 0
			int incoming_param_i;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_i_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_i = (*incoming_param_i_arguments_citer)->get()->get<int >();
			result = eAny(this->removeValue(incoming_param_i));
			break;
		}
		
		// 950923814
		case StructuredClassifiersPackage::EXTENSIONALVALUELIST_OPERATION_SETVALUE_EXTENSIONALVALUE_EINT:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> incoming_param_value;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> >();
			//Retrieve input parameter 'i'
			//parameter 1
			int incoming_param_i;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_i_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_i = (*incoming_param_i_arguments_citer)->get()->get<int >();
			result = eAny(this->setValue(incoming_param_value,incoming_param_i));
			break;
		}

		default:
		{
			// call superTypes
			result = ExtensionalValueImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueList> ExtensionalValueListImpl::getThisExtensionalValueListPtr() const
{
	return m_thisExtensionalValueListPtr.lock();
}
void ExtensionalValueListImpl::setThisExtensionalValueListPtr(std::weak_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValueList> thisExtensionalValueListPtr)
{
	m_thisExtensionalValueListPtr = thisExtensionalValueListPtr;
	setThisExtensionalValuePtr(thisExtensionalValueListPtr);
}
