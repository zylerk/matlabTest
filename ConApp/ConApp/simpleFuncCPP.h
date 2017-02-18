//
// MATLAB Compiler: 6.2 (R2016a)
// Date: Sat Feb 18 03:04:47 2017
// Arguments: "-B" "macro_default" "-W" "cpplib:simpleFuncCPP" "-T" "link:lib"
// "-d" "C:\Users\apex\Documents\MATLAB\simpleFuncCPP\for_testing" "-v"
// "C:\Users\apex\Documents\MATLAB\dll\simpleFunction.m" 
//

#ifndef __simpleFuncCPP_h
#define __simpleFuncCPP_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_simpleFuncCPP
#define PUBLIC_simpleFuncCPP_C_API __global
#else
#define PUBLIC_simpleFuncCPP_C_API /* No import statement needed. */
#endif

#define LIB_simpleFuncCPP_C_API PUBLIC_simpleFuncCPP_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_simpleFuncCPP
#define PUBLIC_simpleFuncCPP_C_API __declspec(dllexport)
#else
#define PUBLIC_simpleFuncCPP_C_API __declspec(dllimport)
#endif

#define LIB_simpleFuncCPP_C_API PUBLIC_simpleFuncCPP_C_API


#else

#define LIB_simpleFuncCPP_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_simpleFuncCPP_C_API 
#define LIB_simpleFuncCPP_C_API /* No special import/export declaration */
#endif

extern LIB_simpleFuncCPP_C_API 
bool MW_CALL_CONV simpleFuncCPPInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_simpleFuncCPP_C_API 
bool MW_CALL_CONV simpleFuncCPPInitialize(void);

extern LIB_simpleFuncCPP_C_API 
void MW_CALL_CONV simpleFuncCPPTerminate(void);



extern LIB_simpleFuncCPP_C_API 
void MW_CALL_CONV simpleFuncCPPPrintStackTrace(void);

extern LIB_simpleFuncCPP_C_API 
bool MW_CALL_CONV mlxSimpleFunction(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_simpleFuncCPP
#define PUBLIC_simpleFuncCPP_CPP_API __declspec(dllexport)
#else
#define PUBLIC_simpleFuncCPP_CPP_API __declspec(dllimport)
#endif

#define LIB_simpleFuncCPP_CPP_API PUBLIC_simpleFuncCPP_CPP_API

#else

#if !defined(LIB_simpleFuncCPP_CPP_API)
#if defined(LIB_simpleFuncCPP_C_API)
#define LIB_simpleFuncCPP_CPP_API LIB_simpleFuncCPP_C_API
#else
#define LIB_simpleFuncCPP_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_simpleFuncCPP_CPP_API void MW_CALL_CONV simpleFunction(int nargout, mwArray& y, const mwArray& x1, const mwArray& x2);

#endif
#endif
