from distutils.core import Extension, setup
from Cython.Build import cythonize
import os
import pathlib



#############################################################################
# Project Configuration
#############################################################################
PROJECT_NAME = "pySYCL"
PROJECT_VERSION = "0.1"

#############################################################################
# SYCL build configuration
#############################################################################
SYCL_COMPILER = "clang++"
PATH_SYCL_BUILD = "/data/share/oneapi/llvm/build/"
SYCL_LIBRARY = "sycl"
PATH_SYCL_LIBRARY = PATH_SYCL_BUILD + "/lib/"
PATH_SYCL_INCLUDE = [
    PATH_SYCL_BUILD + "/include/",
    PATH_SYCL_BUILD + "/include/sycl/"
]
COMPILE_OPTION_SYCL = [
    "-fsycl",
    "-fsycl-targets=nvptx64-nvidia-cuda"
]

#############################################################################
# C++ Code
#############################################################################
CPP_SOURCES = [
    "pySYCL/cpp/query.cpp",
    "pySYCL/cpp/memory.cpp",
    "pySYCL/cpp/core.cpp",
    
]

#############################################################################
# Cython configuration
#############################################################################
NAME_BASE_CYTHON = "pySYCL/interface.pyx"



#############################################################################
# Cython build script
#############################################################################
pySYCL = Extension(
    name=PROJECT_NAME,
    sources=[
        NAME_BASE_CYTHON,
    ] + CPP_SOURCES,
    libraries=[
        SYCL_LIBRARY
    ],
    library_dirs=[
        PATH_SYCL_LIBRARY
        ],
    include_dirs=[
        "pySYCL/include",
        ] + PATH_SYCL_INCLUDE,
    language="clang++",
    extra_compile_args=[
        "-Wno-deprecated-declarations",
        "-Wno-unused-function"
        ] + COMPILE_OPTION_SYCL
)

os.environ["CC"] = SYCL_COMPILER
setup(
    name=PROJECT_NAME,
    version=PROJECT_VERSION,
    author="Janghyun Son",
    author_email="jhson989@gmail.com",
    ext_modules=cythonize(pySYCL)
)
