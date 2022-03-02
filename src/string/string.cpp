#include "string.hpp"

namespace hack::string
{
  v_str split_str(const std::string& str, char t)
  {
    v_str v;

    std::string::size_type begin = 0;
    std::string::size_type end = str.find_first_of(t);
    
    while(end != std::string::npos)
    {
      v.emplace_back(str.substr(begin, end - begin));
      begin = ++end;
      end = str.find_first_of(t, begin);
    }

    v.emplace_back(str.substr(begin));

    return v;
  }
}
