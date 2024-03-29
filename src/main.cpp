#include "Node.h"
#include "DoublyLinkedList.h"
#include "ListNode.h"

void
test_int()
{
  std::cout << "======================\n";
  std::cout << "Testing <int> instantiation: \n";
  DoublyLinkedList<int> A;
  A.PushFront(13);
  A.PushBack(14);
  A.PushBack(15);
  A.PushFront(12);
  A.PrintPang();
}

void
test_double()
{
  std::cout << "======================\n";
  std::cout << "Testing <double> instantiation: \n";
  DoublyLinkedList<double> B;
  B.PushFront(3.7);
  B.PushBack(5.8);
  B.PushBack(6.9);
  B.PushFront(12.1);
  B.PrintPang();
}

void
test_string()
{
  std::cout << "======================\n";
  std::cout << "Testing <std::string> instantiation: \n";
  DoublyLinkedList<std::string> C;
  C.PushFront("xiao");
  C.PushBack("pang");
  C.PushBack("hu");
  C.PushFront("ruo");
  C.PrintPang();
}

void
test_pop()
{
  std::cout << "======================\n";
  std::cout << "Testing PopFront and PopBack: \n";
  DoublyLinkedList<std::string> C;
  C.PushFront("xiao");
  C.PushBack("pang");
  C.PushBack("hu");
  C.PushFront("ruo");
  C.PrintPang();

  std::cout << "PopFront once:\n";
  C.PopFront();
  C.PrintPang();
  std::cout << "PopBack once:\n";
  C.PopBack();
  C.PrintPang();
  std::cout << "PopFront once:\n";
  C.PopFront();
  C.PrintPang();
  std::cout << "PopBack once:\n";
  C.PopBack();
  C.PrintPang();
}

void
test_node()
{
  std::cout << "======================\n";
  std::cout << "Testing Node: \n";
  Node<std::string, double> A("Nanning", 500);
  Node<std::string, double> B("Nanjing", 400);
  Node<std::string, double> C("Durham", 300);
  Node<std::string, double> D("Chicago", 200);
  DoublyLinkedList<Node<std::string, double>> V;
  V.PushBack(A);
  V.PushBack(B);
  V.PushFront(C);
  V.PushBack(D);
  V.PrintPang();
  std::cout << "PopBack and PopFront once:\n";
  V.PopBack();
  V.PopFront();
  V.PrintPang();
}

void
test_sortedinsert()
{
  std::cout << "======================\n";
  std::cout << "Testing sorted insertion: \n";
  DoublyLinkedList<int> A;
  A.PushFront(13);
  A.PushBack(14);
  A.PushBack(15);
  A.PushFront(10);
  A.SortedInsert(9);
  A.PrintPang();
  A.SortedInsert(17);
  A.PrintPang();
  A.SortedInsert(11);
  A.PrintPang();
}

void
test_InsertionSort()
{
  std::cout << "======================\n";
  std::cout << "Testing insertion sort: \n";
  DoublyLinkedList<int> A;
  A.PushFront(14);
  A.PushBack(13);
  A.PushBack(20);
  A.PushBack(15);
  A.PushFront(70);
  A.PrintPang();
  A.InsertionSort();
  A.PrintPang();
}

void
test_BubbleSort()
{
  std::cout << "======================\n";
  std::cout << "Testing insertion sort: \n";
  DoublyLinkedList<int> A;
  A.PushFront(14);
  A.PushBack(13);
  A.PushBack(20);
  A.PushBack(15);
  A.PushFront(70);
  A.PrintPang();
  A.BubbleSort();
  A.PrintPang();
}

void
test_SelectionSort()
{
  std::cout << "======================\n";
  std::cout << "Testing insertion sort: \n";
  DoublyLinkedList<int> A;
  A.PushFront(14);
  A.PushBack(13);
  A.PushBack(20);
  A.PushBack(15);
  A.PushFront(70);
  A.PrintPang();
  A.BubbleSort();
  A.PrintPang();
}

void
test_MergeList()
{
  std::cout << "======================\n";
  std::cout << "Testing merge lists: \n";
  ListNode<int> A;
  A.data = 0;
  A.next = new ListNode<int>(1);
  A.next->next = new ListNode<int>(3);
  ListNode<int> B;
  B.data = 0;
  B.next = new ListNode<int>(2);
  B.next->next = new ListNode<int>(4);
  ListNode<int> C;
  A.Print();
  B.Print();
  C = *(C.inMergeList(&A, &B));
  C.Print();
}

void
test_SortedMerge()
{
  std::cout << "======================\n";
  std::cout << "Testing sorted merge: \n";
  DoublyLinkedList<int> A;
  A.PushFront(12);
  A.PushBack(13);
  A.PushBack(20);
  A.PushBack(21);
  A.PushBack(70);
  A.PrintPang();
  DoublyLinkedList<int> B;
  B.PushFront(11);
  B.PushBack(17);
  B.PushBack(83);
  B.PushBack(84);
  B.PushBack(85);
  B.PrintPang();
  B.SortedMerge(&A);
  A.PrintPang();
  B.PrintPang();
}

void
test_MergeSort()
{
  std::cout << "======================\n";
  std::cout << "Testing merge sort: \n";
  DoublyLinkedList<int> A;
  A.PushFront(14);
  A.PushBack(13);
  A.PushBack(22);
  A.PushBack(21);
  A.PushBack(70);
  A.PushBack(80);
  A.PrintPang();
  A.MergeSort();
  A.PrintPang();
}

int
main(void)
{

  // test_int();
  // test_double();
  // test_string();
  // test_pop();
  // test_node();
  // test_sortedinsert();
  // test_InsertionSort();
  // test_BubbleSort();
  // test_SelectionSort();
  // test_MergeList();
  // test_SortedMerge();
  test_MergeSort();
}
