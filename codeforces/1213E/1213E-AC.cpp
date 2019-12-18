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

const int MAXN = 3e5+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

int n;

char forbid[2][8];
char atom[8] = "abc";
char str[MAXN];
bool judge(int lim)
{
	//tp0 -> lim = 6, tp1 -> lim =6
	//if n >= 2 lim = 6 else n = 3
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < lim; i++)
		{
			if (str[i] == forbid[j][0] && str[i+1] == forbid[j][1]) return false;
		}
	}
	return true;
}
int main()
{
	freopen("1213E.in", "r", stdin);
	while (cin >> n)
	{
		bool OK = false;
		cin >> forbid[0] >> forbid[1];
		do{
			//cout << atom << endl;
			int lim = min(2, n);
			for (int i = 0; i < lim; i++)
			{
				strcat(str, atom);
			}
			if (judge(lim*3))
			{
				OK = true;
				cout << "YES" << endl;
				for (int i = 0; i < n; i++) cout << atom;
				cout << endl;
				break;
			}
			strcpy(str, "");
			for (int j = 0; j < 3; j++)
			{
				for (int i = 0+j*lim; i < lim+j*lim; i++)
				{
					str[i] = atom[j];
				}	
			}
			str[6] = '\0';
			if (judge(lim*3))
			{
				OK = true;
				cout << "YES" << endl;
				for (int j = 0; j < 3; j++)
				{
					for (int i = 0+j*n; i < n+j*n; i++)
					{
						cout << atom[j];
					}	
				}	
				cout << endl;
				break;
			}
			strcpy(str, "");
		}while(next_permutation(atom, atom+3));	
		if (!OK) cout << "NO" << endl;
	}
	return 0;
}