#include "StdAfx.h"
#include "PythonWrapper.h"
#include "PythonFunctionMap.h"
#include "PythonResultInt.h"

CPythonWrapper::CPythonWrapper(void)
{
}

CPythonWrapper::~CPythonWrapper(void)
{
	Finally();
}

BOOL CPythonWrapper::Finally()
{
	mapPythonModule::iterator iter = m_mapPythonModule.begin();

	for(;iter != m_mapPythonModule.end(); iter++)
	{
		CPythonFunctionMap* pMap = iter->second;
		delete pMap;
	}

	m_mapPythonModule.clear();

	return TRUE;
}

BOOL CPythonWrapper::ExcecuteFunc(PythonResult* pResult, char* szModuleName, char* szFunctionName, PyObject* pArgs /*= NULL*/ )
{
	PyObject* pFunc = GetFunc(szModuleName, szFunctionName);
	BOOL bResult = FALSE;

	if(NULL == pFunc)
		return NULL;

	if(pFunc && PyCallable_Check(pFunc))
	{
		PyObject* pObject = PyObject_CallObject(pFunc, pArgs);

		if(pObject != NULL)
		{
			bResult = pResult->SetResult(pObject);
			Py_DECREF(pObject);
		}
	}

	return bResult;

}

BOOL CPythonWrapper::ExcecuteFunc( char* szModuleName, char* szFunctionName, PyObject* pArgs /*= NULL*/ )
{
	PyObject* pFunc = GetFunc(szModuleName, szFunctionName);
	BOOL bResult = FALSE;

	if(NULL == pFunc)
		return NULL;

	if(pFunc && PyCallable_Check(pFunc))
	{
		PyObject* pObject = PyObject_CallObject(pFunc, pArgs);

		if(pObject != NULL)
		{
			bResult = TRUE;
			Py_DECREF(pObject);
		}
	}

	return bResult;
}

PyObject* CPythonWrapper::GetFunc(char* szModuleName, char* szFunctionName)
{
	if(NULL == szModuleName || NULL == szFunctionName)
		return NULL;

	std::string szString = szModuleName;

	mapPythonModule::iterator iter = m_mapPythonModule.find(szString);

	if(iter == m_mapPythonModule.end())
	{
		return NULL;
	}

	CPythonFunctionMap* pModule = iter->second;

	return pModule->GetFunc(szFunctionName);
}

BOOL CPythonWrapper::AddModule(char* szModuleName)
{
	if(NULL == szModuleName)
		return FALSE;

	PyObject* pModuleName = PyUnicode_FromString(szModuleName);

	if(NULL == pModuleName)
		return FALSE;

	PyObject* pModule = PyImport_Import(pModuleName);

	if(NULL == pModule)
		return FALSE;

	CPythonFunctionMap* pModuleInfo = new CPythonFunctionMap();
	pModuleInfo->m_pPythonModule = pModule;

	m_mapPythonModule.insert(mapPythonModule::value_type(szModuleName, pModuleInfo));

	return TRUE;
}

BOOL CPythonWrapper::AddFunction(char* szModuleName, char* szFunctionName)
{
	mapPythonModule::iterator iter = m_mapPythonModule.find(szModuleName);

	if(iter == m_mapPythonModule.end())
		return FALSE;

	CPythonFunctionMap* pMap = iter->second;

	PyObject* pFunc = PyObject_GetAttrString(pMap->m_pPythonModule, szFunctionName);

	if(NULL == pFunc)
		return FALSE;

	pMap->m_mapPythonFunc.insert(CPythonFunctionMap::mapPythonFunc::value_type(szFunctionName, pFunc));

	return TRUE;
}