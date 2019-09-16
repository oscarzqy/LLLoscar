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
char s[MAXN];

int main()
{
	freopen("1214C.in", "r", stdin);
	int n;
	while (cin >> n)
	{
		stack<char> st;
		cin >> s;
		for (int i = 0; i < n; i++)
		{
			char ch;
			ch = s[i];
			if (ch == '(') st.push(ch);
			else if (!st.empty() && st.top() == '(') st.pop();
			else st.push(ch);
		}
		if (st.empty()) puts("YES");
		else if (st.size() != 2) puts("NO");
		else
		{
			char c1 = st.top();
			st.pop();
			if(c1 == st.top()) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}