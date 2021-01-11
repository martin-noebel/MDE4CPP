//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EANNOTATION_HPP
#define ECORE_EANNOTATION_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;



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
namespace ecore 
{
	class EAnnotation;
}

namespace ecore 
{
	class EModelElement;
}

namespace ecore 
{
	class EObject;
}

namespace ecore 
{
	class EStringToStringMapEntry;
}

// base class includes
#include "ecore/EModelElement.hpp"

// enum includes


//*********************************
namespace ecore 
{
	
	class EAnnotation:virtual public EModelElement
	{
		public:
 			EAnnotation(const EAnnotation &) {}
			EAnnotation& operator=(EAnnotation const&) = delete;

		protected:
			EAnnotation(){}


			//Additional constructors for the containments back reference

			EAnnotation(std::weak_ptr<ecore::EObject > par_eContainer);

			//Additional constructors for the containments back reference

			EAnnotation(std::weak_ptr<ecore::EModelElement > par_eModelElement);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EAnnotation() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual std::string getSource() const = 0;
			
			 
			virtual void setSource (std::string _source)= 0; 
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Subset<ecore::EObject, ecore::EObject>> getContents() const = 0;
			
			
			
			virtual std::shared_ptr<Bag<ecore::EStringToStringMapEntry>> getDetails() const = 0;
			
			
			
			virtual std::weak_ptr<ecore::EModelElement > getEModelElement() const = 0;
			
			
			virtual void setEModelElement(std::shared_ptr<ecore::EModelElement> _eModelElement) = 0;
			
			
			virtual std::shared_ptr<Bag<ecore::EObject>> getReferences() const = 0;
			
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			 
			std::string m_source = "";
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			mutable std::shared_ptr<Subset<ecore::EObject, ecore::EObject>> m_contents;
			mutable std::shared_ptr<Bag<ecore::EStringToStringMapEntry>> m_details;
			std::weak_ptr<ecore::EModelElement > m_eModelElement;
			mutable std::shared_ptr<Bag<ecore::EObject>> m_references;

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
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: ECORE_EANNOTATION_HPP */
