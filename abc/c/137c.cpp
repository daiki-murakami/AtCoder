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

int letter_to_int(char c) {
  return tolower(c) - 'a';
}

bool compare_array(vector<int> a1, vector<int> a2) {
  int n = min(a1.size(), a2.size());
  for(int i=0; i<n; i++) {
    if (a1.at(i) != a2.at(i)) {
      return a1.at(i) - a2.at(i);
    }
    return a1.size() - a2.size();
  }
}

bool array_equal(vector<int> a1, vector<int>a2) {
  if (a1.size() != a2.size()) {
    return false;
  }
  for (int i=0; i<a1.size(); i++) {
    if (a1.at(i) != a2.at(i)) {
      return false;
    }
  }
  return true;
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

  vector<string> s(n);
  for (int i=0; i<n; i++) {
    cin >> s.at(i);
    sort(s.at(i).begin(), s.at(i).end());
  }
  sort(s.begin(), s.end());

  long ans = 0;
  long count = 1;
  for (int i=1; i<n; i++) {
    if (s.at(i - 1) == s.at(i)) {
      ans += count;
      count++;
    }
    else {
      count = 1;
    }
  }
  cout << ans << endl;
}