// binary_search_tree.cpp

#include "binary_search_tree.h"
#include <queue>

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
        node* current;
        node* previous;
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

void binary_search_tree::remove(int value) 
{

    node* current;
    node* previous;
    current = root_;
    previous = current;

    while (true)
    {

        if (current->value_ == value)
        {
            break;
        }

        previous = current;

        if (value < current->value_)
        {
            current = current->lhs_;
        }
        else if (value > current->value_)
        {
            current = current->rhs_;
        }

    }

    if (current->lhs_ == nullptr && current->rhs_ == nullptr)
    {
        if (previous->lhs_ != nullptr)
        {
            previous->lhs_ = nullptr;
            delete current;
            count_--;
        }
        else if (previous->rhs_ != nullptr)
        {
            previous->rhs_ = nullptr;
            delete current;
            count_--;
        }
    }

    else if (current->lhs_ == nullptr || current->rhs_ == nullptr)
    {
        if (current->lhs_ != nullptr)
        {
            if (previous->lhs_ == current)
            {
                previous->lhs_ = current->lhs_;
                delete current;
                count_--;
            }
            
            else if (previous->rhs_ == current)
            {
                previous->rhs_ = current->lhs_;
                delete current;
                count_--;
            }
        }
        else if (current->rhs_ != nullptr)
        {
            if (previous->lhs_ == current)
            {
                previous->lhs_ = current->rhs_;
                delete current;
                count_--;
            }

            else if (previous->rhs_ == current)
            {
                previous->rhs_ = current->rhs_;
                delete current;
                count_--;
            }
        }
    }

    else if (current->lhs_ != nullptr && current->rhs_ != nullptr)
    {
        previous = current->rhs_;

        if (previous->lhs_ == nullptr && previous->rhs_ == nullptr)
        {
            current->value_ = previous->value_;
            current->rhs_ = nullptr;
            count_--;
        }

        else if (previous->lhs_ == nullptr && previous->rhs_ != nullptr)
        {
            current->value_ = previous->value_;
            current->rhs_ = current->rhs_->rhs_;
            count_--;
        }

        else
        {
            while (previous->lhs_->lhs_ != nullptr)
                previous = previous->lhs_;

            current->value_ = previous->lhs_->value_;
            previous->lhs_ = nullptr;
            count_--;
        }
    }




}

void binary_search_tree::clear() 
{



    while (root_->lhs_!=nullptr)
    {
        node* current;
        node* previous;
        current = root_;
        previous = current;

        while (true)
        {

            if (current->lhs_ == nullptr && current->rhs_ == nullptr)
            {
                break;
            }

            previous = current;

            if (current->lhs_!=nullptr)
            {
                current = current->lhs_;
            }
            else if (current->rhs_ != nullptr)
            {
                current = current->rhs_;
            }

        }

        if (previous->lhs_ != nullptr)
        {
            previous->lhs_ = nullptr;
            delete current;
            count_--;
        }
        else if (previous->rhs_ != nullptr)
        {
            previous->rhs_ = nullptr;
            delete current;
            count_--;
        }


    }

    while (root_->rhs_ != nullptr)
    {
        node* current;
        node* previous;
        current = root_;
        previous = current;

        while (true)
        {

            if (current->lhs_ == nullptr && current->rhs_ == nullptr)
            {
                break;
            }

            previous = current;

            if (current->lhs_ != nullptr)
            {
                current = current->lhs_;
            }
            else if (current->rhs_ != nullptr)
            {
                current = current->rhs_;
            }

        }

        if (previous->lhs_ != nullptr)
        {
            previous->lhs_ = nullptr;
            delete current;
            count_--;
        }
        else if (previous->rhs_ != nullptr)
        {
            previous->rhs_ = nullptr;
            delete current;
            count_--;
        }

    }

    node* current;
    current = root_;

    delete current;
    root_ = nullptr;
    count_--;

}

int binary_search_tree::size() const {
   return count_;
}

bool binary_search_tree::contains(int value) 
{
    node* current;
    current = root_;

    if (current->value_ == value)
    {
        return true;
    }

    while (current != nullptr)
    {
        if (current->value_ == value)
        {
            return true;
        }

        if (value < current->value_)
        {
            current = current->lhs_;
        }
        else if (value > current->value_)
        {
            current = current->rhs_;
        }
       
    }
    return false;
}

void binary_search_tree::depth_first(linked_list &list, const depth_first_algorithm algorithm) {
   switch (algorithm) {
      case binary_search_tree::PRE_ORDER:
      {
		  pre_order(list, root_);
      } break;
      case binary_search_tree::IN_ORDER:
      {
		  in_order(list, root_);
      } break;
      case binary_search_tree::POST_ORDER:
      {
		  post_order(list, root_);
      } break;
   }
}

void binary_search_tree::breath_first(linked_list &list) 
{
    std::queue<node*> queue;
    queue.push(root_);

    while (queue.empty() == false)
    {
       
        node* new_node = queue.front();
            list.push_back(new_node->value_);
            queue.pop();
            if (new_node->lhs_ != NULL)
            {
                queue.push(new_node->lhs_);
            }
            if (new_node->rhs_ != NULL)
            {
                queue.push(new_node->rhs_);
            }
        
    }
}

void binary_search_tree::in_order(linked_list& list, node* parent)
{
    if (parent == nullptr)
        return;
    in_order(list, parent->lhs_);
    list.push_back(parent->value_);
    in_order(list, parent->rhs_);
}

void binary_search_tree::pre_order(linked_list& list, node* parent)
{
    if (parent == nullptr)
        return;
    list.push_back(parent->value_);
    pre_order(list, parent->lhs_);
    pre_order(list, parent->rhs_);
}

void binary_search_tree::post_order(linked_list& list, node* parent)
{
    if (parent == nullptr)
        return;
    post_order(list, parent->lhs_);
    post_order(list, parent->rhs_);
    list.push_back(parent->value_);
}
