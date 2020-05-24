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

  vector<bitset<10>> stols(m);
  for (int i=0; i<m; i++) {
    int k;
    cin >> k;
    for (int j=0; j<k; j++) {
      int s;
      cin >> s;
      stols.at(i).set(s - 1, 1);
    };
  }

  vector<int> p(m);
  for(int i=0; i<m; i++) {
    cin >> p.at(i);
  }

  int ans = 0;
  for (int tmp=0; tmp < (1 << 10); tmp++) {
    if (tmp >= pow(2, n)) {
      break;
    }
    bitset<10> lightset(tmp);
    
    bool all_on = true;
    for (int i=0; i<m; i++) {
      bitset<10> on = lightset & stols.at(i);
      if (on.count() % 2 != p.at(i)) {
        all_on = false;
      }
    }
    if (all_on) {
      ans++;
    }
  }

  cout << ans << endl;
}