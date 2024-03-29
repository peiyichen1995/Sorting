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
  void PrintPang() const;
  T PopBack();
  T PopFront();

  // private:
  void SortedInsert(T k);
  void SortedMerge(const DoublyLinkedList<T> * l);
  void InsertionSort();
  void BubbleSort();
  void SelectionSort();
  void MergeSort();

  nodePtr head;
  nodePtr tail;
};

#endif
