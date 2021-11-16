//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_READEXTENTACTIONREADEXTENTACTIONIMPL_HPP
#define UML_READEXTENTACTIONREADEXTENTACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ReadExtentAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ReadExtentActionImpl : virtual public ActionImpl, virtual public ReadExtentAction 
	{
		public: 
			ReadExtentActionImpl(const ReadExtentActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ReadExtentActionImpl& operator=(ReadExtentActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ReadExtentActionImpl();
			virtual std::shared_ptr<uml::ReadExtentAction> getThisReadExtentActionPtr() const;
			virtual void setThisReadExtentActionPtr(std::weak_ptr<uml::ReadExtentAction> thisReadExtentActionPtr);

			//Additional constructors for the containments back reference
			ReadExtentActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ReadExtentActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ReadExtentActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ReadExtentActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ReadExtentActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The multiplicity of the result OutputPin is 0..*.
			result.is(0,*)
			*/
			 
			virtual bool multiplicity_of_result(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The type of the result OutputPin is the classifier.
			result.type = classifier
			*/
			 
			virtual bool type_is_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The Classifier whose instances are to be retrieved.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Classifier> getClassifier() const ;
			/*!
			The Classifier whose instances are to be retrieved.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setClassifier(std::shared_ptr<uml::Classifier>) ;
			/*!
			The OutputPin on which the Classifier instances are placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::OutputPin> getResult() const ;
			/*!
			The OutputPin on which the Classifier instances are placed.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setResult(std::shared_ptr<uml::OutputPin>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;
			/*!
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;
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
			/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ;
			
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
			std::weak_ptr<uml::ReadExtentAction> m_thisReadExtentActionPtr;
	};
}
#endif /* end of include guard: UML_READEXTENTACTIONREADEXTENTACTIONIMPL_HPP */
