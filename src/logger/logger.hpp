#pragma once

#include <iostream>
#include <experimental/source_location>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

#include "view/color.hpp"
#include "iterators/sequence_ostream_iterator.hpp"
#include "iterators/associative_ostream_iterator.hpp"

namespace hack
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

  class log
  {
    public:
      log(const std::string devider = ", ", std::experimental::source_location location = std::experimental::source_location::current()); 
      log(log&) = delete;
      log(log&&) = delete;

    public:
      template<typename... Args>
      void operator() (const Args&... args)
      {
        std::cout << make_type_view
                  << location.file_name() << ":" << view::color::reset 
                  << view::color::italic << view::color::yellow << location.function_name() << "()" << view::color::reset
                  << view::color::bold << view::color::blue << "[" << location.line() << "]" << view::color::reset << ": ";
        count = sizeof...(Args);
        print(args...);
      }

    private:
      std::experimental::source_location location;
      static int count;
      static std::string devider;

    private:
      static void print();

      static std::ostream& make_type_view(std::ostream &os)
      {
        os << view::color::bold << view::color::green << "[ok]" << view::color::reset << view::color::green;
        return os;
      }

      template<typename T, typename... Args>
      static void print(const T& data, const Args&... args)
      {
        count--;
        print_t(data);
        print(args...);
      }

      template<is_string T>
      static void print_t(const T& data)
      {
        std::cout << data << (count != 0 ? devider : "");
      }

      template<std::integral T>
      static void print_t(const T& data)
      {
        std::cout << data << (count != 0 ? devider : "");
      }

      template<is_sequence_container T>
      static void print_t(const T& data)
      {
        std::cout << "{ ";
        std::copy(data.cbegin(), data.cend(), iterators::sequence_ostream_iterator<typename T::value_type>(data.size(), std::cout));
        std::cout << " }" << (count != 0 ? devider : "");
      }

      template<is_map T>
      static void print_t(const T& data)
      {
        std::cout << "{";
        std::copy(data.cbegin(), data.cend(), iterators::associative_ostream_iterator<typename T::value_type>(data.size(), std::cout));
        std::cout << "}" << (count != 0 ? devider : "");
      }

      template<is_tuple T, typename std::size_t... idx>
      static void print_t(const T& data)
      {
        print_t(data, std::make_index_sequence<std::tuple_size<T>::value>{});
      }

      template<typename T, typename std::size_t... idx>
      static void print_t(const T& data, std::index_sequence<idx...>)
      {
        std::cout << "{ ";
        ((std::cout << std::get<idx>(data) << (idx != std::tuple_size<T>::value - 1 ? devider : "")), ...);
        std::cout << " }" << (count != 0 ? devider : "");
      }

      friend class warn;
      friend class error;
  };

  class warn : public log
  {
    public:
      warn(const std::string devider = ", ", std::experimental::source_location location = std::experimental::source_location::current()); 
      warn(log&) = delete;
      warn(log&&) = delete;

    public:
      template<typename... Args>
      void operator() (const Args&... args)
      {
        std::cout << make_type_view
                  << location.file_name() << ":" << view::color::reset 
                  << view::color::italic << view::color::yellow << location.function_name() << "()" << view::color::reset
                  << view::color::bold << view::color::blue << "[" << location.line() << "]" << view::color::reset << ": ";
        count = sizeof...(Args);
        print(args...);
      }

    private:
      std::experimental::source_location location;

    private:
      static std::ostream& make_type_view(std::ostream &os)
      {
        os << view::color::bold << view::color::yellow << "[WARN]" << view::color::reset << view::color::yellow;
        return os;
      }
  };

  class error : public log
  {
    public:
      error(const std::string devider = ", ", std::experimental::source_location location = std::experimental::source_location::current()); 
      error(log&) = delete;
      error(log&&) = delete;

    public:
      template<typename... Args>
      void operator() (const Args&... args)
      {
        std::cout << make_type_view
                  << location.file_name() << ":" << view::color::reset 
                  << view::color::italic << view::color::yellow << location.function_name() << "()" << view::color::reset
                  << view::color::bold << view::color::blue << "[" << location.line() << "]" << view::color::reset << ": ";
        count = sizeof...(Args);
        print(args...);
      }

    private:
      std::experimental::source_location location;

    private:
      static std::ostream& make_type_view(std::ostream &os)
      {
        os << view::color::bold <<  view::color::red << "[ERROR]" << view::color::reset << view::color::red;
        return os;
      }
  };
}