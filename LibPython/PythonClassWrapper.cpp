#include "StdAfx.h"
#include "PythonClassWrapper.h"
#include <assert.h>
#include "PythonArg.h"
#include "PythonResult.h"

PythonClassWrapper::PythonClassWrapper(char* szModuleName, char* szClassName )
{
	m_pModuleName = PyUnicode_FromString(szModuleName);
	m_pModule = PyImport_Import(m_pModuleName);
	m_pDict = PyModule_GetDict(m_pModule);	

	m_pClassName = PyDict_GetItemString(m_pDict, szClassName);

	if (PyCallable_Check(m_pClassName))
	{
		m_pInstance = PyObject_CallObject(m_pClassName, NULL); 
	}
}

PythonClassWrapper::~PythonClassWrapper(void)
{

}

BOOL PythonClassWrapper::CallMethod(PythonResult* pResult, char* szMethodName, CPythonArg* pArg )
{
	PyObject* pMethodName = NULL;
	PyObject* pValue = NULL;
	pMethodName = PyUnicode_FromString(szMethodName);
	BOOL bResult = FALSE;

	if(pArg == NULL)
	{
		pValue = PyObject_CallMethod(m_pInstance, szMethodName, NULL);
	}
	else
	{
		if(1 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
												pMethodName, 
												pArg->m_vecArgs[0], 
												NULL);
		}
		else if(2 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
												pMethodName,
												pArg->m_vecArgs[0], 
												pArg->m_vecArgs[1], 
												NULL);
		}
		else if(3 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
												pMethodName, 
												pArg->m_vecArgs[0], 
												pArg->m_vecArgs[1], 
												pArg->m_vecArgs[2],NULL);
		}
		else if(4 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
												pMethodName, 
												pArg->m_vecArgs[0], 
												pArg->m_vecArgs[1], 
												pArg->m_vecArgs[2], 
												pArg->m_vecArgs[3], 
												NULL);
		}
		else if(5 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
												pMethodName, 
												pArg->m_vecArgs[0], 
												pArg->m_vecArgs[1], 
												pArg->m_vecArgs[2], 
												pArg->m_vecArgs[3], 
												pArg->m_vecArgs[4], 
												NULL);
		}
		else if(6 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
												pMethodName, 
												pArg->m_vecArgs[0], 
												pArg->m_vecArgs[1], 
												pArg->m_vecArgs[2], 
												pArg->m_vecArgs[3],
												pArg->m_vecArgs[4], 
												pArg->m_vecArgs[5], 
												NULL);
		}
		else if(7 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
												pMethodName, 
												pArg->m_vecArgs[0], 
												pArg->m_vecArgs[1], 
												pArg->m_vecArgs[2], 
												pArg->m_vecArgs[3],
												pArg->m_vecArgs[4], 
												pArg->m_vecArgs[5], 
												pArg->m_vecArgs[6], 
												NULL);
		}
		else if(8 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
												pMethodName, 
												pArg->m_vecArgs[0], 
												pArg->m_vecArgs[1], 
												pArg->m_vecArgs[2], 
												pArg->m_vecArgs[3],
												pArg->m_vecArgs[4], 
												pArg->m_vecArgs[5], 
												pArg->m_vecArgs[6], 
												pArg->m_vecArgs[7], 
												NULL);
		}
		else if(9 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
												pMethodName, 
												pArg->m_vecArgs[0], 
												pArg->m_vecArgs[1], 
												pArg->m_vecArgs[2], 
												pArg->m_vecArgs[3], 
												pArg->m_vecArgs[4], 
												pArg->m_vecArgs[5], 
												pArg->m_vecArgs[6], 
												pArg->m_vecArgs[7], 
												pArg->m_vecArgs[8], 
												NULL);
		}
	}

	Py_DECREF(pMethodName);

	if(pValue != NULL)
	{
		bResult = pResult->SetResult(pValue);
		Py_DECREF(pValue);

	}

	return bResult;
}

BOOL PythonClassWrapper::CallMethod(char* szMethodName, CPythonArg* pArg )
{
	PyObject* pMethodName = NULL;
	PyObject* pValue = NULL;
	pMethodName = PyUnicode_FromString(szMethodName);
	BOOL bResult = FALSE;

	if(pArg == NULL)
	{
		pValue = PyObject_CallMethod(m_pInstance, szMethodName, NULL);
	}
	else
	{
		if(1 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
				pMethodName, 
				pArg->m_vecArgs[0], 
				NULL);
		}
		else if(2 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
				pMethodName,
				pArg->m_vecArgs[0], 
				pArg->m_vecArgs[1], 
				NULL);
		}
		else if(3 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
				pMethodName, 
				pArg->m_vecArgs[0], 
				pArg->m_vecArgs[1], 
				pArg->m_vecArgs[2],NULL);
		}
		else if(4 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
				pMethodName, 
				pArg->m_vecArgs[0], 
				pArg->m_vecArgs[1], 
				pArg->m_vecArgs[2], 
				pArg->m_vecArgs[3], 
				NULL);
		}
		else if(5 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
				pMethodName, 
				pArg->m_vecArgs[0], 
				pArg->m_vecArgs[1], 
				pArg->m_vecArgs[2], 
				pArg->m_vecArgs[3], 
				pArg->m_vecArgs[4], 
				NULL);
		}
		else if(6 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
				pMethodName, 
				pArg->m_vecArgs[0], 
				pArg->m_vecArgs[1], 
				pArg->m_vecArgs[2], 
				pArg->m_vecArgs[3],
				pArg->m_vecArgs[4], 
				pArg->m_vecArgs[5], 
				NULL);
		}
		else if(7 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
				pMethodName, 
				pArg->m_vecArgs[0], 
				pArg->m_vecArgs[1], 
				pArg->m_vecArgs[2], 
				pArg->m_vecArgs[3],
				pArg->m_vecArgs[4], 
				pArg->m_vecArgs[5], 
				pArg->m_vecArgs[6], 
				NULL);
		}
		else if(8 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
				pMethodName, 
				pArg->m_vecArgs[0], 
				pArg->m_vecArgs[1], 
				pArg->m_vecArgs[2], 
				pArg->m_vecArgs[3],
				pArg->m_vecArgs[4], 
				pArg->m_vecArgs[5], 
				pArg->m_vecArgs[6], 
				pArg->m_vecArgs[7], 
				NULL);
		}
		else if(9 == pArg->GetArgCount())
		{
			pValue = PyObject_CallMethodObjArgs(m_pInstance, 
				pMethodName, 
				pArg->m_vecArgs[0], 
				pArg->m_vecArgs[1], 
				pArg->m_vecArgs[2], 
				pArg->m_vecArgs[3], 
				pArg->m_vecArgs[4], 
				pArg->m_vecArgs[5], 
				pArg->m_vecArgs[6], 
				pArg->m_vecArgs[7], 
				pArg->m_vecArgs[8], 
				NULL);
		}
	}

	Py_DECREF(pMethodName);

	if(pValue != NULL)
	{
		bResult = TRUE;
		Py_DECREF(pValue);

	}

	return bResult;
}