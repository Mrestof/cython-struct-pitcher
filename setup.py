from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize


extensions = [Extension('client_compiled', ['client.pyx', 'client.c'])]

setup(
    ext_modules=cythonize(
        extensions,
        compiler_directives={'language_level':3},
        force=True,
    )
)
