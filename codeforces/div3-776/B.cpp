#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("B.in", "r", stdin);
  int T;
  cin >> T;
  for (int cas = 0; cas < T; ++cas) {
    int l, r, a;
    cin >> l >> r >> a;
    int ans = r / a + r % a;
    int tmp = (r / a) * a - 1;
    if (tmp < l || tmp < 0) cout << ans << endl;
    else {
      ans = max(ans, tmp / a + tmp % a);
      cout <<ans << endl;
    }
  }
  return 0;
}
