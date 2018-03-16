//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_EXECUTOR_HPP
#define FUML_EXECUTOR_HPP

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
	class Behavior;
}

namespace uml 
{
	class Class;
}

namespace fUML 
{
	class Locus;
}

namespace fUML 
{
	class Object;
}

namespace fUML 
{
	class ParameterValue;
}

namespace fUML 
{
	class Reference;
}

namespace fUML 
{
	class Value;
}

namespace uml 
{
	class ValueSpecification;
}

// base class includes

// enum includes

#include "ecore/EObject.hpp"

//*********************************
namespace fUML 
{
	/*!
	 */
	class Executor : virtual public ecore::EObject 

	{
		public:
 			Executor(const Executor &) {}
			Executor& operator=(Executor const&) = delete;

		protected:
			Executor(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Executor() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> evaluate(std::shared_ptr<uml::ValueSpecification>  specification)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::ParameterValue> > execute(std::shared_ptr<uml::Behavior>  behavior,std::shared_ptr<fUML::Object>  context,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Reference> start(std::shared_ptr<uml::Class>  type,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::Locus > getLocus() const = 0;
			
			/*!
			 */
			virtual void setLocus(std::shared_ptr<fUML::Locus> _locus_locus) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<fUML::Locus > m_locus;
			

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
#endif /* end of include guard: FUML_EXECUTOR_HPP */
