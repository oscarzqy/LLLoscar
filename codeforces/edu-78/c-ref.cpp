#include<bits/stdc++.h>
 
using namespace std;
 
 
 
#ifndef ONLINE_JUDGE
 
#include <chrono>
 
using namespace std::chrono;
 
#endif
 
 
 
typedef long long ll;
 
const int maxn = 2e5 + 7;
 
const int mod  = 1e9 + 7;
 
 
 
int n, a[maxn * 2];
 
void solve()
 
{
 
    int cnt = 0;
 
    unordered_map<int, int> M; M.clear();
 
    for (int i = 1; i <= n; ++i) {
 
        if (a[i] == 1) cnt++;
 
        else cnt--;
 
        M[cnt] = i;
 
    }
 
    int ans = 2 * n;
 
    if (M.count(0)) ans = min(ans, n - M[0] + n);
 
    cnt = 0;
 
    for (int i = n * 2; i >= n + 1; i--) {
 
        if (a[i] == 1)
 
            cnt++;
 
        else
 
            cnt--;
 
        if (cnt == 0) ans = min(ans, n + i - n - 1);
 
        if (M.count(-cnt)) ans = min(ans, n - M[-cnt] + i - n - 1);
 
    }
 
    printf("%d\n", ans);
 
}
 
 
 
void readInput() {
 
    int t;
 
    scanf("%d", &t);
 
    while (t--) {
 
        scanf("%d", &n);
 
        for (int i = 1; i <= n * 2; ++i)
 
            scanf("%d", a + i);
 
        solve();
 
    }
 
}
 
 
 
 
 
 
 
int main() {
 
 
    freopen("c.in", "r", stdin);
 
    auto start = high_resolution_clock::now();
 
 
 
 
    readInput();
 
 
 
#ifndef ONLINE_JUDGE
 
    auto stop = high_resolution_clock::now();
 
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by solution: "
 
         << duration.count() / 1000.0 << " ms" << endl;
 
#endif
 
    return 0;
 
}
 