#include <gtest/gtest.h>
#include "shared_ptr.hpp"

using mini_stl::shared_ptr;

#include "shared_ptr_copy_constructor.hpp"

TEST(test, shared_ptr_copy_constructor)
{
    shared_ptr_copy_constructor();
}

