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

char stdArr[MAXN];
char ans[MAXN];

void fillAns(int n, int k)
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = i+k; j <= n; j+=k)
        {
            ans[j] = ans[i];
        }
    }
}
bool check(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] > stdArr[i]) return true;
        else if (ans[i] < stdArr[i]) return false;
    }
    return true;
}

void print(int n)
{
    cout << n << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
    }
    cout << endl;
}
int main()
{
    freopen("c.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    cin >> stdArr+1;
    for (int i = 1; i <= k; i++)
    {
        ans[i] = stdArr[i];
    }
    fillAns(n, k);
    if (check(n))
    {
        print(n);
        return 0;
    }
    int pos = -1;
    for (int i = k; i >= 0; i--)
    {
        if (ans[i] != '9') 
        {
            pos = i;
            ans[i] += 1;
            break;
        } 
    }
    for (int i = pos+1; i <= k; i++)
    {
        ans[i] = '0';
    }
    fillAns(n, k);
    print(n);
    return 0;
}


