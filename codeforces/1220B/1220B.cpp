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

const int MAXN = 1e3+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

int n;
ll maze[MAXN][MAXN];

int main()
{
	freopen("1220B.in", "r", stdin);
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++) 
			{
				scanf("%I64d", &maze[i][j]);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int k1, k2;
			k1 = i < n ? i+1 : i-2;
			k2 = i > 1 ? i-1 : i+2;
			//cout << i << " " << k1 << " " << k2 << endl;
			ll tmp = maze[i][k1]*maze[i][k2];
			tmp /= maze[k1][k2];
			tmp = sqrt(tmp);
			printf("%I64d ", tmp);
		}
		putchar('\n');
	}
	return 0;
}