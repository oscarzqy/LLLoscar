#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#define pb push_back
#define fi first
#define se second
#define lson(r) (r<<1)
#define rson(r) ((r<<1)|1)
#define BLACK 1
#define WHITE 0
using namespace std;

typedef long long ll;

const int MAXN = 1e5+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

int main()
{
    freopen("d.in", "r", stdin);
    int n;
    cin >> n;
    ll cnt[2] = {0};
    int head = BLACK;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        int half = num >> 1;
        cnt[0] += half;
        cnt[1] += half;
        if (num & 1)
        {
            cnt[head]++;
        }
        //cout << num << " " << cnt[0] << " " << cnt[1] << endl;
        head = !head;
    }
    cout << min(cnt[0], cnt[1]) << endl;
    return 0;
}