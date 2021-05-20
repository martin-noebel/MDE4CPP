//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CALLBEHAVIORACTIONCALLBEHAVIORACTIONIMPL_HPP
#define UML_CALLBEHAVIORACTIONCALLBEHAVIORACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../CallBehaviorAction.hpp"

#include "uml/impl/CallActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API CallBehaviorActionImpl : virtual public CallActionImpl, virtual public CallBehaviorAction 
	{
		public: 
			CallBehaviorActionImpl(const CallBehaviorActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CallBehaviorActionImpl& operator=(CallBehaviorActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			CallBehaviorActionImpl();
			virtual std::shared_ptr<CallBehaviorAction> getThisCallBehaviorActionPtr() const;
			virtual void setThisCallBehaviorActionPtr(std::weak_ptr<CallBehaviorAction> thisCallBehaviorActionPtr);

			//Additional constructors for the containments back reference
			CallBehaviorActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			CallBehaviorActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			CallBehaviorActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			CallBehaviorActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~CallBehaviorActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			A CallBehaviorAction may not specify onPort.
			onPort=null
			*/
			 
			virtual bool no_onport(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The Behavior being invoked.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior> getBehavior() const ;
			/*!
			The Behavior being invoked.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setBehavior(std::shared_ptr<uml::Behavior>) ;
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;/*!
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ; 
			 
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
			std::weak_ptr<CallBehaviorAction> m_thisCallBehaviorActionPtr;
	};
}
#endif /* end of include guard: UML_CALLBEHAVIORACTIONCALLBEHAVIORACTIONIMPL_HPP */
