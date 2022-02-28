#pragma once

#include <string>

#ifndef ERROR_EXCEPTION
#define ERROR_EXCEPTION_1(in) { auto trace = std::string(LOGGER___TRACE_ON); \
                                 throw tools::error::error_exception(in, in, "no internal system error", trace); }
#define ERROR_EXCEPTION_2(in, out) { auto trace = std::string(LOGGER___TRACE_ON); \
                                         throw tools::error::error_exception(in, out, "no internal system err", trace); }
#define ERROR_EXCEPTION_3(in, out, err) { auto trace = std::string(LOGGER___TRACE_ON); \
                                              throw tools::error::error_exception(in, out, err, trace); }
#define GET_MACRO(_1,_2,_3,NAME, ...) NAME
#define ERROR_EXCEPTION(...) GET_MACRO(__VA_ARGS__, ERROR_EXCEPTION_3, ERROR_EXCEPTION_2, ERROR_EXCEPTION_1)(__VA_ARGS__)
#endif

namespace tools::error
{
  // implementation error exception
  // example: if (1 < 0) ERROR_EXCEPTION("it's very strange"); 
  // try {} 
  // catch(tools::error::error_exception& e) {}
  struct error_exception : public std::exception
  {
    error_exception(std::string in, std::string out, std::string error, std::string trace) : in { in }, out { out }, error { error }, trace { trace } {};
    std::string in;
    std::string out;
    std::string error;
    std::string trace;
    const char* what () const throw () { return in.c_str(); }
  };
}

