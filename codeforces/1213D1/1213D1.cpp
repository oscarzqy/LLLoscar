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
int a[MAXN];
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
int main()
{
	freopen("1213D.in", "r", stdin);
	while(cin >> n >> k)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		sort(a+1, a+1+n);
		a[0] = 0;
		int ans = INF;
		for (int i = 0; i <= a[n]; i++)
		{
			int cnt = 0, tmp = 0;
			for (int j = 1; j <= n; j++)
			{
				int t = solve(a[j], i);
				if (t != -1)
				{
					cnt++;
					tmp += t;
				}
				if (cnt == k)
				{
					break;
				}
			}
			if (cnt == k) ans = min(tmp, ans);
		}
		cout << ans << endl;
	}
	return 0;
}