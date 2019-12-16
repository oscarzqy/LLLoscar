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

int a[MAXN];

int main()
{
    freopen("c.in", "r", stdin);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        char str[MAXN];
        cin >> str;
        int len = strlen(str);
        int ans = 0;
        vector<int> ansv;
        memset(a, 0, sizeof(a));
        for (int i = 0; i+2 < len; i++)
        {
            if (str[i] == 'o' && str[i+1] == 'n' && str[i+2] == 'e')
            {
                for (int j = i; j <= i+2; j++) a[j] |= 1;
            }
            if (str[i] == 't' && str[i+1] == 'w' && str[i+2] == 'o')
            {
                for (int j = i; j <= i+2; j++) a[j] |= 2;
            }
            if (a[i] & 1 && a[i] & 2)
            {
                a[i] = 0;
                ans++;
                ansv.push_back(i+1);
            }
        }
/*        for (int i = 0; i < len; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
*/        for (int i = 0; i+2 < len; i++)
        {
            if ((a[i] & 1 && a[i+1] & 1 && a[i+2] & 1) || (a[i] & 2 && a[i+1] & 2 && a[i+2] & 2))
            {
                ans++;
                ansv.push_back(i+2+1);
                a[i+2] = 0;
            }
        }
        cout << ans << endl;
        for (int i = 0; i < ansv.size(); i++)
        {
            cout << ansv[i] << " ";
        }
        cout << endl;
    }
    return 0;
}