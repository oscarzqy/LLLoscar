#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("D.in", "r", stdin);
  int T;
  cin >> T;
  for (int cas = 0; cas < T; ++cas) {
    int n;
    cin >> n;
    vector<int> indices(n+1), a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      indices[a[i]] = i+1;
    }
    vector<int> ans(n+1, 0);
    for (int i = n; i >= 1; --i) {
      if (indices[i] == i) continue;
      ans[i] = indices[i];
      int offset = ans[i];
      for (int j = 1; j < i; ++j) {
        indices[j] = (indices[j] - offset + i) % i;
      }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
