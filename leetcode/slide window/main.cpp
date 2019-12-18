#include <bits/stdc++.h>

using namespace std;

void queInsertElem(deque<int> &que, int val)
{
    while(!que.empty() && que.back() < val)
    {
        que.pop_back();
    }
    que.push_back(val);
}
vector<int> solve(vector<int>& nums, int k)
{
    int len = nums.size();
    vector<int> ans;
    deque<int> que;
    int p0 = 0, p1 = 0, i;
    for (i = 0;i < len && i-p0 < k; i++)
    {
        queInsertElem(que, nums[i]);
    }
    p1 = i-1;
    if
    while(p1 < len)
    {
        if (!que.empty())
        {
            int tmp = que.front();
            ans.push_back(tmp);
        }
        p1++;
        if (p1 - p0 >= k)
        {
            if (nums[p0] == que.front()) que.pop_front();
            p0++;
        }
        if (p1 < len) queInsertElem(que, nums[p1]);
    }
    return ans;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, k;
    //cin >> n >> k;
    vector<int> nums;
    nums.clear();
    k = 0;
    n = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> ans = solve(nums, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
