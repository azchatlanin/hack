#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <type_traits>

#include "string/string.hpp"
#include "range/range.hpp"
#include "container/container.hpp"
#include "logger/logger.hpp"
#include "math/matrix.hpp"
#include "math/vector.hpp"

#include <string_view>

int main(int argc, char *argv[])
{
  // {// ex: split_str
  //   std::string str { "asdf,qwer,zxcv" };
  //   hack::string::v_str v = hack::string::split_str(str, ',');
  //   for (const auto& c : v) hack::log()(c);
  // }
  //
  // {// ex: within
  //   hack::log()(hack::range::within(12, 34, 12, 23, 31, 17, 22, 33));
  // }
  //
  // {// ex: vector_multiset
  //   std::vector<std::string> v;
  //   hack::container::vector_multiset(v, "asdf", "qwer", "zcv");
  //   for(const auto& c : v) std::cout << c << std::endl;
  // }
  //
  // {// ex: set_multiset
  //   std::set<int> s;
  //   hack::container::set_multiset(s, 1, 2, 3, 3, 2, 1);
  //   for(const auto& c : s) std::cout << c << std::endl;
  // }
  //
  // {// ex: log
  //   hack::log()(1234, "run in main", 1234);
  //   hack::warn(" # ")(1234, "run in main", 1234);
  //   hack::error(" - ")(1234, "run in main", 1234);
  //
  //   std::string str { "hi" };
  //   hack::log()(str);
  //
  //   std::vector<std::string> vs { "asdf", "qwer", "zxcv" };
  //   hack::log()("vector", vs, 1, 2, 'a');
  // 
  //   std::list<std::string> ls {  "asdf", "qwer", "zxcv" };
  //   hack::log()(vs, ls);
  //
  //   std::map<int, std::string> m { { 1, "asdf" }, { 2, "qwer" }, { 3, "zxcv" } };
  //   hack::log()(vs, ls, m);
  //
  //   std::tuple<int, std::string, bool> tp { 1, "tuple test", false };
  //   hack::log()(tp);
  // }
  //
  // {// ex: matches
  //   std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  //   hack::log()(hack::container::matches(v, 2, 5, 4, 12));
  // }
  //
  // {// ex: vector_remove_at
  //   std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  //   hack::container::vector_remove_at(v, 3);
  //   hack::log()(v);
  // }

  // {// ex: matrix
  //   hack::matrix<int, 3> m_int;
  //   hack::matrix<int, 3> m_int_c { { 2, 3, 4, 123 }, { 0, 2, 4, 555 } };
  //   hack::matrix<float, 3> m_float;
  //
  //   m_int[0][0][0] = 123;
  //   m_int[0][0][1] = 23;
  //   m_int[0][0][2] = 43;
  //   m_int_c[0][0][0] = 123;
  //   m_float[0][0][0] = 123.123;
  //
  //   auto i = m_int[0][0][0];
  //   auto f = m_float[0][0][0];
  //
  //   hack::log()("m_int", i); 
  //   hack::log()("m_float", f);
  //   hack::log()("empty", m_float[123][22][33]);
  //
  //   hack::log("")("compare (true): ", m_int == m_int_c);
  //   hack::log("")("compare (false): ", m_int == m_float);
  //   hack::log("")(m_int);
  //   hack::log("")(m_int_c);
  //
  //   auto m_moved {std::forward<hack::matrix<int, 3>>(m_int_c)};
  //   hack::log("")("moved data: ", m_moved);
  //
  //   m_int = std::forward<hack::matrix<int, 3>>(m_int_c);
  //   hack::log("")("moved data: ", m_int);
  //
  //   hack::matrix<int, 3> m_int_d = m_int; 
  //   hack::log("")("copy data: ", m_int_d);
  //
  //   hack::matrix<int, 3> m_int_cd { { 2, 3, 4, 3 }, { 0, 2, 4, 5 } };
  //   hack::log("")("copy data: ", m_int_cd);
  //   m_int_cd = m_int;
  //   hack::log("")("copy data: ", m_int_cd);
  // }

  {// ex: vector
    hack::vector<int, int, int> v3_1 { 8, 4, 9, };
    hack::vector<int, int, int> v3_2 { 1, 2, 3, };
    hack::log()(v3_1.get_value());
    hack::log()(v3_2.get_value());

    v3_1 = v3_2;

    hack::log()(v3_1.get_value());
    hack::log()(v3_2.get_value());

    hack::log()("length 3", v3_2.length());
    
    hack::vector<int, int> v2_1 { 11, 22 };
    hack::log()("length 2", v2_1.length());

    hack::vector<int, int, int> lerp_1 { 1, 2, 3 };
    hack::vector<int, int, int> lerp_2 { 5, 6, 7 };
    hack::log()("lerp", lerp_1.lerp(lerp_2, 0.75f));
  }
}
