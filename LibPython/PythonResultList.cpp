#include "StdAfx.h"
#include "PythonResultList.h"

PythonResultList::PythonResultList(void)
{
}

PythonResultList::~PythonResultList(void)
{
	m_vecString.clear();
}

BOOL PythonResultList::SetResult( PyObject* pObject )
{
	return FALSE;
}