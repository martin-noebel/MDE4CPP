//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PARAMETER_HPP
#define UML_PARAMETER_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 
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
	class Behavior;
	class Comment;
	class ConnectorEnd;
	class Dependency;
	class Namespace;
	class Operation;
	class ParameterSet;
	class StringExpression;
	class TemplateParameter;
	class Type;
	class ValueSpecification;
}

// base class includes
#include "uml/ConnectableElement.hpp"

#include "uml/MultiplicityElement.hpp"

// enum includes
#include "uml/ParameterDirectionKind.hpp"

#include "uml/ParameterEffectKind.hpp"

#include "uml/VisibilityKind.hpp"


//Includes from codegen annotation

//*********************************
namespace uml 
{
	/*!
	A Parameter is a specification of an argument used to pass information into or out of an invocation of a BehavioralFeature.  Parameters can be treated as ConnectableElements within Collaborations.
	<p>From package UML::Classification.</p>
	*/
	
	class Parameter:virtual public ConnectableElement,virtual public MultiplicityElement
	{
		public:
 			Parameter(const Parameter &) {}
			Parameter& operator=(Parameter const&) = delete;

		protected:
			Parameter(){}


			//Additional constructors for the containments back reference

			Parameter(std::weak_ptr<uml::Behavior > par_behavior);

			//Additional constructors for the containments back reference

			Parameter(std::weak_ptr<uml::Namespace > par_namespace);

			//Additional constructors for the containments back reference

			Parameter(std::weak_ptr<uml::Operation > par_operation);

			//Additional constructors for the containments back reference

			Parameter(std::weak_ptr<uml::Element > par_owner);

			//Additional constructors for the containments back reference

