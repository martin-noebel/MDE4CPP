//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_FIRSTCHOICESTRATEGY_HPP
#define FUML_FIRSTCHOICESTRATEGY_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations



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
	class ChoiceStrategy;
}

// base class includes
#include "fUML/ChoiceStrategy.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class FirstChoiceStrategy:virtual public ChoiceStrategy
	{
		public:
 			FirstChoiceStrategy(const FirstChoiceStrategy &) {}
			FirstChoiceStrategy& operator=(FirstChoiceStrategy const&) = delete;

		protected:
			FirstChoiceStrategy(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~FirstChoiceStrategy() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual int choose(int size)  = 0;
			
			
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
#endif /* end of include guard: FUML_FIRSTCHOICESTRATEGY_HPP */
