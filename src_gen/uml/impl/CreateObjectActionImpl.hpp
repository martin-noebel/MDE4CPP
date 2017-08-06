//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CREATEOBJECTACTIONCREATEOBJECTACTIONIMPL_HPP
#define UML_CREATEOBJECTACTIONCREATEOBJECTACTIONIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) /**/
#else
    #define ACT_DEBUG(a) a
#endif

//*********************************
// generated Includes

//Model includes
#include "../CreateObjectAction.hpp"

#include "impl/ActionImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class CreateObjectActionImpl :virtual public ActionImpl, virtual public CreateObjectAction 
	{
		public: 
			CreateObjectActionImpl(const CreateObjectActionImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			CreateObjectActionImpl& operator=(CreateObjectActionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			CreateObjectActionImpl();

		public:
			//destructor
			virtual ~CreateObjectActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The classifier cannot be abstract.
			not classifier.isAbstract */ 
			virtual bool
			 classifier_not_abstract(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The multiplicity of the result OutputPin is 1..1.
			result.is(1,1) */ 
			virtual bool
			 multiplicity(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The classifier cannot be an AssociationClass.
			not classifier.oclIsKindOf(AssociationClass) */ 
			virtual bool
			 classifier_not_association_class(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The type of the result OutputPin must be the same as the classifier of the CreateObjectAction.
			result.type = classifier */ 
			virtual bool
			 same_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The Classifier to be instantiated.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::Classifier > getClassifier() const ;
			
			/*!
			 The Classifier to be instantiated.
			<p>From package UML::Actions.</p> */
			virtual void setClassifier(std::shared_ptr<uml::Classifier> _classifier_classifier) ;
			/*!
			 The OutputPin on which the newly created object is placed.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::OutputPin > getResult() const ;
			
			/*!
			 The OutputPin on which the newly created object is placed.
			<p>From package UML::Actions.</p> */
			virtual void setResult(std::shared_ptr<uml::OutputPin> _result_result) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element > >
			 getOutput() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Union<uml::RedefinableElement> > getRedefinedElement() const ;/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual 		std::shared_ptr<Union<uml::ActivityGroup> > getInGroup() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Element > getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: UML_CREATEOBJECTACTIONCREATEOBJECTACTIONIMPL_HPP */

