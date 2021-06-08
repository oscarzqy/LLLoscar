#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e5+7;

int sa[MAXN], rk[MAXN];
int tmp[MAXN];
int buck[MAXN];

int main() {
  freopen("2_1.in", "r", stdin);
  string str;
  cin >> str;
  str.append("$");
  memset(buck, 0, sizeof(buck));
  int len = str.length(); 
  for (int i = 0; i < len; ++i) {
    sa[i] = i;
  }
  sort(sa, sa+len, [&str](int a, int b){
    return str[a] < str[b]; 
  });
  rk[sa[0]] = 0;
  for (int i = 1; i < len; ++i) {
    if (str[sa[i]] == str[sa[i-1]]) rk[sa[i]] = rk[sa[i-1]];
    else rk[sa[i]] = rk[sa[i-1]]+1;
  }
  for (int k = 1; k <= len; k <<= 1) {
    memset(buck, 0, sizeof(buck));
    for (int i = 0; i < len; ++i) {
      buck[rk[(sa[i]+k) % len]]++;
    }
    for (int i = 1; i < len; ++i) {
      buck[i] += buck[i-1];
    }
    for (int i = len-1; i >= 0; --i) {
      tmp[--buck[rk[(sa[i] + k) % len]]] = sa[i];
    }
    memcpy(sa, tmp, sizeof(int) * len);
    // first key
    memset(buck, 0, sizeof(buck));
    for (int i = 0; i < len; ++i) {
      buck[rk[sa[i]]]++;
    }
    for (int i = 0;  i < len; ++i) {
      buck[i] += buck[i-1];
    }
    for (int i = len-1; i >= 0; --i) {
      tmp[--buck[rk[sa[i]]]] = sa[i];
    }
    memcpy(sa, tmp, sizeof(int) * len);
    tmp[sa[0]] = 0;
    for (int i = 1; i < len; ++i) {
      if (rk[sa[i]] == rk[sa[i-1]] && rk[(sa[i]+k)%len] == rk[(sa[i-1]+k)%len]) tmp[sa[i]] = tmp[sa[i-1]];
      else tmp[sa[i]] = tmp[sa[i-1]] + 1;
    }
    memcpy(rk, tmp, sizeof(int) * len);
  }
  for (int i = 0; i < len; ++i) {
    cout << sa[i] << " ";
  }
  cout << endl;
  return 0;
}
