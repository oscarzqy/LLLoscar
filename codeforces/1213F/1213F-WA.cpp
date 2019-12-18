
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

int s[2][MAXN];
int idx[2][MAXN];
int par[MAXN], offset[MAXN];
int n, k;
bool vis[MAXN];
char ans[MAXN];
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

void solve()
{
	int dp[MAXN];
	for (int i = 1; i <= n; i++) 
	{
		par[i] = i;
		dp[i] = i;
	}
	queue<int> que;
	for (int i = 1; i <= n; i++)
	{
		que.push(s[0][i]);
	}
	while (!que.empty())
	{
		int now = que.front();
		que.pop();
		for (int j = idx[1][dp[now]]-1; j >= 1; j = idx[1][dp[s[1][j]]])
		{
			int val = s[1][j];
			if (idx[0][val] > idx[0][now])
			{
				dp[now] = val;
				unite(val, now);
				break;
			}
			else if (idx[0][val] > idx[0][find(now)])
			{
				dp[now] = val;
				unite(val, now);
				que.push(val);
				break;
			}
			else if (dp[val] == val) break;
		}
	}
	/*for (int i = 1; i <= n; i++)
	{
		//cout << idx[1][dp[s[0][i]]] << endl;
		for (int j = idx[1][dp[s[0][i]]]-1; j >= 1; j = idx[1][dp[s[1][j]]])
		{
			int now = s[0][i], val = s[1][j];		
			if (idx[0][val] > i || idx[0][val] > idx[0][find(now)]) //!!!!
			{
				//cout << now << " and " << val << endl;
				dp[now] = val;
				unite(val, now); //!!!!!
				break;
			}
			else if (dp[val] == val) break;
		}	
	}*/
	/*for (int i = 1; i <= n; i++)
	{
		int x = find(s[0][i]);
		cout << s[0][i] << " " << x << endl;
	} */
	//return ;
	memset(vis, 0, sizeof(vis));
	memset(offset, 0, sizeof(offset));
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int px = find(s[0][i]);
		if (!vis[px])
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
			int px = find(s[0][i]);
			ans[s[0][i]-1] = ('a'+min(offset[px], k-1));
		}
		ans[n] = '\0';
		puts(ans);
	}
}

int main()
{
	freopen("1213F.in", "r", stdin);
	while (cin >> n >> k)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> s[i][j];
			 	idx[i][s[i][j]] = j;
			}
		}
		solve();
		//return 0;
	}
	return 0;
}
