// unit_test.hpp

#ifndef UNIT_TEST_HPP_INCLUDED
#define UNIT_TEST_HPP_INCLUDED

#include <iostream>

template <typename T>
bool test(const T &result, const char *name, const char *file, const int line) {
   if (result) {
      std::cout << " + pass:   " << name << std::endl;
      return true;
   }

   std::cout << " - FAILED: " << name;
   std::cout << "\tin " << file << " (" << line << ")" << std::endl;

   return false;
}

#define TEST_BEGIN(n) std::cout << "## " << #n << std::endl;
#define TEST_END()    std::cout << std::endl;
#define TEST_CASE(t)  test(t, #t, __FUNCTION__, __LINE__)

#endif // !UNIT_TEST_HPP_INCLUDED
