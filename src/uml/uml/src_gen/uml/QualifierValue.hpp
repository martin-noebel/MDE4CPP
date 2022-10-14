//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_QUALIFIERVALUE_HPP
#define UML_QUALIFIERVALUE_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace uml 
{
	class Comment;
	class InputPin;
	class Property;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Element.hpp"




//*********************************
namespace uml 
{
	/*!
	A QualifierValue is an Element that is used as part of LinkEndData to provide the value for a single qualifier of the end given by the LinkEndData.
	<p>From package UML::Actions.</p>
	*/
	
	class UML_API QualifierValue : virtual public Element
	{
		public:
 			QualifierValue(const QualifierValue &) {}

		protected:
			QualifierValue(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~QualifierValue() {}

			//*********************************
			// Operations
			//*********************************

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The qualifier Property for which the value is to be specified.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Property> getQualifier() const = 0;
			/*!
			The qualifier Property for which the value is to be specified.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setQualifier(std::shared_ptr<uml::Property>) = 0;
			/*!
			The InputPin from which the specified value for the qualifier is taken.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getValue() const = 0;
			/*!
			The InputPin from which the specified value for the qualifier is taken.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setValue(std::shared_ptr<uml::InputPin>) = 0;

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The qualifier Property for which the value is to be specified.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::Property> m_qualifier;
			/*!
			The InputPin from which the specified value for the qualifier is taken.
			<p>From package UML::Actions.</p>
			*/
			
			std::shared_ptr<uml::InputPin> m_value;
	};
}
#endif /* end of include guard: UML_QUALIFIERVALUE_HPP */
