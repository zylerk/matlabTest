// ConApp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

//#include "simpleFunction.h"
#include "simpleFuncCPP.h"


void display(const mxArray* in)
{
	int i = 0, j = 0; /* loop index variables */
	int r = 0, c = 0; /* variables to store the row and column length of the matrix */
	double *data; /* variable to point to the double data stored within the mxArray */

				  /* Get the size of the matrix */
	r = mxGetM(in);
	c = mxGetN(in);

	/* Get a pointer to the double data in mxArray */
	data = mxGetPr(in);

	/* Loop through the data and display the same in matrix format */
	for (i = 0; i < c; i++) {
		for (j = 0; j < r; j++) {
			printf("%4.2f\t", data[j*c + i]);
		}
		printf("\n");
	}
	printf("\n");
}


int run_main(int argc, char **argv)
{
	if (!mclInitializeApplication(NULL, 0))
	{
		fprintf(stderr, "Could not initialize the app.\n");
		return -1;
	}

	//mxArray *in1, *in2;
	//in1 = mxCreateDoubleScalar(1.0);
	//in2 = mxCreateDoubleScalar(2.0);

	mwArray in1(1, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray in2(1, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray out(1, 1, mxDOUBLE_CLASS, mxREAL);
			

	if (!simpleFuncCPPInitialize())
	{
		fprintf(stderr, "could not init the lib.\n");
		return -2;
	}
	else
	{
		//mlfSimpleFunction(1, &out, in1, in2);
		simpleFunction(1, out, in1, in2);

		printf("the value of fund is");
		//display(out);

		//mxDestroyArray(out); out = 0;

		simpleFuncCPPTerminate();

		//mxDestroyArray(in1);
		//mxDestroyArray(in2);
	}

	mclTerminateApplication();

	return 0;
}


int main()
{
	mclmcrInitialize();

	
	return mclRunMain((mclMainFcnType)run_main, 0, NULL);

	
}





