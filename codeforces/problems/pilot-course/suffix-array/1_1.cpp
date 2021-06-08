#include <bits/stdc++.h>

const int MAXN = 1e5+7;

char sa[MAXN];
int rk0[MAXN], rk1[MAXN];
int p[MAXN];

using namespace std;

int main() {
  freopen("1_1.in", "r", stdin);
  string str;
  cin >> str;
  str.append("$");
  int len = str.length();
  for (int i = 0; i < len; ++i) {
    p[i] = i;
  }
  sort(p, p+len, [&str](int a, int b) {
    return str[a] < str[b]; 
  });
  rk0[p[0]] = 0;
  for (int i = 1; i < len; ++i) {
    if (str[p[i]] == str[p[i-1]]) rk0[p[i]] = rk0[p[i-1]];
    else rk0[p[i]] = rk0[p[i-1]] + 1;
  }
  for (int k = 1;; k <<= 1) {
    sort(p, p+len, [k, len](int a, int b) {
      if (rk0[a] != rk0[b]) return rk0[a] < rk0[b];
      return rk0[(a+k)%len] < rk0[(b+k)%len];
    });
    rk1[p[0]] = 0;
    for (int i = 1; i < len; ++i) {
      if (rk0[p[i]] == rk0[p[i-1]] && rk0[(p[i]+k)%len] == rk0[(p[i-1]+k)%len]) {
        rk1[p[i]] = rk1[p[i-1]];
      } else {
        rk1[p[i]] = rk1[p[i-1]] + 1;
      }
    }
    memcpy(rk0, rk1, sizeof(int) * len);
    if (2*k >= len) break;
  }
  for (int i = 0; i < len; ++i) {
    cout << p[i] << " ";
  }
  cout << endl;
  return 0;

}
