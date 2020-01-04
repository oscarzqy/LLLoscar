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

int d[2] = {-1, 1};

map<int, int> dis;

int main()
{
    freopen("d.in", "r", stdin);
    dis.clear();
    int n, k;
    cin >> n >> k;
    queue<int> que; 
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dis[x] = 0;
        que.push(x);
    }
    int cnt = 0;
    ll ans = 0;
    vector<int> ansv;
    while(!que.empty())
    {
        int now = que.front();
        que.pop();
        if (dis[now])
        {
            ans += dis[now];
            ansv.pb(now);
            cnt++;
        }
        if (cnt == k) break;
        for (int i = 0; i < 2; i++)
        {
            int nx = now + d[i];
            if (!dis.count(nx))
            {
                dis[nx] = dis[now] + 1;
                que.push(nx);
            }
        }
    }
    cout << ans << endl;
    for (auto x : ansv)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}