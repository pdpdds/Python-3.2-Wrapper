#pragma once
#include <vector>
#include "PythonResult.h"

class PythonResultList : public PythonResult
{
	typedef std::vector<std::string> vecString;
public:
	PythonResultList(void);
	virtual ~PythonResultList(void);

	virtual BOOL SetResult(PyObject* pObject) override;

	void PythonResultList::make_list_from_tuple(PyObject* tuple);
	void PythonResultList::make_list_from_list(PyObject* list);

protected:

private:
	 vecString m_vecString;
};
