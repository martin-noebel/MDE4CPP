//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STRUCTUREDACTIVITYNODESTRUCTUREDACTIVITYNODEIMPL_HPP
#define UML_STRUCTUREDACTIVITYNODESTRUCTUREDACTIVITYNODEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../StructuredActivityNode.hpp"

#include "uml/impl/ActionImpl.hpp"
#include "uml/impl/ActivityGroupImpl.hpp"
#include "uml/impl/NamespaceImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API StructuredActivityNodeImpl : virtual public ActionImpl, virtual public ActivityGroupImpl, virtual public NamespaceImpl, virtual public StructuredActivityNode 
	{
		public: 
			StructuredActivityNodeImpl(const StructuredActivityNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			StructuredActivityNodeImpl& operator=(StructuredActivityNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			StructuredActivityNodeImpl();
			virtual std::shared_ptr<uml::StructuredActivityNode> getThisStructuredActivityNodePtr() const;
			virtual void setThisStructuredActivityNodePtr(std::weak_ptr<uml::StructuredActivityNode> thisStructuredActivityNodePtr);

			//Additional constructors for the containments back reference
			StructuredActivityNodeImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			StructuredActivityNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			StructuredActivityNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			StructuredActivityNodeImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			StructuredActivityNodeImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup);

		public:
			//destructor
			virtual ~StructuredActivityNodeImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Return those ActivityNodes contained immediately within the StructuredActivityNode that may act as sources of edges owned by the StructuredActivityNode.
			result = (node->union(input.oclAsType(ActivityNode)->asSet())->
			  union(node->select(oclIsKindOf(Action)).oclAsType(Action).output)->asSet())
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::ActivityNode>> sourceNodes() ;
			/*!
			Return those ActivityNodes contained immediately within the StructuredActivityNode that may act as targets of edges owned by the StructuredActivityNode.
			result = (node->union(output.oclAsType(ActivityNode)->asSet())->
			  union(node->select(oclIsKindOf(Action)).oclAsType(Action).input)->asSet())
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::ActivityNode>> targetNodes() ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			If true, then any object used by an Action within the StructuredActivityNode cannot be accessed by any Action outside the node until the StructuredActivityNode as a whole completes. Any concurrent Actions that would result in accessing such objects are required to have their execution deferred until the completion of the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual bool getMustIsolate() const ;
			/*!
			If true, then any object used by an Action within the StructuredActivityNode cannot be accessed by any Action outside the node until the StructuredActivityNode as a whole completes. Any concurrent Actions that would result in accessing such objects are required to have their execution deferred until the completion of the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual void setMustIsolate (bool _mustIsolate);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The ActivityEdges immediately contained in the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge, uml::Element>> getEdge() const ;
			/*!
			The ActivityNodes immediately contained in the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode, uml::Element>> getNode() const ;
			/*!
			The InputPins owned by the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> getStructuredNodeInput() const ;
			/*!
			The OutputPins owned by the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> getStructuredNodeOutput() const ;
			/*!
			The Variables defined in the scope of the StructuredActivityNode.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> getVariable() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			
			//*********************************
			// Container Getter
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

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual std::shared_ptr<Any> eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, std::shared_ptr<Any> newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual std::shared_ptr<Any> eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments) ;

		private:
			std::weak_ptr<uml::StructuredActivityNode> m_thisStructuredActivityNodePtr;
	};
}
#endif /* end of include guard: UML_STRUCTUREDACTIVITYNODESTRUCTUREDACTIVITYNODEIMPL_HPP */
