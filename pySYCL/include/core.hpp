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

        /* getter */
        sycl::device& get_device() {return sycl_device_;}

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
        queue(pysycl::device* device_p);
        queue (const queue& q) = delete;
        queue& operator=(const queue& q) = delete;

        /* Destructor */
        ~queue();

        /* Getter */
        sycl::queue& get_queue(){return sycl_queue_;}
};


}


