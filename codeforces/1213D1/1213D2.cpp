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

const int MAXN = 50+7;
const int MAXV = 2e5+7;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

int n, k;
int a[MAXV];
int cnt[MAXV], cost[MAXV], ans = INF;
bool vis[MAXV];
int solve(int x, int tar)
{
	int ret = 0;
	while (x != tar && x)
	{
		ret++;
		x /= 2;
	}
	if (x == tar) return ret;
	return -1;
}

void solve2()
{
	ans = INF;
	for (int i = 1; i <= n; i++)
	{
		int x = a[i];
		cnt[x]++;
		if (cnt[x] == k) ans = min(ans, cost[x]);
		int tmp = 0;
		while (x)
		{
			x /= 2;
			cnt[x]++;
			tmp++;
			cost[x] += tmp;
			if (cnt[x] == k) ans = min(ans, cost[x]);
		}
	}
	cout << ans << endl;
}
int main()
{
	freopen("1213D.in", "r", stdin);
	while(cin >> n >> k)
	{
		memset(cnt, 0, sizeof(cnt));
		memset(cost, 0, sizeof(cost));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		sort(a+1, a+1+n);
		solve2();
	}
	return 0;
}