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

}
pysycl::queue::queue(pysycl::device device) 
        : device_(device) {

}

/* Destructor */
pysycl::queue::~queue() {
    
}








/* ******************************************************************
 * Test code
 * ******************************************************************/


void print_sycl() {
    std::cout << "Hello sycl" << std::endl;
}


void print_properties_host() {
    
    sycl::host_selector host;
    sycl::queue host_q(host);

    sycl::device dev = host_q.get_device();
    std::cout << "=============== Device Properties ==============" << std::endl;
    std::cout << "Name: " << dev.get_info<sycl::info::device::name>() << std::endl;
    std::cout << "Vendor: " << dev.get_info<sycl::info::device::vendor>() << std::endl;
    std::cout << "Memory size: " << dev.get_info<sycl::info::device::global_mem_size>()/1024.0f/1024.0f/1024.0f << " GB"  << std::endl;
    std::cout << "================================================" << std::endl << std::endl;
    
}

