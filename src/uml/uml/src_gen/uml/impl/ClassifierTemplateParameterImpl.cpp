
#include "uml/impl/ClassifierTemplateParameterImpl.hpp"

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
#include <stdexcept>


#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/Any.hpp"
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
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/ParameterableElement.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ClassifierTemplateParameterImpl::ClassifierTemplateParameterImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ClassifierTemplateParameterImpl::~ClassifierTemplateParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ClassifierTemplateParameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ClassifierTemplateParameterImpl::ClassifierTemplateParameterImpl(std::weak_ptr<uml::Element> par_owner)
:ClassifierTemplateParameterImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ClassifierTemplateParameterImpl::ClassifierTemplateParameterImpl(std::weak_ptr<uml::TemplateSignature> par_signature)
:ClassifierTemplateParameterImpl()
{
	m_signature = par_signature;
	m_owner = par_signature;
}

ClassifierTemplateParameterImpl::ClassifierTemplateParameterImpl(const ClassifierTemplateParameterImpl & obj): ClassifierTemplateParameterImpl()
{
	*this = obj;
}

ClassifierTemplateParameterImpl& ClassifierTemplateParameterImpl::operator=(const ClassifierTemplateParameterImpl & obj)
{
	//call overloaded =Operator for each base class
	TemplateParameterImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ClassifierTemplateParameter 
	 * which is generated by the compiler (as ClassifierTemplateParameter is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ClassifierTemplateParameter::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ClassifierTemplateParameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_allowSubstitutable = obj.getAllowSubstitutable();

	//copy references with no containment (soft copy)
	m_constrainingClassifier  = obj.getConstrainingClassifier();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ClassifierTemplateParameterImpl::copy() const
{
	std::shared_ptr<ClassifierTemplateParameterImpl> element(new ClassifierTemplateParameterImpl());
	*element =(*this);
	element->setThisClassifierTemplateParameterPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool ClassifierTemplateParameterImpl::actual_is_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ClassifierTemplateParameterImpl::constraining_classifiers_constrain_args(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ClassifierTemplateParameterImpl::constraining_classifiers_constrain_parametered_element(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ClassifierTemplateParameterImpl::has_constraining_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ClassifierTemplateParameterImpl::matching_abstract(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ClassifierTemplateParameterImpl::parametered_element_no_features(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute allowSubstitutable */
bool ClassifierTemplateParameterImpl::getAllowSubstitutable() const 
{
	return m_allowSubstitutable;
}
void ClassifierTemplateParameterImpl::setAllowSubstitutable(bool _allowSubstitutable)
{
	m_allowSubstitutable = _allowSubstitutable;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference constrainingClassifier */
std::shared_ptr<Bag<uml::Classifier>> ClassifierTemplateParameterImpl::getConstrainingClassifier() const
{
	if(m_constrainingClassifier == nullptr)
	{
		m_constrainingClassifier.reset(new Bag<uml::Classifier>());
		
		
	}
    return m_constrainingClassifier;
}

//*********************************
// Union Getter
//*********************************


std::shared_ptr<Union<uml::Element>> ClassifierTemplateParameterImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ClassifierTemplateParameterImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ClassifierTemplateParameterImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_signature.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ClassifierTemplateParameterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClassifierTemplateParameterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("allowSubstitutable");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setAllowSubstitutable(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("constrainingClassifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("constrainingClassifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	TemplateParameterImpl::loadAttributes(loadHandler, attr_list);
}

void ClassifierTemplateParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	TemplateParameterImpl::loadNode(nodeName, loadHandler);
}

void ClassifierTemplateParameterImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_CONSTRAININGCLASSIFIER:
		{
			std::shared_ptr<Bag<uml::Classifier>> _constrainingClassifier = getConstrainingClassifier();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_constrainingClassifier->push_back(_r);
				}
			}
			return;
		}
	}
	TemplateParameterImpl::resolveReferences(featureID, references);
}

void ClassifierTemplateParameterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	TemplateParameterImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ClassifierTemplateParameterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getClassifierTemplateParameter_Attribute_allowSubstitutable()) )
		{
			saveHandler->addAttribute("allowSubstitutable", this->getAllowSubstitutable());
		}
	// Add references
		saveHandler->addReferences<uml::Classifier>("constrainingClassifier", this->getConstrainingClassifier());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ClassifierTemplateParameterImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getClassifierTemplateParameter_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ClassifierTemplateParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_ALLOWSUBSTITUTABLE:
			return eAny(getAllowSubstitutable(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //378
		case uml::umlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_CONSTRAININGCLASSIFIER:
		{
			return eAnyBag(getConstrainingClassifier(),uml::umlPackage::CLASSIFIER_CLASS); //379
		}
	}
	return TemplateParameterImpl::eGet(featureID, resolve, coreType);
}

bool ClassifierTemplateParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_ALLOWSUBSTITUTABLE:
			return getAllowSubstitutable() != true; //378
		case uml::umlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_CONSTRAININGCLASSIFIER:
			return getConstrainingClassifier() != nullptr; //379
	}
	return TemplateParameterImpl::internalEIsSet(featureID);
}

