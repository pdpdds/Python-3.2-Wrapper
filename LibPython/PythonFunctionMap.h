#pragma once
#include <map>
#include <string>
#include <Python.h> 

class CPythonFunctionMap
{
	friend class CPythonWrapper;

	typedef std::map<std::string, PyObject*> mapPythonFunc;

public:
	CPythonFunctionMap(void);
	virtual ~CPythonFunctionMap(void);

	PyObject* GetFunc(char* szFunctionName);

protected:

private:
	mapPythonFunc m_mapPythonFunc;
	PyObject* m_pPythonModule;
};
