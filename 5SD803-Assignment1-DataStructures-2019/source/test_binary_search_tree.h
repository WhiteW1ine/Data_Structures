// test_binary_search_tree.h

#ifndef TEST_BINARY_SEARCH_TREE_H_INCLUDED
#define TEST_BINARY_SEARCH_TREE_H_INCLUDED

#include "unit_test.hpp"
#include "binary_search_tree.h"

void test_binary_search_tree() 
{
   binary_search_tree tree;

   TEST_BEGIN(binary_search_tree::size);
   TEST_CASE(tree.size() == 0);
   TEST_END();

   TEST_BEGIN(binary_search_tree::insert);
   tree.insert(10);
   TEST_CASE(tree.size() == 1);
   TEST_CASE(tree.contains(10));
   tree.insert(5);
   TEST_CASE(tree.size() == 2);
   TEST_CASE(tree.contains(5));
   tree.insert(15);
   TEST_CASE(tree.size() == 3);
   TEST_CASE(tree.contains(15));
   tree.insert(2);
   tree.insert(1);
   tree.insert(3);
   tree.insert(4);
   tree.insert(13);
   tree.insert(17);
   TEST_CASE(tree.size() == 9);
   tree.insert(16);
   tree.insert(19);
   TEST_CASE(tree.size() == 11);
   TEST_CASE(tree.contains(1));
   {
      const int in_order[] = { 1, 2, 3, 4, 5, 10, 13, 15, 16, 17, 19 };
      linked_list list;
      tree.depth_first(list, binary_search_tree::IN_ORDER);
      int count = tree.size();
      for (int index = 0; index < count; index++) 
      {
         TEST_CASE(list.at(index) == in_order[index]);
      }
   }
   TEST_END();

   TEST_BEGIN(binary_search_tree::remove);
   tree.remove(3);
   TEST_CASE(!tree.contains(3));
   tree.remove(2);
   TEST_CASE(tree.contains(1));
   TEST_CASE(!tree.contains(2));
   tree.remove(5);
   TEST_CASE(tree.contains(1));
   TEST_CASE(tree.contains(4));
   TEST_CASE(!tree.contains(5));
   TEST_CASE(tree.size() == 8);
   {
      const int in_order[] = { 1, 4, 10, 13, 15, 16, 17, 19 };
      linked_list list;
      tree.depth_first(list, binary_search_tree::IN_ORDER);
      const int count = tree.size();
      for (int index = 0; index < count; index++) {
         TEST_CASE(list.at(index) == in_order[index]);
      }
   }
   TEST_END();

   TEST_BEGIN(binary_search_tree::clear);
   tree.clear();
   TEST_CASE(tree.size() == 0);
   TEST_END();

   TEST_BEGIN(binary_search_tree::depth_first::PRE_ORDER);
   {
      const int elements[] = { 10, 5, 3, 2, 4, 7, 15, 13, 17, 16, 20 };
      const int count = sizeof(elements) / sizeof(elements[0]);
      for (int index = 0; index < count; index++) {
         tree.insert(elements[index]);
      }

      const int pre_order[] = { 10, 5, 3, 2, 4, 7, 15, 13, 17, 16, 20 };
      linked_list list;
      tree.depth_first(list, binary_search_tree::PRE_ORDER);
      for (int index = 0; index < count; index++) {
         TEST_CASE(list.at(index) == pre_order[index]);
      }
   }
   TEST_END();

   tree.clear();

   TEST_BEGIN(binary_search_tree::depth_first::POST_ORDER);
   {
      const int elements[] = { 10, 5, 3, 2, 4, 7, 15, 13, 17, 16, 20 };
      const int count = sizeof(elements) / sizeof(elements[0]);
      for (int index = 0; index < count; index++) {
         tree.insert(elements[index]);
      }

      const int post_order[] = { 2, 4, 3, 7, 5, 13, 16, 20, 17, 15, 10 };
      linked_list list;
      tree.depth_first(list, binary_search_tree::POST_ORDER);
      for (int index = 0; index < count; index++) {
         TEST_CASE(list.at(index) == post_order[index]);
      }
   }
   TEST_END();

   tree.clear();


   TEST_BEGIN(binary_search_tree::breath_first);
   {
       const int elements[] = { 10, 5, 3, 2, 4, 7, 15, 13, 17, 16, 20 };
       const int count = sizeof(elements) / sizeof(elements[0]);
       for (int index = 0; index < count; index++) {
           tree.insert(elements[index]);
       }

       const int breath_first[] = { 10, 5, 15, 3, 7, 13, 17, 2, 4, 16, 20 };
       linked_list list;
       tree.breath_first(list);
       for (int index = 0; index < count; index++) {
           TEST_CASE(list.at(index) == breath_first[index]);
       }
   }
   TEST_END();
}


#endif // !TEST_BINARY_SEARCH_TREE_H_INCLUDED
