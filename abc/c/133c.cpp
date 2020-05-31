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
  int l, r;
  cin >> l >> r;

  if (r - l >= 2018) {
    cout << 0 << endl;
  }
  else if (l % 2019 > r % 2019) {
    cout << 0 << endl;
  }
  else {
    int ans = 2019;
    int mod;
    for (int i=l; i<r; i++) {
      for (int j=i+1; j<=r; j++) {
        mod = ((i % 2019) * (j % 2019)) % 2019;
        if (ans > mod) {
          ans = mod;
        }
      }
    }
    cout << ans << endl;
  }
}