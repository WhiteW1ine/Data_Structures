// doubly_linked_list.h

#ifndef DOUBLY_LINKED_LIST_H_INCLUDED
#define DOUBLY_LINKED_LIST_H_INCLUDED

// note: pass with distinction only...

class doubly_linked_list {
   doubly_linked_list(doubly_linked_list &&rhs) = delete;
   doubly_linked_list(const doubly_linked_list &rhs) = delete;
   doubly_linked_list &operator=(const doubly_linked_list &rhs) = delete;

public:
   doubly_linked_list();
   ~doubly_linked_list();

   void push_front(int value);
   void push_back(int value);
   void insert(int value, int index);
   void pop_front();
   void pop_back();
   void remove(int index);
   void clear();
   int size() const;
   int front() const;
   int back() const;
   int at(int index) const;

private:
   struct node {
      node();
      explicit node(int value, node *next, node *previous);

      int value_;
      node *next_;
      node *previous_;
   };

   int count_;
   node *head_;
   node *tail_;
};

#endif // !DOUBLY_LINKED_LIST_H_INCLUDED
