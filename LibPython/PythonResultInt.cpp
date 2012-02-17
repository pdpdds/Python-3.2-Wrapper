#include "StdAfx.h"
#include "PythonResultInt.h"

PythonResultInt::PythonResultInt(void)
{
}

PythonResultInt::~PythonResultInt(void)
{
}

BOOL PythonResultInt::SetResult( PyObject* pObject )
{
	if (PyLong_Check(pObject))
	{
		m_Result = PyLong_AS_LONG(pObject);
		return TRUE;
	}
	
	return FALSE;
}