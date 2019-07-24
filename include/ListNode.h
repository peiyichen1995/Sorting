
#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode
{
public:
  ListNode() : prev(NULL), next(NULL) {}
  ListNode(T d) : data(d), prev(NULL), next(NULL) {}
  ListNode(T d, ListNode<T> * p, ListNode<T> * n) : data(d), prev(p), next(n) {}

public:
  T data;
  ListNode<T> * prev;
  ListNode<T> * next;
};

#endif
