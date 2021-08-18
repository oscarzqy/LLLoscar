#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e5+7;

int sa[MAXN], rk[MAXN], height[MAXN], tmp[MAXN];
int buck[MAXN];

void build(string &pattern, int len) { 
  for (int i = 0; i < len; ++i) {
    sa[i] = i;
  }
  sort(sa, sa+len, [&pattern](int a, int b){
    return pattern[a] < pattern[b];
  });
  rk[sa[0]] = 0;
  for (int i = 1; i < len; ++i) {
    if (pattern[sa[i]] == pattern[sa[i-1]]) rk[sa[i]] = rk[sa[i-1]];
    else rk[sa[i]] = rk[sa[i-1]] + 1;
  }

  for (int k = 1; k <= len; k <<= 1) {
    memset(buck, 0, sizeof(int) * len);
    for (int i = 0; i < len; ++i) buck[rk[i]]++;
    for (int i = 1; i < len; ++i) buck[i] += buck[i-1];
    for (int i = len-1; i >= 0; --i) {
      int nxt = (sa[i] + k) % len;
      tmp[--buck[rk[nxt]]] = sa[i];
    }
    memcpy(sa, tmp, sizeof(int) * len);
    memset(buck, 0, sizeof(int) * len);
    for (int i = 0; i < len; ++i) buck[rk[i]]++;
    for (int i = 1; i < len; ++i) buck[i] += buck[i-1];
    for (int i = len-1; i >= 0; --i) tmp[--buck[rk[sa[i]]]] = sa[i];
    memcpy(sa, tmp, sizeof(int) * len);
    tmp[sa[0]] = 0;
    for(int i = 1; i < len; ++i) {
      if(rk[sa[i]] == rk[sa[i-1]] && rk[(sa[i]+k)%len] == rk[(sa[i-1]+k)%len]) tmp[sa[i]] = tmp[sa[i-1]];
      else tmp[sa[i]] = tmp[sa[i-1]] + 1;
    }
    memcpy(rk, tmp, sizeof(int) * len);
  }
}

void buildLCP(string &str, int len) {
  int k = 0;
  memset(height, 0, sizeof(int) * len);
  for (int i = 0; i < len; ++i) { 
    if (k) k--;
    if (rk[i] == 0) continue;
    int sa1 = rk[i], sa0 = sa1-1;
    for (; k+sa[sa1] < len; ++k) {
      if (str[sa[sa1]+k] != str[sa[sa0]+k]) break; 
    }
    height[sa1] = k;
  }
}

int main() {
  freopen("4_1.in", "r", stdin);
  string str;
  cin >> str;
  str.append("$");
  int len = str.length();
  build(str, len);
  buildLCP(str, len);
  for (int i = 0; i < len; ++i) {
    cout << sa[i] << " ";
  }
  cout << endl;
  for (int i = 1; i < len; ++i) {
    cout << height[i] << " ";
  }
  cout << endl;
  return 0;
}
