#pragma once

#include <iostream>

namespace hack::view::color
{
  template<typename CharT, typename Traits>
  std::basic_ostream<CharT, Traits>& reset(std::basic_ostream<CharT, Traits> &os)
  {
    return os << "\033[0m";
  }

  template<typename CharT, typename Traits>
  std::basic_ostream<CharT, Traits>& bold(std::basic_ostream<CharT, Traits> &os)
  {
    return os << "\033[1m";
  }

  template<typename CharT, typename Traits>
  std::basic_ostream<CharT, Traits>& italic(std::basic_ostream<CharT, Traits> &os)
  {
    return os << "\033[3m";
  }

  template<typename CharT, typename Traits>
  std::basic_ostream<CharT, Traits>& black(std::basic_ostream<CharT, Traits> &os)
  {
    return os << "\033[30m";
  }

  template<typename CharT, typename Traits>
  std::basic_ostream<CharT, Traits>& red(std::basic_ostream<CharT, Traits> &os)
  {
    return os << "\033[31m";
  }

  template<typename CharT, typename Traits>
  std::basic_ostream<CharT, Traits>& green(std::basic_ostream<CharT, Traits> &os)
  {
    return os << "\033[32m";
  }

  template<typename CharT, typename Traits>
  std::basic_ostream<CharT, Traits>& yellow(std::basic_ostream<CharT, Traits> &os)
  {
    return os << "\033[33m";
  }

  template<typename CharT, typename Traits>
  std::basic_ostream<CharT, Traits>& blue(std::basic_ostream<CharT, Traits> &os)
  {
    return os << "\033[34m";
  }

  template<typename CharT, typename Traits>
  std::basic_ostream<CharT, Traits>& magenta(std::basic_ostream<CharT, Traits> &os)
  {
    return os << "\033[35m";
  }

  template<typename CharT, typename Traits>
  std::basic_ostream<CharT, Traits>& cyan(std::basic_ostream<CharT, Traits> &os)
  {
    return os << "\033[36m";
  }

  template<typename CharT, typename Traits>
  std::basic_ostream<CharT, Traits>& white(std::basic_ostream<CharT, Traits> &os)
  {
    return os << "\033[37m";
  }
} 
