#pragma once

#include <iostream>

namespace hack::iterators
{
  template<typename T>
  class associative_ostream_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void>
  {
    using traits = std::char_traits<char>;
    using ostream_type = std::basic_ostream<char, traits>;

    private:
      std::basic_ostream<char, traits>* os_;
      const std::string devider_ = ", ";
      std::size_t size_;

    public:
      associative_ostream_iterator(std::size_t size, ostream_type& os) : os_ { &os }, size_ { size } { }

      auto& operator=(T const& item)
      {
        --size_;
        const auto& [key, value] = item;
        *os_ << "{ " << key << ":" << value << " }" << (size_ != 0 ? devider_ : "");
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
