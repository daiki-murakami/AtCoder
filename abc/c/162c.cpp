#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>

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

int compare_array(vector<int> a1, vector<int>a2) {
  if (a1.size() != a2.size()) {
    return a1.size() - a2.size();
  }
  for (int i=0; i<a1.size(); i++) {
    if (a1.at(i) != a2.at(i)) {
      return a1.at(i) - a2.at(i);
    }
  }
  return 0;
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

char int_to_char(int a) {
  if (a == -1) {
    return 'z';
  }
  else {
    return 'a' + a;
  }
}

long nCr(int n, int r) {
    long ans = 1;
    for (int i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (int i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

int divide_count(int a, int divider) {
  int r = 0;
  while(a % divider == 0) {
    a /= divider;
    r++;
  }
  return r;
}

bool is_prime(int a) {
  int i = 2;
  while(i * i <= a) {
    if(a % i == 0) {
      return false;
    }
    i++;
  }
  return true;
}

int main() {
  std::cout << std::setprecision(9);
  int k;
  cin >> k;

  int ans = 0;
  vector<vector<vector<int>>> v(k, vector<vector<int>>(k, vector<int>(k, 1)));
  for(int i=0; i<k; i++) {
    for(int j=0; j<k; j++) {
      for(int l=0; l<k; l++) {
        if(i==0 || j==0 || l==0) {
          ans++;
        }
        else if(i==j && i==l) {
          ans += i + 1;
          v[i][j][l] = i + 1;
        }
        else if(i < l) {
          ans += v[i][j][l - i - 1];
          v[i][j][l] = v[i][j][l - i - 1];
        }
        else if(j < l) {
          ans += v[i][j][l - j - 1];
          v[i][j][l] = v[i][j][l - j - 1];
        }
        else if(i > l) {
          ans += v[i - l - 1][j][l];
          v[i][j][l] = v[i - l - 1][j][l];
        }
        else if(j > l) {
          ans += v[i][j - l - 1][l];
          v[i][j][l] = v[i][j - l - 1][l];
        }
        else {
          cout << "error" << endl;
        }
      }
    }
  }

  cout << ans << endl;
}