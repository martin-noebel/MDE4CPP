//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXECUTIONOCCURRENCESPECIFICATIONEXECUTIONOCCURRENCESPECIFICATIONIMPL_HPP
#define UML_EXECUTIONOCCURRENCESPECIFICATIONEXECUTIONOCCURRENCESPECIFICATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ExecutionOccurrenceSpecification.hpp"

#include "uml/impl/OccurrenceSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class ExecutionOccurrenceSpecificationImpl : virtual public OccurrenceSpecificationImpl, virtual public ExecutionOccurrenceSpecification 
	{
		public: 
			ExecutionOccurrenceSpecificationImpl(const ExecutionOccurrenceSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ExecutionOccurrenceSpecificationImpl& operator=(ExecutionOccurrenceSpecificationImpl const&) = delete;

		protected:
			friend class umlFactoryImpl;
			ExecutionOccurrenceSpecificationImpl();
			virtual std::shared_ptr<ExecutionOccurrenceSpecification> getThisExecutionOccurrenceSpecificationPtr() const;
			virtual void setThisExecutionOccurrenceSpecificationPtr(std::weak_ptr<ExecutionOccurrenceSpecification> thisExecutionOccurrenceSpecificationPtr);

			//Additional constructors for the containments back reference
			ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction);


			//Additional constructors for the containments back reference
			ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand);


			//Additional constructors for the containments back reference
			ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			ExecutionOccurrenceSpecificationImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~ExecutionOccurrenceSpecificationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			References the execution specification describing the execution that is started or finished at this execution event.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::ExecutionSpecification > getExecution() const ;
			
			/*!
			References the execution specification describing the execution that is started or finished at this execution event.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setExecution(std::shared_ptr<uml::ExecutionSpecification> _execution) ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ExecutionOccurrenceSpecification> m_thisExecutionOccurrenceSpecificationPtr;
	};
}
#endif /* end of include guard: UML_EXECUTIONOCCURRENCESPECIFICATIONEXECUTIONOCCURRENCESPECIFICATIONIMPL_HPP */
