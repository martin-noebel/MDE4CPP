//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCI_EXECUTIONFACTORYEXECUTIONFACTORYIMPL_HPP
#define FUML_SEMANTICS_LOCI_EXECUTIONFACTORYEXECUTIONFACTORYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../ExecutionFactory.hpp"

#include "fUML/Semantics/Loci/impl/LociFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::Loci 
{
	class FUML_API ExecutionFactoryImpl : virtual public ecore::EModelElementImpl,
virtual public ExecutionFactory 
	{
		public: 
			ExecutionFactoryImpl(const ExecutionFactoryImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExecutionFactoryImpl& operator=(ExecutionFactoryImpl const&); 

		protected:
			friend class fUML::Semantics::Loci::LociFactoryImpl;
			ExecutionFactoryImpl();
			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> getThisExecutionFactoryPtr() const;
			virtual void setThisExecutionFactoryPtr(std::weak_ptr<fUML::Semantics::Loci::ExecutionFactory> thisExecutionFactoryPtr);

			//Additional constructors for the containments back reference
			ExecutionFactoryImpl(std::weak_ptr<fUML::Semantics::Loci::Locus> par_locus);

		public:
			//destructor
			virtual ~ExecutionFactoryImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void addBuiltInType(std::shared_ptr<uml::PrimitiveType> type) ;
			virtual void addPrimitiveBehaviorPrototype(std::shared_ptr<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution> execution) ;
			virtual void assignStrategy(std::shared_ptr<fUML::Semantics::Loci::SemanticStrategy> strategy) ;
			virtual std::shared_ptr<fUML::Semantics::Values::Evaluation> createEvaluation(std::shared_ptr<uml::ValueSpecification> specification) ;
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> createExecution(std::shared_ptr<uml::Behavior> behavior,std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> context) ;
			virtual std::shared_ptr<uml::PrimitiveType> getBuiltInType(std::string name) ;
			virtual std::shared_ptr<fUML::Semantics::Loci::SemanticStrategy> getStrategy(std::string name) ;
			virtual int getStrategyIndex(std::string name) ;
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution> instantiateOpaqueBehaviorExecution(std::shared_ptr<uml::Behavior> behavior) ;
			virtual std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> instantiateVisitor(std::shared_ptr<uml::Element> element) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<Bag<uml::PrimitiveType>> getBuiltInTypes() const ;
			virtual std::weak_ptr<fUML::Semantics::Loci::Locus> getLocus() const ;
			virtual void setLocus(std::weak_ptr<fUML::Semantics::Loci::Locus>) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::OpaqueBehaviorExecution>> getPrimitiveBehaviorPrototypes() const ;
			virtual std::shared_ptr<Bag<fUML::Semantics::Loci::SemanticStrategy>> getStrategies() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<fUML::Semantics::Loci::ExecutionFactory> m_thisExecutionFactoryPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCI_EXECUTIONFACTORYEXECUTIONFACTORYIMPL_HPP */
