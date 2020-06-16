#include <iostream>

using namespace std;

template <class T> class List {
private:
  class Node {
  public:
    T data;
    Node *next;
    Node(){};
  };
  Node *head;

public:
  List() {}
  List(initializer_list<T> init);
  ~List();

  T getdata(int pos) const;
  void append(T data);
  void insert(T data, int pos);
  int count();
  void remove(T data);

  friend ostream &operator<<(ostream &out, const List &xs) {
    if (xs.head == nullptr) {
      cout << "Lista jest pusta!" << endl;
    }
    Node *node = xs.head;
    while (node != nullptr) {
      out << node->data << " ";
      node = node->next;
    }
    out << endl;
    return out;
  }
};
