// binary_search_tree.cpp

#include "binary_search_tree.h"

binary_search_tree::node::node()
   : value_(0)
   , lhs_(nullptr)
   , rhs_(nullptr)
{
}

binary_search_tree::node::node(int value, node *lhs, node *rhs)
   : value_(value)
   , lhs_(lhs)
   , rhs_(rhs)
{
}

binary_search_tree::binary_search_tree() 
   : count_(0)
   , root_(nullptr)
{
}

binary_search_tree::~binary_search_tree()
{
}

void binary_search_tree::insert(int value) {

}

void binary_search_tree::remove(int value) {

}

void binary_search_tree::clear() {

}

int binary_search_tree::size() const {
   return count_;
}

bool binary_search_tree::contains(int value) {
   return false;
}

void binary_search_tree::depth_first(linked_list &list, const depth_first_algorithm algorithm) {
   switch (algorithm) {
      case binary_search_tree::PRE_ORDER:
      {

      } break;
      case binary_search_tree::IN_ORDER:
      {

      } break;
      case binary_search_tree::POST_ORDER:
      {

      } break;
   }
}

void binary_search_tree::breath_first(linked_list &list) {

}
