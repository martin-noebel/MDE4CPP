//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONTROLFLOWCONTROLFLOWIMPL_HPP
#define UML_CONTROLFLOWCONTROLFLOWIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ControlFlow.hpp"

#include "uml/impl/ActivityEdgeImpl.hpp"

//*********************************
namespace uml 
{
	class ControlFlowImpl :virtual public ActivityEdgeImpl, virtual public ControlFlow 
	{
		public: 
			ControlFlowImpl(const ControlFlowImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ControlFlowImpl& operator=(ControlFlowImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ControlFlowImpl();
			virtual std::shared_ptr<ControlFlow> getThisControlFlowPtr() const;
			virtual void setThisControlFlowPtr(std::weak_ptr<ControlFlow> thisControlFlowPtr);

			//Additional constructors for the containments back reference
			ControlFlowImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			ControlFlowImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			ControlFlowImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			ControlFlowImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~ControlFlowImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 ControlFlows may not have ObjectNodes at either end, except for ObjectNodes with control type.
			(source.oclIsKindOf(ObjectNode) implies source.oclAsType(ObjectNode).isControlType) and 
			(target.oclIsKindOf(ObjectNode) implies target.oclAsType(ObjectNode).isControlType) */ 
			virtual bool object_nodes(Any diagnostics,std::map <   Any, Any >  context) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityGroups containing the ActivityEdge.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ControlFlow> m_thisControlFlowPtr;
	};
}
#endif /* end of include guard: UML_CONTROLFLOWCONTROLFLOWIMPL_HPP */