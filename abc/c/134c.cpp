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

int main() {
  std::cout << std::setprecision(9);
  int n;
  cin >> n;

  vector<int> a(n);
  int first, second, which;
  first = 0;
  second = 0;
  for (int i=0; i<n; i++) {
    cin >> a.at(i);
    if (a.at(i) >= first) {
      second = first;
      first = a.at(i);
      which = i;
    }
    else if (a.at(i) > second) {
      second = a.at(i);
    }
  }
  for (int i=0; i<n; i++) {
    if (which == i) {
      cout << second << endl;
    }
    else {
      cout << first << endl;
    }
  }
}