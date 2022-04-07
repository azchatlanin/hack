#include "logger.hpp"

namespace hack
{
  std::string log::devider = " ";
  int log::count = 0;

  log::log(std::string devider_, std::experimental::source_location location_) : location { location_ }
  {
    this->devider = devider_;
  }

  warn::warn(std::string devider_, std::experimental::source_location location_) : location { location_ }
  {
    this->devider = devider_;
  }

  error::error(std::string devider_, std::experimental::source_location location_) : location { location_ }
  {
    this->devider = devider_;
  }

  void log::print() { std::cout << std::endl; }
}
