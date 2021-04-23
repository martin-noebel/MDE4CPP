#include "fUML/Semantics/StructuredClassifiers/impl/ObjectImpl.hpp"

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
#include "fUML/Semantics/StructuredClassifiers/DispatchStrategy.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "uml/umlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "fUML/Semantics/CommonBehavior/EventAccepter.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/StructuredClassifiers/ExtensionalValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "uml/Operation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/SimpleClassifiers/SignalInstance.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
ObjectImpl::ObjectImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ObjectImpl::~ObjectImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Object "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ObjectImpl::ObjectImpl(const ObjectImpl & obj): ObjectImpl()
{
	*this = obj;
}

ObjectImpl& ObjectImpl::operator=(const ObjectImpl & obj)
{
	//call overloaded =Operator for each base class
	ExtensionalValueImpl::operator=(obj);
	Object::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Object "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Classifier>> _types = obj.getTypes();
	m_types.reset(new Bag<uml::Classifier>(*(obj.getTypes().get())));
	//Clone references with containment (deep copy)
	if(obj.getObjectActivation()!=nullptr)
	{
		m_objectActivation = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(obj.getObjectActivation()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ObjectImpl::copy() const
{
	std::shared_ptr<ObjectImpl> element(new ObjectImpl());
	*element =(*this);
	element->setThisObjectPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ObjectImpl::eStaticClass() const
{
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getObject_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> ObjectImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new object that is a copy of this object at the same locus as this object.
// However, the new object will NOT have any object activation (i.e, its classifier behaviors will not be started).

std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> newObject = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::Object>(fUML::Semantics::StructuredClassifiers::ExtensionalValueImpl::_copy());

std::shared_ptr<Bag<uml::Classifier>> types = this->getTypes();
unsigned int typesSize = types->size();

for(unsigned int i = 0; i < typesSize; i++)
{
	std::shared_ptr<uml::Classifier> type = types->at(i);
	newObject->getTypes()->add(type);
}

return newObject;
	//end of body
}

void ObjectImpl::_register(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> accepter)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->_register(accepter);
    }
	//end of body
}

void ObjectImpl::destroy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if(this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->stop();
        this->setObjectActivation(nullptr);
    }

    this->getTypes()->clear();
    fUML::Semantics::StructuredClassifiers::ExtensionalValueImpl::destroy();
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> ObjectImpl::dispatch(std::shared_ptr<uml::Operation> operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	static std::shared_ptr<fUML::Semantics::StructuredClassifiers::DispatchStrategy> strategy = std::dynamic_pointer_cast<fUML::Semantics::StructuredClassifiers::DispatchStrategy>(this->getLocus()->getFactory()->getStrategy("dispatch"));
	return strategy->dispatch(getThisObjectPtr(), operation);
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> ObjectImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createObject();
	//end of body
}

void ObjectImpl::send(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> signalInstance)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->send(signalInstance);
    }
	//end of body
}

void ObjectImpl::send(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	
	//end of body
}

void ObjectImpl::startBehavior(std::shared_ptr<uml::Class> classifier,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputs)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if(this->getObjectActivation() == nullptr) 
    {
        this->setObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation>(fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createObjectActivation()));
        this->getObjectActivation()->setObject(getThisObjectPtr());
    }

    this->getObjectActivation()->startBehavior(classifier, inputs);
	//end of body
}

void ObjectImpl::unregister(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> accepter)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if( this->getObjectActivation() != nullptr)
    {
        this->getObjectActivation()->unregister(accepter);
    }
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference objectActivation
*/
std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> ObjectImpl::getObjectActivation() const
{

    return m_objectActivation;
}
void ObjectImpl::setObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> _objectActivation)
{
    m_objectActivation = _objectActivation;
}


/*
Getter & Setter for reference types
*/
std::shared_ptr<Bag<uml::Classifier>> ObjectImpl::getTypes() const
{
	if(m_types == nullptr)
	{
		m_types.reset(new Bag<uml::Classifier>());
		
		
	}

    return m_types;
}



//*********************************
// Union Getter
//*********************************



