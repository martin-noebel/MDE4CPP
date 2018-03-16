//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_OBJECT_HPP
#define FUML_OBJECT_HPP

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
	namespace interface
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace fUML
{
	class FUMLFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class Class;
}

namespace uml 
{
	class Classifier;
}

namespace fUML 
{
	class EventAccepter;
}

namespace fUML 
{
	class Execution;
}

namespace fUML 
{
	class ExtensionalValue;
}

namespace fUML 
{
	class FeatureValue;
}

namespace fUML 
{
	class Locus;
}

namespace fUML 
{
	class ObjectActivation;
}

namespace uml 
{
	class Operation;
}

namespace fUML 
{
	class ParameterValue;
}

namespace fUML 
{
	class SignalInstance;
}

namespace fUML 
{
	class Value;
}

// base class includes
#include "fUML/ExtensionalValue.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class Object:virtual public ExtensionalValue
	{
		public:
 			Object(const Object &) {}
			Object& operator=(Object const&) = delete;

		protected:
			Object(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Object() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void _register(std::shared_ptr<fUML::EventAccepter>  accepter)  = 0;
			
			/*!
			 */ 
			virtual void destroy()  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Execution> dispatch(std::shared_ptr<uml::Operation>  operation)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> new_()  = 0;
			
			/*!
			 */ 
			virtual void send(std::shared_ptr<fUML::SignalInstance>  signalInstance)  = 0;
			
			/*!
			 */ 
			virtual void startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs)  = 0;
			
			/*!
			 */ 
			virtual void unregister(std::shared_ptr<fUML::EventAccepter>  accepter)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::ObjectActivation > getObjectActivation() const = 0;
			
			/*!
			 */
			virtual void setObjectActivation(std::shared_ptr<fUML::ObjectActivation> _objectActivation_objectActivation) = 0;
			/*!
			 */
			virtual std::shared_ptr<Bag<uml::Classifier>> getTypes() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<fUML::ObjectActivation > m_objectActivation;
			/*!
			 */
			std::shared_ptr<Bag<uml::Classifier>> m_types;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_OBJECT_HPP */
