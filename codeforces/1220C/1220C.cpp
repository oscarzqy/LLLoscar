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

char s[MAXN];
char ans[2][20] = {"Ann","Mike"};
int main()
{
	freopen("1220C.in", "r", stdin);
	while (~scanf("%s", s))
	{
		int len = strlen(s);
		char nowMin = s[0], minIdx = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i] > nowMin) puts(ans[0]);
			else 
			{
				puts(ans[1]);
				nowMin = min(s[i], nowMin);
			}
		}
	}
	return 0;
}