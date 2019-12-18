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

const int MAXN = 1e5+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

int n, k, num, rt;
int head[MAXN], cnt;
int sz[MAXN], childMaxSize[MAXN];
ll dis[MAXN];
bool vis[MAXN];

struct Edge
{
	int to, next;
	ll cost;
	Edge () {}
	Edge (int to, ll cost, int next) : to(to), cost(cost), next(next) {}
}edge[MAXN << 2];

void init()
{
	memset(head, -1, sizeof(head));
	memset(edge, -1, sizeof(edge));
	memset(sz, 0, sizeof(sz));
	memset(childMaxSize, 0, sizeof(childMaxSize));
	memset(vis, 0, sizeof(vis));
	num = 0;
	rt = 0;
	childMaxSize[0] = INF;
}

void Add(int from, int to, ll cost)
{
	edge[num] = Edge(to, cost, head[from]);
	head[from] = num++;
}

void findRt(int root, int fa)
{
	sz[root] = 1;
	for (int i = head[root]; i != -1; i = edge[i].next)
	{
		Edge e = edge[i];
		if (e.to == fa || vis[e.to]) continue;
		findRt(e.to, root);
		sz[root] += sz[e.to];
		childMaxSize[root] = max(childMaxSize[root], sz[e.to]);
	}
	childMaxSize[root] = max(childMaxSize[root], n-sz[root]); //fathers
	//cout << root << " " << childMaxSize[root] << endl;
	if (childMaxSize[root] < childMaxSize[rt]) 
	{
		rt = root;
	}
}

int p = 10;
int getDis(int u, int fa, ll nowDis)
{
	dis[cnt++] = nowDis;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		Edge e = edge[i];
		if (vis[e.to] || e.to == fa) continue;
		getDis(e.to, u, nowDis+e.cost);
	}
}

ll calc(int root, ll nowDis)
{
	cnt = 0;
	getDis(root, -1, nowDis);
	sort(dis, dis+cnt);	
	ll res = 0;
	for (int i = 0; i < cnt; i++)
	{
		int l = i, r = cnt-1;
		while (r > l)
		{
			int mid = (l+r) >> 1;
			if (dis[mid] + dis[0] <= k) l = mid+1;
			else r = mid; 
		}	
		res += l-i;
	}
	return res;
}
ll ans = 0;
void solve(int root)
{
	vis[root] = true;
	ans += calc(root, 0);
	//cout << ans << endl;
	for (int i = head[root]; i != -1; i = edge[i].next)
	{
		Edge e = edge[i];
		if (vis[e.to]) continue;
		cout << root << " " << e.to << " " << e.cost << " " << calc(e.to, e.cost) << endl;
		//for (int i = 0; i < cnt; i++) cout << dis[i] << endl;
		//return ;
		ans -= calc(e.to, e.cost);
		cout << ans << endl;
		rt = 0;
		findRt(e.to, -1);
		solve(rt);
	}
}

int main()
{
	freopen("poj1741.in", "r", stdin);
	while(~scanf("%d%d", &n, &k))
	{	
		if (!n && !k) break;
		init();
		for (int i = 0; i < n-1; i++)
		{
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			Add(u, v, c);
			Add(v, u, c);
		}
		findRt(1, -1);
		solve(rt);
		cout << ans << endl;
	}
	return 0;
}






