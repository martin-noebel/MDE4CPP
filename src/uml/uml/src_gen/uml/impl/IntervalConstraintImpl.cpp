
#include "uml/impl/IntervalConstraintImpl.hpp"

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
#include "uml/umlFactory.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
IntervalConstraintImpl::IntervalConstraintImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

IntervalConstraintImpl::~IntervalConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete IntervalConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
IntervalConstraintImpl::IntervalConstraintImpl(std::weak_ptr<uml::Namespace> par_Namespace, const int reference_id)
:IntervalConstraintImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
		m_context = par_Namespace;
		m_namespace = par_Namespace;
		 return;
	case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
		m_namespace = par_Namespace;
		m_owner = par_Namespace;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
IntervalConstraintImpl::IntervalConstraintImpl(std::weak_ptr<uml::Element> par_owner)
:IntervalConstraintImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
IntervalConstraintImpl::IntervalConstraintImpl(std::weak_ptr<uml::Package> par_owningPackage)
:IntervalConstraintImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
IntervalConstraintImpl::IntervalConstraintImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:IntervalConstraintImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

IntervalConstraintImpl::IntervalConstraintImpl(const IntervalConstraintImpl & obj): IntervalConstraintImpl()
{
	*this = obj;
}

IntervalConstraintImpl& IntervalConstraintImpl::operator=(const IntervalConstraintImpl & obj)
{
	//call overloaded =Operator for each base class
	ConstraintImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of IntervalConstraint 
	 * which is generated by the compiler (as IntervalConstraint is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//IntervalConstraint::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy IntervalConstraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> IntervalConstraintImpl::copy() const
{
	std::shared_ptr<IntervalConstraintImpl> element(new IntervalConstraintImpl());
	*element =(*this);
	element->setThisIntervalConstraintPtr(element);
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
std::weak_ptr<uml::Namespace> IntervalConstraintImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> IntervalConstraintImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> IntervalConstraintImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> IntervalConstraintImpl::eContainer() const
{
	if(auto wp = m_context.lock())
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

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void IntervalConstraintImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void IntervalConstraintImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ConstraintImpl::loadAttributes(loadHandler, attr_list);
}

void IntervalConstraintImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ConstraintImpl::loadNode(nodeName, loadHandler);
}

void IntervalConstraintImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ConstraintImpl::resolveReferences(featureID, references);
}

void IntervalConstraintImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ConstraintImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void IntervalConstraintImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> IntervalConstraintImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getIntervalConstraint_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any IntervalConstraintImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ConstraintImpl::eGet(featureID, resolve, coreType);
}

bool IntervalConstraintImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ConstraintImpl::internalEIsSet(featureID);
}

bool IntervalConstraintImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ConstraintImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any IntervalConstraintImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ConstraintImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::IntervalConstraint> IntervalConstraintImpl::getThisIntervalConstraintPtr() const
{
	return m_thisIntervalConstraintPtr.lock();
}
void IntervalConstraintImpl::setThisIntervalConstraintPtr(std::weak_ptr<uml::IntervalConstraint> thisIntervalConstraintPtr)
{
	m_thisIntervalConstraintPtr = thisIntervalConstraintPtr;
	setThisConstraintPtr(thisIntervalConstraintPtr);
}


