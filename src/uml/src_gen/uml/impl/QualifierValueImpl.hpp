//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_QUALIFIERVALUEQUALIFIERVALUEIMPL_HPP
#define UML_QUALIFIERVALUEQUALIFIERVALUEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../QualifierValue.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class QualifierValueImpl : virtual public ElementImpl, virtual public QualifierValue 
	{
		public: 
			QualifierValueImpl(const QualifierValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			QualifierValueImpl& operator=(QualifierValueImpl const&) = delete;

		protected:
			friend class umlFactoryImpl;
			QualifierValueImpl();
			virtual std::shared_ptr<QualifierValue> getThisQualifierValuePtr() const;
			virtual void setThisQualifierValuePtr(std::weak_ptr<QualifierValue> thisQualifierValuePtr);

			//Additional constructors for the containments back reference
			QualifierValueImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~QualifierValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The multiplicity of the value InputPin is 1..1.
			value.is(1,1)
			*/
			 
			virtual bool multiplicity_of_qualifier(Any diagnostics,std::map <  Any ,  Any > context) ;
			
			/*!
			The qualifier must be a qualifier of the Association end of the linkEndData that owns this QualifierValue.
			linkEndData.end.qualifier->includes(qualifier)
			*/
			 
			virtual bool qualifier_attribute(Any diagnostics,std::map <  Any ,  Any > context) ;
			
			/*!
			The type of the value InputPin conforms to the type of the qualifier Property.
			value.type.conformsTo(qualifier.type)
			*/
			 
			virtual bool type_of_qualifier(Any diagnostics,std::map <  Any ,  Any > context) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The qualifier Property for which the value is to be specified.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Property > getQualifier() const ;
			
			/*!
			The qualifier Property for which the value is to be specified.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setQualifier(std::shared_ptr<uml::Property> _qualifier) ;
			
			/*!
			The InputPin from which the specified value for the qualifier is taken.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin > getValue() const ;
			
			/*!
			The InputPin from which the specified value for the qualifier is taken.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setValue(std::shared_ptr<uml::InputPin> _value) ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ; 
			 
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
			std::weak_ptr<QualifierValue> m_thisQualifierValuePtr;
	};
}
#endif /* end of include guard: UML_QUALIFIERVALUEQUALIFIERVALUEIMPL_HPP */
