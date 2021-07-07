#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P=pair<ll, ll>;
const int MAXN = 1e5+7;

int n{};
P goods[MAXN];

int main() {
  freopen("1539D.in", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld",  &goods[i].first, &goods[i].second);   
  }
  sort(goods, goods+n, [](P &p1, P &p2) {
    if (p1.second == p2.second) {
      return p1.first < p2.first;
    }
    return p1.second < p2.second;
  });
  int p1 = 0, p2 = n-1;
  ll ans{}, cnt{};
  while (p1 <= p2) {
    while (p1 < p2 && goods[p1].second > cnt) {
      ll diff = min(goods[p2].first, goods[p1].second - cnt);
      goods[p2].first -= diff;
      cnt += diff;
      ans += diff * 2;
      if (!goods[p2].first) {
        p2--;
      }
    }
    if (p1 == p2) {
      ll no_discount = max(0LL, min(goods[p1].second - cnt, goods[p1].first));
      // no discount 
      cnt += no_discount;
      ans += no_discount * 2;
      goods[p1].first -= no_discount;
    }
    // have discount
    cnt += goods[p1].first;
    ans += goods[p1].first;
    goods[p1].first = 0;
    p1++;
  }
  // cout << p1 << " " << p2 << endl;
  // cout << n << endl;
  // for (int i = 0; i < n; ++i) {
  //  cout << goods[i].first << " " << goods[i].second << endl;
  //}
  cout << ans << endl;
  return 0;
}
