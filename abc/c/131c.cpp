#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

vector<string> split(const string &s, char delim) {
  vector<string> elems;
  string item;
  for (char ch: s) {
    if (ch == delim) {
      if (!item.empty()) {
        elems.push_back(item);
      }
      item.clear();
    }
    else {
      item += ch;
    }
  }
  if (!item.empty()) {
    elems.push_back(item);
  }
  return elems;
}

string to_str_with_zero(int i, int w) {
  ostringstream sout;
  sout << std::setfill('0') << std::setw(w) << i;
  string s = sout.str();
  return s;
}

int gcd(int a, int b) {
  if (a == b) {
    return a;
  }
  else if (a > b) {
    return gcd(a - b, b);
  }
  else {
    return gcd(a, b - a);
  }
}

long divcount(long a, long b, long c) {
  long first;
  if (a % c == 0) {
    first = a;
  }
  else {
    first = a - a % c + c;
  }
  long last = b - b % c;
  return (last - first) / c + 1;
}

int main() {
  std::cout << std::setprecision(9);
  long a, b, c, d;
  cin >> a >> b >> c >> d;

  long div_c = divcount(a, b, c);
  long div_d = divcount(a, b, d);
  long div_cd = divcount(a, b, c * d / gcd(c, d));
  cout << b - a + 1 - div_c - div_d + div_cd << endl;
}