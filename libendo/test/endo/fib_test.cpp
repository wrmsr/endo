#include <gtest/gtest.h>

#include "endo/fib.hpp"

TEST(test_fibs, test_fib) {
  ASSERT_EQ(fib(6), 8);
}
