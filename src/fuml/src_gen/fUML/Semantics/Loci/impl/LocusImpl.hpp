//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCI_LOCUSLOCUSIMPL_HPP
#define FUML_SEMANTICS_LOCI_LOCUSLOCUSIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../Locus.hpp"

#include "fUML/Semantics/Loci/impl/LociFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::Loci 
{
	class FUML_API LocusImpl : virtual public ecore::EModelElementImpl,
virtual public Locus 
	{
		public: 
			LocusImpl(const LocusImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LocusImpl& operator=(LocusImpl const&); 

		protected:
			friend class fUML::Semantics::Loci::LociFactoryImpl;
			LocusImpl();
			virtual std::shared_ptr<fUML::Semantics::Loci::Locus> getThisLocusPtr() const;
			virtual void setThisLocusPtr(std::weak_ptr<fUML::Semantics::Loci::Locus> thisLocusPtr);


		public:
			//destructor
			virtual ~LocusImpl();
			
			//*********************************
			// Operations
			//*********************************
			virtual void add(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value) ;
			virtual void assignExecutor(std::shared_ptr<fUML::Semantics::Loci::Executor> executor) ;
			virtual void assignFactory(std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> factory) ;
			virtual bool conforms(std::shared_ptr<uml::Classifier> type,std::shared_ptr<uml::Classifier> classifier) ;
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> instantiate(std::shared_ptr<uml::Class> type) ;
			virtual void remove(std::shared_ptr<fUML::Semantics::StructuredClassifiers::ExtensionalValue> value) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue> > retrieveExtent(std::shared_ptr<uml::Classifier> classifier) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			virtual std::shared_ptr<fUML::Semantics::Loci::Executor> getExecutor() const ;
			virtual void setExecutor(std::shared_ptr<fUML::Semantics::Loci::Executor>) ;
			virtual std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::ExtensionalValue>> getExtensionalValues() const ;
			virtual std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory> getFactory() const ;
			virtual void setFactory(std::shared_ptr<fUML::Semantics::Loci::ExecutionFactory>) ;
			
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
			std::weak_ptr<fUML::Semantics::Loci::Locus> m_thisLocusPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCI_LOCUSLOCUSIMPL_HPP */
