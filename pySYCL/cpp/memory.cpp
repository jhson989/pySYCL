#include <memory.hpp>

int* pysycl::malloc_device(int num_data, pysycl::queue* queue_p) {

    sycl::queue sycl_queue = queue_p->get_queue();
    return sycl::malloc_device<int>(num_data, sycl_queue);

}


void pysycl::free_device(int* data_p, pysycl::queue* queue_p) {

    sycl::queue sycl_queue = queue_p->get_queue();
    sycl::free (data_p, sycl_queue);
    
}