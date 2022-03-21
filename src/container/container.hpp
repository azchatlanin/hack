#pragma once

#include <algorithm>

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

  template<typename Range, typename... Args>
  int matches(Range r, Args... args)
  {
    return (std::count(std::cbegin(r), std::cend(r), args) + ...);
  }

  // -----------------------------------------------------
  // remove vector element if vector sorting no important
  template<typename T>
  void vector_remove_at(std::vector<T>& v, std::size_t idx)
  {
    if (idx < v.size())
    {
      v[idx] = std::move(v.back());
      v.pop_back();
    }
  }
  
  template<typename T>
  void vector_remove_at(std::vector<T>& v, typename std::vector<T>::iterator it)
  {
    if (it != v.end())
    {
      *it = std::move(v.back());
      v.pop_back();
    }
  }
  // -----------------------------------------------------
}
