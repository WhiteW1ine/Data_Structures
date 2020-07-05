// binary_search_tree.h

#ifndef BINARY_SEARCH_TREE_H_INCLUDED
#define BINARY_SEARCH_TREE_H_INCLUDED

#include "linked_list.h"

// note: implementation required for pass

class binary_search_tree {
   binary_search_tree(binary_search_tree &&rhs) = delete;
   binary_search_tree(const binary_search_tree &rhs) = delete;
   binary_search_tree &operator=(const binary_search_tree &rhs) = delete;

public:
   enum depth_first_algorithm {
      PRE_ORDER,
      IN_ORDER,
      POST_ORDER,
   };

   binary_search_tree();
   ~binary_search_tree();

   void insert(int value);
   void remove(int value);
   void clear();
   int size() const;

   bool contains(int value);
   void depth_first(linked_list &list, const depth_first_algorithm algorithm);
   void breath_first(linked_list &list);

private:
   struct node {
      node();
      explicit node(int value, node *lhs, node *rhs);

      int value_;
      node *lhs_; // lhs -> left-hand side
      node *rhs_; // rhs -> right-hand side
   };

   void in_order(linked_list& list, node* parent);
   void pre_order(linked_list& list, node* parent);
   void post_order(linked_list& list, node* parent);

   int count_;
   node *root_;
};


#endif // !BINARY_SEARCH_TREE_H_INCLUDED
