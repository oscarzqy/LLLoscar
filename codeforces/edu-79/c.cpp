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

int idx[MAXN];
int order[MAXN];
int main()
{
    freopen("c.in", "r", stdin);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            idx[x] = i;
        }
        int depest = -1;
        ll ans = 0;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            if (idx[x] < depest) // send directly for it has been reordered
            {
                ans++;
            }
            else 
            {
                ans += idx[x] - i; //take out
                ans += idx[x] - i - 1; // put it back
                depest = idx[x]; //reorder
            }
        }
        cout << ans << endl;
    }
    return 0;
}