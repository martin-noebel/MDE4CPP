#include "fUML/impl/DataStoreNodeActivationImpl.hpp"

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
#include "fuml/Value.hpp"

//Forward declaration includes
#include "fUML/ActivityEdgeInstance.hpp"

#include "uml/ActivityNode.hpp"

#include "fUML/ActivityNodeActivationGroup.hpp"

#include "fUML/CentralBufferNodeActivation.hpp"

#include "fUML/Token.hpp"


using namespace fUML;

//*********************************
// Constructor / Destructor
//*********************************
DataStoreNodeActivationImpl::DataStoreNodeActivationImpl()
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

DataStoreNodeActivationImpl::~DataStoreNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DataStoreNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			DataStoreNodeActivationImpl::DataStoreNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group)
			:DataStoreNodeActivationImpl()
			{
			    m_group = par_group;
			}






DataStoreNodeActivationImpl::DataStoreNodeActivationImpl(const DataStoreNodeActivationImpl & obj):DataStoreNodeActivationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DataStoreNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_offeredTokenCount = obj.getOfferedTokenCount();
	m_running = obj.isRunning();

	//copy references with no containment (soft copy)
	
	m_group  = obj.getGroup();

	m_node  = obj.getNode();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<fUML::Token>> _heldTokensList = obj.getHeldTokens();
	for(std::shared_ptr<fUML::Token> _heldTokens : *_heldTokensList)
	{
		this->getHeldTokens()->add(std::shared_ptr<fUML::Token>(std::dynamic_pointer_cast<fUML::Token>(_heldTokens->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_heldTokens" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _incomingEdgesList = obj.getIncomingEdges();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _incomingEdges : *_incomingEdgesList)
	{
		this->getIncomingEdges()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_incomingEdges->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_incomingEdges" << std::endl;
	#endif
	std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> _outgoingEdgesList = obj.getOutgoingEdges();
	for(std::shared_ptr<fUML::ActivityEdgeInstance> _outgoingEdges : *_outgoingEdgesList)
	{
		this->getOutgoingEdges()->add(std::shared_ptr<fUML::ActivityEdgeInstance>(std::dynamic_pointer_cast<fUML::ActivityEdgeInstance>(_outgoingEdges->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_outgoingEdges" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  DataStoreNodeActivationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new DataStoreNodeActivationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> DataStoreNodeActivationImpl::eStaticClass() const
{
	return FUMLPackageImpl::eInstance()->getDataStoreNodeActivation_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void DataStoreNodeActivationImpl::addToken(std::shared_ptr<fUML::Token>  token) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Value>value = token->getValue();
		
		bool isUnique = true;
		if (value != nullptr) {
			std::shared_ptr<Bag<fUML::Token> > heldTokens = this->getTokens();
			unsigned int i = 0;
			while (isUnique && i < heldTokens->size()) {
				isUnique = !(heldTokens->at(i)->getValue()->equals(value));
				i++;
			}
		}
		
		if (isUnique) {
			ObjectNodeActivationImpl::addToken(token);
		}
	//end of body
}

int DataStoreNodeActivationImpl::removeToken(std::shared_ptr<fUML::Token>  token) 
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	int i = ObjectNodeActivationImpl::removeToken(token);
		
		if (this->isRunning()) {
			std::shared_ptr<Token> copied_token = std::dynamic_pointer_cast<Token>(token->copy());
			ObjectNodeActivationImpl::addToken(copied_token);
			this->sendUnofferedTokens();
		}
		return i;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************


std::shared_ptr<DataStoreNodeActivation> DataStoreNodeActivationImpl::getThisDataStoreNodeActivationPtr()
{
	if(auto wp = m_group.lock())
	{
		std::shared_ptr<Bag<fUML::ActivityNodeActivation>> ownersDataStoreNodeActivationList = wp->getNodeActivations();
		for (std::shared_ptr<fUML::ActivityNodeActivation> anDataStoreNodeActivation : *ownersDataStoreNodeActivationList)
		{
			if (anDataStoreNodeActivation.get() == this)
			{
				return std::dynamic_pointer_cast<DataStoreNodeActivation>(anDataStoreNodeActivation );
			}
		}
	}
	struct null_deleter{void operator()(void const *) const {}};
	return std::shared_ptr<DataStoreNodeActivation>(this, null_deleter());
}
std::shared_ptr<ecore::EObject> DataStoreNodeActivationImpl::eContainer() const
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
boost::any DataStoreNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
			return getGroup(); //1133
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_HELDTOKENS:
			return getHeldTokens(); //1132
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_INCOMINGEDGES:
			return getIncomingEdges(); //1131
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
			return getNode(); //1134
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
			return getOfferedTokenCount(); //1136
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_OUTGOINGEDGES:
			return getOutgoingEdges(); //1130
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
			return isRunning(); //1135
	}
	return boost::any();
}

void DataStoreNodeActivationImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_GROUP:
		{
			// BOOST CAST
			std::shared_ptr<fUML::ActivityNodeActivationGroup> _group = boost::any_cast<std::shared_ptr<fUML::ActivityNodeActivationGroup>>(newValue);
			setGroup(_group); //1133
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EREFERENCE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ActivityNode> _node = boost::any_cast<std::shared_ptr<uml::ActivityNode>>(newValue);
			setNode(_node); //1134
			break;
		}
		case FUMLPackage::OBJECTNODEACTIVATION_EATTRIBUTE_OFFEREDTOKENCOUNT:
		{
			// BOOST CAST
			int _offeredTokenCount = boost::any_cast<int>(newValue);
			setOfferedTokenCount(_offeredTokenCount); //1136
			break;
		}
		case FUMLPackage::ACTIVITYNODEACTIVATION_EATTRIBUTE_RUNNING:
		{
			// BOOST CAST
			bool _running = boost::any_cast<bool>(newValue);
			setRunning(_running); //1135
			break;
		}
	}
}
