#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a,o,b,r,sum;
    sum.push_back(1);
    for(int i=0;i<n;i++)
    {
        int po=0;
        int lsum=sum.size();
        for(int j=0;j<lsum;j++)
        {
            o.push_back(sum[j]);
        }

        sum.clear();
        //a
        int lo=o.size();
        for(int j=lo-1;j>=0;j--)
        {
            a.push_back(o[j]);
        }
        //b
        po=pow(2,i);
        for(int j=0;j<lo;j++)
        {
            b.push_back(o[j]+po);
        }
        //a+b
        int la=a.size(),lb=b.size();
        for(int j=0;j<la;j++)
        {
            r.push_back(a[j]);
        }
        for(int j=0;j<lb;j++)
        {
            r.push_back(b[j]);
        }
        //rotate
        int lr=r.size();
        for(int j=po;j<lr;j++)
        {
            sum.push_back(r[j]);
            // cout<<sum[j]<<" ";
        }
        // cout<<"\n";
        for(int j=0;j<po;j++)
        {
            sum.push_back(r[j]);
            // cout<<sum[j]<<" ";
        }
        // for(auto& it:sum)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        r.clear();
        o.clear();
        a.clear();
        b.clear();
    }
    for(auto& it:sum)
    {
        cout<<it<<" ";
    }
    return 0;
}