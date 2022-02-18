#include <query.hpp>

void pysycl::print_sycl() {
    std::cout << "Hello sycl" << std::endl;
}


void pysycl::print_properties_host() {
    
    sycl::host_selector host;
    sycl::queue host_q(host);

    sycl::device dev = host_q.get_device();
    std::cout << "=============== Device Properties ==============" << std::endl;
    std::cout << "Name: " << dev.get_info<sycl::info::device::name>() << std::endl;
    std::cout << "Vendor: " << dev.get_info<sycl::info::device::vendor>() << std::endl;
    std::cout << "Memory size: " << dev.get_info<sycl::info::device::global_mem_size>()/1024.0f/1024.0f/1024.0f << " GB"  << std::endl;
    std::cout << "================================================" << std::endl << std::endl;
    
}


void pysycl::print_properties_cpu() {
    
    sycl::cpu_selector cpu;
    sycl::queue cpu_q(cpu);

    sycl::device dev = cpu_q.get_device();
    std::cout << "=============== Device Properties ==============" << std::endl;
    std::cout << "Name: " << dev.get_info<sycl::info::device::name>() << std::endl;
    std::cout << "Vendor: " << dev.get_info<sycl::info::device::vendor>() << std::endl;
    std::cout << "Memory size: " << dev.get_info<sycl::info::device::global_mem_size>()/1024.0f/1024.0f/1024.0f << " GB"  << std::endl;
    std::cout << "================================================" << std::endl << std::endl;
    
}

void pysycl::print_properties_gpu() {

    sycl::gpu_selector gpu;
    sycl::queue gpu_q(gpu);
        
    sycl::device dev = gpu_q.get_device();
    std::cout << "=============== Device Properties ==============" << std::endl;
    std::cout << "Name: " << dev.get_info<sycl::info::device::name>() << std::endl;
    std::cout << "Vendor: " << dev.get_info<sycl::info::device::vendor>() << std::endl;
    std::cout << "Memory size: " << dev.get_info<sycl::info::device::global_mem_size>()/1024.0f/1024.0f/1024.0f << " GB" << std::endl;
    std::cout << "================================================" << std::endl << std::endl;

}

void pysycl::print_properties(pysycl::queue* queue_p) {

    if (queue_p == nullptr)
        printf("???????????????\n");

    sycl::queue sycl_queue = queue_p->get_queue();
    sycl::device sycl_dev = sycl_queue.get_device();

    std::cout << "=============== Device Properties ==============" << std::endl;
    std::cout << "Name: " << sycl_dev.get_info<sycl::info::device::name>() << std::endl;
    std::cout << "Vendor: " << sycl_dev.get_info<sycl::info::device::vendor>() << std::endl;
    std::cout << "Memory size: " << sycl_dev.get_info<sycl::info::device::global_mem_size>()/1024.0f/1024.0f/1024.0f << " GB"  << std::endl;
    std::cout << "================================================" << std::endl << std::endl;
}
