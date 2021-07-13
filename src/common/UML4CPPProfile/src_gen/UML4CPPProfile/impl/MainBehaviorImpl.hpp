//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_MAINBEHAVIOR_MAINBEHAVIORIMPL_HPP
#define UML4CPPPROFILE_MAINBEHAVIOR_MAINBEHAVIORIMPL_HPP

#include <functional>

//Model includes
#include "../MainBehavior.hpp"
#include "uml/impl/StereotypeImpl.hpp"
#include "uml/Property.hpp"

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

namespace uml
{
	class Property;
}

//*********************************
namespace UML4CPPProfile
{
	class MainBehaviorImpl : virtual public uml::StereotypeImpl, virtual public MainBehavior
	{
		public: 
			MainBehaviorImpl(const MainBehaviorImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			MainBehaviorImpl& operator=(MainBehaviorImpl const&);

		protected:
			friend class UML4CPPProfileFactoryImpl;
			//constructor
			MainBehaviorImpl();
			virtual std::shared_ptr<MainBehavior> getThisMainBehaviorPtr();
			virtual void setThisMainBehaviorPtr(std::weak_ptr<MainBehavior> thisMainBehaviorPtr);


		public:

			//destructor
			virtual ~MainBehaviorImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Behavior> getBase_Behavior() const ;
			virtual void setBase_Behavior(std::weak_ptr<uml::Behavior> _base_Behavior);
			
			
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass();
			virtual void instantiate();
			virtual void destroy();

		public:
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			virtual Any get(std::shared_ptr<uml::Property> _property) const ;
			virtual void set(std::shared_ptr<uml::Property> _property, Any value) ;
			virtual void unset(std::shared_ptr<uml::Property> _property) ;
			
		
		private:
			std::weak_ptr<MainBehavior> m_thisMainBehaviorPtr;
			std::map<std::string,std::function<Any()>> m_getterMap;
			std::map<std::string,std::function<void(Any)>> m_setterMap;
			std::map<std::string,std::function<void()>> m_unsetterMap;
	};
}
#endif /* end of include guard: UML4CPPPROFILE_MAINBEHAVIOR_MAINBEHAVIORIMPL_HPP */
