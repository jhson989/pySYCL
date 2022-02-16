from distutils.core import Extension, setup
from Cython.Build import cythonize

import pathlib

###########################

core = Extension(
    name="core",
    sources=[
        "pySYCL/core/cython/core.pyx",
    ],
)

extensions = [
    core
]


setup(
    name="pySYCL",
    version="0.1",
    author="Janghyun Son",
    author_email="jhson989@gmail.com",
    ext_modules=cythonize(extensions),
    python_requires='>=3.7'
)
