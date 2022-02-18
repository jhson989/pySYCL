#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <CL/sycl.hpp>
namespace sycl=cl::sycl;


#include <types.hpp>


/* ******************************************************************
 * Device
 * ******************************************************************/

namespace pysycl {

class device {
    private:
        pysycl::DEVICE_TYPE device_t_;
        sycl::device sycl_device_;
    public:
        /* Constructor */
        device(pysycl::DEVICE_TYPE device_t);
        device& operator=(const device& d) = delete;
        
        /* Destructor */
        ~device();

};

/* ******************************************************************
 * Queue
 * ******************************************************************/

class queue {
    private:
        sycl::queue sycl_queue_;
        pysycl::device device_;
    public:
        /* Constructor */
        queue(pysycl::DEVICE_TYPE device_t);
        queue(pysycl::device device);
        queue (const queue& q) = delete;
        queue& operator=(const queue& q) = delete;

        /* Destructor */
        ~queue();
};


}














/* ******************************************************************
 * Test code
 * ******************************************************************/


void print_sycl();
void print_properties_host();