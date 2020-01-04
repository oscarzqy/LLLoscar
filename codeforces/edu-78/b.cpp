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

bool check(ll mid, ll tar)
{
    ll sum = (1+mid) * mid / 2;
    if (sum >= tar) return true;
    return false;
}
ll getSum(ll x)
{
    return (1+x)*x/2;
}
int main()
{
    freopen("b.in", "r", stdin);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        ll a, b;
        cin >> a >> b;
        ll left = 0, right = 100000;
        ll tar = abs(b - a);
        while(left < right)
        {
            ll mid = (left + right) >> 1;
            bool flag = check(mid, tar);
            //cout << left << " " << right << " " << mid << " " << flag << endl; 
            if (flag) right = mid;
            else left = mid+1;
        }
        ll sum = getSum(left);
        while((sum-tar)&1)
        {
            left++;
            sum = getSum(left);
        }
        cout << left << endl; 
        //return 0;
    }
    return 0;
}