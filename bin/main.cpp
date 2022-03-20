#include <iostream>

#include <map>
#include <vector>

#include "string/string.hpp"
#include "range/range.hpp"
#include "container/container.hpp"
#include "logger/logger.hpp"

int main(int argc, char *argv[])
{
  // {// ex: split_str
  //   std::string str { "asdf,qwer,zxcv" };
  //   hack::string::v_str v = hack::string::split_str(str, ',');
  //   for (const auto& c : v) std::cout << c << std::endl;
  // }
  //
  // {// ex: within
  //   std::cout << std::boolalpha << hack::range::within(12, 34, 12, 23, 31, 17, 22, 33) << std::endl;
  // }
  // 
  // {// ex: v_multiset
  //   std::vector<std::string> v;
  //   hack::container::v_multiset(v, "asdf", "qwer", "zcv");
  //   for(const auto& c : v) std::cout << c << std::endl;
  // }
  //
  // {// ex: s_multiset
  //   std::set<int> s;
  //   hack::container::s_multiset(s, 1, 2, 3, 3, 2, 1);
  //   for(const auto& c : s) std::cout << c << std::endl;
  // }

  {// ex: log
    hack::log()(1234, "run in main", 1234);
    hack::warn(" # ")(1234, "run in main", 1234);
    hack::error(" - ")(1234, "run in main", 1234);

    std::string str { "hi" };
    hack::log()(str);

    std::vector<std::string> vs { "asdf", "qwer", "zxcv" };
    hack::log()("vector", vs, 1, 2, 'a');
    
    std::list<std::string> ls {  "asdf", "qwer", "zxcv" };
    hack::log()(vs, ls);

    std::map<int, std::string> m { { 1, "asdf" }, { 2, "qwer" }, { 3, "zxcv" } };
    hack::log()(vs, ls, m);

    std::tuple<int, std::string, bool> tp { 1, "tuple test", false };
    hack::log()(tp);
  }
}
