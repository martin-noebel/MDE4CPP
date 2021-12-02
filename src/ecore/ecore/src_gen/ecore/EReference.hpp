//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EREFERENCE_HPP
#define ECORE_EREFERENCE_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


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
	class EAttribute;
	class EClass;
	class EClassifier;
	class EGenericType;
}

// namespace macro header include
#include "ecore/ecore.hpp"

// base class includes
#include "ecore/EStructuralFeature.hpp"




//*********************************
namespace ecore 
{
	
	class ECORE_API EReference: virtual public EStructuralFeature
	{
		public:
 			EReference(const EReference &) {}

		protected:
			EReference(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EReference() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************
			virtual bool isContainer() const = 0;
			virtual bool isContainment() const = 0;
			virtual void setContainment (bool _containment)= 0;
			virtual bool isResolveProxies() const = 0;
			virtual void setResolveProxies (bool _resolveProxies)= 0;

			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<ecore::EAttribute>> getEKeys() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEOpposite() const = 0;
			virtual void setEOpposite(std::shared_ptr<ecore::EReference>) = 0;
			virtual std::shared_ptr<ecore::EClass> getEReferenceType() const = 0;
			virtual void setEReferenceType(std::shared_ptr<ecore::EClass>) = 0;

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
			bool m_container= false;
			bool m_containment= false;
			bool m_resolveProxies= true;
			
			//*********************************
			// Reference Members
			//*********************************
			mutable std::shared_ptr<Bag<ecore::EAttribute>> m_eKeys;
			std::shared_ptr<ecore::EReference> m_eOpposite;
			std::shared_ptr<ecore::EClass> m_eReferenceType;
	};
}
#endif /* end of include guard: ECORE_EREFERENCE_HPP */
