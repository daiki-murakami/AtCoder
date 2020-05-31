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
  int n, l;
  cin >> n >> l;

  vector<vector<int>> times(4, vector<int>(l + 1, 0));
  vector<int> hurdles(l + 1, 0);
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    hurdles.at(x) = 1;
  }

  int t1, t2, t3;
  cin >> t1 >> t2 >> t3;

  for(int i=1; i<l+1; i++) {
    if(i >= 4) {
      times.at(0).at(i) = min({
        times.at(0).at(i - 1) + t1,
        times.at(0).at(i - 2) + t1 + t2,
        times.at(0).at(i - 4) + t1 + 3 * t2
      });
    }
    else if(i >= 2) {
      times.at(0).at(i) = min(
        times.at(0).at(i - 1) + t1,
        times.at(0).at(i - 2) + t1 + t2
      );
    }
    else {
      times.at(0).at(i) = times.at(0).at(i - 1) + t1;
    }
    if(hurdles.at(i) == 1) {
      times.at(0).at(i) += t3;
    }
    times.at(1).at(i) = times.at(0).at(i - 1) + t1 / 2 + t2 / 2;
    if(times.at(1).at(i - 1) > 0) {
      times.at(2).at(i) = times.at(1).at(i - 1) + t2;
    }
    if(times.at(2).at(i - 1) > 0) {
      times.at(3).at(i) = times.at(2).at(i - 1) + t2;
    }
  }

  int ans;
  if(l == 2) {
    ans = min({
      times.at(0).at(l),
      times.at(1).at(l),
      times.at(2).at(l)
    });
  }
  else {
    ans = min({
      times.at(0).at(l),
      times.at(1).at(l),
      times.at(2).at(l),
      times.at(3).at(l)
    });
  }
  cout << ans << endl;
}