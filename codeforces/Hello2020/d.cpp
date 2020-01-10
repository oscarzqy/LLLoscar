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

/*
题意：
如果存在两个演讲，在A场地时间冲突，但是在B场地时间不冲突（反之一样） 则为time sensitive
则输出NO
YES的情况任意两个演讲在A B都不冲突 或者在A B都冲突


先排序控制一维（比如在A场地的时间），sa时放入集合 ea+1时出集合，这样在集合内的肯定都是在A场地冲突的 ....这是常见套路
然后在集合中维护维护同一场演讲B的开始时间和结束时间 设当前演讲二crt
如果MaxS > crt.sb || MinE < crt.sa 则集合中的演讲和当前处理到的演讲肯定在B不冲突，那么就是time sensitive
*/

struct Event
{
    int timeStamp, sp, ep, isIn;
    Event() {}
    Event (int _timeStamp, int _sp, int _ep, int _isIn) : timeStamp(_timeStamp), sp(_sp), ep(_ep), isIn(_isIn) {} 
    bool operator < (Event& e) const
    {
        if (timeStamp != e.timeStamp) return timeStamp < e.timeStamp;
        return isIn < e.isIn;
    }
};



bool check(int len, vector<int> &sa, vector<int> &ea, vector<int> &sb, vector<int> &eb)
{
    multiset<int> s, e;
    vector<Event> events;
    for (int i = 0; i < len; i++)
    {
        events.emplace_back(sa[i], sb[i], eb[i], 1);
        events.emplace_back(ea[i]+1, sb[i], eb[i], 0);
    }
    sort(events.begin(), events.end());
/*    for (auto i : events)
    {
        cout << i.timeStamp << " " << i.sp << " " << i.ep << " " << i.isIn << endl;
    }
*/    for(int i = 0; i < (int)events.size() ; i++)
    {
        Event event = events[i];
        if (event.isIn)
        {
            if (!s.empty())
            {
                int maxS = *s.rbegin();
                int minE = *e.begin();
                //not intersetct in venue b but intersected in a 
                if (minE < event.sp || maxS > event.ep) return false;
            } 
            s.insert(event.sp);
            e.insert(event.ep);
        }
        else 
        {
            //use find mathod to erase only one elem
            s.erase(s.find(event.sp));
            e.erase(e.find(event.ep));
        }
    }
    return true;
}


int main()
{
    freopen("d.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> sa(n), ea(n), sb(n), eb(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
    }
    //cout << check(n, sa, ea, sb, eb) << endl;return 0;
    if (check(n, sa, ea, sb, eb) && check(n, sb, eb, sa, ea)) puts("YES");
    else puts("NO");
    return 0;
}