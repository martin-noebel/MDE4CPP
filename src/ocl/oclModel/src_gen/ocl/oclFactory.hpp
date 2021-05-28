//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCLFACTORY_HPP
#define OCLFACTORY_HPP

#include <map>
#include <memory>

#include "ecore/EFactory.hpp"
#include "ocl/oclPackage.hpp"

namespace ocl 
{
	class oclPackage;
}


namespace ocl::Expressions 
{
	class CallExp;
	class CollectionRange;
	class ExpressionInOcl;
	class IfExp;
	class IterateExp;
	class LoopExp;
	class NavigationCallExp;
	class OperationCallExp;
	class Variable;
}


namespace ecore 
{
	class EPackage;
}







namespace ocl 
{
	class oclFactory : virtual public ecore::EFactory 
	{
		private:    
			oclFactory(oclFactory const&) = delete;
			oclFactory& operator=(oclFactory const&) = delete;
		protected:
			oclFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<oclFactory> instance;
			public:
				static std::shared_ptr<oclFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			
	};
}
#endif /* end of include guard: OCLFACTORY_HPP */