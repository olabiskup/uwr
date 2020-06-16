// Aleksandra Biskup 317424
// Zadanie 9 - manipulatory i pliki

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
namespace my_manipulators {
istream &clearline(istream &input) {
  char c = input.get();
  while ((c = input.get()) != '\n')
    ;
  return input;
}

class index {
  int x, w;
  friend ostream &operator<<(ostream &output, const index &idx) {
    cout << "[" << setw(idx.w) << idx.x << "]";
    return output;
  }

public:
  index(int _x, int _w) : x(_x), w(_w) {}
};

class ignore {
  int x;
  friend istream &operator>>(istream &input, const ignore &ign) {
    char c;
    for (int i = 0; i < ign.x; i++) {
      c = input.get();
      if (c == '\n' || c == EOF)
        return input;
    }
    return input;
  }

public:
  ignore(int _x) : x(_x) {}
};

ostream &comma(ostream &output) {
  output << ", ";
  return output;
}

ostream &colon(ostream &output) {
  output << ": ";
  return output;
}
} // namespace my_manipulators

void print(vector<string> v1, vector<string> v2) {
  long unsigned int i = 0;
  cout << "Dodano" << my_manipulators::colon << endl;
  while (i != v1.size()) {
    int j = 0;
    while (v1[i] != v2[j])
      j++;
    cout << my_manipulators::index(j + 1, 1) << v1[i] << my_manipulators::comma
         << endl;
    i++;
  }
}

class Writer {
  ofstream output;

public:
  Writer(string file_name) {
    output.open(file_name, ios::binary);
    if (!output) {
      throw ios_base::failure("Nie uda³o siê otworzyæ pliku");
    }
  }
  template <typename T> void write(T data) {
    output.write(reinterpret_cast<char *>(&data), sizeof(data));
  }
  ~Writer() { output.close(); }
};

class Reader {
  ifstream input;

public:
  Reader(string file_name) {
    input.open(file_name, ios::binary);
    if (!input) {
      throw ios_base::failure("Nie uda³o siê otworzyæ pliku");
    }
  }
  template <typename T> T read() {
    int size = sizeof(T);
    char *data = new char[size];
    input.read(data, size);
    T res = *reinterpret_cast<T *>(data);
    delete[] data;
    return res;
  }
  ~Reader() { input.close(); }
};

void RandomNum(string file_name, int n) {
  Writer write_tmp(file_name);
  int x;
  cout << "Wpisywanie: \n";
  for (int i = 0; i < n; i++) {
    x = rand() % 1000;
    cout << x << "; ";
    write_tmp.write<int>(x);
  }
  write_tmp.~Writer();
  cout << "\nOdczytywanie: \n";
  Reader read_tmp(file_name);
  for (int i = 0; i < n; i++) {
    x = read_tmp.read<int>();
    cout << x << "; ";
  }
  cout << endl;
  read_tmp.~Reader();
}

int main() {
  string s;
  vector<string> v1, v2;
  int x, y;
  cout << "Przecinek" << my_manipulators::comma << "dwukropek"
       << my_manipulators::colon << endl;
  cout << "Test ignore: ";
  cin >> my_manipulators::ignore(5) >> s;
  cout << "Wynik: " << s;
  cout << "\nTest clearline" << my_manipulators::colon;
  cin >> my_manipulators::clearline >> s;
  cout << "Wynik: " << s;
  cout << "\nTest index: ";
  cin >> x >> y;
  cout << endl << my_manipulators::index(x, y);
  cout << endl << "Test wektora" << my_manipulators::colon << endl;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    v1.push_back(s);
  }
  v2 = v1;
  sort(v1.begin(), v1.end());
  print(v1, v2);

  cout << "Test Reader i Writer:\n";

  srand(time(nullptr));
  RandomNum("test.bin", 4);

  return 0;
}
