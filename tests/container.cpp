#include <gtest/gtest.h>

#include "container/container.hpp"

TEST(vector_multiset, check)
{
  std::vector<int> v;
  hack::container::vector_multiset(v, 1, 2, 3);
  ASSERT_EQ(v.at(0), 1);
}

TEST(matches, check)
{
  std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  ASSERT_EQ(hack::container::matches(v, 2, 5, 4, 12), 3);
}
