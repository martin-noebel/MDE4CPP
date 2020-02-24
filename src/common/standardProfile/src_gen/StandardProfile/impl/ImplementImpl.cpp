#include "StandardProfile/impl/ImplementImpl.hpp"

#ifdef NDEBUG
  #define DEBUG_MESSAGE(a) /**/
#else
  #define DEBUG_MESSAGE(a) a
#endif

#include <iostream>


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"
#include "StandardProfile/impl/StandardProfilePackageImpl.hpp"
#include "uml/Stereotype.hpp"
#include "uml/Component.hpp"




//Included from from Ports typed by interface

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
ImplementImpl::ImplementImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Implement::base_Component",[this](){ return eAny(this->getBase_Component());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Implement::base_Component",[this](Any object){this->setBase_Component(object->get<std::shared_ptr<uml::Component>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Implement::base_Component",[this](){m_base_Component = std::shared_ptr<uml::Component>(nullptr);}));
	 

	// init properties without default
	
	
	// init properties with default

	// init connectors
}


ImplementImpl::~ImplementImpl()
{
}

ImplementImpl::ImplementImpl(const ImplementImpl & obj):ImplementImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Implement "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
}

std::shared_ptr<ecore::EObject>  ImplementImpl::copy() const
{
	std::shared_ptr<ImplementImpl> element(new ImplementImpl(*this));
	element->setThisImplementPtr(element);
	return element;
}


std::shared_ptr<uml::Class> ImplementImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Implement();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ImplementImpl::setBase_Component(std::weak_ptr<uml::Component> _base_Component)
{
	m_base_Component = _base_Component;
}
std::weak_ptr<uml::Component> ImplementImpl::getBase_Component() const 
{
	return m_base_Component;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ImplementImpl::get(std::shared_ptr<uml::Property> _property) const
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string, std::function<Any()>>::const_iterator iter = m_getterMap.find(qName);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }
	return eAny(nullptr);
}

void ImplementImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string, std::function<void(Any)>>::iterator iter = m_setterMap.find(qName);
    if(iter != m_setterMap.end())
    {
        //invoke the getter function
        iter->second(value);
    }
}

void ImplementImpl::unset(std::shared_ptr<uml::Property> _property)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string,std::function<void()>>::iterator iter = m_unsetterMap.find(qName);
    if(iter != m_unsetterMap.end())
    {
        //invoke the getter function
        iter->second();
    }
}


std::shared_ptr<Implement> ImplementImpl::getThisImplementPtr()
{
	return m_thisImplementPtr.lock();
}
void ImplementImpl::setThisImplementPtr(std::weak_ptr<Implement> thisImplementPtr)
{
	m_thisImplementPtr = thisImplementPtr;
	setThisStereotypePtr(thisImplementPtr);
}
