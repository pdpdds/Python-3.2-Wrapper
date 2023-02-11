// LibPythonTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PythonWrapper.h"
#include "PythonArg.h"
#include <iostream>
#include "PythonResultInt.h"
#include "PythonResultUnicode.h"

std::string UnicodeToAnsi(std::wstring str)
{

	int nRequired = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), (int)str.length(), NULL, 0, NULL, NULL);
	if (nRequired == 0) return "";

	CHAR* lpWideChar = new CHAR[nRequired + 1];
	if (lpWideChar == NULL) return "";
	nRequired = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), (int)str.length(), lpWideChar, nRequired, NULL, NULL);
	if (nRequired == 0) return "";
	lpWideChar[nRequired] = '\0';
	std::string wstr = lpWideChar;
	delete[]lpWideChar;
	return wstr;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Py_Initialize();

	CPythonWrapper Wrapper;

	//Wrapper.AddModule("py_function");
	//Wrapper.AddFunction("py_function", "multiply1");
	//Wrapper.AddFunction("py_function", "multiply");

	Wrapper.AddModule("checksum");
	Wrapper.AddFunction("checksum", "checksum");

	PythonResultUnicode Result;
	BOOL bResult = Wrapper.ExcecuteFunc(&Result, "checksum", "checksum", 0);
	
	std::string result = UnicodeToAnsi((wchar_t*)Result.GetResult().c_str());

	//if(bResult)
	{
		std::cout << result.c_str();
	}

	CPythonArg Args(2);

	int FirstArg = 5, SecondArg = 4;
	Args.Add(FirstArg);
	Args.Add(SecondArg);

	

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

	//getchar();

	return 0;
}