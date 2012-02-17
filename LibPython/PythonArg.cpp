#include "StdAfx.h"
#include "PythonArg.h"
#include <assert.h>

CPythonArg::CPythonArg(int ArgCount)
: m_pArgs(NULL)
, m_ArgCount(ArgCount)
, m_Index(0)
{
	if(ArgCount <= 0 || ArgCount > 10)
	{
		assert(1);
	}

	m_pArgs = PyTuple_New(m_ArgCount);
}

CPythonArg::~CPythonArg(void)
{
	m_vecArgs.clear();

	Py_DECREF(m_pArgs);
}

BOOL CPythonArg::ValidArgCount(int ArgCount)
{
	if(ArgCount < 0 || ArgCount > 10)
	{
		assert(1);
		return FALSE;
	}

	return TRUE;
}

BOOL CPythonArg::Add(int value)
{
	if(ValidArgCount(m_Index) == FALSE)
		return FALSE;

	PyObject* pValue = NULL;

	pValue = PyLong_FromLong(value);

	if(!pValue)
	{
		return FALSE;
	}

	PyTuple_SetItem(m_pArgs, m_Index, pValue);
	m_vecArgs.push_back(pValue);

	m_Index++;

	return TRUE;
}

BOOL CPythonArg::Add(DWORD value)
{
	if(ValidArgCount(m_Index) == FALSE)
		return FALSE;

	PyObject* pValue = NULL;

	pValue = PyLong_FromLong(value);

	if(!pValue)
	{
		return FALSE;
	}

	PyTuple_SetItem(m_pArgs, m_Index, pValue);
	m_vecArgs.push_back(pValue);

	m_Index++;

	return TRUE;
}

BOOL CPythonArg::Add(long value)
{
	if(ValidArgCount(m_Index) == FALSE)
		return FALSE;

	PyObject* pValue = NULL;

	pValue = PyLong_FromLong(value);

	if(!pValue)
	{
		return FALSE;
	}

	PyTuple_SetItem(m_pArgs, m_Index, pValue);
	m_vecArgs.push_back(pValue);

	m_Index++;

	return TRUE;
}

BOOL CPythonArg::Add(float value)
{
	if(ValidArgCount(m_Index) == FALSE)
		return FALSE;

	PyObject* pValue = NULL;

	pValue = PyLong_FromDouble(value);

	if(!pValue)
	{
		return FALSE;
	}

	PyTuple_SetItem(m_pArgs, m_Index, pValue);
	m_vecArgs.push_back(pValue);

	m_Index++;

	return TRUE;
}

BOOL CPythonArg::Add(double& value)
{
	if(ValidArgCount(m_Index) == FALSE)
		return FALSE;

	PyObject* pValue = NULL;

	pValue = PyLong_FromDouble(value);

	if(!pValue)
	{
		return FALSE;
	}

	PyTuple_SetItem(m_pArgs, m_Index, pValue);
	m_vecArgs.push_back(pValue);

	m_Index++;

	return TRUE;
}

BOOL CPythonArg::Add(short value)
{
	if(ValidArgCount(m_Index) == FALSE)
		return FALSE;

	PyObject* pValue = NULL;

	pValue = PyLong_FromLong(value);

	if(!pValue)
	{
		return FALSE;
	}

	PyTuple_SetItem(m_pArgs, m_Index, pValue);
	m_vecArgs.push_back(pValue);

	m_Index++;

	return TRUE;
}

BOOL CPythonArg::Add(USHORT value)
{
	if(ValidArgCount(m_Index) == FALSE)
		return FALSE;

	PyObject* pValue = NULL;

	pValue = PyLong_FromLong(value);

	if(!pValue)
	{
		return FALSE;
	}

	PyTuple_SetItem(m_pArgs, m_Index, pValue);
	m_vecArgs.push_back(pValue);

	m_Index++;

	return TRUE;
}

BOOL CPythonArg::Add(BYTE value)
{
	if(ValidArgCount(m_Index) == FALSE)
		return FALSE;

	PyObject* pValue = NULL;

	pValue = PyLong_FromLong(value);

	if(!pValue)
	{
		return FALSE;
	}

	PyTuple_SetItem(m_pArgs, m_Index, pValue);
	m_vecArgs.push_back(pValue);

	m_Index++;

	return TRUE;
}

BOOL CPythonArg::Add(char value)
{
	if(ValidArgCount(value) == FALSE)
		return FALSE;

	PyObject* pValue = NULL;

	pValue = PyLong_FromLong(value);

	if(!pValue)
	{
		return FALSE;
	}

	PyTuple_SetItem(m_pArgs, m_Index, pValue);
	m_vecArgs.push_back(pValue);

	m_Index++;

	return TRUE;
}



BOOL CPythonArg::Add(LPSTR value)
{
	if(NULL == value)
		return FALSE;

	if(m_Index >= m_ArgCount)
	{
		assert(1);
		return FALSE;
	}

	PyObject* pValue = NULL;

	pValue = PyUnicode_FromString(value);

	if(!pValue)
		return FALSE;

	PyTuple_SetItem(m_pArgs, m_Index, pValue);
	m_vecArgs.push_back(pValue);

	m_Index++;

	return TRUE;
}

BOOL CPythonArg::Add( LPWSTR value )
{
	if(NULL == value)
		return FALSE;

	if(m_Index >= m_ArgCount)
	{
		assert(1);
		return FALSE;
	}

	PyObject* pValue = NULL;

	pValue = PyUnicode_FromUnicode(value, wcslen(value));

	if(!pValue)
		return FALSE;

	PyTuple_SetItem(m_pArgs, m_Index, pValue);
	m_vecArgs.push_back(pValue);

	m_Index++;

	return TRUE;
}

BOOL CPythonArg::Reset(int ArgCount)
{
	if(ValidArgCount(ArgCount) == FALSE)
		return FALSE;

	Py_DECREF(m_pArgs);

	m_ArgCount = ArgCount;
	m_Index = 0;
	m_pArgs = PyTuple_New(m_ArgCount);

	m_vecArgs.clear();
	
	return TRUE;
}

