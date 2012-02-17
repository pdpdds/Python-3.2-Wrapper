#pragma once
#include <string>
#include <map>
#include "Python.h"

using namespace std;

class PythonModule
{
public:
	PythonModule( std::string ModuleName );
	virtual ~PythonModule(void);

	BOOL AddModuleDef(char* szModuleName);
	virtual BOOL AddMethodDef() = 0;
	virtual BOOL Initialize() = 0;

	std::string& GetModuleName(){return m_ModuleName;}

	PyModuleDef* GetModuleDef(){return m_pModuleDef;}
	PyMethodDef* m_pMethodDef;
	PyModuleDef* m_pModuleDef;

protected:

private:
		
	std::string m_ModuleName;
};
