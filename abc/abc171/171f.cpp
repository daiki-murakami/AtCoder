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

int main() {
  std::cout << std::setprecision(9);
  int divisor = 1000000007;
  int k;
  cin >> k;
  string s;
  cin >> s;
  
  long long c1 = 1;
  long long c2 = s.size();
  long long ans = 0;
  long long pow = 1;
  for (int i=0; i<k+1; i++) {
    ans *= 26;
    ans %= divisor;
    if (i > 0) {
      pow *= 25;
      pow %= divisor;
    }
    ans += (c1 * pow) % divisor;
    ans %= divisor;
    c1 = c2;
    c2 *= i + s.size() + 1;
    c2 %= divisor;
    c2 *= modinv(i + 2, divisor);
    c2 %= divisor;
  }
  cout << ans << endl;
}