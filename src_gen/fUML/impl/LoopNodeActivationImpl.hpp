//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_LOOPNODEACTIVATIONLOOPNODEACTIVATIONIMPL_HPP
#define FUML_LOOPNODEACTIVATIONLOOPNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../LoopNodeActivation.hpp"

#include "fUML/impl/StructuredActivityNodeActivationImpl.hpp"

//*********************************
namespace fUML 
{
	class LoopNodeActivationImpl :virtual public StructuredActivityNodeActivationImpl, virtual public LoopNodeActivation 
	{
		public: 
			LoopNodeActivationImpl(const LoopNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			LoopNodeActivationImpl& operator=(LoopNodeActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			LoopNodeActivationImpl();
			virtual std::shared_ptr<LoopNodeActivation> getThisLoopNodeActivationPtr();
			virtual void setThisLoopNodeActivationPtr(std::weak_ptr<LoopNodeActivation> thisLoopNodeActivationPtr);

			//Additional constructors for the containments back reference
			LoopNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~LoopNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<uml::ActivityNode> makeLoopVariableList()  ;
			
			/*!
			 */ 
			virtual void runBody()  ;
			
			/*!
			 */ 
			virtual void runLoopVariables()  ;
			
			/*!
			 */ 
			virtual bool runTest()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<Bag<fUML::Values>> getBodyOutputLists() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<Union<fUML::PinActivation>> getPinActivation() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<LoopNodeActivation> m_thisLoopNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_LOOPNODEACTIVATIONLOOPNODEACTIVATIONIMPL_HPP */
