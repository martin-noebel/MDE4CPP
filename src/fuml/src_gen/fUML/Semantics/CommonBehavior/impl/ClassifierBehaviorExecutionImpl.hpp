//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_CLASSIFIERBEHAVIOREXECUTIONCLASSIFIERBEHAVIOREXECUTIONIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_CLASSIFIERBEHAVIOREXECUTIONCLASSIFIERBEHAVIOREXECUTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ClassifierBehaviorExecution.hpp"

#include "fUML/impl/FUMLFactoryImpl.hpp"

#include "ecore/impl/EObjectImpl.hpp"

//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	class ClassifierBehaviorExecutionImpl :virtual public ecore::EObjectImpl,
virtual public ClassifierBehaviorExecution 
	{
		public: 
			ClassifierBehaviorExecutionImpl(const ClassifierBehaviorExecutionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ClassifierBehaviorExecutionImpl& operator=(ClassifierBehaviorExecutionImpl const&) = delete;

		protected:
			friend class fUML::FUMLFactoryImpl;
			ClassifierBehaviorExecutionImpl();
			virtual std::shared_ptr<ClassifierBehaviorExecution> getThisClassifierBehaviorExecutionPtr() const;
			virtual void setThisClassifierBehaviorExecutionPtr(std::weak_ptr<ClassifierBehaviorExecution> thisClassifierBehaviorExecutionPtr);



		public:
			//destructor
			virtual ~ClassifierBehaviorExecutionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void _startObjectBehavior() ;
			
			/*!
			 */ 
			virtual void execute(std::shared_ptr<Bag<uml::Class> >  classifier,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> >  inputs) ;
			
			/*!
			 */ 
			virtual void terminate() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<uml::Class > getClassifier() const ;
			
			/*!
			 */
			virtual void setClassifier(std::shared_ptr<uml::Class> _classifier_classifier) ;
			/*!
			 */
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution > getExecution() const ;
			
			/*!
			 */
			virtual void setExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _execution_execution) ;
			/*!
			 */
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation > getObjectActivation() const ;
			
			/*!
			 */
			virtual void setObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> _objectActivation_objectActivation) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
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
			std::weak_ptr<ClassifierBehaviorExecution> m_thisClassifierBehaviorExecutionPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_CLASSIFIERBEHAVIOREXECUTIONCLASSIFIERBEHAVIOREXECUTIONIMPL_HPP */