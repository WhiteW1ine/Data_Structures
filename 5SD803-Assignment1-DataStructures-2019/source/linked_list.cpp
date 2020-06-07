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

void linked_list::push_front(int value) 
{
    node* new_node = new node(value, nullptr);
    if (head_ == nullptr)
    {
        head_ = new_node;
        count_++;
    }
    else if (head_ != nullptr)
    {
        new_node->next_ = head_;
        head_ = new_node;
        count_++;
    }

    if (count_ == 2)
    {
        tail_ = head_->next_;
    }
}

void linked_list::push_back(int value) 
{
    node* new_node = new node(value, nullptr);
    if (head_ == nullptr)
    {
        head_ = new_node;
        count_++;
    }
    else
    {
        node* current = new node;
        current = head_;
        while (current->next_ != nullptr)
        {
            current = current->next_;
        }
        current->next_ = new_node;
        tail_ = new_node;
        count_++;
    }

}

void linked_list::insert(int value, int index) 
{
    node* new_node = new node(value, nullptr);
    node* current = new node;
    current = head_;
    for (int i = 1; i < index; i++)
    {
        current = current->next_;
    }
    new_node->next_ = current->next_;
    current->next_ = new_node;
    count_++;
}

void linked_list::pop_front() 
{
    node* current = new node;
    current = head_;
    head_ = current->next_;
    current = nullptr;
    delete current;
    count_--;
}

void linked_list::pop_back() {

}

void linked_list::remove(int index) 
{
    node* current = new node;
    node* previous = new node;
    current = head_;
    for (int i = 0; i < index; i++)
    {
        previous = current;
        current = current->next_;   
    }
    previous->next_ = current->next_;
    current = nullptr;
    delete current;
    count_--;


    //if (previous->next_ == nullptr)
    //{
    //    pop_front();
    //}
}

void linked_list::clear() {

}

int linked_list::size() const {
   return count_;
}

int linked_list::front() const {
   return head_->value_;
}

int linked_list::back() const 
{
    return tail_->value_;
   
}

int linked_list::at(int index) const 
{
    node* current = new node;
    current = head_;
    for (int i = 0; i < index; i++)
    {
        current = current->next_;
    }
    return current->value_;
}
