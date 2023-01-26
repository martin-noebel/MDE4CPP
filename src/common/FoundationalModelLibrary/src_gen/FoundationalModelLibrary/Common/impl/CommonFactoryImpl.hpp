//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef FOUNDATIONALMODELLIBRARY_COMMON_FACTORYIMPL_HPP
#define FOUNDATIONALMODELLIBRARY_COMMON_FACTORYIMPL_HPP

#include <functional>
#include <map>

#include "uml/impl/FactoryImpl.hpp"
#include "FoundationalModelLibrary/Common/CommonFactory.hpp"

namespace FoundationalModelLibrary::Common 
{
	class CommonFactoryImpl : virtual public uml::FactoryImpl , virtual public CommonFactory 
	{
		protected:
			friend class CommonFactory;
			// Constructor
			CommonFactoryImpl();

		public:
			virtual ~CommonFactoryImpl();
			virtual std::shared_ptr<uml::Element> create(const unsigned int _metaClassId,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const;
			virtual std::shared_ptr<uml::Element> create(const std::shared_ptr<uml::Class> _class,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const;
			virtual std::shared_ptr<uml::Element> create(const std::string _className,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const;

			//Creator functions
			//START Create methods for data type Status
			virtual std::shared_ptr<FoundationalModelLibrary::Common::Status> createStatus(const int metaElementID = CommonPackage::STATUS_DATATYPE) const ;
			//END Create methods for data type Status
			
			

			//Package
			virtual std::shared_ptr<CommonPackage> getCommonPackage();

		private:
			static CommonFactory * create();
			std::map<std::string,unsigned int> m_idMap;
			virtual void init() {}
	};
}
#endif /* end of include guard: FOUNDATIONALMODELLIBRARY_COMMON_FACTORYIMPL_HPP */
