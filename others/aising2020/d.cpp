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

int main() {
  std::cout << std::setprecision(9);
  int n;
  cin >> n;

  string x;
  cin >> x;
  vector<int> x_i(n);
  int first_count = 0;
  for(int i=0; i<n; i++) {
    if(x[i] == '0') {
      x_i[i] = 0;
    }
    else {
      x_i[i] = 1;
      first_count++;
    }
  }

  vector<vector<int>> rs(n, vector<int>(2));
  int r_minus = 0;
  int r_plus = 0;
  if(first_count > 1) {
    rs[0][0] = 1 % (first_count - 1);
  }
  rs[0][1] = 1 % (first_count + 1);
  if(x_i[n - 1] == 1) {
    if(first_count > 1) {
      r_minus = (r_minus + rs[0][0]) % (first_count - 1);
    }
    r_plus = (r_plus + rs[0][1]) % (first_count + 1);
  }
  for(int i=1; i<n; i++) {
    if(first_count > 1) {
      rs[i][0] = (rs[i - 1][0] * 2) % (first_count - 1);
    }
    rs[i][1] = (rs[i - 1][1] * 2) % (first_count + 1);
    if(x_i[n - 1 - i] == 1) {
      if(first_count > 1) {
        r_minus = (r_minus + rs[i][0]) % (first_count - 1);
      }
      r_plus = (r_plus + rs[i][1]) % (first_count + 1);
    }
  }

  vector<int> f(200000);
  f[0] = 0;
  for(int i=1; i<200000; i++) {
    bitset<20> b_i(i);
    f[i] = f[i % b_i.count()] + 1;
  }

  for(int i=0; i<n; i++) {
    int next = 0;
    int ans = 0;
    if(x_i[i] == 0) {
      next = (r_plus + rs[n - 1 - i][1] + first_count + 1) % (first_count + 1);
      ans = f[next] + 1;
    }
    else {
      if(first_count > 1) {
        next = (r_minus - rs[n - 1 - i][0] + first_count - 1) % (first_count - 1);
        ans = f[next] + 1;
      }
    }
    cout << ans << endl;
  }
}