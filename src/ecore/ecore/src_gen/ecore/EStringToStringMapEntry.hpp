//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ESTRINGTOSTRINGMAPENTRY_HPP
#define ECORE_ESTRINGTOSTRINGMAPENTRY_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations



//*********************************
// generated Includes

#include <map>

namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace ecore
{
	class ecoreFactory;
}

//Forward Declaration for used types 

// base class includes

// enum includes

#include "ecore/EModelElement.hpp"

//Includes from codegen annotation

//*********************************
namespace ecore 
{
	
	class EStringToStringMapEntry : virtual public ecore::EModelElement

	{
		public:
 			EStringToStringMapEntry(const EStringToStringMapEntry &) {}
			EStringToStringMapEntry& operator=(EStringToStringMapEntry const&) = delete;

		protected:
			EStringToStringMapEntry(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EStringToStringMapEntry() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual std::string  getKey() const = 0;
			
			 
			virtual void setKey (std::string  _key)= 0; 
			 
			virtual std::string  getValue() const = 0;
			
			 
			virtual void setValue (std::string  _value)= 0; 
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			 
			std::string  m_key = "";
			 
			std::string  m_value = "";
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: ECORE_ESTRINGTOSTRINGMAPENTRY_HPP */
