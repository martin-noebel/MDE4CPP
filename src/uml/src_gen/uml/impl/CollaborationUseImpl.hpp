//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_COLLABORATIONUSECOLLABORATIONUSEIMPL_HPP
#define UML_COLLABORATIONUSECOLLABORATIONUSEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../CollaborationUse.hpp"

#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API CollaborationUseImpl : virtual public NamedElementImpl, virtual public CollaborationUse 
	{
		public: 
			CollaborationUseImpl(const CollaborationUseImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CollaborationUseImpl& operator=(CollaborationUseImpl const&); 

		protected:
			friend class umlFactoryImpl;
			CollaborationUseImpl();
			virtual std::shared_ptr<uml::CollaborationUse> getThisCollaborationUsePtr() const;
			virtual void setThisCollaborationUsePtr(std::weak_ptr<uml::CollaborationUse> thisCollaborationUsePtr);

			//Additional constructors for the containments back reference
			CollaborationUseImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			CollaborationUseImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~CollaborationUseImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			All the client elements of a roleBinding are in one Classifier and all supplier elements of a roleBinding are in one Collaboration.
			roleBinding->collect(client)->forAll(ne1, ne2 |
			  ne1.oclIsKindOf(ConnectableElement) and ne2.oclIsKindOf(ConnectableElement) and
			    let ce1 : ConnectableElement = ne1.oclAsType(ConnectableElement), ce2 : ConnectableElement = ne2.oclAsType(ConnectableElement) in
			      ce1.structuredClassifier = ce2.structuredClassifier)
			and
			  roleBinding->collect(supplier)->forAll(ne1, ne2 |
			  ne1.oclIsKindOf(ConnectableElement) and ne2.oclIsKindOf(ConnectableElement) and
			    let ce1 : ConnectableElement = ne1.oclAsType(ConnectableElement), ce2 : ConnectableElement = ne2.oclAsType(ConnectableElement) in
			      ce1.collaboration = ce2.collaboration)
			*/
			 
			virtual bool client_elements(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			Connectors in a Collaboration typing a CollaborationUse must have corresponding Connectors between elements bound in the context Classifier, and these corresponding Connectors must have the same or more general type than the Collaboration Connectors.
			type.ownedConnector->forAll(connector |
			  let rolesConnectedInCollab : Set(ConnectableElement) = connector.end.role->asSet(),
			        relevantBindings : Set(Dependency) = roleBinding->select(rb | rb.supplier->intersection(rolesConnectedInCollab)->notEmpty()),
			        boundRoles : Set(ConnectableElement) = relevantBindings->collect(client.oclAsType(ConnectableElement))->asSet(),
			        contextClassifier : StructuredClassifier = boundRoles->any(true).structuredClassifier->any(true) in
			          contextClassifier.ownedConnector->exists( correspondingConnector | 
			              correspondingConnector.end.role->forAll( role | boundRoles->includes(role) )
			              and (connector.type->notEmpty() and correspondingConnector.type->notEmpty()) implies connector.type->forAll(conformsTo(correspondingConnector.type)) )
			)
			*/
			 
			virtual bool connectors(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			Every collaborationRole in the Collaboration is bound within the CollaborationUse.
			type.collaborationRole->forAll(role | roleBinding->exists(rb | rb.supplier->includes(role)))
			*/
			 
			virtual bool every_role(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			A mapping between features of the Collaboration and features of the owning Classifier. This mapping indicates which ConnectableElement of the Classifier plays which role(s) in the Collaboration. A ConnectableElement may be bound to multiple roles in the same CollaborationUse (that is, it may play multiple roles).
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Dependency, uml::Element>> getRoleBinding() const ;
			/*!
			The Collaboration which is used in this CollaborationUse. The Collaboration defines the cooperation between its roles which are mapped to ConnectableElements relating to the Classifier owning the CollaborationUse.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<uml::Collaboration> getType() const ;
			/*!
			The Collaboration which is used in this CollaborationUse. The Collaboration defines the cooperation between its roles which are mapped to ConnectableElements relating to the Classifier owning the CollaborationUse.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual void setType(std::shared_ptr<uml::Collaboration>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<uml::CollaborationUse> m_thisCollaborationUsePtr;
	};
}
#endif /* end of include guard: UML_COLLABORATIONUSECOLLABORATIONUSEIMPL_HPP */
