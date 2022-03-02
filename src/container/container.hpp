#pragma once

#include <vector>

namespace hack::container
{
  template<typename Range, typename... Args>
  void v_multiset(Range& r, Args... args)
  {
    std::size_t t = sizeof... (args);
    r.reserve(t);
    (r.emplace_back(std::forward<Args>(args)), ...);
  }
}
