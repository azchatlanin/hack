#pragma once

#include <iostream>

namespace hack::iterators
{
  template<typename T>
  class sequence_ostream_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void>
  {
    using traits = std::char_traits<char>;
    using ostream_type = std::basic_ostream<char, traits>;

    private:
      std::basic_ostream<char, traits>* os;
      const std::string devider = ", ";
      std::size_t size;

    public:
      sequence_ostream_iterator(std::size_t size, ostream_type& s) : os { &s }, size { size } { }

      auto& operator=(T const& item)
      {
        --size;
        *os << item << (size != 0 ? devider : "");
        return *this;
      }

      auto& operator*()
      {
        return *this;
      }

      auto& operator++()
      {
        return *this;
      }
  };
}
