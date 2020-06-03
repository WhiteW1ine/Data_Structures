// linked_list.h

#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

// note: implementation required for pass

class linked_list {
   linked_list(linked_list &&rhs) = delete;
   linked_list(const linked_list &rhs) = delete;
   linked_list &operator=(const linked_list &rhs) = delete;

public:
   linked_list();
   ~linked_list();

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
      explicit node(int value, node *next);

      int value_;
      node *next_;
   };

   int count_;
   node *head_;
   node *tail_;
};

#endif // !LINKED_LIST_H_INCLUDED
