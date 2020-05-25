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

int main() {
  std::cout << std::setprecision(9);
  int n, k;
  cin >> n >> k;

  double ans;
  for (int i = 1; i <= n; i++) {
    int base = 1;
    while (i * base < k) {
      base *= 2;
    }
    ans += 1.0 / base;
  }
  cout << ans / n << endl;;
}