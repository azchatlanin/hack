#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <tuple>

namespace hack::string
{
  template <typename... Strings>
  class string_concat_helper;

  template <typename String, typename... Strings>
  class string_concat_helper<String, Strings...> 
  {
    using string_part = string_concat_helper<Strings...>;
    using string_long = string_concat_helper<std::string, String, Strings...>;

    private:
      const String& data;
      string_part tail;
    
    public:
      string_concat_helper(const String& data_, string_part tail_) : data { data_ } , tail { tail_ } {}

      int size() const
      {
        return data.size() + tail.size();
      }

      template <typename It>
      void save(It end) const
      {
        const auto begin = end - data.size();
        std::copy(data.cbegin(), data.cend(), begin);
        tail.save(begin);
      }

      operator std::string() const
      {
        std::string result(size(), '\0');
        save(result.end());
        return result;
      }

      string_long operator+(const std::string& other) const
      {
        return string_long(other, *this);
      }
  };

  template <>
  class string_concat_helper<> 
  {
    using string_part = string_concat_helper<std::string>;

    public:
      int size() const
      {
        return 0;
      }

      template <typename It>
      void save(It) const { }

      string_part operator+(const std::string& other) const
      {
        return string_part(other, *this);
      }
  };

  template <typename Stream, typename... Strings>
  Stream& operator<<(Stream& stream, const string_concat_helper<Strings...> strings)
  {
    return stream << static_cast<std::string>(strings);
  }

  inline string_concat_helper<> str_concat;
}
