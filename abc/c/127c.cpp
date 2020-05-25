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

  vector<int> lefts(m);
  vector<int> rights(m);
  for (int i = 0; i < m; i++) {
    cin >> lefts.at(i) >> rights.at(i);
  }

  int distance = *min_element(rights.begin(), rights.end()) - *max_element(lefts.begin(), lefts.end());
  if (distance < 0) {
    cout << 0 << endl;
  }
  else {
    cout << distance + 1 << endl;
  }
}