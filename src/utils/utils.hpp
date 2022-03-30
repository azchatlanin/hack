#pragma once

#include <map>
#include <functional>

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

  template<typename T, typename... Args>
  auto func_concat(T t, Args... args)
  {
    if constexpr (sizeof...(args) > 0)
    {
      return [=](auto... params)
      {
        return t(func_concat(args...)(params...));
      };
    }
    else
    {
      return [=](auto... params)
      {
        return t(params...);
      };
    }
  }
}
