//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_AUXILIARY__HPP
#define STANDARDPROFILE_AUXILIARY__HPP




//Forward Declaration for used types
namespace uml 
{
	class Class;
}

// base class includes
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class Auxiliary : virtual public uml::Stereotype 
	{
		private:    
			Auxiliary(const Auxiliary& that) = delete;

		protected:
			Auxiliary(){}

		public:
			//destructor
			virtual ~Auxiliary() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Class> getBase_Class() const  = 0;
			virtual void setBase_Class (std::weak_ptr<uml::Class> _base_Class) = 0;
			
			
			//*********************************
			// Operations
			//*********************************
			
			
		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::Class> m_base_Class;
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_AUXILIARY__HPP */
