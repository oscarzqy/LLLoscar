/*
1、维护区间最值
2、去除冗杂状态 如上题，区间中的两个元素a[i],a[j]（假设现在再求最大值）
若 j>i且a[j]>=a[i] ，a[j]比a[i]还大而且还在后面（目前a[j]留在队列肯定比a[i]有用，因为你是往后推， 核心思想 !!!）
3、保持队列单调，最大值是单调递减序列，最小值反之
4、最优选择在队首
两端都要筛选 出队
*/
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#define pb push_back
#define fi first
#define se second
#define lson(r) (r<<1)
#define rson(r) ((r<<1)|1)

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAXN = 1e6+7;
const int MAXV = 507;
const int MAXE = 507;
const int INF = 0x3f3f3f3f;

int n, m;
namespace minQueue
{
	P array[MAXN];
	int front = 0, tail = -1;
	bool isEmpty()
	{
		return front > tail;
	}
	void push(P elem)
	{
		if (isEmpty())
		{
			array[++tail] = elem;
			return ;
		}
		//backward:
		int i = tail, j = front;
		for (i = tail; i >= front; i--)
		{
			if (array[i].fi < elem.fi && array[i].se >= elem.se-m+1)
			{
				break;
			}
		}
		tail = i;
		array[++tail] = elem;
		//forward
		for (j = front; j < tail; j++)
		{
			if (array[j].fi < elem.fi && array[j].se >= elem.se-m+1)
			{
				break;
			}
		}
		front = j;
	}
	int query()
	{
		return array[front].fi;
	}
}

namespace maxQueue
{
	P array[MAXN];
	int front = 0, tail = -1;
	bool isEmpty()
	{
		return front > tail;
	}
	void push(P elem)
	{
		if (isEmpty())
		{
			array[++tail] = elem;
			return ;
		}
		//backward:
		int i = tail, j = front;
		for (i = tail; i >= front; i--)
		{
			if (array[i].fi > elem.fi && array[i].se >= elem.se-m+1)
			{
				break;
			}
		}
		tail = i;
		array[++tail] = elem;
		//forward
		for (j = front; j < tail; j++)
		{
			if (array[j].fi > elem.fi && array[j].se >= elem.se-m+1)
			{
				break;
			}
		}
		front = j;
	}
	int query()
	{
		return array[front].fi;
	}
}

int main()
{
	freopen("poj2823.in", "r", stdin);
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 0; i < m-1; i++) 
		{
			int x;
			scanf("%d", &x);
			maxQueue::push(P(x, i));
			minQueue::push(P(x, i));
		}
		vector<int> ans[2];
		for (int i = m-1; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			maxQueue::push(P(x, i));
			minQueue::push(P(x, i));
			ans[0].pb(minQueue::query());
			ans[1].pb(maxQueue::query());
		}
		for (int i = 0; i < ans[0].size(); i++) printf("%d ", ans[0][i]);
		putchar('\n');
		for (int i = 0; i < ans[1].size(); i++) printf("%d ", ans[1][i]);
		putchar('\n');
	}
	return 0;
}



