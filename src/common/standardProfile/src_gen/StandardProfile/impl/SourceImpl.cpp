#include "StandardProfile/impl/SourceImpl.hpp"

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
#include "uml/Artifact.hpp"




//Included from from Ports typed by interface

using namespace StandardProfile;

//*********************************
// Constructor / Destructor
//*********************************
SourceImpl::SourceImpl()
{
	//***********************************
	// init Get Set
	//getter init
	m_getterMap.insert(std::pair<std::string,std::function<Any()>>("StandardProfile::Source::base_Artifact",[this](){ return eAny(this->getBase_Artifact());}));
	
	m_setterMap.insert(std::pair<std::string,std::function<void(Any)>>("StandardProfile::Source::base_Artifact",[this](Any object){this->setBase_Artifact(object->get<std::shared_ptr<uml::Artifact>>());}));
	
	m_unsetterMap.insert(std::pair<std::string,std::function<void()>>("StandardProfile::Source::base_Artifact",[this](){m_base_Artifact = std::shared_ptr<uml::Artifact>(nullptr);}));
	 

	// init properties without default
	
	
	// init properties with default

	// init connectors
}


SourceImpl::~SourceImpl()
{
}

SourceImpl::SourceImpl(const SourceImpl & obj):SourceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Source "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
}

std::shared_ptr<ecore::EObject>  SourceImpl::copy() const
{
	std::shared_ptr<SourceImpl> element(new SourceImpl(*this));
	element->setThisSourcePtr(element);
	return element;
}


std::shared_ptr<uml::Class> SourceImpl::getMetaClass()
{
	return StandardProfilePackageImpl::eInstance()->get_StandardProfile_Source();
}

//*********************************
// Attribute Setter Getter
//*********************************
void SourceImpl::setBase_Artifact(std::weak_ptr<uml::Artifact> _base_Artifact)
{
	m_base_Artifact = _base_Artifact;
}
std::weak_ptr<uml::Artifact> SourceImpl::getBase_Artifact() const 
{
	return m_base_Artifact;
}

//*********************************
// Operations
//*********************************

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any SourceImpl::get(std::shared_ptr<uml::Property> _property) const
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string, std::function<Any()>>::const_iterator iter = m_getterMap.find(qName);
    if(iter != m_getterMap.cend())
    {
        //invoke the getter function
        return iter->second();
    }
	return StandardProfile::FileImpl::get(_property);
}

void SourceImpl::set(std::shared_ptr<uml::Property> _property, Any value)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string, std::function<void(Any)>>::iterator iter = m_setterMap.find(qName);
    if(iter != m_setterMap.end())
    {
        //invoke the getter function
        iter->second(value);
    }
	StandardProfile::FileImpl::set(_property, value);
}

void SourceImpl::unset(std::shared_ptr<uml::Property> _property)
{
	//TODO: still two times run through map (contains and [])
	std::string qName = _property->getQualifiedName();
	std::map<std::string,std::function<void()>>::iterator iter = m_unsetterMap.find(qName);
    if(iter != m_unsetterMap.end())
    {
        //invoke the getter function
        iter->second();
    }
	StandardProfile::FileImpl::unset(_property);
}


std::shared_ptr<Source> SourceImpl::getThisSourcePtr()
{
	return m_thisSourcePtr.lock();
}
void SourceImpl::setThisSourcePtr(std::weak_ptr<Source> thisSourcePtr)
{
	m_thisSourcePtr = thisSourcePtr;
	setThisFilePtr(thisSourcePtr);
}
