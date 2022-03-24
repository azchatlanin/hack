#pragma once

#include <tuple>

namespace hack 
{
  template<typename T, typename... Args>
  struct generate_tuple 
  {
    using type = decltype(std::tuple_cat(std::make_tuple(T{}), typename generate_tuple<Args...>::type{}));
  };
  
  template<typename T>
  struct generate_tuple<T> 
  {
    using type = std::tuple<T>;
  };
}

namespace hack
{
  template<typename... Args>
  class vector 
  {
    using value_t = decltype(typename generate_tuple<Args...>::type{});

    public:
      vector(Args... args) : value_ { args... } {}

    public:
      value_t get_value() { return value_; };

    private:
      value_t value_;
  };
}
