#include <bits/stdc++.h>

using namespace std;

int reschedue(const vector<int>& a, int removed_day) {
  // reschedule the exam to the last day
  int len = a.size();
  vector<int> a1 = a;
  a1.erase(a1.begin() + removed_day);
  a1.push_back(a1.back());
  int rest1 = INT_MAX;
  for (int i = 1; i < a1.size() - 1; ++i) {
    rest1 = min(rest1, a1[i] - a1[i-1] - 1);
  }
  a1.pop_back();
  // reschedule the exam to the middle of the max rest period
  // find the largest gap
  int l = -1, r = -1;
  int max_rest = INT_MIN;
  for (int i = 1; i < a1.size() - 1; ++i) {
    if (max_rest < a1[i] - a1[i-1] - 1) {
      max_rest = a1[i] - a1[i-1] - 1;
      l = i-1;
      r = i;
    }
  }
  int new_day = a1[l] + (a1[r]-a1[l]+1) / 2;
  a1.insert(a1.begin() + l + 1, new_day);
  int rest2 = INT_MAX;
  for (int i = 1; i < a1.size()-1; ++i) {
    rest2 = min(rest2, a1[i] - a1[i-1] - 1);
  }
  return max(rest1, rest2);
}

int main() {
  freopen("E.in", "r", stdin);
  int T;
  cin >> T;
  getchar();
  for (int cas = 0; cas < T; cas++) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n+2);
    for (int i = 0; i < n; ++i) cin >> a[i+1];
    getchar();
    a[0] = 0;
    a[n+1] = d;
    int min_rest = INT_MAX;
    int max_rest = INT_MIN;
    vector<int> min_days;
    for (int i = 1; i <= n; ++i) {
      int rest = a[i] - a[i-1] - 1;
      max_rest = max(max_rest, rest);
      if (rest < min_rest) {
        min_rest = rest;
        min_days.clear();
        min_days.push_back(i);
      } else if (rest == min_rest) {
        min_days.push_back(i);
      }
    }
    if (min_days.size() > 2) {
      cout << min_rest << endl;
    } else if (min_days.size() == 2) {
      int u = reschedue(a, min_days[0]);
      cout << u << endl;
    } else {
      int u1 = reschedue(a, min_days[0]);
      int u2{};
      if (min_days[0] - 1 > 0) u2 = reschedue(a, min_days[0]-1);
      cout << max(u1, u2) << endl;
    }
  }
  return 0;
}
