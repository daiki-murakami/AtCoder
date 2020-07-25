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
  if(a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
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

struct plane {
  int x;
  int y;
  char u;

  bool compare_by_plus(const plane& p1, const plane& p2) {
    if(p1.x + p1.y == p2.x + p2.y) {
      return p1.u < p2.u;
    }
    else {
      return p1.x + p1.y < p2.x + p2.y;
    }
  }

  bool compare_by_minus(const plane& p1, const plane& p2) {
    if(p1.y - p1.x == p2.y - p2.x) {
      return p1.u < p2.u;
    }
    else {
      return p1.y - p1.x < p2.y - p2.x;
    }
  }
};

bool compare_by_plus(const plane& p1, const plane& p2) {
  if(p1.x + p1.y == p2.x + p2.y) {
    return p1.u < p2.u;
  }
  else {
    return p1.x + p1.y < p2.x + p2.y;
  }
}

bool compare_by_minus(const plane& p1, const plane& p2) {
  if(p1.y - p1.x == p2.y - p2.x) {
    return p1.u < p2.u;
  }
  else {
    return p1.y - p1.x < p2.y - p2.x;
  }
}

int main() {
  std::cout << std::setprecision(9);
  int n;
  cin >> n;

  vector<plane> p(n);
  for(int i=0; i<n; i++) {
    int x, y;
    char u;
    cin >> x >> y >> u;
    p[i] = {x, y, u};
  }
  sort(p.begin(), p.end(), compare_by_plus);

  for(int i=0; i<n; i++) {
    cout << p[i].x << ' ' << p[i].y << ' ' << p[i].u << endl;
  }
}