#include <iostream>

using namespace std;

class Stack {
private:
  string *data;
  int capacity, size = 0;

public:
  Stack(int cap);
  Stack();
  Stack(initializer_list<string>);
  Stack(const Stack &other);
  Stack(Stack &&other);
  ~Stack();
  void push(string elem);
  string pop();
  string peek();
  Stack reverse();
  int askSize();
};
void printStack(Stack *stack);
