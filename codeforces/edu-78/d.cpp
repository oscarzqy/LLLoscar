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
const int MAXN = 2e6+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

//sweepline and "end-points-sort" problem

int par[MAXN];
int find(int x)
{
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool same(int x, int y)
{
    int px = find(x), py = find(y);
    return px == py;
}

void unite(int x, int y)
{
    int px = find(x), py = find(y);
    par[py] = px;
}


int loc[MAXN];
P p[MAXN], sweepLine[MAXN];
bool cmp(P& p1, P& p2)
{
    return p1.se < p2.se;
}
int main()
{
    freopen("d.in", "r", stdin);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) par[i] = i;
    memset(loc, -1, sizeof(loc));
    m = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].fi >> p[i].se;
        sweepLine[m++] = P(p[i].fi, i+1);
        sweepLine[m++] = P(p[i].se, i+1);
    }
    sort(sweepLine, sweepLine+m);
    set<P> s;
    int numberOfEdge = 0;
    for (int i = 0; i < m; i++)
    {
        P sl = sweepLine[i];
         
        if (s.count(sl)){
            s.erase(sl);
        }else{
            int idx = sl.se - 1;
            int endpos = p[idx].se; 
            for (auto it : s){
                if (it.fi > endpos) break;
                if (same(it.se, sl.se)){
                    //cout << it.se << " " << sl.se << endl;
                    cout << "NO" << endl;
                    return 0;
                }else{
                    numberOfEdge++; 
                    unite(it.se, sl.se);
                }
                if (numberOfEdge > n-1){
                    cout << "NO" << endl;
                    return 0;
                }
            }
            s.insert(P(p[idx].se, sl.se));
        }
    }
    //cout << numberOfEdge << endl;
    if (numberOfEdge == n-1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}



