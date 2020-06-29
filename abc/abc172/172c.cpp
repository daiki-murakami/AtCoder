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

int main() {
  std::cout << std::setprecision(9);
  int n, m;
  long k;
  cin >> n >> m >> k;
  vector<long> a_sum(n);
  for(int i=0; i<n; i++) {
    long a;
    cin >> a;
    if(i == 0) {
      a_sum.at(i) = a;
    }
    else {
      a_sum.at(i) = a_sum.at(i - 1) + a;
    }
  }
  vector<long> b_sum(m);
  for(int i=0; i<m; i++) {
    long b;
    cin >> b;
    if(i == 0) {
      b_sum.at(i) = b;
    }
    else {
      b_sum.at(i) = b_sum.at(i - 1) + b;
    }
  }

  int ans = 0;
  int a_num = 0;
  while(a_sum.at(a_num) <= k) {
    a_num++;
    if(a_num == n) {
      break;
    }
  }
  ans = a_num;

  for(int i=0; i<m; i++) {
    if(b_sum.at(i) > k) {
      break;
    }
    if(a_num > 0) {
      while(a_sum.at(a_num - 1) + b_sum.at(i) > k) {
        a_num--;
        if(a_num == 0) {
          break;
        }
      }
    }
    if(ans < a_num + i + 1) {
      ans = a_num + i + 1;
    }
  }

  cout << ans << endl;
}