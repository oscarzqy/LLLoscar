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
        int a[3];
        for (int j = 0; j < 3; j++)
        {
            cin >> a[j];
        }
        sort(a, a+3);
        if (a[2] > a[0]+a[1]+1) cout << "NO" << endl;
        else cout << "YES" << endl;
    } 
    return 0;
}