#include <Python.h>

static PyObject* bubblesort (PyObject* self, PyObject* args) {
  Py_ssize_t i, j, n;
  PyObject *a, *b, *list;
  PyObject *seq;
  int cmp;

  if (!PyArg_ParseTuple(args, "O", &seq))
    return NULL;

  Py_INCREF(seq);
  list = PySequence_List(seq);
  Py_DECREF(seq);

  n = PyObject_Size(list);

  if (n < 0)
    return NULL;

  for (i = 1; i < n; ++i) for (j = 1; j < n - i + 1; ++j) {
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
    } else {
      Py_DECREF(a);
      Py_DECREF(b);
    }
  }

  return list;
}

static PyMethodDef MySortMethods[] = {
  {"bubblesort", (PyCFunction)bubblesort, METH_VARARGS, "Apply bubble sort to given list."},
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
