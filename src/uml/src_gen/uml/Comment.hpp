//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_COMMENT_HPP
#define UML_COMMENT_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 



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

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 

// base class includes
#include "uml/Element.hpp"

// enum includes


//Includes from codegen annotation

//*********************************
namespace uml 
{
	/*!
	A Comment is a textual annotation that can be attached to a set of Elements.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class Comment:virtual public Element
	{
		public:
 			Comment(const Comment &) {}
			Comment& operator=(Comment const&) = delete;

		protected:
			Comment(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Comment() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			Specifies a string that is the comment.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::string  getBody() const = 0;
			
			/*!
			Specifies a string that is the comment.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setBody (std::string  _body)= 0; 
			
			//*********************************
			// Reference
			//*********************************
			/*!
			References the Element(s) being commented.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Element>> getAnnotatedElement() const = 0;
			
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			Specifies a string that is the comment.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			std::string  m_body = "";
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			References the Element(s) being commented.
			<p>From package UML::CommonStructure.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Element>> m_annotatedElement;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_COMMENT_HPP */