bool ClassifierTemplateParameterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_ALLOWSUBSTITUTABLE:
		{
			// CAST Any to bool
			bool _allowSubstitutable = newValue->get<bool>();
			setAllowSubstitutable(_allowSubstitutable); //378
			return true;
		}
		case uml::umlPackage::CLASSIFIERTEMPLATEPARAMETER_ATTRIBUTE_CONSTRAININGCLASSIFIER:
		{
			// CAST Any to Bag<uml::Classifier>
			if((newValue->isContainer()) && (uml::umlPackage::CLASSIFIER_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Classifier>> constrainingClassifierList= newValue->get<std::shared_ptr<Bag<uml::Classifier>>>();
					std::shared_ptr<Bag<uml::Classifier>> _constrainingClassifier=getConstrainingClassifier();
					for(const std::shared_ptr<uml::Classifier> indexConstrainingClassifier: *_constrainingClassifier)
					{
						if (constrainingClassifierList->find(indexConstrainingClassifier) == -1)
						{
							_constrainingClassifier->erase(indexConstrainingClassifier);
						}
					}

					for(const std::shared_ptr<uml::Classifier> indexConstrainingClassifier: *constrainingClassifierList)
					{
						if (_constrainingClassifier->find(indexConstrainingClassifier) == -1)
						{
							_constrainingClassifier->add(indexConstrainingClassifier);
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

	return TemplateParameterImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ClassifierTemplateParameterImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::ClassifierTemplateParameter::actual_is_classifier(Any, std::map) : bool: 1795975272
		case umlPackage::CLASSIFIERTEMPLATEPARAMETER_OPERATION_ACTUAL_IS_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->actual_is_classifier(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ClassifierTemplateParameter::constraining_classifiers_constrain_args(Any, std::map) : bool: 490731306
		case umlPackage::CLASSIFIERTEMPLATEPARAMETER_OPERATION_CONSTRAINING_CLASSIFIERS_CONSTRAIN_ARGS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->constraining_classifiers_constrain_args(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ClassifierTemplateParameter::constraining_classifiers_constrain_parametered_element(Any, std::map) : bool: 1474478295
		case umlPackage::CLASSIFIERTEMPLATEPARAMETER_OPERATION_CONSTRAINING_CLASSIFIERS_CONSTRAIN_PARAMETERED_ELEMENT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->constraining_classifiers_constrain_parametered_element(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ClassifierTemplateParameter::has_constraining_classifier(Any, std::map) : bool: 1386595471
		case umlPackage::CLASSIFIERTEMPLATEPARAMETER_OPERATION_HAS_CONSTRAINING_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->has_constraining_classifier(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ClassifierTemplateParameter::matching_abstract(Any, std::map) : bool: 2020869422
		case umlPackage::CLASSIFIERTEMPLATEPARAMETER_OPERATION_MATCHING_ABSTRACT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->matching_abstract(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ClassifierTemplateParameter::parametered_element_no_features(Any, std::map) : bool: 705070053
		case umlPackage::CLASSIFIERTEMPLATEPARAMETER_OPERATION_PARAMETERED_ELEMENT_NO_FEATURES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->parametered_element_no_features(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = TemplateParameterImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ClassifierTemplateParameter> ClassifierTemplateParameterImpl::getThisClassifierTemplateParameterPtr() const
{
	return m_thisClassifierTemplateParameterPtr.lock();
}
void ClassifierTemplateParameterImpl::setThisClassifierTemplateParameterPtr(std::weak_ptr<uml::ClassifierTemplateParameter> thisClassifierTemplateParameterPtr)
{
	m_thisClassifierTemplateParameterPtr = thisClassifierTemplateParameterPtr;
	setThisTemplateParameterPtr(thisClassifierTemplateParameterPtr);
}


