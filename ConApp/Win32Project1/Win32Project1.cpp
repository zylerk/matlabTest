// Win32Project1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

// Include the C++ shared library header 
#include "simpleFunction.h"

void display(const mxArray* );

int run_main(int argc, char **argv)
{
	// Set up the application state for the MATLAB Runtime instance created in the application.
	if (!mclInitializeApplication(NULL, 0))
	{
		std::cerr << "could not initialize the application properly"
			<< std::endl;
		return -1;
	}

	// Load the required MATLAB code into the MATLAB Runtime.
	if (!simpleFunctionInitialize())
	{
		std::cerr << "could not initialize the library properly"
			<< std::endl;
		return -1;
	}

	try
	{
		// Create input data
		double data[] = { 1,2,3,4,5,6,7,8,9 };
		//mwArray in1(1, 1, mxDOUBLE_CLASS, mxREAL);
		//mwArray in2(1, 1, mxDOUBLE_CLASS, mxREAL);
		//in1.SetData(data, 1);
		//in2.SetData(data, 1);

		mxArray *in1 = NULL;
		mxArray *in2 = NULL;

		in1 = mxCreateDoubleMatrix(1, 1, mxREAL);
		in2 = mxCreateDoubleMatrix(1, 1, mxREAL);
		memcpy(mxGetPr(in1), data, 1 * sizeof(double));
		memcpy(mxGetPr(in2), data, 1 * sizeof(double));

		// Create output array
		mxArray *out=NULL;

		// Call the library function
		//simpleFunction(1, out, in1, in2);
		mlfSimpleFunction(1, &out, in1, in2);

		std::cout << "The value of added matrix is:" << std::endl;
		display(out);
		//std::cout << out << std::endl;

		mxDestroyArray(out);
		mxDestroyArray(in1);
		mxDestroyArray(in2);

	}

	// Catch the MATLAB generated mwException
	catch (const mwException& e)
	{
		std::cerr << e.what() << std::endl;
		return -2;
	}

	// Catch any other exceptions that may be thrown
	catch (...)
	{
		std::cerr << "Unexpected error thrown" << std::endl;
		return -3;
	}

	// Release the resources used by the generated MATLAB code
	simpleFunctionTerminate();

	// Release all state and resources used by the MATLAB Runtime for the application
	mclTerminateApplication();
	return 0;
}

int main()
{
	// Initialize the MATLAB Runtime
	mclmcrInitialize();

	// Create a new thread and run the MATLAB generated code in it.
	return mclRunMain((mclMainFcnType)run_main, 0, NULL);
}


void display(const mxArray* in)
{
	int i = 0, j = 0;    /* loop index variables */
	int r = 0, c = 0;   /* variables to store the row and
						* column length of the matrix */
	double *data; /* variable to point to the double
				  * data stored within the mxArray */

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
