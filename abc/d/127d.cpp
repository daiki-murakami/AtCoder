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
  int n1 = a1.size();
  int n2 = a2.size();
  if (n1 != n2) {
    return n1 - n2;
  }
  for (int i=0; i<n1; i++) {
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

vector<vector<int>> all_comb(int n, int k) {
  vector<vector<int>> combs(nCr(n, k), vector<int>(k));
  for(int i=0; i<k; i++) {
    combs[0][i] = i;
    combs[1][i] = i;
  }
  
  for(long i=1; i<nCr(n, k); i++) {
    int p = 1;
    while(combs[i][k - p] == n - p) {
      p++;
      if(p > k) {
        break;
      }
    }
    combs[i][k - p]++;
    int q = combs[i][k - p];
    for(int j=1; j<p; j++) {
      combs[i][k - p + j] = q + j;
    }

    if(i < nCr(n, k) - 1) {
      for(int j=0; j<k; j++) {
        combs[i + 1][j] = combs[i][j];
      }
    }
  }

  return combs;
}

template <typename TYPE> void co(TYPE a) {
  cout << a << endl;
}

template <typename TYPE> void co_2(TYPE a, TYPE b) {
  cout << a << ' ' << b << endl;
}

template <typename TYPE> void co_l(vector<TYPE> as) {
  int n = as.size();
  for(int i=0; i<n; i++) {
    cout << as[i] << endl;
  }
}

template <typename TYPE> void co_s(vector<TYPE> as) {
  int n = as.size();
  for(int i=0; i<n; i++) {
    if(i > 0) {
      cout << ' ';
    }
    cout << as[i];
  }
  cout << endl;
}

int main() {
  std::cout << std::setprecision(9);
  int n, m;
  cin >> n >> m;

  vector<long> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  vector<pair<long, int>> q(m);
  for(int i=0; i<m; i++) {
    cin >> q[i].second >> q[i].first;
  }
  sort(a.begin(), a.end(), greater<long>());
  sort(q.begin(), q.end(), greater<pair<long, int>>());
  
  int count_a = 0;
  int count_q = 0;
  int count_all = 0;
  long ans = 0;
  while(count_all < n) {
    if(a[count_a] >= q[count_q].first) {
      ans += a[count_a];
      count_a++;
      count_all++;
    }
    else {
      if(count_all + q[count_q].second >= n) {
        ans += q[count_q].first * (n - count_all);
        count_all = n;
        count_q++;
      }
      else {
        ans += q[count_q].first * q[count_q].second;
        count_all += q[count_q].second;
        count_q++;
      }
    }
  }

  co(ans);
}