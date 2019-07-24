#include "DoublyLinkedList.h"
#include <assert.h>

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  head = NULL;
  tail = NULL;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  nodePtr tmp = head;
  nodePtr n = head;
  while (n != NULL)
  {
    tmp = n;
    delete n;
    n = tmp->next;
  }
}

template <typename T>
void
DoublyLinkedList<T>::PushBack(T addData)
{
  nodePtr n = new ListNode<T>(addData, tail, NULL);

  if (tail)
    tail->next = n;
  tail = n;

  if (head == NULL)
    head = n;
}

template <typename T>
void
DoublyLinkedList<T>::PushFront(T addData)
{
  nodePtr n = new ListNode<T>(addData, NULL, head);

  if (head)
    head->prev = n;
  head = n;

  if (tail == NULL)
    tail = n;
}

template <typename T>
void
DoublyLinkedList<T>::PrintPang()
{
  std::cout << "head --> ";
  if (head != NULL)
  {
    nodePtr curr = head;
    while (curr->next != NULL)
    {
      std::cout << curr->data << " <--> ";
      curr = curr->next;
    }
    std::cout << curr->data;
  }
  std::cout << " <-- tail" << std::endl;
}

template <typename T>
T
DoublyLinkedList<T>::PopBack()
{
  assert(tail != NULL);
  T del;
  nodePtr curr = tail;
  tail = curr->prev;
  del = curr->data;
  delete curr;
  if (tail)
    tail->next = NULL;
  else
    head = NULL;
  return del;
}

template <typename T>
T
DoublyLinkedList<T>::PopFront()
{
  assert(head != NULL);
  T del;
  nodePtr curr = head;
  head = curr->next;
  del = curr->data;
  delete curr;
  if (head)
    head->prev = NULL;
  else
    tail = NULL;
  return del;
}

template <typename T>
void
DoublyLinkedList<T>::SortedInsert(T k)
{
  if (head == NULL || k <= head->data)
  {
    this->PushFront(k);
    return;
  }

  ListNode<T> * cur = head;

  while (cur->next)
  {
    cur = cur->next;
    if (k < cur->data)
    {
      ListNode<T> * tmp = new ListNode<T>(k, cur->prev, cur);
      cur->prev->next = tmp;
      cur->prev = tmp;
      return;
    }
  }

  if (k >= cur->data)
  {
    this->PushBack(k);
    return;
  }
}

template <typename T>
void
DoublyLinkedList<T>::InsertionSort()
{
  if (head == NULL || head->next == NULL)
    return;

  ListNode<T> * cur = head->next;
  ListNode<T> * tmp;
  // ListNode<T> * tmp2;
  T keep;
  // start from head
  // if (cur->next->data < cur->data)
  // {
  //   keep = cur->data;
  //   cur->data = cur->next->data;
  //   cur->next->data = keep;
  // }
  //
  // cur = cur->next;

  while (cur)
  {
    if (cur->data < cur->prev->data)
    {
      tmp = cur;
      while (tmp != head && tmp->data < tmp->prev->data)
      {
        keep = tmp->data;
        tmp->data = tmp->prev->data;
        tmp->prev->data = keep;
        tmp = tmp->prev;
      }
    }
    cur = cur->next;
  }

  return;
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<double>;
template class DoublyLinkedList<std::string>;
template class DoublyLinkedList<Node<std::string, double>>;
