
#include "uml/impl/ClauseImpl.hpp"

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

#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"

#include "uml/Clause.hpp"
#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/ExecutableNode.hpp"
#include "uml/OutputPin.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ClauseImpl::ClauseImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ClauseImpl::~ClauseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Clause "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ClauseImpl::ClauseImpl(std::weak_ptr<uml::Element> par_owner)
:ClauseImpl()
{
	m_owner = par_owner;
}

ClauseImpl::ClauseImpl(const ClauseImpl & obj): ClauseImpl()
{
	*this = obj;
}

ClauseImpl& ClauseImpl::operator=(const ClauseImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Clause 
	 * which is generated by the compiler (as Clause is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Clause::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Clause "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_body  = obj.getBody();
	m_bodyOutput  = obj.getBodyOutput();
	m_decider  = obj.getDecider();
	m_predecessorClause  = obj.getPredecessorClause();
	m_successorClause  = obj.getSuccessorClause();
	m_test  = obj.getTest();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ClauseImpl::copy() const
{
	std::shared_ptr<ClauseImpl> element(new ClauseImpl());
	*element =(*this);
	element->setThisClausePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool ClauseImpl::body_output_pins(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClauseImpl::decider_output(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClauseImpl::test_and_body(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
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
/* Getter & Setter for reference body */
std::shared_ptr<Bag<uml::ExecutableNode>> ClauseImpl::getBody() const
{
	if(m_body == nullptr)
	{
		m_body.reset(new Bag<uml::ExecutableNode>());
		
		
	}
    return m_body;
}

/* Getter & Setter for reference bodyOutput */
std::shared_ptr<Bag<uml::OutputPin>> ClauseImpl::getBodyOutput() const
{
	if(m_bodyOutput == nullptr)
	{
		m_bodyOutput.reset(new Bag<uml::OutputPin>());
		
		
	}
    return m_bodyOutput;
}

/* Getter & Setter for reference decider */
std::shared_ptr<uml::OutputPin> ClauseImpl::getDecider() const
{
    return m_decider;
}
void ClauseImpl::setDecider(std::shared_ptr<uml::OutputPin> _decider)
{
    m_decider = _decider;
	
}

/* Getter & Setter for reference predecessorClause */
std::shared_ptr<Bag<uml::Clause>> ClauseImpl::getPredecessorClause() const
{
	if(m_predecessorClause == nullptr)
	{
		m_predecessorClause.reset(new Bag<uml::Clause>());
		
		
	}
    return m_predecessorClause;
}

/* Getter & Setter for reference successorClause */
std::shared_ptr<Bag<uml::Clause>> ClauseImpl::getSuccessorClause() const
{
	if(m_successorClause == nullptr)
	{
		m_successorClause.reset(new Bag<uml::Clause>());
		
		
	}
    return m_successorClause;
}

/* Getter & Setter for reference test */
std::shared_ptr<Bag<uml::ExecutableNode>> ClauseImpl::getTest() const
{
	if(m_test == nullptr)
	{
		m_test.reset(new Bag<uml::ExecutableNode>());
		
		
	}
    return m_test;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ClauseImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ClauseImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ClauseImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClauseImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("body");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("body")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("bodyOutput");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyOutput")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("decider");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("decider")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("predecessorClause");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("predecessorClause")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("successorClause");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("successorClause")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("test");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("test")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void ClauseImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ElementImpl::loadNode(nodeName, loadHandler);
}

void ClauseImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODY:
		{
			std::shared_ptr<Bag<uml::ExecutableNode>> _body = getBody();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExecutableNode>  _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_body->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODYOUTPUT:
		{
			std::shared_ptr<Bag<uml::OutputPin>> _bodyOutput = getBodyOutput();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::OutputPin>  _r = std::dynamic_pointer_cast<uml::OutputPin>(ref);
				if (_r != nullptr)
				{
					_bodyOutput->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_DECIDER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::OutputPin> _decider = std::dynamic_pointer_cast<uml::OutputPin>( references.front() );
				setDecider(_decider);
			}
			
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE:
		{
			std::shared_ptr<Bag<uml::Clause>> _predecessorClause = getPredecessorClause();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Clause>  _r = std::dynamic_pointer_cast<uml::Clause>(ref);
				if (_r != nullptr)
				{
					_predecessorClause->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE:
		{
			std::shared_ptr<Bag<uml::Clause>> _successorClause = getSuccessorClause();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Clause>  _r = std::dynamic_pointer_cast<uml::Clause>(ref);
				if (_r != nullptr)
				{
					_successorClause->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLAUSE_ATTRIBUTE_TEST:
		{
			std::shared_ptr<Bag<uml::ExecutableNode>> _test = getTest();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExecutableNode>  _r = std::dynamic_pointer_cast<uml::ExecutableNode>(ref);
				if (_r != nullptr)
				{
					_test->push_back(_r);
				}
			}
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void ClauseImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ClauseImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::ExecutableNode>("body", this->getBody());
		saveHandler->addReferences<uml::OutputPin>("bodyOutput", this->getBodyOutput());
		saveHandler->addReference(this->getDecider(), "decider", getDecider()->eClass() != uml::umlPackage::eInstance()->getOutputPin_Class()); 
		saveHandler->addReferences<uml::Clause>("predecessorClause", this->getPredecessorClause());
		saveHandler->addReferences<uml::Clause>("successorClause", this->getSuccessorClause());
		saveHandler->addReferences<uml::ExecutableNode>("test", this->getTest());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ClauseImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getClause_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ClauseImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODY:
		{
			return eAnyBag(getBody(),1759403238); //383
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODYOUTPUT:
		{
			return eAnyBag(getBodyOutput(),681481770); //384
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_DECIDER:
		{
			std::shared_ptr<ecore::EObject> returnValue=getDecider();
			return eAny(returnValue,returnValue->getMetaElementID(),false); //385
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE:
		{
			return eAnyBag(getPredecessorClause(),1571471300); //386
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE:
		{
			return eAnyBag(getSuccessorClause(),1571471300); //387
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_TEST:
		{
			return eAnyBag(getTest(),1759403238); //388
		}
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}

bool ClauseImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODY:
			return getBody() != nullptr; //383
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODYOUTPUT:
			return getBodyOutput() != nullptr; //384
		case uml::umlPackage::CLAUSE_ATTRIBUTE_DECIDER:
			return getDecider() != nullptr; //385
		case uml::umlPackage::CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE:
			return getPredecessorClause() != nullptr; //386
		case uml::umlPackage::CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE:
			return getSuccessorClause() != nullptr; //387
		case uml::umlPackage::CLAUSE_ATTRIBUTE_TEST:
			return getTest() != nullptr; //388
	}
	return ElementImpl::internalEIsSet(featureID);
}

bool ClauseImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODY:
		{
			// BOOST CAST
			if((newValue->isContainer()) && (uml::umlPackage::EXECUTABLENODE_CLASS ==newValue->getTypeId()))
			{
				try
				{
					std::shared_ptr<Bag<uml::ExecutableNode>> bodyList= newValue->get<std::shared_ptr<Bag<uml::ExecutableNode>>>();
					std::shared_ptr<Bag<uml::ExecutableNode>> _body=getBody();
					for(const std::shared_ptr<uml::ExecutableNode> indexBody: *_body)
					{
						if (bodyList->find(indexBody) == -1)
						{
							_body->erase(indexBody);
						}
					}

					for(const std::shared_ptr<uml::ExecutableNode> indexBody: *bodyList)
					{
						if (_body->find(indexBody) == -1)
						{
							_body->add(indexBody);
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
		case uml::umlPackage::CLAUSE_ATTRIBUTE_BODYOUTPUT:
		{
			// BOOST CAST
			if((newValue->isContainer()) && (uml::umlPackage::OUTPUTPIN_CLASS ==newValue->getTypeId()))
			{
				try
				{
					std::shared_ptr<Bag<uml::OutputPin>> bodyOutputList= newValue->get<std::shared_ptr<Bag<uml::OutputPin>>>();
					std::shared_ptr<Bag<uml::OutputPin>> _bodyOutput=getBodyOutput();
					for(const std::shared_ptr<uml::OutputPin> indexBodyOutput: *_bodyOutput)
					{
						if (bodyOutputList->find(indexBodyOutput) == -1)
						{
							_bodyOutput->erase(indexBodyOutput);
						}
					}

					for(const std::shared_ptr<uml::OutputPin> indexBodyOutput: *bodyOutputList)
					{
						if (_bodyOutput->find(indexBodyOutput) == -1)
						{
							_bodyOutput->add(indexBodyOutput);
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
		case uml::umlPackage::CLAUSE_ATTRIBUTE_DECIDER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OutputPin> _decider = std::dynamic_pointer_cast<uml::OutputPin>(_temp);
			setDecider(_decider); //385
			return true;
		}
		case uml::umlPackage::CLAUSE_ATTRIBUTE_PREDECESSORCLAUSE:
		{
			// BOOST CAST
			if((newValue->isContainer()) && (uml::umlPackage::CLAUSE_CLASS ==newValue->getTypeId()))
			{
				try
				{
					std::shared_ptr<Bag<uml::Clause>> predecessorClauseList= newValue->get<std::shared_ptr<Bag<uml::Clause>>>();
					std::shared_ptr<Bag<uml::Clause>> _predecessorClause=getPredecessorClause();
					for(const std::shared_ptr<uml::Clause> indexPredecessorClause: *_predecessorClause)
					{
						if (predecessorClauseList->find(indexPredecessorClause) == -1)
						{
							_predecessorClause->erase(indexPredecessorClause);
						}
					}

					for(const std::shared_ptr<uml::Clause> indexPredecessorClause: *predecessorClauseList)
					{
						if (_predecessorClause->find(indexPredecessorClause) == -1)
						{
							_predecessorClause->add(indexPredecessorClause);
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
		case uml::umlPackage::CLAUSE_ATTRIBUTE_SUCCESSORCLAUSE:
		{
			// BOOST CAST
			if((newValue->isContainer()) && (uml::umlPackage::CLAUSE_CLASS ==newValue->getTypeId()))
			{
				try
				{
					std::shared_ptr<Bag<uml::Clause>> successorClauseList= newValue->get<std::shared_ptr<Bag<uml::Clause>>>();
					std::shared_ptr<Bag<uml::Clause>> _successorClause=getSuccessorClause();
					for(const std::shared_ptr<uml::Clause> indexSuccessorClause: *_successorClause)
					{
						if (successorClauseList->find(indexSuccessorClause) == -1)
						{
							_successorClause->erase(indexSuccessorClause);
						}
					}

					for(const std::shared_ptr<uml::Clause> indexSuccessorClause: *successorClauseList)
					{
						if (_successorClause->find(indexSuccessorClause) == -1)
						{
							_successorClause->add(indexSuccessorClause);
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
		case uml::umlPackage::CLAUSE_ATTRIBUTE_TEST:
		{
			// BOOST CAST
			if((newValue->isContainer()) && (uml::umlPackage::EXECUTABLENODE_CLASS ==newValue->getTypeId()))
			{
				try
				{
					std::shared_ptr<Bag<uml::ExecutableNode>> testList= newValue->get<std::shared_ptr<Bag<uml::ExecutableNode>>>();
					std::shared_ptr<Bag<uml::ExecutableNode>> _test=getTest();
					for(const std::shared_ptr<uml::ExecutableNode> indexTest: *_test)
					{
						if (testList->find(indexTest) == -1)
						{
							_test->erase(indexTest);
						}
					}

					for(const std::shared_ptr<uml::ExecutableNode> indexTest: *testList)
					{
						if (_test->find(indexTest) == -1)
						{
							_test->add(indexTest);
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

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ClauseImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::Clause::body_output_pins(Any, std::map) : bool: 555602658
		case umlPackage::CLAUSE_OPERATION_BODY_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->body_output_pins(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Clause::decider_output(Any, std::map) : bool: 1781490540
		case umlPackage::CLAUSE_OPERATION_DECIDER_OUTPUT_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->decider_output(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Clause::test_and_body(Any, std::map) : bool: 1862078178
		case umlPackage::CLAUSE_OPERATION_TEST_AND_BODY_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->test_and_body(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Clause> ClauseImpl::getThisClausePtr() const
{
	return m_thisClausePtr.lock();
}
void ClauseImpl::setThisClausePtr(std::weak_ptr<uml::Clause> thisClausePtr)
{
	m_thisClausePtr = thisClausePtr;
	setThisElementPtr(thisClausePtr);
}