std::shared_ptr<Object> ObjectImpl::getThisObjectPtr() const
{
	return m_thisObjectPtr.lock();
}
void ObjectImpl::setThisObjectPtr(std::weak_ptr<Object> thisObjectPtr)
{
	m_thisObjectPtr = thisObjectPtr;
	setThisExtensionalValuePtr(thisObjectPtr);
}
std::shared_ptr<ecore::EObject> ObjectImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ObjectImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_OBJECTACTIVATION:
			return eAny(getObjectActivation()); //803
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_TYPES:
		{
			return eAny(getTypes()); //802			
		}
	}
	return ExtensionalValueImpl::eGet(featureID, resolve, coreType);
}
bool ObjectImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_OBJECTACTIVATION:
			return getObjectActivation() != nullptr; //803
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_TYPES:
			return getTypes() != nullptr; //802
	}
	return ExtensionalValueImpl::internalEIsSet(featureID);
}
bool ObjectImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_OBJECTACTIVATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> _objectActivation = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::ObjectActivation>(_temp);
			setObjectActivation(_objectActivation); //803
			return true;
		}
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_TYPES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> typesList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				typesList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterTypes = m_types->begin();
			Bag<uml::Classifier>::iterator endTypes = m_types->end();
			while (iterTypes != endTypes)
			{
				if (typesList->find(*iterTypes) == -1)
				{
					m_types->erase(*iterTypes);
				}
				iterTypes++;
			}
 
			iterTypes = typesList->begin();
			endTypes = typesList->end();
			while (iterTypes != endTypes)
			{
				if (m_types->find(*iterTypes) == -1)
				{
					m_types->add(*iterTypes);
				}
				iterTypes++;			
			}
			return true;
		}
	}

	return ExtensionalValueImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ObjectImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 8039
		case StructuredClassifiersPackage::OBJECT_OPERATION__COPY:
		{
			result = eAny(this->_copy());
			break;
		}
		
		// 8034
		case StructuredClassifiersPackage::OBJECT_OPERATION__REGISTER_EVENTACCEPTER:
		{
			//Retrieve input parameter 'accepter'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> incoming_param_accepter;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_accepter_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_accepter = (*incoming_param_accepter_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> >();
			this->_register(incoming_param_accepter);
			break;
		}
		
		// 8037
		case StructuredClassifiersPackage::OBJECT_OPERATION_DESTROY:
		{
			this->destroy();
			break;
		}
		
		// 8032
		case StructuredClassifiersPackage::OBJECT_OPERATION_DISPATCH_OPERATION:
		{
			//Retrieve input parameter 'operation'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_operation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_operation = (*incoming_param_operation_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			result = eAny(this->dispatch(incoming_param_operation));
			break;
		}
		
		// 8036
		case StructuredClassifiersPackage::OBJECT_OPERATION_NEW_:
		{
			result = eAny(this->new_());
			break;
		}
		
		// 8033
		case StructuredClassifiersPackage::OBJECT_OPERATION_SEND_SIGNALINSTANCE:
		{
			//Retrieve input parameter 'signalInstance'
			//parameter 0
			std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> incoming_param_signalInstance;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_signalInstance_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_signalInstance = (*incoming_param_signalInstance_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> >();
			this->send(incoming_param_signalInstance);
			break;
		}
		
		// 8038
		case StructuredClassifiersPackage::OBJECT_OPERATION_SEND_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurrence = (*incoming_param_eventOccurrence_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			this->send(incoming_param_eventOccurrence);
			break;
		}
		
		// 8031
		case StructuredClassifiersPackage::OBJECT_OPERATION_STARTBEHAVIOR_CLASS_PARAMETERVALUE:
		{
			//Retrieve input parameter 'classifier'
			//parameter 0
			std::shared_ptr<uml::Class> incoming_param_classifier;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_classifier_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_classifier = (*incoming_param_classifier_arguments_citer)->get()->get<std::shared_ptr<uml::Class> >();
			//Retrieve input parameter 'inputs'
			//parameter 1
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> incoming_param_inputs;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_inputs_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_inputs = (*incoming_param_inputs_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> >();
			this->startBehavior(incoming_param_classifier,incoming_param_inputs);
			break;
		}
		
		// 8035
		case StructuredClassifiersPackage::OBJECT_OPERATION_UNREGISTER_EVENTACCEPTER:
		{
			//Retrieve input parameter 'accepter'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> incoming_param_accepter;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_accepter_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_accepter = (*incoming_param_accepter_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> >();
			this->unregister(incoming_param_accepter);
			break;
		}

		default:
		{
			// call superTypes
			result = ExtensionalValueImpl::eInvoke(operationID, arguments);
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
void ObjectImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("types");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("types")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ExtensionalValueImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("objectActivation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ObjectActivation";
			}
			loadHandler->handleChild(this->getObjectActivation()); 

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
	ExtensionalValueImpl::loadNode(nodeName, loadHandler);
}

void ObjectImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::OBJECT_ATTRIBUTE_TYPES:
		{
			std::shared_ptr<Bag<uml::Classifier>> _types = getTypes();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_types->push_back(_r);
				}
			}
			return;
		}
	}
	ExtensionalValueImpl::resolveReferences(featureID, references);
}

void ObjectImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExtensionalValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ObjectImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::Classifier>("types", this->getTypes());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'objectActivation'

		saveHandler->addReference(this->getObjectActivation(), "objectActivation", getObjectActivation()->eClass() != fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getObjectActivation_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

