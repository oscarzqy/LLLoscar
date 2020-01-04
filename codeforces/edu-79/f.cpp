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
typedef pair<int, int> P;
const int MAXN = 1e6+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;


int n, k, l;
int a[MAXN];
char str[MAXN];
vector<P> dp;

//https://codeforces.com/blog/entry/72577
//
int getOpNums(int cost)
{
    dp.resize(n+1);
    for (int i = 1; i <= n; i++) dp[i] = P(INF, INF);
    dp[0] = P(0, 0);
    for (int i = 1; i <= n; i++)
    {
        //no operation
        if (dp[i].fi > dp[i-1].fi + a[i])
        {
            dp[i].fi = dp[i-1].fi + a[i];
            dp[i].se = dp[i-1].se; 
        }
        if (i-l >= 0 && dp[i].fi > dp[i-l].fi + cost)
        {
            dp[i].fi = dp[i-l].fi + cost;
            dp[i].se = dp[i-l].se + 1;
        }
    }
/*    for (int i = 0; i <= n; i++)
    {
        cout << i << " " << dp[i].fi << " " << dp[i].se << endl;
    }
*/    return dp[n].se;
}
int solve()
{
    int l = 0, r = n, mid;
    int tmp; 
    while(l < r)
    {
        mid = (l+r) >> 1;
        tmp = getOpNums(mid);
        //cout << l << " " << r << " " << mid << " " << tmp << endl;
        if (tmp > k) l = mid+1;
        else r = mid;
    }
    l--;
    tmp = getOpNums(l);
    if (tmp <= k) return 0;
    else 
    {
        l++;
        getOpNums(l);
        int ans = dp[n].fi - l*1ll*k;
        return ans;
    }
}

bool isUpperCase(char ch)
{
    if (ch >= 'A' && ch <= 'Z') return true;
    return false;
}
bool isLowerCase(char ch)
{
    if (ch >= 'a' && ch <= 'z') return true;
    return false;
}
int main()
{
    freopen("f.in", "r", stdin);
    cin >> n >> k >> l;
    cin >> str;
    int res, ans;
    a[0] = 0;
    //target is to trans every elem to lowercase;
    for (int i = 1; i <= n; i++)
    {
        a[i] = isUpperCase(str[i-1]); 
    }
    ans = solve();
    //target is to trans every elem to uppercase
    for (int i = 1; i <= n; i++)
    {
        a[i] = isLowerCase(str[i-1]);
    }
    res = solve();
    ans = min(ans, solve());
    cout << ans << endl;
    return 0;
}

