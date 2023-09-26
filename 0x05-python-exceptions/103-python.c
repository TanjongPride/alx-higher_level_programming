#!/usr/bin/python3
#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - Prints information about Python lists
 * @p: PyObject pointer to a Python object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t i, size;
	PyObject *item;

	size = PyList_Size(p);
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; i++)
	{
		item = PyList_GetItem(p, i);
		printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
	}
}

/**
 * print_python_bytes - Prints information about Python bytes
 * @p: PyObject pointer to a Python object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	char *str;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		fflush(stdout);
		return;
	}

	size = PyBytes_Size(p);
	str = PyBytes_AsString(p);

	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", str);

	printf("  first %ld bytes: ", (size + 1 < 10) ? size + 1 : 10);
	for (i = 0; i < size + 1 && i < 10; i++)
		printf("%02x%c", str[i] & 0xff, (i == size || i == 9) ? '\n' : ' ');
	fflush(stdout);
}

/**
 * print_python_float - Prints information about Python float objects
 * @p: PyObject pointer to a Python object
 */
void print_python_float(PyObject *p)
{
	PyObject *repr;

	printf("[.] float object info\n");
	if (!PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		fflush(stdout);
		return;
	}

	repr = PyObject_Repr(p);
	printf("  value: %s\n", PyUnicode_AsUTF8(repr));
	fflush(stdout);
	Py_DECREF(repr);
}
