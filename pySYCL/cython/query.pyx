
cdef extern from "query.hpp" namespace "pysycl":
    void print_sycl()
    void print_properties_host()
    void print_properties_cpu()
    void print_properties_gpu()
    void print_properties(queue* queue)


def printProperties(Queue queue):
    print_properties(queue.c_queue_)