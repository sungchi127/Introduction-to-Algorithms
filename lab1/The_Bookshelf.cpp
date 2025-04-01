#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> ma,flag;
    int n,m,q,a;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        ma[a]=i;
        flag[a]=1;
    }
    while(m--)
    {
        cin>>q;
        if(ma[q]>=0&&ma[q]<n&&flag[q]==1)
            cout<<ma[q]<<"\n";
        else
            cout<<"-1"<<"\n";
    }
    
    return 0;
}