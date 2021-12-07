
#include "ocl/Expressions/impl/TupleLiteralPartImpl.hpp"

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
#include "ecore/ecoreFactory.hpp"

#include "ecore/EAnnotation.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/ETypedElement.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
TupleLiteralPartImpl::TupleLiteralPartImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TupleLiteralPartImpl::~TupleLiteralPartImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TupleLiteralPart "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


TupleLiteralPartImpl::TupleLiteralPartImpl(const TupleLiteralPartImpl & obj): TupleLiteralPartImpl()
{
	*this = obj;
}

TupleLiteralPartImpl& TupleLiteralPartImpl::operator=(const TupleLiteralPartImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::ETypedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TupleLiteralPart 
	 * which is generated by the compiler (as TupleLiteralPart is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TupleLiteralPart::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TupleLiteralPart "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'attribute'
	if(obj.getAttribute()!=nullptr)
	{
		m_attribute = std::dynamic_pointer_cast<ecore::EAttribute>(obj.getAttribute()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> TupleLiteralPartImpl::copy() const
{
	std::shared_ptr<TupleLiteralPartImpl> element(new TupleLiteralPartImpl());
	*element =(*this);
	element->setThisTupleLiteralPartPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference attribute */
std::shared_ptr<ecore::EAttribute> TupleLiteralPartImpl::getAttribute() const
{
    return m_attribute;
}
void TupleLiteralPartImpl::setAttribute(std::shared_ptr<ecore::EAttribute> _attribute)
{
    m_attribute = _attribute;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TupleLiteralPartImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void TupleLiteralPartImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TupleLiteralPartImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void TupleLiteralPartImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("attribute") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EAttribute";
			}
			loadHandler->handleChild(this->getAttribute());

			return; 
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
	//load BasePackage Nodes
	ecore::ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void TupleLiteralPartImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ecore::ETypedElementImpl::resolveReferences(featureID, references);
}

void TupleLiteralPartImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TupleLiteralPartImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'attribute'

		saveHandler->addReference(this->getAttribute(), "attribute", getAttribute()->eClass() != ecore::ecorePackage::eInstance()->getEAttribute_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> TupleLiteralPartImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getTupleLiteralPart_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any TupleLiteralPartImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_ATTRIBUTE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getAttribute();
			return eAny(returnValue,returnValue->getMetaElementID(),false); //8810
		}
	}
	return ecore::ETypedElementImpl::eGet(featureID, resolve, coreType);
}

bool TupleLiteralPartImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_ATTRIBUTE:
			return getAttribute() != nullptr; //8810
	}
	return ecore::ETypedElementImpl::internalEIsSet(featureID);
}

bool TupleLiteralPartImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::TUPLELITERALPART_ATTRIBUTE_ATTRIBUTE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EAttribute> _attribute = std::dynamic_pointer_cast<ecore::EAttribute>(_temp);
			setAttribute(_attribute); //8810
			return true;
		}
	}

	return ecore::ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any TupleLiteralPartImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::ETypedElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Expressions::TupleLiteralPart> TupleLiteralPartImpl::getThisTupleLiteralPartPtr() const
{
	return m_thisTupleLiteralPartPtr.lock();
}
void TupleLiteralPartImpl::setThisTupleLiteralPartPtr(std::weak_ptr<ocl::Expressions::TupleLiteralPart> thisTupleLiteralPartPtr)
{
	m_thisTupleLiteralPartPtr = thisTupleLiteralPartPtr;
	setThisETypedElementPtr(thisTupleLiteralPartPtr);
}


