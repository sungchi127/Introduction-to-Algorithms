#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0);
	cin.tie(0);
    long long int n,k;
    cin>>n>>k;
    multiset<pair<double,double>> s;
    pair<double,double> s1;
    long double c,p,num,flag;

    for(int i=0;i<n;i++)
    {
        cin>>c>>p;
        num=c/(p+1);
        s.insert(make_pair(num,p));
    }

    flag=(*prev(s.end())).first;

    for(int i = 0; i < k; i++)//塞人
    {   
        s1=*prev(s.end());//找到新最大值後人數+1
        // cout<<s1.first<<" "<<s1.second<<"\n";
        s1.second+=1;
        if(flag>s1.first)
        {
            flag=s1.first;
        }
        s1.first=(s1.first*(s1.second))/(s1.second+1);
        s.erase(prev(s.end()));
        // cout<<"*"<<s1.first<<"\n";
        s.insert(make_pair(s1.first,s1.second));
        // for (const auto &si : s) {
        //     cout << si.first << " ";
        // }
        // cout<<"\n";
    }
    cout<<setprecision(7)<<flag;
    return 0;
}
