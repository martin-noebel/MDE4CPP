//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_COMMENTCOMMENTIMPL_HPP
#define UML_COMMENTCOMMENTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Comment.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API CommentImpl : virtual public ElementImpl, virtual public Comment 
	{
		public: 
			CommentImpl(const CommentImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CommentImpl& operator=(CommentImpl const&); 

		protected:
			friend class umlFactoryImpl;
			CommentImpl();
			virtual std::shared_ptr<uml::Comment> getThisCommentPtr() const;
			virtual void setThisCommentPtr(std::weak_ptr<uml::Comment> thisCommentPtr);

			//Additional constructors for the containments back reference
			CommentImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~CommentImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Specifies a string that is the comment.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual std::string getBody() const ;
			/*!
			Specifies a string that is the comment.
			<p>From package UML::CommonStructure.</p>
			*/
			 
			virtual void setBody (std::string _body);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			References the Element(s) being commented.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Element>> getAnnotatedElement() const ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::Comment> m_thisCommentPtr;
	};
}
#endif /* end of include guard: UML_COMMENTCOMMENTIMPL_HPP */