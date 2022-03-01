#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "string/string.hpp"


TEST(split_str, check)
{
  hack::v_str v { "asdf", "qwer", "zxcv" };

  ASSERT_EQ(hack::split_str("asdf,qwer,zxcv", ','), v);
}
