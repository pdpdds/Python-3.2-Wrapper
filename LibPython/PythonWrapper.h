#pragma once
#include <map>
#include <string>
#include <Python.h>
#include <Windows.h>

class CPythonFunctionMap;
class PythonResult;

class CPythonWrapper
{
	typedef std::map<std::string, CPythonFunctionMap*> mapPythonModule;

public:
	CPythonWrapper(void);
	virtual ~CPythonWrapper(void);

	BOOL Finally();

	PyObject* GetFunc(char* szModuleName, char* szFunctionName);
	BOOL AddModule(char* szModuleName);
	BOOL AddFunction(char* szModuleName, char* szFunctionName);

	BOOL ExcecuteFunc(PythonResult* pResult, char* szModuleName, char* szFunctionName, PyObject* pArgs = NULL);
	BOOL ExcecuteFunc(char* szModuleName, char* szFunctionName, PyObject* pArgs = NULL);

protected:

private:
	mapPythonModule m_mapPythonModule;
};

