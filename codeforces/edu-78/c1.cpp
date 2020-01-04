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
#define BLACK 2
using namespace std;

typedef long long ll;

const int MAXN = 2e5+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;
int n;

int row[MAXN];
unordered_map<int, int> ump;

int main()
{
    freopen("c.in", "r", stdin);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        cin >> n;
        ump.clear();
        //this initialization when you don't have to eat from left.
        ump[0] = n;
        int sumBlack = 0, sumRed = 0, tmp = 0, tar = 0, ans = 2*n;
        for (int i = 0; i < 2*n; i++)
        {
            cin >> row[i]; 
            if (row[i] == BLACK) sumBlack++;
            else sumRed++;
        } 
        for (int i = n-1; i >= 0; i--)
        {
            if (row[i] == BLACK)
            {
                tmp++;
            }
            else if (row[i] == RED)
            {
                tmp--;
            }
            if (ump.find(tmp) == ump.end())
            {
                ump[tmp] = i;
            }
         //   cout << tmp << " ";
        }
        //cout << ";";
        tmp = 0;
        tar = sumBlack - sumRed;

        //the same when you don't have to eat to the right
        int d = tar - tmp;
        if (ump.find(d) != ump.end())
        {
            int p = ump[d];
            ans = min(ans, n-p);
        }
        for (int i = n; i < 2*n; i++)
        {
            if (row[i] == BLACK) tmp++;
            else tmp--;
         //   cout << tmp << " ";
            int d = tar - tmp, pos;
            if (ump.find(d) == ump.end()) continue;
            else pos = ump[d];
            ans = min(ans, i-pos+1);
        }
        //cout << endl;
        //cout << tar << endl;
        cout << ans << endl;        
    };
    return 0;
}

