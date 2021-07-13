//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_EXTERNALLIBRARY_EXTERNALLIBRARYIMPL_HPP
#define UML4CPPPROFILE_EXTERNALLIBRARY_EXTERNALLIBRARYIMPL_HPP

#include <functional>

//Model includes
#include "../ExternalLibrary.hpp"
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
	class ExternalLibraryImpl : virtual public uml::StereotypeImpl, virtual public ExternalLibrary
	{
		public: 
			ExternalLibraryImpl(const ExternalLibraryImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			ExternalLibraryImpl& operator=(ExternalLibraryImpl const&);

		protected:
			friend class UML4CPPProfileFactoryImpl;
			//constructor
			ExternalLibraryImpl();
			virtual std::shared_ptr<ExternalLibrary> getThisExternalLibraryPtr();
			virtual void setThisExternalLibraryPtr(std::weak_ptr<ExternalLibrary> thisExternalLibraryPtr);


		public:

			//destructor
			virtual ~ExternalLibraryImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Package> getBase_Package() const ;
			virtual void setBase_Package(std::weak_ptr<uml::Package> _base_Package);
			virtual std::string getIncludePath() const ;
			virtual void setIncludePath(std::string _includePath);
			virtual std::string getLibraryName() const ;
			virtual void setLibraryName(std::string _libraryName);
			virtual std::string getLibraryPath() const ;
			virtual void setLibraryPath(std::string _libraryPath);
			
			
			

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
			std::weak_ptr<ExternalLibrary> m_thisExternalLibraryPtr;
			std::map<std::string,std::function<Any()>> m_getterMap;
			std::map<std::string,std::function<void(Any)>> m_setterMap;
			std::map<std::string,std::function<void()>> m_unsetterMap;
	};
}
#endif /* end of include guard: UML4CPPPROFILE_EXTERNALLIBRARY_EXTERNALLIBRARYIMPL_HPP */
