
#include "ocl/Evaluations/impl/NavigationCallExpEvalImpl.hpp"

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
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/ModelPropertyCallExpEval.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "fUML/Semantics/SimpleClassifiers/StringValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
NavigationCallExpEvalImpl::NavigationCallExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

NavigationCallExpEvalImpl::~NavigationCallExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete NavigationCallExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


NavigationCallExpEvalImpl::NavigationCallExpEvalImpl(const NavigationCallExpEvalImpl & obj): NavigationCallExpEvalImpl()
{
	*this = obj;
}

NavigationCallExpEvalImpl& NavigationCallExpEvalImpl::operator=(const NavigationCallExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	ModelPropertyCallExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of NavigationCallExpEval 
	 * which is generated by the compiler (as NavigationCallExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//NavigationCallExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy NavigationCallExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_navigationSource  = obj.getNavigationSource();
	m_qualifiers  = obj.getQualifiers();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> NavigationCallExpEvalImpl::copy() const
{
	std::shared_ptr<NavigationCallExpEvalImpl> element(new NavigationCallExpEvalImpl());
	*element =(*this);
	element->setThisNavigationCallExpEvalPtr(element);
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
/* Getter & Setter for reference navigationSource */
std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> NavigationCallExpEvalImpl::getNavigationSource() const
{
    return m_navigationSource;
}
void NavigationCallExpEvalImpl::setNavigationSource(std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _navigationSource)
{
    m_navigationSource = _navigationSource;
	
}

/* Getter & Setter for reference qualifiers */
std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> NavigationCallExpEvalImpl::getQualifiers() const
{
	if(m_qualifiers == nullptr)
	{
		m_qualifiers.reset(new Bag<ocl::Evaluations::OclExpEval>());
		
		
	}
    return m_qualifiers;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> NavigationCallExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void NavigationCallExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void NavigationCallExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("navigationSource");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("navigationSource")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("qualifiers");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("qualifiers")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ModelPropertyCallExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void NavigationCallExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ModelPropertyCallExpEvalImpl::loadNode(nodeName, loadHandler);
}

void NavigationCallExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::NAVIGATIONCALLEXPEVAL_ATTRIBUTE_NAVIGATIONSOURCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _navigationSource = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>( references.front() );
				setNavigationSource(_navigationSource);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::NAVIGATIONCALLEXPEVAL_ATTRIBUTE_QUALIFIERS:
		{
			std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> _qualifiers = getQualifiers();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ocl::Evaluations::OclExpEval>  _r = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(ref);
				if (_r != nullptr)
				{
					_qualifiers->push_back(_r);
				}
			}
			return;
		}
	}
	ModelPropertyCallExpEvalImpl::resolveReferences(featureID, references);
}

void NavigationCallExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ModelPropertyCallExpEvalImpl::saveContent(saveHandler);
	
	PropertyCallExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void NavigationCallExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getNavigationSource(), "navigationSource", getNavigationSource()->eClass() != fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getStringValue_Class()); 
		saveHandler->addReferences<ocl::Evaluations::OclExpEval>("qualifiers", this->getQualifiers());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> NavigationCallExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getNavigationCallExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any NavigationCallExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::NAVIGATIONCALLEXPEVAL_ATTRIBUTE_NAVIGATIONSOURCE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getNavigationSource();
			return eAny(returnValue,fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::STRINGVALUE_CLASS,false); //557
		}
		case ocl::Evaluations::EvaluationsPackage::NAVIGATIONCALLEXPEVAL_ATTRIBUTE_QUALIFIERS:
		{
			return eAnyBag(getQualifiers(),ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS); //558
		}
	}
	return ModelPropertyCallExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool NavigationCallExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::NAVIGATIONCALLEXPEVAL_ATTRIBUTE_NAVIGATIONSOURCE:
			return getNavigationSource() != nullptr; //557
		case ocl::Evaluations::EvaluationsPackage::NAVIGATIONCALLEXPEVAL_ATTRIBUTE_QUALIFIERS:
			return getQualifiers() != nullptr; //558
	}
	return ModelPropertyCallExpEvalImpl::internalEIsSet(featureID);
}

bool NavigationCallExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::NAVIGATIONCALLEXPEVAL_ATTRIBUTE_NAVIGATIONSOURCE:
		{
			// CAST Any to fUML::Semantics::SimpleClassifiers::StringValue
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::StringValue> _navigationSource = std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::StringValue>(_temp);
			setNavigationSource(_navigationSource); //557
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::NAVIGATIONCALLEXPEVAL_ATTRIBUTE_QUALIFIERS:
		{
			// CAST Any to Bag<ocl::Evaluations::OclExpEval>
			if((newValue->isContainer()) && (ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> qualifiersList= newValue->get<std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>>>();
					std::shared_ptr<Bag<ocl::Evaluations::OclExpEval>> _qualifiers=getQualifiers();
					for(const std::shared_ptr<ocl::Evaluations::OclExpEval> indexQualifiers: *_qualifiers)
					{
						if (qualifiersList->find(indexQualifiers) == -1)
						{
							_qualifiers->erase(indexQualifiers);
						}
					}

					for(const std::shared_ptr<ocl::Evaluations::OclExpEval> indexQualifiers: *qualifiersList)
					{
						if (_qualifiers->find(indexQualifiers) == -1)
						{
							_qualifiers->add(indexQualifiers);
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

	return ModelPropertyCallExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any NavigationCallExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ModelPropertyCallExpEvalImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::NavigationCallExpEval> NavigationCallExpEvalImpl::getThisNavigationCallExpEvalPtr() const
{
	return m_thisNavigationCallExpEvalPtr.lock();
}
void NavigationCallExpEvalImpl::setThisNavigationCallExpEvalPtr(std::weak_ptr<ocl::Evaluations::NavigationCallExpEval> thisNavigationCallExpEvalPtr)
{
	m_thisNavigationCallExpEvalPtr = thisNavigationCallExpEvalPtr;
	setThisModelPropertyCallExpEvalPtr(thisNavigationCallExpEvalPtr);
}


