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


int solve(priority_queue<int>& que)
{
    int ret = 0;
    int cnt = 20;
    while(!que.empty())
    {
        int x = que.top();
        que.pop();
        while(!que.empty() && que.top() == x)
        {
            x = que.top();
            que.pop();
        }

        x >>= 1;
        if (!(x&1)) que.push(x);
        ret++;
    }
    cout << ret << endl;
    return ret;
}
int main()
{
    freopen("b.in", "r", stdin);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        int n;
        cin >> n;
        priority_queue<int> evenQueue;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (!(x & 1)) evenQueue.push(x);
        }
        solve(evenQueue);
    }   
    return 0;
}