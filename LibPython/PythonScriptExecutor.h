#pragma once
#include <map>
#include <string>
#include <Python.h>

class PythonScriptExecutor
{
public:
	PythonScriptExecutor(void);
	virtual ~PythonScriptExecutor(void);

	BOOL ReadPythonScript(char* szFileName);
	BOOL Execute();

protected:

private:
	PyObject *m_pMainModule;
	PyObject *m_pMainDictionary;

	std::string *m_pPythonScript;//파이썬 스크립트를 담을 버퍼
};
