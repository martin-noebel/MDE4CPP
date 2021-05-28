#include "ocl/Expressions/impl/FeatureCallExpImpl.hpp"

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
#include "ecore/EcoreFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"


#include "ocl/Expressions/CallExp.hpp"
#include "ocl/Expressions/CollectionRange.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ocl/Expressions/ExpressionInOcl.hpp"
#include "ocl/Expressions/IfExp.hpp"
#include "ocl/Expressions/LoopExp.hpp"
#include "ocl/Expressions/NavigationCallExp.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/OperationCallExp.hpp"
#include "ocl/Expressions/Variable.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
FeatureCallExpImpl::FeatureCallExpImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

FeatureCallExpImpl::~FeatureCallExpImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FeatureCallExp "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
FeatureCallExpImpl::FeatureCallExpImpl(std::weak_ptr<ocl::Expressions::CallExp> par_appliedElement)
:FeatureCallExpImpl()
{
	m_appliedElement = par_appliedElement;
}

//Additional constructor for the containments back reference
FeatureCallExpImpl::FeatureCallExpImpl(std::weak_ptr<ocl::Expressions::IfExp> par_IfExp, const int reference_id)
:FeatureCallExpImpl()
{
	switch(reference_id)
	{	
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_ELSEOWNER:
		m_elseOwner = par_IfExp;
		 return;
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_IFOWNER:
		m_ifOwner = par_IfExp;
		 return;
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_THENOWNER:
		m_thenOwner = par_IfExp;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
FeatureCallExpImpl::FeatureCallExpImpl(std::weak_ptr<ocl::Expressions::CollectionRange> par_CollectionRange, const int reference_id)
:FeatureCallExpImpl()
{
	switch(reference_id)
	{	
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_FIRSTOWNER:
		m_firstOwner = par_CollectionRange;
		 return;
	case ocl::Expressions::ExpressionsPackage::OCLEXPRESSION_ATTRIBUTE_LASTOWNER:
		m_lastOwner = par_CollectionRange;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
FeatureCallExpImpl::FeatureCallExpImpl(std::weak_ptr<ocl::Expressions::Variable> par_initializedElement)
:FeatureCallExpImpl()
{
	m_initializedElement = par_initializedElement;
}


//Additional constructor for the containments back reference
FeatureCallExpImpl::FeatureCallExpImpl(std::weak_ptr<ocl::Expressions::LoopExp> par_loopBodyOwner)
:FeatureCallExpImpl()
{
	m_loopBodyOwner = par_loopBodyOwner;
}

//Additional constructor for the containments back reference
FeatureCallExpImpl::FeatureCallExpImpl(std::weak_ptr<ocl::Expressions::OperationCallExp> par_parentCall)
:FeatureCallExpImpl()
{
	m_parentCall = par_parentCall;
}

//Additional constructor for the containments back reference
FeatureCallExpImpl::FeatureCallExpImpl(std::weak_ptr<ocl::Expressions::NavigationCallExp> par_parentNav)
:FeatureCallExpImpl()
{
	m_parentNav = par_parentNav;
}


//Additional constructor for the containments back reference
FeatureCallExpImpl::FeatureCallExpImpl(std::weak_ptr<ocl::Expressions::ExpressionInOcl> par_topExpression)
:FeatureCallExpImpl()
{
	m_topExpression = par_topExpression;
}

FeatureCallExpImpl::FeatureCallExpImpl(const FeatureCallExpImpl & obj): FeatureCallExpImpl()
{
	*this = obj;
}

FeatureCallExpImpl& FeatureCallExpImpl::operator=(const FeatureCallExpImpl & obj)
{
	//call overloaded =Operator for each base class
	CallExpImpl::operator=(obj);
	FeatureCallExp::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy FeatureCallExp "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isPre = obj.getIsPre();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> FeatureCallExpImpl::copy() const
{
	std::shared_ptr<FeatureCallExpImpl> element(new FeatureCallExpImpl());
	*element =(*this);
	element->setThisFeatureCallExpPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> FeatureCallExpImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getFeatureCallExp_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isPre
*/
bool FeatureCallExpImpl::getIsPre() const 
{
	return m_isPre;
}
void FeatureCallExpImpl::setIsPre(bool _isPre)
{
	m_isPre = _isPre;
} 


//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<FeatureCallExp> FeatureCallExpImpl::getThisFeatureCallExpPtr() const
{
	return m_thisFeatureCallExpPtr.lock();
}
void FeatureCallExpImpl::setThisFeatureCallExpPtr(std::weak_ptr<FeatureCallExp> thisFeatureCallExpPtr)
{
	m_thisFeatureCallExpPtr = thisFeatureCallExpPtr;
	setThisCallExpPtr(thisFeatureCallExpPtr);
}
std::shared_ptr<ecore::EObject> FeatureCallExpImpl::eContainer() const
{
	if(auto wp = m_appliedElement.lock())
	{
		return wp;
	}

	if(auto wp = m_elseOwner.lock())
	{
		return wp;
	}
	if(auto wp = m_ifOwner.lock())
	{
		return wp;
	}
	if(auto wp = m_thenOwner.lock())
	{
		return wp;
	}

	if(auto wp = m_firstOwner.lock())
	{
		return wp;
	}
	if(auto wp = m_lastOwner.lock())
	{
		return wp;
	}


	if(auto wp = m_initializedElement.lock())
	{
		return wp;
	}


	if(auto wp = m_loopBodyOwner.lock())
	{
		return wp;
	}

	if(auto wp = m_parentCall.lock())
	{
		return wp;
	}

	if(auto wp = m_parentNav.lock())
	{
		return wp;
	}


	if(auto wp = m_topExpression.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any FeatureCallExpImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::FEATURECALLEXP_ATTRIBUTE_ISPRE:
			return eAny(getIsPre()); //2923
	}
	return CallExpImpl::eGet(featureID, resolve, coreType);
}
bool FeatureCallExpImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::FEATURECALLEXP_ATTRIBUTE_ISPRE:
			return getIsPre() != false; //2923
	}
	return CallExpImpl::internalEIsSet(featureID);
}
bool FeatureCallExpImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::FEATURECALLEXP_ATTRIBUTE_ISPRE:
		{
			// BOOST CAST
			bool _isPre = newValue->get<bool>();
			setIsPre(_isPre); //2923
			return true;
		}
	}

	return CallExpImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void FeatureCallExpImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void FeatureCallExpImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isPre");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsPre(value);
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

	CallExpImpl::loadAttributes(loadHandler, attr_list);
}

void FeatureCallExpImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CallExpImpl::loadNode(nodeName, loadHandler);
}

void FeatureCallExpImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	CallExpImpl::resolveReferences(featureID, references);
}

void FeatureCallExpImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CallExpImpl::saveContent(saveHandler);
	
	OclExpressionImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void FeatureCallExpImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getFeatureCallExp_Attribute_isPre()) )
		{
			saveHandler->addAttribute("isPre", this->getIsPre());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}
