//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_BUILDCOMPONENT_BUILDCOMPONENTIMPL_HPP
#define STANDARDPROFILE_BUILDCOMPONENT_BUILDCOMPONENTIMPL_HPP

#include <functional>

//Model includes
#include "../BuildComponent.hpp"
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
	class BuildComponentImpl : virtual public uml::StereotypeImpl, virtual public BuildComponent
	{
		private:    
			BuildComponentImpl(BuildComponentImpl const&) = delete;
			BuildComponentImpl& operator=(BuildComponentImpl const&) = delete;

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			BuildComponentImpl();
			virtual std::shared_ptr<BuildComponent> getThisBuildComponentPtr();
			virtual void setThisBuildComponentPtr(std::weak_ptr<BuildComponent> thisBuildComponentPtr);


		public:
			//destructor
			virtual ~BuildComponentImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Component> getBase_Component() const ;
			virtual void setBase_Component (std::weak_ptr<uml::Component> _base_Component);
			

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
			std::weak_ptr<BuildComponent> m_thisBuildComponentPtr;
			std::map<std::string,std::function<Any()>> m_getterMap;
			std::map<std::string,std::function<void(Any)>> m_setterMap;
			std::map<std::string,std::function<void()>> m_unsetterMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_BUILDCOMPONENT_BUILDCOMPONENTIMPL_HPP */
