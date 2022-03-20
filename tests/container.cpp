#include <gtest/gtest.h>

#include "container/container.hpp"

TEST(v_multiset, check)
{
  std::vector<int> v;
  hack::container::vector_multiset(v, 1, 2, 3);
  ASSERT_EQ(v.at(0), 1);
}
