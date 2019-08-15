
#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode
{
public:
  ListNode() : prev(NULL), next(NULL) {}
  ListNode(T d) : data(d), prev(NULL), next(NULL) {}
  ListNode(T d, ListNode<T> * p, ListNode<T> * n) : data(d), prev(p), next(n) {}

  ListNode<T> * inMergeList(ListNode<T> * l, ListNode<T> * r)
  {
    if (l == NULL)
      return r;
    else if (r == NULL)
    {
      return l;
    }

    ListNode<T> * res;

    if (l->data <= r->data)
    {
      res = l;
      res->next = inMergeList(l->next, r);
    }
    else
    {
      res = r;
      res->next = inMergeList(l, r->next);
    }

    return res;
  }

  // void MergeList(ListNode<T> * l)
  // {
  //   ListNode<T> * cur = this;
  //   this = inMergeList(cur, l);
  //   return;
  // }

  void Print()
  {
    std::cout << "start:";
    ListNode<T> * cur = this;
    while (cur != NULL)
    {
      std::cout << " " << cur->data;
      cur = cur->next;
    }
    std::cout << std::endl;
  }

public:
  T data;
  ListNode<T> * prev;
  ListNode<T> * next;
};

#endif
