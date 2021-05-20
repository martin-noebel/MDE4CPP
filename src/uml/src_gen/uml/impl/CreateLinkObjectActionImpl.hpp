//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CREATELINKOBJECTACTIONCREATELINKOBJECTACTIONIMPL_HPP
#define UML_CREATELINKOBJECTACTIONCREATELINKOBJECTACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../CreateLinkObjectAction.hpp"

#include "uml/impl/CreateLinkActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API CreateLinkObjectActionImpl : virtual public CreateLinkActionImpl, virtual public CreateLinkObjectAction 
	{
		public: 
			CreateLinkObjectActionImpl(const CreateLinkObjectActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CreateLinkObjectActionImpl& operator=(CreateLinkObjectActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			CreateLinkObjectActionImpl();
			virtual std::shared_ptr<CreateLinkObjectAction> getThisCreateLinkObjectActionPtr() const;
			virtual void setThisCreateLinkObjectActionPtr(std::weak_ptr<CreateLinkObjectAction> thisCreateLinkObjectActionPtr);

			//Additional constructors for the containments back reference
			CreateLinkObjectActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			CreateLinkObjectActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			CreateLinkObjectActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			CreateLinkObjectActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~CreateLinkObjectActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The Association must be an AssociationClass.
			self.association().oclIsKindOf(AssociationClass)
			*/
			 
			virtual bool association_class(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			The multiplicity of the OutputPin is 1..1.
			result.is(1,1)
			*/
			 
			virtual bool multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			The type of the result OutputPin must be the same as the Association of the CreateLinkObjectAction.
			result.type = association()
			*/
			 
			virtual bool type_of_result(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The output pin on which the newly created link object is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getResult() const ;
			/*!
			The output pin on which the newly created link object is placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(std::shared_ptr<uml::OutputPin>) ;
			
			
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
			std::weak_ptr<CreateLinkObjectAction> m_thisCreateLinkObjectActionPtr;
	};
}
#endif /* end of include guard: UML_CREATELINKOBJECTACTIONCREATELINKOBJECTACTIONIMPL_HPP */
