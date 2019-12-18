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

ll getCnt(ll x)
{
    int ret = 0;
    while(x)
    {
        ret++;
        if (x & 1) x --;
        else x >>= 1;
    }
    return ret;
}
int main()
{
    freopen("e.in", "r", stdin);
    ll n, k;
    cin >> n >> k;
    ll left = 1, right = n;
    while(left < right)
    {
        ll mid = (left + right) >> 1;
        ll cnt = getCnt(mid);
        if (cnt > k)
        {
            right = mid;
        }
        else
        {
            left = mid+1;
        }
    }
    cout << left << endl;
    return 0;
}