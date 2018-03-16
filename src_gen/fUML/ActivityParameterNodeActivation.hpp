//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_ACTIVITYPARAMETERNODEACTIVATION_HPP
#define FUML_ACTIVITYPARAMETERNODEACTIVATION_HPP

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
namespace fUML 
{
	class ActivityEdgeInstance;
}

namespace uml 
{
	class ActivityNode;
}

namespace fUML 
{
	class ActivityNodeActivationGroup;
}

namespace fUML 
{
	class ObjectNodeActivation;
}

namespace fUML 
{
	class Token;
}

// base class includes
#include "fUML/ObjectNodeActivation.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class ActivityParameterNodeActivation:virtual public ObjectNodeActivation
	{
		public:
 			ActivityParameterNodeActivation(const ActivityParameterNodeActivation &) {}
			ActivityParameterNodeActivation& operator=(ActivityParameterNodeActivation const&) = delete;

		protected:
			ActivityParameterNodeActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityParameterNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void clearTokens()  = 0;
			
			/*!
			 */ 
			virtual void fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens)  = 0;
			
			
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
#endif /* end of include guard: FUML_ACTIVITYPARAMETERNODEACTIVATION_HPP */
