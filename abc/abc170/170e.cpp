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
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  vector<int> b(n);
  vector<multiset<int>> kinder(200000);
  for (int i=0; i<n; i++) {
    cin >> a.at(i) >> b.at(i);
    kinder.at(b.at(i) - 1).insert(a.at(i));
  }

  multiset<int> max_rate;
  for (int i=0; i<200000; i++) {
    if (kinder.at(i).size() != 0) {
      max_rate.insert(*kinder.at(i).rbegin());
    }
  }

  for (int i=0; i<q; i++) {
    int c, d;
    cin >> c >> d;
    int before_max_from, after_max_from;
    int before_max_to, after_max_to;
    before_max_from = *kinder.at(b.at(c - 1) - 1).rbegin();
    if (kinder.at(d - 1).size() > 0) {
      before_max_to = *kinder.at(d - 1).rbegin();
    }
    kinder.at(b.at(c - 1) - 1).erase(kinder.at(b.at(c - 1) - 1).find(a.at(c - 1)));
    kinder.at(d - 1).insert(a.at(c - 1));
    if (kinder.at(b.at(c - 1) - 1).size() > 0) {
      after_max_from = *kinder.at(b.at(c - 1) - 1).rbegin();
    }
    after_max_to = *kinder.at(d - 1).rbegin();

    if (kinder.at(b.at(c - 1) - 1).size() > 0) {
      if (before_max_from != after_max_from) {
        max_rate.erase(max_rate.find(before_max_from));
        max_rate.insert(after_max_from);
      }
    }
    else {
      max_rate.erase(max_rate.find(before_max_from));
    }
    if (kinder.at(d - 1).size() > 1) {
      if (before_max_to != after_max_to) {
        max_rate.erase(max_rate.find(before_max_to));
        max_rate.insert(after_max_to);
      }
    }
    else {
      max_rate.insert(after_max_to);
    }
    b.at(c - 1) = d;

    cout << *(--max_rate.rend()) << endl;
  }
}