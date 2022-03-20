#pragma once

#include <vector>
#include <set>

namespace hack::container
{
  template<typename Range, typename... Args>
  void vector_multiset(Range& r, Args... args)
  {
    constexpr std::size_t t = sizeof... (args);
    r.reserve(t);
    (r.emplace_back(std::forward<Args>(args)), ...);
  }

  template<typename Range, typename... Args>
  void set_multiset(Range& r, Args... args)
  {
    (r.insert(args), ...);
  }
}
