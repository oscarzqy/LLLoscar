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
typedef pair<int, int> Pii;
const int MAXN = 4e5+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;
int n;
Pii pa[MAXN];
vector<int> graph[MAXN];
int route[MAXN], idx[MAXN];
bool cmp(Pii p1, Pii p2)
{
	if (p1.fi != p2.fi) return p1.fi > p2.fi;
	return p1.se < p2.se;
}

void print(int root)
{
	queue<int> que;
	que.push(root);
	while (!que.empty())
	{
		int now = que.front();
		que.pop();
		for (int i = 0; i < graph[now].size(); i++)
		{
			que.push(graph[now][i]);
			cout << now << " " << graph[now][i] << endl;
		}
	}
}
void solve()
{
	for (int i = 1; i < n; i++)
	{
		Pii p = pa[i];
		graph[p.se].pb(pa[i+1].se);
		route[i] = pa[i].se;
		idx[pa[i].se] = i;
	}
	route[n] = pa[n].se;
	idx[pa[n].se] = n;
	int maxLen = n;
	for (int i = 1; i <= n; i++)
	{
		int waitNode = pa[i].se+1, nowNode = pa[i].se;
		int id = idx[nowNode], nid = id + pa[i].fi - 1;
		if (nid == maxLen)
		{
			maxLen++;
			idx[waitNode] = maxLen;
			route[maxLen] = waitNode;
		}
		int node = route[nid];
		graph[node].pb(waitNode);
	}
	//return ;
	print(pa[1].se);

}
int main()
{
	freopen("1214E.in", "r", stdin);
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++) 
		{
			graph[2*i-1].clear();
			graph[2*i].clear();
			scanf("%d", &pa[i].fi);
			pa[i].se = 2*i-1;
		}
		sort(pa+1, pa+1+n, cmp);
		solve();
	}	
	return 0;
}