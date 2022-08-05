//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICSFACTORY_HPP
#define FUML_SEMANTICSFACTORY_HPP
// namespace macro header include
#include "fUML/fUML.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

namespace fUML::Semantics::Activities
{
	class ActivityNodeActivationGroup;
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}


namespace fUML::Semantics::Actions
{
	class CallActionActivation;
	class StructuredActivityNodeActivation;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}




namespace fUML::Semantics::Actions
{
	class CallActionActivation;
}
namespace fUML::Semantics::Activities
{
	class DecisionNodeActivation;
	class ObjectToken;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}
namespace fUML::Semantics::StructuredClassifiers
{
	class Object;
}




namespace fUML::Semantics::Activities
{
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ObjectActivation;
	class ParameterValue;
}


namespace fUML::Semantics::Activities
{
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}


namespace fUML::Semantics::Activities
{
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}




namespace fUML::Semantics 
{
	class SemanticsFactoryPluginImpl;
}
namespace fUML::Semantics 
{
	class FUML_API SemanticsFactory : virtual public ecore::EFactory 
	{
		private:    
			SemanticsFactory(SemanticsFactory const&) = delete;
			SemanticsFactory& operator=(SemanticsFactory const&) = delete;
		protected:
			SemanticsFactory(){}
		private:    	
			friend class SemanticsPluginImpl; 
		// Header only sinleton like implemenation for SemanticsFactory eInstance()
		private: 
			static std::shared_ptr<SemanticsFactory>* getSemanticsFactoryStaticPtr()
			{
				static std::shared_ptr<SemanticsFactory> local_instance; 
				return &(local_instance);
			}
		    static void seteInstance(std::shared_ptr<SemanticsFactory> _instance) {*(getSemanticsFactoryStaticPtr())=_instance;}; 
		public:
			static std::shared_ptr<SemanticsFactory> eInstance(){return *(getSemanticsFactoryStaticPtr());}
		
		public:    		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			
	};
}
#endif /* end of include guard: FUML_SEMANTICSFACTORY_HPP */
