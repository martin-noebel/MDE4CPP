//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_BEHAVIORALFEATUREBEHAVIORALFEATUREIMPL_HPP
#define UML_BEHAVIORALFEATUREBEHAVIORALFEATUREIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../BehavioralFeature.hpp"

#include "uml/impl/FeatureImpl.hpp"
#include "uml/impl/NamespaceImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API BehavioralFeatureImpl : virtual public FeatureImpl, virtual public NamespaceImpl, virtual public BehavioralFeature 
	{
		public: 
			BehavioralFeatureImpl(const BehavioralFeatureImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			BehavioralFeatureImpl& operator=(BehavioralFeatureImpl const&); 

		protected:
			friend class umlFactoryImpl;
			BehavioralFeatureImpl();
			virtual std::shared_ptr<BehavioralFeature> getThisBehavioralFeaturePtr() const;
			virtual void setThisBehavioralFeaturePtr(std::weak_ptr<BehavioralFeature> thisBehavioralFeaturePtr);

			//Additional constructors for the containments back reference
			BehavioralFeatureImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			BehavioralFeatureImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~BehavioralFeatureImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			When isAbstract is true there are no methods.
			isAbstract implies method->isEmpty()
			*/
			 
			virtual bool abstract_no_method(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			Creates a return result parameter with the specified name and type.
			*/
			 
			virtual std::shared_ptr<uml::Parameter> createReturnResult(std::string name,std::shared_ptr<uml::Type> type) ;/*!
			The ownedParameters with direction in and inout.
			result = (ownedParameter->select(direction=ParameterDirectionKind::_'in' or direction=ParameterDirectionKind::inout))
			<p>From package UML::Classification.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Parameter> > inputParameters() ;/*!
			The ownedParameters with direction out, inout, or return.
			result = (ownedParameter->select(direction=ParameterDirectionKind::out or direction=ParameterDirectionKind::inout or direction=ParameterDirectionKind::return))
			<p>From package UML::Classification.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Parameter> > outputParameters() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			Specifies the semantics of concurrent calls to the same passive instance (i.e., an instance originating from a Class with isActive being false). Active instances control access to their own BehavioralFeatures.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual uml::CallConcurrencyKind getConcurrency() const ;
			/*!
			Specifies the semantics of concurrent calls to the same passive instance (i.e., an instance originating from a Class with isActive being false). Active instances control access to their own BehavioralFeatures.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setConcurrency (uml::CallConcurrencyKind _concurrency);
			/*!
			If true, then the BehavioralFeature does not have an implementation, and one must be supplied by a more specific Classifier. If false, the BehavioralFeature must have an implementation in the Classifier or one must be inherited.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getIsAbstract() const ;
			/*!
			If true, then the BehavioralFeature does not have an implementation, and one must be supplied by a more specific Classifier. If false, the BehavioralFeature must have an implementation in the Classifier or one must be inherited.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setIsAbstract (bool _isAbstract);
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			A Behavior that implements the BehavioralFeature. There may be at most one Behavior for a particular pairing of a Classifier (as owner of the Behavior) and a BehavioralFeature (as specification of the Behavior).
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Behavior>> getMethod() const ;
			
			/*!
			The ordered set of formal Parameters of this BehavioralFeature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Parameter, uml::NamedElement>> getOwnedParameter() const ;
			
			/*!
			The ParameterSets owned by this BehavioralFeature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ParameterSet, uml::NamedElement>> getOwnedParameterSet() const ;
			
			/*!
			The Types representing exceptions that may be raised during an invocation of this BehavioralFeature.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Type>> getRaisedException() const ;
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<BehavioralFeature> m_thisBehavioralFeaturePtr;
	};
}
#endif /* end of include guard: UML_BEHAVIORALFEATUREBEHAVIORALFEATUREIMPL_HPP */
