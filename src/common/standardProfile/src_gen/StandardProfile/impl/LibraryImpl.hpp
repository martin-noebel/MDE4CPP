//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_LIBRARY_LIBRARYIMPL_HPP
#define STANDARDPROFILE_LIBRARY_LIBRARYIMPL_HPP

#include <functional>

//Model includes
#include "../Library.hpp"
#include "StandardProfile/impl/FileImpl.hpp"
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
	class LibraryImpl:virtual public FileImpl, virtual public Library
	{
		private:    
			LibraryImpl(LibraryImpl const&) = delete;
			LibraryImpl& operator=(LibraryImpl const&) = delete;

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			LibraryImpl();
			virtual std::shared_ptr<Library> getThisLibraryPtr();
			virtual void setThisLibraryPtr(std::weak_ptr<Library> thisLibraryPtr);


		public:
			//destructor
			virtual ~LibraryImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Artifact> getBase_Artifact() const ;
			virtual void setBase_Artifact (std::weak_ptr<uml::Artifact> _base_Artifact);
			

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
			std::weak_ptr<Library> m_thisLibraryPtr;
			std::map<std::string,std::function<Any()>> m_getterMap;
			std::map<std::string,std::function<void(Any)>> m_setterMap;
			std::map<std::string,std::function<void()>> m_unsetterMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_LIBRARY_LIBRARYIMPL_HPP */
