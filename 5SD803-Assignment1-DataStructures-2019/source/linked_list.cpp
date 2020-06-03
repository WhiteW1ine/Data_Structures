// linked_list.cpp

#include "linked_list.h"

linked_list::node::node()
   : value_(0)
   , next_(nullptr)
{
}

linked_list::node::node(int value, node *next)
   : value_(value)
   , next_(next)
{
}

linked_list::linked_list() 
   : count_(0)
   , head_(nullptr)
   , tail_(nullptr)
{
}

linked_list::~linked_list()
{
}

void linked_list::push_front(int value) {

}

void linked_list::push_back(int value) {

}

void linked_list::insert(int value, int index) {

}

void linked_list::pop_front() {

}

void linked_list::pop_back() {

}

void linked_list::remove(int index) {

}

void linked_list::clear() {

}

int linked_list::size() const {
   return count_;
}

int linked_list::front() const {
   return -1;
}

int linked_list::back() const {
   return -1;
}

int linked_list::at(int index) const {
   return -1;
}
