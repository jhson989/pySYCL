#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <CL/sycl.hpp>
namespace sycl=cl::sycl;

#include <core.hpp>
#include <types.hpp>

namespace pysycl {

int* malloc_device(int num_data, pysycl::queue* queue_p);
void free_device(int* data_p, pysycl::queue* queue_p);

}