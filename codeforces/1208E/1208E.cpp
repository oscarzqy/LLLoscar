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
typedef pair<ll, int> P;
const int MAXN = 1e6+7;
const int MAXV = 507;
const int MAXE = 507;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, w;
ll a[MAXN];
ll ans[MAXN];
namespace seg
{
	ll c[MAXN << 2];

	void pushUp(int root)
	{
		c[root] = max(c[lson(root)], c[rson(root)]);
	}

	void build(int root, int l, int r)
	{
		c[root] = 0;
		if (l == r)
		{
			c[root] = a[l];
			return ;
		}
		int mid = (l+r) >> 1;
		build(lson(root), l, mid);
		build(rson(root), mid+1, r);
		pushUp(root);
	}

	ll query(int root, int l, int r, int ql, int qr)
	{
		if (l > qr || r < ql) return -INF;
		if (l >= ql && r <= qr) return c[root];
		int mid = (l+r) >> 1;
		ll ret = -INF;
		if (mid >= ql) ret = query(lson(root), l, mid, ql, qr);
		if (mid < qr) ret = max(ret, query(rson(root), mid+1, r, ql, qr));
		return ret;
	}
}


namespace maxQueue
{
	P array[MAXN];
	int front = 0, tail = -1;
	bool isEmpty()
	{
		return front > tail;
	}
	void push(int idx, int lim, int len)
	{
		ll val = idx <= len ? a[idx] : 0;
		if (isEmpty()) 
		{
			array[++tail] = P(a[val], idx);
			return ;
		}
		while (tail >= front && (array[tail].fi <= val || array[tail].se < lim)) 
			tail--;
		array[++tail] = P(val, idx);
		while (front < tail && (array[front].fi <= val || array[front].se < lim))
			front++;
	}
	ll query()
	{
		if (!isEmpty()) 
		{
			return array[front].fi;
		}
	}
	void clear()
	{
		front = 0, tail = -1;
	}

}
int main()
{
	freopen("1208E.in", "r", stdin);
	int n, w;
	while (~scanf("%d%d", &n, &w))
	{
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= n; i++)
		{
			int len;
			scanf("%d", &len);
			maxQueue::clear();
			for (int j = 1; j <= len; j++) scanf("%I64d", &a[j]);
			if(len == w)
			{
				for (int j = 1; j <= len; j++) ans[j] += a[j];
				continue;
			}
			//for (int j = 1; j <= len; j++) cout << j << " " << a[j] << endl;
			//seg::build(1, 1, w);	
			else maxQueue::push(0, 0, len);
			for (int j = 1; j <= w; j++)
			{
				int l = max(0, j-(w-len)), r = j;
				maxQueue::push(j, l, len);
				ll tmp = maxQueue::query();
				ans[j] += tmp;
			}
		}
		for (int i = 1; i <= w; i++) printf("%I64d ", ans[i]);
		putchar('\n');
	}
	return 0;
}



