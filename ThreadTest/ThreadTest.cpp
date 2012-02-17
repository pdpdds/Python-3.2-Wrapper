// ThreadTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <Python.h>
#include "PythonScriptExecutor.h"
#include "PythonSampleModule.h"

int _tmain(int argc, _TCHAR* argv[])
{
	PythonSampleModule Module("SampleModule");
	Module.Initialize();
	
	Py_Initialize();

	PyImport_ImportModule("SampleModule");


	PythonScriptExecutor Executor;
	if(TRUE == Executor.ReadPythonScript("test_thread.py"))
	{
		Executor.Execute();
	}

	int arg = 0;
	PyObject *arglist = NULL;
	PyObject *result  = NULL;

	if( PythonSampleModule::fPythonCallback != NULL )
	{
		for( int i = 0; i < 100; ++i )
		{
			++arg;
			arglist = Py_BuildValue( "(i)", arg );
			result  = PyEval_CallObject( PythonSampleModule::fPythonCallback, arglist );
			Py_DECREF( arglist );

			if( result != NULL )
				Py_DECREF( result );
		}
	}

	Py_Finalize();

	return 0;
}

