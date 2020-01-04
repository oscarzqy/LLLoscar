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

const int MAXN = 2e5+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

int ans[MAXN];
unordered_set<int> us;

//first set those numbers that maybe sent to onesself
bool cmp(int a, int b)
{
    if (us.count(a) != us.count(b)) return us.count(a) > us.count(b);
    else return a > b;
}
int main()
{
    freopen("c.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> v;
    us.clear(); 
    for(int i = 1; i <= n; i++)
    {
        us.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans[i] = x;
        if (!x) v.pb(i);
        else us.erase(x);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        int pos = v[i];
        for (auto j : us)
        {
            if (j != pos)
            {
                ans[pos] = j;
                us.erase(j);
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}