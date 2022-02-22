#include <core.hpp>




/* ******************************************************************
 * Device
 * ******************************************************************/

/* Constructor */
pysycl::device::device(pysycl::DEVICE_TYPE device_t) {

    if (device_t == DEVICE_TYPE_GPU) {
        device_t_ = DEVICE_TYPE_GPU;
        sycl_device_ = sycl::device(sycl::gpu_selector());
    } else {
        std::cout << "[[[ERR]]] Unsupported device type: " << device_t << std::endl;
        std::exit(1);
    }

}

/* Destructor */
pysycl::device::~device() {

}



/* ******************************************************************
 * Queue
 * ******************************************************************/


/* Constructor */
pysycl::queue::queue(pysycl::DEVICE_TYPE device_t) 
        : device_(pysycl::device(device_t)) {
    sycl_queue_ = sycl::queue(device_.get_device());
    printf("1\n");
}
pysycl::queue::queue(pysycl::device device) 
        : device_(device) {
    sycl_queue_ = sycl::queue(device_.get_device());
    printf("2\n");
}

pysycl::queue::queue(pysycl::device* device_p) 
        : device_(*device_p) {
    if (device_p == nullptr)
        printf("device null???????????\n");
    sycl_queue_ = sycl::queue(device_.get_device());
}

/* Destructor */
pysycl::queue::~queue() {
    
}








