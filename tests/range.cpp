#include <gtest/gtest.h>

#include "range/range.hpp"

TEST(within, check)
{
  ASSERT_EQ(hack::range::within(23, 123, 34, 44, 55, 66), true);
  ASSERT_EQ(hack::range::within(23, 123, 134, 44, 55, 66), false);
}
