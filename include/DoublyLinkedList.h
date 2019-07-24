#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H

#include <string>
#include <iostream>
#include "ListNode.h"
#include "Node.h"

template <typename T>
class DoublyLinkedList
{
public:
  typedef ListNode<T> * nodePtr;

public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  void PushBack(T addData);
  void PushFront(T addData);
  void PrintPang();
  T PopBack();
  T PopFront();

  // private:
  void SortedInsert(T k);
  void InsertionSort();

  nodePtr head;
  nodePtr tail;
};

#endif
