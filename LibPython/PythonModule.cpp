#include "StdAfx.h"
#include "PythonModule.h"

PythonModule::PythonModule( std::string ModuleName )
: m_ModuleName(ModuleName)
{
	m_pMethodDef = NULL;
	m_pModuleDef = NULL;
}

PythonModule::~PythonModule(void)
{
	if(m_pMethodDef)
		delete m_pMethodDef;

	if(m_pModuleDef)
		delete m_pModuleDef;
}

BOOL PythonModule::AddModuleDef(char* szModuleName)
{
	if(NULL == szModuleName)
		return FALSE;

	if(NULL == m_pMethodDef)
		return FALSE;

	if(NULL != m_pModuleDef)
		return FALSE;

	m_pModuleDef = new PyModuleDef;

	PyModuleDef_Base base = PyModuleDef_HEAD_INIT;


	m_pModuleDef->m_base = base;

	int iLen = strlen(szModuleName);

	m_pModuleDef->m_name = (const char*)malloc(iLen + 1);
	strcpy((char*)m_pModuleDef->m_name, szModuleName);
	m_pModuleDef->m_doc = NULL;
	m_pModuleDef->m_size = -1;
	m_pModuleDef->m_methods = m_pMethodDef;

	return TRUE;
}
