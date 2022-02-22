#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <CL/sycl.hpp>
namespace sycl=cl::sycl;

#include <core.hpp>
#include <types.hpp>

namespace pysycl {

template <typename T> T* malloc_device(size_t num_data, pysycl::queue* queue_p){
    sycl::queue sycl_queue = queue_p->get_queue();
    return sycl::malloc_device<T>(num_data, sycl_queue);
}

template <typename T> void free_device(T* data_p, pysycl::queue* queue_p){
    sycl::queue sycl_queue = queue_p->get_queue();
    sycl::free (data_p, sycl_queue);
}


}


