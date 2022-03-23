#include "logger.hpp"

namespace hack
{
  std::string log::devider_ = " ";
  int log::count_ = 0;

  log::log(const std::string devider, std::experimental::source_location location) : location_ { location }
  {
    this->devider_ = devider;
  }

  warn::warn(const std::string devider, std::experimental::source_location location) : location_ { location }
  {
   this->devider_ = devider;
  }

  error::error(const std::string devider, std::experimental::source_location location) : location_ { location }
  {
   this->devider_ = devider;
  }

  void log::print() { std::cout << std::endl; }
}
