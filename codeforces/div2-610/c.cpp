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

bool diff[MAXN];
int mand[MAXN];
vector<int> hardOne, easyOne;
int main()
{
    freopen("c.in", "r", stdin);
    int Cas;
    cin >> Cas;
    for (int cas = 1; cas <= Cas; cas++)
    {
        int n, T, a, b;
        cin >> n >> T >> a >> b;
        hardOne.clear();
        easyOne.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> diff[i];
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (diff[i]) hardOne.pb(x);
            else easyOne.pb(x);
        }
        sort(hardOne.begin(), hardOne.end());
        sort(easyOne.begin(), easyOne.end());
        int easyLen = easyOne.size(), hardLen = hardOne.size();
        int ans = 0; 
        int crtTime = 0;
        int hardp = 0, easyp = 0;
        int easyWait = 0, hardWait = 0; 
        int manProbs = 0;
        while(crtTime <= T)
        {
            cout << ans << " " << crtTime << endl;
            if (crtTime > T) break;
            ans += easyWait + hardWait;
            ans += manProbs;
            easyWait = 0;
            hardWait = 0;
            manProbs = 0;
            if (easyp == easyLen && hardp == hardLen) break;
            //add problems already mandatory
            while( (easyp < easyLen && easyOne[easyp] <= crtTime) || (hardp < hardLen && hardOne[hardp] <= crtTime) )
            {
                for (;easyp < easyLen && easyOne[easyp] <= crtTime; easyp++)
                {
                    manProbs++;
                    crtTime += a;
                }
                for (;hardp < hardLen && hardOne[hardp] <= crtTime; hardp++)
                {   
                    manProbs++;
                    crtTime += b;
                }
            }
            //cout << crtTime << endl;
            if (!manProbs) //can add arbitrary problem
            {
                //easy problem is priority
                if (easyp != easyLen)
                {
                    easyp++;
                    easyWait++;
                    crtTime += a;
                }
                else if (hardp != hardLen)
                {
                    hardp++;
                    hardWait++;
                    crtTime += b;
                }
            }
            while( (easyp < easyLen && easyOne[easyp] <= crtTime) || (hardp < hardLen && hardOne[hardp] <= crtTime) )
            {
                for (;easyp < easyLen && easyOne[easyp] <= crtTime; easyp++)
                {
                    manProbs++;
                    crtTime += a;
                }
                for (;hardp < hardLen && hardOne[hardp] <= crtTime; hardp++)
                {   
                    manProbs++;
                    crtTime += b;
                }
            }
        }
        cout << ans << endl;
    } 
    return 0;
}