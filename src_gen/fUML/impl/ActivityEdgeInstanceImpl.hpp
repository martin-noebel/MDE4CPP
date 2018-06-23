//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_ACTIVITYEDGEINSTANCEACTIVITYEDGEINSTANCEIMPL_HPP
#define FUML_ACTIVITYEDGEINSTANCEACTIVITYEDGEINSTANCEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ActivityEdgeInstance.hpp"


#include "ecore/impl/EObjectImpl.hpp"

//*********************************
namespace fUML 
{
	class ActivityEdgeInstanceImpl :virtual public ecore::EObjectImpl,
virtual public ActivityEdgeInstance 
	{
		public: 
			ActivityEdgeInstanceImpl(const ActivityEdgeInstanceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ActivityEdgeInstanceImpl& operator=(ActivityEdgeInstanceImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ActivityEdgeInstanceImpl();
			virtual std::shared_ptr<ActivityEdgeInstance> getThisActivityEdgeInstancePtr();
			virtual void setThisActivityEdgeInstancePtr(std::weak_ptr<ActivityEdgeInstance> thisActivityEdgeInstancePtr);

			//Additional constructors for the containments back reference
			ActivityEdgeInstanceImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~ActivityEdgeInstanceImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual int countOfferedValue()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > getOfferedTokens()  ;
			
			/*!
			 */ 
			virtual bool hasOffer()  ;
			
			/*!
			 */ 
			virtual void sendOffer(std::shared_ptr<Bag<fUML::Token> >  tokens)  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > takeOfferedTokens()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > takeOfferedTokens(int maxCount)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<uml::ActivityEdge > getEdge() const ;
			
			/*!
			 */
			virtual void setEdge(std::shared_ptr<uml::ActivityEdge> _edge_edge) ;
			/*!
			 */
			virtual std::weak_ptr<fUML::ActivityNodeActivationGroup > getGroup() const ;
			
			/*!
			 */
			virtual void setGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup> _group_group) ;
			/*!
			 */
			virtual std::shared_ptr<Bag<fUML::Offer>> getOffers() const ;
			
			/*!
			 */
			virtual std::weak_ptr<fUML::ActivityNodeActivation > getSource() const ;
			
			/*!
			 */
			virtual void setSource(std::shared_ptr<fUML::ActivityNodeActivation> _source_source) ;
			/*!
			 */
			virtual std::weak_ptr<fUML::ActivityNodeActivation > getTarget() const ;
			
			/*!
			 */
			virtual void setTarget(std::shared_ptr<fUML::ActivityNodeActivation> _target_target) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ActivityEdgeInstance> m_thisActivityEdgeInstancePtr;
	};
}
#endif /* end of include guard: FUML_ACTIVITYEDGEINSTANCEACTIVITYEDGEINSTANCEIMPL_HPP */
