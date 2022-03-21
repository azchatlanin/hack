#pragma once

namespace hack::range
{
  template<typename T, typename... Args>
  bool within(const T min, const T max, Args... args)
  {
    // 1, 5, 2, 3, 4
    // ( (1 <= 2 && 5 >= 2) && (1 <= 3 && 5 >= 3) && (1 <= 4 && 5 >= 4) )
    return ((min <= args && max >= args) && ...);
  }
}
