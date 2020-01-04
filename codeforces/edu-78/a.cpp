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


int cnt[26], ncnt[26];

bool check(vector<char>& v)
{
    for (auto i : v)
    {
        int j = i - 'a';
        if (cnt[j] != ncnt[j]) return false;
    }
    return true;
}
int main()
{
    freopen("a.in", "r", stdin);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        string orgStr, hashStr;
        cin >> orgStr >> hashStr;
        memset(cnt, 0, sizeof(cnt));
        memset(ncnt, 0, sizeof(ncnt));
        int len1 = orgStr.length(), len2 = hashStr.length();
        if (len2 < len1)
        {
            puts("NO");
            continue;
        }
        vector<char> v;
        for (int i = 0; i < len1; i++)
        {
            char now = orgStr[i];
            if (!cnt[now-'a']) v.pb(now);
            cnt[now-'a']++;
        }
        for (int i = 0; i < len1; i++)
        {
            char now = hashStr[i];
            ncnt[now-'a']++;
        }
        if (check(v)) 
        {
            puts("YES");
            continue;
        }
        bool OK = false;
        for (int i = 0, j = len1; j < len2; j++, i++)
        {
            ncnt[hashStr[i]-'a']--;
            ncnt[hashStr[j]-'a']++;
            if (check(v))
            {
                OK = true;
                break;
            }
        }
        if (OK) puts("YES");
        else puts("NO");
    }
    return 0;
}


