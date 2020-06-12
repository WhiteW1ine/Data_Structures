// test_linked_list.h

#ifndef TEST_LINKED_LIST_H_INCLUDED
#define TEST_LINKED_LIST_H_INCLUDED

#include "unit_test.hpp"
#include "linked_list.h"

void test_linked_list() {
   linked_list list;

   TEST_BEGIN(linked_list::size);
   TEST_CASE(list.size() == 0);
   TEST_END();
   
   TEST_BEGIN(linked_list::push_front);
   list.push_front(2);     // 2
   TEST_CASE(list.size() == 1);
   TEST_CASE(list.at(0) == 2);
   TEST_CASE(list.front() == 2);

   list.push_front(1);     // 1, 2
   TEST_CASE(list.size() == 2);
   TEST_CASE(list.at(0) == 1);
   TEST_CASE(list.front() == 1);
   TEST_CASE(list.at(1) == 2);
   TEST_CASE(list.back() == 2);
   TEST_END();

   TEST_BEGIN(linked_list::push_back);
   list.push_back(3);      // 1, 2, 3
   TEST_CASE(list.size() == 3);
   TEST_CASE(list.at(2) == 3);
   TEST_CASE(list.back() == 3);

   list.push_back(5);      // 1, 2, 3, 5
   TEST_CASE(list.size() == 4);
   TEST_CASE(list.at(2) == 3);
   TEST_CASE(list.at(3) == 5);
   TEST_CASE(list.back() == 5);
   TEST_END();

   TEST_BEGIN(linked_list::insert);
   list.insert(4, 3);      // 1, 2, 3, 4, 5
   TEST_CASE(list.size() == 5);
   TEST_CASE(list.at(2) == 3);
   TEST_CASE(list.at(3) == 4);
   TEST_CASE(list.at(4) == 5);
   TEST_END();

   TEST_BEGIN(linked_list::remove);
   list.remove(1);         // 1, 3, 4, 5
   TEST_CASE(list.size() == 4);
   TEST_CASE(list.front() == 1);
   TEST_CASE(list.at(1) == 3);
   TEST_CASE(list.at(2) == 4);
   TEST_CASE(list.back() == 5);
   TEST_END();

   TEST_BEGIN(linked_list::pop_front);
   list.pop_front();       // 3, 4, 5
   TEST_CASE(list.size() == 3);
   TEST_CASE(list.front() == 3);
   TEST_CASE(list.back() == 5);
   TEST_END(); 

   TEST_BEGIN(linked_list::pop_back);
   list.pop_back();       //  3, 4
   TEST_CASE(list.size() == 2);
   TEST_CASE(list.front() == 3);
   TEST_CASE(list.back() == 4);
   TEST_END();

   TEST_BEGIN(linked_list::clear);
   list.clear();
   TEST_CASE(list.size() == 0);
   TEST_END();
}

#endif // !TEST_LINKED_LIST_H_INCLUDED
