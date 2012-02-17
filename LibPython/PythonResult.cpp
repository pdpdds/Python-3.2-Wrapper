#include "StdAfx.h"
#include "PythonResult.h"


/*void 
make_list_from_tuple(PyObject* tuple, pyembed::String_list& out)
{
	if (tuple)
	{
		int size = PyTuple_Size(tuple);
		for (int i=0; i<size; i++)
		{
			PyObject* val = PyTuple_GetItem(tuple, i);
			out.push_back(to_string(val));
		}
	}
}

void 
make_list_from_list(PyObject* list, pyembed::String_list& out)
{
	if (list)
	{
		int size = PyList_Size(list);
		for (int i=0; i<size; i++)
		{
			PyObject* val = PyList_GetItem(list, i);
			out.push_back(to_string(val));
		}
	}
}

void 
make_map_from_dict(PyObject* dict, pyembed::String_map& out)
{
	if (dict)
	{
		PyObject* key;
		PyObject* value;
		int pos = 0;
		while (PyDict_Next(dict, &pos, &key, &value)) 
			out[to_string(key)] = to_string(value);
	}
}

std::string 
to_string(PyObject* val)
{
	if (val)
	{
		std::ostringstream oss;
		if (PyInt_Check(val))
			oss << PyInt_AsLong(val);
		else if (PyLong_Check(val))
			oss << PyLong_AsLong(val);
		else if (PyFloat_Check(val))
			oss << PyFloat_AsDouble(val);
		else if (PyString_Check(val))
			oss << '\"' << PyString_AsString(val) << '\"';
		else if (PyTuple_Check(val))
		{
			oss << '(';
			pyembed::String_list ret;
			make_list_from_tuple(val, ret);
			size_t sz = ret.size();
			for (size_t i=0; i<sz; i++)
			{
				oss << ret[i];
				if (i != (sz - 1))
					oss << ',';
			}
			oss << ')';
		}
		else if (PyList_Check(val))
		{
			oss << '[';
			pyembed::String_list ret;
			make_list_from_list(val, ret);
			size_t sz = ret.size();
			for (size_t i=0; i<sz; i++)
			{
				oss << ret[i];
				if (i != (sz - 1))
					oss << ',';
			}
			oss << ']';
		}
		else if (PyDict_Check(val))
		{
			oss << '{';
			pyembed::String_map ret;
			make_map_from_dict(val, ret);
			size_t sz = ret.size();
			size_t i = 0;
			pyembed::String_map::const_iterator it;
			for (it=ret.begin(); it != ret.end(); it++)
			{
				oss << it->first << ':' << it->second;
				if (i != (sz - 1))
					oss << ',';
				i++;
			}
			oss << '}';
		}
		else
			return "";
		return oss.str();
	}
	else
		return "";
}
*/