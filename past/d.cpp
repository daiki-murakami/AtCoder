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

  string l1, l2, l3, l4, l5;
  cin >> l1 >> l2 >> l3 >> l4 >> l5;

  vector<char> l1_c(l1.begin(), l1.end());
  vector<char> l2_c(l2.begin(), l2.end());
  vector<char> l3_c(l3.begin(), l3.end());
  vector<char> l4_c(l4.begin(), l4.end());
  vector<char> l5_c(l5.begin(), l5.end());
  for(int i=0; i<n; i++) {
    if(l1_c.at(4*i+1) == '.' && l1_c.at(4*i+2) == '#') {
      cout << 1;
    }
    else if(l1_c.at(4*i+1) == '#' && l1_c.at(4*i+2) == '.') {
      cout << 4;
    }
    else {
      if(l2_c.at(4*i+1) == '.' && l2_c.at(4*i+2) == '.') {
        // 2 or 3 or 7
        if(l3_c.at(4*i+1) == '.') {
          cout << 7;
        }
        else {
          if(l4_c.at(4*i+1) == '.') {
            cout << 3;
          }
          else {
            cout << 2;
          }
        }
      }
      else if(l2_c.at(4*i+2) == '.' && l2_c.at(4*i+3) == '.') {
        // 5 or 6
        if(l4_c.at(4*i+1) == '.') {
          cout << 5;
        }
        else {
          cout << 6;
        }
      }
      else {
        // 0 or 8 or 9
        if(l3_c.at(4*i+2) == '.') {
          cout << 0;
        }
        else {
          if(l4_c.at(4*i+1) == '.') {
            cout << 9;
          }
          else {
            cout << 8;
          }
        }
      }
    }
  }
  cout << endl;
}