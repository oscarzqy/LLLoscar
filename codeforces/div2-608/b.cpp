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

const int MAXN = 1e3+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

/*
The parity of W and B will not change
because each time you'd either remove two same elements and add two ones
or shift the possition of two different elements.
so impossible situation is like this:
the number of W and B are both odd so you can't change it to zero(even number)
possible ways:
to implement the demand :
see code below it's very clear;

*/
char str[MAXN];
int main()
{
    freopen("b.in", "r", stdin);
    int n;
    cin >> n; 
    cin >> str;
    int cntB = 0, cntW = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'W') cntW++;
        else cntB++;
    }
    if (!cntW || !cntB) 
    {
        cout << 0 << endl;
        return 0;
    }
    if(cntW & 1 && cntB & 1) 
    {
        cout << -1 << endl;
        return 0;
    }
    char opStr[MAXN];
    memcpy(opStr, str, sizeof(str));
    //change all to B
    vector<int> ans;
    bool fin = false;
    for (int i = 0; i+1 < n; i++)
    {
        if(opStr[i] == 'W') 
        {
            opStr[i] = 'B';
            opStr[i+1] = (opStr[i+1] == 'B') ? 'W' : 'B';
            ans.pb(i);
        } 
    }
    if (opStr[n-1] == 'B') fin = true;
    if (!fin)
    {
        ans.clear();
        memcpy(opStr, str, sizeof(str));
        //change all to W
        for (int i = 0; i+1 < n; i++)
        {
            if(opStr[i] == 'B') 
            {
                opStr[i] = 'W';
                opStr[i+1] = (opStr[i+1] == 'B') ? 'W' : 'B';
                ans.pb(i);
            } 
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i+1 << " ";
    }
    cout << endl;
    return 0;
}