#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+3;
int a[MAXN];
int xors[MAXN];
int main() {

  freopen("1516B.in", "r", stdin);
  int T, n;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    // check two pieces
    int ans{};
    for (int i = 0; i < n; ++i) {
      ans ^= a[i]; 
    }
    if (!ans) {
      cout << "YES" << endl;
      continue; 
    }
    // check three pieces
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        xors[i] = a[i];
      } else {
        xors[i] = xors[i-1] ^ a[i];
      }
    }
    bool yes{};
    for (int i = 1; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        int x1 = xors[i-1];
        int x2 = xors[j-1] ^ x1;
        int x3 = xors[n-1] ^ xors[j-1];
        if (x1 == x2 && x1 == x3) {
          yes = true;
          break;
        }
      }
      if (yes) break;
    }
    if (yes) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
