#ifndef NODE_H
#define NODE_H

#include <assert.h>
#include <iostream>
#include <stdio.h>

template <typename K, typename V>
class Node
{
public:
  Node() {}

  Node(K k, V v) : key(k), val(v) {}

  Node(const Node<K, V> & n)
  {
    key = n.key;
    val = n.val;
  }

  void print() { std::cout << key << ": " << val << std::endl; }

  bool operator>(const Node<K, V> & n) { return (this->val > n.val); }

  bool operator<(const Node<K, V> & n) { return (this->val < n.val); }

  bool operator==(const Node<K, V> & n) { return (this->key == n.key); }

  bool operator<=(const Node<K, V> & n) { return (this->val <= n.val); }

  bool operator>=(const Node<K, V> & n) { return (this->val >= n.val); }

  Node & operator=(const Node<K, V> & n)
  {
    key = n.key;
    val = n.val;
    return *this;
  }

  friend std::ostream & operator<<(std::ostream & os, const Node<K, V> & n)
  {
    os << "(" << n.key << ": " << n.val << ")";
    return os;
  }

private:
  K key;
  V val;
};

#endif
