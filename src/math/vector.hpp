#pragma once

#include <tuple>
#include <math.h>

namespace hack 
{
  template<typename T, typename... Args>
  struct generate_tuple 
  {
    using type = decltype(std::tuple_cat(std::make_tuple(T{}), typename generate_tuple<Args...>::type{}));
  };
  
  template<typename T>
  struct generate_tuple<T> 
  {
    using type = std::tuple<T>;
  };
}

namespace hack
{
  template<typename... Args>
  class vector 
  {
    using value_t = decltype(typename generate_tuple<Args...>::type{});

    public:
      vector(Args... args) : value_ { args... } {}
      vector& operator=(const vector& v)
      {
        if (this == &v) return *this;
        value_ = v.value_;
        return *this;
      }

    public:
      value_t get_value() { return value_; };

      auto get(std::size_t index)
      {
        return std::get<index>(value_);
      }

      auto length()
      {
        return std::sqrt(length_idx(std::make_index_sequence<std::tuple_size<value_t>::value>{}));
      }

      /*
        dest.x = a.x + ((b.x - a.x) * t);
        dest.y = a.y + ((b.y - a.y) * t);
      */
      value_t lerp(vector<Args...>& v, float t)
      {
        return lerp_idx(v.get_value(), t, std::make_index_sequence<std::tuple_size<value_t>::value>{});
      }
      
    private: 
      template<typename std::size_t... idx>
      auto length_idx(std::index_sequence<idx...>)
      {
        return ((std::get<idx>(value_) * std::get<idx>(value_)) + ...);
      }

      template<typename std::size_t... idx>
      auto lerp_idx(const value_t& v, float t, std::index_sequence<idx...>)
      {
        return std::make_tuple((std::get<idx>(value_) + (std::get<idx>(v) - std::get<idx>(value_)) * t)...);
      }

    private:
      value_t value_;
  };
}