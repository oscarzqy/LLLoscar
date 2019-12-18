#include <string.h>
#include <iostream>
#include <cstdio>
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

ll a[MAXN];

namespace seg
{
	ll c[MAXN << 2];
	ll addmark[MAXN << 2];
	void pushUp(int root)
	{
		c[root] = c[lson(root)] + c[rson(root)];
	}

	void pushDonw(int root, int l, int r)
	{
		ll val = addmark[root];
		ll mid = (l+r) >> 1;
		if (val)
		{
			c[lson(root)] += (mid-l+1) * val;
			c[rson(root)] += (r-mid) * val;
			addmark[lson(root)] += val;
			addmark[rson(root)] += val;
			addmark[root] = 0;
		}
	}

	void build(int root, int l, int r)
	{
		addmark[root] = 0;
		if (l == r) 
		{
			c[root] = a[l];
			return ;
		}
		int mid = (l+r) >> 1;
		build(lson(root), l, mid);
		build(rson(root), mid+1, r);
		pushUp(root);
	};

	void update(int root, int l, int r, int ul, int ur, ll addval)
	{
 		if (l > ur || r < ul) return ;
		if (l >= ul && r <= ur)
		{
			c[root] += addval*(r-l+1);
			addmark[root] += addval;
			return ;
		}
		pushDonw(root, l, r);
		int mid = (l+r) >> 1;
		if (mid >= ul) update(lson(root), l, mid, ul, ur, addval);
		if (mid < ur) update(rson(root), mid+1, r, ul, ur, addval);
		pushUp(root);
	}

	ll query(int root, int l, int r, int ql, int qr)
	{
		if (l > qr || r < ql) return 0;
		if (l >= ql && r <= qr) return c[root];
		pushDonw(root, l, r);
		int mid = (l+r) >> 1;
		ll sum = 0;
		if (mid >= ql) sum += query( lson(root), l, mid, ql, qr);
		if (mid < qr) sum += query(rson(root), mid+1, r, ql, qr);
		return sum;
	}
}


int main()
{
	freopen("poj3468.in", "r", stdin);
	int n, q;
	while(~scanf("%d%d", &n, &q))
	{
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		seg::build(1, 1, n);
		for (int i = 0; i < q; i++)
		{
			char ch[32];
			int l, r;
			ll val;
			scanf("%s%d%d", ch, &l, &r);
			//cout << ch << " " << l << " " << r << endl;
			if (ch[0] == 'Q')
			{
				ll ans = seg::query(1, 1, n, l, r);
				printf("%lld\n", ans);
			}
			else 
			{
				scanf("%lld", &val);
				seg::update(1, 1, n, l, r, val);
			}
		}
	}
	return 0;
}


