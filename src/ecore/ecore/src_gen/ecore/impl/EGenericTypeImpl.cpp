
#include "ecore/impl/EGenericTypeImpl.hpp"

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


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"

#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/ETypeParameter.hpp"

//Factories an Package includes
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EGenericTypeImpl::EGenericTypeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EGenericTypeImpl::~EGenericTypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EGenericType "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


EGenericTypeImpl::EGenericTypeImpl(const EGenericTypeImpl & obj): EGenericTypeImpl()
{
	*this = obj;
}

EGenericTypeImpl& EGenericTypeImpl::operator=(const EGenericTypeImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::EModelElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EGenericType 
	 * which is generated by the compiler (as EGenericType is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EGenericType::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EGenericType "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_eClassifier  = obj.getEClassifier();
	m_eRawType  = obj.getERawType();
	m_eTypeParameter  = obj.getETypeParameter();
	//Clone references with containment (deep copy)
	//clone reference 'eLowerBound'
	if(obj.getELowerBound()!=nullptr)
	{
		m_eLowerBound = std::dynamic_pointer_cast<ecore::EGenericType>(obj.getELowerBound()->copy());
	}

	//clone reference 'eTypeArguments'
	std::shared_ptr<Bag<ecore::EGenericType>> eTypeArgumentsList = obj.getETypeArguments();
	if(eTypeArgumentsList)
	{
		m_eTypeArguments.reset(new Bag<ecore::EGenericType>());
		
		
		for(const std::shared_ptr<ecore::EGenericType> eTypeArgumentsindexElem: *eTypeArgumentsList) 
		{
			std::shared_ptr<ecore::EGenericType> temp = std::dynamic_pointer_cast<ecore::EGenericType>((eTypeArgumentsindexElem)->copy());
			m_eTypeArguments->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr eTypeArguments."<< std::endl;)
	}

	//clone reference 'eUpperBound'
	if(obj.getEUpperBound()!=nullptr)
	{
		m_eUpperBound = std::dynamic_pointer_cast<ecore::EGenericType>(obj.getEUpperBound()->copy());
	}
	
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> EGenericTypeImpl::copy() const
{
	std::shared_ptr<EGenericTypeImpl> element(new EGenericTypeImpl());
	*element =(*this);
	element->setThisEGenericTypePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool EGenericTypeImpl::isInstance(Any object) const
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eClassifier */
std::shared_ptr<ecore::EClassifier> EGenericTypeImpl::getEClassifier() const
{
    return m_eClassifier;
}
void EGenericTypeImpl::setEClassifier(std::shared_ptr<ecore::EClassifier> _eClassifier)
{
    m_eClassifier = _eClassifier;
	
}

/* Getter & Setter for reference eLowerBound */
std::shared_ptr<ecore::EGenericType> EGenericTypeImpl::getELowerBound() const
{
    return m_eLowerBound;
}
void EGenericTypeImpl::setELowerBound(std::shared_ptr<ecore::EGenericType> _eLowerBound)
{
    m_eLowerBound = _eLowerBound;
	
}

/* Getter & Setter for reference eRawType */
std::shared_ptr<ecore::EClassifier> EGenericTypeImpl::getERawType() const
{
    return m_eRawType;
}
void EGenericTypeImpl::setERawType(std::shared_ptr<ecore::EClassifier> _eRawType)
{
    m_eRawType = _eRawType;
	
}

/* Getter & Setter for reference eTypeArguments */
std::shared_ptr<Bag<ecore::EGenericType>> EGenericTypeImpl::getETypeArguments() const
{
	if(m_eTypeArguments == nullptr)
	{
		m_eTypeArguments.reset(new Bag<ecore::EGenericType>());
		
		
	}
    return m_eTypeArguments;
}

/* Getter & Setter for reference eTypeParameter */
std::shared_ptr<ecore::ETypeParameter> EGenericTypeImpl::getETypeParameter() const
{
    return m_eTypeParameter;
}
void EGenericTypeImpl::setETypeParameter(std::shared_ptr<ecore::ETypeParameter> _eTypeParameter)
{
    m_eTypeParameter = _eTypeParameter;
	
}

/* Getter & Setter for reference eUpperBound */
std::shared_ptr<ecore::EGenericType> EGenericTypeImpl::getEUpperBound() const
{
    return m_eUpperBound;
}
void EGenericTypeImpl::setEUpperBound(std::shared_ptr<ecore::EGenericType> _eUpperBound)
{
    m_eUpperBound = _eUpperBound;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EGenericTypeImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EGenericTypeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EGenericTypeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("eClassifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eClassifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("eRawType");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eRawType")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("eTypeParameter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eTypeParameter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ecore::EObjectImpl::loadAttributes(loadHandler, attr_list);
}

void EGenericTypeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("eLowerBound") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EGenericType";
			}
			loadHandler->handleChild(this->getELowerBound());

			return; 
		}

		if ( nodeName.compare("eTypeArguments") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EGenericType";
			}
			loadHandler->handleChildContainer<ecore::EGenericType>(this->getETypeArguments());  

			return; 
		}

		if ( nodeName.compare("eUpperBound") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EGenericType";
			}
			loadHandler->handleChild(this->getEUpperBound());

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
}

void EGenericTypeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ECLASSIFIER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EClassifier> _eClassifier = std::dynamic_pointer_cast<ecore::EClassifier>( references.front() );
				setEClassifier(_eClassifier);
			}
			
			return;
		}

		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ERAWTYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EClassifier> _eRawType = std::dynamic_pointer_cast<ecore::EClassifier>( references.front() );
				setERawType(_eRawType);
			}
			
			return;
		}

		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ETYPEPARAMETER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::ETypeParameter> _eTypeParameter = std::dynamic_pointer_cast<ecore::ETypeParameter>( references.front() );
				setETypeParameter(_eTypeParameter);
			}
			
			return;
		}
	}
	ecore::EObjectImpl::resolveReferences(featureID, references);
}

void EGenericTypeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::EObjectImpl::saveContent(saveHandler);
}

void EGenericTypeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
	// Add references
		saveHandler->addReference(this->getEClassifier(),"eClassifier", getEClassifier()->eClass() != ecore::ecorePackage::eInstance()->getEClassifier_Class());
		saveHandler->addReference(this->getERawType(),"eRawType", getERawType()->eClass() != ecore::ecorePackage::eInstance()->getEClassifier_Class());
		saveHandler->addReference(this->getETypeParameter(),"eTypeParameter", getETypeParameter()->eClass() != ecore::ecorePackage::eInstance()->getETypeParameter_Class());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eLowerBound'

		saveHandler->addReference(this->getELowerBound(), "eLowerBound", getELowerBound()->eClass() != ecore::ecorePackage::eInstance()->getEGenericType_Class());

		// Save 'eTypeArguments'

		saveHandler->addReferences<ecore::EGenericType>("eTypeArguments", this->getETypeArguments());

		// Save 'eUpperBound'

		saveHandler->addReference(this->getEUpperBound(), "eUpperBound", getEUpperBound()->eClass() != ecore::ecorePackage::eInstance()->getEGenericType_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<EClass> EGenericTypeImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEGenericType_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EGenericTypeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ECLASSIFIER:
		{
			std::shared_ptr<ecore::EObject> returnValue=getEClassifier();
			return eAny(returnValue,returnValue->getMetaElementID(),false); //285
		}
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ELOWERBOUND:
		{
			std::shared_ptr<ecore::EObject> returnValue=getELowerBound();
			return eAny(returnValue,returnValue->getMetaElementID(),false); //283
		}
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ERAWTYPE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getERawType();
			return eAny(returnValue,returnValue->getMetaElementID(),false); //282
		}
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ETYPEARGUMENTS:
		{
			return eAnyBag(getETypeArguments(),1282018195); //281
		}
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ETYPEPARAMETER:
		{
			std::shared_ptr<ecore::EObject> returnValue=getETypeParameter();
			return eAny(returnValue,returnValue->getMetaElementID(),false); //284
		}
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_EUPPERBOUND:
		{
			std::shared_ptr<ecore::EObject> returnValue=getEUpperBound();
			return eAny(returnValue,returnValue->getMetaElementID(),false); //280
		}
	}
	return ecore::EObjectImpl::eGet(featureID, resolve, coreType);
}

