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


int bits[16] = {1, 1};
void init()
{
    for (int i = 2; i <= 10; i++)
    {
        bits[i] = bits[i-1] * 10;
    }
}
int numberOfBits(int x)
{
    int ret = 0;
    while(x)
    {
        ret ++;
        x /= 10;
    }
    return ret;
}


int main()
{
    freopen("a.in", "r", stdin);
    int t;
    cin >> t;
    init();
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        cin >> n;
        int numbers = numberOfBits(n);
        int highest = n / bits[numbers];
        int bigest = 0;
        for (int j = 1; j <= numbers; j++)
        {
            bigest += highest * bits[j];
        }
        int ans = (numbers-1) * 9 + (highest-1) + (n >= bigest ? 1 : 0);
        cout << ans << endl;
    }    
    return 0;
}