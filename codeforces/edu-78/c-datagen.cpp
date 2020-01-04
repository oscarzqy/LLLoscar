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
    freopen("c.in", "w", stdout);
    int T = 10;
    int n = 15;
    srand(time(0));
    cout << T << endl;
    while(T--)
    {
        cout << n << endl;
        for (int i = 0; i < 2*n; i++)
        {
            int x = rand() % 2 + 1;
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}