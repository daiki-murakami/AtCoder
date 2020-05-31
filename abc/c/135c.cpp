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

  vector<long> a(n + 1);
  for (int i=0; i<n+1; i++) {
    cin >> a.at(i);
  }
  vector<long> b(n);
  for (int i=0; i<n; i++) {
    cin >> b.at(i);
  }

  long ans = 0;
  for (int i=0; i<n; i++) {
    long first = min(a.at(i), b.at(i));
    ans += first;
    b.at(i) -= first;
    long second = min(a.at(i + 1), b.at(i));
    ans += second;
    a.at(i + 1) -= second; 
  }
  cout << ans << endl;
}