//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ENUMERATION_HPP
#define UML_ENUMERATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


//*********************************
// generated Includes

//Forward Declaration for used types 
namespace uml 
{
	class CollaborationUse;
	class Comment;
	class Constraint;
	class Dependency;
	class ElementImport;
	class EnumerationLiteral;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class Operation;
	class Package;
	class PackageImport;
	class Property;
	class StringExpression;
	class Substitution;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class UseCase;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/DataType.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	An Enumeration is a DataType whose values are enumerated in the model as EnumerationLiterals.
	<p>From package UML::SimpleClassifiers.</p>
	*/
	
	class UML_API Enumeration : virtual public DataType
	{
		public:
 			Enumeration(const Enumeration &) {}

		protected:
			Enumeration(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Enumeration() {}

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
			The ordered set of literals owned by this Enumeration.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::EnumerationLiteral, uml::NamedElement>> getOwnedLiteral() const = 0;

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
			The ordered set of literals owned by this Enumeration.
			<p>From package UML::SimpleClassifiers.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::EnumerationLiteral, uml::NamedElement>> m_ownedLiteral;
	};
}
#endif /* end of include guard: UML_ENUMERATION_HPP */
