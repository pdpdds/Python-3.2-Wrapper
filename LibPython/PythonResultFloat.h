#pragma once
#include "PythonResult.h"

class PythonResultFloat : public PythonResult
{
public:
	PythonResultFloat(void);
	virtual ~PythonResultFloat(void);

	virtual BOOL SetResult(PyObject* pObject) override;

protected:

private:
	float m_Result;
};
