//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_REFERENCEREFERENCEIMPL_HPP
#define FUML_REFERENCEREFERENCEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Reference.hpp"

#include "fUML/impl/StructuredValueImpl.hpp"

//*********************************
namespace fUML 
{
	class ReferenceImpl :virtual public StructuredValueImpl, virtual public Reference 
	{
		public: 
			ReferenceImpl(const ReferenceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ReferenceImpl& operator=(ReferenceImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ReferenceImpl();
			virtual std::shared_ptr<Reference> getThisReferencePtr();
			virtual void setThisReferencePtr(std::weak_ptr<Reference> thisReferencePtr);



		public:
			//destructor
			virtual ~ReferenceImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void assignFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Value> >  values,int position)  ;
			
			/*!
			 */ 
			virtual void destroy()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Execution> dispatch(std::shared_ptr<uml::Operation>  operation)  ;
			
			/*!
			 */ 
			virtual bool equals(std::shared_ptr<fUML::Value>  otherValue)  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<uml::Classifier> > getTypes()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> new_()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::FeatureValue> retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature)  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::FeatureValue> > retrieveFeatureValues()  ;
			
			/*!
			 */ 
			virtual void send(std::shared_ptr<fUML::SignalInstance>  signalInstance)  ;
			
			/*!
			 */ 
			virtual void startBehavior(std::shared_ptr<uml::Class>  classifier,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs)  ;
			
			/*!
			 */ 
			virtual std::string toString()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::Object > getReferent() const ;
			
			/*!
			 */
			virtual void setReferent(std::shared_ptr<fUML::Object> _referent_referent) ;
							
			
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
			std::weak_ptr<Reference> m_thisReferencePtr;
	};
}
#endif /* end of include guard: FUML_REFERENCEREFERENCEIMPL_HPP */
