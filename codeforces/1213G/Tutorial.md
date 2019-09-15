https://codeforces.com/problemset/problem/1213/G

An simple way to optimize this kind of unsorted queries is to do it offline which is very easy to be finished by read those queries all and sort them.

Official Tutorial

https://codeforces.com/blog/entry/69464  

Let's carry the value ***res*** that means the answer for the current set of edges. Initially it is ***0***. Let's sort all edges by their weight and all queries by their weight also (both in non-decreasing order).

Let's merge components of the tree using DSU (disjoint set union). We need to carry sizes of components also (it is easy if we use DSU). Then let's iterate over all queries in order of non-decreasing their weights. If the current query has weight cwcw then let's merge all components connected by edges with weight wi≤cwwi≤cw. When we merge two components with sizes s1s1 and s2s2, the answer changes like that: res:=res−(s12)−(s22)+(s1+s22)res:=res−(s12)−(s22)+(s1+s22). The value (x2)(x2) equals to x(x−1)2x(x−1)2. It is so because we subtract all old paths corresponding to these components and add all new paths in the obtained component. So the answer for the current query will be resres after all required merges.