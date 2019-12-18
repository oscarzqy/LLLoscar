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

//想清楚要控制的东西，与其控制维度，不如控制必经的点
//the solution of this problem is called "you must come through here" -必经之路法
//想了半天如何去在二维上去算最大重合
//实际上，只需要守株待兔
//assuming we school is located at (x, y), then you must pass through (x-1, y), (x, y+1), (x+1, y), (x, y-1)
int tentcnt[4] = {0};
int tentloc[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int main()
{
    freopen("c.in", "r", stdin);
    int n, sx, sy;
    cin >> n >> sx >> sy;
    memset(tentcnt, 0, sizeof(tentcnt));
    for (int i = 0; i < 4; i++)
    {
        tentloc[i][0] += sx;
        tentloc[i][1] += sy;
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x < sx) tentcnt[0]++;
        else if (x > sx) tentcnt[2]++;
        if (y < sy) tentcnt[3]++;
        else if (y > sy) tentcnt[1]++;
    }
    int maxIdx = 0, maxCnt = tentcnt[0];
    for (int i = 1; i < 4; i++)
    { 
        if (tentcnt[i] > maxCnt)
        {
            maxCnt = tentcnt[i];
            maxIdx = i;
        }
    }
    cout << maxCnt << endl;
    cout << tentloc[maxIdx][0] << " " << tentloc[maxIdx][1] << endl;
    return 0;
}