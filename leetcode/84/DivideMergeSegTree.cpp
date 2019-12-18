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

const int MAXN = 1e5+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

int n;

typedef struct Node
{
	int val;
	int idx;
	Node () {}
	Node (int _val, int _idx) : val(_val), idx(_idx) {}
}Node;

Node nodes[MAXN << 2];
int heights[MAXN];

void pushUp(int root)
{
	if (nodes[lson(root)].val > nodes[rson(root)].val) nodes[root] = nodes[rson(root)];
	else nodes[root] = nodes[lson(root)];
}

void build(int root, int l, int r)
{
	if (l == r)
	{
		nodes[root] = Node(heights[l], l);
		return ;
	}
	int mid = (l+r) >> 1;
	build(lson(root), l, mid);
	build(rson(root), mid+1, r);
	pushUp(root);
}

Node query(int root, int l, int r, int ql, int qr)
{
	if (l > qr || r < ql) return Node(-1, -1);
	if (l >= ql && r <= qr) return nodes[root];
	int mid = (l+r) >> 1;
	Node ret1, ret2;
	ret1 = query(lson(root), l, mid, ql, qr);
	ret2 = query(rson(root), mid+1, r, ql, qr);
	if (ret1.idx == -1) return ret2;
	if (ret2.idx == -1) return ret1;
	if (ret1.val > ret2.val) return ret2;
	else return ret1;
}

int solve(int start, int end)
{
	int minHeight = INF;
	if (end < start) return -INF;
	int minIndex = -1;
	Node tmp = query(0, 0, n-1, start, end);
	minIndex = tmp.idx;
	return max(tmp.val*(end-start+1), max(solve(minIndex+1, end), solve(start, minIndex-1)));
}
int main()
{
	freopen("in.txt", "r", stdin);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &heights[i]);
	}
	build(0, 0, n-1);
	int ans = solve(0, n-1);
	cout << ans << endl;
	return 0;
}

1.2015-2016年第2学期的成绩数据有没有缺失
2.2016年的体测数据和成绩相关的数据有没有缺失和不正常的值统计一下人数




