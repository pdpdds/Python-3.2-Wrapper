#include "StdAfx.h"
#include "PythonSampleModule.h"

PyObject* PythonSampleModule::fPythonCallback = NULL;

PyMethodDef SampleModulemethodDefinitions[] =
{
	{ "myCppFunction", PythonSampleModule::myCppFunction, METH_VARARGS, "Sets an int value" },
	{ "setCallback", PythonSampleModule::SetCallback, METH_VARARGS, "Sets a call-back function in Python" },
	{NULL, NULL, 0, NULL} 
};

static struct PyModuleDef SampleModuleDef = {
   PyModuleDef_HEAD_INIT,
   "SampleModule",   /* name of module */
   "DocumentDesc", /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   SampleModulemethodDefinitions
};


PyMODINIT_FUNC PyInitSampleModule()
{
	return PyModule_Create(&SampleModuleDef);
}

PythonSampleModule::PythonSampleModule( std::string ModuleName )
: PythonModule(ModuleName)
{
}

PythonSampleModule::~PythonSampleModule(void)
{
}

BOOL PythonSampleModule::AddMethodDef()
{
	m_pMethodDef = SampleModulemethodDefinitions;
	return TRUE;
}

BOOL PythonSampleModule::Initialize()
{
	//AddMethodDef();
	//AddModuleDef((char*)GetModuleName().c_str());
	PyImport_AppendInittab(GetModuleName().c_str(), PyInitSampleModule);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////////////
//파이썬이 호출할 C++ 인터페이스
/////////////////////////////////////////////////////////////////////////////////////
PyObject* PythonSampleModule::SetCallback( PyObject* self, PyObject* args )
{
	PyObject *result = NULL;
	PyObject *temp   = NULL;

	if( PyArg_ParseTuple( args, "O", &temp ) )
	{
		if( !PyCallable_Check( temp ) ) 
		{
			PyErr_SetString( PyExc_TypeError, "parameter must be callable" );
			Py_INCREF( Py_None );
			return Py_None;
		}

		Py_XINCREF( temp );              // Ref the new call-back
		Py_XDECREF( fPythonCallback );  // Unref the previous call-back
		fPythonCallback = temp;         // Cache the new call-back
	}

	Py_INCREF( Py_None );
	return Py_None;
}

PyObject* PythonSampleModule::myCppFunction( PyObject* self, PyObject* args )
{
	int nValue;

	if( PyArg_ParseTuple( args, "i", &nValue ) )
	{
		cout << "Python thread - Script called myCppFunction and passed: " << nValue << endl;
	}

	Py_INCREF( Py_None );
	return Py_None;
}