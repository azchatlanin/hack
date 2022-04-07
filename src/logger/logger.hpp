#pragma once

#include <experimental/source_location>

#include "boost/type_index.hpp"

#include "view/color.hpp"
#include "concepts/concepts.hpp"
#include "iterators/sequence_ostream_iterator.hpp"
#include "iterators/associative_ostream_iterator.hpp"
#include "math/matrix.hpp"

namespace hack
{
  template<typename T, typename U>
  void prepare(T t, U u)
  {
    std::cout << t
              << u.file_name() << ":" << view::color::reset 
              << view::color::italic << view::color::yellow << u.function_name() << "()" << view::color::reset
              << view::color::bold << view::color::blue << "[" << u.line() << "]" << view::color::reset << ": ";
  }

  class log
  {
    public:
      log(std::string devider_ = ", ", std::experimental::source_location location_ = std::experimental::source_location::current()); 
      log(log&) = delete;
      log(log&&) = delete;

    public:
      template<typename... Args>
      void operator() (const Args&... args)
      {
        count = sizeof...(Args);
        prepare(make_type_view, location);
        print(args...);
      }

      template<typename... Args>
      static void type_trace(const Args&... args)
      {
        std::cout << make_type_view << ": " << view::color::reset;
        count = sizeof...(Args);
        print(boost::typeindex::type_id<Args>().pretty_name()...);
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

      template<concepts::is_string T>
      static void print_t(const T& data)
      {
        std::cout << data << (count != 0 ? devider : "");
      }

      template<std::integral T>
      static void print_t(const T& data)
      {
        std::cout << data << (count != 0 ? devider : "");
      }

      template<concepts::is_sequence_container T>
      static void print_t(const T& data)
      {
        std::cout << "{ ";
        std::copy(data.cbegin(), data.cend(), iterators::sequence_ostream_iterator<typename T::value_type>(data.size(), std::cout));
        std::cout << " }" << (count != 0 ? devider : "");
      }

      template<concepts::is_map T>
      static void print_t(const T& data)
      {
        std::cout << "{";
        std::copy(data.cbegin(), data.cend(), iterators::associative_ostream_iterator<typename T::value_type>(data.size(), std::cout));
        std::cout << "}" << (count != 0 ? devider : "");
      }

      template<concepts::is_tuple T, typename std::size_t... idx>
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

      template<typename T, std::size_t demention>
      static void print_t(const matrix<T, demention>& data)
      {
        std::size_t index = data.size();
        for (auto& r : data)
        {
          index--;
          std::cout << "{ ";
          print_t(std::get<demention>(r));
          std::cout << " }" << (index != 0 ? ", " : "");
        }
      }

      template<concepts::not_defined T>
      static void print_t(const T& data)
      {
        std::cout << data << (count != 0 ? devider : "");
      }

      friend class warn;
      friend class error;
  };

  class warn : public log
  {
    public:
      warn(std::string devider_ = ", ", std::experimental::source_location location_ = std::experimental::source_location::current());
      warn(log&) = delete;
      warn(log&&) = delete;

    public:
      template<typename... Args>
      void operator() (const Args&... args)
      {
        prepare(make_type_view, location);
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
      error(std::string devider_ = ", ", std::experimental::source_location location_ = std::experimental::source_location::current()); 
      error(log&) = delete;
      error(log&&) = delete;

    public:
      template<typename... Args>
      void operator() (const Args&... args)
      {
        prepare(make_type_view, location);
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
