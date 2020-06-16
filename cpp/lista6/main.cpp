// Aleksandra Biskup 317424
#include "Expression.hpp"

int main() {
  Expression *test =
      new Divide(new Multiply(new Subtract(new Variable("x"), new Number(1)),
                              new Variable("x")),
                 new Number(2));
  Expression *test1 = new Divide(
      new Add(new Number(3), new Number(5)),
      new Add(new Number(2), new Multiply(new Variable("x"), new Number(7))));
  Expression *test2 =
      new Divide(new Cos(new Multiply(new Add(new Variable("x"), new Number(1)),
                                      new Variable("x"))),
                 new Power(new e, new Power(new Variable("x"), new Number(2))));
  cout << test->description();
  cout << endl;
  cout << test1->description() << endl;
  cout << test2->description() << endl;
  Variable::assVar("x", 0);
  for (int i = 0; i < 100; i++) {
    Variable::assVar("x", Variable::getVar("x") + 0.01);
    cout << Variable::getVar("x") << "   " << test->evaluate() << "    "
         << test1->evaluate() << "    " << test2->evaluate() << endl;
  }
  return 0;
}