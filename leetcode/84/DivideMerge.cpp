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
int heights[MAXN];
int ans = 0;

int solve(int start, int end)
{
	int minHeight = INF;
	if (end < start) return -INF;
	int minIndex = -1;
	for (int i = start; i <= end; i++)
	{
		if (minHeight > heights[i])
		{
			minHeight = heights[i];
			minIndex = i;
		}
	}
	return max(minHeight*(end-start+1), max(solve(minIndex+1, end), solve(start, minIndex-1)));
}

int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> heights[i];
	ans = solve(0, n-1);
	cout << ans << endl;
	return 0;
}

