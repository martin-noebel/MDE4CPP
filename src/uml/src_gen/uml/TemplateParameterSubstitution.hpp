//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATEPARAMETERSUBSTITUTION_HPP
#define UML_TEMPLATEPARAMETERSUBSTITUTION_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T, class ... U> class Subset;


class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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
namespace uml 
{
	class Comment;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class ParameterableElement;
}

namespace uml 
{
	class TemplateBinding;
}

namespace uml 
{
	class TemplateParameter;
}

// base class includes
#include "uml/Element.hpp"

// enum includes


//*********************************
namespace uml 
{
	/*!
	A TemplateParameterSubstitution relates the actual parameter to a formal TemplateParameter as part of a template binding.
	<p>From package UML::CommonStructure.</p>
	*/
	
	class TemplateParameterSubstitution:virtual public Element
	{
		public:
 			TemplateParameterSubstitution(const TemplateParameterSubstitution &) {}
			TemplateParameterSubstitution& operator=(TemplateParameterSubstitution const&) = delete;

		protected:
			TemplateParameterSubstitution(){}


			//Additional constructors for the containments back reference

			TemplateParameterSubstitution(std::weak_ptr<uml::Element > par_owner);

			//Additional constructors for the containments back reference

			TemplateParameterSubstitution(std::weak_ptr<uml::TemplateBinding > par_templateBinding);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~TemplateParameterSubstitution() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The actual ParameterableElement must be compatible with the formal TemplateParameter, e.g., the actual ParameterableElement for a Class TemplateParameter must be a Class.
			actual->forAll(a | a.isCompatibleWith(formal.parameteredElement))
			*/
			 
			virtual bool must_be_compatible(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The ParameterableElement that is the actual parameter for this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ParameterableElement > getActual() const = 0;
			
			/*!
			The ParameterableElement that is the actual parameter for this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setActual(std::shared_ptr<uml::ParameterableElement> _actual) = 0;
			
			/*!
			The formal TemplateParameter that is associated with this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::TemplateParameter > getFormal() const = 0;
			
			/*!
			The formal TemplateParameter that is associated with this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setFormal(std::shared_ptr<uml::TemplateParameter> _formal) = 0;
			
			/*!
			The ParameterableElement that is owned by this TemplateParameterSubstitution as its actual parameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ParameterableElement > getOwnedActual() const = 0;
			
			/*!
			The ParameterableElement that is owned by this TemplateParameterSubstitution as its actual parameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setOwnedActual(std::shared_ptr<uml::ParameterableElement> _ownedActual) = 0;
			
			/*!
			The TemplateBinding that owns this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::TemplateBinding > getTemplateBinding() const = 0;
			
			/*!
			The TemplateBinding that owns this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setTemplateBinding(std::shared_ptr<uml::TemplateBinding> _templateBinding) = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The ParameterableElement that is the actual parameter for this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::ParameterableElement > m_actual;/*!
			The formal TemplateParameter that is associated with this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::TemplateParameter > m_formal;/*!
			The ParameterableElement that is owned by this TemplateParameterSubstitution as its actual parameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::shared_ptr<uml::ParameterableElement > m_ownedActual;/*!
			The TemplateBinding that owns this TemplateParameterSubstitution.
			<p>From package UML::CommonStructure.</p>
			*/
			
			std::weak_ptr<uml::TemplateBinding > m_templateBinding;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_TEMPLATEPARAMETERSUBSTITUTION_HPP */
