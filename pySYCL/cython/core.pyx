# distutils: language = c++
# cython: language_level=3
STUFF = "Hi"

cdef extern from "core.hpp" namespace "pysycl":
    # Device
    cdef cppclass device:
        device(DEVICE_TYPE) except +
    # Queue
    cdef cppclass queue:
        queue(DEVICE_TYPE) except +
        queue(device* d) except +

   
cdef class Device:
    cdef device* c_device

    def __cinit__(self, device_type):

        if device_type.lower() == "gpu" :
            self.c_device = new device(DEVICE_TYPE_GPU)
        else :
            print("Unsupported device type : " + device_type)

    def __dealloc__(self):
        del self.c_device


cdef class Queue:
    cdef device* c_device
    cdef queue* c_queue
    
    def __cinit__(self, device_type):

        if device_type.lower() == "gpu" :
            self.c_device = new device(DEVICE_TYPE_GPU)
        else :
            print("Unsupported device type : " + device_type)
            return
        self.c_queue = new queue(self.c_device)


    def __cinit__(self, Device device):
        self.c_device = device.c_device
        self.c_queue = new queue(self.c_device)
        

    def __dealloc__(self):
        del self.c_queue
        

