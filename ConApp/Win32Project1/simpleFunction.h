/*
 * MATLAB Compiler: 6.2 (R2016a)
 * Date: Sat Feb 18 22:12:08 2017
 * Arguments: "-B" "macro_default" "-W" "lib:simpleFunction" "-T" "link:lib"
 * "-d" "C:\Users\apex\Documents\MATLAB\simpleFunction\for_testing" "-v"
 * "C:\Users\apex\Documents\MATLAB\dll\simpleFunction.m" 
 */

#ifndef __simpleFunction_h
#define __simpleFunction_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
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

#ifdef EXPORTING_simpleFunction
#define PUBLIC_simpleFunction_C_API __global
#else
#define PUBLIC_simpleFunction_C_API /* No import statement needed. */
#endif

#define LIB_simpleFunction_C_API PUBLIC_simpleFunction_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_simpleFunction
#define PUBLIC_simpleFunction_C_API __declspec(dllexport)
#else
#define PUBLIC_simpleFunction_C_API __declspec(dllimport)
#endif

#define LIB_simpleFunction_C_API PUBLIC_simpleFunction_C_API


#else

#define LIB_simpleFunction_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_simpleFunction_C_API 
#define LIB_simpleFunction_C_API /* No special import/export declaration */
#endif

extern LIB_simpleFunction_C_API 
bool MW_CALL_CONV simpleFunctionInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_simpleFunction_C_API 
bool MW_CALL_CONV simpleFunctionInitialize(void);

extern LIB_simpleFunction_C_API 
void MW_CALL_CONV simpleFunctionTerminate(void);



extern LIB_simpleFunction_C_API 
void MW_CALL_CONV simpleFunctionPrintStackTrace(void);

extern LIB_simpleFunction_C_API 
bool MW_CALL_CONV mlxSimpleFunction(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);



extern LIB_simpleFunction_C_API bool MW_CALL_CONV mlfSimpleFunction(int nargout, mxArray** y, mxArray* x1, mxArray* x2);

#ifdef __cplusplus
}
#endif
#endif
