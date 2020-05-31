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

  vector<vector<char>> rows;
  for(int i=0; i<n; i++) {
    string s;
    cin >> s;
    vector<char> s_c(s.begin(), s.end());
    rows.push_back(s_c);
  }

  vector<char> ans(n);
  bool ok = true;
  int l = 0;
  int r = n - 1;
  while(l < r) {
    bool found = false;
    for(int i=0; i<n; i++) {
      auto itr = find(rows.at(r).begin(), rows.at(r).end(), rows.at(l).at(i));
      if(itr != rows.at(r).end()) {
        ans.at(l) = rows.at(l).at(i);
        ans.at(r) = rows.at(l).at(i);
        l++;
        r--;
        found = true;
        break;
      }
    }
    if(!found) {
      ok = false;
      break;
    }
  }
  if(l == r) {
    ans.at(l) = rows.at(l).at(0);
  }
  if(ok) {
    for(int i=0; i<n; i++) {
      cout << ans.at(i);
    }
    cout << endl;
  }
  else {
    cout << -1 << endl;
  }
}