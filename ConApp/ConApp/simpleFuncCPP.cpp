//
// MATLAB Compiler: 5.1 (R2014a)
// Date: Sat Feb 18 00:38:12 2017
// Arguments: "-B" "macro_default" "-W" "cpplib:simpleFuncCPP" "-T" "link:lib"
// "-d" "C:\Users\apex\Documents\MATLAB\simpleFuncCPP\for_testing" "-v"
// "C:\Users\apex\Documents\MATLAB\dll\simpleFunction.m"
// "class{Class1:C:\Users\apex\Documents\MATLAB\dll\simpleFunction.m}" 
//

#include "stdafx.h"

#include <stdio.h>
#define EXPORTING_simpleFuncCPP 1
#include "simpleFuncCPP.h"

static HMCRINSTANCE _mcr_inst = NULL;


#if defined( _MSC_VER) || defined(__BORLANDC__) || defined(__WATCOMC__) || defined(__LCC__)
#ifdef __LCC__
#undef EXTERN_C
#endif
#include <windows.h>

static char path_to_dll[_MAX_PATH];

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, void *pv)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        if (GetModuleFileName(hInstance, (LPWSTR)path_to_dll, _MAX_PATH) == 0)
            return FALSE;
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
    }
    return TRUE;
}
#endif
#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
  return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
  int written = 0;
  size_t len = 0;
  len = strlen(s);
  written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
  if (len > 0 && s[ len-1 ] != '\n')
    written += mclWrite(2 /* stderr */, "\n", sizeof(char));
  return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_simpleFuncCPP_C_API
#define LIB_simpleFuncCPP_C_API /* No special import/export declaration */
#endif

LIB_simpleFuncCPP_C_API 
bool MW_CALL_CONV simpleFuncCPPInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
  if (_mcr_inst != NULL)
    return true;
  if (!mclmcrInitialize())
    return false;
  if (!GetModuleFileName(GetModuleHandle((LPCWSTR)("simpleFuncCPP")), (LPWSTR)path_to_dll, _MAX_PATH))
    return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream(path_to_dll);
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(   &_mcr_inst,
                                                                error_handler, 
                                                                print_handler,
                                                                ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
  return true;
}

LIB_simpleFuncCPP_C_API 
bool MW_CALL_CONV simpleFuncCPPInitialize(void)
{
  return simpleFuncCPPInitializeWithHandlers(mclDefaultErrorHandler, 
                                             mclDefaultPrintHandler);
}

LIB_simpleFuncCPP_C_API 
void MW_CALL_CONV simpleFuncCPPTerminate(void)
{
  if (_mcr_inst != NULL)
    mclTerminateInstance(&_mcr_inst);
}

LIB_simpleFuncCPP_C_API 
void MW_CALL_CONV simpleFuncCPPPrintStackTrace(void) 
{
  char** stackTrace;
  int stackDepth = mclGetStackTrace(&stackTrace);
  int i;
  for(i=0; i<stackDepth; i++)
  {
    mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
    mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
  }
  mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_simpleFuncCPP_C_API 
bool MW_CALL_CONV mlxSimpleFunction(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "simpleFunction", nlhs, plhs, nrhs, prhs);
}

LIB_simpleFuncCPP_CPP_API 
void MW_CALL_CONV simpleFunction(int nargout, mwArray& y, const mwArray& x1, const 
                                 mwArray& x2)
{
  mclcppMlfFeval(_mcr_inst, "simpleFunction", nargout, 1, 2, &y, &x1, &x2);
}

