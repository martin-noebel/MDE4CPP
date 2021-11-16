
#include "ocl/Evaluations/impl/PrimitiveLiteralExpEvalImpl.hpp"

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
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"

#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "ocl/Evaluations/LiteralExpEval.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
PrimitiveLiteralExpEvalImpl::PrimitiveLiteralExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PrimitiveLiteralExpEvalImpl::~PrimitiveLiteralExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PrimitiveLiteralExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


PrimitiveLiteralExpEvalImpl::PrimitiveLiteralExpEvalImpl(const PrimitiveLiteralExpEvalImpl & obj): PrimitiveLiteralExpEvalImpl()
{
	*this = obj;
}

PrimitiveLiteralExpEvalImpl& PrimitiveLiteralExpEvalImpl::operator=(const PrimitiveLiteralExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	LiteralExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PrimitiveLiteralExpEval 
	 * which is generated by the compiler (as PrimitiveLiteralExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PrimitiveLiteralExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PrimitiveLiteralExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PrimitiveLiteralExpEvalImpl::copy() const
{
	std::shared_ptr<PrimitiveLiteralExpEvalImpl> element(new PrimitiveLiteralExpEvalImpl());
	*element =(*this);
	element->setThisPrimitiveLiteralExpEvalPtr(element);
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

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PrimitiveLiteralExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void PrimitiveLiteralExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PrimitiveLiteralExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	LiteralExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void PrimitiveLiteralExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	LiteralExpEvalImpl::loadNode(nodeName, loadHandler);
}

void PrimitiveLiteralExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	LiteralExpEvalImpl::resolveReferences(featureID, references);
}

void PrimitiveLiteralExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	LiteralExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PrimitiveLiteralExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> PrimitiveLiteralExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getPrimitiveLiteralExpEval_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any PrimitiveLiteralExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return LiteralExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool PrimitiveLiteralExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return LiteralExpEvalImpl::internalEIsSet(featureID);
}

bool PrimitiveLiteralExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return LiteralExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any PrimitiveLiteralExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
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


std::shared_ptr<ocl::Evaluations::PrimitiveLiteralExpEval> PrimitiveLiteralExpEvalImpl::getThisPrimitiveLiteralExpEvalPtr() const
{
	return m_thisPrimitiveLiteralExpEvalPtr.lock();
}
void PrimitiveLiteralExpEvalImpl::setThisPrimitiveLiteralExpEvalPtr(std::weak_ptr<ocl::Evaluations::PrimitiveLiteralExpEval> thisPrimitiveLiteralExpEvalPtr)
{
	m_thisPrimitiveLiteralExpEvalPtr = thisPrimitiveLiteralExpEvalPtr;
	setThisLiteralExpEvalPtr(thisPrimitiveLiteralExpEvalPtr);
}
