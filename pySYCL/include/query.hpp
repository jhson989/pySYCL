#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
#include <CL/sycl.hpp>
namespace sycl=cl::sycl;


#include <types.hpp>
#include <core.hpp>

namespace pysycl {
    
void print_sycl();
void print_properties_host();
void print_properties_cpu();
void print_properties_gpu();
void print_properties(pysycl::queue* queue_p);


}