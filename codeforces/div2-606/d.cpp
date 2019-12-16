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


char str[MAXN];

int main()
{
    freopen("d.in", "r", stdin);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        int n;
        cin >> n;
        vector<int> zo, oz;
        int oo = 0, zz = 0;
        int ozLen = oz.size(), zoLen = zo.size();
        vector<string> strV;
        for (int i = 1; i <= n; i++)
        {
            cin >> str;
            int len = strlen(str);
            if (str[0] == '0' && str[len-1] == '0') zz++;
            else if (str[0] == '1' && str[len-1] == '1') oo++;
            else if (str[0] == '0' && str[len-1] == '1') zo.pb(i);
            else oz.pb(i);
            strV.pb(str);
        }
        ozLen = oz.size(), zoLen = zo.size();
/*        cout << ozLen << endl;
        for (int i = 0; i < ozLen; i++) cout << strV[oz[i]-1] << endl;
        cout << zoLen << endl;
        for (int i = 0; i < zoLen; i++) cout << strV[zo[i]-1] << endl;
            return 0;
*/        if (!ozLen && !zoLen && oo && zz) cout << -1 << endl;
        else 
        {
            int d;
            vector<int> ansv;
            vector<int>& larger = oz;
            vector<int>& lesser = zo;
            map<string, bool> vis; 
            if (ozLen < zoLen)
            {
                swap(larger, lesser);
            }
            int lessLen = lesser.size(), largeLen = larger.size();
            d = (largeLen - lessLen) / 2;
            if (d < 1) cout << 0 << endl;
            else
            {
                for (auto i : lesser)
                {
                    //cout << i << " " << strV[i-1] << " hello" << endl;
                    vis[strV[i-1]] = true;
                }
                for (int j = 0; j < largeLen && ansv.size() < d; j++)
                {
                    string tmp = strV[larger[j]-1];
                    //cout << tmp << endl;
                    reverse(tmp.begin(), tmp.end());
                    if (vis[tmp]) continue;
                    ansv.pb(larger[j]);
                }
                if (ansv.size() < d) cout << -1 << endl;
                else 
                {
                    cout << d << endl;
                    for (auto i : ansv)
                    {
                        cout << i << " ";
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}