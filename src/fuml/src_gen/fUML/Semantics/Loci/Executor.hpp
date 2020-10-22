//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCI_EXECUTOR_HPP
#define FUML_SEMANTICS_LOCI_EXECUTOR_HPP

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

namespace fUML::Semantics::Loci 
{
	class Locus;
}

namespace fUML::Semantics::StructuredClassifiers 
{
	class Object;
}

namespace fUML::Semantics::CommonBehavior 
{
	class ParameterValue;
}

namespace fUML::Semantics::StructuredClassifiers 
{
	class Reference;
}

namespace fUML::Semantics::Values 
{
	class Value;
}

namespace uml 
{
	class ValueSpecification;
}

// base class includes

// enum includes

#include "ecore/EModelElement.hpp"

//*********************************
namespace fUML::Semantics::Loci 
{
	
	class Executor : virtual public ecore::EModelElement

	{
		public:
 			Executor(const Executor &) {}
			Executor& operator=(Executor const&) = delete;

		protected:
			Executor(){}


			//Additional constructors for the containments back reference

			Executor(std::weak_ptr<fUML::Semantics::Loci::Locus > par_locus);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Executor() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> evaluate(std::shared_ptr<uml::ValueSpecification>  specification) = 0;
			
			 
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > execute(std::shared_ptr<uml::Behavior>  behavior,std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>  context,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> >  inputs) = 0;
			
			 
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> start(std::shared_ptr<uml::Class>  type,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> >  inputs) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::weak_ptr<fUML::Semantics::Loci::Locus > getLocus() const = 0;
			
			
			virtual void setLocus(std::shared_ptr<fUML::Semantics::Loci::Locus> _locus) = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::weak_ptr<fUML::Semantics::Loci::Locus > m_locus;

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_LOCI_EXECUTOR_HPP */
