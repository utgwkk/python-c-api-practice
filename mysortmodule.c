#include <Python.h>

static PyObject* bubblesort (PyObject* self, PyObject* list) {
  Py_ssize_t i, j, n;
  PyObject *a, *b;
  int cmp;

  Py_INCREF(list);

  n = PyObject_Size(list);

  if (n < 0)
    return NULL;

  for (i = 1; i < n; ++i) for (j = 2; j < n - i + 1; ++j) {
    a = PyList_GetItem(list, j);
    Py_INCREF(a);
    b = PyList_GetItem(list, j - 1);
    Py_INCREF(b);

    cmp = PyObject_RichCompareBool(a, b, Py_LT);

    if (cmp == -1) {
      Py_DECREF(a);
      Py_DECREF(b);
      return NULL;
    }

    if (cmp == 1) {
      PyList_SetItem(list, j, b);
      PyList_SetItem(list, j - 1, a);
    }
  }

  return list;
}

static PyMethodDef MySortMethods[] = {
  {"bubblesort", (PyCFunction)bubblesort, METH_O, "Apply bubble sort to given list."},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef mysortmodule = {
  PyModuleDef_HEAD_INIT,
  "mysort",
  NULL,
  -1,
  MySortMethods
};

PyMODINIT_FUNC PyInit_mysort (void) {
  return PyModule_Create(&mysortmodule);
}
