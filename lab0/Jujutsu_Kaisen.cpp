#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int count=2;
    set<int> road;
    multiset<int> l;
    long long int N,L,p;
    cin>>L>>N;
    road.insert(0);
    road.insert(L);
    l.insert(L);
    while(cin>>p)
    {
        road.insert(p);
        count++;
        int max=0,tmp1=0,tmp2=0,len1=0,len2=0;
        tmp1=*prev(road.lower_bound(p));
        tmp2=*(road.upper_bound(p));
        len1=p-tmp1;
        len2=tmp2-p;
        l.erase(l.find(tmp2-tmp1));
        l.insert(len1);
        l.insert(len2);
        max=*prev(l.end());
        max=max/2;
        cout<<max<<"\n";
    }
    return 0;
}