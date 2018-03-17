//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_READLINKOBJECTENDACTIONREADLINKOBJECTENDACTIONIMPL_HPP
#define UML_READLINKOBJECTENDACTIONREADLINKOBJECTENDACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ReadLinkObjectEndAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class ReadLinkObjectEndActionImpl :virtual public ActionImpl, virtual public ReadLinkObjectEndAction 
	{
		public: 
			ReadLinkObjectEndActionImpl(const ReadLinkObjectEndActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ReadLinkObjectEndActionImpl& operator=(ReadLinkObjectEndActionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ReadLinkObjectEndActionImpl();
			virtual std::shared_ptr<ReadLinkObjectEndAction> getThisReadLinkObjectEndActionPtr();
			virtual void setThisReadLinkObjectEndActionPtr(std::weak_ptr<ReadLinkObjectEndAction> thisReadLinkObjectEndActionPtr);

			//Additional constructors for the containments back reference
			ReadLinkObjectEndActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			ReadLinkObjectEndActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			ReadLinkObjectEndActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			ReadLinkObjectEndActionImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~ReadLinkObjectEndActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The association of the end must be an AssociationClass.
			end.association.oclIsKindOf(AssociationClass) */ 
			virtual bool association_of_association(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The ends of the association must not be static.
			end.association.memberEnd->forAll(e | not e.isStatic) */ 
			virtual bool ends_of_association(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The multiplicity of the object InputPin is 1..1.
			object.is(1,1) */ 
			virtual bool multiplicity_of_object(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The multiplicity of the result OutputPin is 1..1.
			result.is(1,1) */ 
			virtual bool multiplicity_of_result(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The end Property must be an Association memberEnd.
			end.association <> null */ 
			virtual bool property(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The type of the object InputPin is the AssociationClass that owns the end Property.
			object.type = end.association */ 
			virtual bool type_of_object(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The type of the result OutputPin is the same as the type of the end Property.
			result.type = end.type */ 
			virtual bool type_of_result(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The Association end to be read.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::Property > getEnd() const ;
			
			/*!
			 The Association end to be read.
			<p>From package UML::Actions.</p> */
			virtual void setEnd(std::shared_ptr<uml::Property> _end_end) ;
			/*!
			 The input pin from which the link object is obtained.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::InputPin > getObject() const ;
			
			/*!
			 The input pin from which the link object is obtained.
			<p>From package UML::Actions.</p> */
			virtual void setObject(std::shared_ptr<uml::InputPin> _object_object) ;
			/*!
			 The OutputPin where the result value is placed.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::OutputPin > getResult() const ;
			
			/*!
			 The OutputPin where the result value is placed.
			<p>From package UML::Actions.</p> */
			virtual void setResult(std::shared_ptr<uml::OutputPin> _result_result) ;
							
			
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
			std::weak_ptr<ReadLinkObjectEndAction> m_thisReadLinkObjectEndActionPtr;
	};
}
#endif /* end of include guard: UML_READLINKOBJECTENDACTIONREADLINKOBJECTENDACTIONIMPL_HPP */