bool EGenericTypeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ECLASSIFIER:
			return getEClassifier() != nullptr; //285
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ELOWERBOUND:
			return getELowerBound() != nullptr; //283
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ERAWTYPE:
			return getERawType() != nullptr; //282
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ETYPEARGUMENTS:
			return getETypeArguments() != nullptr; //281
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ETYPEPARAMETER:
			return getETypeParameter() != nullptr; //284
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_EUPPERBOUND:
			return getEUpperBound() != nullptr; //280
	}
	return ecore::EObjectImpl::internalEIsSet(featureID);
}

bool EGenericTypeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ECLASSIFIER:
		{
			// CAST Any to ecore::EClassifier
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EClassifier> _eClassifier = std::dynamic_pointer_cast<ecore::EClassifier>(_temp);
			setEClassifier(_eClassifier); //285
			return true;
		}
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ELOWERBOUND:
		{
			// CAST Any to ecore::EGenericType
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EGenericType> _eLowerBound = std::dynamic_pointer_cast<ecore::EGenericType>(_temp);
			setELowerBound(_eLowerBound); //283
			return true;
		}
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ERAWTYPE:
		{
			// CAST Any to ecore::EClassifier
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EClassifier> _eRawType = std::dynamic_pointer_cast<ecore::EClassifier>(_temp);
			setERawType(_eRawType); //282
			return true;
		}
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ETYPEARGUMENTS:
		{
			// CAST Any to Bag<ecore::EGenericType>
			if((newValue->isContainer()) && (ecore::ecorePackage::EGENERICTYPE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ecore::EGenericType>> eTypeArgumentsList= newValue->get<std::shared_ptr<Bag<ecore::EGenericType>>>();
					std::shared_ptr<Bag<ecore::EGenericType>> _eTypeArguments=getETypeArguments();
					for(const std::shared_ptr<ecore::EGenericType> indexETypeArguments: *_eTypeArguments)
					{
						if (eTypeArgumentsList->find(indexETypeArguments) == -1)
						{
							_eTypeArguments->erase(indexETypeArguments);
						}
					}

					for(const std::shared_ptr<ecore::EGenericType> indexETypeArguments: *eTypeArgumentsList)
					{
						if (_eTypeArguments->find(indexETypeArguments) == -1)
						{
							_eTypeArguments->add(indexETypeArguments);
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
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_ETYPEPARAMETER:
		{
			// CAST Any to ecore::ETypeParameter
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::ETypeParameter> _eTypeParameter = std::dynamic_pointer_cast<ecore::ETypeParameter>(_temp);
			setETypeParameter(_eTypeParameter); //284
			return true;
		}
		case ecore::ecorePackage::EGENERICTYPE_ATTRIBUTE_EUPPERBOUND:
		{
			// CAST Any to ecore::EGenericType
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EGenericType> _eUpperBound = std::dynamic_pointer_cast<ecore::EGenericType>(_temp);
			setEUpperBound(_eUpperBound); //280
			return true;
		}
	}

	return ecore::EObjectImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EGenericTypeImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// ecore::EGenericType::isInstance(Any) : bool {const}: 1426574931
		case ecorePackage::EGENERICTYPE_OPERATION_ISINSTANCE_EJAVAOBJECT:
		{
			//Retrieve input parameter 'object'
			//parameter 0
			Any incoming_param_object;
			std::list<Any>::const_iterator incoming_param_object_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_object = (*incoming_param_object_arguments_citer)->get<Any >();
			result = eAny(this->isInstance(incoming_param_object),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ecore::EModelElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::EGenericType> EGenericTypeImpl::getThisEGenericTypePtr() const
{
	return m_thisEGenericTypePtr.lock();
}
void EGenericTypeImpl::setThisEGenericTypePtr(std::weak_ptr<ecore::EGenericType> thisEGenericTypePtr)
{
	m_thisEGenericTypePtr = thisEGenericTypePtr;
}


