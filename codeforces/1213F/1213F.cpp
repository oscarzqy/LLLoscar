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

int n, k;
int p[MAXN], q[MAXN];
int par[MAXN], offset[MAXN];
int find(int x)
{
	if (x != par[x]) return find(par[x]);
	return par[x];
}

bool isSame(int x, int y)
{
	int px = find(x), py = find(y);
	return px == py;
}

void unite(int x, int y)
{
	int px = find(x), py = find(y);
	par[px] = py;
}
char ans[MAXN];
bool vis[MAXN];
void solve()
{
	for (int i = 1; i <= n; i++) par[i] = i;
	set<int> setq, setp;
	int root = p[1];
	memset(offset, 0, sizeof(offset));
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = p[i], y = q[i];
		unite(x, root);
		unite(y, root);
		//cout << x << " " << y << " " << root << " " << find(x) << endl;
		if (!setp.erase(y)) setq.insert(y);
		if (!setq.erase(x)) setp.insert(x);
		if (setp.empty() && setq.empty()) root = p[i+1];
	}
	for (int i = 1; i <= n; i++)
	{
		int px = find(p[i]);
		if(!vis[px]) 
		{
			vis[px] = 1;
			offset[px] = cnt++;
		}
	}
	if (cnt < k) puts("NO");
	else 
	{
		puts("YES");
		for (int i = 1; i <= n; i++)
		{
			int px = find(p[i]);
			//cout << p[i] << " " << px << " " << offset[px] << endl;
			ans[p[i]-1] = 'a'+min(offset[px], k-1);
		}
		ans[n] = '\0';
		puts(ans);
	}

}
int main()
{
	freopen("1213F.in", "r", stdin);
	while(cin >> n >> k)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				if (!j) cin >> p[i];
				else cin >> q[i];
			}	
		}
		solve();
		//return 0;
	}
	return 0;
}