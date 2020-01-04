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

const int MAXN = 2e5+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

bool vis[MAXN];
vector<int> house;
int solveMin()
{
    int res = 0, len = house.size();
    memset(vis, 0, sizeof(vis));
    for (auto x : house)
    {
        if (vis[x-1] || vis[x] || vis[x+1]) continue; //then go to house that has already been occupied. 
        else //go to x+1 because it is more profitble in order to minimize the total number of house occupied.
        {
            vis[x+1] = true;
            res++;
        }
    }
    return res;
}

int solveMax()
{
    int res = 0, len = house.size();
    memset(vis, 0, sizeof(vis));
    for (auto x : house) //try to occupiy houses as many as possible in asccending order.
    {
        if (!vis[x-1]){
            vis[x-1] = true;
            res++;
        }else if (!vis[x]){
            vis[x] = true;
            res++;
        }else if (!vis[x+1]){
            vis[x+1] = true;
            res++;
        }
    }
    return res;
}
int main()
{
    freopen("e.in", "r", stdin);
    int n;
    cin >> n;
    house.resize(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> house[i];
    }
    sort(house.begin(), house.end());
    int Min = solveMin();
    int Max = solveMax();
    cout << Min << " " << Max << endl;
    return 0;
}