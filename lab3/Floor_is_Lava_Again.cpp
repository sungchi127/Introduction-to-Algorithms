#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6;
double c[maxn],p[maxn];

struct s{
    double x,c,p,num;
    s(double _x,double _c,double _p,double _num)
    {
        x=_x;
        c=_c;
        p=_p;
        num=_num;
    }
};
struct cmp{
    bool operator()(s const& p1,s const& p2)
    {
        return p1.x < p2.x;
    }
};
priority_queue<s,vector<s>,cmp> q;

signed main(){
    int n,k;
    double sum=0;
    cin>>n>>k;
    for(int i =0;i<n;i++)
    {
        cin>>c[i]>>p[i];
        double tmp=p[i]+1;
        q.emplace(s(c[i]/tmp,c[i],p[i],0));
        //cout<<c[i]/tmp<<" "<<c[i]<<" "<<p[i]<<endl;
    }
    for(int i=0;i<k;i++)
    {
        double tmpx=0,tmpc=0,tmpp=0,tmpnum=0,x=0;
        tmpx=q.top().x;//max addtion
        //cout<<tmpx<<endl;
        tmpc=q.top().c;
        tmpp=q.top().p;
        tmpnum=q.top().num+1;
        q.pop();
        sum+=tmpx;
        //cout<<i<<" "<<tmpx<<" "<<sum<<endl;
        x=(tmpc/(tmpp+tmpnum+1))*(tmpnum+1)-(tmpc/(tmpp+tmpnum))*(tmpnum);
        q.emplace(s(x,tmpc,tmpp,tmpnum));
        //cout<<x<<" "<<tmpc<<" "<<tmpp<<" "<<tmpnum<<" "<<tmpadd<<endl;
    }
    cout<<setprecision(8)<<sum;
    return 0;
}