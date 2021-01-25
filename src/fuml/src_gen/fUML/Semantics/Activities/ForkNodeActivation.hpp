//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_FORKNODEACTIVATION_HPP
#define FUML_SEMANTICS_ACTIVITIES_FORKNODEACTIVATION_HPP

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
	class fUMLFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityNodeActivationGroup;
	class Token;
}
namespace uml 
{
	class ActivityNode;
}

// base class includes
#include "fUML/Semantics/Activities/ControlNodeActivation.hpp"

// enum includes


//Includes from codegen annotation
#include "fUML/Semantics/Activities/ForkedToken.hpp"
#include "fUML/FUMLFactory.hpp"
#include"uml/ActivityNode.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	
	class ForkNodeActivation:virtual public ControlNodeActivation
	{
		public:
 			ForkNodeActivation(const ForkNodeActivation &) {}
			ForkNodeActivation& operator=(ForkNodeActivation const&) = delete;

		protected:
			ForkNodeActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ForkNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > incomingTokens) = 0;
			
			 
			virtual void terminate() = 0;
			
			
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
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_FORKNODEACTIVATION_HPP */
