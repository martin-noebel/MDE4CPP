#include "uml/impl/RegionImpl.hpp"

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
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/UmlFactory.hpp"


#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/Region.hpp"
#include "uml/State.hpp"
#include "uml/StateMachine.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Transition.hpp"
#include "uml/Vertex.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
RegionImpl::RegionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

RegionImpl::~RegionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Region "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
RegionImpl::RegionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:RegionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
RegionImpl::RegionImpl(std::weak_ptr<uml::Element> par_owner)
:RegionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
RegionImpl::RegionImpl(std::weak_ptr<uml::State> par_state)
:RegionImpl()
{
	m_state = par_state;
	m_namespace = par_state;
}

//Additional constructor for the containments back reference
RegionImpl::RegionImpl(std::weak_ptr<uml::StateMachine> par_stateMachine)
:RegionImpl()
{
	m_stateMachine = par_stateMachine;
	m_namespace = par_stateMachine;
}

RegionImpl::RegionImpl(const RegionImpl & obj): RegionImpl()
{
	*this = obj;
}

RegionImpl& RegionImpl::operator=(const RegionImpl & obj)
{
	//call overloaded =Operator for each base class
	NamespaceImpl::operator=(obj);
	RedefinableElementImpl::operator=(obj);
	Region::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Region "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_state  = obj.getState();
	m_stateMachine  = obj.getStateMachine();
	//Clone references with containment (deep copy)
	if(obj.getExtendedRegion()!=nullptr)
	{
		m_extendedRegion = std::dynamic_pointer_cast<uml::Region>(obj.getExtendedRegion()->copy());
	}
	std::shared_ptr<Subset<uml::Vertex, uml::NamedElement>> subvertexContainer = getSubvertex();
	if(nullptr != subvertexContainer )
	{
		int size = subvertexContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _subvertex=(*subvertexContainer)[i];
			if(nullptr != _subvertex)
			{
				subvertexContainer->push_back(std::dynamic_pointer_cast<uml::Vertex>(_subvertex->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container subvertex."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr subvertex."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Transition, uml::NamedElement>> transitionContainer = getTransition();
	if(nullptr != transitionContainer )
	{
		int size = transitionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _transition=(*transitionContainer)[i];
			if(nullptr != _transition)
			{
				transitionContainer->push_back(std::dynamic_pointer_cast<uml::Transition>(_transition->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container transition."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr transition."<< std::endl;)
	}
	/*Subset*/
	m_subvertex->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_transition->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> RegionImpl::copy() const
{
	std::shared_ptr<RegionImpl> element(new RegionImpl());
	*element =(*this);
	element->setThisRegionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> RegionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getRegion_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool RegionImpl::belongsToPSM()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::StateMachine> RegionImpl::containingStateMachine()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RegionImpl::deep_history_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RegionImpl::initial_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RegionImpl::owned(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Classifier> RegionImpl::redefinitionContext()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool RegionImpl::shallow_history_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference extendedRegion
*/
std::shared_ptr<uml::Region> RegionImpl::getExtendedRegion() const
{

    return m_extendedRegion;
}
void RegionImpl::setExtendedRegion(std::shared_ptr<uml::Region> _extendedRegion)
{
    m_extendedRegion = _extendedRegion;
}


/*
Getter & Setter for reference state
*/
std::weak_ptr<uml::State> RegionImpl::getState() const
{

    return m_state;
}
void RegionImpl::setState(std::weak_ptr<uml::State> _state)
{
    m_state = _state;
}


/*
Getter & Setter for reference stateMachine
*/
std::weak_ptr<uml::StateMachine> RegionImpl::getStateMachine() const
{

    return m_stateMachine;
}
void RegionImpl::setStateMachine(std::weak_ptr<uml::StateMachine> _stateMachine)
{
    m_stateMachine = _stateMachine;
}


/*
Getter & Setter for reference subvertex
*/
std::shared_ptr<Subset<uml::Vertex, uml::NamedElement>> RegionImpl::getSubvertex() const
{
	if(m_subvertex == nullptr)
	{
		/*Subset*/
		m_subvertex.reset(new Subset<uml::Vertex, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_subvertex->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_subvertex - Subset<uml::Vertex, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_subvertex;
}



/*
Getter & Setter for reference transition
*/
std::shared_ptr<Subset<uml::Transition, uml::NamedElement>> RegionImpl::getTransition() const
{
	if(m_transition == nullptr)
	{
		/*Subset*/
		m_transition.reset(new Subset<uml::Transition, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_transition->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_transition - Subset<uml::Transition, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_transition;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> RegionImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> RegionImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> RegionImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> RegionImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> RegionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> RegionImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<Region> RegionImpl::getThisRegionPtr() const
{
	return m_thisRegionPtr.lock();
}
void RegionImpl::setThisRegionPtr(std::weak_ptr<Region> thisRegionPtr)
{
	m_thisRegionPtr = thisRegionPtr;
	setThisNamespacePtr(thisRegionPtr);
	setThisRedefinableElementPtr(thisRegionPtr);
}
std::shared_ptr<ecore::EObject> RegionImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_state.lock())
	{
		return wp;
	}

	if(auto wp = m_stateMachine.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any RegionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::REGION_ATTRIBUTE_EXTENDEDREGION:
			return eAny(getExtendedRegion()); //20718
		case uml::umlPackage::REGION_ATTRIBUTE_STATE:
			return eAny(getState().lock()); //20719
		case uml::umlPackage::REGION_ATTRIBUTE_STATEMACHINE:
			return eAny(getStateMachine().lock()); //20720
		case uml::umlPackage::REGION_ATTRIBUTE_SUBVERTEX:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Vertex>::iterator iter = m_subvertex->begin();
			Bag<uml::Vertex>::iterator end = m_subvertex->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //20722			
		}
		case uml::umlPackage::REGION_ATTRIBUTE_TRANSITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Transition>::iterator iter = m_transition->begin();
			Bag<uml::Transition>::iterator end = m_transition->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //20721			
		}
	}
	Any result;
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = RedefinableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool RegionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::REGION_ATTRIBUTE_EXTENDEDREGION:
			return getExtendedRegion() != nullptr; //20718
		case uml::umlPackage::REGION_ATTRIBUTE_STATE:
			return getState().lock() != nullptr; //20719
		case uml::umlPackage::REGION_ATTRIBUTE_STATEMACHINE:
			return getStateMachine().lock() != nullptr; //20720
		case uml::umlPackage::REGION_ATTRIBUTE_SUBVERTEX:
			return getSubvertex() != nullptr; //20722
		case uml::umlPackage::REGION_ATTRIBUTE_TRANSITION:
			return getTransition() != nullptr; //20721
	}
	bool result = false;
	result = NamespaceImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::internalEIsSet(featureID);
	return result;
}
bool RegionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::REGION_ATTRIBUTE_EXTENDEDREGION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Region> _extendedRegion = std::dynamic_pointer_cast<uml::Region>(_temp);
			setExtendedRegion(_extendedRegion); //20718
			return true;
		}
		case uml::umlPackage::REGION_ATTRIBUTE_STATE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>(_temp);
			setState(_state); //20719
			return true;
		}
		case uml::umlPackage::REGION_ATTRIBUTE_STATEMACHINE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StateMachine> _stateMachine = std::dynamic_pointer_cast<uml::StateMachine>(_temp);
			setStateMachine(_stateMachine); //20720
			return true;
		}
		case uml::umlPackage::REGION_ATTRIBUTE_SUBVERTEX:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Vertex>> subvertexList(new Bag<uml::Vertex>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				subvertexList->add(std::dynamic_pointer_cast<uml::Vertex>(*iter));
				iter++;
			}
			
			Bag<uml::Vertex>::iterator iterSubvertex = m_subvertex->begin();
			Bag<uml::Vertex>::iterator endSubvertex = m_subvertex->end();
			while (iterSubvertex != endSubvertex)
			{
				if (subvertexList->find(*iterSubvertex) == -1)
				{
					m_subvertex->erase(*iterSubvertex);
				}
				iterSubvertex++;
			}
 
			iterSubvertex = subvertexList->begin();
			endSubvertex = subvertexList->end();
			while (iterSubvertex != endSubvertex)
			{
				if (m_subvertex->find(*iterSubvertex) == -1)
				{
					m_subvertex->add(*iterSubvertex);
				}
				iterSubvertex++;			
			}
			return true;
		}
		case uml::umlPackage::REGION_ATTRIBUTE_TRANSITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Transition>> transitionList(new Bag<uml::Transition>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				transitionList->add(std::dynamic_pointer_cast<uml::Transition>(*iter));
				iter++;
			}
			
			Bag<uml::Transition>::iterator iterTransition = m_transition->begin();
			Bag<uml::Transition>::iterator endTransition = m_transition->end();
			while (iterTransition != endTransition)
			{
				if (transitionList->find(*iterTransition) == -1)
				{
					m_transition->erase(*iterTransition);
				}
				iterTransition++;
			}
 
			iterTransition = transitionList->begin();
			endTransition = transitionList->end();
			while (iterTransition != endTransition)
			{
				if (m_transition->find(*iterTransition) == -1)
				{
					m_transition->add(*iterTransition);
				}
				iterTransition++;			
			}
			return true;
		}
	}

	bool result = false;
	result = NamespaceImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any RegionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 20801
		case umlPackage::REGION_OPERATION_BELONGSTOPSM:
		{
			result = eAny(this->belongsToPSM());
			break;
		}
		
		// 20802
		case umlPackage::REGION_OPERATION_CONTAININGSTATEMACHINE:
		{
			result = eAny(this->containingStateMachine());
			break;
		}
		
		// 20797
		case umlPackage::REGION_OPERATION_DEEP_HISTORY_VERTEX_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->deep_history_vertex(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 20800
		case umlPackage::REGION_OPERATION_INITIAL_VERTEX_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->initial_vertex(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 20799
		case umlPackage::REGION_OPERATION_OWNED_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->owned(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 20803
		case umlPackage::REGION_OPERATION_REDEFINITIONCONTEXT:
		{
			result = eAny(this->redefinitionContext());
			break;
		}
		
		// 20798
		case umlPackage::REGION_OPERATION_SHALLOW_HISTORY_VERTEX_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->shallow_history_vertex(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = RedefinableElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = NamespaceImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void RegionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void RegionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("extendedRegion");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("extendedRegion")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamespaceImpl::loadAttributes(loadHandler, attr_list);
	RedefinableElementImpl::loadAttributes(loadHandler, attr_list);
}

void RegionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("subvertex") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::Vertex>(this->getSubvertex());  

			return; 
		}

		if ( nodeName.compare("transition") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Transition";
			}
			loadHandler->handleChildContainer<uml::Transition>(this->getTransition());  

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
	NamespaceImpl::loadNode(nodeName, loadHandler);
	RedefinableElementImpl::loadNode(nodeName, loadHandler);
}

void RegionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::REGION_ATTRIBUTE_EXTENDEDREGION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Region> _extendedRegion = std::dynamic_pointer_cast<uml::Region>( references.front() );
				setExtendedRegion(_extendedRegion);
			}
			
			return;
		}

		case uml::umlPackage::REGION_ATTRIBUTE_STATE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>( references.front() );
				setState(_state);
			}
			
			return;
		}

		case uml::umlPackage::REGION_ATTRIBUTE_STATEMACHINE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StateMachine> _stateMachine = std::dynamic_pointer_cast<uml::StateMachine>( references.front() );
				setStateMachine(_stateMachine);
			}
			
			return;
		}
	}
	NamespaceImpl::resolveReferences(featureID, references);
	RedefinableElementImpl::resolveReferences(featureID, references);
}

void RegionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void RegionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'subvertex'
		for (std::shared_ptr<uml::Vertex> subvertex : *this->getSubvertex()) 
		{
			saveHandler->addReference(subvertex, "subvertex", subvertex->eClass() != package->getVertex_Class());
		}

		// Save 'transition'
		for (std::shared_ptr<uml::Transition> transition : *this->getTransition()) 
		{
			saveHandler->addReference(transition, "transition", transition->eClass() != package->getTransition_Class());
		}
	// Add references
		saveHandler->addReference(this->getExtendedRegion(), "extendedRegion", getExtendedRegion()->eClass() != uml::umlPackage::eInstance()->getRegion_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

