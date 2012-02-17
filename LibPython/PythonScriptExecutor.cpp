#include "StdAfx.h"
#include "PythonScriptExecutor.h"
#include <iostream>
#include <fstream>

using namespace std;

PythonScriptExecutor::PythonScriptExecutor(void)
: m_pMainModule(NULL)
, m_pMainDictionary(NULL)
, m_pPythonScript(NULL)
{
}

PythonScriptExecutor::~PythonScriptExecutor(void)
{
	if(m_pPythonScript)
	{
		delete m_pPythonScript;
		m_pPythonScript = NULL;
	}
}

BOOL PythonScriptExecutor::ReadPythonScript( char* szFileName )
{
	ifstream pythonFile;

	if(m_pPythonScript != NULL)
	{
		delete m_pPythonScript;
		m_pPythonScript = NULL;
	}

	if(m_pMainModule == NULL || m_pMainDictionary == NULL)
	{
		m_pMainModule  = PyImport_AddModule( "__main__" );
		m_pMainDictionary = PyModule_GetDict( m_pMainModule );
	}

	pythonFile.open( szFileName );

	if ( !pythonFile.is_open() ) 
	{
		cout << "Cannot open Python script file, \"" << szFileName << "\"!" << endl;
		return FALSE;
	}
	else
	{
		// Get the length of the file
		pythonFile.seekg( 0, ios::end );
		int nLength = pythonFile.tellg();
		pythonFile.seekg( 0, ios::beg );

		// Allocate  a char buffer for the read.
		char *buffer = new char[nLength];
		memset( buffer, 0, nLength );

		// read data as a block:
		pythonFile.read( buffer, nLength );

		m_pPythonScript = new string;
		m_pPythonScript->assign( buffer );

		delete [] buffer;
		pythonFile.close();

		return TRUE;
	}
}

BOOL PythonScriptExecutor::Execute()
{
	if (m_pMainModule == NULL || 
		m_pMainDictionary == NULL || 
		m_pPythonScript == NULL)
	{
		return FALSE;
	}

	if( m_pPythonScript != NULL )
	{
		PyRun_String( m_pPythonScript->c_str(), Py_file_input, 
			m_pMainDictionary, m_pMainDictionary );

		delete m_pPythonScript;
		m_pPythonScript = NULL;
	}

	return TRUE;
}