#pragma once
#include <string>
#include "PythonResult.h"

class PythonResultUnicode : public PythonResult
{
public:
	PythonResultUnicode(void);
	virtual ~PythonResultUnicode(void);

	virtual BOOL SetResult(PyObject* pObject) override;
	std::wstring& GetResult(){return m_Result;}

protected:

private:
	std::wstring m_Result;
};
