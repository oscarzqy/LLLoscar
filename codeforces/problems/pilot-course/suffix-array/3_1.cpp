#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 7;

int sa[MAXN], tmp[MAXN], rk[MAXN];
int buck[MAXN];

void build(string &str, int len) {
  memset(buck, 0, sizeof(buck));
  for (int i = 0; i < len; ++i) sa[i] = i;
  sort(sa, sa+len, [&str](int a, int b){
    return str[a] < str[b];
  });
  rk[sa[0]] = 0;
  for (int i = 1; i < len; ++i) {
    if (str[sa[i]] == str[sa[i-1]]) rk[sa[i]] = rk[sa[i-1]];
    else rk[sa[i]] = rk[sa[i-1]]+1;
  }
  for (int k = 1; k <= len; k <<= 1) {
    memset(buck, 0, sizeof(int) * len);
    for (int i = 0; i < len; ++i) {
      buck[rk[i]]++;
    }
    for (int i = 1; i < len; ++i) {
      buck[i] += buck[i-1];
    }
    for (int i = len-1; i >= 0; --i) {
      int nxt = (sa[i] + k) % len;
      tmp[--buck[rk[nxt]]] = sa[i];
    }
    memcpy(sa, tmp, sizeof(int) * len);
    memset(buck, 0, sizeof(int) * len);
    for (int i = 0; i < len; ++i) {
      buck[rk[i]]++;
    }
    for (int i = 1; i < len; ++i) {
      buck[i] += buck[i-1];
    }
    for (int i = len-1; i >= 0; --i) {
      int cur = sa[i];
      tmp[--buck[rk[cur]]] = sa[i];
    }
    memcpy(sa, tmp, sizeof(int) * len);
    tmp[sa[0]] = 0;  
    for (int i = 1; i < len; ++i) {
      int cur = sa[i];
      int nxt = (sa[i] + k) % len;
      if (rk[cur] == rk[sa[i-1]] && rk[nxt] == rk[(sa[i-1] + k) % len]) {
        tmp[sa[i]] = tmp[sa[i-1]];
      } else {
        tmp[sa[i]] = tmp[sa[i-1]] + 1;
      }
    }
    memcpy(rk, tmp, sizeof(int) * len);
  }
}

int compare(string &pattern, string &match, int idx) {
  int len = match.length();
  int mod = pattern.length();
  for (int i = 0; i < len; ++i) {
    if (pattern[(idx+i)%mod] < match[i]) {
      return -1;
    } else if (pattern[(idx+i)%mod] > match[i]) {
      return 1;
    }
  }
  return 0;
}

bool solve(string &pattern, string &match) {
  int len = pattern.length();
  int l = 0, r = len-1;
  while (l < r) {
    int mid = (l+r) >> 1;
    int comp_res = compare(pattern, match, sa[mid]);
    if (comp_res < 0) {
      l = mid+1;
    } else {
      r = mid;
    }
    // cout << mid << " " << comp_res << endl;
  }
  return compare(pattern, match, sa[l]) == 0;
}

int main() {
  freopen("3_1.in", "r" ,stdin);
  string str;
  cin >> str;
  str.append("$");
  int len = str.length();
  build(str, len);
  int n;
  cin >> n;
  for (int cas = 1; cas <= n; ++cas) {
    string match;
    cin >> match;
    if (solve(str, match)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
