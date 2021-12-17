
#include "ocl/Evaluations/impl/TupleLiteralExpEvalImpl.hpp"

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
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/umlFactory.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "ocl/Evaluations/LiteralExpEval.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
#include "ocl/Evaluations/VariableDeclEval.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
TupleLiteralExpEvalImpl::TupleLiteralExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TupleLiteralExpEvalImpl::~TupleLiteralExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TupleLiteralExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


TupleLiteralExpEvalImpl::TupleLiteralExpEvalImpl(const TupleLiteralExpEvalImpl & obj): TupleLiteralExpEvalImpl()
{
	*this = obj;
}

TupleLiteralExpEvalImpl& TupleLiteralExpEvalImpl::operator=(const TupleLiteralExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	LiteralExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TupleLiteralExpEval 
	 * which is generated by the compiler (as TupleLiteralExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TupleLiteralExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TupleLiteralExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_tuplePart  = obj.getTuplePart();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> TupleLiteralExpEvalImpl::copy() const
{
	std::shared_ptr<TupleLiteralExpEvalImpl> element(new TupleLiteralExpEvalImpl());
	*element =(*this);
	element->setThisTupleLiteralExpEvalPtr(element);
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
/* Getter & Setter for reference tuplePart */
std::shared_ptr<Bag<ocl::Evaluations::VariableDeclEval>> TupleLiteralExpEvalImpl::getTuplePart() const
{
	if(m_tuplePart == nullptr)
	{
		m_tuplePart.reset(new Bag<ocl::Evaluations::VariableDeclEval>());
		
		
	}
    return m_tuplePart;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TupleLiteralExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void TupleLiteralExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TupleLiteralExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("tuplePart");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("tuplePart")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	LiteralExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void TupleLiteralExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LiteralExpEvalImpl::loadNode(nodeName, loadHandler);
}

void TupleLiteralExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::TUPLELITERALEXPEVAL_ATTRIBUTE_TUPLEPART:
		{
			std::shared_ptr<Bag<ocl::Evaluations::VariableDeclEval>> _tuplePart = getTuplePart();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Evaluations::VariableDeclEval>  _r = std::dynamic_pointer_cast<ocl::Evaluations::VariableDeclEval>(ref);
				if (_r != nullptr)
				{
					_tuplePart->push_back(_r);
				}
			}
			return;
		}
	}
	LiteralExpEvalImpl::resolveReferences(featureID, references);
}

void TupleLiteralExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TupleLiteralExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReferences<ocl::Evaluations::VariableDeclEval>("tuplePart", this->getTuplePart());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> TupleLiteralExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getTupleLiteralExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any TupleLiteralExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::TUPLELITERALEXPEVAL_ATTRIBUTE_TUPLEPART:
		{
			return eAnyBag(getTuplePart(),ocl::Evaluations::EvaluationsPackage::VARIABLEDECLEVAL_CLASS); //866
		}
	}
	return LiteralExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool TupleLiteralExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::TUPLELITERALEXPEVAL_ATTRIBUTE_TUPLEPART:
			return getTuplePart() != nullptr; //866
	}
	return LiteralExpEvalImpl::internalEIsSet(featureID);
}

bool TupleLiteralExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::TUPLELITERALEXPEVAL_ATTRIBUTE_TUPLEPART:
		{
			// CAST Any to Bag<ocl::Evaluations::VariableDeclEval>
			if((newValue->isContainer()) && (ocl::Evaluations::EvaluationsPackage::VARIABLEDECLEVAL_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ocl::Evaluations::VariableDeclEval>> tuplePartList= newValue->get<std::shared_ptr<Bag<ocl::Evaluations::VariableDeclEval>>>();
					std::shared_ptr<Bag<ocl::Evaluations::VariableDeclEval>> _tuplePart=getTuplePart();
					for(const std::shared_ptr<ocl::Evaluations::VariableDeclEval> indexTuplePart: *_tuplePart)
					{
						if (tuplePartList->find(indexTuplePart) == -1)
						{
							_tuplePart->erase(indexTuplePart);
						}
					}

					for(const std::shared_ptr<ocl::Evaluations::VariableDeclEval> indexTuplePart: *tuplePartList)
					{
						if (_tuplePart->find(indexTuplePart) == -1)
						{
							_tuplePart->add(indexTuplePart);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
	}

	return LiteralExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any TupleLiteralExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = LiteralExpEvalImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::TupleLiteralExpEval> TupleLiteralExpEvalImpl::getThisTupleLiteralExpEvalPtr() const
{
	return m_thisTupleLiteralExpEvalPtr.lock();
}
void TupleLiteralExpEvalImpl::setThisTupleLiteralExpEvalPtr(std::weak_ptr<ocl::Evaluations::TupleLiteralExpEval> thisTupleLiteralExpEvalPtr)
{
	m_thisTupleLiteralExpEvalPtr = thisTupleLiteralExpEvalPtr;
	setThisLiteralExpEvalPtr(thisTupleLiteralExpEvalPtr);
}


