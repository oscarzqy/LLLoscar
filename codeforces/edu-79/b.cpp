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

ll sum[MAXN], maxCost[MAXN];
int maxIndex[MAXN];
bool check(const int& num, const int& s)
{
    ll res = sum[num-1] - maxCost[num-1];
    return res <= s;
}
int main()
{
    freopen("b.in", "r", stdin);
    int T, n;
    ll s;
    cin >> T;
    memset(maxCost, -1, sizeof(maxCost));
    for (int cas = 1; cas <= T; cas++)
    {
        cin >> n >> s;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (i == 0)
            {
                sum[i] = x;
                maxCost[i] = x;
                maxIndex[i] = i;
            }
            else
            {
                sum[i] = sum[i-1] + x;
                if (maxCost[i-1] < x)
                {
                    maxCost[i] = x;
                    maxIndex[i] = i;
                }
                else 
                {
                    maxCost[i] = maxCost[i-1];
                    maxIndex[i] = maxIndex[i-1];
                }
            }
        }
        int left = 0, right = n;
        bool flag;
        while(left < right)
        {
            int mid = (left + right) >> 1;
            flag = check(mid, s);
            if (flag) left = mid+1;
            else right = mid;
        }
        flag = check(left, s);
        if (!flag) left--;
        if (!left) cout << 0 << endl;
        else if (sum[left-1] <= s) cout << 0 << endl;
        else cout << maxIndex[left-1]+1 << endl;
    }
    return 0;
}