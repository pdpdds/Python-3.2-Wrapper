#pragma once
#include "Python.h"
#include <vector>

class CPythonArg
{
	friend class PythonClassWrapper;
	typedef std::vector<PyObject*> vecArgs;
public:
	CPythonArg(int ArgCount);
	virtual ~CPythonArg(void);

	BOOL Add(int value);
	BOOL Add(LPSTR value);
	BOOL Add(LPWSTR value);
	BOOL Add(DWORD value);
	BOOL Add(long value);
	BOOL Add(float value);
	BOOL Add(double& value);
	BOOL Add(short value);
	BOOL Add(USHORT value);
	BOOL Add(BYTE value);
	BOOL Add(char value);

	BOOL Reset(int ArgCount);

	PyObject* GetArg(){return m_pArgs;}
	int GetArgCount(){return m_ArgCount;}

protected:
	BOOL ValidArgCount(int ArgCount);

private:
	PyObject* m_pArgs;
	int m_ArgCount;
	int m_Index;

	vecArgs m_vecArgs;
};
