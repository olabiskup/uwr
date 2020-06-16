// Aleksandra Biskup 317424
// Zadanie 1 - Rozkład liczb całkowitych na czynniki pierwsze

#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int64_t x) {
  int64_t n = floor(sqrt(x));
  if (x % 2 == 0)
    return false;
  for (int64_t i = 3; i <= n; i = i + 2) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

vector<int64_t> factorize(int64_t x) {
  vector<int64_t> result;

  if (x == INT64_MIN) {
    x /= 2;
    x = -x;
    result.push_back(-1);
    result.push_back(2);
  }

  if (x == -1)
    return {x};

  if (x < 0) {
    x = -x;
    result.push_back(-1);
  }

  int64_t n = floor(sqrt(x));

  if (is_prime(x)) {
    result.push_back(x);
    return result;
  }
  if (x == 0 || x == 1)
    return {x};
  else {

    int64_t k = 2;

    while (x != 1 && k <= n) {
      if (x % k == 0) {
        x /= k;
        result.push_back(k);
      } else
        k++;
    }
    if (x != 1)
      result.push_back(x);
  }
  return result;
}

int64_t str2int2(string s) {
  string maxs = "9223372036854775807", mins = "9223372036854775808";
  bool negative = false;
  for (size_t i = 0; i < s.size(); i++) {
    if (s[0] == '-')
      continue;
    if (!isdigit(s[i]))
      throw invalid_argument("Błędny argument!");
  }

  if (s[0] == '-') {
    s.erase(begin(s));
    if (!s.compare(mins))
      return INT64_MIN;
    negative = true;
  }

  if (s.size() > 19)
    throw invalid_argument("Błędny argument!");

  int64_t res = 0;
  for (size_t i = 0; i < s.size(); i++) {
    res = res * 10 + (s[i] - '0');
  }

  if (!negative && res < 0)
    throw invalid_argument("Błędny argument!");

  if (negative)
    res = -res;

  if (negative && res > 0)
    throw invalid_argument("Błędny argument!");

  return res;
}

int main(int argc, char *argv[]) {
  if (argc < 2)
    cout << "Należy podać liczby do rozłożenia na czynniki pierwsze!\n";
  string s;

  for (int i = 1; i < argc; i++) {
    s = argv[i];
    vector<int64_t> factors = factorize(str2int2(s));
    cout << s << " = " << factors[0];
    factors.erase(begin(factors));
    for (const int64_t x : factors) {
      cout << " * " << x;
    }
    putchar('\n');
  }
  return 0;
}