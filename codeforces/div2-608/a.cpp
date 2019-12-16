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

int main()
{
    freopen("a.in", "r", stdin);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int ans = 0;
    if (e > f)
    {
        int S1 = min(a, d);
        d -= S1;
        int S2 = min(d, min(b, c));
        ans = S1 * e + S2 * f;
    }
    else 
    {
        int S2 = min(d, min(b, c));
        d -= S2; 
        int S1 = min(a, d);
        ans = S1 * e + S2 * f;
    }
    cout << ans << endl;
    return 0;
}