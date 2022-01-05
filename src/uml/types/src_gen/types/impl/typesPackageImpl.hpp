//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef TYPESPACKAGEIMPL_HPP
#define TYPESPACKAGEIMPL_HPP

// namespace macro header include
#include "types/types.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "types/typesPackage.hpp" 


namespace types 
{
}

namespace ecore
{
	class ecoreFactory;
}

namespace types
{
	class TYPES_API typesPackageImpl : public ecore::EPackageImpl ,virtual public typesPackage
	{
		private:    
			typesPackageImpl(typesPackageImpl const&) = delete;
			typesPackageImpl& operator=(typesPackageImpl const&) = delete;

		protected:
			typesPackageImpl();

		public:
			virtual ~typesPackageImpl();


			virtual std::shared_ptr<ecore::EDataType> getBoolean_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getInteger_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getReal_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getString_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getUnlimitedNatural_Class() const ;
			virtual std::shared_ptr<ecore::EDataType> getAny_Class() const ;
			
			// SubPackages Getters
			

		private:
			
			std::shared_ptr<ecore::EDataType> m_any_Class = nullptr;std::shared_ptr<ecore::EDataType> m_boolean_Class = nullptr;std::shared_ptr<ecore::EDataType> m_integer_Class = nullptr;std::shared_ptr<ecore::EDataType> m_real_Class = nullptr;std::shared_ptr<ecore::EDataType> m_string_Class = nullptr;std::shared_ptr<ecore::EDataType> m_unlimitedNatural_Class = nullptr;
			
			
			

			friend class typesPackage;

			static bool isInited;
			static typesPackage* create();
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
#endif /* end of include guard: TYPESPACKAGEIMPL_HPP */