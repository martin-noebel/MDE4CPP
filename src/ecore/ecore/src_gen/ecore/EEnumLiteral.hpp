//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EENUMLITERAL_HPP
#define ECORE_EENUMLITERAL_HPP


#include <memory>
#include <string>
#include "abstractDataTypes/Any.hpp"
// forward declarations


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
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
namespace ecore 
{
	class EAnnotation;
	class EEnum;
}

// namespace macro header include
#include "ecore/ecore.hpp"

// base class includes
#include "ecore/ENamedElement.hpp"




//*********************************
namespace ecore 
{
	
	class ECORE_API EEnumLiteral: virtual public ENamedElement
	{
		public:
 			EEnumLiteral(const EEnumLiteral &) {}

		protected:
			EEnumLiteral(){}
			//Additional constructors for the containments back reference
			EEnumLiteral(std::weak_ptr<ecore::EObject> par_eContainer);

			//Additional constructors for the containments back reference
			EEnumLiteral(std::weak_ptr<ecore::EEnum> par_eEnum);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EEnumLiteral() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual Any getInstance() const = 0;
			virtual void setInstance (Any _instance)= 0;
			virtual std::string getLiteral() const = 0;
			virtual void setLiteral (std::string _literal)= 0;
			virtual int getValue() const = 0;
			virtual void setValue (int _value)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::weak_ptr<ecore::EEnum> getEEnum() const = 0;

			//*********************************
			// Union Reference Getters
			//*********************************
			virtual std::shared_ptr<Union<ecore::EObject>> getEContentUnion() const = 0;

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			Any m_instance= nullptr;
			std::string m_literal= "";
			int m_value= 0;
			
			//*********************************
			// Reference Members
			//*********************************
			std::weak_ptr<ecore::EEnum> m_eEnum;
	};
}
#endif /* end of include guard: ECORE_EENUMLITERAL_HPP */
