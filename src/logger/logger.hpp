#pragma once

#include <experimental/source_location>

#include "view/color.hpp"
#include "concepts/concepts.hpp"
#include "iterators/sequence_ostream_iterator.hpp"
#include "iterators/associative_ostream_iterator.hpp"
#include "matrix/matrix.hpp"

namespace hack
{
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
                  << location_.file_name() << ":" << view::color::reset 
                  << view::color::italic << view::color::yellow << location_.function_name() << "()" << view::color::reset
                  << view::color::bold << view::color::blue << "[" << location_.line() << "]" << view::color::reset << ": ";
        count_ = sizeof...(Args);
        print(args...);
      }

    private:
      std::experimental::source_location location_;
      static int count_;
      static std::string devider_;

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
        count_--;
        print_t(data);
        print(args...);
      }

      template<concepts::is_string T>
      static void print_t(const T& data)
      {
        std::cout << data << (count_ != 0 ? devider_ : "");
      }

      template<std::integral T>
      static void print_t(const T& data)
      {
        std::cout << data << (count_ != 0 ? devider_ : "");
      }

      template<concepts::is_sequence_container T>
      static void print_t(const T& data)
      {
        std::cout << "{ ";
        std::copy(data.cbegin(), data.cend(), iterators::sequence_ostream_iterator<typename T::value_type>(data.size(), std::cout));
        std::cout << " }" << (count_ != 0 ? devider_ : "");
      }

      template<concepts::is_map T>
      static void print_t(const T& data)
      {
        std::cout << "{";
        std::copy(data.cbegin(), data.cend(), iterators::associative_ostream_iterator<typename T::value_type>(data.size(), std::cout));
        std::cout << "}" << (count_ != 0 ? devider_ : "");
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
        ((std::cout << std::get<idx>(data) << (idx != std::tuple_size<T>::value - 1 ? devider_ : "")), ...);
        std::cout << " }" << (count_ != 0 ? devider_ : "");
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
        std::cout << data << (count_ != 0 ? devider_ : "");
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
                  << location_.file_name() << ":" << view::color::reset 
                  << view::color::italic << view::color::yellow << location_.function_name() << "()" << view::color::reset
                  << view::color::bold << view::color::blue << "[" << location_.line() << "]" << view::color::reset << ": ";
        count_ = sizeof...(Args);
        print(args...);
      }

    private:
      std::experimental::source_location location_;

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
                  << location_.file_name() << ":" << view::color::reset 
                  << view::color::italic << view::color::yellow << location_.function_name() << "()" << view::color::reset
                  << view::color::bold << view::color::blue << "[" << location_.line() << "]" << view::color::reset << ": ";
        count_ = sizeof...(Args);
        print(args...);
      }

    private:
      std::experimental::source_location location_;

    private:
      static std::ostream& make_type_view(std::ostream &os)
      {
        os << view::color::bold <<  view::color::red << "[ERROR]" << view::color::reset << view::color::red;
        return os;
      }
  };
}
