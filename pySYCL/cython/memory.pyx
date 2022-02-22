# distutils: language = c++
# cython: language_level=3

import numpy as np

cdef extern from "memory.hpp" namespace "pysycl":
    cdef int* malloc_device(int num_data, queue* queue)
    cdef void free_device(int* data_p, queue* queue)

cdef class MemObj:
    cdef int* c_data_

    def __cinit__(self, num_data, Queue queue):
        self.c_data_ = malloc_device(num_data, queue.c_queue_)
    
    def free(self, Queue queue):
        free_device(self.c_data_, queue.c_queue_)

def mallocDevice(num_data, Queue queue):
    return MemObj(num_data, queue)

def free(MemObj mem, Queue queue):
    mem.free(queue)