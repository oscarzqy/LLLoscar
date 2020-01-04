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
typedef pair<int, int> P;
const int MAXN = 5e5+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

vector<int> graph[MAXN];
P p[MAXN];
int num;

//之前用p来判断，还超时了
void dfs(int u, int f)
{
    //cout << u << endl;
    for (auto v : graph[u])
    {
        if (v == f) continue;
        p[v].fi = ++num;
    }
    p[u].se = ++num;
    for (int i  = graph[u].size()-1; i >= 0; i--)
    {
        int v = graph[u][i];
        if (v == f) continue;
        dfs(v, u);
    }
}

int main()
{
    freopen("e.in", "r", stdin);
    int n;
    memset(p, -1, sizeof(p)); 
    num = 0;
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        //small point to big
        graph[u].pb(v);
        graph[v].pb(u);
    }
    p[1].fi = ++num;
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", p[i].fi, p[i].se);
    }
    return 0;
}