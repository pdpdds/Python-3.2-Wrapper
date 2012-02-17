#include "StdAfx.h"
#include "PythonFunctionMap.h"

CPythonFunctionMap::CPythonFunctionMap(void)
: m_pPythonModule(NULL)
{
}

CPythonFunctionMap::~CPythonFunctionMap(void)
{
	mapPythonFunc::iterator iter = m_mapPythonFunc.begin();

	for(;iter != m_mapPythonFunc.end(); iter++)
	{
		PyObject* pFunc = iter->second;
		Py_XDECREF(pFunc);
	}

	m_mapPythonFunc.clear();

	if(m_pPythonModule)
	{
		Py_DECREF(m_pPythonModule);
	}
}

PyObject* CPythonFunctionMap::GetFunc(char* szFunctionName)
{
	mapPythonFunc::iterator iter = m_mapPythonFunc.find(szFunctionName);

	if(iter == m_mapPythonFunc.end())
	{
		return NULL;
	}

	return iter->second;
}
