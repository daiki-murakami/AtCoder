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
  double w, h;
  int x, y;
  cin >> w >> h >> x >> y;

  double area = w * h / 2.0;
  if (x * 2 == w && y * 2 == h) {
    cout << area << ' ' << 1 << endl;
  }
  else {
    cout << area << ' ' << 0 << endl;
  }
}