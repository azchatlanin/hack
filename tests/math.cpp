#include <gtest/gtest.h>

#include "math/matrix.hpp"

TEST(matrix, check)
{
  hack::matrix<int, 2> m { { 0, 0, 1 }, { 0, 1, 1 } };
  m[1][1] = 123;

  ASSERT_EQ(m.size(), 3);
}
