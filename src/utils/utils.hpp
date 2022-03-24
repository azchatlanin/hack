#pragma once

#include <iostream>
#include <unordered_map>

namespace hack::utils
{
  template<typename T, std::size_t N>
  struct generate_tuple 
  {
    using type = decltype(std::tuple_cat(typename generate_tuple<T, N - 1>::type{}, std::make_tuple(T{})));
  };

  template<typename T>
  struct generate_tuple<T, 1> 
  {
    using type = std::tuple<T>;
  };
}
