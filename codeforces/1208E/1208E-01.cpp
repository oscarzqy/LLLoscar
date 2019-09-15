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
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll a[MAXN];
ll sum[MAXN];
int ml[MAXN], mr[MAXN];
int main()
{
	freopen("1208E.in", "r", stdin);
	int n, w;
	while(cin >> n >> w)
	{
		memset(sum, 0, sizeof(sum));
		while (n--)
		{
			int len;
			scanf("%d", &len);
			a[0] = a[len+1] = INF;
			stack<int> sl ,sr;
			for (int i = 1; i <= len; i++)
			{
				scanf("%I64d", &a[i]);
			}	
			//左边控制的是前一个数作用的范围
			sl.push(0);
			for (int i = 1; i <= len; i++)
			{
				while(a[i] >= a[sl.top()]) sl.pop();
				ml[i] = sl.top();
				sl.push(i);
			}
			//右边控制的本数作用的范围
			sr.push(len+1);
			for (int i = len; i >= 1; i--)
			{
				while(a[i] > a[sr.top()]) sr.pop();
				mr[i] = sr.top();
				sr.push(i);
			}
			//缩小范围
			for (int i = 1; i <= len; i++)
			{
				int l = i, r = w-len+i;
				if (ml[i]) l = max(l, w-len+ml[i]+1);
				if (mr[i] != len+1) r = min(r, mr[i]-1);
				if (a[i] < 0)
				{
					l = max(l, w-len+1);
					r = min(r, len);
				}
				if (r < l) continue;
				sum[l] += a[i];
				sum[r+1] -= a[i];
			}
		}
		for (int i = 2; i <= w; i++) sum[i] += sum[i-1];
		for (int i = 1; i <= w; i++) cout << sum[i] << " ";
		cout << endl;
	}
	return 0;
}