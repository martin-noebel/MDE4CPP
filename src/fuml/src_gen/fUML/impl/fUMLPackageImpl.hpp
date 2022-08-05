//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUMLPACKAGEIMPL_HPP
#define FUMLPACKAGEIMPL_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "fUML/fUMLPackage.hpp" 


namespace fUML 
{
	namespace Semantics 
	{
		class SemanticsPackage;
	}

	class fUMLPluginImpl; 
}

namespace ecore
{
	class ecoreFactory;
}

namespace fUML
{
	class FUML_API fUMLPackageImpl : public ecore::EPackageImpl ,virtual public fUMLPackage
	{
		private:    
			fUMLPackageImpl(fUMLPackageImpl const&) = delete;
			fUMLPackageImpl& operator=(fUMLPackageImpl const&) = delete;

		protected:
			fUMLPackageImpl();

		public:
			virtual ~fUMLPackageImpl();


			
			// SubPackages Getters
			virtual std::shared_ptr<fUML::Semantics::SemanticsPackage> getSemantics_Package() const ;
			

		private:
			
			
			
			
			

			friend class fUMLPluginImpl; 

			static bool isInited;
			static fUMLPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: FUMLPACKAGEIMPL_HPP */
