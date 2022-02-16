from distutils.core import Extension, setup
from Cython.Build import cythonize

import pathlib

###########################

core = Extension(
    name="pySYCL",
    sources=[
        "pySYCL/pySYCL.pyx",
    ],
    libraries=["coreSYCL"],
    library_dirs=["build/"],
    include_dirs=["pySYCL/include"]
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
