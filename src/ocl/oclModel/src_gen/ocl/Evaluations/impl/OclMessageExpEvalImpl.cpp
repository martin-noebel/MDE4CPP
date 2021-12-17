
#include "ocl/Evaluations/impl/OclMessageExpEvalImpl.hpp"

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
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "uml/umlFactory.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Evaluations/OclMessageArgEval.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
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
OclMessageExpEvalImpl::OclMessageExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OclMessageExpEvalImpl::~OclMessageExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OclMessageExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


OclMessageExpEvalImpl::OclMessageExpEvalImpl(const OclMessageExpEvalImpl & obj): OclMessageExpEvalImpl()
{
	*this = obj;
}

OclMessageExpEvalImpl& OclMessageExpEvalImpl::operator=(const OclMessageExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	OclExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of OclMessageExpEval 
	 * which is generated by the compiler (as OclMessageExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//OclMessageExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OclMessageExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_name = obj.getName();

	//copy references with no containment (soft copy)
	m_arguments  = obj.getArguments();
	m_target  = obj.getTarget();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OclMessageExpEvalImpl::copy() const
{
	std::shared_ptr<OclMessageExpEvalImpl> element(new OclMessageExpEvalImpl());
	*element =(*this);
	element->setThisOclMessageExpEvalPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute name */
std::string OclMessageExpEvalImpl::getName() const 
{
	return m_name;
}
void OclMessageExpEvalImpl::setName(std::string _name)
{
	m_name = _name;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference arguments */
std::shared_ptr<Bag<ocl::Evaluations::OclMessageArgEval>> OclMessageExpEvalImpl::getArguments() const
{
	if(m_arguments == nullptr)
	{
		m_arguments.reset(new Bag<ocl::Evaluations::OclMessageArgEval>());
		
		
	}
    return m_arguments;
}

/* Getter & Setter for reference target */
std::shared_ptr<ocl::Evaluations::OclExpEval> OclMessageExpEvalImpl::getTarget() const
{
    return m_target;
}
void OclMessageExpEvalImpl::setTarget(std::shared_ptr<ocl::Evaluations::OclExpEval> _target)
{
    m_target = _target;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> OclMessageExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void OclMessageExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OclMessageExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("name");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setName(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("arguments");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("arguments")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("target");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("target")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	OclExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void OclMessageExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	OclExpEvalImpl::loadNode(nodeName, loadHandler);
}

void OclMessageExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEEXPEVAL_ATTRIBUTE_ARGUMENTS:
		{
			std::shared_ptr<Bag<ocl::Evaluations::OclMessageArgEval>> _arguments = getArguments();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Evaluations::OclMessageArgEval>  _r = std::dynamic_pointer_cast<ocl::Evaluations::OclMessageArgEval>(ref);
				if (_r != nullptr)
				{
					_arguments->push_back(_r);
				}
			}
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEEXPEVAL_ATTRIBUTE_TARGET:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _target = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setTarget(_target);
			}
			
			return;
		}
	}
	OclExpEvalImpl::resolveReferences(featureID, references);
}

void OclMessageExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void OclMessageExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getOclMessageExpEval_Attribute_name()) )
		{
			saveHandler->addAttribute("name", this->getName());
		}
	// Add references
		saveHandler->addReferences<ocl::Evaluations::OclMessageArgEval>("arguments", this->getArguments());
		saveHandler->addReference(this->getTarget(), "target", getTarget()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> OclMessageExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getOclMessageExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any OclMessageExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEEXPEVAL_ATTRIBUTE_ARGUMENTS:
		{
			return eAnyBag(getArguments(),ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_CLASS); //637
		}
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEEXPEVAL_ATTRIBUTE_NAME:
			return eAny(getName(),ecore::ecorePackage::ESTRING_CLASS,false); //638
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEEXPEVAL_ATTRIBUTE_TARGET:
		{
			std::shared_ptr<ecore::EObject> returnValue=getTarget();
			return eAny(returnValue,ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS,false); //636
		}
	}
	return OclExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool OclMessageExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEEXPEVAL_ATTRIBUTE_ARGUMENTS:
			return getArguments() != nullptr; //637
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEEXPEVAL_ATTRIBUTE_NAME:
			return getName() != ""; //638
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEEXPEVAL_ATTRIBUTE_TARGET:
			return getTarget() != nullptr; //636
	}
	return OclExpEvalImpl::internalEIsSet(featureID);
}

bool OclMessageExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEEXPEVAL_ATTRIBUTE_ARGUMENTS:
		{
			// CAST Any to Bag<ocl::Evaluations::OclMessageArgEval>
			if((newValue->isContainer()) && (ocl::Evaluations::EvaluationsPackage::OCLMESSAGEARGEVAL_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ocl::Evaluations::OclMessageArgEval>> argumentsList= newValue->get<std::shared_ptr<Bag<ocl::Evaluations::OclMessageArgEval>>>();
					std::shared_ptr<Bag<ocl::Evaluations::OclMessageArgEval>> _arguments=getArguments();
					for(const std::shared_ptr<ocl::Evaluations::OclMessageArgEval> indexArguments: *_arguments)
					{
						if (argumentsList->find(indexArguments) == -1)
						{
							_arguments->erase(indexArguments);
						}
					}

					for(const std::shared_ptr<ocl::Evaluations::OclMessageArgEval> indexArguments: *argumentsList)
					{
						if (_arguments->find(indexArguments) == -1)
						{
							_arguments->add(indexArguments);
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
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEEXPEVAL_ATTRIBUTE_NAME:
		{
			// CAST Any to std::string
			std::string _name = newValue->get<std::string>();
			setName(_name); //638
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::OCLMESSAGEEXPEVAL_ATTRIBUTE_TARGET:
		{
			// CAST Any to ocl::Evaluations::OclExpEval
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _target = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setTarget(_target); //636
			return true;
		}
	}

	return OclExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any OclMessageExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = OclExpEvalImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::OclMessageExpEval> OclMessageExpEvalImpl::getThisOclMessageExpEvalPtr() const
{
	return m_thisOclMessageExpEvalPtr.lock();
}
void OclMessageExpEvalImpl::setThisOclMessageExpEvalPtr(std::weak_ptr<ocl::Evaluations::OclMessageExpEval> thisOclMessageExpEvalPtr)
{
	m_thisOclMessageExpEvalPtr = thisOclMessageExpEvalPtr;
	setThisOclExpEvalPtr(thisOclMessageExpEvalPtr);
}


