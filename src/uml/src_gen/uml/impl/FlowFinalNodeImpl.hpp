//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_FLOWFINALNODEFLOWFINALNODEIMPL_HPP
#define UML_FLOWFINALNODEFLOWFINALNODEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../FlowFinalNode.hpp"

#include "uml/impl/FinalNodeImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API FlowFinalNodeImpl : virtual public FinalNodeImpl, virtual public FlowFinalNode 
	{
		public: 
			FlowFinalNodeImpl(const FlowFinalNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			FlowFinalNodeImpl& operator=(FlowFinalNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			FlowFinalNodeImpl();
			virtual std::shared_ptr<FlowFinalNode> getThisFlowFinalNodePtr() const;
			virtual void setThisFlowFinalNodePtr(std::weak_ptr<FlowFinalNode> thisFlowFinalNodePtr);

			//Additional constructors for the containments back reference
			FlowFinalNodeImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			FlowFinalNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			FlowFinalNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			FlowFinalNodeImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~FlowFinalNodeImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
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
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
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
			std::weak_ptr<FlowFinalNode> m_thisFlowFinalNodePtr;
	};
}
#endif /* end of include guard: UML_FLOWFINALNODEFLOWFINALNODEIMPL_HPP */
