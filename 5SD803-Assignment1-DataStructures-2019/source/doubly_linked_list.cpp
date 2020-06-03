// doubly_linked_list.cpp

#include "doubly_linked_list.h"

doubly_linked_list::node::node()
   : value_(0)
   , next_(nullptr)
   , previous_(nullptr)
{
}

doubly_linked_list::node::node(int value, node *next, node *previous)
   : value_(value)
   , next_(next)
   , previous_(previous)
{
}

doubly_linked_list::doubly_linked_list()
   : count_(0)
   , head_(nullptr)
   , tail_(nullptr)
{
}

doubly_linked_list::~doubly_linked_list()
{
}

void doubly_linked_list::push_front(int value) {

}

void doubly_linked_list::push_back(int value) {

}

void doubly_linked_list::insert(int value, int index) {

}

void doubly_linked_list::pop_front() {

}

void doubly_linked_list::pop_back() {

}

void doubly_linked_list::remove(int index) {

}

void doubly_linked_list::clear() {

}

int doubly_linked_list::size() const {
   return count_;
}

int doubly_linked_list::front() const {
   return -1;
}

int doubly_linked_list::back() const {
   return -1;
}

int doubly_linked_list::at(int index) const {
   return -1;
}
