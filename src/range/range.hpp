#pragma once

#include <string>
#include <vector>

namespace hack
{
  template<typename T, typename... Args>
  bool within(T min, T max, Args... args)
  {
    return ((min <= args && max >= args) && ...);
    // 1, 5, 2, 3, 4
    // ( (1 <= 2 && 5 >= 2) && (1 <= 3 && 5 >= 3) && (1 <= 4 && 5 >= 4) )
  }
}
