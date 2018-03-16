#include "fUML/impl/ObjectNodeActivationImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "fUML/impl/FUMLPackageImpl.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/ObjectToken.hpp"
#include "fUML/Token.hpp"

//Forward declaration includes
#include "persistence/interface/XLoadHandler.hpp" // used for Persistence
#include "persistence/interface/XSaveHandler.hpp" // used for Persistence
#include "fUML/FUMLFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include <exception> // used in Persistence

#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivation.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/Token.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "fUML/FUMLPackage.hpp"
#include "fUML/FUMLFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
ObjectNodeActivationImpl::ObjectNodeActivationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References

	//Init references
}

ObjectNodeActivationImpl::~ObjectNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ObjectNodeActivationImpl::ObjectNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:ObjectNodeActivationImpl()
			{
			    m_group = par_group;
			}






ObjectNodeActivationImpl::ObjectNodeActivationImpl(const ObjectNodeActivationImpl & obj):ObjectNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_offeredTokenCount = obj.getOfferedTokenCount();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdges = obj.getIncomingEdges();
	m_incomingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getIncomingEdges().get())));

	m_node  = obj.getNode();

	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdges = obj.getOutgoingEdges();
	m_outgoingEdges.reset(new Bag<fUML::ActivityEdgeInstance>(*(obj.getOutgoingEdges().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ObjectNodeActivationImpl::copy() const
{
	std::shared_ptr<ObjectNodeActivationImpl> element(new ObjectNodeActivationImpl(*this));
	element->setThisObjectNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ObjectNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getObjectNodeActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ObjectNodeActivationImpl::setOfferedTokenCount(int _offeredTokenCount)
{
	m_offeredTokenCount = _offeredTokenCount;
} 

int ObjectNodeActivationImpl::getOfferedTokenCount() const 
{
	return m_offeredTokenCount;
}

//*********************************
// Operations
//*********************************
void ObjectNodeActivationImpl::addToken(std::shared_ptr<fUML::Token>  token) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (token->getValue() == nullptr) {
        token->withdraw();
    } else {
        ActivityNodeActivationImpl::addToken(token);
    }
	//end of body
}

void ObjectNodeActivationImpl::clearTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    ActivityNodeActivationImpl::clearTokens();
    this->setOfferedTokenCount(0);
	//end of body
}

int ObjectNodeActivationImpl::countOfferedValues() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		int totalValueCount = 0;
    unsigned int i = 0;
    while (i < this->getIncomingEdges()->size()) {
        totalValueCount = totalValueCount
                + this->getIncomingEdges()->at(i)->countOfferedValue();
        i = i + 1;
    }

    return totalValueCount;
	//end of body
}

int ObjectNodeActivationImpl::countUnofferedTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (this->getHeldTokens()->size() == 0) {
        this->setOfferedTokenCount(0);
    }

    return (this->getHeldTokens()->size() - this->getOfferedTokenCount());
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ObjectNodeActivationImpl::getUnofferedTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Token> > tokens(new Bag<fUML::Token>());

  int i = 0; 
  const int numberUnofferedTokens=this->countUnofferedTokens(); 
  int offeredTokenCount=this->getOfferedTokenCount(); 
 
  Bag<fUML::Token>* heldTokenPtr = this->getHeldTokens().get(); 
  if(nullptr!=heldTokenPtr) 
  { 
    while (i < numberUnofferedTokens) 
    { 
      tokens->push_back((*heldTokenPtr)[offeredTokenCount + i]);
      i++; 
    } 
  } 
  return tokens; 
	//end of body
}

int ObjectNodeActivationImpl::removeToken(std::shared_ptr<fUML::Token>  token) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    int i = ActivityNodeActivationImpl::removeToken(token);
    if (i > 0 && i <= this->getOfferedTokenCount()) {
        this->setOfferedTokenCount(this->getOfferedTokenCount() - 1);
    }

    return i;
	//end of body
}

void ObjectNodeActivationImpl::run() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    ActivityNodeActivationImpl::run();
    this->setOfferedTokenCount(0);
	//end of body
}

void ObjectNodeActivationImpl::sendOffers(std::shared_ptr<Bag<fUML::Token> >  tokens) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (tokens->size() == 0) 
	{
		std::shared_ptr<ObjectToken> token = fUML::FUMLFactory::eInstance()->createObjectToken();
		token->setHolder(getThisObjectNodeActivationPtr());
		token->setWithdrawn(false);
		tokens->push_back(token);
	}

	ActivityNodeActivationImpl::sendOffers(tokens);
	//end of body
}

void ObjectNodeActivationImpl::sendUnofferedTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<Token> > tokens = this->getUnofferedTokens();
    this->setOfferedTokenCount(this->getOfferedTokenCount() + tokens->size());
    this->sendOffers(tokens);
	//end of body
}

std::shared_ptr<Bag<fUML::Token> > ObjectNodeActivationImpl::takeUnofferedTokens() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<fUML::Token> > tokens = this->getUnofferedTokens();
    for (unsigned int i = 0; i < tokens->size(); i++) 
    {
    	std::shared_ptr<Token> token = tokens->at(i);
        token->withdraw();
    }
    return tokens;
	//end of body
}

void ObjectNodeActivationImpl::terminate() 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    this->clearTokens();
    ActivityNodeActivationImpl::terminate();
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<ObjectNodeActivation> ObjectNodeActivationImpl::getThisObjectNodeActivationPtr()
{
	return m_thisObjectNodeActivationPtr.lock();
}
void ObjectNodeActivationImpl::setThisObjectNodeActivationPtr(std::weak_ptr<ObjectNodeActivation> thisObjectNodeActivationPtr)
{
	m_thisObjectNodeActivationPtr = thisObjectNodeActivationPtr;
	setThisActivityNodeActivationPtr(thisObjectNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> ObjectNodeActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ObjectNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //596
	}
	return ActivityNodeActivationImpl::internalEIsSet(featureID);
}
bool ObjectNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount() != 0; //596
	}
	return ActivityNodeActivationImpl::internalEIsSet(featureID);
}
bool ObjectNodeActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
		{
			// BOOST CAST
			int _offeredTokenCount = boost::any_cast<int>(newValue);
			setOfferedTokenCount(_offeredTokenCount); //596
			return true;
		}
	}

	return ActivityNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ObjectNodeActivationImpl::load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get FUMLFactory
	std::shared_ptr<fUML::FUMLFactory> modelFactory = fUML::FUMLFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
	}
}		

void ObjectNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("offeredTokenCount");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream ( iter->second ) >> value;
			this->setOfferedTokenCount(value);
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

	ActivityNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory)
{


	ActivityNodeActivationImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ObjectNodeActivationImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	ActivityNodeActivationImpl::resolveReferences(featureID, references);
}

void ObjectNodeActivationImpl::save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ObjectNodeActivationImpl::saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::FUMLPackage> package = fUML::FUMLPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getObjectNodeActivation_EAttribute_offeredTokenCount()) )
		{
			saveHandler->addAttribute("offeredTokenCount", this->getOfferedTokenCount());
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

