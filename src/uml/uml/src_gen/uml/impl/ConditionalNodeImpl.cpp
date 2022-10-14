
#include "uml/impl/ConditionalNodeImpl.hpp"
#ifdef NDEBUG
	#define DEBUG_INFO(a)		/**/
	#define DEBUG_WARNING(a)	/**/
	#define DEBUG_ERROR(a)		/**/
#else
	#define DEBUG_INFO(a) 		std::cout<<"[\e[0;32mInfo\e[0m]:\t\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_WARNING(a) 	std::cout<<"[\e[0;33mWarning\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
	#define DEBUG_ERROR(a)		std::cout<<"[\e[0;31mError\e[0m]:\t"<<__PRETTY_FUNCTION__<<"\n\t\t  -- Message: "<<a<<std::endl;
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


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
//Forward declaration includes
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Clause.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Variable.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConditionalNodeImpl::ConditionalNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ConditionalNodeImpl::~ConditionalNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConditionalNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConditionalNodeImpl::ConditionalNodeImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id)
:ConditionalNodeImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		m_activity = par_Activity;
		m_owner = par_Activity;
		 return;
	case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		m_inActivity = par_Activity;
		m_owner = par_Activity;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
ConditionalNodeImpl::ConditionalNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ConditionalNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ConditionalNodeImpl::ConditionalNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ConditionalNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ConditionalNodeImpl::ConditionalNodeImpl(std::weak_ptr<uml::Element> par_owner)
:ConditionalNodeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ConditionalNodeImpl::ConditionalNodeImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup)
:ConditionalNodeImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}

ConditionalNodeImpl::ConditionalNodeImpl(const ConditionalNodeImpl & obj): ConditionalNodeImpl()
{
	*this = obj;
}

ConditionalNodeImpl& ConditionalNodeImpl::operator=(const ConditionalNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuredActivityNodeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ConditionalNode 
	 * which is generated by the compiler (as ConditionalNode is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ConditionalNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConditionalNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isAssured = obj.getIsAssured();
	m_isDeterminate = obj.getIsDeterminate();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'clause'
	std::shared_ptr<Subset<uml::Clause, uml::Element>> clauseList = obj.getClause();
	if(clauseList)
	{
		/*Subset*/
		m_clause.reset(new Subset<uml::Clause, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_clause - Subset<uml::Clause, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getClause()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_clause - Subset<uml::Clause, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Clause> clauseindexElem: *clauseList) 
		{
			std::shared_ptr<uml::Clause> temp = std::dynamic_pointer_cast<uml::Clause>((clauseindexElem)->copy());
			m_clause->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for clause.")
	}
	/*Subset*/
	getClause()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_clause - Subset<uml::Clause, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> ConditionalNodeImpl::copy() const
{
	std::shared_ptr<ConditionalNodeImpl> element(new ConditionalNodeImpl());
	*element =(*this);
	element->setThisConditionalNodePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isAssured */
bool ConditionalNodeImpl::getIsAssured() const 
{
	return m_isAssured;
}
void ConditionalNodeImpl::setIsAssured(bool _isAssured)
{
	m_isAssured = _isAssured;
	
}

/* Getter & Setter for attribute isDeterminate */
bool ConditionalNodeImpl::getIsDeterminate() const 
{
	return m_isDeterminate;
}
void ConditionalNodeImpl::setIsDeterminate(bool _isDeterminate)
{
	m_isDeterminate = _isDeterminate;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference clause */
std::shared_ptr<Subset<uml::Clause, uml::Element>> ConditionalNodeImpl::getClause() const
{
	if(m_clause == nullptr)
	{
		/*Subset*/
		m_clause.reset(new Subset<uml::Clause, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_clause - Subset<uml::Clause, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getClause()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_clause - Subset<uml::Clause, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_clause;
}

/* Getter & Setter for reference result */
std::shared_ptr<Bag<uml::OutputPin>> ConditionalNodeImpl::getResult() const
{
	//Getter call of redefined container reference StructuredActivityNode::structuredNodeOutput 
	return uml::StructuredActivityNodeImpl::getStructuredNodeOutput();
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ConditionalNodeImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}
	if(auto wp = m_inActivity.lock())
	{
		return wp;
	}


	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_superGroup.lock())
	{
		return wp;
	}
	return nullptr;
}

std::shared_ptr<ecore::EClass> ConditionalNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getConditionalNode_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ConditionalNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_CLAUSE:
			return eEcoreContainerAny(getClause(),uml::umlPackage::CLAUSE_CLASS); //4944
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_ISASSURED:
			return eAny(getIsAssured(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //4945
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_ISDETERMINATE:
			return eAny(getIsDeterminate(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //4946
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_RESULT:
			return eEcoreContainerAny(getResult(),uml::umlPackage::OUTPUTPIN_CLASS); //4947
	}
	return StructuredActivityNodeImpl::eGet(featureID, resolve, coreType);
}

bool ConditionalNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_CLAUSE:
			return getClause() != nullptr; //4944
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_ISASSURED:
			return getIsAssured() != false; //4945
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_ISDETERMINATE:
			return getIsDeterminate() != false; //4946
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_RESULT:
			return getResult() != nullptr; //4947
	}
	return StructuredActivityNodeImpl::internalEIsSet(featureID);
}

bool ConditionalNodeImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_CLAUSE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::Clause>> _clause = getClause();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::Clause> valueToAdd = std::dynamic_pointer_cast<uml::Clause>(anEObject);
	
							if (valueToAdd)
							{
								if(_clause->find(valueToAdd) == -1)
								{
									_clause->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'clause'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'clause'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_ISASSURED:
		{
			try
			{
				bool _isAssured = newValue->get<bool>();
				setIsAssured(_isAssured); //4945
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isAssured'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_ISDETERMINATE:
		{
			try
			{
				bool _isDeterminate = newValue->get<bool>();
				setIsDeterminate(_isDeterminate); //4946
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'isDeterminate'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::CONDITIONALNODE_ATTRIBUTE_RESULT:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::OutputPin>> _result = getResult();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::OutputPin> valueToAdd = std::dynamic_pointer_cast<uml::OutputPin>(anEObject);
	
							if (valueToAdd)
							{
								if(_result->find(valueToAdd) == -1)
								{
									_result->add(valueToAdd);
								}
								//else, valueToAdd is already present so it won't be added again
							}
							else
							{
								throw "Invalid argument";
							}
						}
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'result'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'result'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return StructuredActivityNodeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ConditionalNodeImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = StructuredActivityNodeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ConditionalNode> ConditionalNodeImpl::getThisConditionalNodePtr() const
{
	return m_thisConditionalNodePtr.lock();
}
void ConditionalNodeImpl::setThisConditionalNodePtr(std::weak_ptr<uml::ConditionalNode> thisConditionalNodePtr)
{
	m_thisConditionalNodePtr = thisConditionalNodePtr;
	setThisStructuredActivityNodePtr(thisConditionalNodePtr);
}


