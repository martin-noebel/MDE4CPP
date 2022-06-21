//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EFACTORY_HPP
#define ECORE_EFACTORY_HPP


#include <memory>
#include <string>
// forward declarations

class Any;

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
	class EClass;
	class EDataType;
	class EPackage;
}

// namespace macro header include
#include "ecore/ecore.hpp"

// base class includes
#include "ecore/EModelElement.hpp"




//*********************************
namespace ecore 
{
	
	class ECORE_API EFactory : virtual public EModelElement
	{
		public:
 			EFactory(const EFactory &) {}

		protected:
			EFactory(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EFactory() {}

			//*********************************
			// Operations
			//*********************************
			virtual std::string convertToString(std::shared_ptr<ecore::EDataType> eDataType, std::shared_ptr<Any> instanceValue) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> eClass) const = 0;
			virtual std::shared_ptr<Any> createFromString(std::shared_ptr<ecore::EDataType> eDataType, std::string literalValue) const = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<ecore::EPackage> getEPackage() const = 0;
			virtual void setEPackage(std::shared_ptr<ecore::EPackage>) = 0;

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
			
			//*********************************
			// Reference Members
			//*********************************
			std::shared_ptr<ecore::EPackage> m_ePackage;
	};
}
#endif /* end of include guard: ECORE_EFACTORY_HPP */
