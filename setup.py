from setuptools import setup, Extension

module = Extension(
    'mysort',
    sources=['mysortmodule.c']
)

setup(
    name='mysort',
    version='1.0',
    description='C API practice',
    ext_modules=[module]
)
