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

  vector<pair<int, int>> edges(m);
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  for(int i=0; i<m; i++) {
    cin >> edges.at(i).first >> edges.at(i).second;
    matrix.at(edges.at(i).first - 1).at(edges.at(i).second - 1) = 1;
    matrix.at(edges.at(i).second - 1).at(edges.at(i).first - 1) = 1;
  }

  vector<int> colors(n);
  for(int i=0; i<n; i++) {
    cin >> colors.at(i);
  }

  for(int i=0; i<q; i++) {
    int type;
    cin >> type;
    if(type == 1) {
      int x;
      cin >> x;
      cout << colors.at(x - 1) << endl;;
      for(int j=0; j<n; j++){
        if(matrix.at(x - 1).at(j) == 1) {
          colors.at(j) = colors.at(x - 1);
        }
      }
    }
    else if(type == 2) {
      int x, y;
      cin >> x >> y;
      cout << colors.at(x - 1) << endl;;
      colors.at(x - 1) = y;
    }
  }
}