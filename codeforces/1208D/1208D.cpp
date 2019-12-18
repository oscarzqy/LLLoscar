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
typedef pair<ll, ll> P; 

const int MAXN = 2e5+7;
const int MAXV = 507;
const int MAXE = 507;
const ll INF = 0x3f3f3f3f3f3f3f3f;

P p[MAXN];
P c[MAXN << 2];

ll lazy[MAXN];

void pushUp(int root)
{
    P tp1 = c[root<<1];
    P tp2 = c[root<<1|1];
    if (tp1.fi < tp2.fi) c[root] = tp1;
    else if (tp1.fi > tp2.fi) c[root] = tp2;
    else if (tp1.se > tp2.se) c[root] = tp1;
    else c[root] = tp2;
}

void pushDown(int root)
{
    ll val = lazy[root];
    if (val)
    {
        c[root<<1].fi += val;
        c[root<<1|1].fi += val;
        lazy[root<<1] += val;
        lazy[root<<1|1] += val;
        lazy[root] = 0;
    }
}

void build(int root, int l, int r)
{
    lazy[root] = 0;
    c[root] = P(INF, INF);
    if (l == r) 
    {
        c[root] = p[l];
        return ;
    }
    int mid = (l+r) >> 1;
    build(root << 1, l, mid);
    build(root << 1 | 1, mid+1, r);
    pushUp(root);    
}

P query(int root, int l, int r, int ql, int qr)
{
    if (qr < l || ql > r) return P(INF, INF);
    if (l >= ql && r <= qr) return c[root];
    pushDown(root); 
    int mid = (l+r) >> 1;
    P tp1 = query(root<<1, l, mid, ql, qr);
    P tp2 = query(root<<1|1, mid+1, r, ql, qr);
    P ret;
    if (tp1.fi < tp2.fi) ret = tp1;
    else if (tp1.fi > tp2.fi) ret = tp2;
    else if (tp1.se > tp2.se) ret = tp1;
    else ret = tp2;
    return ret;
}

void update_single(int root, int l, int r, int pos)
{
    if (r < pos || l > pos) return ;
    if (l == r) 
    {
        c[root] = p[l];    
        return ;
    }
    pushDown(root);
    int mid = (l+r) >> 1;
    update_single(root << 1, l, mid, pos);
    update_single(root<<1|1, mid+1, r, pos);
    pushUp(root);
}

void update(int root, int l, int r, int ul, int ur, int val)
{
    if (l > ur || r < ul) return ;
    if (l >= ul && r <= ur)
    {
        lazy[root] += val;
        c[root].fi += val;
        return ;
    }
    pushDown(root);
    int mid = (l+r) >> 1;
    update(root<<1, l, mid, ul, ur, val);
    update(root<<1|1, mid+1, r, ul, ur, val);
    pushUp(root);
}

int ans[MAXN];


void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        P t = query(1, 1, n, i, i);
        cout << "(" << (t.fi>1000?-1:t.fi) << "," << (t.se>1000?-1:t.se) << ") ";
    }
    cout << endl;
}

int main()
{
    freopen("1208D.in", "r", stdin);
    int n;
    while (cin >> n)
    {
        memset(c, 0x3f, sizeof(c));
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i].fi;
            p[i].se = i;
        }
        build(1, 1, n);
        //print(n);
        for (int i = 1; i <= n; i++)
        {
            P t = query(1, 1, n, 1, n);
            int pos = t.se;
            //cout << pos << endl;
            ans[pos] = i;
            p[pos] = P(INF, INF);
            update_single(1, 1, n, pos);
            update(1, 1, n, pos+1, n, -i);
            //print(n);
        }   
        //return 0;    
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
        /*
        for (int i = 1; i <= 4*n; i++) cout << i << " " << lazy[i] << endl;
        cout << endl;
        */
    }    
    return 0;
}
//mine 2 1 15 8 12 3 6 13 14 9 10 5 4 7 11 
//jury's 2 1 15 10 12 3 6 13 14 8 9 5 4 7 11