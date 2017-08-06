//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OPERATIONOPERATIONIMPL_HPP
#define UML_OPERATIONOPERATIONIMPL_HPP

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
#include "../Operation.hpp"

#include "impl/BehavioralFeatureImpl.hpp"
#include "impl/ParameterableElementImpl.hpp"
#include "impl/TemplateableElementImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class OperationImpl :virtual public BehavioralFeatureImpl, virtual public ParameterableElementImpl, virtual public TemplateableElementImpl, virtual public Operation 
	{
		public: 
			OperationImpl(const OperationImpl & obj);
			virtual ecore::EObject *  copy() const;

		private:    
			OperationImpl& operator=(OperationImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			OperationImpl();

		public:
			//destructor
			virtual ~OperationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 An Operation can have at most one return parameter; i.e., an owned parameter with the direction set to 'return.'
			self.ownedParameter->select(direction = ParameterDirectionKind::return)->size() <= 1 */ 
			virtual bool
			 at_most_one_return(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 A bodyCondition can only be specified for a query Operation.
			bodyCondition <> null implies isQuery */ 
			virtual bool
			 only_body_for_query(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 Retrieves the (only) return result parameter for this operation. */ 
			virtual std::shared_ptr<uml::Parameter> 
			 getReturnResult()  ;
			
			/*!
			 */ 
			virtual void
			 setIsOrdered(bool newIsOrdered)  ;
			
			/*!
			 */ 
			virtual void
			 setIsUnique(bool newIsUnique)  ;
			
			/*!
			 */ 
			virtual void
			 setLower(int newLower)  ;
			
			/*!
			 */ 
			virtual void
			 setType(std::shared_ptr<uml::Type>  newType)  ;
			
			/*!
			 */ 
			virtual void
			 setUpper(int newUpper)  ;
			
			/*!
			 If this operation has a return parameter, isOrdered equals the value of isOrdered for that parameter. Otherwise isOrdered is false.
			result = (if returnResult()->notEmpty() then returnResult()-> exists(isOrdered) else false endif)
			<p>From package UML::Classification.</p> */ 
			virtual bool
			 isOrdered()  ;
			
			/*!
			 If this operation has a return parameter, isUnique equals the value of isUnique for that parameter. Otherwise isUnique is true.
			result = (if returnResult()->notEmpty() then returnResult()->exists(isUnique) else true endif)
			<p>From package UML::Classification.</p> */ 
			virtual bool
			 isUnique()  ;
			
			/*!
			 If this operation has a return parameter, lower equals the value of lower for that parameter. Otherwise lower has no value.
			result = (if returnResult()->notEmpty() then returnResult()->any(true).lower else null endif)
			<p>From package UML::Classification.</p> */ 
			virtual int
			 getLower()  ;
			
			/*!
			 The query returnResult() returns the set containing the return parameter of the Operation if one exists, otherwise, it returns an empty set
			result = (ownedParameter->select (direction = ParameterDirectionKind::return)->asSet())
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Parameter> >
			 returnResult()  ;
			
			
			
			/*!
			 If this operation has a return parameter, upper equals the value of upper for that parameter. Otherwise upper has no value.
			result = (if returnResult()->notEmpty() then returnResult()->any(true).upper else null endif)
			<p>From package UML::Classification.</p> */ 
			virtual int
			 getUpper()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Specifies whether the return parameter is ordered or not, if present.  This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p> */ 
			virtual bool getIsOrdered() const ;
			
			/*!
			 Specifies whether an execution of the BehavioralFeature leaves the state of the system unchanged (isQuery=true) or whether side effects may occur (isQuery=false).
			<p>From package UML::Classification.</p> */ 
			virtual bool getIsQuery() const ;
			
			/*!
			 Specifies whether an execution of the BehavioralFeature leaves the state of the system unchanged (isQuery=true) or whether side effects may occur (isQuery=false).
			<p>From package UML::Classification.</p> */ 
			virtual void setIsQuery (bool _isQuery); 
			
			/*!
			 Specifies whether the return parameter is unique or not, if present. This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p> */ 
			virtual bool getIsUnique() const ;
			
			/*!
			 Specifies the lower multiplicity of the return parameter, if present. This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p> */ 
			virtual int getLower() const ;
			
			/*!
			 The upper multiplicity of the return parameter, if present. This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p> */ 
			virtual int getUpper() const ;
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 An optional Constraint on the result values of an invocation of this Operation.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<uml::Constraint > getBodyCondition() const ;
			
			/*!
			 An optional Constraint on the result values of an invocation of this Operation.
			<p>From package UML::Classification.</p> */
			virtual void setBodyCondition(std::shared_ptr<uml::Constraint> _bodyCondition_bodyCondition) ;
			/*!
			 The Class that owns this operation, if any.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<uml::Class > getClass() const ;
			
			/*!
			 The Class that owns this operation, if any.
			<p>From package UML::Classification.</p> */
			virtual void setClass(std::shared_ptr<uml::Class> _class_class) ;
			/*!
			 The DataType that owns this Operation, if any.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<uml::DataType > getDatatype() const ;
			
			/*!
			 The DataType that owns this Operation, if any.
			<p>From package UML::Classification.</p> */
			virtual void setDatatype(std::shared_ptr<uml::DataType> _datatype_datatype) ;
			/*!
			 The Interface that owns this Operation, if any.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<uml::Interface > getInterface() const ;
			
			/*!
			 The Interface that owns this Operation, if any.
			<p>From package UML::Classification.</p> */
			virtual void setInterface(std::shared_ptr<uml::Interface> _interface_interface) ;
			/*!
			 An optional set of Constraints specifying the state of the system when the Operation is completed.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ > >
			 getPostcondition() const ;
			
			/*!
			 An optional set of Constraints on the state of the system when the Operation is invoked.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ > >
			 getPrecondition() const ;
			
			/*!
			 The Operations that are redefined by this Operation.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Subset<uml::Operation, uml::RedefinableElement > >
			 getRedefinedOperation() const ;
			
			/*!
			 The return type of the operation, if present. This information is derived from the return result for this Operation.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<uml::Type > getType() const ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::NamedElement> > getMember() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual 		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > >
			 getOwnedMember() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Union<uml::RedefinableElement> > getRedefinedElement() const ;/*!
			 The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Union<uml::Classifier> > getRedefinitionContext() const ;/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<uml::Namespace > getNamespace() const ;/*!
			 The Classifiers that have this Feature as a feature.
			<p>From package UML::Classification.</p> */
			virtual 		std::shared_ptr<Union<uml::Classifier> > getFeaturingClassifier() const ;/*!
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
#endif /* end of include guard: UML_OPERATIONOPERATIONIMPL_HPP */

