
#include "fUML/Semantics/Actions/impl/StructuralFeatureActionActivationImpl.hpp"

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


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"

//Includes from codegen annotation
#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "uml/Association.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/StructuredClassifiers/Link.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "uml/Property.hpp"
#include "uml/StructuralFeature.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Values/Value.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
StructuralFeatureActionActivationImpl::StructuralFeatureActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StructuralFeatureActionActivationImpl::~StructuralFeatureActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuralFeatureActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StructuralFeatureActionActivationImpl::StructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:StructuralFeatureActionActivationImpl()
{
	m_group = par_group;
}

StructuralFeatureActionActivationImpl::StructuralFeatureActionActivationImpl(const StructuralFeatureActionActivationImpl & obj): StructuralFeatureActionActivationImpl()
{
	*this = obj;
}

StructuralFeatureActionActivationImpl& StructuralFeatureActionActivationImpl::operator=(const StructuralFeatureActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of StructuralFeatureActionActivation 
	 * which is generated by the compiler (as StructuralFeatureActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//StructuralFeatureActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuralFeatureActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Association> StructuralFeatureActionActivationImpl::getAssociation(std::shared_ptr<uml::StructuralFeature> feature)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// If the structural feature for the action of this activation is an association end,
// then get the associated association.

std::shared_ptr<uml::Association> association = nullptr;
std::shared_ptr<uml::Property> property = std::dynamic_pointer_cast<uml::Property>(feature);

if(property != nullptr)
{
	association = property->getAssociation();
}

return association;
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link> > StructuralFeatureActionActivationImpl::getMatchingLinks(std::shared_ptr<uml::Association> association,std::shared_ptr<uml::StructuralFeature> end,std::shared_ptr<fUML::Semantics::Values::Value> oppositeValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the links of the given binary association whose end opposite
// to the given end has the given value

return getMatchingLinksForEndValue(association, end, oppositeValue, nullptr);
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link> > StructuralFeatureActionActivationImpl::getMatchingLinksForEndValue(std::shared_ptr<uml::Association> association,std::shared_ptr<uml::StructuralFeature> end,std::shared_ptr<fUML::Semantics::Values::Value> oppositeValue,std::shared_ptr<fUML::Semantics::Values::Value> endValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the links of the given binary association whose end opposite
// to the given end has the given opposite value and, optionally, that
// has a given end value for the given end.

std::shared_ptr<uml::Property> oppositeEnd = getOppositeEnd(association, end);

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> extent = this->getExecutionLocus()->retrieveExtent(association);

std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link>> links(new Bag<fUML::Semantics::StructuredClassifiers::Link>);
for(unsigned int i = 0; i < extent->size(); i++){
	std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> link = extent->at(i);
	if(link->retrieveFeatureValue(oppositeEnd)->getValues()->at(0) == oppositeValue) {
		bool matches = true;
		if(endValue != nullptr) {
			matches = (link->retrieveFeatureValue(end)->getValues()->at(0) == endValue);
		}
		
		if(matches){
			if(!(std::dynamic_pointer_cast<uml::MultiplicityElement>(end)->getIsOrdered()) || (links->size() == 0)){
				links->add(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link>(link));
			}
			else {
				unsigned int n = link->retrieveFeatureValue(end)->getPosition();
				bool continueSearching = true;
				unsigned int j = 0;
				while(continueSearching && (j < links->size())){
					j += 1;
					continueSearching = (unsigned int)(links->at(j-1)->retrieveFeatureValue(end)->getPosition()) < n;
				}
				if(continueSearching){
					links->add(std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link>(link));
				}
				else {
					links->insert((links->begin() + (j-1)), std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Link>(link));
				}
			}
		}
	}
}

return links;
	//end of body
}

std::shared_ptr<uml::Property> StructuralFeatureActionActivationImpl::getOppositeEnd(std::shared_ptr<uml::Association> association,std::shared_ptr<uml::StructuralFeature> end)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Get the end of a binary association opposite to the given end.

std::shared_ptr<uml::Property> oppositeEnd = association->getMemberEnd()->at(0);
if(oppositeEnd == end)
{
		oppositeEnd = association->getMemberEnd()->at(1);
}

return oppositeEnd;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> StructuralFeatureActionActivationImpl::getPinActivation() const
{
	if(m_pinActivation == nullptr)
	{
		/*Union*/
		m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::Semantics::Actions::PinActivation>()" << std::endl;
		#endif
		
		
	}
	return m_pinActivation;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> StructuralFeatureActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void StructuralFeatureActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void StructuralFeatureActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void StructuralFeatureActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void StructuralFeatureActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ActionActivationImpl::resolveReferences(featureID, references);
}

void StructuralFeatureActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void StructuralFeatureActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> StructuralFeatureActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getStructuralFeatureActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any StructuralFeatureActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool StructuralFeatureActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}

bool StructuralFeatureActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any StructuralFeatureActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// fUML::Semantics::Actions::StructuralFeatureActionActivation::getAssociation(uml::StructuralFeature) : uml::Association: 1275297557
		case ActionsPackage::STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETASSOCIATION_STRUCTURALFEATURE:
		{
			//Retrieve input parameter 'feature'
			//parameter 0
			std::shared_ptr<uml::StructuralFeature> incoming_param_feature;
			std::list<Any>::const_iterator incoming_param_feature_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_feature = (*incoming_param_feature_arguments_citer)->get<std::shared_ptr<uml::StructuralFeature> >();
			result = eAnyObject(this->getAssociation(incoming_param_feature), uml::umlPackage::ASSOCIATION_CLASS);
			break;
		}
		// fUML::Semantics::Actions::StructuralFeatureActionActivation::getMatchingLinks(uml::Association, uml::StructuralFeature, fUML::Semantics::Values::Value) : fUML::Semantics::StructuredClassifiers::Link[*]: 1331426136
		case ActionsPackage::STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKS_ASSOCIATION_VALUE:
		{
			//Retrieve input parameter 'association'
			//parameter 0
			std::shared_ptr<uml::Association> incoming_param_association;
			std::list<Any>::const_iterator incoming_param_association_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_association = (*incoming_param_association_arguments_citer)->get<std::shared_ptr<uml::Association> >();
			//Retrieve input parameter 'end'
			//parameter 1
			std::shared_ptr<uml::StructuralFeature> incoming_param_end;
			std::list<Any>::const_iterator incoming_param_end_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_end = (*incoming_param_end_arguments_citer)->get<std::shared_ptr<uml::StructuralFeature> >();
			//Retrieve input parameter 'oppositeValue'
			//parameter 2
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_oppositeValue;
			std::list<Any>::const_iterator incoming_param_oppositeValue_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_oppositeValue = (*incoming_param_oppositeValue_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link> > resultList = this->getMatchingLinks(incoming_param_association,incoming_param_end,incoming_param_oppositeValue);
			return eAnyBag(resultList,fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::LINK_CLASS);
			break;
		}
		// fUML::Semantics::Actions::StructuralFeatureActionActivation::getMatchingLinksForEndValue(uml::Association, uml::StructuralFeature, fUML::Semantics::Values::Value, fUML::Semantics::Values::Value) : fUML::Semantics::StructuredClassifiers::Link[*]: 1009305296
		case ActionsPackage::STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETMATCHINGLINKSFORENDVALUE_ASSOCIATION_VALUE:
		{
			//Retrieve input parameter 'association'
			//parameter 0
			std::shared_ptr<uml::Association> incoming_param_association;
			std::list<Any>::const_iterator incoming_param_association_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_association = (*incoming_param_association_arguments_citer)->get<std::shared_ptr<uml::Association> >();
			//Retrieve input parameter 'end'
			//parameter 1
			std::shared_ptr<uml::StructuralFeature> incoming_param_end;
			std::list<Any>::const_iterator incoming_param_end_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_end = (*incoming_param_end_arguments_citer)->get<std::shared_ptr<uml::StructuralFeature> >();
			//Retrieve input parameter 'oppositeValue'
			//parameter 2
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_oppositeValue;
			std::list<Any>::const_iterator incoming_param_oppositeValue_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_oppositeValue = (*incoming_param_oppositeValue_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			//Retrieve input parameter 'endValue'
			//parameter 3
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_endValue;
			std::list<Any>::const_iterator incoming_param_endValue_arguments_citer = std::next(arguments->begin(), 3);
			incoming_param_endValue = (*incoming_param_endValue_arguments_citer)->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Link> > resultList = this->getMatchingLinksForEndValue(incoming_param_association,incoming_param_end,incoming_param_oppositeValue,incoming_param_endValue);
			return eAnyBag(resultList,fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::LINK_CLASS);
			break;
		}
		// fUML::Semantics::Actions::StructuralFeatureActionActivation::getOppositeEnd(uml::Association, uml::StructuralFeature) : uml::Property: 1780438725
		case ActionsPackage::STRUCTURALFEATUREACTIONACTIVATION_OPERATION_GETOPPOSITEEND_ASSOCIATION_STRUCTURALFEATURE:
		{
			//Retrieve input parameter 'association'
			//parameter 0
			std::shared_ptr<uml::Association> incoming_param_association;
			std::list<Any>::const_iterator incoming_param_association_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_association = (*incoming_param_association_arguments_citer)->get<std::shared_ptr<uml::Association> >();
			//Retrieve input parameter 'end'
			//parameter 1
			std::shared_ptr<uml::StructuralFeature> incoming_param_end;
			std::list<Any>::const_iterator incoming_param_end_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_end = (*incoming_param_end_arguments_citer)->get<std::shared_ptr<uml::StructuralFeature> >();
			result = eAnyObject(this->getOppositeEnd(incoming_param_association,incoming_param_end), uml::umlPackage::PROPERTY_CLASS);
			break;
		}

		default:
		{
			// call superTypes
			result = ActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::Actions::StructuralFeatureActionActivation> StructuralFeatureActionActivationImpl::getThisStructuralFeatureActionActivationPtr() const
{
	return m_thisStructuralFeatureActionActivationPtr.lock();
}
void StructuralFeatureActionActivationImpl::setThisStructuralFeatureActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::StructuralFeatureActionActivation> thisStructuralFeatureActionActivationPtr)
{
	m_thisStructuralFeatureActionActivationPtr = thisStructuralFeatureActionActivationPtr;
	setThisActionActivationPtr(thisStructuralFeatureActionActivationPtr);
}


