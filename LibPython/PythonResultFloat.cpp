#include "StdAfx.h"
#include "PythonResultFloat.h"

PythonResultFloat::PythonResultFloat(void)
{
}

PythonResultFloat::~PythonResultFloat(void)
{
}

BOOL PythonResultFloat::SetResult( PyObject* pObject )
{

	if (PyFloat_Check(pObject))
	{
		m_Result = (float)PyFloat_AsDouble(pObject);
		return TRUE;
	}

	return FALSE;
}