// PythonClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PythonClassWrapper.h"
#include "PythonArg.h"
#include "PythonResultInt.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Py_Initialize();

	PythonClassWrapper* pInstance = new PythonClassWrapper("py_class", "Multiply");
	CPythonArg Args(2);
	Args.Add(5);
	Args.Add(4);

	PythonResultInt Result;
	BOOL bResult = pInstance->CallMethod(&Result, "multiply2", &Args);

	if(bResult)
	{
		printf("result of call : %ld\n", Result.GetResult());
	}

	Py_Finalize();

	return 0;
}
