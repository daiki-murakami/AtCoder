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

long modinv(long long a, long long m) {
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
  long mod = 1000000007;
  int h, w;
  int cx, cy, dx, dy;
  cin >> h >> w;
  cin >> cx >> cy >> dx >> dy;

  vector<vector<char>> s(h, vector<char>(w));
  for(int i=0; i<h; i++) {
    string s_i;
    cin >> s_i;
    vector<char> s_c(s_i.begin(), s_i.end());
    s[i] = s_c;
  }

  vector<vector<int>> g(h, vector<int>(w, -1));
  int g_num = 0;
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      if(s[i][j] == '.' && g[i][j] == -1) {
        g[i][j] = g_num;
        queue<int> q;
        q.push(i * w + j);
        while(!q.empty()) {
          int itr = q.front();
          int itr_i = itr / w;
          int itr_j = itr % w;
          for(int k=itr_i-1; k<=itr_i+1; k++) {
            if(k >= 0 && k < h) {
              if(s[k][itr_j] == '.' && g[k][itr_j] == -1) {
                g[k][itr_j] = g_num;
                q.push(k * w + itr_j);
              }
            }
          }
          for(int k=itr_j-1; k<=itr_j+1; k++) {
            if(k >= 0 && k < w) {
              if(s[itr_i][k] == '.' && g[itr_i][k] == -1) {
                g[itr_i][k] = g_num;
                q.push(itr_i * w + k);
              }
            }
          }
          q.pop();
        }
        g_num++;
      }
    }
  }

  vector<vector<int>> m(g_num);
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      if(g[i][j] == -1) {
        continue;
      }
      int g_now = g[i][j];
      for(int k=i-2; k<=i+2; k++) {
        for(int l=j-2; l<=j+2; l++) {
          if(k >= 0 && k < h && l >= 0 && l < w) {
            if(g[k][l] != -1 && g[k][l] != g_now) {
              m[g_now].push_back(g[k][l]);
              m[g[k][l]].push_back(g_now);
            }
          }
        }
      }
    }
  }

  vector<int> ans(g_num, -1);
  ans[g[cx - 1][cy - 1]] = 0;
  queue<int> q_a;
  q_a.push(g[cx - 1][cy - 1]);
  while(!q_a.empty()) {
    int s = q_a.front();
    int size = m[s].size();
    for(int i=0; i<size; i++) {
      int t = m[s][i];
      if(ans[t] == -1) {
        ans[t] = ans[s] + 1;
        if(g[dx - 1][dy - 1] == i) {
          break;
        }
        q_a.push(t);
      }
    }
    q_a.pop();
  }

  co(ans[g[dx - 1][dy - 1]]);
}