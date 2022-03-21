#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

namespace hack::concepts
{
  template<typename T>
  concept is_sequence_container = std::same_as<T, std::vector<typename T::value_type>> || 
    std::same_as<T, std::list<typename T::value_type>>;

  template<typename T>
  concept is_tuple = requires (T t)
  { 
    std::tuple_cat(t, std::make_tuple(1, "tuple"));
  };

  template<class T>
  concept is_string = std::is_convertible_v<T, std::string_view>;

  template<class T>
  concept is_map = std::same_as<T, std::map<typename T::key_type, typename T::mapped_type, typename T::key_compare, typename T::allocator_type>> ||
    std::same_as<T, std::unordered_map<typename T::key_type, typename T::mapped_type, typename T::hasher, typename T::key_equal, typename T::allocator_type>>;
}
