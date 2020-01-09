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

const int MAXN = 250007;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;
ll MOD; 
ll fac[MAXN];

void init()
{
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fac[i] = (fac[i-1] * 1ll * i) % MOD;
    }
}

/*
for i = 1 to len
求长度为i的pair(j, j+i-1)的贡献
pair的个数为n-i+1....确定最小几种的就确定了个数
pair内全排列 i!
将pair视为一个整体和其余的数 全排列(n-i+1)!
*/
int main()
{
    freopen("c.in", "r", stdin);
    int n;
    cin >> n >> MOD;
    init();
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + (n-i+1) * (fac[i] * fac[n-i+1] % MOD) ) % MOD;
    }
    cout << ans << endl;
    return 0;
}