//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_ACTIVITYNODEACTIVATIONACTIVITYNODEACTIVATIONIMPL_HPP
#define FUML_ACTIVITYNODEACTIVATIONACTIVITYNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ActivityNodeActivation.hpp"

#include "fUML/impl/SemanticVisitorImpl.hpp"

//*********************************
namespace fUML 
{
	class ActivityNodeActivationImpl :virtual public SemanticVisitorImpl, virtual public ActivityNodeActivation 
	{
		public: 
			ActivityNodeActivationImpl(const ActivityNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ActivityNodeActivationImpl& operator=(ActivityNodeActivationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ActivityNodeActivationImpl();
			virtual std::shared_ptr<ActivityNodeActivation> getThisActivityNodeActivationPtr();
			virtual void setThisActivityNodeActivationPtr(std::weak_ptr<ActivityNodeActivation> thisActivityNodeActivationPtr);

			//Additional constructors for the containments back reference
			ActivityNodeActivationImpl(std::weak_ptr<fUML::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~ActivityNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void addIncomingEdge(std::shared_ptr<fUML::ActivityEdgeInstance>  edge)  ;
			
			/*!
			 */ 
			virtual void addOutgoingEdge(std::shared_ptr<fUML::ActivityEdgeInstance>  edge)  ;
			
			/*!
			 */ 
			virtual void addToken(std::shared_ptr<fUML::Token>  token)  ;
			
			/*!
			 */ 
			virtual void addTokens(std::shared_ptr<Bag<fUML::Token> >  tokens)  ;
			
			/*!
			 */ 
			virtual void clearTokens()  ;
			
			/*!
			 */ 
			virtual void createEdgeInstances()  ;
			
			/*!
			 */ 
			virtual void createNodeActivations()  ;
			
			/*!
			 */ 
			virtual void fire(std::shared_ptr<Bag<fUML::Token> >  incomingTokens)  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::ActivityExecution> getActivityExecution()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Object> getExecutionContext()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Locus> getExecutionLocus()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::ActivityNodeActivation> getNodeActivation(std::shared_ptr<uml::ActivityNode>  node)  ;
			
			/*!
			 */ 
			virtual bool getRunning()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > getTokens()  ;
			
			/*!
			 */ 
			virtual bool isReady()  ;
			
			/*!
			 */ 
			virtual bool isSourceFor(std::shared_ptr<fUML::ActivityEdgeInstance>  edgeInstances)  ;
			
			/*!
			 */ 
			virtual void recieveOffer()  ;
			
			/*!
			 */ 
			virtual int removeToken(std::shared_ptr<fUML::Token>  token)  ;
			
			/*!
			 */ 
			virtual void resume()  ;
			
			/*!
			 */ 
			virtual void run()  ;
			
			/*!
			 */ 
			virtual void sendOffers(std::shared_ptr<Bag<fUML::Token> >  tokens)  ;
			
			/*!
			 */ 
			virtual void suspend()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > takeOfferedTokens()  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > takeTokens()  ;
			
			/*!
			 */ 
			virtual void terminate()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual bool isRunning() const ;
			
			/*!
			 */ 
			virtual void setRunning (bool _running); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::weak_ptr<fUML::ActivityNodeActivationGroup > getGroup() const ;
			
			/*!
			 */
			virtual void setGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup> _group_group) ;
			/*!
			 */
			virtual std::shared_ptr<Bag<fUML::Token>> getHeldTokens() const ;
			
			/*!
			 */
			virtual std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> getIncomingEdges() const ;
			
			/*!
			 */
			virtual std::shared_ptr<uml::ActivityNode > getNode() const ;
			
			/*!
			 */
			virtual void setNode(std::shared_ptr<uml::ActivityNode> _node_node) ;
			/*!
			 */
			virtual std::shared_ptr<Bag<fUML::ActivityEdgeInstance>> getOutgoingEdges() const ;
			
							
			
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
			virtual void load(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interface::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interface::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, boost::any newValue) ;

		private:
			std::weak_ptr<ActivityNodeActivation> m_thisActivityNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_ACTIVITYNODEACTIVATIONACTIVITYNODEACTIVATIONIMPL_HPP */
