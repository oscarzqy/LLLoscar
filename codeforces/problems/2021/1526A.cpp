#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;
int l[MAXN][2];
vector<int> g[MAXN];
int n;
long long dp[MAXN][2];
void dfs(int u, int fa) {
  dp[u][0] = dp[u][1] = 0;
  for (auto v : g[u]) {
    if (v == fa) {
      continue;
    }
    dfs(v, u);
    dp[u][0] += max(abs(l[u][0]-l[v][0])+dp[v][0], abs(l[u][0]-l[v][1])+dp[v][1]);
    dp[u][1] += max(abs(l[u][1]-l[v][0])+dp[v][0], abs(l[u][1]-l[v][1])+dp[v][1]);
  }
}
int main() {
  freopen("1526A.in", "r", stdin);
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      //cin >> l[i][0] >> l[i][1];
      scanf("%d%d", &l[i][0], &l[i][1]);
      g[i].clear();
    }
   for (int i = 0; i < n-1; ++i) {
      int u, v;
      //cin >> u >> v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1, -1);
    long long ans = max(dp[1][0], dp[1][1]);
    cout << ans << endl;
  }
  return 0;
}
