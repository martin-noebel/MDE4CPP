//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXPANSIONKIND_HPP
#define UML_EXPANSIONKIND_HPP

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

namespace uml 
{
	enum ExpansionKind {
		ITERATIVE = 1
,
		PARALLEL = 0
,
		STREAM = 2
	};
}
#endif /* end of include guard: EXPANSIONKIND_HPP */
