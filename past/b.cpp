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
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> result(n, vector<int>(m, 0));
  vector<int> points(m, n);
  for (int i=0; i<q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int per;
      cin >> per;
      int ans = 0;
      for (int j=0; j<m; j++) {
        ans += result.at(per - 1).at(j) * points.at(j);
      }
      cout << ans << endl;
    }
    else if (type == 2) {
      int per, pro;
      cin >> per >> pro;
      result.at(per - 1).at(pro - 1) = 1;
      points.at(pro - 1) -= 1;
    }
  }
}