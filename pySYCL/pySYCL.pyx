#cython: language_level=3


cdef extern from "core.hpp":
    void print_sycl()

def test():
    print_sycl()