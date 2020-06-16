#include "wymierna.hpp"

using namespace calculations;

int main() {
  Rational r1(9, 5);
  Rational r2(1, 2);
  cout << "1/2 = " << r1 << endl;
  cout << "9/5 = " << r2 << endl;

  cout << "9/5 + 1/2 = " << r1 + r2 << endl;
  cout << "9/5 - 1/2 = " << r1 - r2 << endl;
  cout << " 9/5 * 1/2 = " << r1 * r2 << endl;
  cout << "9/5 / 1/2  = " << r1 / r2 << endl;

  cout << "-(9/5) = " << -r2 << endl;
  cout << "!(9/5) = " << !r2 << endl;

  cout << "Castowanie 9/5 do int " << (int)r1 << endl;
  cout << "Castowanie 9/5 do double: " << (double)r1 << endl;
  return 0;
}