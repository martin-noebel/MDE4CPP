//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EATTRIBUTE_HPP
#define ECORE_EATTRIBUTE_HPP


#include <memory>
#include <string>
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
	class EClass;
	class EClassifier;
	class EDataType;
	class EGenericType;
}

// base class includes
#include "ecore/EStructuralFeature.hpp"

// enum includes



//*********************************
namespace ecore 
{
	
	class EAttribute: virtual public EStructuralFeature
	{
		public:
 			EAttribute(const EAttribute &) {}

		protected:
			EAttribute(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EAttribute() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual bool isID() const = 0;
			 
			virtual void setID (bool _iD)= 0;
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<ecore::EDataType> getEAttributeType() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			 
			bool m_iD = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<ecore::EDataType> m_eAttributeType;

		public:
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<ecore::EObject>> getEContens() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: ECORE_EATTRIBUTE_HPP */
