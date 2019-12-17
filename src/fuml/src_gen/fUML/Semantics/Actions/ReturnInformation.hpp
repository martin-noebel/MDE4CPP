//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_RETURNINFORMATION_HPP
#define FUML_SEMANTICS_ACTIONS_RETURNINFORMATION_HPP

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
namespace fUML::Semantics::CommonBehavior 
{
	class CallEventOccurrence;
}

namespace uml 
{
	class Classifier;
}

namespace uml 
{
	class Operation;
}

namespace fUML::Semantics::CommonBehavior 
{
	class ParameterValue;
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
#include "fUML/Semantics/Values/Value.hpp"

// enum includes


//*********************************
namespace fUML::Semantics::Actions 
{
	/*!
	 */
	class ReturnInformation:virtual public fUML::Semantics::Values::Value
	{
		public:
 			ReturnInformation(const ReturnInformation &) {}
			ReturnInformation& operator=(ReturnInformation const&) = delete;

		protected:
			ReturnInformation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ReturnInformation() {}

			//*********************************
			// Operations
			//*********************************
			
			
			/*!
			 */ 
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value>  otherValue) = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<uml::Operation> getOperation() = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<uml::Classifier> > getTypes() = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() = 0;
			
			/*!
			 */ 
			virtual void reply(std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> >  outputParameterValues) = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<uml::ValueSpecification> specify() = 0;
			
			/*!
			 */ 
			virtual std::string toString() = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence > getCallEventOccurrence() const = 0;
			
			/*!
			 */
			virtual void setCallEventOccurrence(std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> _callEventOccurrence_callEventOccurrence) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence > m_callEventOccurrence;
			

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
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_RETURNINFORMATION_HPP */
