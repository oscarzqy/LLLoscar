#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#define pb push_back
#define CLR(a) memset(a, 0, sizeof(a));
#define MEM(a, b) memset(a, b, sizeof(a));
#define fi first
#define se second
#define lson (crt<<1)
#define rson ((crt<<1)|1)
 
using namespace std;
 
typedef long long ll;
 
const int MAXN = 5007;
const int MAXV = 207;
const int MAXE = 207;
const int INF = 0x3f3f3f3f;
 
map<int, int> a, b;
vector<int> av, bv;
int n, m;
 
bool check(int addVal, int pos, int len)
{
    for (int i = 0; i < len; i++)
    {
        int now = av[i];
        int x = (now + addVal)%m;
        if (b.find(x) == b.end() || b[x] != a[now]) return false;
    }
    return true;
} 
int main()
{
    freopen("b.in", "r", stdin);
    a.clear();
    b.clear();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b[x]++;
    }
    for (auto i : a)
    {
        av.pb(i.fi);
    }
    for (auto i : b)
    {
        bv.pb(i.fi);
    }
    int len = av.size();
    int ans = INF;
    for (int i = 0; i < len; i++)
    {
        //cout << a[av[0]] << " " << b[bv[i]] << endl;
        if (a[av[0]] != b[bv[i]]) continue;
        int addVal = (av[0]-bv[i]+m)%m; 
        //if (addVal < 0) addVal*=-1;
        bool f1 = check(addVal, i, len);
        //cout << addVal << " " << f1 << ";";
        if (f1) ans = min(ans, addVal);
        addVal = (bv[i]-av[0]+m)%m;
        //if (addVal < 0) addVal*=-1;
        bool f2 = check(addVal, i, len);
        //cout << addVal << " " << f2 << endl;
        if (f2) ans = min(ans, addVal);
    }
    cout << ans << endl;
    return 0;
}