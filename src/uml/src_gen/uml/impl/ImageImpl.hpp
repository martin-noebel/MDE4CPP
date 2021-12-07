//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_IMAGEIMAGEIMPL_HPP
#define UML_IMAGEIMAGEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Image.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ImageImpl : virtual public ElementImpl, virtual public Image 
	{
		public: 
			ImageImpl(const ImageImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ImageImpl& operator=(ImageImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ImageImpl();
			virtual std::shared_ptr<uml::Image> getThisImagePtr() const;
			virtual void setThisImagePtr(std::weak_ptr<uml::Image> thisImagePtr);

			//Additional constructors for the containments back reference
			ImageImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ImageImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			This contains the serialization of the image according to the format. The value could represent a bitmap, image such as a GIF file, or drawing 'instructions' using a standard such as Scalable Vector Graphic (SVG) (which is XML based).
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::string getContent() const ;
			/*!
			This contains the serialization of the image according to the format. The value could represent a bitmap, image such as a GIF file, or drawing 'instructions' using a standard such as Scalable Vector Graphic (SVG) (which is XML based).
			<p>From package UML::Packages.</p>
			*/
			 
			virtual void setContent (std::string _content);
			/*!
			This indicates the format of the content, which is how the string content should be interpreted. The following values are reserved: SVG, GIF, PNG, JPG, WMF, EMF, BMP. In addition the prefix 'MIME: ' is also reserved. This option can be used as an alternative to express the reserved values above, for example "SVG" could instead be expressed as "MIME: image/svg+xml".
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::string getFormat() const ;
			/*!
			This indicates the format of the content, which is how the string content should be interpreted. The following values are reserved: SVG, GIF, PNG, JPG, WMF, EMF, BMP. In addition the prefix 'MIME: ' is also reserved. This option can be used as an alternative to express the reserved values above, for example "SVG" could instead be expressed as "MIME: image/svg+xml".
			<p>From package UML::Packages.</p>
			*/
			 
			virtual void setFormat (std::string _format);
			/*!
			This contains a location that can be used by a tool to locate the image as an alternative to embedding it in the stereotype.
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::string getLocation() const ;
			/*!
			This contains a location that can be used by a tool to locate the image as an alternative to embedding it in the stereotype.
			<p>From package UML::Packages.</p>
			*/
			 
			virtual void setLocation (std::string _location);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			
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
			std::weak_ptr<uml::Image> m_thisImagePtr;
	};
}
#endif /* end of include guard: UML_IMAGEIMAGEIMPL_HPP */
