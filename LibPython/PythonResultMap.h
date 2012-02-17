#pragma once
#include "PythonResult.h"

class PythonResultMap : public PythonResult
{
public:
	PythonResultMap(void);
	virtual ~PythonResultMap(void);

	virtual BOOL SetResult(PyObject* pObject) override;

protected:

private:
};
