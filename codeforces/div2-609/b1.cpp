/** Simplicity is the final achievement **/
 
#include <bits/stdc++.h>
#include <stdio.h>
#include <ext/pb_ds/assoc_container.hpp>
 
 
using namespace __gnu_pbds;
using namespace std;
 
 
const int N = 1e5+44;
const int P = (1 << 18);
const long long MD = 1e9 + 7;
 
long long n, m, t, k;
 
int mp[N];
 
#define int long long
 
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
 
map<int, int> a, b;
 
 
long long dis(int a, int b) {
    if (a > b) return m - a + b;
    else return b - a;
}
 
 
int32_t main() {
    // ios::sync_with_stdio(false);
    cin.tie(0);
    /** ONLY FOOLS RUSH IN **/
    cin >> n >> m;
 
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> t;
        b[t]++;
    }
 
    vector<PII> aa(a.size()), bb(b.size());
 
    int I = 0;
    for (auto x : a) aa[I++] = {x.second, x.first};
    I = 0;
    for (auto x : b) bb[I++] = {x.second, x.first};
 
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
 
    I = 1;
    for (int i = 1; i < (int)aa.size(); i++) {
        if (aa[i].first == aa[i-1].first) I++;
        else break;
    }
 
    // I = bb.size();
 
    for (int i = 0; i < I; i++) {
        bool is = 1;
        for (int j = 0; j < I; j++) {
            if (dis(aa[0].second, bb[i].second) != dis(aa[j].second, bb[(j + i) % I].second)) is = 0;
        }
        if (is) return cout << dis(aa[0].second, bb[i].second), 0;
    }
 
 
 
 
    return 0;
}