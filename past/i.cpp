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

  vector<long> rnum(n);
  vector<long> cnum(n);
  for(int i=0; i<n; i++) {
    rnum.at(i) = i;
    cnum.at(i) = i;
  }

  int reverse = -1;
  for(int i=0; i<q; i++) {
    int type;
    cin >> type;

    if((type == 1 && reverse == -1) || (type == 2 && reverse == 1)) {
      int a, b;
      cin >> a >> b;
      long tmp = rnum.at(a - 1);
      rnum.at(a - 1) = rnum.at(b - 1);
      rnum.at(b - 1) = tmp;
    }
    else if((type == 1 && reverse == 1) || (type == 2 && reverse == -1)) {
      int a, b;
      cin >> a >> b;
      long tmp = cnum.at(a - 1);
      cnum.at(a - 1) = cnum.at(b - 1);
      cnum.at(b - 1) = tmp;
    }
    else if(type == 3) {
      if(reverse == 1) {
        reverse = -1;
      }
      else {
        reverse = 1;
      }
    }
    else if(type == 4) {
      int a, b;
      cin >> a >> b;
      if(reverse == 1) {
        cout << n * rnum.at(b - 1) + cnum.at(a - 1) << endl;
      }
      else {
        cout << n * rnum.at(a - 1) + cnum.at(b - 1) << endl;
      }
    }
  }
}