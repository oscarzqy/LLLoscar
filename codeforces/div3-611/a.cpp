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
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        int h, m;
        cin >> h >> m;
        if (h == 0&& m == 0) cout << 0 << endl;
        else
        {
            int dh = 24 - h - 1;
            int ans = 60 - m;
            ans += dh*60;
            cout << ans << endl;
        }        
    }
    return 0;
}