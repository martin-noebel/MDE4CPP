//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_WRITELINKACTIONWRITELINKACTIONIMPL_HPP
#define UML_WRITELINKACTIONWRITELINKACTIONIMPL_HPP

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
#include "../WriteLinkAction.hpp"

#include "impl/LinkActionImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class WriteLinkActionImpl :virtual public LinkActionImpl, virtual public WriteLinkAction 
	{
		public: 
			WriteLinkActionImpl(const WriteLinkActionImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			WriteLinkActionImpl& operator=(WriteLinkActionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			WriteLinkActionImpl();

		public:
			//destructor
			virtual ~WriteLinkActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The visibility of at least one end must allow access from the context Classifier of the WriteLinkAction.
			endData.end->exists(end |
			  end.type=_'context' or
			  end.visibility=VisibilityKind::public or 
			  end.visibility=VisibilityKind::protected and
			  endData.end->exists(other | 
			    other<>end and _'context'.conformsTo(other.type.oclAsType(Classifier)))) */ 
			virtual bool
			 allow_access(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
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
			 The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element > >
			 getInput() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
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
#endif /* end of include guard: UML_WRITELINKACTIONWRITELINKACTIONIMPL_HPP */

