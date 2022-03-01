#pragma once

#include <string>
#include <vector>

namespace hack
{
  using v_str = std::vector<std::string>;

  v_str split_str(const std::string& str, char t);
}
