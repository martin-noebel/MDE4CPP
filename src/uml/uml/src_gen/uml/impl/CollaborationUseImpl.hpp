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
			std::weak_ptr<uml::CollaborationUse> m_thisCollaborationUsePtr;
	};
}
#endif /* end of include guard: UML_COLLABORATIONUSECOLLABORATIONUSEIMPL_HPP */
