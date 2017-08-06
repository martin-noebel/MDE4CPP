//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LINKENDCREATIONDATALINKENDCREATIONDATAIMPL_HPP
#define UML_LINKENDCREATIONDATALINKENDCREATIONDATAIMPL_HPP

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
#include "../LinkEndCreationData.hpp"

#include "impl/LinkEndDataImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class LinkEndCreationDataImpl :virtual public LinkEndDataImpl, virtual public LinkEndCreationData 
	{
		public: 
			LinkEndCreationDataImpl(const LinkEndCreationDataImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			LinkEndCreationDataImpl& operator=(LinkEndCreationDataImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			LinkEndCreationDataImpl();

		public:
			//destructor
			virtual ~LinkEndCreationDataImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 LinkEndCreationData for ordered Association ends must have a single insertAt InputPin for the insertion point with type UnlimitedNatural and multiplicity of 1..1, if isReplaceAll=false, and must have no InputPin for the insertion point when the association ends are unordered.
			if  not end.isOrdered
			then insertAt = null
			else
				not isReplaceAll=false implies
				insertAt <> null and insertAt->forAll(type=UnlimitedNatural and is(1,1))
			endif */ 
			virtual bool
			 insertAt_pin(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Specifies whether the existing links emanating from the object on this end should be destroyed before creating a new link.
			<p>From package UML::Actions.</p> */ 
			virtual bool getIsReplaceAll() const ;
			
			/*!
			 Specifies whether the existing links emanating from the object on this end should be destroyed before creating a new link.
			<p>From package UML::Actions.</p> */ 
			virtual void setIsReplaceAll (bool _isReplaceAll); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 For ordered Association ends, the InputPin that provides the position where the new link should be inserted or where an existing link should be moved to. The type of the insertAt InputPin is UnlimitedNatural, but the input cannot be zero. It is omitted for Association ends that are not ordered.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::InputPin > getInsertAt() const ;
			
			/*!
			 For ordered Association ends, the InputPin that provides the position where the new link should be inserted or where an existing link should be moved to. The type of the insertAt InputPin is UnlimitedNatural, but the input cannot be zero. It is omitted for Association ends that are not ordered.
			<p>From package UML::Actions.</p> */
			virtual void setInsertAt(std::shared_ptr<uml::InputPin> _insertAt_insertAt) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: UML_LINKENDCREATIONDATALINKENDCREATIONDATAIMPL_HPP */

