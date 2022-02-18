# distutils: language = c++
# cython: language_level=3

cdef extern from "core.hpp" namespace "pysycl":
    # Device
    cdef cppclass device:
        device(DEVICE_TYPE)
    # Queue
    cdef cppclass queue:
        queue(DEVICE_TYPE) 

   
cdef class Device:
    cdef device* c_device_p

    def __init__(self, device_type):

        if device_type.lower() == "gpu" :
            self.c_device_p = new device(DEVICE_TYPE_GPU)
        else :
            print("Unsupported device type : " + device_type)


    def __del__(self):
        del self.device


cdef class Queue:
    cdef device* c_device_p
    cdef queue* c_queue_p
    
    def __init__(self, device):
        print(device)
        pass
        #self.c_device_p = device.c_device_p
        #self.c_queue_p = new queue(self.c_device_p)

    def __del__(self):
        pass
        #del self c_queue_p