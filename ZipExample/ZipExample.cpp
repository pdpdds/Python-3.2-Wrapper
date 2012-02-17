// ZipExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PythonWrapper.h"
#include "PythonArg.h"
#include "PythonResultInt.h"
#include <assert.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Py_Initialize();

	CPythonWrapper Wrapper;

	Wrapper.AddModule("Zipper");
	Wrapper.AddFunction("Zipper", "Pack");

	CPythonArg Args(2);

	Args.Add("Image.zip");
	Args.Add("jpg");

	BOOL bResult = Wrapper.ExcecuteFunc("Zipper", "Pack", Args.GetArg());

	assert(bResult == TRUE);



	Py_Finalize();

	return 0;
}