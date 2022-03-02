#include <iostream>

#include "string/string.hpp"
#include "range/range.hpp"

int main(int argc, char *argv[])
{
  {// ex: split_str
    std::string str { "asdf,qwer,zxcv" };
    hack::v_str v = hack::split_str(str, ',');
    for (const auto& c : v) std::cout << c << std::endl;
  }

  {// ex: within
    std::cout << hack::within(12, 34, 12, 23, 31) << std::endl;
  }
}
