#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#define pb push_back
#define fi first
#define se second
#define lson(r) (r<<1)
#define rson(r) ((r<<1)|1)
 
using namespace std;
 
typedef long long ll;
 
const int MAXN = 5007;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;
 
typedef pair<int, int> P;
bool vis[MAXN];
int need[MAXN], hire[MAXN], val[MAXN];
vector<int> portals[MAXN];
int dp[MAXN][MAXN];
int n, m, k;
bool cmp(int x, int y)
{
    return val[x] > val[y];
}
 
void solve(int& ans)
{
    queue<P> que;
    que.push(P(0, k));
    while(!que.empty())
    {
        P p = que.front();
        que.pop();
        //  cout << p.fi << " " << p.se << " " << dp[p.fi][p.se] << endl;
        if (p.fi > n) 
        {
            ans = max(ans, dp[p.fi][p.se]);
            continue;
        }
        int nx = p.fi + 1, ny = p.se + hire[p.fi];
        int tmp = 0;
        if (p.se >= need[nx])
        {
            dp[nx][ny] = dp[p.fi][p.se];
            que.push(P(nx, ny));
        }
        for (auto i : portals[p.fi])
        {
            p.se--;
            if (p.se < need[nx]) break;
            tmp += val[i];
            dp[nx][ny] = dp[p.fi][p.se] + tmp;
            que.push(P(nx, ny));
        }
    } 
}
int main()
{
    freopen("d.in", "r", stdin);
    P parr[MAXN];
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> need[i] >> hire[i] >> val[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        parr[i] = P(u, v);
    }
    sort(parr, parr+n);
    for (int i = n-1; i >= 0; i--)
    {
        int u = parr[i].fi, v = parr[i].se;
        if (vis[v]) continue;
        vis[v] = true;
        portals[u].pb(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) portals[i].pb(i);
    }
    for (int i = 0; i < n; i++)
    {
        sort(portals[i].begin(), portals[i].end(), cmp);
    }
    memset(dp, -1, sizeof(dp));
    int ans = -1;
    dp[0][k] = 0;
    solve(ans); 
    cout << ans << endl;
    return 0;
}