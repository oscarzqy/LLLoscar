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

const int MAXN = 1e6+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

int a[MAXN];
char str[MAXN];
bool isDel[MAXN];
/*
string s;
cin >> s;
vector<int> r;
for (string t: {"twone", "one", "two"}) {
    for (size_t pos = 0; (pos = s.find(t, pos)) != string::npos;) {
        s[pos + t.length() / 2] = '?';
        r.push_back(pos + t.length() / 2);
    }
}
cout << r.size() << endl;
for (auto rr: r)
    cout << rr + 1 << " ";
cout << endl;
*/
int main()
{
    freopen("c.in", "r", stdin);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        cin >> str;
        memset(isDel, 0, sizeof(isDel)); 
        int len = strlen(str);
        int ans = 0;
        vector<int> ansv;
        for (int i = 0; i+4 < len; i++)
        {
            vector<int> v;
            string tmp;
            for (int j = i; j < len && v.size() < 5; j++)
            {
                if (!isDel[j]) 
                {
                    v.pb(j);
                    tmp += str[j];
                }
            } 
            if (v.size() < 5) break;
            if (tmp == "twone")
            {
                ans++;
                ansv.pb(v[2]);
                isDel[v[2]] = true;
            }
        }
        for (int i = 0; i+2 < len; i++)
        {
            vector<int> v;
            string tmp;
            for (int j = i; j < len && v.size() < 3; j++)
            {
                if (!isDel[j])
                {
                    v.pb(j);
                    tmp += str[j];
                }
            }
            if(v.size() < 3) break;
            if (tmp == "one" || tmp == "two")
            {
                ans++;
                isDel[v[1]] = true;
                ansv.pb(v[1]);
            }
        }
        cout << ans << endl;
        for (auto i : ansv)
        {
            cout << i+1 << " ";
        }
        cout << endl;
    }
    return 0;
}