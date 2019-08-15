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
  T keep;

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

template <typename T>
void
DoublyLinkedList<T>::BubbleSort()
{
  if (head == NULL || head->next == NULL)
    return;

  int stop = 0;
  T keep;
  ListNode<T> * cur;

  while (stop == 0)
  {
    cur = head;
    stop = 1;
    while (cur->next)
    {
      if (cur->next->data < cur->data)
      {
        keep = cur->next->data;
        cur->next->data = cur->data;
        cur->data = keep;
        stop = 0;
      }
      cur = cur->next;
    }
  }

  return;
}

template <typename T>
void
DoublyLinkedList<T>::SelectionSort()
{
  if (head == NULL || head->next == NULL)
    return;

  ListNode<T> * cur = head;
  ListNode<T> * tmp;
  ListNode<T> * min;
  T keep;

  while (cur->next)
  {
    tmp = cur;
    keep = tmp->data;
    while (tmp)
    {
      if (tmp->data <= keep)
      {
        keep = tmp->data;
        min = tmp;
      }
      tmp = tmp->next;
    }

    min->data = cur->data;
    cur->data = keep;

    cur = cur->next;
  }

  return;
}

template <typename T>
void
DoublyLinkedList<T>::SortedMerge(const DoublyLinkedList<T> * l)
{
  if (tail->data <= l->head->data)
  {
    nodePtr cur = l->head;
    ListNode<T> * tmp = tail;
    while (cur)
    {
      tmp->next = new ListNode<T>(cur->data, tmp, NULL);
      tmp = tmp->next;
      cur = cur->next;
    }
    tail = tmp;
  }
  else if (head->data >= l->tail->data)
  {
    nodePtr cur = l->head->next;
    ListNode<T> * tmp = new ListNode<T>(l->head->data);
    ListNode<T> * keep = tmp;
    while (cur)
    {
      tmp->next = new ListNode<T>(cur->data, tmp, NULL);
      tmp = tmp->next;
      cur = cur->next;
    }
    tmp->next = head;
    head->prev = tmp;
    head = keep;
  }

  nodePtr cur = l->head;
  nodePtr tmp;
  while (cur)
  {
    if (cur->data <= head->data)
    {
      tmp = new ListNode<T>(cur->data, NULL, head);
      head = tmp;
      cur = cur->next;
      continue;
    }
    else if (cur->data >= tail->data)
    {
      tmp = new ListNode<T>(cur->data, tail, NULL);
      tail = tmp;
      cur = cur->next;
      continue;
    }
    else
    {
      tmp = head;
      while (tmp != tail)
      {
        if (tmp->data <= cur->data && cur->data <= tmp->next->data)
        {
          tmp->next = new ListNode<T>(cur->data, tmp, tmp->next);
          break;
        }
        tmp = tmp->next;
      }
      cur = cur->next;
      continue;
    }
  }

  return;
}

template <typename T>
void
DoublyLinkedList<T>::MergeSort()
{
  if (head == NULL || head->next == NULL)
    return;

  else if (head->next->next == NULL)
  {
    if (head->data > tail->data)
    {
      std::swap(head->data, tail->data);
    }
    return;
  }
  // split list into two parts
  ListNode<T> * slow = head;
  ListNode<T> * fast = head->next;

  while (fast->next != NULL && fast->next->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  DoublyLinkedList<T> A;
  DoublyLinkedList<T> B;
  nodePtr cur = head;
  while (cur != slow->next)
  {
    A.PushBack(cur->data);
    cur = cur->next;
  }
  while (cur)
  {
    B.PushBack(cur->data);
    cur = cur->next;
  }
  A.MergeSort();

  B.MergeSort();

  A.SortedMerge(&B);

  head = A.head;
  tail = A.tail;

  return;
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<double>;
template class DoublyLinkedList<std::string>;
template class DoublyLinkedList<Node<std::string, double>>;
