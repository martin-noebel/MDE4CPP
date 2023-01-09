//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERSFACTORYIMPL_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERSFACTORYIMPL_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"

namespace SimpleClassifiers 
{
}

namespace fUML::Semantics::SimpleClassifiers 
{
	class FUML_API SimpleClassifiersFactoryImpl : virtual public ecore::EFactoryImpl , virtual public SimpleClassifiersFactory 
	{
		private:    
			SimpleClassifiersFactoryImpl(SimpleClassifiersFactoryImpl const&) = delete;
			SimpleClassifiersFactoryImpl& operator=(SimpleClassifiersFactoryImpl const&) = delete;

		protected:
			friend class SimpleClassifiersFactory;
			// Constructor
			SimpleClassifiersFactoryImpl();

		public:
			virtual ~SimpleClassifiersFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 

		private:
			static SimpleClassifiersFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERSFACTORYIMPL_HPP */
