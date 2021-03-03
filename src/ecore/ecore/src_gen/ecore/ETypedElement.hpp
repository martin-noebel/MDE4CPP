//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ETYPEDELEMENT_HPP
#define ECORE_ETYPEDELEMENT_HPP


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
	class EClassifier;
	class EGenericType;
}

// base class includes
#include "ecore/ENamedElement.hpp"

// enum includes



//*********************************
namespace ecore 
{
	
	class ETypedElement: virtual public ENamedElement
	{
		public:
 			ETypedElement(const ETypedElement &) {}

		protected:
			ETypedElement(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ETypedElement() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual int getLowerBound() const = 0;
			 
			virtual void setLowerBound (int _lowerBound)= 0;
			 
			virtual bool isMany() const = 0;
			
			 
			virtual bool isOrdered() const = 0;
			 
			virtual void setOrdered (bool _ordered)= 0;
			 
			virtual bool isRequired() const = 0;
			 
			virtual void setRequired (bool _required)= 0;
			 
			virtual bool isUnique() const = 0;
			 
			virtual void setUnique (bool _unique)= 0;
			 
			virtual int getUpperBound() const = 0;
			 
			virtual void setUpperBound (int _upperBound)= 0;
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<ecore::EGenericType> getEGenericType() const = 0;
			
			virtual void setEGenericType(std::shared_ptr<ecore::EGenericType>) = 0;
			
			virtual std::shared_ptr<ecore::EClassifier> getEType() const = 0;
			
			virtual void setEType(std::shared_ptr<ecore::EClassifier>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			 
			int m_lowerBound = 0;
			 
			bool m_many = false;
			 
			bool m_ordered = true;
			 
			bool m_required = false;
			 
			bool m_unique = true;
			 
			int m_upperBound = 1;
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<ecore::EGenericType> m_eGenericType;
			std::shared_ptr<ecore::EClassifier> m_eType;

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
#endif /* end of include guard: ECORE_ETYPEDELEMENT_HPP */
