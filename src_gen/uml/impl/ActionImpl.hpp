//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_ACTIONACTIONIMPL_HPP
#define UML_ACTIONACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Action.hpp"

#include "uml/impl/ExecutableNodeImpl.hpp"

//*********************************
namespace uml 
{
	class ActionImpl :virtual public ExecutableNodeImpl, virtual public Action 
	{
		public: 
			ActionImpl(const ActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ActionImpl& operator=(ActionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ActionImpl();
			virtual std::shared_ptr<Action> getThisActionPtr();
			virtual void setThisActionPtr(std::weak_ptr<Action> thisActionPtr);

			//Additional constructors for the containments back reference
			ActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			ActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			ActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			ActionImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~ActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 Return this Action and all Actions contained directly or indirectly in it. By default only the Action itself is returned, but the operation is overridden for StructuredActivityNodes.
			result = (self->asSet())
			<p>From package UML::Actions.</p> */ 
			virtual std::shared_ptr<Bag<uml::Action> > allActions()  ;
			
			/*!
			 Returns all the ActivityNodes directly or indirectly owned by this Action. This includes at least all the Pins of the Action.
			result = (input.oclAsType(Pin)->asSet()->union(output->asSet()))
			<p>From package UML::Actions.</p> */ 
			virtual std::shared_ptr<Bag<uml::ActivityNode> > allOwnedNodes()  ;
			
			/*!
			 result = (if inStructuredNode<>null then inStructuredNode.containingBehavior() 
			else if activity<>null then activity
			else interaction 
			endif
			endif
			)
			<p>From package UML::Actions.</p> */ 
			virtual std::shared_ptr<uml::Behavior> containingBehavior()  ;
			
			
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 If true, the Action can begin a new, concurrent execution, even if there is already another execution of the Action ongoing. If false, the Action cannot begin a new execution until any previous execution has completed.
			<p>From package UML::Actions.</p> */ 
			virtual bool getIsLocallyReentrant() const ;
			
			/*!
			 If true, the Action can begin a new, concurrent execution, even if there is already another execution of the Action ongoing. If false, the Action cannot begin a new execution until any previous execution has completed.
			<p>From package UML::Actions.</p> */ 
			virtual void setIsLocallyReentrant (bool _isLocallyReentrant); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The context Classifier of the Behavior that contains this Action, or the Behavior itself if it has no context.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::Classifier > getContext() const ;
			
			
			/*!
			 A Constraint that must be satisfied when execution of the Action is completed.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::Constraint, uml::Element>> getLocalPostcondition() const ;
			
			/*!
			 A Constraint that must be satisfied when execution of the Action is started.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<Subset<uml::Constraint, uml::Element>> getLocalPrecondition() const ;
			
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			 The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;/*!
			 The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;/*!
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
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<Action> m_thisActionPtr;
	};
}
#endif /* end of include guard: UML_ACTIONACTIONIMPL_HPP */
