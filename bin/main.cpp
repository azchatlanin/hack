#include <iostream>

#include "string/string.hpp"

int main(int argc, char *argv[])
{
  std::string str { "asdf,qwer,zxcv" };
  hack::v_str v = hack::split_str(str, ',');

  for (const auto& c : v) std::cout << c << std::endl;
}
