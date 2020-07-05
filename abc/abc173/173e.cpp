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
  int n, k;
  cin >> n >> k;

  vector<long> a(n);
  int plus = 0;
  for(int i=0; i<n; i++) {
    cin >> a[i];
    if(a[i] > 0) {
      plus++;
    }
  }
  sort(a.begin(), a.end(), greater<int>());

  long ans = 1;
  if(plus == 0 && k % 2 == 1) {
    for(int i=0; i<k; i++) {
      ans *= a[i];
      ans %= 1000000007;
    }
    if(ans < 0) {
      ans += 1000000007;
    }
    cout << ans << endl;
  }
  else {
    int l = 0;
    int r = n - 1;
    for(int i=0; i<k/2; i++) {
      if(a[l] * a[l + 1] > a[r] * a[r - 1]) {
        ans *= ((a[l] * a[l + 1]) % 1000000007);
        ans %= 1000000007;
        l += 2;
      }
      else {
        ans *= ((a[r] * a[r - 1]) % 1000000007);
        ans %= 1000000007;
        r -= 2;
      }
    }
    if(k % 2 == 1) {
      ans *= max(a[l], a[r]);
      ans %= 1000000007;
    }
    if(ans < 0) {
      ans += 1000000007;
    }
    cout << ans << endl;
  }
}