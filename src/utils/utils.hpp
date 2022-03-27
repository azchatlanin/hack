#pragma once

#include <map>

namespace hack::utils
{
  template<typename Result, typename... Args>
  auto func_memory(Result (*f)(Args...))
  {
    std::map<std::tuple<Args...>, Result> cache;

    return [f, cache](Args... args) mutable -> Result
    {
      const auto key = std::make_tuple(args...);
      const auto cached = cache.find(key);

      if(cached == cache.end())
      {
        auto result = f(args...);
        cache[key] = result;
        return result;
      }
      return cached->second;
    };
  }
}


  // std::map<std::tuple<Args...>, Result> cache;
  //
  // return [f, cache](Args... args) mutable -> Result
  // {
  //   const auto args_tuple = std::make_tuple(args...);
  //   const auto cached = cache.find(args_tuple);
  //
  //   if (cached == cache.end()) 
  //   {
  //     auto result = f(args...);
  //     cache[args_tuple] = result;
  //     return result;
  //   } 
  //   else 
  //     return cached->second
