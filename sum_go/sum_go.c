#include <Python.h>

/* Will come from go */
PyObject* sum(PyObject* , PyObject*);

/* To shim go's missing variadic function support */
int PyArg_ParseTuple_ll(PyObject* args, long* a, long* b) {
    return PyArg_ParseTuple(args, "ll", a, b);
}

static struct PyMethodDef methods[] = {
    {"sum", (PyCFunction)sum, METH_VARARGS},
    {NULL, NULL}
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "sum_go",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit_sum_go(void) {
    return PyModule_Create(&module);
}
#else
PyMODINIT_FUNC initsum_go(void) {
    Py_InitModule3("sum_go", methods, NULL);
}
#endif
