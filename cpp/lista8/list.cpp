#include "list.hpp"

template <class T> List<T>::List(initializer_list<T> init) {
  for (auto i : init)
    this->append(i);
}

template <class T> void List<T>::append(T data) {
  Node *newnode = new Node();
  newnode->data = data;
  newnode->next = NULL;
  if (head == nullptr) {
    head = newnode;
  } else {
    Node *tmp = head;
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = newnode;
  }
}

template <class T> int List<T>::count() {
  if (head == nullptr)
    return 0;
  int length = 0;
  Node *tmp = head;
  while (tmp->next != nullptr) {
    length++;
    tmp = tmp->next;
  }
  return length;
}

template <class T> T List<T>::getdata(int pos) const {
  Node *tmp = head;
  for (int i = 0; i < pos; i++) {
    tmp = tmp->next;
  }
  return tmp->data;
}

template <class T> void List<T>::remove(T data) {
  Node *tmp = head;
  if (tmp->data == data) {
    head = tmp->next;
    delete tmp;
    return;
  }
}

template <class T> List<T>::~List() {
  while (head != nullptr) {
    Node *tmp = head->next;
    delete (head);
    head = tmp;
  }
}

template class List<int>;