#pragma once
#include <map>
#include <string>
#include <Python.h>

class CPythonArg;
class PythonResult;

class PythonClassWrapper
{
public:
	PythonClassWrapper(char* szModuleName, char* szClassName );
	virtual ~PythonClassWrapper(void);

	BOOL CallMethod(PythonResult* pResult, char* szMethodName, CPythonArg* pArg = NULL);
	BOOL CallMethod(char* szMethodName, CPythonArg* pArg = NULL);

protected:

private:
	PyObject* m_pClassName;
	PyObject* m_pModuleName;
	PyObject* m_pModule;
	PyObject* m_pDict;
	PyObject* m_pInstance;
};