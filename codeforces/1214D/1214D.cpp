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

const int MAXN = 1e6+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;
int n, m;
int d[2][2] = {0, 1, 1, 0};

char maze[MAXN];
bool vis[MAXN];
int passed[MAXN];
int cnt[MAXN];
bool OK(int x, int y)
{
	int idx = x*m+y;
	if (x >= n || x < 0 || y >= m || y < 0) return false;
	if (maze[idx] == '#') return false;
	return true;
}

bool dfs(int x, int y)
{
	int idx = x*m+y;
	if (passed[idx] != -1) return passed[idx];
	if (x == n-1 && y == m-1) return true;
	vis[idx] = true;
	bool ret = false;
	for (int i = 0; i < 2; i++)
	{
		int nx = x + d[i][0], ny = y + d[i][1];
		if (OK(nx, ny))
		{
			ret |= dfs(nx, ny);
		}
	}
	passed[idx] = ret;
	if (!ret) maze[idx] = '#';
	return ret;
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << maze[i*m+j];
		}
		cout << endl;
	}
}
int main()
{
	freopen("1214D.in", "r", stdin);
	while(~scanf("%d%d", &n, &m))
	{
		memset(cnt, 0, sizeof(cnt));
		memset(passed, -1, sizeof(passed));
		getchar();
		for (int i = 0; i < n; i++)
		{
			int rowNum = i*m;
			for (int j = 0; j < m; j++)
			{
				char ch = getchar();
				maze[rowNum+j] = ch;
			}
			getchar();
		}
		if (!dfs(0, 0))
		{
			puts("0");
		}
		else 
		{
			for (int i = 1; i < n*m-1; i++) 
			{
				if (!vis[i]) maze[i] = '#';
			}
			//print();
			for (int i = 1; i < n*m-1; i++)
			{
				int x = i / m, y = i % m;
				int dis = x+y;
				//cout << x << "," << y << " " << dis << " " << maze[i] << endl;
				if (maze[i] == '.')
				{
					cnt[dis]++;
				}
			}	
			int ans = INF;
			for (int i = 1; i < n+m-2; i++)
			{
				//cout << i << " " << cnt[i] << endl;
				ans = min(ans, cnt[i]);
			}
			printf("%d\n", ans);
		}
		return 0;
	}
	return 0;
}
