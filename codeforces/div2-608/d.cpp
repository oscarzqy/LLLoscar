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
const int MAXE = 3e5+7;
const int INF = 0x3f3f3f3f;
 
typedef pair<int, int> P;
bool vis[MAXN];
int need[MAXN], hire[MAXN], val[MAXN];
vector<int> portals[MAXN];
int dp[MAXN][MAXN];
int n, m, k;
P parr[MAXE];
bool cmp(int x, int y)
{
    return val[x] > val[y];
}

struct Node
{
    int pos, men, val;
    Node () {}
    Node(int _pos, int _men, int _val) : pos(_pos), men(_men), val(_val) {}
} ;
void solve(int& ans)
{
    queue<Node> que;
    que.push(Node(0, k, 0)); 
    while(!que.empty())
    {
        Node p = que.front();
        que.pop();
        int pos = p.pos, men = p.men, imp = p.val;
        if (dp[pos][men] > imp) continue;
        // cout << pos << " " << men << " " << dp[pos][men] << endl;
        int cnt = 0;
        if (pos > n)
        {
            ans = max(ans, imp);
            continue;
        }
        int tmp = 0;
        //dp[pos][men] = max(dp[pos][men], imp);
        int npos = pos+1;
        if (need[npos] > men) continue;
        if (imp > dp[npos][men+hire[npos]])
        {
            dp[npos][men+hire[npos]] = imp;
            que.push(Node(npos, men+hire[npos], imp));
        }
        for (int i = 0; i < portals[pos].size(); i++)
        {
            int leftMen = men - i - 1;
            int nmen = leftMen + hire[npos]; 
            if (leftMen < need[npos]) break;
            int sendTo = portals[pos][i];
            tmp += val[sendTo];
            if (imp + tmp > dp[npos][nmen])
            {
                dp[npos][nmen] = imp+tmp;
                que.push(Node(npos, nmen, dp[npos][nmen]));
            }
        }
    } 
}
int main()
{
    freopen("d.in", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &need[i], &hire[i], &val[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        parr[i] = P(u, v);
    }
    sort(parr, parr+m);
    for (int i = m-1; i >= 0; i--)
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
    for (int i = 0; i <= n; i++)
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