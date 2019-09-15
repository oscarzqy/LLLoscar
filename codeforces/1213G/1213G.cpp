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

const int MAXN = 2e5+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

int n, m;
int par[MAXN];

int find(int x)
{
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

bool isSame(int x, int y)
{
	int px = find(x), py = find(y);
	return px == py;
}

void unite(int x, int y)
{
	int px = find(x), py = find(y);
	if (px == py) return ;
	par[px] = py;
}

struct Edge
{
	int u, v, cost;
	Edge () {}
	Edge (int u, int v, int cost) : u(u), v(v), cost(cost) {}
	bool operator < (Edge e) const
	{
		return cost < e.cost;
	}
}edge[MAXN];

int queryIdx[MAXN];
ll ans[MAXN];
ll cnt[MAXN];
bool vis[MAXN];
vector<int> qArray;
ll C2(ll x)
{
	return x*(x-1) / 2;
}
void solve()
{
	memset(vis, 0, sizeof(vis));
	sort(edge, edge+n-1);
	sort(qArray.begin(), qArray.end());
	int now = 0, j = 0, k = 0;
	ll res = 0;
	for (int i = 1; i <= n; i++) 
	{
		par[i] = i;
		cnt[i] = 1;
	}
	vector<ll> cv;
	int i;
	for (int j = 0; j < qArray.size(); j++)
	{
		for (i = k; i < n-1; i++)
		{
			if (edge[i].cost > qArray[j]) 
			{
				k = i;
				break;
			}
			//cout << i << endl;
			int u = edge[i].u, v = edge[i].v;
			int pu = find(u), pv = find(v);
			res = res - C2(cnt[pu]) - C2(cnt[pv]);
			ll tmp = cnt[pu] + cnt[pv];
			cnt[pu] = cnt[pv] = tmp;
			res += C2(tmp);
			unite(u, v);
		}
		k = i;//important espacially when i == n-1 but k dosen't change	
		//cout << qArray[j] << " " << res << endl;
		ans[qArray[j]] = res;
	}
	
	for (int i = 0; i < m; i++)
	{
		printf("%I64d ", ans[queryIdx[i]]);
	}
	putchar('\n');
}

int main()
{
	freopen("1213G.in", "r", stdin);
	while (cin >> n >> m)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n-1; i++)
		{
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			edge[i] = Edge(u, v, c);
		}
		for (int i = 0; i < m; i++)
		{
			int q;
			scanf("%d", &q);
			if (!vis[q])
			{
				vis[q] = true;
				qArray.pb(q);
			}
			queryIdx[i] = q;
		}
		solve();
	}
	return 0;
}



