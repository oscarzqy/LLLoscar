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
    freopen("b.in", "r", stdin);
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas++)
    {
        int n, k;
        int ans = 0; 
        cin >> n >> k;
        int res = n / k;
        int rem = n % k;
        ans = res * k;
        if (rem > k/2) ans += k/2;
        else ans += rem;
        cout << ans << endl; 
    }
    return 0;
}