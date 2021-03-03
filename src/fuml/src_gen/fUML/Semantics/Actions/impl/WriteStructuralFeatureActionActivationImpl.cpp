#include "fUML/Semantics/Actions/impl/WriteStructuralFeatureActionActivationImpl.hpp"

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
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Actions/StructuralFeatureActionActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
WriteStructuralFeatureActionActivationImpl::WriteStructuralFeatureActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

WriteStructuralFeatureActionActivationImpl::~WriteStructuralFeatureActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete WriteStructuralFeatureActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
WriteStructuralFeatureActionActivationImpl::WriteStructuralFeatureActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:WriteStructuralFeatureActionActivationImpl()
{
	m_group = par_group;
}

WriteStructuralFeatureActionActivationImpl::WriteStructuralFeatureActionActivationImpl(const WriteStructuralFeatureActionActivationImpl & obj): WriteStructuralFeatureActionActivationImpl()
{
	*this = obj;
}

WriteStructuralFeatureActionActivationImpl& WriteStructuralFeatureActionActivationImpl::operator=(const WriteStructuralFeatureActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuralFeatureActionActivationImpl::operator=(obj);
	WriteStructuralFeatureActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy WriteStructuralFeatureActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> WriteStructuralFeatureActionActivationImpl::copy() const
{
	std::shared_ptr<WriteStructuralFeatureActionActivationImpl> element(new WriteStructuralFeatureActionActivationImpl());
	*element =(*this);
	element->setThisWriteStructuralFeatureActionActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> WriteStructuralFeatureActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getWriteStructuralFeatureActionActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
int WriteStructuralFeatureActionActivationImpl::position(std::shared_ptr<fUML::Semantics::Values::Value> value,std::shared_ptr<Bag<fUML::Semantics::Values::Value>> list,int startAt)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return the position (counting from 1) of the first occurance of the given value in the
// given list at or after the starting index, or 0 if it is not found.

bool found = false;
unsigned int i = startAt;

while(!found && i<=list->size()) {
	found = (list->at(i-1) == value);
	i += 1;
}

if(!found){
	i = 1;
}

return i-1;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> WriteStructuralFeatureActionActivationImpl::getPinActivation() const
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




std::shared_ptr<WriteStructuralFeatureActionActivation> WriteStructuralFeatureActionActivationImpl::getThisWriteStructuralFeatureActionActivationPtr() const
{
	return m_thisWriteStructuralFeatureActionActivationPtr.lock();
}
void WriteStructuralFeatureActionActivationImpl::setThisWriteStructuralFeatureActionActivationPtr(std::weak_ptr<WriteStructuralFeatureActionActivation> thisWriteStructuralFeatureActionActivationPtr)
{
	m_thisWriteStructuralFeatureActionActivationPtr = thisWriteStructuralFeatureActionActivationPtr;
	setThisStructuralFeatureActionActivationPtr(thisWriteStructuralFeatureActionActivationPtr);
}
std::shared_ptr<ecore::EObject> WriteStructuralFeatureActionActivationImpl::eContainer() const
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
Any WriteStructuralFeatureActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return StructuralFeatureActionActivationImpl::eGet(featureID, resolve, coreType);
}
bool WriteStructuralFeatureActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return StructuralFeatureActionActivationImpl::internalEIsSet(featureID);
}
bool WriteStructuralFeatureActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return StructuralFeatureActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void WriteStructuralFeatureActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void WriteStructuralFeatureActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	StructuralFeatureActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void WriteStructuralFeatureActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	StructuralFeatureActionActivationImpl::loadNode(nodeName, loadHandler);
}

void WriteStructuralFeatureActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	StructuralFeatureActionActivationImpl::resolveReferences(featureID, references);
}

void WriteStructuralFeatureActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuralFeatureActionActivationImpl::saveContent(saveHandler);
	
	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void WriteStructuralFeatureActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

