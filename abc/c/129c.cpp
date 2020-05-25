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
  int n, m;
  cin >> n >> m;

  vector<int> steps(n + 1, 1);
  for (int i=0; i<m; i++) {
    int a;
    cin >> a;
    steps.at(a) = 0;
  }

  for (int i=2; i<n + 1; i++) {
    if (steps.at(i) > 0) {
      steps.at(i) = steps.at(i - 1) + steps.at(i - 2);
      steps.at(i) %= 1000000007;
    }
  }

  cout << steps.at(n) << endl;
}