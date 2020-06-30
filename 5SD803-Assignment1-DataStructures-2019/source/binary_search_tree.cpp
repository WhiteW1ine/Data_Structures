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

void binary_search_tree::insert(int value) 
{
    node* new_node = new node(value, nullptr, nullptr);

    if (root_ == nullptr)
    {
        root_ = new_node;
        count_++;
    }
    else 
    {
        node* current = nullptr;
        node* previous = nullptr;
        current = root_;
        previous = current;
        while (current != nullptr)
        {
            previous = current;
            if (new_node->value_ < current->value_)
            {
                current = current->lhs_;
            }
            else if (new_node->value_ > current->value_)
            {
                current = current->rhs_;
            }
        }

        if (new_node->value_ < previous->value_)
        {
            previous->lhs_ = new_node;
            count_++;
        }
        else if (new_node->value_ > previous->value_)
        {
            previous->rhs_ = new_node;
            count_++;
        }
    }
}

void binary_search_tree::remove(int value) {

}

void binary_search_tree::clear() {

}

int binary_search_tree::size() const {
   return count_;
}

bool binary_search_tree::contains(int value) 
{
    node* new_node = new node(value, nullptr, nullptr);

    while (root_ != nullptr)
    {
        if (new_node->value_ < root_->value_)
        {
            root_ = root_->lhs_;
        }
        else if (new_node->value_ > root_->value_)
        {
            root_ = root_->rhs_;
        }
        else if (new_node->value_ == root_->value_)
        {
            return true;
        }
    }
    return false;
}

void binary_search_tree::depth_first(linked_list &list, const depth_first_algorithm algorithm) {
   switch (algorithm) {
      case binary_search_tree::PRE_ORDER:
      {

      } break;
      case binary_search_tree::IN_ORDER:
      {
          IN_ORDER;
          IN_ORDER;
      } break;
      case binary_search_tree::POST_ORDER:
      {

      } break;
   }
}

void binary_search_tree::breath_first(linked_list &list) 
{

}
