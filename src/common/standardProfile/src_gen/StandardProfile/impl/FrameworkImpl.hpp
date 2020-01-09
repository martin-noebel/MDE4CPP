//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_FRAMEWORK_FRAMEWORKIMPL_HPP
#define STANDARDPROFILE_FRAMEWORK_FRAMEWORKIMPL_HPP

#include <functional>

//Model includes
#include "../Framework.hpp"
#include "uml/impl/StereotypeImpl.hpp"
#include "uml/Property.hpp"

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

namespace uml
{
	class Property;
}

//*********************************
namespace StandardProfile
{
	class FrameworkImpl : virtual public uml::StereotypeImpl, virtual public Framework
	{
		private:    
			FrameworkImpl(FrameworkImpl const&) = delete;
			FrameworkImpl& operator=(FrameworkImpl const&) = delete;

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			FrameworkImpl();
			virtual std::shared_ptr<Framework> getThisFrameworkPtr();
			virtual void setThisFrameworkPtr(std::weak_ptr<Framework> thisFrameworkPtr);


		public:
			//destructor
			virtual ~FrameworkImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Package> getBase_Package() const ;
			virtual void setBase_Package (std::weak_ptr<uml::Package> _base_Package);
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass();

		public:
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			virtual Any get(std::shared_ptr<uml::Property> _property) const ;
			virtual void set(std::shared_ptr<uml::Property> _property, Any value) ;
			virtual void unset(std::shared_ptr<uml::Property> _property) ;
			
		
		private:
			std::weak_ptr<Framework> m_thisFrameworkPtr;
			std::map<std::string,std::function<Any()>> m_getterMap;
			std::map<std::string,std::function<void(Any)>> m_setterMap;
			std::map<std::string,std::function<void()>> m_unsetterMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_FRAMEWORK_FRAMEWORKIMPL_HPP */
