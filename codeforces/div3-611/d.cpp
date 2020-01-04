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
const int LIM = 2e9;


vector<int> trees;
bool check(int dis, int men)
{
    int len = trees.size();
    int pre = -LIM;
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        int crttree = trees[i];
        //int pretree = max(crttree-dis, i-1 >= 0 ? trees[i-1]+1 : -LIM);
        //int nxttree = min(crttree+dis, i+1 < len ? trees[i+1]-1 : LIM);
        int pretree = max(crttree - dis, pre+1);
        int nxttree = min(crttree+dis, i+1 < len ? trees[i+1]-1 : LIM);
        pre = nxttree;
        int tmp = crttree - pretree;
        tmp += nxttree - crttree;
        //cout << pretree << " " << crttree << " " << nxttree << " " << tmp << endl;
        res += tmp;
    }
    //cout << res << endl;
    return res >= men;
}
int main()
{
    freopen("d.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    trees.resize(n);
    for (int i = 0; i < n; i++) cin >> trees[i];
    sort(trees.begin(), trees.end());
    int l = 1, r = MAXN;
    //cout << check(2, m) << endl;
    //return 0;
    while(l < r)
    {
        int mid = (l+r) >> 1;
        bool flag = check(mid, m);
        if(flag) r = mid;
        else l = mid+1;   
    } 
    //cout << l << endl;
    int dis = l, len = trees.size();
    ll ans = 0;
    int pretree = -INF;
    vector<int> ansv;
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        int crttree = trees[i];
        //leftside
        for (int j = min(dis, crttree - pretree - 1); j > 0; j--)
        {
            if (pretree >= crttree - j) continue;
            ans += (ll)j;
           // cout << crttree << " " << j << endl;
            ansv.pb(crttree-j); 
            cnt++;
            if (cnt == m) break;
        }
        if (cnt == m) break;
        int nxttree = i+1 < len ? trees[i+1] : LIM;
        for(int j = 1; j <= dis; j++)
        {
            if (crttree + j >= nxttree) 
            {
                pretree = nxttree;
                break;
            }
           // cout << crttree << " " << j << endl;
            ans += min((ll)j, (ll)(nxttree-crttree-j));
            //ans += (ll)j;
            ansv.pb(crttree + j);
            cnt++;
            pretree = crttree + j;
            if (cnt == m) break; 
        }
        if (cnt == m) break;
    }
    cout << ans << endl;
    for (auto i : ansv) 
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


