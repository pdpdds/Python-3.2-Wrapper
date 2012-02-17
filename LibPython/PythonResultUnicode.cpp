#include "StdAfx.h"
#include "PythonResultUnicode.h"

PythonResultUnicode::PythonResultUnicode(void)
{
}

PythonResultUnicode::~PythonResultUnicode(void)
{
}

BOOL PythonResultUnicode::SetResult( PyObject* pObject )
{
	if (PyUnicode_Check(pObject))
	{
		m_Result = PyUnicode_AS_UNICODE(pObject);
		return TRUE;
	}

	return FALSE;
}