
#include "ecore/impl/EModelElementImpl.hpp"

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


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EObject.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EModelElementImpl::EModelElementImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EModelElementImpl::~EModelElementImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EModelElement "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EModelElementImpl::EModelElementImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EModelElementImpl()
{
	m_eContainer = par_eContainer;
}

EModelElementImpl::EModelElementImpl(const EModelElementImpl & obj): EModelElementImpl()
{
	*this = obj;
}

EModelElementImpl& EModelElementImpl::operator=(const EModelElementImpl & obj)
{
	//call overloaded =Operator for each base class
	EObjectImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EModelElement 
	 * which is generated by the compiler (as EModelElement is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EModelElement::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EModelElement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'eAnnotations'
	std::shared_ptr<Subset<ecore::EAnnotation, ecore::EObject>> eAnnotationsList = obj.getEAnnotations();
	if(eAnnotationsList)
	{
		/*Subset*/
		m_eAnnotations.reset(new Subset<ecore::EAnnotation, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eAnnotations - Subset<ecore::EAnnotation, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		getEAnnotations()->initSubset(getEContentUnion());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eAnnotations - Subset<ecore::EAnnotation, ecore::EObject >(getEContentUnion())" << std::endl;
		#endif
		
		for(const std::shared_ptr<ecore::EAnnotation> eAnnotationsindexElem: *eAnnotationsList) 
		{
			std::shared_ptr<ecore::EAnnotation> temp = std::dynamic_pointer_cast<ecore::EAnnotation>((eAnnotationsindexElem)->copy());
			m_eAnnotations->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr eAnnotations."<< std::endl;)
	}
	/*Subset*/
	getEAnnotations()->initSubset(getEContentUnion());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_eAnnotations - Subset<ecore::EAnnotation, ecore::EObject >(getEContentUnion())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EAnnotation> EModelElementImpl::getEAnnotation(std::string source)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for(std::shared_ptr<EAnnotation> a : *m_eAnnotations)
    {
	    if(a->getSource()==source)
	    {
		    return a;
	    }
    }
    return std::shared_ptr<ecore::EAnnotation>();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eAnnotations */
std::shared_ptr<Subset<ecore::EAnnotation, ecore::EObject>> EModelElementImpl::getEAnnotations() const
{
	if(m_eAnnotations == nullptr)
	{
		/*Subset*/
		m_eAnnotations.reset(new Subset<ecore::EAnnotation, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eAnnotations - Subset<ecore::EAnnotation, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		getEAnnotations()->initSubset(getEContentUnion());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eAnnotations - Subset<ecore::EAnnotation, ecore::EObject >(getEContentUnion())" << std::endl;
		#endif
		
	}
    return m_eAnnotations;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EModelElementImpl::getEContentUnion() const
{
	if(m_eContentUnion == nullptr)
	{
		/*Union*/
		m_eContentUnion.reset(new Union<ecore::EObject>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_eContentUnion - Union<ecore::EObject>()" << std::endl;
		#endif
		
		
	}
	return m_eContentUnion;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EModelElementImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EModelElementImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get ecoreFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EModelElementImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void EModelElementImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("eAnnotations") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EAnnotation";
			}
			loadHandler->handleChildContainer<ecore::EAnnotation>(this->getEAnnotations());  

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
	EObjectImpl::loadNode(nodeName, loadHandler);
}

void EModelElementImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	EObjectImpl::resolveReferences(featureID, references);
}

void EModelElementImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EModelElementImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Save 'eAnnotations'
		for (std::shared_ptr<ecore::EAnnotation> eAnnotations : *this->getEAnnotations()) 
		{
			saveHandler->addReference(eAnnotations, "eAnnotations", eAnnotations->eClass() != package->getEAnnotation_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<EClass> EModelElementImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEModelElement_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EModelElementImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EMODELELEMENT_ATTRIBUTE_EANNOTATIONS:
		{
			return eAnyBag(getEAnnotations(),ecore::ecorePackage::EANNOTATION_CLASS); //383
		}
	}
	return EObjectImpl::eGet(featureID, resolve, coreType);
}

bool EModelElementImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EMODELELEMENT_ATTRIBUTE_EANNOTATIONS:
			return getEAnnotations() != nullptr; //383
	}
	return EObjectImpl::internalEIsSet(featureID);
}

bool EModelElementImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EMODELELEMENT_ATTRIBUTE_EANNOTATIONS:
		{
			// CAST Any to Bag<ecore::EAnnotation>
			if((newValue->isContainer()) && (ecore::ecorePackage::EANNOTATION_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ecore::EAnnotation>> eAnnotationsList= newValue->get<std::shared_ptr<Bag<ecore::EAnnotation>>>();
					std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotations=getEAnnotations();
					for(const std::shared_ptr<ecore::EAnnotation> indexEAnnotations: *_eAnnotations)
					{
						if (eAnnotationsList->find(indexEAnnotations) == -1)
						{
							_eAnnotations->erase(indexEAnnotations);
						}
					}

					for(const std::shared_ptr<ecore::EAnnotation> indexEAnnotations: *eAnnotationsList)
					{
						if (_eAnnotations->find(indexEAnnotations) == -1)
						{
							_eAnnotations->add(indexEAnnotations);
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

	return EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EModelElementImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// ecore::EModelElement::getEAnnotation(std::string) : ecore::EAnnotation: 304921690
		case ecorePackage::EMODELELEMENT_OPERATION_GETEANNOTATION_ESTRING:
		{
			//Retrieve input parameter 'source'
			//parameter 0
			std::string incoming_param_source;
			std::list<Any>::const_iterator incoming_param_source_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_source = (*incoming_param_source_arguments_citer)->get<std::string >();
			result = eAny(this->getEAnnotation(incoming_param_source), ecore::ecorePackage::EANNOTATION_CLASS,false);
			break;
		}

		default:
		{
			// call superTypes
			result = EObjectImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::EModelElement> EModelElementImpl::getThisEModelElementPtr() const
{
	return m_thisEModelElementPtr.lock();
}
void EModelElementImpl::setThisEModelElementPtr(std::weak_ptr<ecore::EModelElement> thisEModelElementPtr)
{
	m_thisEModelElementPtr = thisEModelElementPtr;
	setThisEObjectPtr(thisEModelElementPtr);
}


