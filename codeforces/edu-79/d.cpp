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
const ll MOD = 998244353;
 

/*
https://blog.csdn.net/liangzhaoyang1/article/details/56514028

求解 x模 m 同余的逆元 x-
即x*x- MOD m = (x/a) MOD
a 是除数, x-是模m的逆元

前提m是质数
由费马小定理：  x- = x^(m-2)

*/
ll myPow(ll x, int times)
{
    if (times == 0) return 1ll;
    ll tmp = 1ll;
    tmp = myPow(x, times >> 1);
    tmp = (tmp*tmp) % MOD; 
    if (times & 1) tmp = (tmp * x) % MOD;
    return tmp % MOD;
}
 
ll inv(ll x)
{
    ll res = myPow(x, MOD-2);
    return res;
}
 
int cnt[MAXN];
vector<int> v[MAXN];
ll invArr[MAXN];
int main()
{
   // freopen("d.in", "r", stdin);
    int n, k;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        v[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> v[i][j];
            cnt[v[i][j]]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < MAXN; i++) invArr[i] = inv(i);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            ll de = (invArr[n]*invArr[n]) % MOD;
            de = (de * invArr[v[i].size()]) % MOD;
            ll nu = cnt[v[i][j]];
            ans = (ans + ((de*nu) % MOD)) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}