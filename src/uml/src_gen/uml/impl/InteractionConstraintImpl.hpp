//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONCONSTRAINTINTERACTIONCONSTRAINTIMPL_HPP
#define UML_INTERACTIONCONSTRAINTINTERACTIONCONSTRAINTIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../InteractionConstraint.hpp"

#include "uml/impl/ConstraintImpl.hpp"

//*********************************
namespace uml 
{
	class InteractionConstraintImpl : virtual public ConstraintImpl, virtual public InteractionConstraint 
	{
		public: 
			InteractionConstraintImpl(const InteractionConstraintImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			InteractionConstraintImpl& operator=(InteractionConstraintImpl const&) = delete;

		protected:
			friend class umlFactoryImpl;
			InteractionConstraintImpl();
			virtual std::shared_ptr<InteractionConstraint> getThisInteractionConstraintPtr() const;
			virtual void setThisInteractionConstraintPtr(std::weak_ptr<InteractionConstraint> thisInteractionConstraintPtr);

			//Additional constructors for the containments back reference
			InteractionConstraintImpl(std::weak_ptr<uml::Namespace > par_Namespace, const int reference_id);


			//Additional constructors for the containments back reference


			//Additional constructors for the containments back reference
			InteractionConstraintImpl(std::weak_ptr<uml::Element > par_owner);


			//Additional constructors for the containments back reference
			InteractionConstraintImpl(std::weak_ptr<uml::Package > par_owningPackage);


			//Additional constructors for the containments back reference
			InteractionConstraintImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);




		public:
			//destructor
			virtual ~InteractionConstraintImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The dynamic variables that take part in the constraint must be owned by the ConnectableElement corresponding to the covered Lifeline.
			*/
			 
			virtual bool dynamic_variables(Any diagnostics,std::map <  Any ,  Any > context) ;
			
			/*!
			The constraint may contain references to global data or write-once data.
			*/
			 
			virtual bool global_data(Any diagnostics,std::map <  Any ,  Any > context) ;
			
			/*!
			If maxint is specified, then minint must be specified and the evaluation of maxint must be >= the evaluation of minint.
			maxint->notEmpty() implies (minint->notEmpty() and 
			maxint->asSequence()->first().integerValue() >=
			minint->asSequence()->first().integerValue() )
			*/
			 
			virtual bool maxint_greater_equal_minint(Any diagnostics,std::map <  Any ,  Any > context) ;
			
			/*!
			If maxint is specified, then the expression must evaluate to a positive integer.
			maxint->notEmpty() implies 
			maxint->asSequence()->first().integerValue() > 0
			*/
			 
			virtual bool maxint_positive(Any diagnostics,std::map <  Any ,  Any > context) ;
			
			/*!
			Minint/maxint can only be present if the InteractionConstraint is associated with the operand of a loop CombinedFragment.
			maxint->notEmpty() or minint->notEmpty() implies
			interactionOperand.combinedFragment.interactionOperator =
			InteractionOperatorKind::loop
			*/
			 
			virtual bool minint_maxint(Any diagnostics,std::map <  Any ,  Any > context) ;
			
			/*!
			If minint is specified, then the expression must evaluate to a non-negative integer.
			minint->notEmpty() implies 
			minint->asSequence()->first().integerValue() >= 0
			*/
			 
			virtual bool minint_non_negative(Any diagnostics,std::map <  Any ,  Any > context) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The maximum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification > getMaxint() const ;
			
			/*!
			The maximum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setMaxint(std::shared_ptr<uml::ValueSpecification> _maxint) ;
			
			/*!
			The minimum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::ValueSpecification > getMinint() const ;
			
			/*!
			The minimum number of iterations of a loop
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setMinint(std::shared_ptr<uml::ValueSpecification> _minint) ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const ; 
			 
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
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<InteractionConstraint> m_thisInteractionConstraintPtr;
	};
}
#endif /* end of include guard: UML_INTERACTIONCONSTRAINTINTERACTIONCONSTRAINTIMPL_HPP */
