//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_CLASSIFICATIONFACTORYIMPL_HPP
#define FUML_SEMANTICS_CLASSIFICATIONFACTORYIMPL_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "fUML/Semantics/Classification/ClassificationFactory.hpp"

namespace Classification 
{	class InstanceValueEvaluation;
}

namespace fUML::Semantics::Classification 
{
	class FUML_API ClassificationFactoryImpl : virtual public ecore::EFactoryImpl , virtual public ClassificationFactory 
	{
		private:    
			ClassificationFactoryImpl(ClassificationFactoryImpl const&) = delete;
			ClassificationFactoryImpl& operator=(ClassificationFactoryImpl const&) = delete;

		protected:
			friend class ClassificationPluginImpl;  
			// Constructor
			ClassificationFactoryImpl();

		public:
			virtual ~ClassificationFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<fUML::Semantics::Classification::InstanceValueEvaluation> createInstanceValueEvaluation(const int metaElementID = ClassificationPackage::INSTANCEVALUEEVALUATION_CLASS) const ;
			 

		private:
			static ClassificationFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_CLASSIFICATIONFACTORYIMPL_HPP */
