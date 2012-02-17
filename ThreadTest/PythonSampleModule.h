#pragma once
#include "PythonModule.h"
#include <iostream>
#include <fstream>

using namespace std;

class PythonSampleModule : public PythonModule
{
public:
	PythonSampleModule(std::string ModuleName);
	virtual ~PythonSampleModule(void);

	virtual BOOL AddMethodDef() override;
	BOOL Initialize() override;


	static PyObject* myCppFunction( PyObject* self, PyObject* args );
	static PyObject* SetCallback( PyObject* self, PyObject* args );

	static PyObject *fPythonCallback;

protected:

private:
};
