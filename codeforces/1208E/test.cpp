#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <time.h>
#include <map>
#include <set>
#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)
#define random(x) (rand()%x)
using namespace std;
const double eps=1e-8; 
typedef long long ll;
const int MAXN=1000005;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
ll sum[MAXN];
int a[MAXN];
int al[MAXN];
int ar[MAXN];
int main(){
 	freopen("1208E.in", "r", stdin);
	int q,n,w;
	gi2(q,w);
	while(q--){
		gi(n);
		for(int i=1;i<=n;i++){
			gi(a[i]);
		}
		a[0]=a[n+1]=inf;
		stack<int>sl,sr;
		sl.push(0);
		for(int i=1;i<=n;i++){
			while(a[i]>=a[sl.top()]){
				sl.pop();
			}
			al[i]=sl.top();
			sl.push(i);
		}
		sr.push(n+1);
		for(int i=n;i;i--){
			while(a[i]>a[sr.top()]){
				sr.pop();
			}
			ar[i]=sr.top();
			sr.push(i);
		}
		for(int i=1;i<=n;i++){
			int l=i,r=w-n+i;
			int maxl=al[i],maxr=ar[i];
			if(maxl)l=max(l,w-n+maxl+1);//范围缩小
			if(maxr!=n+1)r=min(r,maxr-1);//范围缩小
			if(a[i]<0){//可以没有数字的地方 不能受a[i]的影响
				r=min(n,r);
				l=max(l,w-n+1);
			}
			if(r<l)continue;
			sum[l]+=a[i];
			sum[r+1]-=a[i];
			
		}
		
	}
	for(int i=1;i<=w;i++){
		sum[i]+=sum[i-1];
		printf("%lld ",sum[i]);
	}
	return 0;
}