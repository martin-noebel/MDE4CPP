//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_RELATIONSHIP_HPP
#define UML_RELATIONSHIP_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) /**/
#else
    #define ACT_DEBUG(a) a
#endif

#include <string>
#include <map>
#include <vector>
#include "SubsetUnion.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace uml 
{
	class Comment;
}

namespace ecore 
{
	class EAnnotation;
}

namespace uml 
{
	class Element;
}

// base class includes
#include "Element.hpp"

// enum includes


//*********************************
namespace uml 
{
	/*!
	 Relationship is an abstract concept that specifies some kind of relationship between Elements.
	<p>From package UML::CommonStructure.</p> */
	class Relationship:virtual public Element	{
		public:
 			Relationship(const Relationship &) {}
			Relationship& operator=(Relationship const&) = delete;
	
		protected:
			Relationship(){}

		public:
			virtual ecore::EObject* copy() const = 0;

			//destructor
			virtual ~Relationship() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p> */
					std::shared_ptr<Union<uml::Element> > m_relatedElement;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getRelatedElement() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const = 0; 
	};

}
#endif /* end of include guard: UML_RELATIONSHIP_HPP */

