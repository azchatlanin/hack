#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "string/string.hpp"


TEST(split_str, check)
{
  std::vector<std::string> v { "asdf", "qwer", "zxcv" };
  ASSERT_EQ(hack::string::split_str("asdf,qwer,zxcv", ','), v);
}
