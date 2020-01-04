#include <bits/stdc++.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#define pb push_back
#define fi first
#define se second
#define lson(r) (r<<1)
#define rson(r) ((r<<1)|1)
#define RED 1
#define BLUE 2
using namespace std;

typedef long long ll;

const int MAXN = 2e5+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

//bi search cannot do this thing.
//to expain it: 
//for example:
/*
4
1 1 2 2 2 2 1 1
*/
int row[MAXN];
int sumRed[MAXN], sumBlue[MAXN];
int n, blue = 0, red = 0;
bool check(int len, int mid)
{
    int leftBegin = max(0, n-len);
    int toEatRed = red - mid, toEatBlue = blue - mid;
    for (int l = leftBegin; l <= n && l+len-1 < 2*n; l++)
    {
        int eatBlue = sumBlue[l+len-1] - (l == 0 ? 0 : sumBlue[l-1]);
        int eatRed = sumRed[l+len-1] - (l == 0 ? 0 : sumRed[l-1]);
        // cout << l << " " << eatRed << " " << eatBlue << endl;
        if(eatRed == toEatRed && eatBlue == toEatBlue) return true;
    }
    return false;
}
int main()
{
    freopen("c.in", "r", stdin);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        int ans = 0;
        cin >> n;
        memset(sumRed, 0, sizeof(sumRed));
        memset(sumBlue, 0, sizeof(sumBlue));
        red = 0;
        blue = 0;
        for (int i = 0; i < 2*n; i++)
        {
            scanf("%d", &row[i]);
            if (row[i] == RED)
            {
                sumRed[i] = 1;
                red++;
            }
            else
            {
                sumBlue[i] = 1;
                blue++;
            }
            if (i == 0) continue;
            sumBlue[i] += sumBlue[i-1];
            sumRed[i] += sumRed[i-1];
        }
        //bisearch the how many jars should remain.
        int right = min(blue, red), left = 0;
        while(left < right)
        {
            int mid = (left+right) >> 1;
            int toEat = 2*n - 2*mid;
            bool flag = check(toEat, mid);
            cout << left << " " << right << " " << mid << " " << flag << " " << toEat << endl;
            if (flag) left = mid+1;
            else right = mid;
        }
        if (!check(2*n-2*left, left)) left--;
        cout << 2*n-2*left << endl;
    }
    return 0;
}
