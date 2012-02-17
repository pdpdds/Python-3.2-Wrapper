#pragma once
#include "Python.h"

class PythonResult
{
public:
	PythonResult(void){}
	virtual ~PythonResult(void){}

	virtual BOOL SetResult(PyObject* pObject) = 0;

protected:

private:
};
