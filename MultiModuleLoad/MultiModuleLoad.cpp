// LibPythonTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PythonWrapper.h"
#include "PythonArg.h"
#include <iostream>
#include "PythonResultInt.h"
#include "PythonResultUnicode.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Py_Initialize();

	CPythonWrapper Wrapper;

	Wrapper.AddModule("py_function");
	Wrapper.AddFunction("py_function", "multiply1");
	Wrapper.AddFunction("py_function", "multiply");

	Wrapper.AddModule("hello");
	Wrapper.AddFunction("hello", "echo");

	CPythonArg Args(2);

	int FirstArg = 5, SecondArg = 4;
	Args.Add(FirstArg);
	Args.Add(SecondArg);

	PythonResultInt Result;
	BOOL bResult = Wrapper.ExcecuteFunc(&Result, "py_function", "multiply1", Args.GetArg());

	if(bResult)
	{
		printf("result of call : %ld\n", Result.GetResult());
	}

	Args.Reset(1);
	Args.Add(L"Python Wrapper Test!!");

	PythonResultUnicode ResultUnicode;
	bResult = Wrapper.ExcecuteFunc(&ResultUnicode, "hello", "echo", Args.GetArg());

	if(bResult)
	{
		std::wcout << ResultUnicode.GetResult().c_str();
	}

	Py_Finalize();

	getchar();

	return 0;
}