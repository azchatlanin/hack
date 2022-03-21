#include <iostream>

#include <map>
#include <set>
#include <vector>

#include "string/string.hpp"
#include "range/range.hpp"
#include "container/container.hpp"
#include "logger/logger.hpp"

int main(int argc, char *argv[])
{
  {// ex: split_str
    std::string str { "asdf,qwer,zxcv" };
    hack::string::v_str v = hack::string::split_str(str, ',');
    for (const auto& c : v) hack::log()(c);
  }

  {// ex: within
    hack::log()(hack::range::within(12, 34, 12, 23, 31, 17, 22, 33));
  }

  {// ex: vector_multiset
    std::vector<std::string> v;
    hack::container::vector_multiset(v, "asdf", "qwer", "zcv");
    for(const auto& c : v) std::cout << c << std::endl;
  }

  {// ex: set_multiset
    std::set<int> s;
    hack::container::set_multiset(s, 1, 2, 3, 3, 2, 1);
    for(const auto& c : s) std::cout << c << std::endl;
  }

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

  {// ex: matches
    std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    hack::log()(hack::container::matches(v, 2, 5, 4, 12));
  }

  {// ex: vector_remove_at
    std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    hack::container::vector_remove_at(v, 3);
    hack::log()(v);
  }
}