			Parameter(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Parameter() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			A Parameter may only be associated with a Connector end within the context of a Collaboration.
			end->notEmpty() implies collaboration->notEmpty()
			*/
			 
			virtual bool connector_end(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			Only in and inout Parameters may have a delete effect. Only out, inout, and return Parameters may have a create effect.
			(effect = ParameterEffectKind::delete implies (direction = ParameterDirectionKind::_'in' or direction = ParameterDirectionKind::inout))
			and
			(effect = ParameterEffectKind::create implies (direction = ParameterDirectionKind::out or direction = ParameterDirectionKind::inout or direction = ParameterDirectionKind::return))
			*/
			 
			virtual bool in_and_out(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			 
			virtual bool isSetDefault() = 0;
			
			/*!
			An input Parameter cannot be an exception.
			isException implies (direction <> ParameterDirectionKind::_'in' and direction <> ParameterDirectionKind::inout)
			*/
			 
			virtual bool not_exception(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			Parameters typed by DataTypes cannot have an effect.
			(type.oclIsKindOf(DataType)) implies (effect = null)
			*/
			 
			virtual bool object_effect(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			Reentrant behaviors cannot have stream Parameters.
			(isStream and behavior <> null) implies not behavior.isReentrant
			*/
			 
			virtual bool reentrant_behaviors(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			/*!
			Sets the default value for this parameter to the specified Boolean value.
			*/
			 
			virtual void setBooleanDefaultValue(bool value) = 0;
			
			/*!
			Sets the default value for this parameter to the specified integer value.
			*/
			 
			virtual void setIntegerDefaultValue(int value) = 0;
			
			/*!
			Sets the default value for this parameter to the null value.
			*/
			 
			virtual void setNullDefaultValue() = 0;
			
			/*!
			Sets the default value for this parameter to the specified real value.
			*/
			 
			virtual void setRealDefaultValue(double value) = 0;
			
			/*!
			Sets the default value for this parameter to the specified string value.
			*/
			 
			virtual void setStringDefaultValue(std::string value) = 0;
			
			/*!
			Sets the default value for this parameter to the specified unlimited natural value.
			*/
			 
			virtual void setUnlimitedNaturalDefaultValue(int value) = 0;
			
			/*!
			A Parameter cannot be a stream and exception at the same time.
			not (isException and isStream)
			*/
			 
			virtual bool stream_and_exception(Any diagnostics,std::map <  Any ,  Any > context) = 0;
			
			 
			virtual void unsetDefault() = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			A String that represents a value to be used when no argument is supplied for the Parameter.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual std::string  getDefault() const = 0;
			
			/*!
			A String that represents a value to be used when no argument is supplied for the Parameter.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setDefault (std::string  _default)= 0; 
			/*!
			Indicates whether a parameter is being sent into or out of a behavioral element.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual uml::ParameterDirectionKind  getDirection() const = 0;
			
			/*!
			Indicates whether a parameter is being sent into or out of a behavioral element.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setDirection (uml::ParameterDirectionKind  _direction)= 0; 
			/*!
			Specifies the effect that executions of the owner of the Parameter have on objects passed in or out of the parameter.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual uml::ParameterEffectKind  getEffect() const = 0;
			
			/*!
			Specifies the effect that executions of the owner of the Parameter have on objects passed in or out of the parameter.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setEffect (uml::ParameterEffectKind  _effect)= 0; 
			/*!
			Tells whether an output parameter may emit a value to the exclusion of the other outputs.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool  getIsException() const = 0;
			
			/*!
			Tells whether an output parameter may emit a value to the exclusion of the other outputs.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsException (bool  _isException)= 0; 
			/*!
			Tells whether an input parameter may accept values while its behavior is executing, or whether an output parameter may post values while the behavior is executing.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool  getIsStream() const = 0;
			
			/*!
			Tells whether an input parameter may accept values while its behavior is executing, or whether an output parameter may post values while the behavior is executing.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsStream (bool  _isStream)= 0; 
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::weak_ptr<uml::Behavior > getBehavior() const = 0;
			
			
			virtual void setBehavior(std::shared_ptr<uml::Behavior> _behavior) = 0;
			
			/*!
			Specifies a ValueSpecification that represents a value to be used when no argument is supplied for the Parameter.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification > getDefaultValue() const = 0;
			
			/*!
			Specifies a ValueSpecification that represents a value to be used when no argument is supplied for the Parameter.
			<p>From package UML::Classification.</p>
			*/
			
			virtual void setDefaultValue(std::shared_ptr<uml::ValueSpecification> _defaultValue) = 0;
			
			/*!
			The Operation owning this parameter.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::weak_ptr<uml::Operation > getOperation() const = 0;
			
			
			/*!
			The ParameterSets containing the parameter. See ParameterSet.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ParameterSet>> getParameterSet() const = 0;
			
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			A String that represents a value to be used when no argument is supplied for the Parameter.
			<p>From package UML::Classification.</p>
			*/
			 
			std::string  m_default = "";
			/*!
			Indicates whether a parameter is being sent into or out of a behavioral element.
			<p>From package UML::Classification.</p>
			*/
			 
			uml::ParameterDirectionKind  m_direction = ParameterDirectionKind::IN;
			/*!
			Specifies the effect that executions of the owner of the Parameter have on objects passed in or out of the parameter.
			<p>From package UML::Classification.</p>
			*/
			 
			uml::ParameterEffectKind  m_effect = ParameterEffectKind::CREATE;
			/*!
			Tells whether an output parameter may emit a value to the exclusion of the other outputs.
			<p>From package UML::Classification.</p>
			*/
			 
			bool  m_isException = false;
			/*!
			Tells whether an input parameter may accept values while its behavior is executing, or whether an output parameter may post values while the behavior is executing.
			<p>From package UML::Classification.</p>
			*/
			 
			bool  m_isStream = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::weak_ptr<uml::Behavior > m_behavior;/*!
			Specifies a ValueSpecification that represents a value to be used when no argument is supplied for the Parameter.
			<p>From package UML::Classification.</p>
			*/
			
			std::shared_ptr<uml::ValueSpecification > m_defaultValue;/*!
			The Operation owning this parameter.
			<p>From package UML::Classification.</p>
			*/
			
			std::weak_ptr<uml::Operation > m_operation;/*!
			The ParameterSets containing the parameter. See ParameterSet.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::ParameterSet>> m_parameterSet;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace > getNamespace() const = 0;/*!
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
#endif /* end of include guard: UML_PARAMETER_HPP */
