#include "zad4.hpp"

Stack::~Stack() {
  if (data)
    delete[] data;
}

Stack::Stack() {
  capacity = 1;
  data = new string[1];
}

Stack::Stack(const Stack &other) : capacity(other.capacity), size(other.size) {
  data = new string[other.capacity];
  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

Stack::Stack(Stack &&other) {
  data = other.data;
  size = other.size;
  capacity = other.capacity;
  other.data = nullptr;
  other.size = 0;
}

Stack::Stack(initializer_list<string> init) {
  if (init.size() > 100 || init.size() < 1)
    throw invalid_argument("Lista niewłaściwego rozmiaru");
  data = new string[init.size()];
  size = init.size();
  capacity = init.size();
  int i = 0;
  auto iter = init.begin();
  while (iter != init.end()) {
    auto value = *iter;
    data[i++] = value;
    iter = next(iter);
  }
}

Stack::Stack(int cap) {
  if (cap > 100 || cap < 1)
    throw invalid_argument("Poza zakresem");
  data = new string[cap];
  capacity = cap;
}
void Stack::push(string elem) {
  if (size >= capacity) {
    cout << "Przekroczenie pojemności";
    return;
  }
  data[size++] = elem;
  cout << "Dopisano na stos: " << elem;
}
string Stack::pop() {
  if (size == 0) {
    cout << "Stos jest pusty";
    return "";
  }
  return data[--size];
}
string Stack::peek() {
  if (size == 0) {
    cout << "Stos jest pusty";
    return "";
  }
  return data[size];
}

int Stack::askSize() { return size; }

Stack Stack::reverse() {
  Stack revStack(capacity);
  for (int i = size - 1; i >= 0; i--) {
    revStack.push(data[i]);
  }
  return revStack;
}

void printStack(Stack *stack) {
  Stack tmp = *stack;
  while (tmp.askSize() > 0)
    cout << tmp.pop() << " ";
}