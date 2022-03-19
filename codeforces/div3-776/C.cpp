#include <bits/stdc++.h>

using namespace std;
using P = struct {
  int first, second, index;
};

int main() {
  freopen("C.in", "r", stdin);
  int T;
  cin >> T;
  for (int cas = 0; cas < T; cas++) {
    int n, m;
    vector<P> nodes;
    getchar();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
      P p;
      cin >> p.first >> p.second;
      p.index = i+1;
      nodes.push_back(move(p));
    }
    sort(nodes.begin(), nodes.end(), [](P &p1, P &p2){
      if (p1.second != p2.second) return p1.second < p2.second;
      return p1.first < p2.first;
    });
    int ans = 0;
    for (int i = 0; i < n * 2; ++i) {
      ans += nodes[i].second;
    }
    sort(nodes.begin(), nodes.begin()+2*n, [](P &p1, P &p2){
            return p1.first < p2.first;
         });
    cout <<ans <<endl;
    for (int i = 0; i < n; ++i) {
      cout << nodes[i].index << " " << nodes[n*2-1-i].index << endl;
    }
    cout << endl;
  }
  return 0;
}
