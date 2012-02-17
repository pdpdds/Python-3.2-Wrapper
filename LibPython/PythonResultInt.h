#pragma once
#include "PythonResult.h"

class PythonResultInt : public PythonResult
{
public:
	PythonResultInt(void);
	virtual ~PythonResultInt(void);

	virtual BOOL SetResult(PyObject* pObject) override;
	int GetResult(){return m_Result;}

protected:

private:
	int m_Result;
};
