#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  freopen("1542B.in", "r", stdin);
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    ll n, a, b;
    cin >> n >> a >> b;
    if (a == 1) {
      if ((n-1) % b == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      ll tmp = 1; 
      bool flag = false;
      while (tmp <= n) {
        if (tmp % b == n % b) {
          flag = true;
          break;
        } else {
          tmp *= a;
        }
      }
      if (flag) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
