#include "logger.hpp"

namespace hack
{
  std::string log::devider = " ";
  int log::count = 0;

  log::log(const std::string devider, std::experimental::source_location location) : location { location }
  {
    this->devider = devider;
  }

  warn::warn(const std::string devider, std::experimental::source_location location) : location { location }
  {
   this->devider = devider;
  }

  error::error(const std::string devider, std::experimental::source_location location) : location { location }
  {
   this->devider = devider;
  }

  void log::print() { std::cout << std::endl; }
}
